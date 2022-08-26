/* Save and restore call-clobbered registers which are live across a call.
   Copyright (C) 1989, 1992, 94-95, 97, 98, 1999 Free Software Foundation, Inc.

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

#include "config.h"
#include "system.h"
#include "rtl.h"
#include "insn-config.h"
#include "flags.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "recog.h"
#include "basic-block.h"
#include "reload.h"
#include "expr.h"
#include "toplev.h"

#ifndef MAX_MOVE_MAX
#define MAX_MOVE_MAX MOVE_MAX
#endif

#ifndef MIN_UNITS_PER_WORD
#define MIN_UNITS_PER_WORD UNITS_PER_WORD
#endif

#define MOVE_MAX_WORDS (MOVE_MAX / UNITS_PER_WORD)

/* Modes for each hard register that we can save.  The smallest mode is wide
   enough to save the entire contents of the register.  When saving the
   register because it is live we first try to save in multi-register modes.
   If that is not possible the save is done one register at a time.  */

static enum machine_mode 
  regno_save_mode[FIRST_PSEUDO_REGISTER][MAX_MOVE_MAX / MIN_UNITS_PER_WORD + 1];

/* For each hard register, a place on the stack where it can be saved,
   if needed.  */

static rtx 
  regno_save_mem[FIRST_PSEUDO_REGISTER][MAX_MOVE_MAX / MIN_UNITS_PER_WORD + 1];

/* We will only make a register eligible for caller-save if it can be
   saved in its widest mode with a simple SET insn as long as the memory
   address is valid.  We record the INSN_CODE is those insns here since
   when we emit them, the addresses might not be valid, so they might not
   be recognized.  */

static enum insn_code 
  reg_save_code[FIRST_PSEUDO_REGISTER][MAX_MOVE_MAX / MIN_UNITS_PER_WORD + 1];
static enum insn_code 
  reg_restore_code[FIRST_PSEUDO_REGISTER][MAX_MOVE_MAX / MIN_UNITS_PER_WORD + 1];

/* Set of hard regs currently residing in save area (during insn scan).  */

static HARD_REG_SET hard_regs_saved;

/* Number of registers currently in hard_regs_saved.  */

static int n_regs_saved;

/* Computed by mark_referenced_regs, all regs referenced in a given
   insn.  */
static HARD_REG_SET referenced_regs;

/* Computed in mark_set_regs, holds all registers set by the current
   instruction.  */
static HARD_REG_SET this_insn_sets;


static void mark_set_regs		PROTO((rtx, rtx));
static void mark_referenced_regs	PROTO((rtx));
static int insert_save			PROTO((struct insn_chain *, int, int,
					       HARD_REG_SET *));
static int insert_restore		PROTO((struct insn_chain *, int, int,
					       int));
static void insert_one_insn		PROTO((struct insn_chain *, int,
					       enum insn_code, rtx));

/* Initialize for caller-save.

   Look at all the hard registers that are used by a call and for which
   regclass.c has not already excluded from being used across a call.

   Ensure that we can find a mode to save the register and that there is a 
   simple insn to save and restore the register.  This latter check avoids
   problems that would occur if we tried to save the MQ register of some
   machines directly into memory.  */

