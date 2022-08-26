/* This file may have been modified by DJ Delorie (Jan 1991).  If so,
** these modifications are Coyright (C) 1991 DJ Delorie, 24 Kirsten Ave,
** Rochester NH, 03867-2954, USA.
*/

/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that: (1) source distributions retain this entire copyright
 * notice and comment, and (2) distributions including binaries display
 * the following acknowledgement:  ``This product includes software
 * developed by the University of California, Berkeley and its contributors''
 * in the documentation or other materials provided with the distribution
 * and in all advertising materials mentioning features or use of this
 * software. Neither the name of the University nor the names of its
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* _findenv is defined in getenv.c.  */

extern char *_findenv _PARAMS ((const char *, int *));

/*
 * setenv --
 *	Set the value of the environmental variable "name" to be
 *	"value".  If rewrite is set, replace any current value.
 */

int
_DEFUN (setenv, (name, value, rewrite),
	_CONST char *name _AND
	_CONST char *value _AND
	int rewrite)
{
  extern char **environ;
  static int alloced;		/* if allocated space before */
  register char *C;
  int l_value, offset;

  if (*value == '=')		/* no `=' in value */
    ++value;
  l_value = strlen (value);
  if ((C = _findenv (name, &offset)))
    {				/* find if already exists */
      if (!rewrite)
	return 0;
      if (strlen (C) >= l_value)
	{			/* old larger; copy over */
	  while (*C++ = *value++);
	  return 0;
	}
    }
  else
    {				/* create new slot */
      register int cnt;
      register char **P;

      for (P = environ, cnt = 0; *P; ++P, ++cnt);
      if (alloced)
	{			/* just increase size */
	  environ = (char **) realloc ((char *) environ,
				       (size_t) (sizeof (char *) * (cnt + 2)));
	  if (!environ)
	    return -1;
	}
      else
	{			/* get new space */
	  alloced = 1;		/* copy old entries into it */
	  P = (char **) malloc ((size_t) (sizeof (char *) * (cnt + 2)));
	  if (!P)
	    return (-1);
	  bcopy ((char *) environ, (char *) P, cnt * sizeof (char *));
	  environ = P;
	}
      environ[cnt + 1] = NULL;
      offset = cnt;
    }
  for (C = (char *) name; *C && *C != '='; ++C);	/* no `=' in name */
  if (!(environ[offset] =	/* name + `=' + value */
	malloc ((size_t) ((int) (C - name) + l_value + 2))))
    return -1;
  for (C = environ[offset]; (*C = *name++) && *C != '='; ++C);
  for (*C++ = '='; *C++ = *value++;);
  return 0;
}

/*
 * unsetenv(name) --
 *	Delete environmental variable "name".
 */
void
_DEFUN (unsetenv, (name),
        _CONST char *name)
{
  extern char **environ;
  register char **P;
  int offset;

  while (_findenv (name, &offset))	/* if set multiple times */
    for (P = &environ[offset];; ++P)
      if (!(*P = *(P + 1)))
	break;
}
