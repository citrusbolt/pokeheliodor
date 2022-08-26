/* Data flow analysis for GNU compiler.
   Copyright (C) 1987, 88, 92-98, 1999 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */


/* This file contains the data flow analysis pass of the compiler.
   It computes data flow information
   which tells combine_instructions which insns to consider combining
   and controls register allocation.

   Additional data flow information that is too bulky to record
   is generated during the analysis, and is used at that time to
   create autoincrement and autodecrement addressing.

   The first step is dividing the function into basic blocks.
   find_basic_blocks does this.  Then life_analysis determines
   where each register is live and where it is dead.

   ** find_basic_blocks **

   find_basic_blocks divides the current function's rtl
   into basic blocks.  It records the beginnings and ends of the
   basic blocks in the vectors basic_block_head and basic_block_end,
   and the number of blocks in n_basic_blocks.

   find_basic_blocks also finds any unreachable loops
   and deletes them.

   ** life_analysis **

   life_analysis is called immediately after find_basic_blocks.
   It uses the basic block information to determine where each
   hard or pseudo register is live.

   ** live-register info **

   The information about where each register is live is in two parts:
   the REG_NOTES of insns, and the vector basic_block_live_at_start.

   basic_block_live_at_start has an element for each basic block,
   and the element is a bit-vector with a bit for each hard or pseudo
   register.  The bit is 1 if the register is live at the beginning
   of the basic block.

   Two types of elements can be added to an insn's REG_NOTES.  
   A REG_DEAD note is added to an insn's REG_NOTES for any register
   that meets both of two conditions:  The value in the register is not
   needed in subsequent insns and the insn does not replace the value in
   the register (in the case of multi-word hard registers, the value in
   each register must be replaced by the insn to avoid a REG_DEAD note).

   In the vast majority of cases, an object in a REG_DEAD note will be
   used somewhere in the insn.  The (rare) exception to this is if an
   insn uses a multi-word hard register and only some of the registers are
   needed in subsequent insns.  In that case, REG_DEAD notes will be
   provided for those hard registers that are not subsequently needed.
   Partial REG_DEAD notes of this type do not occur when an insn sets
   only some of the hard registers used in such a multi-word operand;
   omitting REG_DEAD notes for objects stored in an insn is optional and
   the desire to do so does not justify the complexity of the partial
   REG_DEAD notes.

   REG_UNUSED notes are added for each register that is set by the insn
   but is unused subsequently (if every register set by the insn is unused
   and the insn does not reference memory or have some other side-effect,
   the insn is deleted instead).  If only part of a multi-word hard
   register is used in a subsequent insn, REG_UNUSED notes are made for
   the parts that will not be used.

   To determine which registers are live after any insn, one can
   start from the beginning of the basic block and scan insns, noting
   which registers are set by each insn and which die there.

   ** Other actions of life_analysis **

   life_analysis sets up the LOG_LINKS fields of insns because the
   information needed to do so is readily available.

   life_analysis deletes insns whose only effect is to store a value
   that is never used.

   life_analysis notices cases where a reference to a register as
   a memory address can be combined with a preceding or following
   incrementation or decrementation of the register.  The separate
   instruction to increment or decrement is deleted and the address
   is changed to a POST_INC or similar rtx.

   Each time an incrementing or decrementing address is created,
   a REG_INC element is added to the insn's REG_NOTES list.

   life_analysis fills in certain vectors containing information about
   register usage: reg_n_refs, reg_n_deaths, reg_n_sets, reg_live_length,
   reg_n_calls_crosses and reg_basic_block.

   life_analysis sets current_function_sp_is_unchanging if the function
   doesn't modify the stack pointer.  */

#include "config.h"
#include "system.h"
#include "rtl.h"
#include "basic-block.h"
#include "insn-config.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "flags.h"
#include "output.h"
#include "except.h"
#include "toplev.h"
#include "recog.h"

#include "obstack.h"
#define obstack_chunk_alloc xmalloc
#define obstack_chunk_free free

#define XNMALLOC(TYPE, COUNT) ((TYPE *) xmalloc ((COUNT) * sizeof (TYPE)))

/* The contents of the current function definition are allocated
   in this obstack, and all are freed at the end of the function.
   For top-level functions, this is temporary_obstack.
   Separate obstacks are made for nested functions.  */

extern struct obstack *function_obstack;

/* List of labels that must never be deleted.  */
extern rtx forced_labels;

/* Get the basic block number of an insn.
   This info should not be expected to remain available
   after the end of life_analysis.  */

/* This is the limit of the allocated space in the following two arrays.  */

static int max_uid_for_flow;

#define BLOCK_NUM(INSN)  uid_block_number[INSN_UID (INSN)]

/* This is where the BLOCK_NUM values are really stored.
   This is set up by find_basic_blocks and used there and in life_analysis,
   and then freed.  */

int *uid_block_number;

/* INSN_VOLATILE (insn) is 1 if the insn refers to anything volatile.  */

#define INSN_VOLATILE(INSN) uid_volatile[INSN_UID (INSN)]
static char *uid_volatile;

/* Nonzero if the second flow pass has completed.  */
int flow2_completed;

/* Number of basic blocks in the current function.  */

int n_basic_blocks;

/* Maximum register number used in this function, plus one.  */

int max_regno;

/* Indexed by n, giving various register information */

varray_type reg_n_info;

/* Size of the reg_n_info table.  */

unsigned int reg_n_max;

/* Element N is the next insn that uses (hard or pseudo) register number N
   within the current basic block; or zero, if there is no such insn.
   This is valid only during the final backward scan in propagate_block.  */

static rtx *reg_next_use;

/* Size of a regset for the current function,
   in (1) bytes and (2) elements.  */

int regset_bytes;
int regset_size;

/* Element N is first insn in basic block N.
   This info lasts until we finish compiling the function.  */

rtx *x_basic_block_head;

/* Element N is last insn in basic block N.
   This info lasts until we finish compiling the function.  */

rtx *x_basic_block_end;

/* Element N indicates whether basic block N can be reached through a
   computed jump.  */

char *basic_block_computed_jump_target;

/* Element N is a regset describing the registers live
   at the start of basic block N.
   This info lasts until we finish compiling the function.  */

regset *basic_block_live_at_start;

/* Regset of regs live when calls to `setjmp'-like functions happen.  */

regset regs_live_at_setjmp;

/* List made of EXPR_LIST rtx's which gives pairs of pseudo registers
   that have to go in the same hard reg.
   The first two regs in the list are a pair, and the next two
   are another pair, etc.  */
rtx regs_may_share;

/* Pointer to head of predecessor/successor block list.  */
static int_list_block *flow_int_list_blocks;

/* Element N is the list of successors of basic block N.  */
static int_list_ptr *basic_block_succ;

/* Element N is the list of predecessors of basic block N.  */
static int_list_ptr *basic_block_pred;

/* Element N is depth within loops of the last insn in basic block number N.
   Freed after life_analysis.  */

static short *basic_block_loop_depth;

/* Depth within loops of basic block being scanned for lifetime analysis,
   plus one.  This is the weight attached to references to registers.  */

static int loop_depth;

/* During propagate_block, this is non-zero if the value of CC0 is live.  */

static int cc0_live;

/* During propagate_block, this contains a list of all the MEMs we are
   tracking for dead store elimination. 

   ?!? Note we leak memory by not free-ing items on this list.  We need to
   write some generic routines to operate on memory lists since cse, gcse,
   loop, sched, flow and possibly other passes all need to do basically the
   same operations on these lists.  */

static rtx mem_set_list;

/* Set of registers that may be eliminable.  These are handled specially
   in updating regs_ever_live.  */

static HARD_REG_SET elim_reg_set;

/* Forward declarations */
static void find_basic_blocks_1		PROTO((rtx, rtx));
static void add_edge			PROTO((int, int));
static void add_edge_to_label		PROTO((int, rtx));
static void make_edges			PROTO((int));
static void mark_label_ref		PROTO((int, rtx));
static void delete_unreachable_blocks	PROTO((void));
static int delete_block			PROTO((int));
static void life_analysis_1		PROTO((rtx, int));
static void propagate_block		PROTO((regset, rtx, rtx, int, 
					       regset, int));
static int set_noop_p			PROTO((rtx));
static int noop_move_p			PROTO((rtx));
static void record_volatile_insns	PROTO((rtx));
static void mark_regs_live_at_end	PROTO((regset));
static int insn_dead_p			PROTO((rtx, regset, int, rtx));
static int libcall_dead_p		PROTO((rtx, regset, rtx, rtx));
static void mark_set_regs		PROTO((regset, regset, rtx,
					       rtx, regset));
static void mark_set_1			PROTO((regset, regset, rtx,
					       rtx, regset));
#ifdef AUTO_INC_DEC
static void find_auto_inc		PROTO((regset, rtx, rtx));
static int try_pre_increment_1		PROTO((rtx));
static int try_pre_increment		PROTO((rtx, rtx, HOST_WIDE_INT));
#endif
static void mark_used_regs		PROTO((regset, regset, rtx, int, rtx));
void dump_flow_info			PROTO((FILE *));
static void add_pred_succ		PROTO ((int, int, int_list_ptr *,
						int_list_ptr *, int *, int *));
static int_list_ptr alloc_int_list_node PROTO ((int_list_block **));
static int_list_ptr add_int_list_node   PROTO ((int_list_block **,
						int_list **, int));
/* CYGNUS LOCAL LRS */
void init_regset_vector		PROTO ((regset *, int,
						struct obstack *));
static void count_reg_sets_1		PROTO ((rtx));
static void count_reg_sets		PROTO ((rtx));
static void count_reg_references	PROTO ((rtx));
static void notice_stack_pointer_modification PROTO ((rtx, rtx));
static void invalidate_mems_from_autoinc	PROTO ((rtx));

/* Find basic blocks of the current function.
   F is the first insn of the function and NREGS the number of register numbers
   in use.  */

void
find_basic_blocks (f, nregs, file)
     rtx f;
     int nregs;
     FILE *file;
{
  register rtx insn;
  register int i;
  rtx nonlocal_label_list = nonlocal_label_rtx_list ();

  /* Avoid leaking memory if this is called multiple times per compiled
     function.  */
  free_bb_memory ();

  /* Count the basic blocks.  Also find maximum insn uid value used.  */

  {
    rtx prev_call = 0;
    register RTX_CODE prev_code = JUMP_INSN;
    register RTX_CODE code;
    int eh_region = 0;
    int call_had_abnormal_edge = 0;

    for (insn = f, i = 0; insn; insn = NEXT_INSN (insn))
      {
	code = GET_CODE (insn);

	/* A basic block starts at label, or after something that can jump.  */
	if (code == CODE_LABEL
	    || (GET_RTX_CLASS (code) == 'i'
		&& (prev_code == JUMP_INSN
		    || (prev_code == CALL_INSN && call_had_abnormal_edge)
		    || prev_code == BARRIER)))
	  {
	    i++;

	    /* If the previous insn was a call that did not create an
	       abnormal edge, we want to add a nop so that the CALL_INSN
	       itself is not at basic block end.  This allows us to easily
	       distinguish between normal calls and those which create
	       abnormal edges in the flow graph.  */

	    if (i > 0 && !call_had_abnormal_edge && prev_call != 0)
	      {
		rtx nop = gen_rtx_USE (VOIDmode, const0_rtx);
		emit_insn_after (nop, prev_call);
	      }
	  }

	if (code == CALL_INSN)
          {
            rtx note = find_reg_note(insn, REG_EH_REGION, NULL_RTX);

            /* We change the code of the CALL_INSN, so that it won't start a
               new block.  */
            if (note && XINT (XEXP (note, 0), 0) == 0)
              code = INSN;
            else
              {
                prev_call = insn;
                call_had_abnormal_edge = (nonlocal_label_list != 0
                                          || eh_region);
              }
          }

	else if (code != NOTE && code != BARRIER)
	  prev_call = 0;

	if (code != NOTE)
	  prev_code = code;
	else if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_EH_REGION_BEG)
	  ++eh_region;
	else if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_EH_REGION_END)
	  --eh_region;
      }
  }

  n_basic_blocks = i;

  max_uid_for_flow = get_max_uid ();
#ifdef AUTO_INC_DEC
  /* Leave space for insns life_analysis makes in some cases for auto-inc.
     These cases are rare, so we don't need too much space.  */
  max_uid_for_flow += max_uid_for_flow / 10;
#endif

  /* Allocate some tables that last till end of compiling this function
     and some needed only in find_basic_blocks and life_analysis.  */

  x_basic_block_head = XNMALLOC (rtx, n_basic_blocks);
  x_basic_block_end = XNMALLOC (rtx, n_basic_blocks);
  basic_block_succ = XNMALLOC (int_list_ptr, n_basic_blocks);
  basic_block_pred = XNMALLOC (int_list_ptr, n_basic_blocks);
  bzero ((char *)basic_block_succ, n_basic_blocks * sizeof (int_list_ptr));
  bzero ((char *)basic_block_pred, n_basic_blocks * sizeof (int_list_ptr));

  basic_block_computed_jump_target = (char *) oballoc (n_basic_blocks);
  basic_block_loop_depth = XNMALLOC (short, n_basic_blocks);
  uid_block_number = XNMALLOC (int, (max_uid_for_flow + 1));
  uid_volatile = XNMALLOC (char, (max_uid_for_flow + 1));
  bzero (uid_volatile, max_uid_for_flow + 1);

  find_basic_blocks_1 (f, nonlocal_label_list);
}

/* For communication between find_basic_blocks_1 and its subroutines.  */

/* An array of CODE_LABELs, indexed by UID for the start of the active
   EH handler for each insn in F.  */
static int *active_eh_region;
static int *nested_eh_region;

/* Element N nonzero if basic block N can actually be reached.  */

static char *block_live_static;

/* List of label_refs to all labels whose addresses are taken
   and used as data.  */
static rtx label_value_list;

/* a list of non-local labels in the function.  */
static rtx nonlocal_label_list;

/* Find all basic blocks of the function whose first insn is F.
   Store the correct data in the tables that describe the basic blocks,
   set up the chains of references for each CODE_LABEL, and
   delete any entire basic blocks that cannot be reached.

   NONLOCAL_LABELS is a list of non-local labels in the function.
   Blocks that are otherwise unreachable may be reachable with a non-local
   goto.  */

static void
find_basic_blocks_1 (f, nonlocal_labels)
     rtx f, nonlocal_labels;
{
  register rtx insn;
  register int i;
  register char *block_live = (char *) alloca (n_basic_blocks);
  register char *block_marked = (char *) alloca (n_basic_blocks);
  rtx note, eh_note;
  enum rtx_code prev_code, code;
  int depth;
  int call_had_abnormal_edge = 0;

  active_eh_region = (int *) alloca ((max_uid_for_flow + 1) * sizeof (int));
  nested_eh_region = (int *) alloca ((max_label_num () + 1) * sizeof (int));
  nonlocal_label_list = nonlocal_labels;

  label_value_list = 0;
  block_live_static = block_live;
  bzero (block_live, n_basic_blocks);
  bzero (block_marked, n_basic_blocks);
  bzero (basic_block_computed_jump_target, n_basic_blocks);
  bzero ((char *) active_eh_region, (max_uid_for_flow + 1) * sizeof (int));
  bzero ((char *) nested_eh_region, (max_label_num () + 1) * sizeof (int));
  current_function_has_computed_jump = 0;

  /* Initialize with just block 0 reachable and no blocks marked.  */
  if (n_basic_blocks > 0)
    block_live[0] = 1;

  /* Initialize the ref chain of each label to 0.  Record where all the
     blocks start and end and their depth in loops.  For each insn, record
     the block it is in.   Also mark as reachable any blocks headed by labels
     that must not be deleted.  */

  for (eh_note = NULL_RTX, insn = f, i = -1, prev_code = JUMP_INSN, depth = 1;
       insn; insn = NEXT_INSN (insn))
    {
      code = GET_CODE (insn);
      if (code == NOTE)
	{
	  if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_LOOP_BEG)
	    depth++;
	  else if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_LOOP_END)
	    depth--;
	}

      /* A basic block starts at label, or after something that can jump.  */
      else if (code == CODE_LABEL
	       || (GET_RTX_CLASS (code) == 'i'
		   && (prev_code == JUMP_INSN
		       || (prev_code == CALL_INSN && call_had_abnormal_edge)
		       || prev_code == BARRIER)))
	{
	  BLOCK_HEAD (++i) = insn;
	  BLOCK_END (i) = insn;
	  basic_block_loop_depth[i] = depth;

	  if (code == CODE_LABEL)
	    {
	      LABEL_REFS (insn) = insn;
	      /* Any label that cannot be deleted
		 is considered to start a reachable block.  */
	      if (LABEL_PRESERVE_P (insn))
		block_live[i] = 1;
	    }
	}

      else if (GET_RTX_CLASS (code) == 'i')
	{
	  BLOCK_END (i) = insn;
	  basic_block_loop_depth[i] = depth;
	}

      if (GET_RTX_CLASS (code) == 'i')
	{
	  /* Make a list of all labels referred to other than by jumps.  */
	  for (note = REG_NOTES (insn); note; note = XEXP (note, 1))
	    if (REG_NOTE_KIND (note) == REG_LABEL
		&& XEXP (note, 0) != eh_return_stub_label)
	      label_value_list = gen_rtx_EXPR_LIST (VOIDmode, XEXP (note, 0),
						    label_value_list);
	}

      /* Keep a lifo list of the currently active exception notes.  */
      if (GET_CODE (insn) == NOTE)
	{
	  if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_EH_REGION_BEG)
	    {
              if (eh_note)
                nested_eh_region [NOTE_BLOCK_NUMBER (insn)] = 
                                     NOTE_BLOCK_NUMBER (XEXP (eh_note, 0));
              else
                nested_eh_region [NOTE_BLOCK_NUMBER (insn)] = 0;
	      eh_note = gen_rtx_EXPR_LIST (VOIDmode,
						 insn, eh_note);
	    }
	  else if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_EH_REGION_END)
	    eh_note = XEXP (eh_note, 1);
	}
      /* If we encounter a CALL_INSN, note which exception handler it
	 might pass control to.

	 If doing asynchronous exceptions, record the active EH handler
	 for every insn, since most insns can throw.  */
      else if (eh_note
	       && (asynchronous_exceptions
		   || (GET_CODE (insn) == CALL_INSN)))
	active_eh_region[INSN_UID (insn)] =
                                        NOTE_BLOCK_NUMBER (XEXP (eh_note, 0));
      BLOCK_NUM (insn) = i;

      /* We change the code of the CALL_INSN, so that it won't start a
	 new block if it doesn't throw.  */
      if (code == CALL_INSN)
        {
          rtx rnote = find_reg_note(insn, REG_EH_REGION, NULL_RTX);
          if (rnote && XINT (XEXP (rnote, 0), 0) == 0)
            code = INSN;
        }

      /* Record whether this call created an edge.  */
      if (code == CALL_INSN)
	call_had_abnormal_edge = (nonlocal_label_list != 0 || eh_note);

      if (code != NOTE)
	prev_code = code;

    }

  if (i + 1 != n_basic_blocks)
    abort ();

  /* Now find which basic blocks can actually be reached
     and put all jump insns' LABEL_REFS onto the ref-chains
     of their target labels.  */

  if (n_basic_blocks > 0)
    {
      int something_marked = 1;

      /* Pass over all blocks, marking each block that is reachable
	 and has not yet been marked.
	 Keep doing this until, in one pass, no blocks have been marked.
	 Then blocks_live and blocks_marked are identical and correct.
	 In addition, all jumps actually reachable have been marked.  */

      while (something_marked)
	{
	  something_marked = 0;
	  for (i = 0; i < n_basic_blocks; i++)
	    if (block_live[i] && !block_marked[i])
	      {
		int_list_ptr p;

		block_marked[i] = 1;
		something_marked = 1;

		make_edges (i);

		for (p = basic_block_succ[i]; p; p = p->next)
		  block_live[INT_LIST_VAL (p)] = 1;
	      }
	}

      /* This should never happen.  If it does that means we've computed an
	 incorrect flow graph, which can lead to aborts/crashes later in the
	 compiler or incorrect code generation.

	 We used to try and continue here, but that's just asking for trouble
	 later during the compile or at runtime.  It's easier to debug the
	 problem here than later!  */
      for (i = 1; i < n_basic_blocks; i++)
	if (block_live[i] && basic_block_pred[i] == 0)
	  abort ();

      if (! reload_completed)
	delete_unreachable_blocks ();
    }
}

