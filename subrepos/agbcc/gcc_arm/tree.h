/* Front-end tree definitions for GNU compiler.
   Copyright (C) 1989, 93-98, 1999 Free Software Foundation, Inc.

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

#include "machmode.h"

#ifndef RTX_CODE
struct rtx_def;
#endif

/* Codes of tree nodes */

#define DEFTREECODE(SYM, STRING, TYPE, NARGS)   SYM,

enum tree_code {
#include "tree.def"

  LAST_AND_UNUSED_TREE_CODE	/* A convenient way to get a value for
				   NUM_TREE_CODE.  */
};

#undef DEFTREECODE

/* Number of tree codes.  */
#define NUM_TREE_CODES ((int)LAST_AND_UNUSED_TREE_CODE)

/* Indexed by enum tree_code, contains a character which is
   `<' for a comparison expression, `1', for a unary arithmetic
   expression, `2' for a binary arithmetic expression, `e' for
   other types of expressions, `r' for a reference, `c' for a
   constant, `d' for a decl, `t' for a type, `s' for a statement,
   and `x' for anything else (TREE_LIST, IDENTIFIER, etc).  */

#define MAX_TREE_CODES 256
extern char tree_code_type[MAX_TREE_CODES];
#define TREE_CODE_CLASS(CODE)	tree_code_type[(int) (CODE)]

/* Returns non-zero iff CLASS is the tree-code class of an
   expression.  */

#define IS_EXPR_CODE_CLASS(CLASS) \
  (CLASS == '<' || CLASS == '1' || CLASS == '2' || CLASS == 'e')

/* Number of argument-words in each kind of tree-node.  */

extern int tree_code_length[MAX_TREE_CODES];

/* Names of tree components.  */

extern char *tree_code_name[MAX_TREE_CODES];

/* Codes that identify the various built in functions
   so that expand_call can identify them quickly.  */

enum built_in_function
{
  NOT_BUILT_IN,
  BUILT_IN_ALLOCA,
  BUILT_IN_ABS,
  BUILT_IN_FABS,
  BUILT_IN_LABS,
  BUILT_IN_FFS,
  BUILT_IN_DIV,
  BUILT_IN_LDIV,
  BUILT_IN_FFLOOR,
  BUILT_IN_FCEIL,
  BUILT_IN_FMOD,
  BUILT_IN_FREM,
  BUILT_IN_MEMCPY,
  BUILT_IN_MEMCMP,
  BUILT_IN_MEMSET,
  BUILT_IN_STRCPY,
  BUILT_IN_STRCMP,
  BUILT_IN_STRLEN,
  BUILT_IN_FSQRT,
  BUILT_IN_SIN,
  BUILT_IN_COS,
  BUILT_IN_GETEXP,
  BUILT_IN_GETMAN,
  BUILT_IN_SAVEREGS,
  BUILT_IN_CLASSIFY_TYPE,
  BUILT_IN_NEXT_ARG,
  BUILT_IN_ARGS_INFO,
  BUILT_IN_CONSTANT_P,
  BUILT_IN_FRAME_ADDRESS,
  BUILT_IN_RETURN_ADDRESS,
  BUILT_IN_AGGREGATE_INCOMING_ADDRESS,
  BUILT_IN_APPLY_ARGS,
  BUILT_IN_APPLY,
  BUILT_IN_RETURN,
  BUILT_IN_SETJMP,
  BUILT_IN_LONGJMP,
  BUILT_IN_TRAP,

  /* Various hooks for the DWARF 2 __throw routine.  */
  BUILT_IN_UNWIND_INIT,
  BUILT_IN_DWARF_CFA,
  BUILT_IN_DWARF_FP_REGNUM,
  BUILT_IN_DWARF_REG_SIZE,
  BUILT_IN_FROB_RETURN_ADDR,
  BUILT_IN_EXTRACT_RETURN_ADDR,
  BUILT_IN_EH_RETURN,

  /* C++ extensions */
  BUILT_IN_NEW,
  BUILT_IN_VEC_NEW,
  BUILT_IN_DELETE,
  BUILT_IN_VEC_DELETE,

  /* CYGNUS LOCAL -- branch prediction */
  BUILT_IN_EXPECT,
  /* END CYGNUS LOCAL -- branch prediction */

  /* Upper bound on non-language-specific builtins. */
  END_BUILTINS
};

/* The definition of tree nodes fills the next several pages.  */

/* A tree node can represent a data type, a variable, an expression
   or a statement.  Each node has a TREE_CODE which says what kind of
   thing it represents.  Some common codes are:
   INTEGER_TYPE -- represents a type of integers.
   ARRAY_TYPE -- represents a type of pointer.
   VAR_DECL -- represents a declared variable.
   INTEGER_CST -- represents a constant integer value.
   PLUS_EXPR -- represents a sum (an expression).

   As for the contents of a tree node: there are some fields
   that all nodes share.  Each TREE_CODE has various special-purpose
   fields as well.  The fields of a node are never accessed directly,
   always through accessor macros.  */

/* This type is used everywhere to refer to a tree node.  */

typedef union tree_node *tree;

/* Every kind of tree node starts with this structure,
   so all nodes have these fields.

   See the accessor macros, defined below, for documentation of the fields. 

   DO NOT change the layout of tree_common unless absolutely necessary.  Some
   front-ends (namely g++) depend on the internal layout of this tructure.
   See my_tree_cons in the cp subdir for such uglyness.  Ugh.  */

struct tree_common
{
  union tree_node *chain;
  union tree_node *type;
#ifdef ONLY_INT_FIELDS
  unsigned int code : 8;
#else
  enum tree_code code : 8;
#endif

  unsigned side_effects_flag : 1;
  unsigned constant_flag : 1;
  unsigned permanent_flag : 1;
  unsigned addressable_flag : 1;
  unsigned volatile_flag : 1;
  unsigned readonly_flag : 1;
  unsigned unsigned_flag : 1;
  unsigned asm_written_flag: 1;

  unsigned used_flag : 1;
  unsigned raises_flag : 1;
  unsigned static_flag : 1;
  unsigned public_flag : 1;
  unsigned private_flag : 1;
  unsigned protected_flag : 1;

  unsigned lang_flag_0 : 1;
  unsigned lang_flag_1 : 1;
  unsigned lang_flag_2 : 1;
  unsigned lang_flag_3 : 1;
  unsigned lang_flag_4 : 1;
  unsigned lang_flag_5 : 1;
  unsigned lang_flag_6 : 1;
  /* There is room for three more flags.  */
};

/* The following table lists the uses of each of the above flags and
   for which types of nodes they are defined.  Note that expressions
   include decls.

   addressable_flag:

       TREE_ADDRESSABLE in
   	   VAR_DECL, FUNCTION_DECL, CONSTRUCTOR, LABEL_DECL, ..._TYPE
	   IDENTIFIER_NODE

   static_flag:

       TREE_STATIC in
           VAR_DECL, FUNCTION_DECL, CONSTRUCTOR, ADDR_EXPR
       TREE_NO_UNUSED_WARNING in
           CONVERT_EXPR, NOP_EXPR, COMPOUND_EXPR
       TREE_VIA_VIRTUAL in
           TREE_LIST or TREE_VEC
       TREE_CONSTANT_OVERFLOW in
           INTEGER_CST, REAL_CST, COMPLEX_CST
       TREE_SYMBOL_REFERENCED in
           IDENTIFIER_NODE

   public_flag:

       TREE_OVERFLOW in
           INTEGER_CST, REAL_CST, COMPLEX_CST
       TREE_PUBLIC in
           VAR_DECL or FUNCTION_DECL
       TREE_VIA_PUBLIC in
           TREE_LIST or TREE_VEC
       EXPR_WFL_EMIT_LINE_NOTE in
           EXPR_WITH_FILE_LOCATION

   private_flag:

       TREE_VIA_PRIVATE in
           TREE_LIST or TREE_VEC
       TREE_PRIVATE in
           ??? unspecified nodes

   protected_flag:

       TREE_VIA_PROTECTED in
           TREE_LIST
       TREE_PROTECTED in
           BLOCK
	   ??? unspecified nodes

   side_effects_flag:

       TREE_SIDE_EFFECTS in
           all expressions

   volatile_flag:

       TREE_THIS_VOLATILE in
           all expressions
       TYPE_VOLATILE in
           ..._TYPE

   readonly_flag:

       TREE_READONLY in
           all expressions
       ITERATOR_BOUND_P in
           VAR_DECL if iterator (C)
       TYPE_READONLY in
           ..._TYPE

   constant_flag:

       TREE_CONSTANT in
           all expressions

   permanent_flag: TREE_PERMANENT in all nodes

   unsigned_flag:

       TREE_UNSIGNED in
           INTEGER_TYPE, ENUMERAL_TYPE, FIELD_DECL
       DECL_BUILT_IN_NONANSI in
           FUNCTION_DECL
       TREE_PARMLIST in
           TREE_PARMLIST (C++)
       SAVE_EXPR_NOPLACEHOLDER in
	   SAVE_EXPR

   asm_written_flag:

       TREE_ASM_WRITTEN in
           VAR_DECL, FUNCTION_DECL, RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE
	   BLOCK

   used_flag:

       TREE_USED in
           expressions, IDENTIFIER_NODE

   raises_flag:

       TREE_RAISES in
           expressions

							  */
/* Define accessors for the fields that all tree nodes have
   (though some fields are not used for all kinds of nodes).  */

/* The tree-code says what kind of node it is.
   Codes are defined in tree.def.  */
#define TREE_CODE(NODE) ((enum tree_code) (NODE)->common.code)
#define TREE_SET_CODE(NODE, VALUE) ((NODE)->common.code = (int) (VALUE))

/* When checking is enabled, errors will be generated if a tree node
   is accessed incorrectly. The macros abort with a fatal error,
   except for the *1 variants, which just return 0 on failure.  The
   latter variants should only be used for combination checks, which
   succeed when one of the checks succeed. The CHAIN_CHECK macro helps
   defining such checks.  */

#ifdef ENABLE_CHECKING
#define DO_CHECK(FUNC, t, param)   FUNC (t, param, __FILE__, __LINE__, 0)
#define DO_CHECK1(FUNC, t, param)  FUNC (t, param, __FILE__, __LINE__, 1)
#define CHAIN_CHECK(t, c1, c2)     (c1 (t) ? t : c2 (t))
#else
#define DO_CHECK(FUNC, t, param)   (t)
#define DO_CHECK1(FUNC, t, param)  (t)
#define CHAIN_CHECK(t, c1, c2)     (t)
#endif

#define TREE_CHECK(t, code)        DO_CHECK (tree_check, t, code)
#define TREE_CHECK1(t, code)       DO_CHECK1 (tree_check, t, code)

#include "tree-check.h"

#define TYPE_CHECK(t)          DO_CHECK (tree_class_check, t, 't')
#define TYPE_CHECK1(t)         DO_CHECK1 (tree_class_check, t, 't')
#define DECL_CHECK(t)          DO_CHECK (tree_class_check, t, 'd')
#define DECL_CHECK1(t)         DO_CHECK1 (tree_class_check, t, 'd')
#define CST_CHECK(t)           DO_CHECK (tree_class_check, t, 'c')
#define CST_CHECK1(t)          DO_CHECK1 (tree_class_check, t, 'c')
#define EXPR_CHECK(t)          DO_CHECK (expr_check, t, 0)

/* Chained checks. The last check has to succeed, the others may fail. */
#define CST_OR_CONSTRUCTOR_CHECK(t) \
   CHAIN_CHECK (t, CST_CHECK1, CONSTRUCTOR_CHECK)

/* In all nodes that are expressions, this is the data type of the expression.
   In POINTER_TYPE nodes, this is the type that the pointer points to.
   In ARRAY_TYPE nodes, this is the type of the elements.  */
#define TREE_TYPE(NODE) ((NODE)->common.type)

/* Nodes are chained together for many purposes.
   Types are chained together to record them for being output to the debugger
   (see the function `chain_type').
   Decls in the same scope are chained together to record the contents
   of the scope.
   Statement nodes for successive statements used to be chained together.
   Often lists of things are represented by TREE_LIST nodes that
   are chained together.  */

#define TREE_CHAIN(NODE) ((NODE)->common.chain)

/* Given an expression as a tree, strip any NON_LVALUE_EXPRs and NOP_EXPRs
   that don't change the machine mode.  */

#define STRIP_NOPS(EXP) \
  while ((TREE_CODE (EXP) == NOP_EXPR				\
	  || TREE_CODE (EXP) == CONVERT_EXPR			\
	  || TREE_CODE (EXP) == NON_LVALUE_EXPR)		\
	 && (TYPE_MODE (TREE_TYPE (EXP))			\
	     == TYPE_MODE (TREE_TYPE (TREE_OPERAND (EXP, 0)))))	\
    (EXP) = TREE_OPERAND (EXP, 0);

/* Like STRIP_NOPS, but don't alter the TREE_TYPE either.  */