void
init_caller_save ()
{
  char *first_obj = (char *) oballoc (0);
  rtx addr_reg;
  int offset;
  rtx address;
  int i, j;

  /* First find all the registers that we need to deal with and all
     the modes that they can have.  If we can't find a mode to use,
     we can't have the register live over calls.  */

  for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
    {
      if (call_used_regs[i] && ! call_fixed_regs[i])
	{
	  for (j = 1; j <= MOVE_MAX_WORDS; j++)
	    {
	      regno_save_mode[i][j] = HARD_REGNO_CALLER_SAVE_MODE (i, j);
	      if (regno_save_mode[i][j] == VOIDmode && j == 1)
		{
		  call_fixed_regs[i] = 1;
		  SET_HARD_REG_BIT (call_fixed_reg_set, i);
		}
	    }
	}
      else
	regno_save_mode[i][1] = VOIDmode;
    }

  /* The following code tries to approximate the conditions under which
     we can easily save and restore a register without scratch registers or
     other complexities.  It will usually work, except under conditions where
     the validity of an insn operand is dependent on the address offset.
     No such cases are currently known.

     We first find a typical offset from some BASE_REG_CLASS register.
     This address is chosen by finding the first register in the class
     and by finding the smallest power of two that is a valid offset from
     that register in every mode we will use to save registers.  */

  for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
    if (TEST_HARD_REG_BIT (reg_class_contents[(int) BASE_REG_CLASS], i))
      break;

  if (i == FIRST_PSEUDO_REGISTER)
    abort ();

  addr_reg = gen_rtx_REG (Pmode, i);

  for (offset = 1 << (HOST_BITS_PER_INT / 2); offset; offset >>= 1)
    {
      address = gen_rtx_PLUS (Pmode, addr_reg, GEN_INT (offset));

      for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
	if (regno_save_mode[i][1] != VOIDmode
	  && ! strict_memory_address_p (regno_save_mode[i][1], address))
	  break;

      if (i == FIRST_PSEUDO_REGISTER)
	break;
    }

  /* If we didn't find a valid address, we must use register indirect.  */
  if (offset == 0)
    address = addr_reg;

  /* Next we try to form an insn to save and restore the register.  We
     see if such an insn is recognized and meets its constraints.  */

  start_sequence ();

  for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
    for (j = 1; j <= MOVE_MAX_WORDS; j++)
      if (regno_save_mode[i][j] != VOIDmode)
        {
	  rtx mem = gen_rtx_MEM (regno_save_mode[i][j], address);
	  rtx reg = gen_rtx_REG (regno_save_mode[i][j], i);
	  rtx savepat = gen_rtx_SET (VOIDmode, mem, reg);
	  rtx restpat = gen_rtx_SET (VOIDmode, reg, mem);
	  rtx saveinsn = emit_insn (savepat);
	  rtx restinsn = emit_insn (restpat);
	  int ok;

	  reg_save_code[i][j] = recog_memoized (saveinsn);
	  reg_restore_code[i][j] = recog_memoized (restinsn);

	  /* Now extract both insns and see if we can meet their
             constraints.  */
	  ok = (reg_save_code[i][j] != (enum insn_code)-1
		&& reg_restore_code[i][j] != (enum insn_code)-1);
	  if (ok)
	    {
	      extract_insn (saveinsn);
	      ok = constrain_operands (1);
	      extract_insn (restinsn);
	      ok &= constrain_operands (1);
	    }

	  if (! ok)
	    {
	      regno_save_mode[i][j] = VOIDmode;
	      if (j == 1)
		{
		  call_fixed_regs[i] = 1;
		  SET_HARD_REG_BIT (call_fixed_reg_set, i);
		}
	    }
      }

  end_sequence ();

  obfree (first_obj);
}

/* Initialize save areas by showing that we haven't allocated any yet.  */

void
init_save_areas ()
{
  int i, j;

  for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
    for (j = 1; j <= MOVE_MAX_WORDS; j++)
      regno_save_mem[i][j] = 0;
}

/* Allocate save areas for any hard registers that might need saving.
   We take a conservative approach here and look for call-clobbered hard
   registers that are assigned to pseudos that cross calls.  This may
   overestimate slightly (especially if some of these registers are later
   used as spill registers), but it should not be significant.

   Future work:

     In the fallback case we should iterate backwards across all possible
     modes for the save, choosing the largest available one instead of 
     falling back to the smallest mode immediately.  (eg TF -> DF -> SF).

     We do not try to use "move multiple" instructions that exist
     on some machines (such as the 68k moveml).  It could be a win to try 
     and use them when possible.  The hard part is doing it in a way that is
     machine independent since they might be saving non-consecutive 
     registers. (imagine caller-saving d0,d1,a0,a1 on the 68k) */

