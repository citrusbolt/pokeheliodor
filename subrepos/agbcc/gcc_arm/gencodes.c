/* Generate from machine description:

   - some macros CODE_FOR_... giving the insn_code_number value
   for each of the defined standard insn names.
   Copyright (C) 1987, 1991, 1995, 1998, 1999 Free Software Foundation, Inc.

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


#include "hconfig.h"
#include "system.h"
#include "rtl.h"
#include "obstack.h"

static struct obstack obstack;
struct obstack *rtl_obstack = &obstack;

#define obstack_chunk_alloc xmalloc
#define obstack_chunk_free free

static void fatal PVPROTO ((const char *, ...))
  ATTRIBUTE_PRINTF_1 ATTRIBUTE_NORETURN;
void fancy_abort PROTO((void)) ATTRIBUTE_NORETURN;

/* Define this so we can link with print-rtl.o to get debug_rtx function.  */
char **insn_name_ptr = 0;

static int insn_code_number;

static void gen_insn PROTO((rtx));

static void
gen_insn (insn)
     rtx insn;
{
  /* Don't mention instructions whose names are the null string
     or begin with '*'.  They are in the machine description just
     to be recognized.  */
  if (XSTR (insn, 0)[0] != 0 && XSTR (insn, 0)[0] != '*')
    printf ("  CODE_FOR_%s = %d,\n", XSTR (insn, 0),
	    insn_code_number);
}

PTR
xmalloc (size)
  size_t size;
{
  register PTR val = (PTR) malloc (size);

  if (val == 0)
    fatal ("virtual memory exhausted");
  return val;
}

PTR
xrealloc (old, size)
  PTR old;
  size_t size;
{
  register PTR ptr;
  if (old)
    ptr = (PTR) realloc (old, size);
  else
    ptr = (PTR) malloc (size);
  if (!ptr)
    fatal ("virtual memory exhausted");
  return ptr;
}

static void
fatal VPROTO ((const char *format, ...))
{
#ifndef ANSI_PROTOTYPES
  const char *format;
#endif
  va_list ap;

  VA_START (ap, format);

#ifndef ANSI_PROTOTYPES
  format = va_arg (ap, const char *);
#endif

  fprintf (stderr, "gencodes: ");
  vfprintf (stderr, format, ap);
  va_end (ap);
  fprintf (stderr, "\n");
  exit (FATAL_EXIT_CODE);
}

/* More 'friendly' abort that prints the line and file.
   config.h can #define abort fancy_abort if you like that sort of thing.  */

void
fancy_abort ()
{
  fatal ("Internal gcc abort.");
}

int
main (argc, argv)
     int argc;
     char **argv;
{
  rtx desc;
  FILE *infile;
  register int c;

  obstack_init (rtl_obstack);

  if (argc <= 1)
    fatal ("No input file name.");

  infile = fopen (argv[1], "r");
  if (infile == 0)
    {
      perror (argv[1]);
      exit (FATAL_EXIT_CODE);
    }

  init_rtl ();

  printf ("/* Generated automatically by the program `gencodes'\n\
from the machine description file `md'.  */\n\n");

  printf ("#ifndef MAX_INSN_CODE\n\n");

  /* Read the machine description.  */

  insn_code_number = 0;
  printf ("enum insn_code {\n");

  while (1)
    {
      c = read_skip_spaces (infile);
      if (c == EOF)
	break;
      ungetc (c, infile);

      desc = read_rtx (infile);
      if (GET_CODE (desc) == DEFINE_INSN || GET_CODE (desc) == DEFINE_EXPAND)
	{
	  gen_insn (desc);
	  insn_code_number++;
	}
      if (GET_CODE (desc) == DEFINE_PEEPHOLE
	  || GET_CODE (desc) == DEFINE_SPLIT)
	{
	  insn_code_number++;
	}
    }

  printf ("  CODE_FOR_nothing };\n");

  printf ("\n#define MAX_INSN_CODE ((int) CODE_FOR_nothing)\n");

  printf ("#endif /* MAX_INSN_CODE */\n");

  fflush (stdout);
  exit (ferror (stdout) != 0 ? FATAL_EXIT_CODE : SUCCESS_EXIT_CODE);
  /* NOTREACHED */
  return 0;
}