#define STRIP_TYPE_NOPS(EXP) \
  while ((TREE_CODE (EXP) == NOP_EXPR				\
	  || TREE_CODE (EXP) == CONVERT_EXPR			\
	  || TREE_CODE (EXP) == NON_LVALUE_EXPR)		\
	 && (TREE_TYPE (EXP)					\
	     == TREE_TYPE (TREE_OPERAND (EXP, 0))))		\
    (EXP) = TREE_OPERAND (EXP, 0);

/* Nonzero if TYPE represents an integral type.  Note that we do not
   include COMPLEX types here.  */

#define INTEGRAL_TYPE_P(TYPE)  \
  (TREE_CODE (TYPE) == INTEGER_TYPE || TREE_CODE (TYPE) == ENUMERAL_TYPE  \
   || TREE_CODE (TYPE) == BOOLEAN_TYPE || TREE_CODE (TYPE) == CHAR_TYPE)

/* Nonzero if TYPE represents a floating-point type, including complex
   floating-point types.  */

#define FLOAT_TYPE_P(TYPE)		\
  (TREE_CODE (TYPE) == REAL_TYPE	\
   || (TREE_CODE (TYPE) == COMPLEX_TYPE \
       && TREE_CODE (TREE_TYPE (TYPE)) == REAL_TYPE))

/* Nonzero if TYPE represents an aggregate (multi-component) type. */

#define AGGREGATE_TYPE_P(TYPE) \
  (TREE_CODE (TYPE) == ARRAY_TYPE || TREE_CODE (TYPE) == RECORD_TYPE \
   || TREE_CODE (TYPE) == UNION_TYPE || TREE_CODE (TYPE) == QUAL_UNION_TYPE \
   || TREE_CODE (TYPE) == SET_TYPE)

/* Nonzero if TYPE represents a pointer type.  */

#define POINTER_TYPE_P(TYPE) \
  (TREE_CODE (TYPE) == POINTER_TYPE || TREE_CODE (TYPE) == REFERENCE_TYPE)

/* Nonzero if TYPE represents a type.  */

#define TYPE_P(TYPE)	(TREE_CODE_CLASS (TREE_CODE (TYPE)) == 't')

/* Define many boolean fields that all tree nodes have.  */

/* In VAR_DECL nodes, nonzero means address of this is needed.
   So it cannot be in a register.
   In a FUNCTION_DECL, nonzero means its address is needed.
   So it must be compiled even if it is an inline function.
   In CONSTRUCTOR nodes, it means object constructed must be in memory.
   In LABEL_DECL nodes, it means a goto for this label has been seen 
   from a place outside all binding contours that restore stack levels.
   In ..._TYPE nodes, it means that objects of this type must
   be fully addressable.  This means that pieces of this
   object cannot go into register parameters, for example.
   In IDENTIFIER_NODEs, this means that some extern decl for this name
   had its address taken.  That matters for inline functions.  */
#define TREE_ADDRESSABLE(NODE) ((NODE)->common.addressable_flag)

/* In a VAR_DECL, nonzero means allocate static storage.
   In a FUNCTION_DECL, nonzero if function has been defined.
   In a CONSTRUCTOR, nonzero means allocate static storage.  */
#define TREE_STATIC(NODE) ((NODE)->common.static_flag)

/* In a CONVERT_EXPR, NOP_EXPR or COMPOUND_EXPR, this means the node was
   made implicitly and should not lead to an "unused value" warning.  */
#define TREE_NO_UNUSED_WARNING(NODE) ((NODE)->common.static_flag)

/* Nonzero for a TREE_LIST or TREE_VEC node means that the derivation
   chain is via a `virtual' declaration.  */
#define TREE_VIA_VIRTUAL(NODE) ((NODE)->common.static_flag)

/* In an INTEGER_CST, REAL_CST, or COMPLEX_CST, this means there was an
   overflow in folding.  This is distinct from TREE_OVERFLOW because ANSI C
   requires a diagnostic when overflows occur in constant expressions.  */
#define TREE_CONSTANT_OVERFLOW(NODE) ((NODE)->common.static_flag)

/* In an IDENTIFIER_NODE, this means that assemble_name was called with
   this string as an argument.  */
#define TREE_SYMBOL_REFERENCED(NODE) ((NODE)->common.static_flag)

/* In an INTEGER_CST, REAL_CST, of COMPLEX_CST, this means there was an
   overflow in folding, and no warning has been issued for this subexpression.
   TREE_OVERFLOW implies TREE_CONSTANT_OVERFLOW, but not vice versa.  */
#define TREE_OVERFLOW(NODE) ((NODE)->common.public_flag)

/* In a VAR_DECL or FUNCTION_DECL,
   nonzero means name is to be accessible from outside this module.
   In an identifier node, nonzero means an external declaration
   accessible from outside this module was previously seen
   for this name in an inner scope.  */
#define TREE_PUBLIC(NODE) ((NODE)->common.public_flag)

/* Nonzero for TREE_LIST or TREE_VEC node means that the path to the
   base class is via a `public' declaration, which preserves public
   fields from the base class as public.  */
#define TREE_VIA_PUBLIC(NODE) ((NODE)->common.public_flag)

/* Ditto, for `private' declarations.  */
#define TREE_VIA_PRIVATE(NODE) ((NODE)->common.private_flag)

/* Nonzero for TREE_LIST node means that the path to the
   base class is via a `protected' declaration, which preserves
   protected fields from the base class as protected.
   OVERLOADED.  */
#define TREE_VIA_PROTECTED(NODE) ((NODE)->common.protected_flag)

/* In any expression, nonzero means it has side effects or reevaluation
   of the whole expression could produce a different value.
   This is set if any subexpression is a function call, a side effect
   or a reference to a volatile variable.
   In a ..._DECL, this is set only if the declaration said `volatile'.  */
#define TREE_SIDE_EFFECTS(NODE) ((NODE)->common.side_effects_flag)

/* Nonzero means this expression is volatile in the C sense:
   its address should be of type `volatile WHATEVER *'.
   In other words, the declared item is volatile qualified.
   This is used in _DECL nodes and _REF nodes.

   In a ..._TYPE node, means this type is volatile-qualified.
   But use TYPE_VOLATILE instead of this macro when the node is a type,
   because eventually we may make that a different bit.

   If this bit is set in an expression, so is TREE_SIDE_EFFECTS.  */
#define TREE_THIS_VOLATILE(NODE) ((NODE)->common.volatile_flag)

/* In a VAR_DECL, PARM_DECL or FIELD_DECL, or any kind of ..._REF node,
   nonzero means it may not be the lhs of an assignment.
   In a ..._TYPE node, means this type is const-qualified
   (but the macro TYPE_READONLY should be used instead of this macro
   when the node is a type).  */
#define TREE_READONLY(NODE) ((NODE)->common.readonly_flag)

/* Value of expression is constant.
   Always appears in all ..._CST nodes.
   May also appear in an arithmetic expression, an ADDR_EXPR or a CONSTRUCTOR
   if the value is constant.  */
#define TREE_CONSTANT(NODE) ((NODE)->common.constant_flag)

/* Nonzero means permanent node;
   node will continue to exist for the entire compiler run.
   Otherwise it will be recycled at the end of the function.  */
#define TREE_PERMANENT(NODE) ((NODE)->common.permanent_flag)

/* In INTEGER_TYPE or ENUMERAL_TYPE nodes, means an unsigned type.
   In FIELD_DECL nodes, means an unsigned bit field.
   The same bit is used in functions as DECL_BUILT_IN_NONANSI.  */
#define TREE_UNSIGNED(NODE) ((NODE)->common.unsigned_flag)

/* Nonzero in a VAR_DECL means assembler code has been written.
   Nonzero in a FUNCTION_DECL means that the function has been compiled.
   This is interesting in an inline function, since it might not need
   to be compiled separately.
   Nonzero in a RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE or ENUMERAL_TYPE
   if the sdb debugging info for the type has been written.
   In a BLOCK node, nonzero if reorder_blocks has already seen this block.  */
#define TREE_ASM_WRITTEN(NODE) ((NODE)->common.asm_written_flag)

/* Nonzero in a _DECL if the name is used in its scope.
   Nonzero in an expr node means inhibit warning if value is unused.
   In IDENTIFIER_NODEs, this means that some extern decl for this name
   was used.  */
#define TREE_USED(NODE) ((NODE)->common.used_flag)

/* Nonzero for a tree node whose evaluation could result
   in the raising of an exception.  Not implemented yet.  */
#define TREE_RAISES(NODE) ((NODE)->common.raises_flag)

/* Used in classes in C++.  */
#define TREE_PRIVATE(NODE) ((NODE)->common.private_flag)
/* Used in classes in C++.
   In a BLOCK node, this is BLOCK_HANDLER_BLOCK.  */
#define TREE_PROTECTED(NODE) ((NODE)->common.protected_flag)

/* These flags are available for each language front end to use internally.  */
#define TREE_LANG_FLAG_0(NODE) ((NODE)->common.lang_flag_0)
#define TREE_LANG_FLAG_1(NODE) ((NODE)->common.lang_flag_1)
#define TREE_LANG_FLAG_2(NODE) ((NODE)->common.lang_flag_2)
#define TREE_LANG_FLAG_3(NODE) ((NODE)->common.lang_flag_3)
#define TREE_LANG_FLAG_4(NODE) ((NODE)->common.lang_flag_4)
#define TREE_LANG_FLAG_5(NODE) ((NODE)->common.lang_flag_5)
#define TREE_LANG_FLAG_6(NODE) ((NODE)->common.lang_flag_6)

/* Define additional fields and accessors for nodes representing constants.  */

/* In an INTEGER_CST node.  These two together make a 2-word integer.
   If the data type is signed, the value is sign-extended to 2 words
   even though not all of them may really be in use.
   In an unsigned constant shorter than 2 words, the extra bits are 0.  */
#define TREE_INT_CST_LOW(NODE) (INTEGER_CST_CHECK (NODE)->int_cst.int_cst_low)
#define TREE_INT_CST_HIGH(NODE) (INTEGER_CST_CHECK (NODE)->int_cst.int_cst_high)

#define INT_CST_LT(A, B)  \
(TREE_INT_CST_HIGH (A) < TREE_INT_CST_HIGH (B)			\
 || (TREE_INT_CST_HIGH (A) == TREE_INT_CST_HIGH (B)		\
     && ((unsigned HOST_WIDE_INT) TREE_INT_CST_LOW (A)		\
	 < (unsigned HOST_WIDE_INT) TREE_INT_CST_LOW (B))))