void
setup_save_areas ()
{
  int i, j, k;
  HARD_REG_SET hard_regs_used;

  /* Allocate space in the save area for the largest multi-register
     pseudos first, then work backwards to single register
     pseudos.  */

  /* Find and record all call-used hard-registers in this function.  */
  CLEAR_HARD_REG_SET (hard_regs_used);
  for (i = FIRST_PSEUDO_REGISTER; i < max_regno; i++)
    if (reg_renumber[i] >= 0 && REG_N_CALLS_CROSSED (i) > 0)
      {
	int regno = reg_renumber[i];
	int endregno 
	  = regno + HARD_REGNO_NREGS (regno, GET_MODE (regno_reg_rtx[i]));
	int nregs = endregno - regno;

	for (j = 0; j < nregs; j++)
	  {
	    if (call_used_regs[regno+j]) 
	      SET_HARD_REG_BIT (hard_regs_used, regno+j);
	  }
      }

  /* Now run through all the call-used hard-registers and allocate
     space for them in the caller-save area.  Try to allocate space
     in a manner which allows multi-register saves/restores to be done.  */

  for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
    for (j = MOVE_MAX_WORDS; j > 0; j--)
      {
	int do_save = 1;

	/* If no mode exists for this size, try another.  Also break out
	   if we have already saved this hard register.  */
	if (regno_save_mode[i][j] == VOIDmode || regno_save_mem[i][1] != 0)
	  continue;

	/* See if any register in this group has been saved.  */
	for (k = 0; k < j; k++)
	  if (regno_save_mem[i + k][1])
	    {
	      do_save = 0;
	      break;
	    }
	if (! do_save)
	  continue;

	for (k = 0; k < j; k++)
	  if (! TEST_HARD_REG_BIT (hard_regs_used, i + k))
	    {
	      do_save = 0;
	      break;
	    }
	if (! do_save)
	  continue;

	/* We have found an acceptable mode to store in.  */
	regno_save_mem[i][j]
	  = assign_stack_local (regno_save_mode[i][j],
				GET_MODE_SIZE (regno_save_mode[i][j]), 0);

	/* Setup single word save area just in case...  */
	for (k = 0; k < j; k++)
	  {
	    /* This should not depend on WORDS_BIG_ENDIAN.
	       The order of words in regs is the same as in memory.  */
	    rtx temp = gen_rtx_MEM (regno_save_mode[i+k][1], 
				    XEXP (regno_save_mem[i][j], 0));

	    regno_save_mem[i+k][1] 
	      = adj_offsettable_operand (temp, k * UNITS_PER_WORD);
	  }
      }
}