/* Record INSN's block number as BB.  */

void
set_block_num (insn, bb)
     rtx insn;
     int bb;
{
  if (INSN_UID (insn) >= max_uid_for_flow)
    {
      /* Add one-eighth the size so we don't keep calling xrealloc.  */
      max_uid_for_flow = INSN_UID (insn) + (INSN_UID (insn) + 7) / 8;
      uid_block_number = (int *)
	xrealloc (uid_block_number, (max_uid_for_flow + 1) * sizeof (int));
    }
  BLOCK_NUM (insn) = bb;
}

/* Subroutines of find_basic_blocks.  */

void
free_bb_memory ()
{
  free_int_list (&flow_int_list_blocks);
}

/* Make an edge in the cfg from block PRED to block SUCC.  */
static void
add_edge (pred, succ)
     int pred, succ;
{
  int_list *p;

  for (p = basic_block_pred[succ]; p ; p = p->next)
    if (p->val == pred)
      return;

  add_int_list_node (&flow_int_list_blocks, basic_block_pred + succ, pred);
  add_int_list_node (&flow_int_list_blocks, basic_block_succ + pred, succ);
}

/* Make an edge in the cfg from block PRED to the block starting with
   label LABEL.  */
static void
add_edge_to_label (pred, label)
     int pred;
     rtx label;
{
  /* If the label was never emitted, this insn is junk,
     but avoid a crash trying to refer to BLOCK_NUM (label).
     This can happen as a result of a syntax error
     and a diagnostic has already been printed.  */
  if (INSN_UID (label) == 0)
    return;

  add_edge (pred, BLOCK_NUM (label));
}

/* Check expression X for label references.  If one is found, add an edge
   from basic block PRED to the block beginning with the label.  */

static void
mark_label_ref (pred, x)
     int pred;
     rtx x;
{
  register RTX_CODE code;
  register int i;
  register char *fmt;

  code = GET_CODE (x);
  if (code == LABEL_REF)
    {
      add_edge_to_label (pred, XEXP (x, 0));
      return;
    }

  fmt = GET_RTX_FORMAT (code);
  for (i = GET_RTX_LENGTH (code) - 1; i >= 0; i--)
    {
      if (fmt[i] == 'e')
	mark_label_ref (pred, XEXP (x, i));
      if (fmt[i] == 'E')
	{
	  register int j;
	  for (j = 0; j < XVECLEN (x, i); j++)
	    mark_label_ref (pred, XVECEXP (x, i, j));
	}
    }
}

/* For basic block I, make edges and mark live all blocks which are reachable
   from it.  */
static void
make_edges (i)
     int i;
{
  rtx insn, x;
  rtx pending_eh_region = NULL_RTX;

  /* See if control drops into the next block.  */
  if (i + 1 < n_basic_blocks)
    {
      for (insn = PREV_INSN (BLOCK_HEAD (i + 1));
	   insn && GET_CODE (insn) == NOTE; insn = PREV_INSN (insn))
	;

      if (insn && GET_CODE (insn) != BARRIER)
	add_edge (i, i + 1);
    }

  insn = BLOCK_END (i);
  if (GET_CODE (insn) == JUMP_INSN)
    mark_label_ref (i, PATTERN (insn));

  /* If we have any forced labels, mark them as potentially reachable from
     this block.  */
  for (x = forced_labels; x; x = XEXP (x, 1))
    if (! LABEL_REF_NONLOCAL_P (x))
      add_edge_to_label (i, XEXP (x, 0));

  /* Now scan the insns for this block, we may need to make edges for some of
     them to various non-obvious locations (exception handlers, nonlocal
     labels, etc).  */
  for (insn = BLOCK_HEAD (i);
       insn != NEXT_INSN (BLOCK_END (i));
       insn = NEXT_INSN (insn))
    {
      if (GET_RTX_CLASS (GET_CODE (insn)) == 'i')
	{
	  rtx note;
	  /* References to labels in non-jumping insns have REG_LABEL notes
	     attached to them.

	     This can happen for computed gotos; we don't care about them
	     here since the values are also on the label_value_list and will
	     be marked live if we find a live computed goto.

	     This can also happen when we take the address of a label to pass
	     as an argument to __throw.  Note throw only uses the value to
	     determine what handler should be called -- ie the label is not
	     used as a jump target, it just marks regions in the code.

	     In theory we should be able to ignore the REG_LABEL notes, but
	     we have to make sure that the label and associated insns aren't
	     marked dead, so we make the block in question live and create an
	     edge from this insn to the label.  This is not strictly correct,
	     but it is close enough for now.  

	     See below for code that handles the eh_stub label specially.  */
	  for (note = REG_NOTES (insn);
	       note;
	       note = XEXP (note, 1))
	    {
	      if (REG_NOTE_KIND (note) == REG_LABEL
		  && XEXP (note, 0) != eh_return_stub_label)
		add_edge_to_label (i, XEXP (note, 0));
	    }

	  /* If this is a computed jump, then mark it as reaching everything
	     on the label_value_list and forced_labels list.  */
	  if (computed_jump_p (insn))
	    {
	      current_function_has_computed_jump = 1;
	      for (x = label_value_list; x; x = XEXP (x, 1))
		{
		  int b = BLOCK_NUM (XEXP (x, 0));
		  basic_block_computed_jump_target[b] = 1;
		  add_edge (i, b);
		}

	      for (x = forced_labels; x; x = XEXP (x, 1))
		{
		  int b = BLOCK_NUM (XEXP (x, 0));
		  basic_block_computed_jump_target[b] = 1;
		  add_edge (i, b);
		}
	    }

          /* If this is a call with an EH_RETHROW note, then we 
             know its a rethrow call, and we know exactly where
             this call can end up going. */
          else if (GET_CODE (insn) == CALL_INSN
                    && (note = find_reg_note (insn, REG_EH_RETHROW, NULL_RTX)))
            {
              int region = XINT (XEXP (note, 0), 0);
              /* if nested region is not 0, we know for sure it has been 
                 processed. If it is zero, we dont know whether its an
                 outer region, or hasn't been seen yet, so defer it */
              if (nested_eh_region[region] != 0) 
                {
                  /* start with the first region OUTSIDE the one specified 
                     in the rethrow parameter. (since a rethrow behaves
                     as if a handler in the region didn't handle the 
                     exception, so the handlers for the next outer region
                     are going to get a shot at it.*/
		  for ( region = nested_eh_region[region]; region; 
			region = nested_eh_region[region]) 
		    {
		      handler_info *ptr = get_first_handler (region);
		      for ( ; ptr ; ptr = ptr->next)
                        add_edge_to_label (i, ptr->handler_label);
		    }
                }
              else 
                {
                  /* Push this region onto a list, and after we've done the
                     whole procedure, we'll process everything on the list */
                  pending_eh_region = gen_rtx_EXPR_LIST (VOIDmode, insn, 
                                                         pending_eh_region);
                }
            }

	  /* If this is a CALL_INSN, then mark it as reaching the active EH
	     handler for this CALL_INSN.  If we're handling asynchronous
	     exceptions mark every insn as reaching the active EH handler.

	     Also mark the CALL_INSN as reaching any nonlocal goto sites.  */
	  else if (asynchronous_exceptions
		   || (GET_CODE (insn) == CALL_INSN
		       && ! find_reg_note (insn, REG_RETVAL, NULL_RTX)))
	    {
              int region = active_eh_region[INSN_UID (insn)];
              note = find_reg_note(insn, REG_EH_REGION, NULL_RTX);

              /* Override region if we see a REG_EH_REGION note. */
              if (note)
                region = XINT (XEXP (note, 0), 0);

	      if (region)
		{
		  handler_info *ptr;
		  region = active_eh_region[INSN_UID (insn)];
		  for ( ; region; region = nested_eh_region[region])
		    {
		      ptr = get_first_handler (region);
		      for ( ; ptr ; ptr = ptr->next)
			add_edge_to_label (i, ptr->handler_label);
		    }
		}
	      if (! asynchronous_exceptions)
		{
		  for (x = nonlocal_label_list; x; x = XEXP (x, 1))
		    add_edge_to_label (i, XEXP (x, 0));
		}
	      /* ??? This could be made smarter: in some cases it's possible
		 to tell that certain calls will not do a nonlocal goto.

		 For example, if the nested functions that do the nonlocal
		 gotos do not have their addresses taken, then only calls to
		 those functions or to other nested functions that use them
		 could possibly do nonlocal gotos.  */
	    }
	}
    }

  while (pending_eh_region != NULL_RTX)
    {
      rtx insn = XEXP (pending_eh_region, 0);
      rtx note = find_reg_note (insn, REG_EH_RETHROW, NULL_RTX);
      int region = XINT (XEXP (note, 0), 0);
      /* start with the first region OUTSIDE the one specified 
         in the rethrow parameter */
      for ( region = nested_eh_region[region]; region; 
            region = nested_eh_region[region]) 
        {
          handler_info *ptr = get_first_handler (region);
          for ( ; ptr ; ptr = ptr->next)
            add_edge_to_label (BLOCK_NUM (insn), ptr->handler_label);
        }
      pending_eh_region = XEXP (pending_eh_region, 1);
    }

  /* We know something about the structure of the function __throw in
     libgcc2.c.  It is the only function that ever contains eh_stub labels.
     It modifies its return address so that the last block returns to one of
     the eh_stub labels within it.  So we have to make additional edges in
     the flow graph.  */
  if (i + 1 == n_basic_blocks && eh_return_stub_label != 0)
    add_edge_to_label (i, eh_return_stub_label);
}

/* Now delete the code for any basic blocks that can't be reached.
   They can occur because jump_optimize does not recognize unreachable loops
   as unreachable.  */
static void
delete_unreachable_blocks ()
{
  int deleted_handler = 0;
  int deleted = 0;
  int i, j;
  rtx insn;
  int *block_num_map = XNMALLOC (int, n_basic_blocks);

  for (i = n_basic_blocks - 1; i >= 0; i--)
    if (! block_live_static[i])
      deleted_handler |= delete_block (i);

  for (i = 0; i < n_basic_blocks; i++)
    if (block_live_static[i])
      block_num_map[i] = i - deleted;
    else
      {
	deleted++;
	block_num_map[i] = -1;
      }

  /* Eliminate all traces of the deleted blocks by renumbering the remaining
     ones.  */
  for (i = j = 0; i < n_basic_blocks; i++)
    {
      int_list_ptr p;

      if (block_num_map[i] == -1)
	continue;

      for (p = basic_block_pred[i]; p; p = p->next)
	INT_LIST_VAL (p) = block_num_map[INT_LIST_VAL (p)];
      for (p = basic_block_succ[i]; p; p = p->next)
	INT_LIST_VAL (p) = block_num_map[INT_LIST_VAL (p)];

      if (i != j)
	{
	  rtx tmp = BLOCK_HEAD (i);
	  for (;;)
	    {
	      BLOCK_NUM (tmp) = j;
	      if (tmp == BLOCK_END (i))
		break;
	      tmp = NEXT_INSN (tmp);
	    }
	  BLOCK_HEAD (j) = BLOCK_HEAD (i);
	  BLOCK_END (j) = BLOCK_END (i);
	  basic_block_pred[j] = basic_block_pred[i];
	  basic_block_succ[j] = basic_block_succ[i];
	  basic_block_loop_depth[j] = basic_block_loop_depth[i];
	  basic_block_computed_jump_target[j]
	    = basic_block_computed_jump_target[i];
	}
      j++;
    }
  n_basic_blocks -= deleted;
  free (block_num_map);

  /* If we deleted an exception handler, we may have EH region
     begin/end blocks to remove as well. */
  if (deleted_handler)
    for (insn = get_insns (); insn; insn = NEXT_INSN (insn))
      if (GET_CODE (insn) == NOTE)
	{
	  if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_EH_REGION_BEG ||
	      NOTE_LINE_NUMBER (insn) == NOTE_INSN_EH_REGION_END)
	    {
	      int num = CODE_LABEL_NUMBER (insn);
	      /* A NULL handler indicates a region is no longer needed,
                 unless its the target of a rethrow. */
	      if (get_first_handler (num) == NULL && !rethrow_used (num))
		{
		  NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
		  NOTE_SOURCE_FILE (insn) = 0;
		}
	    }
	}
}

/* Delete the insns in a (non-live) block.  We physically delete every
   non-note insn except the start and end (so BLOCK_HEAD/END needn't
   be updated), we turn the latter into NOTE_INSN_DELETED notes.

   We use to "delete" the insns by turning them into notes, but we may be
   deleting lots of insns that subsequent passes would otherwise have to
   process.  Secondly, lots of deleted blocks in a row can really slow down
   propagate_block since it will otherwise process insn-turned-notes multiple
   times when it looks for loop begin/end notes.

   Return nonzero if we deleted an exception handler.  */
static int
delete_block (i)
     int i;
{
  int deleted_handler = 0;
  rtx insn;
  rtx kept_head = 0;
  rtx kept_tail = 0;

  /* If the head of this block is a CODE_LABEL, then it might
     be the label for an exception handler which can't be
     reached.

     We need to remove the label from the exception_handler_label
     list and remove the associated NOTE_EH_REGION_BEG and
     NOTE_EH_REGION_END notes.  */
  insn = BLOCK_HEAD (i);
  if (GET_CODE (insn) == CODE_LABEL)
    {
      rtx x, *prev = &exception_handler_labels;

      for (x = exception_handler_labels; x; x = XEXP (x, 1))
	{
	  if (XEXP (x, 0) == insn)
	    {
	      /* Found a match, splice this label out of the
		 EH label list.  */
	      *prev = XEXP (x, 1);
	      XEXP (x, 1) = NULL_RTX;
	      XEXP (x, 0) = NULL_RTX;

	      /* Remove the handler from all regions */
	      remove_handler (insn);
	      deleted_handler = 1;
	      break;
	    }
	  prev = &XEXP (x, 1);
	}
    }

  /* Walk the insns of the block, building a chain of NOTEs that need to be
     kept.  */
  insn = BLOCK_HEAD (i);
  for (;;)
    {
      if (GET_CODE (insn) == BARRIER)
	abort ();
      else if (GET_CODE (insn) == NOTE && NOTE_LINE_NUMBER (insn) != NOTE_INSN_DELETED)
	{
	  if (kept_head == 0)
	    kept_head = kept_tail = insn;
	  else
	    {
	      NEXT_INSN (kept_tail) = insn;
	      PREV_INSN (insn) = kept_tail;
	      kept_tail = insn;
	    }
	}
      if (insn == BLOCK_END (i))
	break;
      insn = NEXT_INSN (insn);
    }
  insn = NEXT_INSN (insn);

  /* BARRIERs are between basic blocks, not part of one.
     Delete a BARRIER if the preceding jump is deleted.
     We cannot alter a BARRIER into a NOTE
     because it is too short; but we can really delete
     it because it is not part of a basic block.  */
  if (insn != 0 && GET_CODE (insn) == BARRIER)
    insn = NEXT_INSN (insn);

  /* Now unchain all of the block, and put the chain of kept notes in its
     place.  */
  if (kept_head == 0)
    {
      NEXT_INSN (PREV_INSN (BLOCK_HEAD (i))) = insn;
      if (insn != 0)
	PREV_INSN (insn) = PREV_INSN (BLOCK_HEAD (i));
      else
	set_last_insn (PREV_INSN (BLOCK_HEAD(i)));
    }
  else
    {
      NEXT_INSN (PREV_INSN (BLOCK_HEAD (i))) = kept_head;
      if (insn != 0)
	PREV_INSN (insn) = kept_tail;

      PREV_INSN (kept_head) = PREV_INSN (BLOCK_HEAD (i));
      NEXT_INSN (kept_tail) = insn;

      /* This must happen after NEXT_INSN (kept_tail) has been reinitialized
	 since set_last_insn will abort if it detects a non-NULL NEXT_INSN
	 field in its argument.  */
      if (insn == NULL_RTX)
	set_last_insn (kept_tail);
    }

  /* Each time we delete some basic blocks,
     see if there is a jump around them that is
     being turned into a no-op.  If so, delete it.  */

  if (block_live_static[i - 1])
    {
      register int j;
      for (j = i + 1; j < n_basic_blocks; j++)
	if (block_live_static[j])
	  {
	    rtx label;
	    insn = BLOCK_END (i - 1);
	    if (GET_CODE (insn) == JUMP_INSN
		/* An unconditional jump is the only possibility
		   we must check for, since a conditional one
		   would make these blocks live.  */
		&& simplejump_p (insn)
		&& (label = XEXP (SET_SRC (PATTERN (insn)), 0), 1)
		&& INSN_UID (label) != 0
		&& BLOCK_NUM (label) == j)
	      {
		PUT_CODE (insn, NOTE);
		NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
		NOTE_SOURCE_FILE (insn) = 0;
		if (GET_CODE (NEXT_INSN (insn)) != BARRIER)
		  abort ();
		delete_insn (NEXT_INSN (insn));
	      }
	    break;
	  }
    }

  return deleted_handler;
}

/* Perform data flow analysis.
   F is the first insn of the function and NREGS the number of register numbers
   in use.  */

