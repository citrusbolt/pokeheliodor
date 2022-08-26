/* Definitions of target machine for GNU compiler.  ARM on semi-hosted platform
   Copyright (C) 1994, 1995, 1996, 1997 Free Software Foundation, Inc.
   Contributed by Richard Earnshaw (richard.earnshaw@armltd.co.uk)

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

/* CYGNUS LOCAL */
/* Note: The definitions LOCAL_LABEL_PREFIX and USER_LABEL_PREFIX here
   *must* match the definitions in bfd/coff-arm.c  */ 
#undef  LOCAL_LABEL_PREFIX
#define LOCAL_LABEL_PREFIX "."
/* #define LOCAL_LABEL_PREFIX "" */
/* #define NO_DOT_IN_LABEL */

#undef USER_LABEL_PREFIX
#define USER_LABEL_PREFIX ""
/* END CYGNUS LOCAL */

/* CYGNUS LOCAL */
#define STARTFILE_SPEC  "%scrt0.o"
/* END CYGNUS LOCAL */

#define LIB_SPEC "-lc"

#define CPP_PREDEFINES \
    "-Darm -D__semi__ -Acpu(arm) -Amachine(arm)"

/* CYGNUS LOCAL */
#define ASM_SPEC "%{mbig-endian:-EB} %{mcpu=*:-m%*} %{march=*:-m%*} \
 %{mapcs-*:-mapcs-%*} %{mthumb-interwork:-mthumb-interwork}"
/* END CYGNUS LOCAL */

#define LINK_SPEC "%{mbig-endian:-EB} -X"

#define TARGET_VERSION fputs (" (ARM/semi-hosted)", stderr);

#define TARGET_DEFAULT ARM_FLAG_APCS_32

#undef CPP_APCS_PC_DEFAULT_SPEC
#define CPP_APCS_PC_DEFAULT_SPEC "-D__APCS_32__"