/* Find the places where hard regs are live across calls and save them.  */
void
save_call_clobbered_regs ()
{
  struct insn_chain *chain, *next;

  CLEAR_HARD_REG_SET (hard_regs_saved);
  n_regs_saved = 0;

  for (chain = reload_insn_chain; chain != 0; chain = next)
    {
      rtx insn = chain->insn;
      enum rtx_code code = GET_CODE (insn);

      next = chain->next;

      if (chain->is_caller_save_insn)
	abort ();

      if (GET_RTX_CLASS (code) == 'i')
	{
	  /* If some registers have been saved, see if INSN references
	     any of them.  We must restore them before the insn if so.  */

	  if (n_regs_saved)
	    {
	      int regno;

	      if (code == JUMP_INSN)
		/* Restore all registers if this is a JUMP_INSN.  */
		COPY_HARD_REG_SET (referenced_regs, hard_regs_saved);
	      else
		{
		  CLEAR_HARD_REG_SET (referenced_regs);
		  mark_referenced_regs (PATTERN (insn));
		  AND_HARD_REG_SET (referenced_regs, hard_regs_saved);
		}

	      for (regno = 0; regno < FIRST_PSEUDO_REGISTER; regno++)
		if (TEST_HARD_REG_BIT (referenced_regs, regno))
		  regno += insert_restore (chain, 1, regno, MOVE_MAX_WORDS);
	    }

	  if (code == CALL_INSN)
	    {
	      rtx x;
	      int regno, nregs;
	      HARD_REG_SET hard_regs_to_save;

	      /* Use the register life information in CHAIN to compute which
		 regs are live before the call.  */
	      REG_SET_TO_HARD_REG_SET (hard_regs_to_save, chain->live_before);
	      compute_use_by_pseudos (&hard_regs_to_save, chain->live_before);

	      /* Record all registers set in this call insn.  These don't need
		 to be saved.  */
	      CLEAR_HARD_REG_SET (this_insn_sets);
	      note_stores (PATTERN (insn), mark_set_regs);

	      /* Compute which hard regs must be saved before this call.  */
	      AND_COMPL_HARD_REG_SET (hard_regs_to_save, call_fixed_reg_set);
	      AND_COMPL_HARD_REG_SET (hard_regs_to_save, this_insn_sets);
	      AND_COMPL_HARD_REG_SET (hard_regs_to_save, hard_regs_saved);
	      AND_HARD_REG_SET (hard_regs_to_save, call_used_reg_set);

	      /* Registers used for function parameters need not be saved.  */
	      for (x = CALL_INSN_FUNCTION_USAGE (insn); x != 0;
		   x = XEXP (x, 1))
		{
		  rtx y;

		  if (GET_CODE (XEXP (x, 0)) != USE)
		    continue;
		  y = XEXP (XEXP (x, 0), 0);
		  if (GET_CODE (y) != REG)
		    abort ();
		  regno = REGNO (y);
		  if (REGNO (y) >= FIRST_PSEUDO_REGISTER)
		    abort ();
		  nregs = HARD_REGNO_NREGS (regno, GET_MODE (y));
		  while (nregs-- > 0)
		    CLEAR_HARD_REG_BIT (hard_regs_to_save, regno + nregs);
		}

	      /* Neither do registers for which we find a death note.  */
	      for (x = REG_NOTES (insn); x != 0; x = XEXP (x, 1))
		{
		  rtx y = XEXP (x, 0);

		  if (REG_NOTE_KIND (x) != REG_DEAD)
		    continue;
		  if (GET_CODE (y) != REG)
		    abort ();
		  regno = REGNO (y);

		  if (regno >= FIRST_PSEUDO_REGISTER)
		    regno = reg_renumber[regno];
		  if (regno < 0)
		    continue;
		  nregs = HARD_REGNO_NREGS (regno, GET_MODE (y));
		  while (nregs-- > 0)
		    CLEAR_HARD_REG_BIT (hard_regs_to_save, regno + nregs);		  
		}
		
	      for (regno = 0; regno < FIRST_PSEUDO_REGISTER; regno++)
		if (TEST_HARD_REG_BIT (hard_regs_to_save, regno))
		  regno += insert_save (chain, 1, regno, &hard_regs_to_save);

	      /* Must recompute n_regs_saved.  */
	      n_regs_saved = 0;
	      for (regno = 0; regno < FIRST_PSEUDO_REGISTER; regno++)
		if (TEST_HARD_REG_BIT (hard_regs_saved, regno))
		  n_regs_saved++;
	    }
	}

      if (chain->next == 0 || chain->next->block > chain->block)
	{
	  int regno;
	  /* At the end of the basic block, we must restore any registers that
	     remain saved.  If the last insn in the block is a JUMP_INSN, put
	     the restore before the insn, otherwise, put it after the insn.  */

	  if (n_regs_saved)
	    for (regno = 0; regno < FIRST_PSEUDO_REGISTER; regno++)
	      if (TEST_HARD_REG_BIT (hard_regs_saved, regno))
		regno += insert_restore (chain, GET_CODE (insn) == JUMP_INSN,
					 regno, MOVE_MAX_WORDS);
	}
    }  
}

/* Here from note_stores when an insn stores a value in a register.
   Set the proper bit or bits in this_insn_sets.  All pseudos that have
   been assigned hard regs have had their register number changed already,
   so we can ignore pseudos.  */
static void
mark_set_regs (reg, setter)
     rtx reg;
     rtx setter ATTRIBUTE_UNUSED;
{
  register int regno, endregno, i;
  enum machine_mode mode = GET_MODE (reg);
  int word = 0;

  if (GET_CODE (reg) == SUBREG)
    {
      word = SUBREG_WORD (reg);
      reg = SUBREG_REG (reg);
    }

  if (GET_CODE (reg) != REG || REGNO (reg) >= FIRST_PSEUDO_REGISTER)
    return;

  regno = REGNO (reg) + word;
  endregno = regno + HARD_REGNO_NREGS (regno, mode);

  for (i = regno; i < endregno; i++)
    SET_HARD_REG_BIT (this_insn_sets, i);
}