void
life_analysis (f, nregs, file)
     rtx f;
     int nregs;
     FILE *file;
{
#ifdef ELIMINABLE_REGS
  register size_t i;
  static struct {int from, to; } eliminables[] = ELIMINABLE_REGS;
#endif

  /* Record which registers will be eliminated.  We use this in
     mark_used_regs.  */

  CLEAR_HARD_REG_SET (elim_reg_set);

#ifdef ELIMINABLE_REGS
  for (i = 0; i < sizeof eliminables / sizeof eliminables[0]; i++)
    SET_HARD_REG_BIT (elim_reg_set, eliminables[i].from);
#else
  SET_HARD_REG_BIT (elim_reg_set, FRAME_POINTER_REGNUM);
#endif

  /* We want alias analysis information for local dead store elimination.  */
  init_alias_analysis ();
  life_analysis_1 (f, nregs);
  end_alias_analysis ();

  if (file)
    dump_flow_info (file);

  free_basic_block_vars (1);
}

/* Free the variables allocated by find_basic_blocks.

   KEEP_HEAD_END_P is non-zero if BLOCK_HEAD and BLOCK_END
   are not to be freed.  */

void
free_basic_block_vars (keep_head_end_p)
     int keep_head_end_p;
{
  if (basic_block_loop_depth)
    {
      free (basic_block_loop_depth);
      basic_block_loop_depth = 0;
    }
  if (uid_block_number)
    {
      free (uid_block_number);
      uid_block_number = 0;
    }
  if (uid_volatile)
    {
      free (uid_volatile);
      uid_volatile = 0;
    }

  if (! keep_head_end_p && x_basic_block_head)
    {
      free (x_basic_block_head);
      x_basic_block_head = 0;
      free (x_basic_block_end);
      x_basic_block_end = 0;
    }
}

/* Return nonzero if the destination of SET equals the source.  */
static int
set_noop_p (set)
     rtx set;
{
  rtx src = SET_SRC (set);
  rtx dst = SET_DEST (set);
  if (GET_CODE (src) == REG && GET_CODE (dst) == REG
      && REGNO (src) == REGNO (dst))
    return 1;
  if (GET_CODE (src) != SUBREG || GET_CODE (dst) != SUBREG
      || SUBREG_WORD (src) != SUBREG_WORD (dst))
    return 0;
  src = SUBREG_REG (src);
  dst = SUBREG_REG (dst);
  if (GET_CODE (src) == REG && GET_CODE (dst) == REG
      && REGNO (src) == REGNO (dst))
    return 1;
  return 0;
}

/* Return nonzero if an insn consists only of SETs, each of which only sets a
   value to itself.  */
static int
noop_move_p (insn)
     rtx insn;
{
  rtx pat = PATTERN (insn);

  /* Insns carrying these notes are useful later on.  */
  if (find_reg_note (insn, REG_EQUAL, NULL_RTX))
    return 0;

  if (GET_CODE (pat) == SET && set_noop_p (pat))
    return 1;

  if (GET_CODE (pat) == PARALLEL)
    {
      int i;
      /* If nothing but SETs of registers to themselves,
	 this insn can also be deleted.  */
      for (i = 0; i < XVECLEN (pat, 0); i++)
	{
	  rtx tem = XVECEXP (pat, 0, i);

	  if (GET_CODE (tem) == USE
	      || GET_CODE (tem) == CLOBBER)
	    continue;

	  if (GET_CODE (tem) != SET || ! set_noop_p (tem))
	    return 0;
	}

      return 1;
    }
  return 0;
}

static void
notice_stack_pointer_modification (x, pat)
     rtx x;
     rtx pat ATTRIBUTE_UNUSED;
{
  if (x == stack_pointer_rtx
      /* The stack pointer is only modified indirectly as the result
	 of a push until later in flow.  See the comments in rtl.texi
	 regarding Embedded Side-Effects on Addresses.  */
      || (GET_CODE (x) == MEM
	  && (GET_CODE (XEXP (x, 0)) == PRE_DEC
	      || GET_CODE (XEXP (x, 0)) == PRE_INC
	      || GET_CODE (XEXP (x, 0)) == POST_DEC
	      || GET_CODE (XEXP (x, 0)) == POST_INC)
	  && XEXP (XEXP (x, 0), 0) == stack_pointer_rtx))
    current_function_sp_is_unchanging = 0;
}

/* Record which insns refer to any volatile memory
   or for any reason can't be deleted just because they are dead stores.
   Also, delete any insns that copy a register to itself.
   And see if the stack pointer is modified.  */
static void
record_volatile_insns (f)
     rtx f;
{
  rtx insn;
  for (insn = f; insn; insn = NEXT_INSN (insn))
    {
      enum rtx_code code1 = GET_CODE (insn);
      if (code1 == CALL_INSN)
	INSN_VOLATILE (insn) = 1;
      else if (code1 == INSN || code1 == JUMP_INSN)
	{
	  if (GET_CODE (PATTERN (insn)) != USE
	      && volatile_refs_p (PATTERN (insn)))
	    INSN_VOLATILE (insn) = 1;

	  /* A SET that makes space on the stack cannot be dead.
	     (Such SETs occur only for allocating variable-size data,
	     so they will always have a PLUS or MINUS according to the
	     direction of stack growth.)
	     Even if this function never uses this stack pointer value,
	     signal handlers do!  */
	  else if (code1 == INSN && GET_CODE (PATTERN (insn)) == SET
		   && SET_DEST (PATTERN (insn)) == stack_pointer_rtx
#ifdef STACK_GROWS_DOWNWARD
		   && GET_CODE (SET_SRC (PATTERN (insn))) == MINUS
#else
		   && GET_CODE (SET_SRC (PATTERN (insn))) == PLUS
#endif
		   && XEXP (SET_SRC (PATTERN (insn)), 0) == stack_pointer_rtx)
	    INSN_VOLATILE (insn) = 1;

	  /* Delete (in effect) any obvious no-op moves.  */
	  else if (noop_move_p (insn))
	    {
	      PUT_CODE (insn, NOTE);
	      NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
	      NOTE_SOURCE_FILE (insn) = 0;
	    }
	}

      /* Check if insn modifies the stack pointer.  */
      if ( current_function_sp_is_unchanging
	   && GET_RTX_CLASS (GET_CODE (insn)) == 'i')
	note_stores (PATTERN (insn), notice_stack_pointer_modification);
    }
}

/* Mark those regs which are needed at the end of the function as live
   at the end of the last basic block.  */
static void
mark_regs_live_at_end (set)
     regset set;
{
  int i;
  
#ifdef EXIT_IGNORE_STACK
  if (! EXIT_IGNORE_STACK
      || (! FRAME_POINTER_REQUIRED
	  && ! current_function_calls_alloca
	  && flag_omit_frame_pointer)
      || current_function_sp_is_unchanging)
#endif
    /* If exiting needs the right stack value,
       consider the stack pointer live at the end of the function.  */
    SET_REGNO_REG_SET (set, STACK_POINTER_REGNUM);

  /* Mark the frame pointer is needed at the end of the function.  If
     we end up eliminating it, it will be removed from the live list
     of each basic block by reload.  */

  SET_REGNO_REG_SET (set, FRAME_POINTER_REGNUM);
#if FRAME_POINTER_REGNUM != HARD_FRAME_POINTER_REGNUM
  /* If they are different, also mark the hard frame pointer as live */
  SET_REGNO_REG_SET (set, HARD_FRAME_POINTER_REGNUM);
#endif      


  /* Mark all global registers and all registers used by the epilogue
     as being live at the end of the function since they may be
     referenced by our caller.  */
  for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
    if (global_regs[i]
#ifdef EPILOGUE_USES
	|| EPILOGUE_USES (i)
#endif
	)
      SET_REGNO_REG_SET (set, i);
}

/* Determine which registers are live at the start of each
   basic block of the function whose first insn is F.
   NREGS is the number of registers used in F.
   We allocate the vector basic_block_live_at_start
   and the regsets that it points to, and fill them with the data.
   regset_size and regset_bytes are also set here.  */

static void
life_analysis_1 (f, nregs)
     rtx f;
     int nregs;
{
  int first_pass;
  int changed;
  /* For each basic block, a bitmask of regs
     live on exit from the block.  */
  regset *basic_block_live_at_end;
  /* For each basic block, a bitmask of regs
     live on entry to a successor-block of this block.
     If this does not match basic_block_live_at_end,
     that must be updated, and the block must be rescanned.  */
  regset *basic_block_new_live_at_end;
  /* For each basic block, a bitmask of regs
     whose liveness at the end of the basic block
     can make a difference in which regs are live on entry to the block.
     These are the regs that are set within the basic block,
     possibly excluding those that are used after they are set.  */
  regset *basic_block_significant;
  register int i;
  char save_regs_ever_live[FIRST_PSEUDO_REGISTER];

  struct obstack flow_obstack;

  gcc_obstack_init (&flow_obstack);

  max_regno = nregs;

  /* The post-reload life analysis have (on a global basis) the same registers
     live as was computed by reload itself.

     Otherwise elimination offsets and such may be incorrect.

     Reload will make some registers as live even though they do not appear
     in the rtl.  */
  if (reload_completed)
    bcopy (regs_ever_live, save_regs_ever_live, (sizeof (regs_ever_live)));

  bzero (regs_ever_live, sizeof regs_ever_live);

  /* Allocate and zero out many data structures
     that will record the data from lifetime analysis.  */

  allocate_for_life_analysis ();

  reg_next_use = (rtx *) alloca (nregs * sizeof (rtx));
  bzero ((char *) reg_next_use, nregs * sizeof (rtx));

  /* Set up several regset-vectors used internally within this function.
     Their meanings are documented above, with their declarations.  */

  basic_block_live_at_end
    = (regset *) alloca (n_basic_blocks * sizeof (regset));

  /* Don't use alloca since that leads to a crash rather than an error message
     if there isn't enough space.
     Don't use oballoc since we may need to allocate other things during
     this function on the temporary obstack.  */
  init_regset_vector (basic_block_live_at_end, n_basic_blocks, &flow_obstack);

  basic_block_new_live_at_end
    = (regset *) alloca (n_basic_blocks * sizeof (regset));
  init_regset_vector (basic_block_new_live_at_end, n_basic_blocks,
		      &flow_obstack);

  basic_block_significant
    = (regset *) alloca (n_basic_blocks * sizeof (regset));
  init_regset_vector (basic_block_significant, n_basic_blocks, &flow_obstack);

  /* Assume that the stack pointer is unchanging if alloca hasn't been used.
     This will be cleared by record_volatile_insns if it encounters an insn
     which modifies the stack pointer.  */
  current_function_sp_is_unchanging = !current_function_calls_alloca;

  record_volatile_insns (f);

  if (n_basic_blocks > 0)
    {
      mark_regs_live_at_end (basic_block_live_at_end[n_basic_blocks - 1]);
      COPY_REG_SET (basic_block_new_live_at_end[n_basic_blocks - 1],
		    basic_block_live_at_end[n_basic_blocks - 1]);
    }

  /* Propagate life info through the basic blocks
     around the graph of basic blocks.

     This is a relaxation process: each time a new register
     is live at the end of the basic block, we must scan the block
     to determine which registers are, as a consequence, live at the beginning
     of that block.  These registers must then be marked live at the ends
     of all the blocks that can transfer control to that block.
     The process continues until it reaches a fixed point.  */

  first_pass = 1;
  changed = 1;
  while (changed)
    {
      changed = 0;
      for (i = n_basic_blocks - 1; i >= 0; i--)
	{
	  int consider = first_pass;
	  int must_rescan = first_pass;
	  register int j;

	  if (!first_pass)
	    {
	      /* Set CONSIDER if this block needs thinking about at all
		 (that is, if the regs live now at the end of it
		 are not the same as were live at the end of it when
		 we last thought about it).
		 Set must_rescan if it needs to be thought about
		 instruction by instruction (that is, if any additional
		 reg that is live at the end now but was not live there before
		 is one of the significant regs of this basic block).  */

	      EXECUTE_IF_AND_COMPL_IN_REG_SET
		(basic_block_new_live_at_end[i],
		 basic_block_live_at_end[i], 0, j,
		 {
		   consider = 1;
		   if (REGNO_REG_SET_P (basic_block_significant[i], j))
		     {
		       must_rescan = 1;
		       goto done;
		     }
		 });
	    done:
	      if (! consider)
		continue;
	    }

	  /* The live_at_start of this block may be changing,
	     so another pass will be required after this one.  */
	  changed = 1;

	  if (! must_rescan)
	    {
	      /* No complete rescan needed;
		 just record those variables newly known live at end
		 as live at start as well.  */
	      IOR_AND_COMPL_REG_SET (basic_block_live_at_start[i],
				     basic_block_new_live_at_end[i],
				     basic_block_live_at_end[i]);

	      IOR_AND_COMPL_REG_SET (basic_block_live_at_end[i],
				     basic_block_new_live_at_end[i],
				     basic_block_live_at_end[i]);
	    }
	  else
	    {
	      /* Update the basic_block_live_at_start
		 by propagation backwards through the block.  */
	      COPY_REG_SET (basic_block_live_at_end[i],
			    basic_block_new_live_at_end[i]);
	      COPY_REG_SET (basic_block_live_at_start[i],
			    basic_block_live_at_end[i]);
	      propagate_block (basic_block_live_at_start[i],
			       BLOCK_HEAD (i), BLOCK_END (i), 0,
			       first_pass ? basic_block_significant[i]
			       : (regset) 0,
			       i);
	    }

	  {
	    int_list_ptr p;

	    /* Update the basic_block_new_live_at_end's of
	       all the blocks that reach this one.  */
	    for (p = basic_block_pred[i]; p; p = p->next)
	      {
		register int from_block = INT_LIST_VAL (p);
		IOR_REG_SET (basic_block_new_live_at_end[from_block],
			     basic_block_live_at_start[i]);
	      }
	  }
#ifdef USE_C_ALLOCA
	  alloca (0);
#endif
	}
      first_pass = 0;
    }

  /* The only pseudos that are live at the beginning of the function are
     those that were not set anywhere in the function.  local-alloc doesn't
     know how to handle these correctly, so mark them as not local to any
     one basic block.  */

  if (n_basic_blocks > 0)
    EXECUTE_IF_SET_IN_REG_SET (basic_block_live_at_start[0],
			       FIRST_PSEUDO_REGISTER, i,
			       {
				 REG_BASIC_BLOCK (i) = REG_BLOCK_GLOBAL;
			       });

  /* Now the life information is accurate.
     Make one more pass over each basic block
     to delete dead stores, create autoincrement addressing
     and record how many times each register is used, is set, or dies.

     To save time, we operate directly in basic_block_live_at_end[i],
     thus destroying it (in fact, converting it into a copy of
     basic_block_live_at_start[i]).  This is ok now because
     basic_block_live_at_end[i] is no longer used past this point.  */

  for (i = 0; i < n_basic_blocks; i++)
    {
      propagate_block (basic_block_live_at_end[i],
		       BLOCK_HEAD (i), BLOCK_END (i), 1,
		       (regset) 0, i);
#ifdef USE_C_ALLOCA
      alloca (0);
#endif
    }

#if 0
  /* Something live during a setjmp should not be put in a register
     on certain machines which restore regs from stack frames
     rather than from the jmpbuf.
     But we don't need to do this for the user's variables, since
     ANSI says only volatile variables need this.  */
#ifdef LONGJMP_RESTORE_FROM_STACK
  EXECUTE_IF_SET_IN_REG_SET (regs_live_at_setjmp,
			     FIRST_PSEUDO_REGISTER, i,
			     {
			       if (regno_reg_rtx[i] != 0
				   && ! REG_USERVAR_P (regno_reg_rtx[i]))
				 {
				   REG_LIVE_LENGTH (i) = -1;
				   REG_BASIC_BLOCK (i) = -1;
				 }
			     });
#endif
#endif

  /* We have a problem with any pseudoreg that
     lives across the setjmp.  ANSI says that if a
     user variable does not change in value
     between the setjmp and the longjmp, then the longjmp preserves it.
     This includes longjmp from a place where the pseudo appears dead.
     (In principle, the value still exists if it is in scope.)
     If the pseudo goes in a hard reg, some other value may occupy
     that hard reg where this pseudo is dead, thus clobbering the pseudo.
     Conclusion: such a pseudo must not go in a hard reg.  */
  EXECUTE_IF_SET_IN_REG_SET (regs_live_at_setjmp,
			     FIRST_PSEUDO_REGISTER, i,
			     {
			       if (regno_reg_rtx[i] != 0)
				 {
				   REG_LIVE_LENGTH (i) = -1;
				   REG_BASIC_BLOCK (i) = -1;
				 }
			     });

  /* Restore regs_ever_live that was provided by reload.  */
  if (reload_completed)
    bcopy (save_regs_ever_live, regs_ever_live, (sizeof (regs_ever_live)));

  free_regset_vector (basic_block_live_at_end, n_basic_blocks);
  free_regset_vector (basic_block_new_live_at_end, n_basic_blocks);
  free_regset_vector (basic_block_significant, n_basic_blocks);
  basic_block_live_at_end = (regset *)0;
  basic_block_new_live_at_end = (regset *)0;
  basic_block_significant = (regset *)0;

  obstack_free (&flow_obstack, NULL_PTR);
}

/* Subroutines of life analysis.  */

/* Allocate the permanent data structures that represent the results
   of life analysis.  Not static since used also for stupid life analysis.  */

void
allocate_for_life_analysis ()
{
  register int i;

  /* Recalculate the register space, in case it has grown.  Old style
     vector oriented regsets would set regset_{size,bytes} here also.  */
  allocate_reg_info (max_regno, FALSE, FALSE);

  /* Because both reg_scan and flow_analysis want to set up the REG_N_SETS
     information, explicitly reset it here.  The allocation should have
     already happened on the previous reg_scan pass.  Make sure in case
     some more registers were allocated.  */
  for (i = 0; i < max_regno; i++)
    REG_N_SETS (i) = 0;

  basic_block_live_at_start
    = (regset *) oballoc (n_basic_blocks * sizeof (regset));
  init_regset_vector (basic_block_live_at_start, n_basic_blocks,
		      function_obstack);

  regs_live_at_setjmp = OBSTACK_ALLOC_REG_SET (function_obstack);
  CLEAR_REG_SET (regs_live_at_setjmp);
}

/* Make each element of VECTOR point at a regset.  The vector has
   NELTS elements, and space is allocated from the ALLOC_OBSTACK
   obstack.  */

/* CYGNUS LOCAL LRS */
void
init_regset_vector (vector, nelts, alloc_obstack)
     regset *vector;
     int nelts;
     struct obstack *alloc_obstack;
{
  register int i;

  for (i = 0; i < nelts; i++)
    {
      vector[i] = OBSTACK_ALLOC_REG_SET (alloc_obstack);
      CLEAR_REG_SET (vector[i]);
    }
}

/* Release any additional space allocated for each element of VECTOR point
   other than the regset header itself.  The vector has NELTS elements.  */

void
free_regset_vector (vector, nelts)
     regset *vector;
     int nelts;
{
  register int i;

  for (i = 0; i < nelts; i++)
    FREE_REG_SET (vector[i]);
}

