/* Definitions of target machine for GNU compiler.
   ARM Linux-based GNU systems version.
   Copyright (C) 1997, 1998 Free Software Foundation, Inc.
   Contributed by Russell King  <rmk92@ecs.soton.ac.uk>.

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
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/*
 * We are using GAS, so stabs should work.
 */

#ifndef DBX_DEBUGGING_INFO
#define DBX_DEBUGGING_INFO 1
#endif

/*
 * This is how we tell the assembler that a symbol is weak.  GAS always
 * supports weak symbols.
 */

#define ASM_WEAKEN_LABEL(FILE,NAME) \
  do { fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME); \
       fputc ('\n', FILE); } while (0)

/* This is used in ASM_FILE_START */
#undef  ARM_OS_NAME
#define ARM_OS_NAME "Linux"

/* Unsigned chars produces much better code than signed.  */
#define DEFAULT_SIGNED_CHAR 0

#undef  SUBTARGET_CPP_SPEC
#define SUBTARGET_CPP_SPEC  "%{posix:-D_POSIX_SOURCE} %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__}"

#undef  SIZE_TYPE
#define SIZE_TYPE "unsigned int"

#undef  PTRDIFF_TYPE
#define PTRDIFF_TYPE "int"

#undef  WCHAR_TYPE
#define WCHAR_TYPE "long int"

#undef  WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE BITS_PER_WORD

#if 0		/* not yet */

/* Clear the instruction cache from `beg' to `end'.  This makes an
   inline system call to SYS_cacheflush.  The arguments are as
   follows:

	cacheflush (start, end, flags)

*/

#define CLEAR_INSN_CACHE(BEG, END)					\
{									\
  register unsigned long _beg __asm ("a1") = (unsigned long) (BEG);	\
  register unsigned long _end __asm ("a2") = (unsigned long) (END);	\
  register unsigned long _flg __asm ("a3") = 0;				\
  __asm __volatile ("swi 0x9000b8");					\
}

#endif

/* If cross-compiling, don't require stdio.h etc to build libgcc.a.  */
#ifdef CROSS_COMPILE
#ifndef inhibit_libc
#define inhibit_libc
#endif
#endif