/* Walk X and record all referenced registers in REFERENCED_REGS.  */
static void
mark_referenced_regs (x)
     rtx x;
{
  enum rtx_code code = GET_CODE (x);
  char *fmt;
  int i, j;

  if (code == SET)
    mark_referenced_regs (SET_SRC (x));
  if (code == SET || code == CLOBBER)
    {
      x = SET_DEST (x);
      code = GET_CODE (x);
      if (code == REG || code == PC || code == CC0
	  || (code == SUBREG && GET_CODE (SUBREG_REG (x)) == REG))
	return;
    }
  if (code == MEM || code == SUBREG)
    {
      x = XEXP (x, 0);
      code = GET_CODE (x);
    }

  if (code == REG)
    {
      int regno = REGNO (x);
      int hardregno = (regno < FIRST_PSEUDO_REGISTER ? regno
		       : reg_renumber[regno]);

      if (hardregno >= 0)
	{
	  int nregs = HARD_REGNO_NREGS (hardregno, GET_MODE (x));
	  while (nregs-- > 0)
	    SET_HARD_REG_BIT (referenced_regs, hardregno + nregs);
	}
      /* If this is a pseudo that did not get a hard register, scan its
	 memory location, since it might involve the use of another
	 register, which might be saved.  */
      else if (reg_equiv_mem[regno] != 0)
	mark_referenced_regs (XEXP (reg_equiv_mem[regno], 0));
      else if (reg_equiv_address[regno] != 0)
	mark_referenced_regs (reg_equiv_address[regno]);
      return;
    }

  fmt = GET_RTX_FORMAT (code);
  for (i = GET_RTX_LENGTH (code) - 1; i >= 0; i--)
    {
      if (fmt[i] == 'e')
	mark_referenced_regs (XEXP (x, i));
      else if (fmt[i] == 'E')
	for (j = XVECLEN (x, i) - 1; j >= 0; j--)
	  mark_referenced_regs (XVECEXP (x, i, j));
    }
}

/* Insert a sequence of insns to restore.  Place these insns in front of
   CHAIN if BEFORE_P is nonzero, behind the insn otherwise.  MAXRESTORE is
   the maximum number of registers which should be restored during this call.
   It should never be less than 1 since we only work with entire registers.

   Note that we have verified in init_caller_save that we can do this
   with a simple SET, so use it.  Set INSN_CODE to what we save there
   since the address might not be valid so the insn might not be recognized.
   These insns will be reloaded and have register elimination done by
   find_reload, so we need not worry about that here.

   Return the extra number of registers saved.  */

static int
insert_restore (chain, before_p, regno, maxrestore)
     struct insn_chain *chain;
     int before_p;
     int regno;
     int maxrestore;
{
  int i;
  rtx pat = NULL_RTX;
  enum insn_code code = CODE_FOR_nothing;
  int numregs = 0;

  /* A common failure mode if register status is not correct in the RTL
     is for this routine to be called with a REGNO we didn't expect to
     save.  That will cause us to write an insn with a (nil) SET_DEST
     or SET_SRC.  Instead of doing so and causing a crash later, check
     for this common case and abort here instead.  This will remove one
     step in debugging such problems.  */

  if (regno_save_mem[regno][1] == 0)
    abort ();

  /* Get the pattern to emit and update our status.

     See if we can restore `maxrestore' registers at once.  Work
     backwards to the single register case.  */
  for (i = maxrestore; i > 0; i--)
    {
      int j, k;
      int ok = 1;

      if (regno_save_mem[regno][i] == 0)
	continue;

      for (j = 0; j < i; j++)
	if (! TEST_HARD_REG_BIT (hard_regs_saved, regno + j))
	  {
	    ok = 0;
	    break;
	  }
      /* Must do this one restore at a time */
      if (! ok)
	continue;

      pat = gen_rtx_SET (VOIDmode,
			 gen_rtx_REG (GET_MODE (regno_save_mem[regno][i]), 
				      regno), 
			 regno_save_mem[regno][i]);
      code = reg_restore_code[regno][i];

      /* Clear status for all registers we restored.  */
      for (k = 0; k < i; k++)
	{
	  CLEAR_HARD_REG_BIT (hard_regs_saved, regno + k);
	  n_regs_saved--;
	}

      numregs = i;
      break;
    }

  insert_one_insn (chain, before_p, code, pat);

  /* Tell our callers how many extra registers we saved/restored */
  return numregs - 1;
}