/* Compute the registers live at the beginning of a basic block
   from those live at the end.

   When called, OLD contains those live at the end.
   On return, it contains those live at the beginning.
   FIRST and LAST are the first and last insns of the basic block.

   FINAL is nonzero if we are doing the final pass which is not
   for computing the life info (since that has already been done)
   but for acting on it.  On this pass, we delete dead stores,
   set up the logical links and dead-variables lists of instructions,
   and merge instructions for autoincrement and autodecrement addresses.

   SIGNIFICANT is nonzero only the first time for each basic block.
   If it is nonzero, it points to a regset in which we store
   a 1 for each register that is set within the block.

   BNUM is the number of the basic block.  */

static void
propagate_block (old, first, last, final, significant, bnum)
     register regset old;
     rtx first;
     rtx last;
     int final;
     regset significant;
     int bnum;
{
  register rtx insn;
  rtx prev;
  regset live;
  regset dead;

  /* The loop depth may change in the middle of a basic block.  Since we
     scan from end to beginning, we start with the depth at the end of the
     current basic block, and adjust as we pass ends and starts of loops.  */
  loop_depth = basic_block_loop_depth[bnum];

  dead = ALLOCA_REG_SET ();
  live = ALLOCA_REG_SET ();

  cc0_live = 0;
  mem_set_list = NULL_RTX;

  /* Include any notes at the end of the block in the scan.
     This is in case the block ends with a call to setjmp.  */

  while (NEXT_INSN (last) != 0 && GET_CODE (NEXT_INSN (last)) == NOTE)
    {
      /* Look for loop boundaries, we are going forward here.  */
      last = NEXT_INSN (last);
      if (NOTE_LINE_NUMBER (last) == NOTE_INSN_LOOP_BEG)
	loop_depth++;
      else if (NOTE_LINE_NUMBER (last) == NOTE_INSN_LOOP_END)
	loop_depth--;
    }

  if (final)
    {
      register int i;

      /* Process the regs live at the end of the block.
	 Mark them as not local to any one basic block. */
      EXECUTE_IF_SET_IN_REG_SET (old, 0, i,
				 {
				   REG_BASIC_BLOCK (i) = REG_BLOCK_GLOBAL;
				 });
    }

  /* Scan the block an insn at a time from end to beginning.  */

  for (insn = last; ; insn = prev)
    {
      prev = PREV_INSN (insn);

      if (GET_CODE (insn) == NOTE)
	{
	  /* Look for loop boundaries, remembering that we are going
	     backwards.  */
	  if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_LOOP_END)
	    loop_depth++;
	  else if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_LOOP_BEG)
	    loop_depth--;

	  /* If we have LOOP_DEPTH == 0, there has been a bookkeeping error. 
	     Abort now rather than setting register status incorrectly.  */
	  if (loop_depth == 0)
	    abort ();

	  /* If this is a call to `setjmp' et al,
	     warn if any non-volatile datum is live.  */

	  if (final && NOTE_LINE_NUMBER (insn) == NOTE_INSN_SETJMP)
	    IOR_REG_SET (regs_live_at_setjmp, old);
	}

      /* Update the life-status of regs for this insn.
	 First DEAD gets which regs are set in this insn
	 then LIVE gets which regs are used in this insn.
	 Then the regs live before the insn
	 are those live after, with DEAD regs turned off,
	 and then LIVE regs turned on.  */

      else if (GET_RTX_CLASS (GET_CODE (insn)) == 'i')
	{
	  register int i;
	  rtx note = find_reg_note (insn, REG_RETVAL, NULL_RTX);
	  int insn_is_dead
	    = (insn_dead_p (PATTERN (insn), old, 0, REG_NOTES (insn))
	       /* Don't delete something that refers to volatile storage!  */
	       && ! INSN_VOLATILE (insn));
	  int libcall_is_dead 
	    = (insn_is_dead && note != 0
	       && libcall_dead_p (PATTERN (insn), old, note, insn));

	  /* If an instruction consists of just dead store(s) on final pass,
	     "delete" it by turning it into a NOTE of type NOTE_INSN_DELETED.
	     We could really delete it with delete_insn, but that
	     can cause trouble for first or last insn in a basic block.  */
	  if (final && insn_is_dead)
	    {
	      PUT_CODE (insn, NOTE);
	      NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
	      NOTE_SOURCE_FILE (insn) = 0;

	      /* CC0 is now known to be dead.  Either this insn used it,
		 in which case it doesn't anymore, or clobbered it,
		 so the next insn can't use it.  */
	      cc0_live = 0;

	      /* If this insn is copying the return value from a library call,
		 delete the entire library call.  */
	      if (libcall_is_dead)
		{
		  rtx first = XEXP (note, 0);
		  rtx p = insn;
		  while (INSN_DELETED_P (first))
		    first = NEXT_INSN (first);
		  while (p != first)
		    {
		      p = PREV_INSN (p);
		      PUT_CODE (p, NOTE);
		      NOTE_LINE_NUMBER (p) = NOTE_INSN_DELETED;
		      NOTE_SOURCE_FILE (p) = 0;
		    }
		}
	      goto flushed;
	    }

	  CLEAR_REG_SET (dead);
	  CLEAR_REG_SET (live);

	  /* See if this is an increment or decrement that can be
	     merged into a following memory address.  */
#ifdef AUTO_INC_DEC
	  {
	    register rtx x = single_set (insn);

	    /* Does this instruction increment or decrement a register?  */
	    if (!reload_completed
		&& final && x != 0
		&& GET_CODE (SET_DEST (x)) == REG
		&& (GET_CODE (SET_SRC (x)) == PLUS
		    || GET_CODE (SET_SRC (x)) == MINUS)
		&& XEXP (SET_SRC (x), 0) == SET_DEST (x)
		&& GET_CODE (XEXP (SET_SRC (x), 1)) == CONST_INT
		/* Ok, look for a following memory ref we can combine with.
		   If one is found, change the memory ref to a PRE_INC
		   or PRE_DEC, cancel this insn, and return 1.
		   Return 0 if nothing has been done.  */
		&& try_pre_increment_1 (insn))
	      goto flushed;
	  }
#endif /* AUTO_INC_DEC */

	  /* If this is not the final pass, and this insn is copying the
	     value of a library call and it's dead, don't scan the
	     insns that perform the library call, so that the call's
	     arguments are not marked live.  */
	  if (libcall_is_dead)
	    {
	      /* Mark the dest reg as `significant'.  */
	      mark_set_regs (old, dead, PATTERN (insn), NULL_RTX, significant);

	      insn = XEXP (note, 0);
	      prev = PREV_INSN (insn);
	    }
	  else if (GET_CODE (PATTERN (insn)) == SET
		   && SET_DEST (PATTERN (insn)) == stack_pointer_rtx
		   && GET_CODE (SET_SRC (PATTERN (insn))) == PLUS
		   && XEXP (SET_SRC (PATTERN (insn)), 0) == stack_pointer_rtx
		   && GET_CODE (XEXP (SET_SRC (PATTERN (insn)), 1)) == CONST_INT)
	    /* We have an insn to pop a constant amount off the stack.
	       (Such insns use PLUS regardless of the direction of the stack,
	       and any insn to adjust the stack by a constant is always a pop.)
	       These insns, if not dead stores, have no effect on life.  */
	    ;
	  else
	    {
	      /* Any regs live at the time of a call instruction
		 must not go in a register clobbered by calls.
		 Find all regs now live and record this for them.  */

	      if (GET_CODE (insn) == CALL_INSN && final)
		EXECUTE_IF_SET_IN_REG_SET (old, 0, i,
					   {
					     REG_N_CALLS_CROSSED (i)++;
					   });

	      /* LIVE gets the regs used in INSN;
		 DEAD gets those set by it.  Dead insns don't make anything
		 live.  */

	      mark_set_regs (old, dead, PATTERN (insn),
			     final ? insn : NULL_RTX, significant);

	      /* If an insn doesn't use CC0, it becomes dead since we 
		 assume that every insn clobbers it.  So show it dead here;
		 mark_used_regs will set it live if it is referenced.  */
	      cc0_live = 0;

	      if (! insn_is_dead)
		mark_used_regs (old, live, PATTERN (insn), final, insn);

	      /* Sometimes we may have inserted something before INSN (such as
		 a move) when we make an auto-inc.  So ensure we will scan
		 those insns.  */
#ifdef AUTO_INC_DEC
	      prev = PREV_INSN (insn);
#endif

	      if (! insn_is_dead && GET_CODE (insn) == CALL_INSN)
		{
		  register int i;

		  rtx note;

	          for (note = CALL_INSN_FUNCTION_USAGE (insn);
		       note;
		       note = XEXP (note, 1))
		    if (GET_CODE (XEXP (note, 0)) == USE)
		      mark_used_regs (old, live, SET_DEST (XEXP (note, 0)),
				      final, insn);

		  /* Each call clobbers all call-clobbered regs that are not
		     global or fixed.  Note that the function-value reg is a
		     call-clobbered reg, and mark_set_regs has already had
		     a chance to handle it.  */

		  for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
		    if (call_used_regs[i] && ! global_regs[i]
			&& ! fixed_regs[i])
		      SET_REGNO_REG_SET (dead, i);

		  /* The stack ptr is used (honorarily) by a CALL insn.  */
		  SET_REGNO_REG_SET (live, STACK_POINTER_REGNUM);

		  /* Calls may also reference any of the global registers,
		     so they are made live.  */
		  for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
		    if (global_regs[i])
		      mark_used_regs (old, live,
				      gen_rtx_REG (reg_raw_mode[i], i),
				      final, insn);

		  /* Calls also clobber memory.  */
		  mem_set_list = NULL_RTX;
		}

	      /* Update OLD for the registers used or set.  */
	      AND_COMPL_REG_SET (old, dead);
	      IOR_REG_SET (old, live);

	    }

	  /* On final pass, update counts of how many insns each reg is live
	     at.  */
	  if (final)
	    EXECUTE_IF_SET_IN_REG_SET (old, 0, i,
				       { REG_LIVE_LENGTH (i)++; });
	}
    flushed: ;
      if (insn == first)
	break;
    }

  FREE_REG_SET (dead);
  FREE_REG_SET (live);
}

/* Return 1 if X (the body of an insn, or part of it) is just dead stores
   (SET expressions whose destinations are registers dead after the insn).
   NEEDED is the regset that says which regs are alive after the insn.

   Unless CALL_OK is non-zero, an insn is needed if it contains a CALL.

   If X is the entire body of an insn, NOTES contains the reg notes
   pertaining to the insn.  */

static int
insn_dead_p (x, needed, call_ok, notes)
     rtx x;
     regset needed;
     int call_ok;
     rtx notes ATTRIBUTE_UNUSED;
{
  enum rtx_code code = GET_CODE (x);

#ifdef AUTO_INC_DEC
  /* If flow is invoked after reload, we must take existing AUTO_INC
     expresions into account.  */
  if (reload_completed)
    {
      for ( ; notes; notes = XEXP (notes, 1))
	{
	  if (REG_NOTE_KIND (notes) == REG_INC)
	    {
	      int regno = REGNO (XEXP (notes, 0));

	      /* Don't delete insns to set global regs.  */
	      if ((regno < FIRST_PSEUDO_REGISTER && global_regs[regno])
		  || REGNO_REG_SET_P (needed, regno))
		return 0;
	    }
	}
    }
#endif

  /* If setting something that's a reg or part of one,
     see if that register's altered value will be live.  */

  if (code == SET)
    {
      rtx r = SET_DEST (x);

      /* A SET that is a subroutine call cannot be dead.  */
      if (! call_ok && GET_CODE (SET_SRC (x)) == CALL)
	return 0;

#ifdef HAVE_cc0
      if (GET_CODE (r) == CC0)
	return ! cc0_live;
#endif
      
      if (GET_CODE (r) == MEM && ! MEM_VOLATILE_P (r))
	{
	  rtx temp;
	  /* Walk the set of memory locations we are currently tracking
	     and see if one is an identical match to this memory location.
	     If so, this memory write is dead (remember, we're walking
	     backwards from the end of the block to the start.  */
	  temp = mem_set_list;
	  while (temp)
	    {
	      if (rtx_equal_p (XEXP (temp, 0), r))
		return 1;
	      temp = XEXP (temp, 1);
	    }
	}

      while (GET_CODE (r) == SUBREG || GET_CODE (r) == STRICT_LOW_PART
	     || GET_CODE (r) == ZERO_EXTRACT)
	r = SUBREG_REG (r);

      if (GET_CODE (r) == REG)
	{
	  int regno = REGNO (r);

	  /* Don't delete insns to set global regs.  */
	  if ((regno < FIRST_PSEUDO_REGISTER && global_regs[regno])
	      /* Make sure insns to set frame pointer aren't deleted.  */
	      || regno == FRAME_POINTER_REGNUM
#if FRAME_POINTER_REGNUM != HARD_FRAME_POINTER_REGNUM
	      || regno == HARD_FRAME_POINTER_REGNUM
#endif
#if FRAME_POINTER_REGNUM != ARG_POINTER_REGNUM
	      /* Make sure insns to set arg pointer are never deleted
		 (if the arg pointer isn't fixed, there will be a USE for
		 it, so we can treat it normally).  */
	      || (regno == ARG_POINTER_REGNUM && fixed_regs[regno])
#endif
	      || REGNO_REG_SET_P (needed, regno))
	    return 0;

	  /* If this is a hard register, verify that subsequent words are
	     not needed.  */
	  if (regno < FIRST_PSEUDO_REGISTER)
	    {
	      int n = HARD_REGNO_NREGS (regno, GET_MODE (r));

	      while (--n > 0)
		if (REGNO_REG_SET_P (needed, regno+n))
		  return 0;
	    }

	  return 1;
	}
    }

  /* If performing several activities,
     insn is dead if each activity is individually dead.
     Also, CLOBBERs and USEs can be ignored; a CLOBBER or USE
     that's inside a PARALLEL doesn't make the insn worth keeping.  */
  else if (code == PARALLEL)
    {
      int i = XVECLEN (x, 0);

      for (i--; i >= 0; i--)
	if (GET_CODE (XVECEXP (x, 0, i)) != CLOBBER
	    && GET_CODE (XVECEXP (x, 0, i)) != USE
	    && ! insn_dead_p (XVECEXP (x, 0, i), needed, call_ok, NULL_RTX))
	  return 0;

      return 1;
    }

  /* A CLOBBER of a pseudo-register that is dead serves no purpose.  That
     is not necessarily true for hard registers.  */
  else if (code == CLOBBER && GET_CODE (XEXP (x, 0)) == REG
	   && REGNO (XEXP (x, 0)) >= FIRST_PSEUDO_REGISTER
	   && ! REGNO_REG_SET_P (needed, REGNO (XEXP (x, 0))))
    return 1;

  /* We do not check other CLOBBER or USE here.  An insn consisting of just
     a CLOBBER or just a USE should not be deleted.  */
  return 0;
}

/* If X is the pattern of the last insn in a libcall, and assuming X is dead,
   return 1 if the entire library call is dead.
   This is true if X copies a register (hard or pseudo)
   and if the hard return  reg of the call insn is dead.
   (The caller should have tested the destination of X already for death.)

   If this insn doesn't just copy a register, then we don't
   have an ordinary libcall.  In that case, cse could not have
   managed to substitute the source for the dest later on,
   so we can assume the libcall is dead.

   NEEDED is the bit vector of pseudoregs live before this insn.
   NOTE is the REG_RETVAL note of the insn.  INSN is the insn itself.  */

static int
libcall_dead_p (x, needed, note, insn)
     rtx x;
     regset needed;
     rtx note;
     rtx insn;
{
  register RTX_CODE code = GET_CODE (x);

  if (code == SET)
    {
      register rtx r = SET_SRC (x);
      if (GET_CODE (r) == REG)
	{
	  rtx call = XEXP (note, 0);
	  rtx call_pat;
	  register int i;

	  /* Find the call insn.  */
	  while (call != insn && GET_CODE (call) != CALL_INSN)
	    call = NEXT_INSN (call);

	  /* If there is none, do nothing special,
	     since ordinary death handling can understand these insns.  */
	  if (call == insn)
	    return 0;

	  /* See if the hard reg holding the value is dead.
	     If this is a PARALLEL, find the call within it.  */
	  call_pat = PATTERN (call);
	  if (GET_CODE (call_pat) == PARALLEL)
	    {
	      for (i = XVECLEN (call_pat, 0) - 1; i >= 0; i--)
		if (GET_CODE (XVECEXP (call_pat, 0, i)) == SET
		    && GET_CODE (SET_SRC (XVECEXP (call_pat, 0, i))) == CALL)
		  break;

	      /* This may be a library call that is returning a value
		 via invisible pointer.  Do nothing special, since
		 ordinary death handling can understand these insns.  */
	      if (i < 0)
		return 0;

	      call_pat = XVECEXP (call_pat, 0, i);
	    }

	  return insn_dead_p (call_pat, needed, 1, REG_NOTES (call));
	}
    }
  return 1;
}

/* Return 1 if register REGNO was used before it was set, i.e. if it is
   live at function entry.  Don't count global register variables, variables
   in registers that can be used for function arg passing, or variables in
   fixed hard registers.  */

int
regno_uninitialized (regno)
     int regno;
{
  if (n_basic_blocks == 0
      || (regno < FIRST_PSEUDO_REGISTER
	  && (global_regs[regno]
	      || fixed_regs[regno]
	      || FUNCTION_ARG_REGNO_P (regno))))
    return 0;

  return REGNO_REG_SET_P (basic_block_live_at_start[0], regno);
}

/* 1 if register REGNO was alive at a place where `setjmp' was called
   and was set more than once or is an argument.
   Such regs may be clobbered by `longjmp'.  */

int
regno_clobbered_at_setjmp (regno)
     int regno;
{
  if (n_basic_blocks == 0)
    return 0;

  return ((REG_N_SETS (regno) > 1
	   || REGNO_REG_SET_P (basic_block_live_at_start[0], regno))
	  && REGNO_REG_SET_P (regs_live_at_setjmp, regno));
}

/* INSN references memory, possibly using autoincrement addressing modes.
   Find any entries on the mem_set_list that need to be invalidated due
   to an address change.  */
static void
invalidate_mems_from_autoinc (insn)
     rtx insn;
{
  rtx note = REG_NOTES (insn);
  for (note = REG_NOTES (insn); note; note = XEXP (note, 1))
    {
      if (REG_NOTE_KIND (note) == REG_INC)
        {
          rtx temp = mem_set_list;
          rtx prev = NULL_RTX;

          while (temp)
	    {
	      if (reg_overlap_mentioned_p (XEXP (note, 0), XEXP (temp, 0)))
	        {
	          /* Splice temp out of list.  */
	          if (prev)
	            XEXP (prev, 1) = XEXP (temp, 1);
	          else
	            mem_set_list = XEXP (temp, 1);
	        }
	      else
	        prev = temp;
              temp = XEXP (temp, 1);
	    }
	}
    }
}