#define INT_CST_LT_UNSIGNED(A, B)  \
(((unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (A)	\
  < (unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (B))	\
 || (((unsigned HOST_WIDE_INT) TREE_INT_CST_HIGH (A)	\
      == (unsigned HOST_WIDE_INT ) TREE_INT_CST_HIGH (B)) \
     && (((unsigned HOST_WIDE_INT) TREE_INT_CST_LOW (A)	\
	  < (unsigned HOST_WIDE_INT) TREE_INT_CST_LOW (B)))))

struct tree_int_cst
{
  char common[sizeof (struct tree_common)];
  struct rtx_def *rtl;	/* acts as link to register transfer language
			   (rtl) info */
  HOST_WIDE_INT int_cst_low;
  HOST_WIDE_INT int_cst_high;
};

/* In REAL_CST, STRING_CST, COMPLEX_CST nodes, and CONSTRUCTOR nodes,
   and generally in all kinds of constants that could
   be given labels (rather than being immediate).  */

#define TREE_CST_RTL(NODE) (CST_OR_CONSTRUCTOR_CHECK (NODE)->real_cst.rtl)

/* In a REAL_CST node.  */
/* We can represent a real value as either a `double' or a string.
   Strings don't allow for any optimization, but they do allow
   for cross-compilation.  */

#define TREE_REAL_CST(NODE) (REAL_CST_CHECK (NODE)->real_cst.real_cst)

#include "real.h"

struct tree_real_cst
{
  char common[sizeof (struct tree_common)];
  struct rtx_def *rtl;	/* acts as link to register transfer language
				   (rtl) info */
  REAL_VALUE_TYPE real_cst;
};

/* In a STRING_CST */
#define TREE_STRING_LENGTH(NODE) (STRING_CST_CHECK (NODE)->string.length)
#define TREE_STRING_POINTER(NODE) (STRING_CST_CHECK (NODE)->string.pointer)

struct tree_string
{
  char common[sizeof (struct tree_common)];
  struct rtx_def *rtl;	/* acts as link to register transfer language
				   (rtl) info */
  int length;
  char *pointer;
};

/* In a COMPLEX_CST node.  */
#define TREE_REALPART(NODE) (COMPLEX_CST_CHECK (NODE)->complex.real)
#define TREE_IMAGPART(NODE) (COMPLEX_CST_CHECK (NODE)->complex.imag)

struct tree_complex
{
  char common[sizeof (struct tree_common)];
  struct rtx_def *rtl;	/* acts as link to register transfer language
				   (rtl) info */
  union tree_node *real;
  union tree_node *imag;
};

/* Define fields and accessors for some special-purpose tree nodes.  */

#define IDENTIFIER_LENGTH(NODE) (IDENTIFIER_NODE_CHECK (NODE)->identifier.length)
#define IDENTIFIER_POINTER(NODE) (IDENTIFIER_NODE_CHECK (NODE)->identifier.pointer)

struct tree_identifier
{
  char common[sizeof (struct tree_common)];
  int length;
  char *pointer;
};

/* In a TREE_LIST node.  */
#define TREE_PURPOSE(NODE) (TREE_LIST_CHECK (NODE)->list.purpose)
#define TREE_VALUE(NODE) (TREE_LIST_CHECK (NODE)->list.value)

struct tree_list
{
  char common[sizeof (struct tree_common)];
  union tree_node *purpose;
  union tree_node *value;
};

/* In a TREE_VEC node.  */
#define TREE_VEC_LENGTH(NODE) (TREE_VEC_CHECK (NODE)->vec.length)
#define TREE_VEC_ELT(NODE,I) (TREE_VEC_CHECK (NODE)->vec.a[I])
#define TREE_VEC_END(NODE) ((void) TREE_VEC_CHECK (NODE),&((NODE)->vec.a[(NODE)->vec.length]))

struct tree_vec
{
  char common[sizeof (struct tree_common)];
  int length;
  union tree_node *a[1];
};

/* Define fields and accessors for some nodes that represent expressions.  */

/* In a SAVE_EXPR node.  */
#define SAVE_EXPR_CONTEXT(NODE) TREE_OPERAND(NODE, 1)
#define SAVE_EXPR_RTL(NODE) (*(struct rtx_def **) &EXPR_CHECK (NODE)->exp.operands[2])
#define SAVE_EXPR_NOPLACEHOLDER(NODE) TREE_UNSIGNED (NODE)

/* In a RTL_EXPR node.  */
#define RTL_EXPR_SEQUENCE(NODE) (*(struct rtx_def **) &EXPR_CHECK (NODE)->exp.operands[0])
#define RTL_EXPR_RTL(NODE) (*(struct rtx_def **) &EXPR_CHECK (NODE)->exp.operands[1])

/* In a CALL_EXPR node.  */
#define CALL_EXPR_RTL(NODE) (*(struct rtx_def **) &EXPR_CHECK (NODE)->exp.operands[2])

/* In a CONSTRUCTOR node.  */
#define CONSTRUCTOR_ELTS(NODE) TREE_OPERAND (NODE, 1)

/* In ordinary expression nodes.  */
#define TREE_OPERAND(NODE, I) (EXPR_CHECK (NODE)->exp.operands[I])
#define TREE_COMPLEXITY(NODE) (EXPR_CHECK (NODE)->exp.complexity)

/* In a LABELED_BLOCK_EXPR node.  */
#define LABELED_BLOCK_LABEL(NODE) TREE_OPERAND (NODE, 0)
#define LABELED_BLOCK_BODY(NODE) TREE_OPERAND (NODE, 1)

/* In a EXIT_BLOCK_EXPR node.  */
#define EXIT_BLOCK_LABELED_BLOCK(NODE) TREE_OPERAND (NODE, 0)
#define EXIT_BLOCK_RETURN(NODE) TREE_OPERAND (NODE, 1)

/* In a LOOP_EXPR node.  */
#define LOOP_EXPR_BODY(NODE) TREE_OPERAND (NODE, 0)

/* In a EXPR_WITH_FILE_LOCATION node.  */
#define EXPR_WFL_NODE(NODE) TREE_OPERAND((NODE), 0)
#define EXPR_WFL_FILENAME(NODE) (IDENTIFIER_POINTER ((NODE)->common.chain))
#define EXPR_WFL_FILENAME_NODE(NODE) ((NODE)->common.chain)
#define EXPR_WFL_LINENO(NODE) (EXPR_CHECK (NODE)->exp.complexity >> 12)
#define EXPR_WFL_COLNO(NODE) (EXPR_CHECK (NODE)->exp.complexity & 0xfff)
#define EXPR_WFL_LINECOL(NODE) (EXPR_CHECK (NODE)->exp.complexity)
#define EXPR_WFL_SET_LINECOL(NODE, LINE, COL) \
  (EXPR_WFL_LINECOL(NODE) = ((LINE) << 12) | ((COL) & 0xfff))
#define EXPR_WFL_EMIT_LINE_NOTE(NODE) ((NODE)->common.public_flag)

struct tree_exp
{
  char common[sizeof (struct tree_common)];
  int complexity;
  union tree_node *operands[1];
};

/* In a BLOCK node.  */
#define BLOCK_VARS(NODE) (BLOCK_CHECK (NODE)->block.vars)
#define BLOCK_TYPE_TAGS(NODE) (BLOCK_CHECK (NODE)->block.type_tags)
#define BLOCK_SUBBLOCKS(NODE) (BLOCK_CHECK (NODE)->block.subblocks)
#define BLOCK_SUPERCONTEXT(NODE) (BLOCK_CHECK (NODE)->block.supercontext)
/* Note: when changing this, make sure to find the places
   that use chainon or nreverse.  */
#define BLOCK_CHAIN(NODE) TREE_CHAIN (NODE)
#define BLOCK_ABSTRACT_ORIGIN(NODE) (BLOCK_CHECK (NODE)->block.abstract_origin)
#define BLOCK_ABSTRACT(NODE) (BLOCK_CHECK (NODE)->block.abstract_flag)
#define BLOCK_END_NOTE(NODE) (BLOCK_CHECK (NODE)->block.end_note)
/* Nonzero means that this block has separate live range regions */
#define BLOCK_LIVE_RANGE_FLAG(NOTE) (BLOCK_CHECK (NOTE)->block.live_range_flag)

/* Nonzero means that this block has a variable declared in it
   that is split into separate live ranges.  */
#define BLOCK_LIVE_RANGE_VAR_FLAG(NOTE) (BLOCK_CHECK (NOTE)->block.live_range_var_flag)

/* Index for marking the start of the block for live ranges.  */
#define BLOCK_LIVE_RANGE_START(NOTE) (BLOCK_CHECK (NOTE)->block.live_range_start)

/* Index for marking the end of the block for live ranges.  */
#define BLOCK_LIVE_RANGE_END(NOTE) (BLOCK_CHECK (NOTE)->block.live_range_end)

/* Nonzero means that this block is prepared to handle exceptions
   listed in the BLOCK_VARS slot.  */
#define BLOCK_HANDLER_BLOCK(NODE) (BLOCK_CHECK (NODE)->block.handler_block_flag)

struct tree_block
{
  char common[sizeof (struct tree_common)];

  unsigned handler_block_flag : 1;
  unsigned abstract_flag : 1;
  unsigned live_range_flag : 1;
  unsigned live_range_var_flag : 1;

  union tree_node *vars;
  union tree_node *type_tags;
  union tree_node *subblocks;
  union tree_node *supercontext;
  union tree_node *abstract_origin;
  struct rtx_def *end_note;
  int live_range_start;
  int live_range_end;
};

/* Define fields and accessors for nodes representing data types.  */

/* See tree.def for documentation of the use of these fields.
   Look at the documentation of the various ..._TYPE tree codes.  */

#define TYPE_UID(NODE) (TYPE_CHECK (NODE)->type.uid)
#define TYPE_SIZE(NODE) (TYPE_CHECK (NODE)->type.size)
#define TYPE_SIZE_UNIT(NODE) (TYPE_CHECK (NODE)->type.size_unit)
#define TYPE_MODE(NODE) (TYPE_CHECK (NODE)->type.mode)
#define TYPE_VALUES(NODE) (TYPE_CHECK (NODE)->type.values)
#define TYPE_DOMAIN(NODE) (TYPE_CHECK (NODE)->type.values)
#define TYPE_FIELDS(NODE) (TYPE_CHECK (NODE)->type.values)
#define TYPE_METHODS(NODE) (TYPE_CHECK (NODE)->type.maxval)
#define TYPE_VFIELD(NODE) (TYPE_CHECK (NODE)->type.minval)
#define TYPE_ARG_TYPES(NODE) (TYPE_CHECK (NODE)->type.values)
#define TYPE_METHOD_BASETYPE(NODE) (TYPE_CHECK (NODE)->type.maxval)
#define TYPE_OFFSET_BASETYPE(NODE) (TYPE_CHECK (NODE)->type.maxval)
#define TYPE_POINTER_TO(NODE) (TYPE_CHECK (NODE)->type.pointer_to)
#define TYPE_REFERENCE_TO(NODE) (TYPE_CHECK (NODE)->type.reference_to)
#define TYPE_MIN_VALUE(NODE) (TYPE_CHECK (NODE)->type.minval)
#define TYPE_MAX_VALUE(NODE) (TYPE_CHECK (NODE)->type.maxval)
#define TYPE_PRECISION(NODE) (TYPE_CHECK (NODE)->type.precision)
#define TYPE_SYMTAB_ADDRESS(NODE) (TYPE_CHECK (NODE)->type.symtab.address)
#define TYPE_SYMTAB_POINTER(NODE) (TYPE_CHECK (NODE)->type.symtab.pointer)
#define TYPE_NAME(NODE) (TYPE_CHECK (NODE)->type.name)
#define TYPE_NEXT_VARIANT(NODE) (TYPE_CHECK (NODE)->type.next_variant)
#define TYPE_MAIN_VARIANT(NODE) (TYPE_CHECK (NODE)->type.main_variant)
#define TYPE_NONCOPIED_PARTS(NODE) (TYPE_CHECK (NODE)->type.noncopied_parts)
#define TYPE_CONTEXT(NODE) (TYPE_CHECK (NODE)->type.context)
#define TYPE_OBSTACK(NODE) (TYPE_CHECK (NODE)->type.obstack)
#define TYPE_LANG_SPECIFIC(NODE) (TYPE_CHECK (NODE)->type.lang_specific)

/* For aggregate types, information about this type, as a base type
   for itself.  Used in a language-dependent way for types that are
   neither a RECORD_TYPE, QUAL_UNION_TYPE, nor a UNION_TYPE.  */
#define TYPE_BINFO(NODE) (TYPE_CHECK (NODE)->type.binfo)

/* The (language-specific) typed-based alias set for this type.
   Objects whose TYPE_ALIAS_SETs are different cannot alias each
   other.  If the TYPE_ALIAS_SET is -1, no alias set has yet been
   assigned to this type.  If the TYPE_ALIAS_SET is 0, objects of this
   type can alias objects of any type.  */
#define TYPE_ALIAS_SET(NODE) (TYPE_CHECK (NODE)->type.alias_set)

/* Nonzero iff the typed-based alias set for this type has been
   calculated.  */
#define TYPE_ALIAS_SET_KNOWN_P(NODE) \
  (TYPE_CHECK (NODE)->type.alias_set != -1)

/* A TREE_LIST of IDENTIFIER nodes of the attributes that apply
   to this type.  */
#define TYPE_ATTRIBUTES(NODE) (TYPE_CHECK (NODE)->type.attributes)

/* The alignment necessary for objects of this type.
   The value is an int, measured in bits.  */
#define TYPE_ALIGN(NODE) (TYPE_CHECK (NODE)->type.align)

#define TYPE_STUB_DECL(NODE) (TREE_CHAIN (NODE))

/* In a RECORD_TYPE, UNION_TYPE or QUAL_UNION_TYPE, it means the type
   has BLKmode only because it lacks the alignment requirement for
   its size.  */
#define TYPE_NO_FORCE_BLK(NODE) (TYPE_CHECK (NODE)->type.no_force_blk_flag)

/* Nonzero in a type considered volatile as a whole.  */
#define TYPE_VOLATILE(NODE) ((NODE)->common.volatile_flag)

/* Means this type is const-qualified.  */
#define TYPE_READONLY(NODE) ((NODE)->common.readonly_flag)

/* If nonzero, this type is `restrict'-qualified, in the C sense of
   the term.  */
#define TYPE_RESTRICT(NODE) (TYPE_CHECK (NODE)->type.restrict_flag)

/* There is a TYPE_QUAL value for each type qualifier.  They can be
   combined by bitwise-or to form the complete set of qualifiers for a
   type.  */

#define TYPE_UNQUALIFIED   0x0
#define TYPE_QUAL_CONST    0x1
#define TYPE_QUAL_VOLATILE 0x2
#define TYPE_QUAL_RESTRICT 0x4

/* The set of type qualifiers for this type.  */
#define TYPE_QUALS(NODE)			\
  ((TYPE_READONLY(NODE) * TYPE_QUAL_CONST) |	\
   (TYPE_VOLATILE(NODE) * TYPE_QUAL_VOLATILE) |	\
   (TYPE_RESTRICT(NODE) * TYPE_QUAL_RESTRICT))

/* These flags are available for each language front end to use internally.  */
#define TYPE_LANG_FLAG_0(NODE) (TYPE_CHECK (NODE)->type.lang_flag_0)
#define TYPE_LANG_FLAG_1(NODE) (TYPE_CHECK (NODE)->type.lang_flag_1)
#define TYPE_LANG_FLAG_2(NODE) (TYPE_CHECK (NODE)->type.lang_flag_2)
#define TYPE_LANG_FLAG_3(NODE) (TYPE_CHECK (NODE)->type.lang_flag_3)
#define TYPE_LANG_FLAG_4(NODE) (TYPE_CHECK (NODE)->type.lang_flag_4)
#define TYPE_LANG_FLAG_5(NODE) (TYPE_CHECK (NODE)->type.lang_flag_5)
#define TYPE_LANG_FLAG_6(NODE) (TYPE_CHECK (NODE)->type.lang_flag_6)

/* If set in an ARRAY_TYPE, indicates a string type (for languages
   that distinguish string from array of char).
   If set in a SET_TYPE, indicates a bitstring type. */
#define TYPE_STRING_FLAG(NODE) (TYPE_CHECK (NODE)->type.string_flag)

/* If non-NULL, this is a upper bound of the size (in bytes) of an
   object of the given ARRAY_TYPE.  This allows temporaries to be allocated. */
#define TYPE_ARRAY_MAX_SIZE(ARRAY_TYPE) TYPE_MAX_VALUE (ARRAY_TYPE)

/* Indicates that objects of this type must be initialized by calling a
   function when they are created.  */
#define TYPE_NEEDS_CONSTRUCTING(NODE) (TYPE_CHECK (NODE)->type.needs_constructing_flag)

/* Indicates that objects of this type (a UNION_TYPE), should be passed
   the same way that the first union alternative would be passed.  */
#define TYPE_TRANSPARENT_UNION(NODE) (TYPE_CHECK (NODE)->type.transparent_union_flag)

/* Indicated that objects of this type should be laid out in as
   compact a way as possible.  */
#define TYPE_PACKED(NODE) (TYPE_CHECK (NODE)->type.packed_flag)

struct tree_type
{
  char common[sizeof (struct tree_common)];
  union tree_node *values;
  union tree_node *size;
  union tree_node *size_unit;
  union tree_node *attributes;
  unsigned uid;

  unsigned char precision;
#ifdef ONLY_INT_FIELDS
  int mode : 8;
#else
  enum machine_mode mode : 8;
#endif

  unsigned string_flag : 1;
  unsigned no_force_blk_flag : 1;
  unsigned needs_constructing_flag : 1;
  unsigned transparent_union_flag : 1;
  unsigned packed_flag : 1;
  unsigned restrict_flag : 1;

  unsigned lang_flag_0 : 1;
  unsigned lang_flag_1 : 1;
  unsigned lang_flag_2 : 1;
  unsigned lang_flag_3 : 1;
  unsigned lang_flag_4 : 1;
  unsigned lang_flag_5 : 1;
  unsigned lang_flag_6 : 1;
  /* room for 3 more bits */

  unsigned int align;
  union tree_node *pointer_to;
  union tree_node *reference_to;
  union {int address; char *pointer; } symtab;
  union tree_node *name;
  union tree_node *minval;
  union tree_node *maxval;
  union tree_node *next_variant;
  union tree_node *main_variant;
  union tree_node *binfo;
  union tree_node *noncopied_parts;
  union tree_node *context;
  struct obstack *obstack;
  int alias_set;
  /* Points to a structure whose details depend on the language in use.  */
  struct lang_type *lang_specific;
};

/* Define accessor macros for information about type inheritance
   and basetypes.

   A "basetype" means a particular usage of a data type for inheritance
   in another type.  Each such basetype usage has its own "binfo"
   object to describe it.  The binfo object is a TREE_VEC node.

   Inheritance is represented by the binfo nodes allocated for a
   given type.  For example, given types C and D, such that D is
   inherited by C, 3 binfo nodes will be allocated: one for describing
   the binfo properties of C, similarly one for D, and one for
   describing the binfo properties of D as a base type for C.
   Thus, given a pointer to class C, one can get a pointer to the binfo
   of D acting as a basetype for C by looking at C's binfo's basetypes.  */

/* The actual data type node being inherited in this basetype.  */
#define BINFO_TYPE(NODE) TREE_TYPE (NODE)

/* The offset where this basetype appears in its containing type.
   BINFO_OFFSET slot holds the offset (in bytes)
   from the base of the complete object to the base of the part of the
   object that is allocated on behalf of this `type'.
   This is always 0 except when there is multiple inheritance.  */
   
#define BINFO_OFFSET(NODE) TREE_VEC_ELT ((NODE), 1)
#define TYPE_BINFO_OFFSET(NODE) BINFO_OFFSET (TYPE_BINFO (NODE))
#define BINFO_OFFSET_ZEROP(NODE) (integer_zerop (BINFO_OFFSET (NODE)))

/* The virtual function table belonging to this basetype.  Virtual
   function tables provide a mechanism for run-time method dispatching.
   The entries of a virtual function table are language-dependent.  */

#define BINFO_VTABLE(NODE) TREE_VEC_ELT ((NODE), 2)
#define TYPE_BINFO_VTABLE(NODE) BINFO_VTABLE (TYPE_BINFO (NODE))

/* The virtual functions in the virtual function table.  This is
   a TREE_LIST that is used as an initial approximation for building
   a virtual function table for this basetype.  */
#define BINFO_VIRTUALS(NODE) TREE_VEC_ELT ((NODE), 3)
#define TYPE_BINFO_VIRTUALS(NODE) BINFO_VIRTUALS (TYPE_BINFO (NODE))

/* A vector of additional binfos for the types inherited by this basetype.

   If this basetype describes type D as inherited in C,
   and if the basetypes of D are E anf F,
   then this vector contains binfos for inheritance of E and F by C.

   ??? This could probably be done by just allocating the
   base types at the end of this TREE_VEC (instead of using
   another TREE_VEC).  This would simplify the calculation
   of how many basetypes a given type had.  */
#define BINFO_BASETYPES(NODE) TREE_VEC_ELT ((NODE), 4)
#define TYPE_BINFO_BASETYPES(NODE) TREE_VEC_ELT (TYPE_BINFO (NODE), 4)

/* Accessor macro to get to the Nth basetype of this basetype.  */
#define BINFO_BASETYPE(NODE,N) TREE_VEC_ELT (BINFO_BASETYPES (NODE), (N))
#define TYPE_BINFO_BASETYPE(NODE,N) BINFO_TYPE (TREE_VEC_ELT (BINFO_BASETYPES (TYPE_BINFO (NODE)), (N)))

/* For a BINFO record describing an inheritance, this yields a pointer
   to the artificial FIELD_DECL node which contains the "virtual base
   class pointer" for the given inheritance.  */
#define BINFO_VPTR_FIELD(NODE) TREE_VEC_ELT ((NODE), 5)

/* The size of a base class subobject of this type.  Not all frontends
   currently allocate the space for this field.  */
#define BINFO_SIZE(NODE) TREE_VEC_ELT ((NODE), 6)
#define TYPE_BINFO_SIZE(NODE) BINFO_SIZE (TYPE_BINFO (NODE))

/* Slot used to build a chain that represents a use of inheritance.
   For example, if X is derived from Y, and Y is derived from Z,
   then this field can be used to link the binfo node for X to
   the binfo node for X's Y to represent the use of inheritance
   from X to Y.  Similarly, this slot of the binfo node for X's Y
   can point to the Z from which Y is inherited (in X's inheritance
   hierarchy).  In this fashion, one can represent and traverse specific
   uses of inheritance using the binfo nodes themselves (instead of
   consing new space pointing to binfo nodes).
   It is up to the language-dependent front-ends to maintain
   this information as necessary.  */
#define BINFO_INHERITANCE_CHAIN(NODE) TREE_VEC_ELT ((NODE), 0)

/* Define fields and accessors for nodes representing declared names.  */

/* This is the name of the object as written by the user.
   It is an IDENTIFIER_NODE.  */
#define DECL_NAME(NODE) (DECL_CHECK (NODE)->decl.name)
/* This is the name of the object as the assembler will see it
   (but before any translations made by ASM_OUTPUT_LABELREF).
   Often this is the same as DECL_NAME.
   It is an IDENTIFIER_NODE.  */
#define DECL_ASSEMBLER_NAME(NODE) (DECL_CHECK (NODE)->decl.assembler_name)
/* Records the section name in a section attribute.  Used to pass
   the name from decl_attributes to make_function_rtl and make_decl_rtl.  */
#define DECL_SECTION_NAME(NODE) (DECL_CHECK (NODE)->decl.section_name)
/*  For FIELD_DECLs, this is the
    RECORD_TYPE, UNION_TYPE, or QUAL_UNION_TYPE node that the field is
    a member of.  For VAR_DECL, PARM_DECL, FUNCTION_DECL, LABEL_DECL,
    and CONST_DECL nodes, this points to either the FUNCTION_DECL for the
    containing function, the RECORD_TYPE or UNION_TYPE for the containing
    type, or NULL_TREE if the given decl has "file scope".  */
#define DECL_CONTEXT(NODE) (DECL_CHECK (NODE)->decl.context)
#define DECL_FIELD_CONTEXT(NODE) (DECL_CHECK (NODE)->decl.context)
/* In a DECL this is the field where configuration dependent machine
   attributes are store */
#define DECL_MACHINE_ATTRIBUTES(NODE) (DECL_CHECK (NODE)->decl.machine_attributes)
/* In a FIELD_DECL, this is the field position, counting in bits,
   of the bit closest to the beginning of the structure.  */
#define DECL_FIELD_BITPOS(NODE) (DECL_CHECK (NODE)->decl.arguments)
/* In a FIELD_DECL, this indicates whether the field was a bit-field and
   if so, the type that was originally specified for it.
   TREE_TYPE may have been modified (in finish_struct).  */
#define DECL_BIT_FIELD_TYPE(NODE) (DECL_CHECK (NODE)->decl.result)
/* In FUNCTION_DECL, a chain of ..._DECL nodes.  */
/* VAR_DECL and PARM_DECL reserve the arguments slot
   for language-specific uses.  */
#define DECL_ARGUMENTS(NODE) (DECL_CHECK (NODE)->decl.arguments)
/* In FUNCTION_DECL, holds the decl for the return value.  */
#define DECL_RESULT(NODE) (DECL_CHECK (NODE)->decl.result)
/* For a TYPE_DECL, holds the "original" type.  (TREE_TYPE has the copy.) */
#define DECL_ORIGINAL_TYPE(NODE) (DECL_CHECK (NODE)->decl.result)
/* In PARM_DECL, holds the type as written (perhaps a function or array).  */
#define DECL_ARG_TYPE_AS_WRITTEN(NODE) (DECL_CHECK (NODE)->decl.result)
/* For a FUNCTION_DECL, holds the tree of BINDINGs.
   For a VAR_DECL, holds the initial value.
   For a PARM_DECL, not used--default
   values for parameters are encoded in the type of the function,
   not in the PARM_DECL slot.  */
#define DECL_INITIAL(NODE) (DECL_CHECK (NODE)->decl.initial)
/* For a PARM_DECL, records the data type used to pass the argument,
   which may be different from the type seen in the program.  */
#define DECL_ARG_TYPE(NODE) (DECL_CHECK (NODE)->decl.initial)   /* In PARM_DECL.  */
/* For a FIELD_DECL in a QUAL_UNION_TYPE, records the expression, which
   if nonzero, indicates that the field occupies the type.  */
#define DECL_QUALIFIER(NODE) (DECL_CHECK (NODE)->decl.initial)
/* These two fields describe where in the source code the declaration was.  */
#define DECL_SOURCE_FILE(NODE) (DECL_CHECK (NODE)->decl.filename)
#define DECL_SOURCE_LINE(NODE) (DECL_CHECK (NODE)->decl.linenum)
/* Holds the size of the datum, as a tree expression.
   Need not be constant.  */
#define DECL_SIZE(NODE) (DECL_CHECK (NODE)->decl.size)
/* Holds the alignment required for the datum.  */
#define DECL_ALIGN(NODE) (DECL_CHECK (NODE)->decl.frame_size.u)
/* Holds the machine mode corresponding to the declaration of a variable or
   field.  Always equal to TYPE_MODE (TREE_TYPE (decl)) except for a
   FIELD_DECL.  */
#define DECL_MODE(NODE) (DECL_CHECK (NODE)->decl.mode)
/* Holds the RTL expression for the value of a variable or function.  If
   PROMOTED_MODE is defined, the mode of this expression may not be same
   as DECL_MODE.  In that case, DECL_MODE contains the mode corresponding
   to the variable's data type, while the mode
   of DECL_RTL is the mode actually used to contain the data.  */
#define DECL_RTL(NODE) (DECL_CHECK (NODE)->decl.rtl)
/* Holds an INSN_LIST of all of the live ranges in which the variable
   has been moved to a possibly different register.  */
#define DECL_LIVE_RANGE_RTL(NODE) (DECL_CHECK (NODE)->decl.live_range_rtl)
/* For PARM_DECL, holds an RTL for the stack slot or register
   where the data was actually passed.  */
#define DECL_INCOMING_RTL(NODE) (DECL_CHECK (NODE)->decl.saved_insns.r)
/* For FUNCTION_DECL, if it is inline, holds the saved insn chain.  */
#define DECL_SAVED_INSNS(NODE) (DECL_CHECK (NODE)->decl.saved_insns.r)
/* For FUNCTION_DECL, if it is inline,
   holds the size of the stack frame, as an integer.  */
#define DECL_FRAME_SIZE(NODE) (DECL_CHECK (NODE)->decl.frame_size.i)
/* For FUNCTION_DECL, if it is built-in,
   this identifies which built-in operation it is.  */
#define DECL_FUNCTION_CODE(NODE) (DECL_CHECK (NODE)->decl.frame_size.f)
#define DECL_SET_FUNCTION_CODE(NODE,VAL) (DECL_CHECK (NODE)->decl.frame_size.f = (VAL))
/* For a FIELD_DECL, holds the size of the member as an integer.  */
#define DECL_FIELD_SIZE(NODE) (DECL_CHECK (NODE)->decl.saved_insns.i)

/* The DECL_VINDEX is used for FUNCTION_DECLS in two different ways.
   Before the struct containing the FUNCTION_DECL is laid out,
   DECL_VINDEX may point to a FUNCTION_DECL in a base class which
   is the FUNCTION_DECL which this FUNCTION_DECL will replace as a virtual
   function.  When the class is laid out, this pointer is changed
   to an INTEGER_CST node which is suitable for use as an index
   into the virtual function table.  */
#define DECL_VINDEX(NODE) (DECL_CHECK (NODE)->decl.vindex)
/* For FIELD_DECLS, DECL_FCONTEXT is the *first* baseclass in
   which this FIELD_DECL is defined.  This information is needed when
   writing debugging information about vfield and vbase decls for C++.  */
#define DECL_FCONTEXT(NODE) (DECL_CHECK (NODE)->decl.vindex)

/* Every ..._DECL node gets a unique number.  */
#define DECL_UID(NODE) (DECL_CHECK (NODE)->decl.uid)

/* For any sort of a ..._DECL node, this points to the original (abstract)
   decl node which this decl is an instance of, or else it is NULL indicating
   that this decl is not an instance of some other decl.  For example,
   in a nested declaration of an inline function, this points back to the
   definition.  */
#define DECL_ABSTRACT_ORIGIN(NODE) (DECL_CHECK (NODE)->decl.abstract_origin)

/* Like DECL_ABSTRACT_ORIGIN, but returns NODE if there's no abstract
   origin.  This is useful when setting the DECL_ABSTRACT_ORIGIN.  */
#define DECL_ORIGIN(NODE) \
  (DECL_ABSTRACT_ORIGIN (NODE) ? DECL_ABSTRACT_ORIGIN (NODE) : NODE)

/* Nonzero for any sort of ..._DECL node means this decl node represents
   an inline instance of some original (abstract) decl from an inline function;
   suppress any warnings about shadowing some other variable.  */
#define DECL_FROM_INLINE(NODE) (DECL_ABSTRACT_ORIGIN (NODE) != (tree) 0)

/* Nonzero if a _DECL means that the name of this decl should be ignored
   for symbolic debug purposes.  */
#define DECL_IGNORED_P(NODE) (DECL_CHECK (NODE)->decl.ignored_flag)

/* Nonzero for a given ..._DECL node means that this node represents an
   "abstract instance" of the given declaration (e.g. in the original
   declaration of an inline function).  When generating symbolic debugging
   information, we mustn't try to generate any address information for nodes
   marked as "abstract instances" because we don't actually generate
   any code or allocate any data space for such instances.  */
#define DECL_ABSTRACT(NODE) (DECL_CHECK (NODE)->decl.abstract_flag)

/* Nonzero if a _DECL means that no warnings should be generated just
   because this decl is unused.  */
#define DECL_IN_SYSTEM_HEADER(NODE) (DECL_CHECK (NODE)->decl.in_system_header_flag)

/* Nonzero for a given ..._DECL node means that this node should be
   put in .common, if possible.  If a DECL_INITIAL is given, and it
   is not error_mark_node, then the decl cannot be put in .common.  */
#define DECL_COMMON(NODE) (DECL_CHECK (NODE)->decl.common_flag)

/* Language-specific decl information.  */
#define DECL_LANG_SPECIFIC(NODE) (DECL_CHECK (NODE)->decl.lang_specific)

/* In a VAR_DECL or FUNCTION_DECL,
   nonzero means external reference:
   do not allocate storage, and refer to a definition elsewhere.  */
#define DECL_EXTERNAL(NODE) (DECL_CHECK (NODE)->decl.external_flag)

/* In a VAR_DECL for a RECORD_TYPE, sets number for non-init_priority
   initializatons. */
#define DEFAULT_INIT_PRIORITY 65535
#define MAX_INIT_PRIORITY 65535
#define MAX_RESERVED_INIT_PRIORITY 100

/* In a TYPE_DECL
   nonzero means the detail info about this type is not dumped into stabs.
   Instead it will generate cross reference ('x') of names. 
   This uses the same flag as DECL_EXTERNAL. */
#define TYPE_DECL_SUPPRESS_DEBUG(NODE) (DECL_CHECK (NODE)->decl.external_flag)
   

/* In VAR_DECL and PARM_DECL nodes, nonzero means declared `register'.  */
#define DECL_REGISTER(NODE) (DECL_CHECK (NODE)->decl.regdecl_flag)
/* In LABEL_DECL nodes, nonzero means that an error message about
   jumping into such a binding contour has been printed for this label.  */
#define DECL_ERROR_ISSUED(NODE) (DECL_CHECK (NODE)->decl.regdecl_flag)
/* In a FIELD_DECL, indicates this field should be bit-packed.  */
#define DECL_PACKED(NODE) (DECL_CHECK (NODE)->decl.regdecl_flag)
/* In a FUNCTION_DECL with a non-zero DECL_CONTEXT, indicates that a
   static chain is not needed.  */
#define DECL_NO_STATIC_CHAIN(NODE) (DECL_CHECK (NODE)->decl.regdecl_flag)

/* Nonzero in a ..._DECL means this variable is ref'd from a nested function.
   For VAR_DECL nodes, PARM_DECL nodes, and FUNCTION_DECL nodes.

   For LABEL_DECL nodes, nonzero if nonlocal gotos to the label are permitted.

   Also set in some languages for variables, etc., outside the normal
   lexical scope, such as class instance variables.  */
#define DECL_NONLOCAL(NODE) (DECL_CHECK (NODE)->decl.nonlocal_flag)

/* Nonzero in a FUNCTION_DECL means this function can be substituted
   where it is called.  */
#define DECL_INLINE(NODE) (DECL_CHECK (NODE)->decl.inline_flag)

/* Nonzero in a FUNCTION_DECL means this is a built-in function
   that is not specified by ansi C and that users are supposed to be allowed
   to redefine for any purpose whatever.  */
#define DECL_BUILT_IN_NONANSI(NODE) ((NODE)->common.unsigned_flag)

/* Nonzero in a FIELD_DECL means it is a bit field, and must be accessed
   specially.  */
#define DECL_BIT_FIELD(NODE) (DECL_CHECK (NODE)->decl.bit_field_flag)
/* In a LABEL_DECL, nonzero means label was defined inside a binding
   contour that restored a stack level and which is now exited.  */
#define DECL_TOO_LATE(NODE) (DECL_CHECK (NODE)->decl.bit_field_flag)
/* In a FUNCTION_DECL, nonzero means a built in function.  */
#define DECL_BUILT_IN(NODE) (DECL_CHECK (NODE)->decl.bit_field_flag)
/* In a VAR_DECL that's static,
   nonzero if the space is in the text section.  */
#define DECL_IN_TEXT_SECTION(NODE) (DECL_CHECK (NODE)->decl.bit_field_flag)

/* Used in VAR_DECLs to indicate that the variable is a vtable.
   Used in FIELD_DECLs for vtable pointers.
   Used in FUNCTION_DECLs to indicate that the function is virtual.  */
#define DECL_VIRTUAL_P(NODE) (DECL_CHECK (NODE)->decl.virtual_flag)

/* Used to indicate that the linkage status of this DECL is not yet known,
   so it should not be output now.  */
#define DECL_DEFER_OUTPUT(NODE) (DECL_CHECK (NODE)->decl.defer_output)

/* Used in PARM_DECLs whose type are unions to indicate that the
   argument should be passed in the same way that the first union
   alternative would be passed.  */
#define DECL_TRANSPARENT_UNION(NODE) (DECL_CHECK (NODE)->decl.transparent_union)

/* Used in FUNCTION_DECLs to indicate that they should be run automatically
   at the beginning or end of execution.  */
#define DECL_STATIC_CONSTRUCTOR(NODE) (DECL_CHECK (NODE)->decl.static_ctor_flag)
#define DECL_STATIC_DESTRUCTOR(NODE) (DECL_CHECK (NODE)->decl.static_dtor_flag)

/* Used to indicate that this DECL represents a compiler-generated entity.  */
#define DECL_ARTIFICIAL(NODE) (DECL_CHECK (NODE)->decl.artificial_flag)

/* Used to indicate that this DECL has weak linkage.  */
#define DECL_WEAK(NODE) (DECL_CHECK (NODE)->decl.weak_flag)

/* Used in TREE_PUBLIC decls to indicate that copies of this DECL in
   multiple translation units should be merged.  */
#define DECL_ONE_ONLY(NODE) (DECL_CHECK (NODE)->decl.transparent_union)

/* Used in FUNCTION_DECLs to indicate that function entry and exit should
   be instrumented with calls to support routines.  */
#define DECL_NO_INSTRUMENT_FUNCTION_ENTRY_EXIT(NODE) ((NODE)->decl.no_instrument_function_entry_exit)

/* Used in FUNCTION_DECLs to indicate that in this function,
   check-memory-usage should be disabled.  */
#define DECL_NO_CHECK_MEMORY_USAGE(NODE) ((NODE)->decl.no_check_memory_usage)

/* Additional flags for language-specific uses.  */
#define DECL_LANG_FLAG_0(NODE) (DECL_CHECK (NODE)->decl.lang_flag_0)
#define DECL_LANG_FLAG_1(NODE) (DECL_CHECK (NODE)->decl.lang_flag_1)
#define DECL_LANG_FLAG_2(NODE) (DECL_CHECK (NODE)->decl.lang_flag_2)
#define DECL_LANG_FLAG_3(NODE) (DECL_CHECK (NODE)->decl.lang_flag_3)
#define DECL_LANG_FLAG_4(NODE) (DECL_CHECK (NODE)->decl.lang_flag_4)
#define DECL_LANG_FLAG_5(NODE) (DECL_CHECK (NODE)->decl.lang_flag_5)
#define DECL_LANG_FLAG_6(NODE) (DECL_CHECK (NODE)->decl.lang_flag_6)
#define DECL_LANG_FLAG_7(NODE) (DECL_CHECK (NODE)->decl.lang_flag_7)

/* Used to indicate that the pointer to this DECL cannot be treated as
   an address constant.  */
#define DECL_NON_ADDR_CONST_P(NODE) (DECL_CHECK (NODE)->decl.non_addr_const_p)

/* Used to indicate an alias set for the memory pointed to by this
   particular FIELD_DECL, PARM_DECL, or VAR_DECL, which must have
   pointer (or reference) type.  */
#define DECL_POINTER_ALIAS_SET(NODE) \
  (DECL_CHECK (NODE)->decl.pointer_alias_set)

/* Nonzero if an alias set has been assigned to this declaration.  */
#define DECL_POINTER_ALIAS_SET_KNOWN_P(NODE) \
  (DECL_POINTER_ALIAS_SET (NODE) != - 1)

struct tree_decl
{
  char common[sizeof (struct tree_common)];
  char *filename;
  int linenum;
  unsigned int uid;
  union tree_node *size;
#ifdef ONLY_INT_FIELDS
  int mode : 8;
#else
  enum machine_mode mode : 8;
#endif

  unsigned external_flag : 1;
  unsigned nonlocal_flag : 1;
  unsigned regdecl_flag : 1;
  unsigned inline_flag : 1;
  unsigned bit_field_flag : 1;
  unsigned virtual_flag : 1;
  unsigned ignored_flag : 1;
  unsigned abstract_flag : 1;

  unsigned in_system_header_flag : 1;
  unsigned common_flag : 1;
  unsigned defer_output : 1;
  unsigned transparent_union : 1;
  unsigned static_ctor_flag : 1;
  unsigned static_dtor_flag : 1;
  unsigned artificial_flag : 1;
  unsigned weak_flag : 1;

  unsigned lang_flag_0 : 1;
  unsigned lang_flag_1 : 1;
  unsigned lang_flag_2 : 1;
  unsigned lang_flag_3 : 1;
  unsigned lang_flag_4 : 1;
  unsigned lang_flag_5 : 1;
  unsigned lang_flag_6 : 1;
  unsigned lang_flag_7 : 1;

  unsigned non_addr_const_p : 1;
  unsigned no_instrument_function_entry_exit : 1;
  unsigned no_check_memory_usage : 1;

  /* For a FUNCTION_DECL, if inline, this is the size of frame needed.
     If built-in, this is the code for which built-in function.
     For other kinds of decls, this is DECL_ALIGN.  */
  union {
    int i;
    unsigned int u;
    enum built_in_function f;
  } frame_size;

  union tree_node *name;
  union tree_node *context;
  union tree_node *arguments;
  union tree_node *result;
  union tree_node *initial;
  union tree_node *abstract_origin;
  union tree_node *assembler_name;
  union tree_node *section_name;
  union tree_node *machine_attributes;
  struct rtx_def *rtl;	/* acts as link to register transfer language
				   (rtl) info */
  struct rtx_def *live_range_rtl;
  /* For FUNCTION_DECLs: points to insn that constitutes its definition
     on the permanent obstack.  For FIELD_DECL, this is DECL_FIELD_SIZE.  */
  union {
    struct rtx_def *r;
    HOST_WIDE_INT i;
  } saved_insns;
  union tree_node *vindex;
  int pointer_alias_set;
  /* Points to a structure whose details depend on the language in use.  */
  struct lang_decl *lang_specific;
};

/* Define the overall contents of a tree node.
   It may be any of the structures declared above
   for various types of node.  */

union tree_node
{
  struct tree_common common;
  struct tree_int_cst int_cst;
  struct tree_real_cst real_cst;
  struct tree_string string;
  struct tree_complex complex;
  struct tree_identifier identifier;
  struct tree_decl decl;
  struct tree_type type;
  struct tree_list list;
  struct tree_vec vec;
  struct tree_exp exp;
  struct tree_block block;
 };

#define NULL_TREE (tree) NULL

/* The following functions accept a wide integer argument.  Rather than
   having to cast on every function call, we use a macro instead, that is
   defined here and in rtl.h.  */

#ifndef exact_log2
#define exact_log2(N) exact_log2_wide ((unsigned HOST_WIDE_INT) (N))
#define floor_log2(N) floor_log2_wide ((unsigned HOST_WIDE_INT) (N))
#endif
extern int exact_log2_wide             PROTO((unsigned HOST_WIDE_INT));
extern int floor_log2_wide             PROTO((unsigned HOST_WIDE_INT));

extern char *oballoc			PROTO((int));
extern char *permalloc			PROTO((int));
extern char *savealloc			PROTO((int));
extern char *expralloc			PROTO((int));

/* Lowest level primitive for allocating a node.
   The TREE_CODE is the only argument.  Contents are initialized
   to zero except for a few of the common fields.  */

extern tree make_node			PROTO((enum tree_code));

/* Make a copy of a node, with all the same contents except
   for TREE_PERMANENT.  (The copy is permanent
   iff nodes being made now are permanent.)  */

extern tree copy_node			PROTO((tree));

/* Make a copy of a chain of TREE_LIST nodes.  */

extern tree copy_list			PROTO((tree));

/* Make a TREE_VEC.  */

extern tree make_tree_vec		PROTO((int));

/* Return the (unique) IDENTIFIER_NODE node for a given name.
   The name is supplied as a char *.  */

extern tree get_identifier		PROTO((char *));

/* If an identifier with the name TEXT (a null-terminated string) has
   previously been referred to, return that node; otherwise return
   NULL_TREE.  */

extern tree maybe_get_identifier	PROTO((char *));

/* Construct various types of nodes.  */

#define build_int_2(LO,HI)  \
  build_int_2_wide ((HOST_WIDE_INT) (LO), (HOST_WIDE_INT) (HI))

extern tree build			PVPROTO((enum tree_code, tree, ...));
extern tree build_nt			PVPROTO((enum tree_code, ...));
extern tree build_parse_node		PVPROTO((enum tree_code, ...));

extern tree build_int_2_wide		PROTO((HOST_WIDE_INT, HOST_WIDE_INT));
extern tree build_real			PROTO((tree, REAL_VALUE_TYPE));
extern tree build_real_from_int_cst 	PROTO((tree, tree));
extern tree build_complex		PROTO((tree, tree, tree));
extern tree build_string		PROTO((int, char *));
extern tree build1			PROTO((enum tree_code, tree, tree));
extern tree build_tree_list		PROTO((tree, tree));
extern tree build_decl_list		PROTO((tree, tree));
extern tree build_expr_list		PROTO((tree, tree));
extern tree build_decl			PROTO((enum tree_code, tree, tree));
extern tree build_block			PROTO((tree, tree, tree, tree, tree));
extern tree build_expr_wfl              PROTO((tree, char *, int, int));

/* Construct various nodes representing data types.  */

extern tree make_signed_type		PROTO((int));
extern tree make_unsigned_type		PROTO((int));
extern void set_sizetype		PROTO((tree));
extern tree signed_or_unsigned_type 	PROTO((int, tree));
extern void fixup_unsigned_type		PROTO((tree));
extern tree build_pointer_type		PROTO((tree));
extern tree build_reference_type 	PROTO((tree));
extern tree build_index_type		PROTO((tree));
extern tree build_index_2_type		PROTO((tree, tree));
extern tree build_array_type		PROTO((tree, tree));
extern tree build_function_type		PROTO((tree, tree));
extern tree build_method_type		PROTO((tree, tree));
extern tree build_offset_type		PROTO((tree, tree));
extern tree build_complex_type		PROTO((tree));
extern tree array_type_nelts		PROTO((tree));

extern tree value_member		PROTO((tree, tree));
extern tree purpose_member		PROTO((tree, tree));
extern tree binfo_member		PROTO((tree, tree));
extern int attribute_hash_list		PROTO((tree));
extern int attribute_list_equal		PROTO((tree, tree));
extern int attribute_list_contained	PROTO((tree, tree));
extern int tree_int_cst_equal		PROTO((tree, tree));
extern int tree_int_cst_lt		PROTO((tree, tree));
extern int tree_int_cst_sgn		PROTO((tree));
extern int index_type_equal		PROTO((tree, tree));
extern tree get_inner_array_type	PROTO((tree));

/* From expmed.c.  Since rtl.h is included after tree.h, we can't
   put the prototype here.  Rtl.h does declare the prototype if
   tree.h had been included.  */

extern tree make_tree			PROTO((tree, struct rtx_def *));

/* Return a type like TTYPE except that its TYPE_ATTRIBUTES
   is ATTRIBUTE.

   Such modified types already made are recorded so that duplicates
   are not made. */

extern tree build_type_attribute_variant PROTO((tree, tree));
extern tree build_decl_attribute_variant PROTO((tree, tree));

extern tree merge_machine_decl_attributes PROTO((tree, tree));
extern tree merge_machine_type_attributes PROTO((tree, tree));

/* Split a list of declspecs and attributes into two.  */

extern void split_specs_attrs		PROTO((tree, tree *, tree *));

/* Strip attributes from a list of combined specs and attrs.  */

extern tree strip_attrs			PROTO((tree));

/* Return 1 if an attribute and its arguments are valid for a decl or type.  */

extern int valid_machine_attribute	PROTO((tree, tree, tree, tree));

/* Given a tree node and a string, return non-zero if the tree node is
   a valid attribute name for the string.  */

extern int is_attribute_p		PROTO((char *, tree));

/* Given an attribute name and a list of attributes, return the list element
   of the attribute or NULL_TREE if not found.  */

extern tree lookup_attribute		PROTO((char *, tree));

/* Given two attributes lists, return a list of their union.  */

extern tree merge_attributes		PROTO((tree, tree));

/* Given a type node TYPE and a TYPE_QUALIFIER_SET, return a type for
   the same kind of data as TYPE describes.  Variants point to the
   "main variant" (which has no qualifiers set) via TYPE_MAIN_VARIANT,
   and it points to a chain of other variants so that duplicate
   variants are never made.  Only main variants should ever appear as
   types of expressions.  */

extern tree build_qualified_type        PROTO((tree, int));

/* Like build_qualified_type, but only deals with the `const' and
   `volatile' qualifiers.  This interface is retained for backwards
   compatiblity with the various front-ends; new code should use
   build_qualified_type instead.  */

#define build_type_variant(TYPE, CONST_P, VOLATILE_P)			\
  build_qualified_type (TYPE,						\
			((CONST_P) ? TYPE_QUAL_CONST : 0)		\
			| ((VOLATILE_P) ? TYPE_QUAL_VOLATILE : 0))

/* Make a copy of a type node.  */

extern tree build_type_copy		PROTO((tree));

/* Given a ..._TYPE node, calculate the TYPE_SIZE, TYPE_SIZE_UNIT,
   TYPE_ALIGN and TYPE_MODE fields.
   If called more than once on one node, does nothing except
   for the first time.  */

extern void layout_type			PROTO((tree));

/* Given a hashcode and a ..._TYPE node (for which the hashcode was made),
   return a canonicalized ..._TYPE node, so that duplicates are not made.
   How the hash code is computed is up to the caller, as long as any two
   callers that could hash identical-looking type nodes agree.  */

extern tree type_hash_canon		PROTO((int, tree));

/* Given a VAR_DECL, PARM_DECL, RESULT_DECL or FIELD_DECL node,
   calculates the DECL_SIZE, DECL_SIZE_UNIT, DECL_ALIGN and DECL_MODE
   fields.  Call this only once for any given decl node.

   Second argument is the boundary that this field can be assumed to
   be starting at (in bits).  Zero means it can be assumed aligned
   on any boundary that may be needed.  */

extern void layout_decl			PROTO((tree, unsigned));

/* Return an expr equal to X but certainly not valid as an lvalue.  */

extern tree non_lvalue			PROTO((tree));
extern tree pedantic_non_lvalue		PROTO((tree));

extern tree convert			PROTO((tree, tree));
extern tree size_in_bytes		PROTO((tree));
extern HOST_WIDE_INT int_size_in_bytes	PROTO((tree));
extern tree size_binop			PROTO((enum tree_code, tree, tree));
extern tree ssize_binop			PROTO((enum tree_code, tree, tree));
extern tree size_int_wide		PROTO((unsigned HOST_WIDE_INT,
					       unsigned HOST_WIDE_INT, int));
#define size_int(L) size_int_2 ((L), 0, 0)
#define bitsize_int(L, H) size_int_2 ((L), (H), 1)
#define size_int_2(L, H, T)			\
  size_int_wide ((unsigned HOST_WIDE_INT) (L),	\
		 (unsigned HOST_WIDE_INT) (H), (T))

extern tree round_up			PROTO((tree, int));
extern tree get_pending_sizes		PROTO((void));
extern void put_pending_sizes		PROTO((tree));

/* Type for sizes of data-type.  */

#define BITS_PER_UNIT_LOG \
  ((BITS_PER_UNIT > 1) + (BITS_PER_UNIT > 2) + (BITS_PER_UNIT > 4) \
   + (BITS_PER_UNIT > 8) + (BITS_PER_UNIT > 16) + (BITS_PER_UNIT > 32) \
   + (BITS_PER_UNIT > 64) + (BITS_PER_UNIT > 128) + (BITS_PER_UNIT > 256))

struct sizetype_tab
{
  tree xsizetype, xbitsizetype;
  tree xssizetype, xusizetype;
  tree xsbitsizetype, xubitsizetype;
};

extern struct sizetype_tab sizetype_tab;

#define sizetype sizetype_tab.xsizetype
#define bitsizetype sizetype_tab.xbitsizetype
#define ssizetype sizetype_tab.xssizetype
#define usizetype sizetype_tab.xusizetype
#define sbitsizetype sizetype_tab.xsbitsizetype
#define ubitsizetype sizetype_tab.xubitsizetype

/* If nonzero, an upper limit on alignment of structure fields, in bits. */
extern int maximum_field_alignment;

/* If non-zero, the alignment of a bitstring or (power-)set value, in bits. */
extern int set_alignment;

/* Concatenate two lists (chains of TREE_LIST nodes) X and Y
   by making the last node in X point to Y.
   Returns X, except if X is 0 returns Y.  */

extern tree chainon			PROTO((tree, tree));

/* Make a new TREE_LIST node from specified PURPOSE, VALUE and CHAIN.  */

extern tree tree_cons			PROTO((tree, tree, tree));
extern tree perm_tree_cons		PROTO((tree, tree, tree));
extern tree temp_tree_cons		PROTO((tree, tree, tree));
extern tree saveable_tree_cons		PROTO((tree, tree, tree));
extern tree decl_tree_cons		PROTO((tree, tree, tree));
extern tree expr_tree_cons		PROTO((tree, tree, tree));

/* Return the last tree node in a chain.  */

extern tree tree_last			PROTO((tree));

/* Reverse the order of elements in a chain, and return the new head.  */

extern tree nreverse			PROTO((tree));

/* Returns the length of a chain of nodes
   (number of chain pointers to follow before reaching a null pointer).  */

extern int list_length			PROTO((tree));

/* integer_zerop (tree x) is nonzero if X is an integer constant of value 0 */

extern int integer_zerop		PROTO((tree));

/* integer_onep (tree x) is nonzero if X is an integer constant of value 1 */

extern int integer_onep			PROTO((tree));

/* integer_all_onesp (tree x) is nonzero if X is an integer constant
   all of whose significant bits are 1.  */

extern int integer_all_onesp		PROTO((tree));

/* integer_pow2p (tree x) is nonzero is X is an integer constant with
   exactly one bit 1.  */

extern int integer_pow2p		PROTO((tree));

/* staticp (tree x) is nonzero if X is a reference to data allocated
   at a fixed address in memory.  */

extern int staticp			PROTO((tree));

/* Gets an error if argument X is not an lvalue.
   Also returns 1 if X is an lvalue, 0 if not.  */

extern int lvalue_or_else		PROTO((tree, char *));

/* save_expr (EXP) returns an expression equivalent to EXP
   but it can be used multiple times within context CTX
   and only evaluate EXP once.  */

extern tree save_expr			PROTO((tree));

/* Returns the index of the first non-tree operand for CODE, or the number
   of operands if all are trees.  */

extern int first_rtl_op			PROTO((enum tree_code));

/* unsave_expr (EXP) returns an expression equivalent to EXP but it
   can be used multiple times and will evaluate EXP, in its entirety
   each time.  */

extern tree unsave_expr			PROTO((tree));

/* unsave_expr_now (EXP) resets EXP in place, so that it can be
   expanded again.  */

extern tree unsave_expr_now		PROTO((tree));

/* Return 1 if EXP contains a PLACEHOLDER_EXPR; i.e., if it represents a size
   or offset that depends on a field within a record.

   Note that we only allow such expressions within simple arithmetic
   or a COND_EXPR.  */

extern int contains_placeholder_p	PROTO((tree));

/* Return 1 if EXP contains any expressions that produce cleanups for an
   outer scope to deal with.  Used by fold.  */

extern int has_cleanups			PROTO((tree));

/* Given a tree EXP, a FIELD_DECL F, and a replacement value R,
   return a tree with all occurrences of references to F in a
   PLACEHOLDER_EXPR replaced by R.   Note that we assume here that EXP
   contains only arithmetic expressions.  */

extern tree substitute_in_expr		PROTO((tree, tree, tree));

/* variable_size (EXP) is like save_expr (EXP) except that it
   is for the special case of something that is part of a
   variable size for a data type.  It makes special arrangements
   to compute the value at the right time when the data type
   belongs to a function parameter.  */

extern tree variable_size		PROTO((tree));

/* stabilize_reference (EXP) returns an reference equivalent to EXP
   but it can be used multiple times
   and only evaluate the subexpressions once.  */

extern tree stabilize_reference		PROTO((tree));

/* Subroutine of stabilize_reference; this is called for subtrees of
   references.  Any expression with side-effects must be put in a SAVE_EXPR
   to ensure that it is only evaluated once.  */

extern tree stabilize_reference_1	PROTO((tree));

/* Return EXP, stripped of any conversions to wider types
   in such a way that the result of converting to type FOR_TYPE
   is the same as if EXP were converted to FOR_TYPE.
   If FOR_TYPE is 0, it signifies EXP's type.  */

extern tree get_unwidened		PROTO((tree, tree));

/* Return OP or a simpler expression for a narrower value
   which can be sign-extended or zero-extended to give back OP.
   Store in *UNSIGNEDP_PTR either 1 if the value should be zero-extended
   or 0 if the value should be sign-extended.  */

extern tree get_narrower		PROTO((tree, int *));

/* Given MODE and UNSIGNEDP, return a suitable type-tree
   with that mode.
   The definition of this resides in language-specific code
   as the repertoire of available types may vary.  */

extern tree type_for_mode		PROTO((enum machine_mode, int));

/* Given PRECISION and UNSIGNEDP, return a suitable type-tree
   for an integer type with at least that precision.
   The definition of this resides in language-specific code
   as the repertoire of available types may vary.  */

extern tree type_for_size		PROTO((unsigned, int));

/* Given an integer type T, return a type like T but unsigned.
   If T is unsigned, the value is T.
   The definition of this resides in language-specific code
   as the repertoire of available types may vary.  */

extern tree unsigned_type		PROTO((tree));

/* Given an integer type T, return a type like T but signed.
   If T is signed, the value is T.
   The definition of this resides in language-specific code
   as the repertoire of available types may vary.  */

extern tree signed_type			PROTO((tree));

/* This function must be defined in the language-specific files.
   expand_expr calls it to build the cleanup-expression for a TARGET_EXPR.
   This is defined in a language-specific file.  */

extern tree maybe_build_cleanup		PROTO((tree));

/* Given an expression EXP that may be a COMPONENT_REF or an ARRAY_REF,
   look for nested component-refs or array-refs at constant positions
   and find the ultimate containing object, which is returned.  */

extern tree get_inner_reference		PROTO((tree, int *, int *, tree *,
					       enum machine_mode *, int *,
					       int *, int *));

/* Return the FUNCTION_DECL which provides this _DECL with its context,
   or zero if none.  */
extern tree decl_function_context 	PROTO((tree));

/* Return the RECORD_TYPE, UNION_TYPE, or QUAL_UNION_TYPE which provides
   this _DECL with its context, or zero if none.  */
extern tree decl_type_context		PROTO((tree));

/* Given the FUNCTION_DECL for the current function,
   return zero if it is ok for this function to be inline.
   Otherwise return a warning message with a single %s
   for the function's name.  */

extern char *function_cannot_inline_p 	PROTO((tree));

/* Return 1 if EXPR is the real constant zero.  */
extern int real_zerop PROTO((tree));

/* Declare commonly used variables for tree structure.  */

/* An integer constant with value 0 */
extern tree integer_zero_node;

/* An integer constant with value 1 */
extern tree integer_one_node;

/* An integer constant with value 0 whose type is sizetype.  */
extern tree size_zero_node;

/* An integer constant with value 1 whose type is sizetype.  */
extern tree size_one_node;

/* A constant of type pointer-to-int and value 0 */
extern tree null_pointer_node;

/* A node of type ERROR_MARK.  */
extern tree error_mark_node;

/* The type node for the void type.  */
extern tree void_type_node;

/* The type node for the ordinary (signed) integer type.  */
extern tree integer_type_node;

/* The type node for the unsigned integer type.  */
extern tree unsigned_type_node;

/* The type node for the ordinary character type.  */
extern tree char_type_node;

/* Points to the name of the input file from which the current input
   being parsed originally came (before it went into cpp).  */
extern char *input_filename;

/* Current line number in input file.  */
extern int lineno;

/* Nonzero for -pedantic switch: warn about anything
   that standard C forbids.  */
extern int pedantic;

/* Nonzero means lvalues are limited to those valid in pedantic ANSI C.
   Zero means allow extended lvalues.  */

extern int pedantic_lvalues;

/* Nonzero means can safely call expand_expr now;
   otherwise layout_type puts variable sizes onto `pending_sizes' instead.  */

extern int immediate_size_expand;

/* Points to the FUNCTION_DECL of the function whose body we are reading. */

extern tree current_function_decl;

/* Nonzero if function being compiled can call setjmp.  */

extern int current_function_calls_setjmp;

/* Nonzero if function being compiled can call longjmp.  */

extern int current_function_calls_longjmp;

/* Nonzero means all ..._TYPE nodes should be allocated permanently.  */

extern int all_types_permanent;

/* Pointer to function to compute the name to use to print a declaration.
   DECL is the declaration in question.
   VERBOSITY determines what information will be printed:
     0: DECL_NAME, demangled as necessary.
     1: and scope information.
     2: and any other information that might be interesting, such as function
        parameter types in C++.  */

extern char *(*decl_printable_name)		PROTO((tree, int));

/* Pointer to function to finish handling an incomplete decl at the
   end of compilation.  */

extern void (*incomplete_decl_finalize_hook)	PROTO((tree));

/* In tree.c */
extern char *perm_calloc			PROTO((int, long));
extern tree get_file_function_name		PROTO((int));
extern tree get_file_function_name_long 	PROTO((char *));
extern tree get_set_constructor_bits		PROTO((tree, char *, int));
extern tree get_set_constructor_bytes		PROTO((tree,
						       unsigned char *, int));
extern int get_alias_set                        PROTO((tree));
extern int new_alias_set			PROTO((void));
extern int (*lang_get_alias_set)                PROTO((tree));

/* In stmt.c */

extern void expand_fixups			PROTO((struct rtx_def *));
extern tree expand_start_stmt_expr		PROTO((void));
extern tree expand_end_stmt_expr		PROTO((tree));
extern void expand_expr_stmt			PROTO((tree));
extern int warn_if_unused_value			PROTO((tree));
extern void expand_decl_init			PROTO((tree));
extern void clear_last_expr			PROTO((void));
extern void expand_label			PROTO((tree));
extern void expand_goto				PROTO((tree));
extern void expand_asm				PROTO((tree));
extern void expand_start_cond			PROTO((tree, int));
extern void expand_end_cond			PROTO((void));
extern void expand_start_else			PROTO((void));
extern void expand_start_elseif			PROTO((tree));
extern struct nesting *expand_start_loop 	PROTO((int));
extern struct nesting *expand_start_loop_continue_elsewhere 	PROTO((int));
extern void expand_loop_continue_here		PROTO((void));
extern void expand_end_loop			PROTO((void));
extern int expand_continue_loop			PROTO((struct nesting *));
extern int expand_exit_loop			PROTO((struct nesting *));
extern int expand_exit_loop_if_false		PROTO((struct nesting *,
						       tree));
extern int expand_exit_something		PROTO((void));

extern void expand_null_return			PROTO((void));
extern void expand_return			PROTO((tree));
extern int optimize_tail_recursion		PROTO((tree, struct rtx_def *));
extern void expand_start_bindings		PROTO((int));
extern void expand_end_bindings			PROTO((tree, int, int));
extern void start_cleanup_deferral		PROTO((void));
extern void end_cleanup_deferral		PROTO((void));
extern void mark_block_as_eh_region		PROTO((void));
extern void mark_block_as_not_eh_region		PROTO((void));
extern int is_eh_region				PROTO((void));
extern int conditional_context			PROTO((void));
extern tree last_cleanup_this_contour		PROTO((void));
extern int expand_dhc_cleanup			PROTO((tree));
extern int expand_dcc_cleanup			PROTO((tree));
extern void expand_start_case			PROTO((int, tree, tree,
						       char *));
extern void expand_end_case			PROTO((tree));
extern int pushcase				PROTO((tree,
						       tree (*) (tree, tree),
						       tree, tree *));
extern int pushcase_range			PROTO((tree, tree,
						       tree (*) (tree, tree),
						       tree, tree *));
extern void using_eh_for_cleanups		PROTO((void));
extern int stmt_loop_nest_empty			PROTO((void));

/* In fold-const.c */

/* Fold constants as much as possible in an expression.
   Returns the simplified expression.
   Acts only on the top level of the expression;
   if the argument itself cannot be simplified, its
   subexpressions are not changed.  */

extern tree fold		PROTO((tree));

extern int force_fit_type	PROTO((tree, int));
extern int add_double		PROTO((HOST_WIDE_INT, HOST_WIDE_INT,
				       HOST_WIDE_INT, HOST_WIDE_INT,
				       HOST_WIDE_INT *, HOST_WIDE_INT *));
extern int neg_double		PROTO((HOST_WIDE_INT, HOST_WIDE_INT,
				       HOST_WIDE_INT *, HOST_WIDE_INT *));
extern int mul_double		PROTO((HOST_WIDE_INT, HOST_WIDE_INT,
				       HOST_WIDE_INT, HOST_WIDE_INT,
				       HOST_WIDE_INT *, HOST_WIDE_INT *));
extern void lshift_double	PROTO((HOST_WIDE_INT, HOST_WIDE_INT,
				       HOST_WIDE_INT, int, HOST_WIDE_INT *,
				       HOST_WIDE_INT *, int));
extern void rshift_double	PROTO((HOST_WIDE_INT, HOST_WIDE_INT,
				       HOST_WIDE_INT, int,
				       HOST_WIDE_INT *, HOST_WIDE_INT *, int));
extern void lrotate_double	PROTO((HOST_WIDE_INT, HOST_WIDE_INT,
				       HOST_WIDE_INT, int, HOST_WIDE_INT *,
				       HOST_WIDE_INT *));
extern void rrotate_double	PROTO((HOST_WIDE_INT, HOST_WIDE_INT,
				       HOST_WIDE_INT, int, HOST_WIDE_INT *,
				       HOST_WIDE_INT *));
extern int operand_equal_p	PROTO((tree, tree, int));
extern tree invert_truthvalue	PROTO((tree));

/* Interface of the DWARF2 unwind info support.  */

/* Decide whether we want to emit frame unwind information for the current
   translation unit.  */

extern int dwarf2out_do_frame		PROTO((void));

/* Generate a new label for the CFI info to refer to.  */

extern char *dwarf2out_cfi_label	PROTO((void));

/* Entry point to update the canonical frame address (CFA).  */

extern void dwarf2out_def_cfa		PROTO((char *, unsigned, long));

/* Add the CFI for saving a register window.  */

extern void dwarf2out_window_save	PROTO((char *));

/* Add a CFI to update the running total of the size of arguments pushed
   onto the stack.  */

extern void dwarf2out_args_size		PROTO((char *, long));

/* Entry point for saving a register to the stack.  */

extern void dwarf2out_reg_save		PROTO((char *, unsigned, long));

/* Entry point for saving the return address in the stack.  */

extern void dwarf2out_return_save	PROTO((char *, long));

/* Entry point for saving the return address in a register.  */

extern void dwarf2out_return_reg	PROTO((char *, unsigned));

/* Output a marker (i.e. a label) for the beginning of a function, before
   the prologue.  */

extern void dwarf2out_begin_prologue	PROTO((void));

/* Output a marker (i.e. a label) for the absolute end of the generated
   code for a function definition.  */

extern void dwarf2out_end_epilogue	PROTO((void));

/* The language front-end must define these functions.  */

/* Function of no arguments for initializing options.  */
extern void lang_init_options			PROTO((void));

/* Function of no arguments for initializing lexical scanning.  */
extern void init_lex				PROTO((void));
/* Function of no arguments for initializing the symbol table.  */
extern void init_decl_processing		PROTO((void));

/* Functions called with no arguments at the beginning and end or processing
   the input source file.  */
extern void lang_init				PROTO((void));
extern void lang_finish				PROTO((void));

/* Function to identify which front-end produced the output file. */
extern char *lang_identify			PROTO((void));

/* Function to replace the DECL_LANG_SPECIFIC field of a DECL with a copy.  */
extern void copy_lang_decl			PROTO((tree));

/* Function called with no arguments to parse and compile the input.  */
extern int yyparse				PROTO((void));
/* Function called with option as argument
   to decode options starting with -f or -W or +.
   It should return nonzero if it handles the option.  */
extern int lang_decode_option			PROTO((int, char **));

/* Functions for processing symbol declarations.  */
/* Function to enter a new lexical scope.
   Takes one argument: always zero when called from outside the front end.  */
extern void pushlevel				PROTO((int));
/* Function to exit a lexical scope.  It returns a BINDING for that scope.
   Takes three arguments:
     KEEP -- nonzero if there were declarations in this scope.
     REVERSE -- reverse the order of decls before returning them.
     FUNCTIONBODY -- nonzero if this level is the body of a function.  */
extern tree poplevel				PROTO((int, int, int));
/* Set the BLOCK node for the current scope level.  */
extern void set_block				PROTO((tree));
/* Function to add a decl to the current scope level.
   Takes one argument, a decl to add.
   Returns that decl, or, if the same symbol is already declared, may
   return a different decl for that name.  */
extern tree pushdecl				PROTO((tree));
/* Function to return the chain of decls so far in the current scope level.  */
extern tree getdecls				PROTO((void));
/* Function to return the chain of structure tags in the current scope level.  */
extern tree gettags				PROTO((void));

extern tree build_range_type PROTO((tree, tree, tree));

/* Call when starting to parse a declaration:
   make expressions in the declaration last the length of the function.
   Returns an argument that should be passed to resume_momentary later.  */
extern int suspend_momentary PROTO((void));

extern int allocation_temporary_p PROTO((void));

/* Call when finished parsing a declaration:
   restore the treatment of node-allocation that was
   in effect before the suspension.
   YES should be the value previously returned by suspend_momentary.  */
extern void resume_momentary PROTO((int));

/* Called after finishing a record, union or enumeral type.  */
extern void rest_of_type_compilation PROTO((tree, int));

/* Save the current set of obstacks, but don't change them.  */
extern void push_obstacks_nochange PROTO((void));

extern void permanent_allocation PROTO((int));

extern void push_momentary PROTO((void));

extern void clear_momentary PROTO((void));

extern void pop_momentary PROTO((void));

extern void end_temporary_allocation PROTO((void));

/* Pop the obstack selection stack.  */
extern void pop_obstacks PROTO((void));

/* In tree.c */
extern int really_constant_p		PROTO ((tree));
extern void push_obstacks		PROTO ((struct obstack *,
						struct obstack *));
extern void pop_momentary_nofree	PROTO ((void));
extern void preserve_momentary		PROTO ((void));
extern void saveable_allocation		PROTO ((void));
extern void temporary_allocation	PROTO ((void));
extern void resume_temporary_allocation	PROTO ((void));
extern tree get_file_function_name	PROTO ((int));
extern void set_identifier_size		PROTO ((int));
extern int int_fits_type_p		PROTO ((tree, tree));
extern int tree_log2			PROTO ((tree));
extern void preserve_initializer	PROTO ((void));
extern void preserve_data		PROTO ((void));
extern int object_permanent_p		PROTO ((tree));
extern int type_precision		PROTO ((tree));
extern int simple_cst_equal		PROTO ((tree, tree));
extern int type_list_equal		PROTO ((tree, tree));
extern int chain_member			PROTO ((tree, tree));
extern int chain_member_purpose		PROTO ((tree, tree));
extern int chain_member_value		PROTO ((tree, tree));
extern tree listify			PROTO ((tree));
extern tree type_hash_lookup		PROTO ((int, tree));
extern void type_hash_add		PROTO ((int, tree));
extern int type_hash_list		PROTO ((tree));
extern int simple_cst_list_equal	PROTO ((tree, tree));
extern void debug_obstack		PROTO ((char *));
extern void rtl_in_current_obstack	PROTO ((void));
extern void rtl_in_saveable_obstack	PROTO ((void));
extern void init_tree_codes		PROTO ((void));
extern void dump_tree_statistics	PROTO ((void));
extern void print_obstack_statistics	PROTO ((char *, struct obstack *));
#ifdef BUFSIZ
extern void print_obstack_name		PROTO ((char *, FILE *, char *));
#endif
extern void expand_function_end		PROTO ((char *, int, int));
extern void expand_function_start	PROTO ((tree, int));
extern int real_onep			PROTO ((tree));
extern int real_twop			PROTO ((tree));
extern void start_identifier_warnings	PROTO ((void));
extern void gcc_obstack_init		PROTO ((struct obstack *));
extern void init_obstacks		PROTO ((void));
extern void obfree			PROTO ((char *));
extern tree tree_check                  PROTO ((tree, enum tree_code, char*, int, int));
extern tree tree_class_check            PROTO ((tree, char, char*, int, int));
extern tree expr_check                  PROTO ((tree, int, char*, int, int));

/* In function.c */
extern void setjmp_protect_args		PROTO ((void));
extern void setjmp_protect		PROTO ((tree));
extern void expand_main_function	PROTO ((void));
extern void mark_varargs		PROTO ((void));
extern void init_function_start		PROTO ((tree, char *, int));
extern void assign_parms		PROTO ((tree, int));
extern void put_var_into_stack		PROTO ((tree));
extern void uninitialized_vars_warning	PROTO ((tree));
extern void setjmp_args_warning		PROTO ((void));
extern void mark_all_temps_used		PROTO ((void));
extern void init_temp_slots		PROTO ((void));
extern void combine_temp_slots		PROTO ((void));
extern void free_temp_slots		PROTO ((void));
extern void pop_temp_slots		PROTO ((void));
extern void push_temp_slots		PROTO ((void));
extern void preserve_temp_slots		PROTO ((struct rtx_def *));
extern int aggregate_value_p		PROTO ((tree));
extern tree reorder_blocks		PROTO ((tree *, tree,
						struct rtx_def *));
extern void free_temps_for_rtl_expr	PROTO ((tree));
extern void instantiate_virtual_regs	PROTO ((tree, struct rtx_def *));
extern int max_parm_reg_num		PROTO ((void));
extern void push_function_context	PROTO ((void));
extern void pop_function_context	PROTO ((void));
extern void push_function_context_to	PROTO ((tree));
extern void pop_function_context_from	PROTO ((tree));

/* In print-rtl.c */
#ifdef BUFSIZ
extern void print_rtl			PROTO ((FILE *, struct rtx_def *));
#endif

/* In print-tree.c */
extern void debug_tree			PROTO ((tree));
#ifdef BUFSIZ
extern void print_node			PROTO ((FILE *, char *, tree, int));
extern void print_node_brief		PROTO ((FILE *, char *, tree, int));
extern void indent_to			PROTO ((FILE *, int));
#endif

/* In expr.c */
extern void emit_queue				PROTO ((void));
extern int apply_args_register_offset		PROTO ((int));
extern struct rtx_def *expand_builtin_return_addr
	PROTO ((enum built_in_function, int, struct rtx_def *));
extern void do_pending_stack_adjust		PROTO ((void));
extern struct rtx_def *expand_assignment	PROTO ((tree, tree, int, int));
extern struct rtx_def *store_expr		PROTO ((tree, struct rtx_def *,
							int));
extern void check_max_integer_computation_mode	PROTO ((tree));

/* In emit-rtl.c */
extern void start_sequence_for_rtl_expr		PROTO ((tree));
extern struct rtx_def *emit_line_note_after	PROTO ((char *, int,
							struct rtx_def *));
extern struct rtx_def *emit_line_note		PROTO ((char *, int));
extern struct rtx_def *emit_line_note_force	PROTO ((char *, int));

/* In c-typeck.c */
extern int mark_addressable		PROTO ((tree));
extern void incomplete_type_error	PROTO ((tree, tree));

/* In c-lang.c */
extern void print_lang_statistics	PROTO ((void));

/* In c-common.c */
extern tree truthvalue_conversion	PROTO ((tree));
extern int min_precision		PROTO ((tree, int));
extern void split_specs_attrs		PROTO ((tree, tree *, tree *));

/* In c-decl.c */
#ifdef BUFSIZ
extern void print_lang_decl		PROTO ((FILE *, tree, int));
extern void print_lang_type		PROTO ((FILE *, tree, int));
extern void print_lang_identifier	PROTO ((FILE *, tree, int));
#endif
extern int global_bindings_p		PROTO ((void));
extern void insert_block		PROTO ((tree));

/* In integrate.c */
extern void save_for_inline_nocopy	PROTO ((tree));
extern void save_for_inline_copying	PROTO ((tree));
extern void set_decl_abstract_flags	PROTO ((tree, int));
extern void output_inline_function	PROTO ((tree));

/* In c-lex.c */
extern void set_yydebug			PROTO ((int));

/* In stor-layout.c */
extern void fixup_signed_type		PROTO ((tree));

/* varasm.c */
extern void make_decl_rtl		PROTO ((tree, char *, int));
extern void make_decl_one_only		PROTO ((tree));
extern int supports_one_only		PROTO ((void));
extern void variable_section		PROTO ((tree, int));

/* In fold-const.c */
extern int div_and_round_double		PROTO ((enum tree_code, int,
						HOST_WIDE_INT, HOST_WIDE_INT,
						HOST_WIDE_INT, HOST_WIDE_INT,
						HOST_WIDE_INT *,
						HOST_WIDE_INT *,
						HOST_WIDE_INT *,
						HOST_WIDE_INT *));

/* In stmt.c */
extern void emit_nop			PROTO ((void));
extern void expand_computed_goto	PROTO ((tree));
extern struct rtx_def *label_rtx	PROTO ((tree));
extern void expand_asm_operands		PROTO ((tree, tree, tree, tree, int,
						char *, int));
extern int any_pending_cleanups		PROTO ((int));
extern void init_stmt			PROTO ((void));
extern void init_stmt_for_function	PROTO ((void));
extern void remember_end_note		PROTO ((tree));
extern int drop_through_at_end_p	PROTO ((void));
extern void expand_start_target_temps	PROTO ((void));
extern void expand_end_target_temps	PROTO ((void));
extern void expand_elseif		PROTO ((tree));
extern void expand_decl			PROTO ((tree));
extern int expand_decl_cleanup		PROTO ((tree, tree));
extern void expand_anon_union_decl	PROTO ((tree, tree, tree));
extern void move_cleanups_up		PROTO ((void));
extern void expand_start_case_dummy	PROTO ((void));
extern void expand_end_case_dummy	PROTO ((void));
extern tree case_index_expr_type	PROTO ((void));
extern HOST_WIDE_INT all_cases_count	PROTO ((tree, int *));
extern void check_for_full_enumeration_handling PROTO ((tree));
extern void declare_nonlocal_label	PROTO ((tree));
#ifdef BUFSIZ
extern void lang_print_xnode 		PROTO ((FILE *, tree, int));
#endif


/* If KIND=='I', return a suitable global initializer (constructor) name.
   If KIND=='D', return a suitable global clean-up (destructor) name.  */
extern tree get_file_function_name PROTO((int));

/* Interface of the DWARF2 unwind info support.  */

/* Decide whether we want to emit frame unwind information for the current
   translation unit.  */

extern int dwarf2out_do_frame		PROTO((void));

/* Generate a new label for the CFI info to refer to.  */

extern char *dwarf2out_cfi_label	PROTO((void));

/* Entry point to update the canonical frame address (CFA).  */

extern void dwarf2out_def_cfa		PROTO((char *, unsigned, long));

/* Add the CFI for saving a register window.  */

extern void dwarf2out_window_save	PROTO((char *));

/* Add a CFI to update the running total of the size of arguments pushed
   onto the stack.  */

extern void dwarf2out_args_size		PROTO((char *, long));

/* Entry point for saving a register to the stack.  */

extern void dwarf2out_reg_save		PROTO((char *, unsigned, long));

/* Entry point for saving the return address in the stack.  */

extern void dwarf2out_return_save	PROTO((char *, long));

/* Entry point for saving the return address in a register.  */

extern void dwarf2out_return_reg	PROTO((char *, unsigned));

/* Output a marker (i.e. a label) for the beginning of a function, before
   the prologue.  */

extern void dwarf2out_begin_prologue	PROTO((void));

/* Output a marker (i.e. a label) for the absolute end of the generated
   code for a function definition.  */

extern void dwarf2out_end_epilogue	PROTO((void));
