/* Generate check macros for tree codes.
   Copyright (C) 1998 Free Software Foundation, Inc.

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

#include <stdio.h>

#define DEFTREECODE(SYM, NAME, TYPE, LEN) #SYM,

const char *tree_codes[] =
{
#include "tree.def"
(char*)0
};

int main()
{
    printf ("/* This file is generated using gencheck. Do not edit. */\n");

    for (int i = 0; tree_codes[i]; i++)
    {
        printf("#define %s_CHECK(t)\tTREE_CHECK (t, %s)\n",
               tree_codes[i], tree_codes[i]);
        printf("#define %s_CHECK1(t)\tTREE_CHECK1 (t, %s)\n",
               tree_codes[i], tree_codes[i]);
    }

    return 0;
}