/* Process the registers that are set within X.
   Their bits are set to 1 in the regset DEAD,
   because they are dead prior to this insn.

   If INSN is nonzero, it is the insn being processed
   and the fact that it is nonzero implies this is the FINAL pass
   in propagate_block.  In this case, various info about register
   usage is stored, LOG_LINKS fields of insns are set up.  */

static void
mark_set_regs (needed, dead, x, insn, significant)
     regset needed;
     regset dead;
     rtx x;
     rtx insn;
     regset significant;
{
  register RTX_CODE code = GET_CODE (x);

  if (code == SET || code == CLOBBER)
    mark_set_1 (needed, dead, x, insn, significant);
  else if (code == PARALLEL)
    {
      register int i;
      for (i = XVECLEN (x, 0) - 1; i >= 0; i--)
	{
	  code = GET_CODE (XVECEXP (x, 0, i));
	  if (code == SET || code == CLOBBER)
	    mark_set_1 (needed, dead, XVECEXP (x, 0, i), insn, significant);
	}
    }
}

/* Process a single SET rtx, X.  */

static void
mark_set_1 (needed, dead, x, insn, significant)
     regset needed;
     regset dead;
     rtx x;
     rtx insn;
     regset significant;
{
  register int regno;
  register rtx reg = SET_DEST (x);

  /* Some targets place small structures in registers for
     return values of functions.  We have to detect this
     case specially here to get correct flow information.  */
  if (GET_CODE (reg) == PARALLEL
      && GET_MODE (reg) == BLKmode)
    {
      register int i;

      for (i = XVECLEN (reg, 0) - 1; i >= 0; i--)
	  mark_set_1 (needed, dead, XVECEXP (reg, 0, i), insn, significant);
      return;
    }

  /* Modifying just one hardware register of a multi-reg value
     or just a byte field of a register
     does not mean the value from before this insn is now dead.
     But it does mean liveness of that register at the end of the block
     is significant.

     Within mark_set_1, however, we treat it as if the register is
     indeed modified.  mark_used_regs will, however, also treat this
     register as being used.  Thus, we treat these insns as setting a
     new value for the register as a function of its old value.  This
     cases LOG_LINKS to be made appropriately and this will help combine.  */

  while (GET_CODE (reg) == SUBREG || GET_CODE (reg) == ZERO_EXTRACT
	 || GET_CODE (reg) == SIGN_EXTRACT
	 || GET_CODE (reg) == STRICT_LOW_PART)
    reg = XEXP (reg, 0);

  /* If this set is a MEM, then it kills any aliased writes. 
     If this set is a REG, then it kills any MEMs which use the reg.  */
  if (GET_CODE (reg) == MEM
      || GET_CODE (reg) == REG)
    {
      rtx temp = mem_set_list;
      rtx prev = NULL_RTX;

      while (temp)
	{
	  if ((GET_CODE (reg) == MEM
	       && output_dependence (XEXP (temp, 0), reg))
	      || (GET_CODE (reg) == REG
		  && reg_overlap_mentioned_p (reg, XEXP (temp, 0))))
	    {
	      /* Splice this entry out of the list.  */
	      if (prev)
		XEXP (prev, 1) = XEXP (temp, 1);
	      else
		mem_set_list = XEXP (temp, 1);
	    }
	  else
	    prev = temp;
	  temp = XEXP (temp, 1);
	}
    }

  /* If the memory reference had embedded side effects (autoincrement
     address modes.  Then we may need to kill some entries on the
     memory set list.  */
  if (insn && GET_CODE (reg) == MEM)
    invalidate_mems_from_autoinc (insn);

  if (GET_CODE (reg) == MEM && ! side_effects_p (reg)
      /* There are no REG_INC notes for SP, so we can't assume we'll see 
	 everything that invalidates it.  To be safe, don't eliminate any
	 stores though SP; none of them should be redundant anyway.  */
      && ! reg_mentioned_p (stack_pointer_rtx, reg))
    mem_set_list = gen_rtx_EXPR_LIST (VOIDmode, reg, mem_set_list);

  if (GET_CODE (reg) == REG
      && (regno = REGNO (reg), regno != FRAME_POINTER_REGNUM)
#if FRAME_POINTER_REGNUM != HARD_FRAME_POINTER_REGNUM
      && regno != HARD_FRAME_POINTER_REGNUM
#endif
#if FRAME_POINTER_REGNUM != ARG_POINTER_REGNUM
      && ! (regno == ARG_POINTER_REGNUM && fixed_regs[regno])
#endif
      && ! (regno < FIRST_PSEUDO_REGISTER && global_regs[regno]))
    /* && regno != STACK_POINTER_REGNUM) -- let's try without this.  */
    {
      int some_needed = REGNO_REG_SET_P (needed, regno);
      int some_not_needed = ! some_needed;

      /* Mark it as a significant register for this basic block.  */
      if (significant)
	SET_REGNO_REG_SET (significant, regno);

      /* Mark it as dead before this insn.  */
      SET_REGNO_REG_SET (dead, regno);

      /* A hard reg in a wide mode may really be multiple registers.
	 If so, mark all of them just like the first.  */
      if (regno < FIRST_PSEUDO_REGISTER)
	{
	  int n;

	  /* Nothing below is needed for the stack pointer; get out asap.
	     Eg, log links aren't needed, since combine won't use them.  */
	  if (regno == STACK_POINTER_REGNUM)
	    return;

	  n = HARD_REGNO_NREGS (regno, GET_MODE (reg));
	  while (--n > 0)
	    {
	      int regno_n = regno + n;
	      int needed_regno = REGNO_REG_SET_P (needed, regno_n);
	      if (significant)
		SET_REGNO_REG_SET (significant, regno_n);

	      SET_REGNO_REG_SET (dead, regno_n);
	      some_needed |= needed_regno;
	      some_not_needed |= ! needed_regno;
	    }
	}
      /* Additional data to record if this is the final pass.  */
      if (insn)
	{
	  register rtx y = reg_next_use[regno];
	  register int blocknum = BLOCK_NUM (insn);

	  /* If this is a hard reg, record this function uses the reg.  */

	  if (regno < FIRST_PSEUDO_REGISTER)
	    {
	      register int i;
	      int endregno = regno + HARD_REGNO_NREGS (regno, GET_MODE (reg));

	      for (i = regno; i < endregno; i++)
		{
		  /* The next use is no longer "next", since a store
		     intervenes.  */
		  reg_next_use[i] = 0;

		  regs_ever_live[i] = 1;
		  REG_N_SETS (i)++;
		}
	    }
	  else
	    {
	      /* The next use is no longer "next", since a store
		 intervenes.  */
	      reg_next_use[regno] = 0;

	      /* Keep track of which basic blocks each reg appears in.  */

	      if (REG_BASIC_BLOCK (regno) == REG_BLOCK_UNKNOWN)
		REG_BASIC_BLOCK (regno) = blocknum;
	      else if (REG_BASIC_BLOCK (regno) != blocknum)
		REG_BASIC_BLOCK (regno) = REG_BLOCK_GLOBAL;

	      /* Count (weighted) references, stores, etc.  This counts a
		 register twice if it is modified, but that is correct.  */
	      REG_N_SETS (regno)++;

	      REG_N_REFS (regno) += loop_depth;
		  
	      /* The insns where a reg is live are normally counted
		 elsewhere, but we want the count to include the insn
		 where the reg is set, and the normal counting mechanism
		 would not count it.  */
	      REG_LIVE_LENGTH (regno)++;
	    }

	  if (! some_not_needed)
	    {
	      /* Make a logical link from the next following insn
		 that uses this register, back to this insn.
		 The following insns have already been processed.

		 We don't build a LOG_LINK for hard registers containing
		 in ASM_OPERANDs.  If these registers get replaced,
		 we might wind up changing the semantics of the insn,
		 even if reload can make what appear to be valid assignments
		 later.  */
	      if (y && (BLOCK_NUM (y) == blocknum)
		  && (regno >= FIRST_PSEUDO_REGISTER
		      || asm_noperands (PATTERN (y)) < 0))
		LOG_LINKS (y)
		  = gen_rtx_INSN_LIST (VOIDmode, insn, LOG_LINKS (y));
	    }
	  else if (! some_needed)
	    {
	      /* Note that dead stores have already been deleted when possible
		 If we get here, we have found a dead store that cannot
		 be eliminated (because the same insn does something useful).
		 Indicate this by marking the reg being set as dying here.  */
	      REG_NOTES (insn)
		= gen_rtx_EXPR_LIST (REG_UNUSED, reg, REG_NOTES (insn));
	      REG_N_DEATHS (REGNO (reg))++;
	    }
	  else
	    {
	      /* This is a case where we have a multi-word hard register
		 and some, but not all, of the words of the register are
		 needed in subsequent insns.  Write REG_UNUSED notes
		 for those parts that were not needed.  This case should
		 be rare.  */

	      int i;

	      for (i = HARD_REGNO_NREGS (regno, GET_MODE (reg)) - 1;
		   i >= 0; i--)
		if (!REGNO_REG_SET_P (needed, regno + i))
		  REG_NOTES (insn)
		    = gen_rtx_EXPR_LIST (REG_UNUSED,
					 gen_rtx_REG (reg_raw_mode[regno + i],
						      regno + i),
					 REG_NOTES (insn));
	    }
	}
    }
  else if (GET_CODE (reg) == REG)
    reg_next_use[regno] = 0;

  /* If this is the last pass and this is a SCRATCH, show it will be dying
     here and count it.  */
  else if (GET_CODE (reg) == SCRATCH && insn != 0)
    {
      REG_NOTES (insn)
	= gen_rtx_EXPR_LIST (REG_UNUSED, reg, REG_NOTES (insn));
    }
}

#ifdef AUTO_INC_DEC

/* X is a MEM found in INSN.  See if we can convert it into an auto-increment
   reference.  */

static void
find_auto_inc (needed, x, insn)
     regset needed;
     rtx x;
     rtx insn;
{
  rtx addr = XEXP (x, 0);
  HOST_WIDE_INT offset = 0;
  rtx set;

  /* Here we detect use of an index register which might be good for
     postincrement, postdecrement, preincrement, or predecrement.  */

  if (GET_CODE (addr) == PLUS && GET_CODE (XEXP (addr, 1)) == CONST_INT)
    offset = INTVAL (XEXP (addr, 1)), addr = XEXP (addr, 0);

  if (GET_CODE (addr) == REG)
    {
      register rtx y;
      register int size = GET_MODE_SIZE (GET_MODE (x));
      rtx use;
      rtx incr;
      int regno = REGNO (addr);

      /* Is the next use an increment that might make auto-increment? */
      if ((incr = reg_next_use[regno]) != 0
	  && (set = single_set (incr)) != 0
	  && GET_CODE (set) == SET
	  && BLOCK_NUM (incr) == BLOCK_NUM (insn)
	  /* Can't add side effects to jumps; if reg is spilled and
	     reloaded, there's no way to store back the altered value.  */
	  && GET_CODE (insn) != JUMP_INSN
	  && (y = SET_SRC (set), GET_CODE (y) == PLUS)
	  && XEXP (y, 0) == addr
	  && GET_CODE (XEXP (y, 1)) == CONST_INT
	  && ((HAVE_POST_INCREMENT
	       && (INTVAL (XEXP (y, 1)) == size && offset == 0))
	      || (HAVE_POST_DECREMENT
		  && (INTVAL (XEXP (y, 1)) == - size && offset == 0))
	      || (HAVE_PRE_INCREMENT
		  && (INTVAL (XEXP (y, 1)) == size && offset == size))
	      || (HAVE_PRE_DECREMENT
		  && (INTVAL (XEXP (y, 1)) == - size && offset == - size)))
	  /* Make sure this reg appears only once in this insn.  */
	  && (use = find_use_as_address (PATTERN (insn), addr, offset),
	      use != 0 && use != (rtx) 1))
	{
	  rtx q = SET_DEST (set);
	  enum rtx_code inc_code = (INTVAL (XEXP (y, 1)) == size
				    ? (offset ? PRE_INC : POST_INC)
				    : (offset ? PRE_DEC : POST_DEC));

	  if (dead_or_set_p (incr, addr))
	    {
	      /* This is the simple case.  Try to make the auto-inc.  If
		 we can't, we are done.  Otherwise, we will do any
		 needed updates below.  */
	      if (! validate_change (insn, &XEXP (x, 0),
				     gen_rtx_fmt_e (inc_code, Pmode, addr),
				     0))
		return;
	    }
	  else if (GET_CODE (q) == REG
		   /* PREV_INSN used here to check the semi-open interval
		      [insn,incr).  */
		   && ! reg_used_between_p (q,  PREV_INSN (insn), incr)
		   /* We must also check for sets of q as q may be
		      a call clobbered hard register and there may
		      be a call between PREV_INSN (insn) and incr.  */
		   && ! reg_set_between_p (q,  PREV_INSN (insn), incr))
	    {
	      /* We have *p followed sometime later by q = p+size.
		 Both p and q must be live afterward,
		 and q is not used between INSN and its assignment.
		 Change it to q = p, ...*q..., q = q+size.
		 Then fall into the usual case.  */
	      rtx insns, temp;

	      start_sequence ();
	      emit_move_insn (q, addr);
	      insns = get_insns ();
	      end_sequence ();

	      /* If anything in INSNS have UID's that don't fit within the
		 extra space we allocate earlier, we can't make this auto-inc.
		 This should never happen.  */
	      for (temp = insns; temp; temp = NEXT_INSN (temp))
		{
		  if (INSN_UID (temp) > max_uid_for_flow)
		    return;
		  BLOCK_NUM (temp) = BLOCK_NUM (insn);
		}

	      /* If we can't make the auto-inc, or can't make the
		 replacement into Y, exit.  There's no point in making
		 the change below if we can't do the auto-inc and doing
		 so is not correct in the pre-inc case.  */

	      validate_change (insn, &XEXP (x, 0),
			       gen_rtx_fmt_e (inc_code, Pmode, q),
			       1);
	      validate_change (incr, &XEXP (y, 0), q, 1);
	      if (! apply_change_group ())
		return;

	      /* We now know we'll be doing this change, so emit the
		 new insn(s) and do the updates.  */
	      emit_insns_before (insns, insn);

	      if (BLOCK_HEAD (BLOCK_NUM (insn)) == insn)
		BLOCK_HEAD (BLOCK_NUM (insn)) = insns;

	      /* INCR will become a NOTE and INSN won't contain a
		 use of ADDR.  If a use of ADDR was just placed in
		 the insn before INSN, make that the next use. 
		 Otherwise, invalidate it.  */
	      if (GET_CODE (PREV_INSN (insn)) == INSN
		  && GET_CODE (PATTERN (PREV_INSN (insn))) == SET
		  && SET_SRC (PATTERN (PREV_INSN (insn))) == addr)
		reg_next_use[regno] = PREV_INSN (insn);
	      else
		reg_next_use[regno] = 0;

	      addr = q;
	      regno = REGNO (q);

	      /* REGNO is now used in INCR which is below INSN, but
		 it previously wasn't live here.  If we don't mark
		 it as needed, we'll put a REG_DEAD note for it
		 on this insn, which is incorrect.  */
	      SET_REGNO_REG_SET (needed, regno);

	      /* If there are any calls between INSN and INCR, show
		 that REGNO now crosses them.  */
	      for (temp = insn; temp != incr; temp = NEXT_INSN (temp))
		if (GET_CODE (temp) == CALL_INSN)
		  REG_N_CALLS_CROSSED (regno)++;
	    }
	  else
	    return;

	  /* If we haven't returned, it means we were able to make the
	     auto-inc, so update the status.  First, record that this insn
	     has an implicit side effect.  */

	  REG_NOTES (insn)
	    = gen_rtx_EXPR_LIST (REG_INC, addr, REG_NOTES (insn));

	  /* Modify the old increment-insn to simply copy
	     the already-incremented value of our register.  */
	  if (! validate_change (incr, &SET_SRC (set), addr, 0))
	    abort ();

	  /* If that makes it a no-op (copying the register into itself) delete
	     it so it won't appear to be a "use" and a "set" of this
	     register.  */
	  if (SET_DEST (set) == addr)
	    {
	      PUT_CODE (incr, NOTE);
	      NOTE_LINE_NUMBER (incr) = NOTE_INSN_DELETED;
	      NOTE_SOURCE_FILE (incr) = 0;
	    }

	  if (regno >= FIRST_PSEUDO_REGISTER)
	    {
	      /* Count an extra reference to the reg.  When a reg is
		 incremented, spilling it is worse, so we want to make
		 that less likely.  */
	      REG_N_REFS (regno) += loop_depth;

	      /* Count the increment as a setting of the register,
		 even though it isn't a SET in rtl.  */
	      REG_N_SETS (regno)++;
	    }
	}
    }
}
#endif /* AUTO_INC_DEC */

/* Scan expression X and store a 1-bit in LIVE for each reg it uses.
   This is done assuming the registers needed from X
   are those that have 1-bits in NEEDED.

   On the final pass, FINAL is 1.  This means try for autoincrement
   and count the uses and deaths of each pseudo-reg.

   INSN is the containing instruction.  If INSN is dead, this function is not
   called.  */