/* Like insert_restore above, but save registers instead.  */
static int
insert_save (chain, before_p, regno, to_save)
     struct insn_chain *chain;
     int before_p;
     int regno;
     HARD_REG_SET *to_save;
{
  int i;
  rtx pat = NULL_RTX;
  enum insn_code code = CODE_FOR_nothing;
  int numregs = 0;

  /* A common failure mode if register status is not correct in the RTL
     is for this routine to be called with a REGNO we didn't expect to
     save.  That will cause us to write an insn with a (nil) SET_DEST
     or SET_SRC.  Instead of doing so and causing a crash later, check
     for this common case and abort here instead.  This will remove one
     step in debugging such problems.  */

  if (regno_save_mem[regno][1] == 0)
    abort ();

  /* Get the pattern to emit and update our status.

     See if we can save several registers with a single instruction.  
     Work backwards to the single register case.  */
  for (i = MOVE_MAX_WORDS; i > 0; i--)
    {
      int j, k;
      int ok = 1;
      if (regno_save_mem[regno][i] == 0)
	continue;

      for (j = 0; j < i; j++)
	if (! TEST_HARD_REG_BIT (*to_save, regno + j))
	  {
	    ok = 0;
	    break;
	  }
      /* Must do this one save at a time */
      if (! ok)
	continue;

      pat = gen_rtx_SET (VOIDmode, regno_save_mem[regno][i],
			 gen_rtx_REG (GET_MODE (regno_save_mem[regno][i]),
				      regno));
      code = reg_save_code[regno][i];

      /* Set hard_regs_saved for all the registers we saved.  */
      for (k = 0; k < i; k++)
	{
	  SET_HARD_REG_BIT (hard_regs_saved, regno + k);
	  n_regs_saved++;
	}

      numregs = i;
      break;
    }

  insert_one_insn (chain, before_p, code, pat);

  /* Tell our callers how many extra registers we saved/restored */
  return numregs - 1;
}

/* Emit a new caller-save insn and set the code.  */
static void
insert_one_insn (chain, before_p, code, pat)
     struct insn_chain *chain;
     int before_p;
     enum insn_code code;
     rtx pat;
{
  rtx insn = chain->insn;
  struct insn_chain *new;
  
#ifdef HAVE_cc0
  /* If INSN references CC0, put our insns in front of the insn that sets
     CC0.  This is always safe, since the only way we could be passed an
     insn that references CC0 is for a restore, and doing a restore earlier
     isn't a problem.  We do, however, assume here that CALL_INSNs don't
     reference CC0.  Guard against non-INSN's like CODE_LABEL.  */

  if ((GET_CODE (insn) == INSN || GET_CODE (insn) == JUMP_INSN)
      && before_p
      && reg_referenced_p (cc0_rtx, PATTERN (insn)))
    chain = chain->prev, insn = chain->insn;
#endif

  new = new_insn_chain ();
  if (before_p)
    {
      new->prev = chain->prev;
      if (new->prev != 0)
	new->prev->next = new;
      else
	reload_insn_chain = new;

      chain->prev = new;
      new->next = chain;
      new->insn = emit_insn_before (pat, insn);
      /* ??? It would be nice if we could exclude the already / still saved
	 registers from the live sets.  */
      COPY_REG_SET (new->live_before, chain->live_before);
      COPY_REG_SET (new->live_after, chain->live_before);
      if (chain->insn == BLOCK_HEAD (chain->block))
	BLOCK_HEAD (chain->block) = new->insn;
    }
  else
    {
      new->next = chain->next;
      if (new->next != 0)
	new->next->prev = new;
      chain->next = new;
      new->prev = chain;
      new->insn = emit_insn_after (pat, insn);
      /* ??? It would be nice if we could exclude the already / still saved
	 registers from the live sets, and observe REG_UNUSED notes.  */
      COPY_REG_SET (new->live_before, chain->live_after);
      COPY_REG_SET (new->live_after, chain->live_after);
      if (chain->insn == BLOCK_END (chain->block))
	BLOCK_END (chain->block) = new->insn;
    }
  new->block = chain->block;
  new->is_caller_save_insn = 1;

  INSN_CODE (new->insn) = code;
}