static void
mark_used_regs (needed, live, x, final, insn)
     regset needed;
     regset live;
     rtx x;
     int final;
     rtx insn;
{
  register RTX_CODE code;
  register int regno;
  int i;

 retry:
  code = GET_CODE (x);
  switch (code)
    {
    case LABEL_REF:
    case SYMBOL_REF:
    case CONST_INT:
    case CONST:
    case CONST_DOUBLE:
    case PC:
    case ADDR_VEC:
    case ADDR_DIFF_VEC:
      return;

#ifdef HAVE_cc0
    case CC0:
      cc0_live = 1;
      return;
#endif

    case CLOBBER:
      /* If we are clobbering a MEM, mark any registers inside the address
	 as being used.  */
      if (GET_CODE (XEXP (x, 0)) == MEM)
	mark_used_regs (needed, live, XEXP (XEXP (x, 0), 0), final, insn);
      return;

    case MEM:
      /* Invalidate the data for the last MEM stored, but only if MEM is
	 something that can be stored into.  */
      if (GET_CODE (XEXP (x, 0)) == SYMBOL_REF
	  && CONSTANT_POOL_ADDRESS_P (XEXP (x, 0)))
	; /* needn't clear the memory set list */
      else
	{
	  rtx temp = mem_set_list;
	  rtx prev = NULL_RTX;

	  while (temp)
	    {
	      if (anti_dependence (XEXP (temp, 0), x))
		{
		  /* Splice temp out of the list.  */
		  if (prev)
		    XEXP (prev, 1) = XEXP (temp, 1);
		  else
		    mem_set_list = XEXP (temp, 1);
		}
	      else
		prev = temp;
	      temp = XEXP (temp, 1);
	    }
	}

      /* If the memory reference had embedded side effects (autoincrement
	 address modes.  Then we may need to kill some entries on the
	 memory set list.  */
      if (insn)
	invalidate_mems_from_autoinc (insn);

#ifdef AUTO_INC_DEC
      if (final)
	find_auto_inc (needed, x, insn);
#endif
      break;

    case SUBREG:
      if (GET_CODE (SUBREG_REG (x)) == REG
	  && REGNO (SUBREG_REG (x)) >= FIRST_PSEUDO_REGISTER
	  && (GET_MODE_SIZE (GET_MODE (x))
	      != GET_MODE_SIZE (GET_MODE (SUBREG_REG (x)))))
	REG_CHANGES_SIZE (REGNO (SUBREG_REG (x))) = 1;

      /* While we're here, optimize this case.  */
      x = SUBREG_REG (x);

      /* In case the SUBREG is not of a register, don't optimize */
      if (GET_CODE (x) != REG)
	{
	  mark_used_regs (needed, live, x, final, insn);
	  return;
	}

      /* ... fall through ...  */

    case REG:
      /* See a register other than being set
	 => mark it as needed.  */

      regno = REGNO (x);
      {
	int some_needed = REGNO_REG_SET_P (needed, regno);
	int some_not_needed = ! some_needed;

	SET_REGNO_REG_SET (live, regno);

	/* A hard reg in a wide mode may really be multiple registers.
	   If so, mark all of them just like the first.  */
	if (regno < FIRST_PSEUDO_REGISTER)
	  {
	    int n;

	    /* For stack ptr or fixed arg pointer,
	       nothing below can be necessary, so waste no more time.  */
	    if (regno == STACK_POINTER_REGNUM
#if FRAME_POINTER_REGNUM != HARD_FRAME_POINTER_REGNUM
		|| regno == HARD_FRAME_POINTER_REGNUM
#endif
#if FRAME_POINTER_REGNUM != ARG_POINTER_REGNUM
		|| (regno == ARG_POINTER_REGNUM && fixed_regs[regno])
#endif
		|| regno == FRAME_POINTER_REGNUM)
	      {
		/* If this is a register we are going to try to eliminate,
		   don't mark it live here.  If we are successful in
		   eliminating it, it need not be live unless it is used for
		   pseudos, in which case it will have been set live when
		   it was allocated to the pseudos.  If the register will not
		   be eliminated, reload will set it live at that point.  */

		if (! TEST_HARD_REG_BIT (elim_reg_set, regno))
		  regs_ever_live[regno] = 1;
		return;
	      }
	    /* No death notes for global register variables;
	       their values are live after this function exits.  */
	    if (global_regs[regno])
	      {
		if (final)
		  reg_next_use[regno] = insn;
		return;
	      }

	    n = HARD_REGNO_NREGS (regno, GET_MODE (x));
	    while (--n > 0)
	      {
		int regno_n = regno + n;
		int needed_regno = REGNO_REG_SET_P (needed, regno_n);

		SET_REGNO_REG_SET (live, regno_n);
		some_needed |= needed_regno;
		some_not_needed |= ! needed_regno;
	      }
	  }
	if (final)
	  {
	    /* Record where each reg is used, so when the reg
	       is set we know the next insn that uses it.  */

	    reg_next_use[regno] = insn;

	    if (regno < FIRST_PSEUDO_REGISTER)
	      {
		/* If a hard reg is being used,
		   record that this function does use it.  */

		i = HARD_REGNO_NREGS (regno, GET_MODE (x));
		if (i == 0)
		  i = 1;
		do
		  regs_ever_live[regno + --i] = 1;
		while (i > 0);
	      }
	    else
	      {
		/* Keep track of which basic block each reg appears in.  */

		register int blocknum = BLOCK_NUM (insn);

		if (REG_BASIC_BLOCK (regno) == REG_BLOCK_UNKNOWN)
		  REG_BASIC_BLOCK (regno) = blocknum;
		else if (REG_BASIC_BLOCK (regno) != blocknum)
		  REG_BASIC_BLOCK (regno) = REG_BLOCK_GLOBAL;

		/* Count (weighted) number of uses of each reg.  */

		REG_N_REFS (regno) += loop_depth;
	      }

	    /* Record and count the insns in which a reg dies.
	       If it is used in this insn and was dead below the insn
	       then it dies in this insn.  If it was set in this insn,
	       we do not make a REG_DEAD note; likewise if we already
	       made such a note.  */

	    if (some_not_needed
		&& ! dead_or_set_p (insn, x)
#if 0
		&& (regno >= FIRST_PSEUDO_REGISTER || ! fixed_regs[regno])
#endif
		)
	      {
		/* Check for the case where the register dying partially
		   overlaps the register set by this insn.  */
		if (regno < FIRST_PSEUDO_REGISTER
		    && HARD_REGNO_NREGS (regno, GET_MODE (x)) > 1)
		  {
		    int n = HARD_REGNO_NREGS (regno, GET_MODE (x));
		    while (--n >= 0)
		      some_needed |= dead_or_set_regno_p (insn, regno + n);
		  }

		/* If none of the words in X is needed, make a REG_DEAD
		   note.  Otherwise, we must make partial REG_DEAD notes.  */
		if (! some_needed)
		  {
		    REG_NOTES (insn)
		      = gen_rtx_EXPR_LIST (REG_DEAD, x, REG_NOTES (insn));
		    REG_N_DEATHS (regno)++;
		  }
		else
		  {
		    int i;

		    /* Don't make a REG_DEAD note for a part of a register
		       that is set in the insn.  */

		    for (i = HARD_REGNO_NREGS (regno, GET_MODE (x)) - 1;
			 i >= 0; i--)
		      if (!REGNO_REG_SET_P (needed, regno + i)
			  && ! dead_or_set_regno_p (insn, regno + i))
			REG_NOTES (insn)
			  = gen_rtx_EXPR_LIST (REG_DEAD,
					       gen_rtx_REG (reg_raw_mode[regno + i],
							    regno + i),
					       REG_NOTES (insn));
		  }
	      }
	  }
      }
      return;

    case SET:
      {
	register rtx testreg = SET_DEST (x);
	int mark_dest = 0;

	/* If storing into MEM, don't show it as being used.  But do
	   show the address as being used.  */
	if (GET_CODE (testreg) == MEM)
	  {
#ifdef AUTO_INC_DEC
	    if (final)
	      find_auto_inc (needed, testreg, insn);
#endif
	    mark_used_regs (needed, live, XEXP (testreg, 0), final, insn);
	    mark_used_regs (needed, live, SET_SRC (x), final, insn);
	    return;
	  }
	    
	/* Storing in STRICT_LOW_PART is like storing in a reg
	   in that this SET might be dead, so ignore it in TESTREG.
	   but in some other ways it is like using the reg.

	   Storing in a SUBREG or a bit field is like storing the entire
	   register in that if the register's value is not used
	   then this SET is not needed.  */
	while (GET_CODE (testreg) == STRICT_LOW_PART
	       || GET_CODE (testreg) == ZERO_EXTRACT
	       || GET_CODE (testreg) == SIGN_EXTRACT
	       || GET_CODE (testreg) == SUBREG)
	  {
	    if (GET_CODE (testreg) == SUBREG
		&& GET_CODE (SUBREG_REG (testreg)) == REG
		&& REGNO (SUBREG_REG (testreg)) >= FIRST_PSEUDO_REGISTER
		&& (GET_MODE_SIZE (GET_MODE (testreg))
		    != GET_MODE_SIZE (GET_MODE (SUBREG_REG (testreg)))))
	      REG_CHANGES_SIZE (REGNO (SUBREG_REG (testreg))) = 1;

	    /* Modifying a single register in an alternate mode
	       does not use any of the old value.  But these other
	       ways of storing in a register do use the old value.  */
	    if (GET_CODE (testreg) == SUBREG
		&& !(REG_SIZE (SUBREG_REG (testreg)) > REG_SIZE (testreg)))
	      ;
	    else
	      mark_dest = 1;

	    testreg = XEXP (testreg, 0);
	  }

	/* If this is a store into a register,
	   recursively scan the value being stored.  */

	if ((GET_CODE (testreg) == PARALLEL
	     && GET_MODE (testreg) == BLKmode)
	    || (GET_CODE (testreg) == REG
		&& (regno = REGNO (testreg), regno != FRAME_POINTER_REGNUM)
#if FRAME_POINTER_REGNUM != HARD_FRAME_POINTER_REGNUM
		&& regno != HARD_FRAME_POINTER_REGNUM
#endif
#if FRAME_POINTER_REGNUM != ARG_POINTER_REGNUM
		&& ! (regno == ARG_POINTER_REGNUM && fixed_regs[regno])
#endif
		))
	  /* We used to exclude global_regs here, but that seems wrong.
	     Storing in them is like storing in mem.  */
	  {
	    mark_used_regs (needed, live, SET_SRC (x), final, insn);
	    if (mark_dest)
	      mark_used_regs (needed, live, SET_DEST (x), final, insn);
	    return;
	  }
      }
      break;

    case RETURN:
      /* If exiting needs the right stack value, consider this insn as
	 using the stack pointer.  In any event, consider it as using
	 all global registers and all registers used by return.  */

#ifdef EXIT_IGNORE_STACK
      if (! EXIT_IGNORE_STACK
	  || (! FRAME_POINTER_REQUIRED
	      && ! current_function_calls_alloca
	      && flag_omit_frame_pointer)
	  || current_function_sp_is_unchanging)
#endif
	SET_REGNO_REG_SET (live, STACK_POINTER_REGNUM);

      for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
	if (global_regs[i]
#ifdef EPILOGUE_USES
	    || EPILOGUE_USES (i)
#endif
	    )
	  SET_REGNO_REG_SET (live, i);
      break;

    case ASM_OPERANDS:
    case UNSPEC_VOLATILE:
    case TRAP_IF:
    case ASM_INPUT:
      {
	/* Traditional and volatile asm instructions must be considered to use
	   and clobber all hard registers, all pseudo-registers and all of
	   memory.  So must TRAP_IF and UNSPEC_VOLATILE operations.

	   Consider for instance a volatile asm that changes the fpu rounding
	   mode.  An insn should not be moved across this even if it only uses
	   pseudo-regs because it might give an incorrectly rounded result. 

	   ?!? Unfortunately, marking all hard registers as live causes massive
	   problems for the register allocator and marking all pseudos as live
	   creates mountains of uninitialized variable warnings.

	   So for now, just clear the memory set list and mark any regs
	   we can find in ASM_OPERANDS as used.  */
	if (code != ASM_OPERANDS || MEM_VOLATILE_P (x))
	  mem_set_list = NULL_RTX;

        /* For all ASM_OPERANDS, we must traverse the vector of input operands.
	   We can not just fall through here since then we would be confused
	   by the ASM_INPUT rtx inside ASM_OPERANDS, which do not indicate
	   traditional asms unlike their normal usage.  */
	if (code == ASM_OPERANDS)
	  {
	    int j;

	    for (j = 0; j < ASM_OPERANDS_INPUT_LENGTH (x); j++)
	      mark_used_regs (needed, live, ASM_OPERANDS_INPUT (x, j),
			      final, insn);
	  }
	break;
      }

    default:
      break;
    }

  /* Recursively scan the operands of this expression.  */

  {
    register char *fmt = GET_RTX_FORMAT (code);
    register int i;
    
    for (i = GET_RTX_LENGTH (code) - 1; i >= 0; i--)
      {
	if (fmt[i] == 'e')
	  {
	    /* Tail recursive case: save a function call level.  */
	    if (i == 0)
	      {
		x = XEXP (x, 0);
		goto retry;
	      }
	    mark_used_regs (needed, live, XEXP (x, i), final, insn);
	  }
	else if (fmt[i] == 'E')
	  {
	    register int j;
	    for (j = 0; j < XVECLEN (x, i); j++)
	      mark_used_regs (needed, live, XVECEXP (x, i, j), final, insn);
	  }
      }
  }
}

#ifdef AUTO_INC_DEC

static int
try_pre_increment_1 (insn)
     rtx insn;
{
  /* Find the next use of this reg.  If in same basic block,
     make it do pre-increment or pre-decrement if appropriate.  */
  rtx x = single_set (insn);
  HOST_WIDE_INT amount = ((GET_CODE (SET_SRC (x)) == PLUS ? 1 : -1)
		* INTVAL (XEXP (SET_SRC (x), 1)));
  int regno = REGNO (SET_DEST (x));
  rtx y = reg_next_use[regno];
  if (y != 0
      && BLOCK_NUM (y) == BLOCK_NUM (insn)
      /* Don't do this if the reg dies, or gets set in y; a standard addressing
	 mode would be better.  */
      && ! dead_or_set_p (y, SET_DEST (x))
      && try_pre_increment (y, SET_DEST (x), amount))
    {
      /* We have found a suitable auto-increment
	 and already changed insn Y to do it.
	 So flush this increment-instruction.  */
      PUT_CODE (insn, NOTE);
      NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
      NOTE_SOURCE_FILE (insn) = 0;
      /* Count a reference to this reg for the increment
	 insn we are deleting.  When a reg is incremented.
	 spilling it is worse, so we want to make that
	 less likely.  */
      if (regno >= FIRST_PSEUDO_REGISTER)
	{
	  REG_N_REFS (regno) += loop_depth;
	  REG_N_SETS (regno)++;
	}
      return 1;
    }
  return 0;
}

/* Try to change INSN so that it does pre-increment or pre-decrement
   addressing on register REG in order to add AMOUNT to REG.
   AMOUNT is negative for pre-decrement.
   Returns 1 if the change could be made.
   This checks all about the validity of the result of modifying INSN.  */

static int
try_pre_increment (insn, reg, amount)
     rtx insn, reg;
     HOST_WIDE_INT amount;
{
  register rtx use;

  /* Nonzero if we can try to make a pre-increment or pre-decrement.
     For example, addl $4,r1; movl (r1),... can become movl +(r1),...  */
  int pre_ok = 0;
  /* Nonzero if we can try to make a post-increment or post-decrement.
     For example, addl $4,r1; movl -4(r1),... can become movl (r1)+,...
     It is possible for both PRE_OK and POST_OK to be nonzero if the machine
     supports both pre-inc and post-inc, or both pre-dec and post-dec.  */
  int post_ok = 0;

  /* Nonzero if the opportunity actually requires post-inc or post-dec.  */
  int do_post = 0;

  /* From the sign of increment, see which possibilities are conceivable
     on this target machine.  */
  if (HAVE_PRE_INCREMENT && amount > 0)
    pre_ok = 1;
  if (HAVE_POST_INCREMENT && amount > 0)
    post_ok = 1;

  if (HAVE_PRE_DECREMENT && amount < 0)
    pre_ok = 1;
  if (HAVE_POST_DECREMENT && amount < 0)
    post_ok = 1;

  if (! (pre_ok || post_ok))
    return 0;

  /* It is not safe to add a side effect to a jump insn
     because if the incremented register is spilled and must be reloaded
     there would be no way to store the incremented value back in memory.  */

  if (GET_CODE (insn) == JUMP_INSN)
    return 0;

  use = 0;
  if (pre_ok)
    use = find_use_as_address (PATTERN (insn), reg, 0);
  if (post_ok && (use == 0 || use == (rtx) 1))
    {
      use = find_use_as_address (PATTERN (insn), reg, -amount);
      do_post = 1;
    }

  if (use == 0 || use == (rtx) 1)
    return 0;

  if (GET_MODE_SIZE (GET_MODE (use)) != (amount > 0 ? amount : - amount))
    return 0;

  /* See if this combination of instruction and addressing mode exists.  */
  if (! validate_change (insn, &XEXP (use, 0),
			 gen_rtx_fmt_e (amount > 0
					? (do_post ? POST_INC : PRE_INC)
					: (do_post ? POST_DEC : PRE_DEC),
					Pmode, reg), 0))
    return 0;

  /* Record that this insn now has an implicit side effect on X.  */
  REG_NOTES (insn) = gen_rtx_EXPR_LIST (REG_INC, reg, REG_NOTES (insn));
  return 1;
}

#endif /* AUTO_INC_DEC */

/* Find the place in the rtx X where REG is used as a memory address.
   Return the MEM rtx that so uses it.
   If PLUSCONST is nonzero, search instead for a memory address equivalent to
   (plus REG (const_int PLUSCONST)).

   If such an address does not appear, return 0.
   If REG appears more than once, or is used other than in such an address,
   return (rtx)1.  */

rtx
find_use_as_address (x, reg, plusconst)
     register rtx x;
     rtx reg;
     HOST_WIDE_INT plusconst;
{
  enum rtx_code code = GET_CODE (x);
  char *fmt = GET_RTX_FORMAT (code);
  register int i;
  register rtx value = 0;
  register rtx tem;

  if (code == MEM && XEXP (x, 0) == reg && plusconst == 0)
    return x;

  if (code == MEM && GET_CODE (XEXP (x, 0)) == PLUS
      && XEXP (XEXP (x, 0), 0) == reg
      && GET_CODE (XEXP (XEXP (x, 0), 1)) == CONST_INT
      && INTVAL (XEXP (XEXP (x, 0), 1)) == plusconst)
    return x;

  if (code == SIGN_EXTRACT || code == ZERO_EXTRACT)
    {
      /* If REG occurs inside a MEM used in a bit-field reference,
	 that is unacceptable.  */
      if (find_use_as_address (XEXP (x, 0), reg, 0) != 0)
	return (rtx) (HOST_WIDE_INT) 1;
    }

  if (x == reg)
    return (rtx) (HOST_WIDE_INT) 1;

  for (i = GET_RTX_LENGTH (code) - 1; i >= 0; i--)
    {
      if (fmt[i] == 'e')
	{
	  tem = find_use_as_address (XEXP (x, i), reg, plusconst);
	  if (value == 0)
	    value = tem;
	  else if (tem != 0)
	    return (rtx) (HOST_WIDE_INT) 1;
	}
      if (fmt[i] == 'E')
	{
	  register int j;
	  for (j = XVECLEN (x, i) - 1; j >= 0; j--)
	    {
	      tem = find_use_as_address (XVECEXP (x, i, j), reg, plusconst);
	      if (value == 0)
		value = tem;
	      else if (tem != 0)
		return (rtx) (HOST_WIDE_INT) 1;
	    }
	}
    }

  return value;
}

/* Write information about registers and basic blocks into FILE.
   This is part of making a debugging dump.  */

void
dump_flow_info (file)
     FILE *file;
{
  register int i;
  static char *reg_class_names[] = REG_CLASS_NAMES;

  fprintf (file, "%d registers.\n", max_regno);

  for (i = FIRST_PSEUDO_REGISTER; i < max_regno; i++)
    if (REG_N_REFS (i))
      {
	enum reg_class class, altclass;
	fprintf (file, "\nRegister %d used %d times across %d insns",
		 i, REG_N_REFS (i), REG_LIVE_LENGTH (i));
	if (REG_BASIC_BLOCK (i) >= 0)
	  fprintf (file, " in block %d", REG_BASIC_BLOCK (i));
	if (REG_N_SETS (i))
  	  fprintf (file, "; set %d time%s", REG_N_SETS (i),
   		   (REG_N_SETS (i) == 1) ? "" : "s");
	if (REG_USERVAR_P (regno_reg_rtx[i]))
  	  fprintf (file, "; user var");
	if (REG_N_DEATHS (i) != 1)
	  fprintf (file, "; dies in %d places", REG_N_DEATHS (i));
	if (REG_N_CALLS_CROSSED (i) == 1)
	  fprintf (file, "; crosses 1 call");
	else if (REG_N_CALLS_CROSSED (i))
	  fprintf (file, "; crosses %d calls", REG_N_CALLS_CROSSED (i));
	if (PSEUDO_REGNO_BYTES (i) != UNITS_PER_WORD)
	  fprintf (file, "; %d bytes", PSEUDO_REGNO_BYTES (i));
	class = reg_preferred_class (i);
	altclass = reg_alternate_class (i);
	if (class != GENERAL_REGS || altclass != ALL_REGS)
	  {
	    if (altclass == ALL_REGS || class == ALL_REGS)
	      fprintf (file, "; pref %s", reg_class_names[(int) class]);
	    else if (altclass == NO_REGS)
	      fprintf (file, "; %s or none", reg_class_names[(int) class]);
	    else
	      fprintf (file, "; pref %s, else %s",
		       reg_class_names[(int) class],
		       reg_class_names[(int) altclass]);
	  }
	if (REGNO_POINTER_FLAG (i))
	  fprintf (file, "; pointer");
	fprintf (file, ".\n");
      }
  fprintf (file, "\n%d basic blocks.\n", n_basic_blocks);
  dump_bb_data (file, basic_block_pred, basic_block_succ, 1);
}


/* Like print_rtl, but also print out live information for the start of each
   basic block.  */

void
print_rtl_with_bb (outf, rtx_first)
     FILE *outf;
     rtx rtx_first;
{
  register rtx tmp_rtx;

  if (rtx_first == 0)
    fprintf (outf, "(nil)\n");

  else
    {
      int i, bb;
      enum bb_state { NOT_IN_BB, IN_ONE_BB, IN_MULTIPLE_BB };
      int max_uid = get_max_uid ();
      int *start = (int *) alloca (max_uid * sizeof (int));
      int *end = (int *) alloca (max_uid * sizeof (int));
      enum bb_state *in_bb_p = (enum bb_state *)
	alloca (max_uid * sizeof (enum bb_state));

      for (i = 0; i < max_uid; i++)
	{
	  start[i] = end[i] = -1;
	  in_bb_p[i] = NOT_IN_BB;
	}

      for (i = n_basic_blocks-1; i >= 0; i--)
	{
	  rtx x;
	  start[INSN_UID (BLOCK_HEAD (i))] = i;
	  end[INSN_UID (BLOCK_END (i))] = i;
	  for (x = BLOCK_HEAD (i); x != NULL_RTX; x = NEXT_INSN (x))
	    {
	      in_bb_p[ INSN_UID(x)]
		= (in_bb_p[ INSN_UID(x)] == NOT_IN_BB)
		 ? IN_ONE_BB : IN_MULTIPLE_BB;
	      if (x == BLOCK_END (i))
		break;
	    }
	}

      for (tmp_rtx = rtx_first; NULL != tmp_rtx; tmp_rtx = NEXT_INSN (tmp_rtx))
	{
	  int did_output;

	  if ((bb = start[INSN_UID (tmp_rtx)]) >= 0)
	    {
	      fprintf (outf, ";; Start of basic block %d, registers live:",
		       bb);

	      EXECUTE_IF_SET_IN_REG_SET (basic_block_live_at_start[bb], 0, i,
					 {
					   fprintf (outf, " %d", i);
					   if (i < FIRST_PSEUDO_REGISTER)
					     fprintf (outf, " [%s]",
						      reg_names[i]);
					 });
	      putc ('\n', outf);
	    }

	  if (in_bb_p[ INSN_UID(tmp_rtx)] == NOT_IN_BB
	      && GET_CODE (tmp_rtx) != NOTE
	      && GET_CODE (tmp_rtx) != BARRIER)
	    fprintf (outf, ";; Insn is not within a basic block\n");
	  else if (in_bb_p[ INSN_UID(tmp_rtx)] == IN_MULTIPLE_BB)
	    fprintf (outf, ";; Insn is in multiple basic blocks\n");

	  did_output = print_rtl_single (outf, tmp_rtx);

	  if ((bb = end[INSN_UID (tmp_rtx)]) >= 0)
	    fprintf (outf, ";; End of basic block %d\n", bb);

	  if (did_output)
	    putc ('\n', outf);
	}
    }
}


/* Integer list support.  */

/* Allocate a node from list *HEAD_PTR.  */

static int_list_ptr
alloc_int_list_node (head_ptr)
     int_list_block **head_ptr;
{
  struct int_list_block *first_blk = *head_ptr;

  if (first_blk == NULL || first_blk->nodes_left <= 0)
    {
      first_blk = (struct int_list_block *) xmalloc (sizeof (struct int_list_block));
      first_blk->nodes_left = INT_LIST_NODES_IN_BLK;
      first_blk->next = *head_ptr;
      *head_ptr = first_blk;
    }

  first_blk->nodes_left--;
  return &first_blk->nodes[first_blk->nodes_left];
}

/* Pointer to head of predecessor/successor block list.  */
static int_list_block *pred_int_list_blocks;

/* Add a new node to integer list LIST with value VAL.
   LIST is a pointer to a list object to allow for different implementations.
   If *LIST is initially NULL, the list is empty.
   The caller must not care whether the element is added to the front or
   to the end of the list (to allow for different implementations).  */

static int_list_ptr
add_int_list_node (blk_list, list, val)
     int_list_block **blk_list;
     int_list **list;
     int val;
{
  int_list_ptr p = alloc_int_list_node (blk_list);

  p->val = val;
  p->next = *list;
  *list = p;
  return p;
}

/* Free the blocks of lists at BLK_LIST.  */

void
free_int_list (blk_list)
     int_list_block **blk_list;
{
  int_list_block *p, *next;

  for (p = *blk_list; p != NULL; p = next)
    {
      next = p->next;
      free (p);
    }

  /* Mark list as empty for the next function we compile.  */
  *blk_list = NULL;
}

/* Predecessor/successor computation.  */

/* Mark PRED_BB a precessor of SUCC_BB,
   and conversely SUCC_BB a successor of PRED_BB.  */

static void
add_pred_succ (pred_bb, succ_bb, s_preds, s_succs, num_preds, num_succs)
     int pred_bb;
     int succ_bb;
     int_list_ptr *s_preds;
     int_list_ptr *s_succs;
     int *num_preds;
     int *num_succs;
{
  if (succ_bb != EXIT_BLOCK)
    {
      add_int_list_node (&pred_int_list_blocks, &s_preds[succ_bb], pred_bb);
      num_preds[succ_bb]++;
    }
  if (pred_bb != ENTRY_BLOCK)
    {
      add_int_list_node (&pred_int_list_blocks, &s_succs[pred_bb], succ_bb);
      num_succs[pred_bb]++;
    }
}

/* Compute the predecessors and successors for each block.  */
/* CYGNUS LOCAL edge splitting/law */
int
compute_preds_succs (s_preds, s_succs, num_preds, num_succs, split_edges)
     int_list_ptr *s_preds;
     int_list_ptr *s_succs;
     int *num_preds;
     int *num_succs;
     int split_edges;
{
  int bb;
  int changed = 0;

  bzero ((char *) s_preds, n_basic_blocks * sizeof (int_list_ptr));
  bzero ((char *) s_succs, n_basic_blocks * sizeof (int_list_ptr));
  bzero ((char *) num_preds, n_basic_blocks * sizeof (int));
  bzero ((char *) num_succs, n_basic_blocks * sizeof (int));

  /* It's somewhat stupid to simply copy the information.  The passes
     which use this function ought to be changed to refer directly to
     basic_block_succ and its relatives.  */
  for (bb = 0; bb < n_basic_blocks; bb++)
    {
      rtx jump = BLOCK_END (bb);
      enum rtx_code code = GET_CODE (jump);
      int_list_ptr p;

      for (p = basic_block_succ[bb]; p; p = p->next)
	add_pred_succ (bb, INT_LIST_VAL (p), s_preds, s_succs, num_preds,
		       num_succs);

      /* If this is a RETURN insn or a conditional jump in the last
	 basic block, or a non-jump insn in the last basic block, then
	 this block reaches the exit block.  */
      if ((code == JUMP_INSN && GET_CODE (PATTERN (jump)) == RETURN)
	  || (((code == JUMP_INSN
	        && condjump_p (jump) && !simplejump_p (jump))
	       || code != JUMP_INSN)
 	      && bb == n_basic_blocks - 1))
	add_pred_succ (bb, EXIT_BLOCK, s_preds, s_succs, num_preds, num_succs);
    }

  add_pred_succ (ENTRY_BLOCK, 0, s_preds, s_succs, num_preds, num_succs);

#if 0
  /* CYGNUS LOCAL edge-splitting/law */
  /* Now see what edges we should split.  */
  if (split_edges)
    {
      /* Array indexed by block number to determine if an in-edge to the
	 block has been split.  Used to prevent more than one in-edge
	 to any given block from being split.  */
      char *split_edge_to_block = (char *) alloca (n_basic_blocks);

      bzero (split_edge_to_block, n_basic_blocks);

      for (bb = 0; bb < n_basic_blocks; bb++)
	{
	  /* Find a block that has more than one successor.  */
	  if (num_succs[bb] > 1)
	    {
	      int_list_ptr p;

	      /* Now look at each successor block to see which have more than
	         one predecessor block.  */
	      for (p = s_succs[bb]; p != NULL; p = p->next)
	        {
	          int pred_bb = INT_LIST_VAL (p);

	          /* If our block falls into this successor (ie no jump), then
		     we can split this edge since the existance of this block
		     will not introduce any new jumps.  */
	          if (split_edge_to_block[pred_bb] == 0
		      && basic_block_drops_in[pred_bb]
		      && num_preds[pred_bb] > 1 && bb + 1 == pred_bb)
		    {
		      rtx insn, jump, label, olabel;

		      jump = BLOCK_END (bb);

		      /* Try to find the conditional jump at the end of the
		         current block.  If it's not a conditional jump, then
		         do not try and split the edge.  */
		      if (GET_CODE (jump) != JUMP_INSN || !condjump_p (jump))
		        continue;

		      label = gen_label_rtx ();

		      /* This code knows that find_basic_blocks always creates
		         a new basic block when it encounters a label.  The
		         label will be deleted by a later pass if it is never
		         used as a jump target.  */
		      label = emit_label_after (label, BLOCK_END (bb));
		      LABEL_NUSES (label) = 0;
		      split_edge_to_block[pred_bb] = 1;
		      changed = 1;
		    }

	         /* If our block jumps to this successor, and the successor
		    can only be reached via jumps, then we can split this
		    edge too since the jump from this block to the successor
		    can be redirected to a dummy block before the successor
		    (which then makes the successor a fall through).  */
	         else if (split_edge_to_block[pred_bb] == 0
			  && num_preds[pred_bb] > 1
			  && !basic_block_drops_in[pred_bb])
		    {
		      rtx insn, jump, label, olabel;

		      jump = BLOCK_END (bb);

		      /* Try to find the conditional jump at the end of the
		         current block.  If it's not a conditional jump, then
		         do not try and split the edge.  */
		      if (GET_CODE (jump) != JUMP_INSN || !condjump_p (jump))
		        continue;

		      /* Make sure we've found the right edge to split.  */
		      if (JUMP_LABEL (jump) != BLOCK_HEAD (pred_bb))
			continue;

		      /* Redirect the jump from this block to its sucessor to
		         use a new label.  */
		      label = gen_label_rtx ();
		      insn = emit_label_after (label,
					       PREV_INSN (BLOCK_HEAD (pred_bb)));
		      LABEL_NUSES (insn) = 0;

		      /* Make sure redirect_jump does not delete this label.  */
		      olabel = JUMP_LABEL (jump);
		      LABEL_NUSES (olabel)++;

		      redirect_jump (jump, label);
		      JUMP_LABEL (jump) = label;

		      /* Fix the reference count.  */
		      LABEL_NUSES (olabel)--;

		      split_edge_to_block[pred_bb] = 1;
		      changed = 1;
		    }

	          /* One might consider splitting other edges, but doing so
		     introduces new jumps in the code, and thus the cost of
		     the jump has to be weighed against the additional
		     redundancies we're likely to find.  */
	        }
	    }
	}

    }
#endif

  return changed;
}
/* END CYGNUS LOCAL */

void
dump_bb_data (file, preds, succs, live_info)
     FILE *file;
     int_list_ptr *preds;
     int_list_ptr *succs;
     int live_info;
{
  int bb;
  int_list_ptr p;

  fprintf (file, "BB data\n\n");
  for (bb = 0; bb < n_basic_blocks; bb++)
    {
      fprintf (file, "BB %d, start %d, end %d\n", bb,
	       INSN_UID (BLOCK_HEAD (bb)), INSN_UID (BLOCK_END (bb)));
      fprintf (file, "  preds:");
      for (p = preds[bb]; p != NULL; p = p->next)
	{
	  int pred_bb = INT_LIST_VAL (p);
	  if (pred_bb == ENTRY_BLOCK)
	    fprintf (file, " entry");
	  else
	    fprintf (file, " %d", pred_bb);
	}
      fprintf (file, "\n");
      fprintf (file, "  succs:");
      for (p = succs[bb]; p != NULL; p = p->next)
	{
	  int succ_bb = INT_LIST_VAL (p);
	  if (succ_bb == EXIT_BLOCK)
	    fprintf (file, " exit");
	  else
	    fprintf (file, " %d", succ_bb);
	}
      if (live_info)
	{
	  int regno;
	  fprintf (file, "\nRegisters live at start:");
	  for (regno = 0; regno < max_regno; regno++)
	    if (REGNO_REG_SET_P (basic_block_live_at_start[bb], regno))
	      fprintf (file, " %d", regno);
	  fprintf (file, "\n");
	}
      fprintf (file, "\n");
    }
  fprintf (file, "\n");
}

/* Free basic block data storage.  */

void
free_bb_mem ()
{
  free_int_list (&pred_int_list_blocks);
}

/* Compute dominator relationships.  */
void
compute_dominators (dominators, post_dominators, s_preds, s_succs)
     sbitmap *dominators;
     sbitmap *post_dominators;
     int_list_ptr *s_preds;
     int_list_ptr *s_succs;
{
  int bb, changed, passes;
  sbitmap *temp_bitmap;

  temp_bitmap = sbitmap_vector_alloc (n_basic_blocks, n_basic_blocks);
  sbitmap_vector_ones (dominators, n_basic_blocks);
  sbitmap_vector_ones (post_dominators, n_basic_blocks);
  sbitmap_vector_zero (temp_bitmap, n_basic_blocks);

  sbitmap_zero (dominators[0]);
  SET_BIT (dominators[0], 0);

  sbitmap_zero (post_dominators[n_basic_blocks-1]);
  SET_BIT (post_dominators[n_basic_blocks-1], 0);

  passes = 0;
  changed = 1;
  while (changed)
    {
      changed = 0;
      for (bb = 1; bb < n_basic_blocks; bb++)
	{
	  sbitmap_intersect_of_predecessors (temp_bitmap[bb], dominators,
					     bb, s_preds);
	  SET_BIT (temp_bitmap[bb], bb);
	  changed |= sbitmap_a_and_b (dominators[bb],
				      dominators[bb],
				      temp_bitmap[bb]);
	  sbitmap_intersect_of_successors (temp_bitmap[bb], post_dominators,
					   bb, s_succs);
	  SET_BIT (temp_bitmap[bb], bb);
	  changed |= sbitmap_a_and_b (post_dominators[bb],
				      post_dominators[bb],
				      temp_bitmap[bb]);
	}
      passes++;
    }

  free (temp_bitmap);
}

/* CYGNUS LOCAL law */
/* This is a fairly simple block merge optimization pass.

   We search for block pairs where the first block is succeeded by only
   the second block and the second block is preceeded only by the first
   block.

   If the blocks are not adjacent, then it must be the case that the
   first block jumps to the second.  With a little work the two blocks
   can be merged into a single larger block.

   The primary benefit of performing this optimization is better local
   optimization within the merged block.

   This optimization will also save a jump if the second block ended with
   an unconditional branch.


   Many improvements could be made to this pass to turn it into a real
   block scheduler.  Probably the most important components would
   be a branch predictor and code to convert from a block list to
   an insn chain by modfiying/adding/removing jumps as needed.

   Given a reducible flow graph (or sub-graph if the whole graph is not
   reducible) we would perform a DFS traversal of the nodes using the
   predictor to select a path at each conditional jump.
   
   First perform the DFS traversal starting at the header for inner
   natural loops.  As each loop is traversed, reduce it to a single
   node and work outward.  Process all natural loops in this manner.

   Once all loops are reduced perform the DFS traversal on the remaining
   flow graph.
   
   The net result would be a block ordering which should minimize branch
   penalties for the predicted path through a function.  As a side effect
   blocks which are not part of a loop would be removed from the loop.  */

void
merge_blocks (f)
     rtx f;
{
  int_list_ptr *s_preds, *s_succs;
  int *num_preds, *num_succs;
  int n_blocks_merged, bb, i;
  sbitmap headers, trailers;
  
  /* Don't try to perform this after the last CSE pass.  It's not worth
     the effort to try and maintain all the data structures that have
     to be preserved after that point.  Most of the benefits come from
     the first couple passes anyway.  */
  if (reload_completed)
    return;

  /* ??? This does not work when EH is enabled.  The g++.eh/spec2.C test
     fails on a solaris2 host if this optimization is performed.
     1) The tests for moving a block decide it is safe if it contains no EH
     region.  This isn't sufficient, and may be unnecessary.  We can't merge
     two blocks if the pred and succ are in different EH regions.  Otherwise,
     a throw may end up in the wrong catch clause.
     2) Calls that throw end a block, and if the call returns a value, the
     call may end up in a different block than the insn which stores the
     return value into a pseudo.  This may not be safe for machines using
     SMALL_REGISTER_CLASSES.
     3) throw/catch edges should be distinguished from branch/fallthrough
     edges, and different heuristics should be applied to them.  */

  if (flag_exceptions)
    return;

  /* First break the program into basic blocks.  */
  find_basic_blocks (f, max_reg_num (), NULL);

  /* If we have only a single block, then there's nothing to do.  */
  if (n_basic_blocks <= 1)
    {
      /* Free storage allocated by find_basic_blocks.  */
      free_basic_block_vars (0);
      return;
    }

  /* We need predecessor/successor lists as well as pred/succ counts for
     each basic block.  */
  s_preds = (int_list_ptr *) alloca (n_basic_blocks * sizeof (int_list_ptr));
  s_succs = (int_list_ptr *) alloca (n_basic_blocks * sizeof (int_list_ptr));
  num_preds = (int *) alloca (n_basic_blocks * sizeof (int));
  num_succs = (int *) alloca (n_basic_blocks * sizeof (int));
  compute_preds_succs (s_preds, s_succs, num_preds, num_succs, 0);

  /* We only need to note which blocks are headers and which blocks are
     trailers.  The pred/succ lists encode the actual chain from one block
     to the next.  */
  headers = sbitmap_alloc (n_basic_blocks);
  trailers = sbitmap_alloc (n_basic_blocks);
  sbitmap_zero (headers);
  sbitmap_zero (trailers);

  n_blocks_merged = 0;

  /* Walk over each block looking for mergeable blocks.  */
  for (bb = 0; bb < n_basic_blocks; bb++)
    {
      int succ_bb;
      rtx temp;

      /* If this block has more than one successor, then there's nothing
	 more to do.  */
      if (num_succs[bb] != 1)
	continue;

      succ_bb = INT_LIST_VAL (s_succs[bb]);

      /* If the successor block is the exit block, then there's nothing
	 more to do, similarly if the successor block is the last block.  */
      if (succ_bb == EXIT_BLOCK || succ_bb == n_basic_blocks - 1)
	continue;

      /* If the successor has more than one precedessor, then there's
	 nothing more to do.  */
      if (num_preds[succ_bb] > 1)
	continue;

      /* If the successor block is the next block, then there's nothing
	 to do.  */
      if (bb + 1 == succ_bb)
	continue;

      /* If the successor block has an EH region begin/end note, then
	 we can not perform this optimization.  */
      temp = BLOCK_HEAD (succ_bb);
      while (temp)
	{
	  if (GET_CODE (temp) == NOTE
              && (NOTE_LINE_NUMBER (temp) == NOTE_INSN_EH_REGION_BEG
                  || NOTE_LINE_NUMBER (temp) == NOTE_INSN_EH_REGION_END))
	    break;

	  if (temp == BLOCK_END (succ_bb))
	    break;
	  temp = NEXT_INSN (temp);
	}

      /* If we stopped on an EH note, then there's nothing we can do.  */
      if (temp
	  && GET_CODE (temp) == NOTE
	  && (NOTE_LINE_NUMBER (temp) == NOTE_INSN_EH_REGION_BEG
	      || NOTE_LINE_NUMBER (temp) == NOTE_INSN_EH_REGION_END))
	continue;

      /* We must keep a tablejump/switch insn immediately in front of its
	 associated jump table.  They should actually be a single block
	 which would avoid this hair.  But I'm not going to try and tackle
	 that problem right now.

	 For now we just special case handling of this situation and
	 avoid doing anything with such blocks.
	
	 Luckily the tablejump and jump table itself must be adjacent.  This
	 property makes it relatively easy to detect this case.  */
      temp = BLOCK_END (succ_bb);
      /* A tablejump will "jump" to the next instruction, which is the jump
         table itself.  */
      if (temp
	  && GET_CODE (temp) == JUMP_INSN
          && JUMP_LABEL (temp)
	  && JUMP_LABEL (temp) == next_nonnote_insn (temp))
	{
	  rtx next = next_nonnote_insn (JUMP_LABEL (temp));

	  /* Now see if the next insn is a jump table, if it is, then we do
	     not want to merge this block.  */
	  if (next
	      && GET_CODE (next) == JUMP_INSN
	      && (GET_CODE (PATTERN (next)) == ADDR_VEC
		  || GET_CODE (PATTERN (next)) == ADDR_DIFF_VEC))
	    continue;
	}

      /* If BB is not already in a chain, then it becomes a chain
	 header.  */
      if (!TEST_BIT (trailers, bb))
	SET_BIT (headers, bb);

      /* SUCC_BB could have been marked as a header already.  It is no longer
	 a header, so clear the bit.  */
      RESET_BIT (headers, succ_bb);

      /* SUCC_BB is in a chain now.  */
      SET_BIT (trailers, succ_bb);

      n_blocks_merged++;
    }

  /* Now rearrange insn chain to reflect the desired block ordering.

     When the merged block does not end with an unconditional branch,
     we must insert an unconditional branch to the fallthrough path
     of successor block to preserve program correctness.

     We only perform a very limited number of transformations on the
     block ordering, so this code is relatively simple right now.  */
  if (n_blocks_merged != 0)
    {

      for (i = 0; i < n_basic_blocks; i++)
	{
	  int_list_ptr ps;
	  int current_block, trailer_block;

	  /* There's nothing to do if this is not a chain header.  */
	  if (! TEST_BIT (headers, i))
	    continue;

	  /* Splice the insn chain so that the trailer block(s)
	     immediately follow the header block.  */
	  ps = s_succs[i];
	  current_block = i;
	  while (ps && TEST_BIT (trailers, INT_LIST_VAL (ps)))
	    {
	      rtx start, end, next, oldlabel, insertpoint;

	      trailer_block = INT_LIST_VAL (ps);

	      /* Find the start/end points for the insns to move.  */
	      start = BLOCK_HEAD (trailer_block);

	      end = BLOCK_END (trailer_block);

	      /* If the next nonnote insn after the end of the trailer
		 block is a BARRIER, then we copy it too.  */
	      next = next_nonnote_insn (end);
	      if (next && GET_CODE (next) == BARRIER)
		end = next;

	      /* We insert insns from the trailer block after the BARRIER
		 which follows thisn block.  */
	      insertpoint = BLOCK_END (current_block);
	      next = next_nonnote_insn (insertpoint);
	      if (next && GET_CODE (next) == BARRIER)
		insertpoint = next;

	      /* Move block and loop notes out of the chain so that we do not
		 disturb their order.  */
	      /* ??? A slightly better solution would be to squeeze out all
		 non-nested notes, and adjust the block trees appropriately. 
		 Even better would be to have a tighter connection between
		 block trees and rtl so that this is not necessary.  */
	      start = squeeze_notes (start, end);
	  
	      /* Scramble the insn chain.  */
	      reorder_insns (start, end, insertpoint);

	      /* If the last copied insn was not a BARRIER, then we must insert
		 a jump from the end of TRAILER_BLOCK to the start of
		 TRAILER_BLOCK + 1 to preserve the meaning of the code.  */
	      if (GET_CODE (end) != BARRIER)
		{
		  rtx jump, insn, label;

		  start = BLOCK_HEAD (trailer_block + 1);
		  /* Make sure the start of the block which used to follow the
		     trailer block starts with a CODE_LABEL.  */
		  if (GET_CODE (start) != CODE_LABEL)
		    {
		      label = gen_label_rtx ();
		      LABEL_NUSES (label) = 1;
		      BLOCK_HEAD (trailer_block + 1)
			= emit_label_after (label, PREV_INSN (start));
		    }
		  else
		    {
		      label = start;
		      LABEL_NUSES (label)++;
		    }


		  jump = emit_jump_insn_after (gen_jump (label),
					       BLOCK_END (trailer_block));
		  BLOCK_END (trailer_block) = jump;
		  JUMP_LABEL (jump) = label;
		  emit_barrier_after (jump);
		}

	      /* Now remove the redundant JUMP at the end of the previous
		 basic block.  */
	      delete_jump (BLOCK_END (current_block));

	      /* Continue the loop in case we merged more than two blocks into
		 a single chain.  */
	      current_block = trailer_block;
	      ps = s_succs[current_block];
	    }
	}
    }

  /* There is one important case the above code does not handle.  If the
     last block is only reachable by one predecessor, then the predecessor
     should be tacked onto the head of the last block.  If the predecessor
     block was a trailer, then we should walk up to the head of its block
     list.  Not yet implemented.  */
  if (num_preds[n_basic_blocks - 1] == 1
      && num_succs[INT_LIST_VAL (s_preds[n_basic_blocks - 1])] == 1)
    {
      rtx start, end, insertpoint;
      int pred = INT_LIST_VAL (s_preds[n_basic_blocks - 1]);

      /* If the predecessor is a trailer block, or it alrady is the immediate
	 predecessor of the last block, then there is nothing to do.  */
      if (!TEST_BIT (trailers, pred) && pred != n_basic_blocks - 2)
	{
	  rtx temp;
	  /* Find the start/end points for the insns to move.  We leave the
	     jump to the last block in its original position.  */
	  start = BLOCK_HEAD (pred);
	  end = BLOCK_END (pred);

	  /* If the predecessor block has an EH region begin/end note, then
	     we can not perform this optimization.  */
	  temp = start;
	  while (temp)
	    {
	      if (GET_CODE (temp) == NOTE
		  && (NOTE_LINE_NUMBER (temp) == NOTE_INSN_EH_REGION_BEG
		      || NOTE_LINE_NUMBER (temp) == NOTE_INSN_EH_REGION_END))
		break;
	      if (temp == BLOCK_END (pred))
		break;
	      temp = NEXT_INSN (temp);
	    }

	  /* If we stopped on an EH note, then there's nothing we can do.  */
	  if (start != end
	      && ! (temp
		    && GET_CODE (temp) == NOTE
		    && (NOTE_LINE_NUMBER (temp) == NOTE_INSN_EH_REGION_BEG
		        || NOTE_LINE_NUMBER (temp) == NOTE_INSN_EH_REGION_END)))
	    {
	      /* For simplicity we'll leave any CODE_LABEL and JUMP in their
		 original location.  If they are dead, then they'll be deleted
		 by the jump optimizer.  If not branches which reach the
		 label will be threaded to the epilogue, which makes the label
		 and jump dead anyway.  */
	      if (GET_CODE (start) == CODE_LABEL)
		start = NEXT_INSN (start);

	      /* The first check is necessary in case the block contains
		 only the CODE_LABEL skipped above and only one other
		 instruction.  */
	      if (start != end && next_nonnote_insn (start) != end)
		{
		  end = PREV_INSN (end);
		  /* We insert insns from the predecessor block after the
		     CODE_LABEL which starts the final block.  */
		  insertpoint = BLOCK_HEAD (n_basic_blocks - 1);

		  start = squeeze_notes (start, end);

		  /* Scramble the insn chain.  */
		  reorder_insns (start, end, insertpoint);
		}
	    }
	}
    }
  

  /* Now that we have maximal blocks, it would be a good time to run natural
     loop analysis and rip out blocks that are physically inside loops, but
     not part of the loop itself.  */
     
  /* Free storage allocated by find_basic_blocks.  */
  free_basic_block_vars (0);
  free_bb_mem ();
}
/* END CYGNUS LOCAL */
/* Count for a single SET rtx, X.  */

static void
count_reg_sets_1 (x)
     rtx x;
{
  register int regno;
  register rtx reg = SET_DEST (x);

  /* Find the register that's set/clobbered.  */
  while (GET_CODE (reg) == SUBREG || GET_CODE (reg) == ZERO_EXTRACT
	 || GET_CODE (reg) == SIGN_EXTRACT
	 || GET_CODE (reg) == STRICT_LOW_PART)
    reg = XEXP (reg, 0);

  if (GET_CODE (reg) == PARALLEL
      && GET_MODE (reg) == BLKmode)
    {
      register int i;
      for (i = XVECLEN (reg, 0) - 1; i >= 0; i--)
	count_reg_sets_1 (XVECEXP (reg, 0, i));
      return;
    }

  if (GET_CODE (reg) == REG)
    {
      regno = REGNO (reg);
      if (regno >= FIRST_PSEUDO_REGISTER)
	{
	  /* Count (weighted) references, stores, etc.  This counts a
	     register twice if it is modified, but that is correct.  */
	  REG_N_SETS (regno)++;

	  REG_N_REFS (regno) += loop_depth;
	}
    }
}

/* Increment REG_N_SETS for each SET or CLOBBER found in X; also increment
   REG_N_REFS by the current loop depth for each SET or CLOBBER found.  */

static void
count_reg_sets  (x)
     rtx x;
{
  register RTX_CODE code = GET_CODE (x);

  if (code == SET || code == CLOBBER)
    count_reg_sets_1 (x);
  else if (code == PARALLEL)
    {
      register int i;
      for (i = XVECLEN (x, 0) - 1; i >= 0; i--)
	{
	  code = GET_CODE (XVECEXP (x, 0, i));
	  if (code == SET || code == CLOBBER)
	    count_reg_sets_1 (XVECEXP (x, 0, i));
	}
    }
}

/* Increment REG_N_REFS by the current loop depth each register reference
   found in X.  */

static void
count_reg_references (x)
     rtx x;
{
  register RTX_CODE code;

 retry:
  code = GET_CODE (x);
  switch (code)
    {
    case LABEL_REF:
    case SYMBOL_REF:
    case CONST_INT:
    case CONST:
    case CONST_DOUBLE:
    case PC:
    case ADDR_VEC:
    case ADDR_DIFF_VEC:
    case ASM_INPUT:
      return;

#ifdef HAVE_cc0
    case CC0:
      return;
#endif

    case CLOBBER:
      /* If we are clobbering a MEM, mark any registers inside the address
	 as being used.  */
      if (GET_CODE (XEXP (x, 0)) == MEM)
	count_reg_references (XEXP (XEXP (x, 0), 0));
      return;

    case SUBREG:
      /* While we're here, optimize this case.  */
      x = SUBREG_REG (x);

      /* In case the SUBREG is not of a register, don't optimize */
      if (GET_CODE (x) != REG)
	{
	  count_reg_references (x);
	  return;
	}

      /* ... fall through ...  */

    case REG:
      if (REGNO (x) >= FIRST_PSEUDO_REGISTER)
	REG_N_REFS (REGNO (x)) += loop_depth;
      return;

    case SET:
      {
	register rtx testreg = SET_DEST (x);
	int mark_dest = 0;

	/* If storing into MEM, don't show it as being used.  But do
	   show the address as being used.  */
	if (GET_CODE (testreg) == MEM)
	  {
	    count_reg_references (XEXP (testreg, 0));
	    count_reg_references (SET_SRC (x));
	    return;
	  }
	    
	/* Storing in STRICT_LOW_PART is like storing in a reg
	   in that this SET might be dead, so ignore it in TESTREG.
	   but in some other ways it is like using the reg.

	   Storing in a SUBREG or a bit field is like storing the entire
	   register in that if the register's value is not used
	   then this SET is not needed.  */
	while (GET_CODE (testreg) == STRICT_LOW_PART
	       || GET_CODE (testreg) == ZERO_EXTRACT
	       || GET_CODE (testreg) == SIGN_EXTRACT
	       || GET_CODE (testreg) == SUBREG)
	  {
	    /* Modifying a single register in an alternate mode
	       does not use any of the old value.  But these other
	       ways of storing in a register do use the old value.  */
	    if (GET_CODE (testreg) == SUBREG
		&& !(REG_SIZE (SUBREG_REG (testreg)) > REG_SIZE (testreg)))
	      ;
	    else
	      mark_dest = 1;

	    testreg = XEXP (testreg, 0);
	  }

	/* If this is a store into a register,
	   recursively scan the value being stored.  */

	if ((GET_CODE (testreg) == PARALLEL
	     && GET_MODE (testreg) == BLKmode)
	    || GET_CODE (testreg) == REG)
	  {
	    count_reg_references (SET_SRC (x));
	    if (mark_dest)
	      count_reg_references (SET_DEST (x));
	    return;
	  }
      }
      break;

    default:
      break;
    }

  /* Recursively scan the operands of this expression.  */

  {
    register char *fmt = GET_RTX_FORMAT (code);
    register int i;
    
    for (i = GET_RTX_LENGTH (code) - 1; i >= 0; i--)
      {
	if (fmt[i] == 'e')
	  {
	    /* Tail recursive case: save a function call level.  */
	    if (i == 0)
	      {
		x = XEXP (x, 0);
		goto retry;
	      }
	    count_reg_references (XEXP (x, i));
	  }
	else if (fmt[i] == 'E')
	  {
	    register int j;
	    for (j = 0; j < XVECLEN (x, i); j++)
	      count_reg_references (XVECEXP (x, i, j));
	  }
      }
  }
}

/* Recompute register set/reference counts immediately prior to register
   allocation.

   This avoids problems with set/reference counts changing to/from values
   which have special meanings to the register allocators.

   Additionally, the reference counts are the primary component used by the
   register allocators to prioritize pseudos for allocation to hard regs.
   More accurate reference counts generally lead to better register allocation.

   F is the first insn to be scanned.
   LOOP_STEP denotes how much loop_depth should be incremented per
   loop nesting level in order to increase the ref count more for references
   in a loop.

   It might be worthwhile to update REG_LIVE_LENGTH, REG_BASIC_BLOCK and
   possibly other information which is used by the register allocators.  */

void
recompute_reg_usage (f, loop_step)
     rtx f;
     int loop_step;
{
  rtx insn;
  int i, max_reg;

  /* Clear out the old data.  */
  max_reg = max_reg_num ();
  for (i = FIRST_PSEUDO_REGISTER; i < max_reg; i++)
    {
      REG_N_SETS (i) = 0;
      REG_N_REFS (i) = 0;
    }

  /* Scan each insn in the chain and count how many times each register is
     set/used.  */
  loop_depth = 1;
  for (insn = f; insn; insn = NEXT_INSN (insn))
    {
      /* Keep track of loop depth.  */
      if (GET_CODE (insn) == NOTE)
	{
	  /* Look for loop boundaries.  */
	  if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_LOOP_END)
	    loop_depth -= loop_step;
	  else if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_LOOP_BEG)
	    loop_depth += loop_step;

	  /* If we have LOOP_DEPTH == 0, there has been a bookkeeping error. 
	     Abort now rather than setting register status incorrectly.  */
	  if (loop_depth == 0)
	    abort ();
	}
      else if (GET_RTX_CLASS (GET_CODE (insn)) == 'i')
	{
	  rtx links;

	  /* This call will increment REG_N_SETS for each SET or CLOBBER
	     of a register in INSN.  It will also increment REG_N_REFS
	     by the loop depth for each set of a register in INSN.  */
	  count_reg_sets (PATTERN (insn));

	  /* count_reg_sets does not detect autoincrement address modes, so
	     detect them here by looking at the notes attached to INSN.  */
	  for (links = REG_NOTES (insn); links; links = XEXP (links, 1))
	    {
	      if (REG_NOTE_KIND (links) == REG_INC)
		/* Count (weighted) references, stores, etc.  This counts a
		   register twice if it is modified, but that is correct.  */
		REG_N_SETS (REGNO (XEXP (links, 0)))++;
	    }

	  /* This call will increment REG_N_REFS by the current loop depth for
	     each reference to a register in INSN.  */
	  count_reg_references (PATTERN (insn));

	  /* count_reg_references will not include counts for arguments to
	     function calls, so detect them here by examining the
	     CALL_INSN_FUNCTION_USAGE data.  */
	  if (GET_CODE (insn) == CALL_INSN)
	    {
	      rtx note;

	      for (note = CALL_INSN_FUNCTION_USAGE (insn);
		   note;
		   note = XEXP (note, 1))
		if (GET_CODE (XEXP (note, 0)) == USE)
		  count_reg_references (SET_DEST (XEXP (note, 0)));
	    }
	}
    }
}
