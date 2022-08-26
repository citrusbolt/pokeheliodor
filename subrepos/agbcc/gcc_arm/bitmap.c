/* Functions to support general ended bitmaps.
   Copyright (C) 1997, 1998 Free Software Foundation, Inc.

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
#include "flags.h"
#include "obstack.h"
#include "regs.h"
#include "basic-block.h"

/* Obstack to allocate bitmap elements from.  */
static struct obstack bitmap_obstack;
static int bitmap_obstack_init = FALSE;


#ifndef INLINE
#ifndef __GNUC__
#define INLINE
#else
#define INLINE __inline__
#endif
#endif

/* Global data */
bitmap_element bitmap_zero;		/* An element of all zero bits. */
bitmap_element *bitmap_free;		/* Freelist of bitmap elements. */

static void bitmap_element_free		PROTO((bitmap, bitmap_element *));
static bitmap_element *bitmap_element_allocate PROTO((void));
static int bitmap_element_zerop		PROTO((bitmap_element *));
static void bitmap_element_link		PROTO((bitmap, bitmap_element *));
static bitmap_element *bitmap_find_bit	PROTO((bitmap, unsigned int));

/* Free a bitmap element */

static INLINE void
bitmap_element_free (head, elt)
     bitmap head;
     bitmap_element *elt;
{
  bitmap_element *next = elt->next;
  bitmap_element *prev = elt->prev;

  if (prev)
    prev->next = next;

  if (next)
    next->prev = prev;

  if (head->first == elt)
    head->first = next;

  /* Since the first thing we try is to insert before current,
     make current the next entry in preference to the previous.  */
  if (head->current == elt)
    head->current = next != 0 ? next : prev;

  elt->next = bitmap_free;
  bitmap_free = elt;
}

/* Allocate a bitmap element.  The bits are cleared, but nothing else is.  */

static INLINE bitmap_element *
bitmap_element_allocate ()
{
  bitmap_element *element;
#if BITMAP_ELEMENT_WORDS != 2
  int i;
#endif

  if (bitmap_free != 0)
    {
      element = bitmap_free;
      bitmap_free = element->next;
    }
  else
    {
      /* We can't use gcc_obstack_init to initialize the obstack since
	 print-rtl.c now calls bitmap functions, and bitmap is linked
	 into the gen* functions.  */
      if (!bitmap_obstack_init)
	{
	  bitmap_obstack_init = TRUE;

	  /* Let particular systems override the size of a chunk.  */
#ifndef OBSTACK_CHUNK_SIZE
#define OBSTACK_CHUNK_SIZE 0
#endif
	  /* Let them override the alloc and free routines too.  */
#ifndef OBSTACK_CHUNK_ALLOC
#define OBSTACK_CHUNK_ALLOC xmalloc
#endif
#ifndef OBSTACK_CHUNK_FREE
#define OBSTACK_CHUNK_FREE free
#endif

#if !defined(__GNUC__) || (__GNUC__ < 2)
#define __alignof__(type) 0
#endif

	  obstack_specify_allocation (&bitmap_obstack, OBSTACK_CHUNK_SIZE,
				      __alignof__ (bitmap_element),
				      (void *(*) ()) OBSTACK_CHUNK_ALLOC,
				      (void (*) ()) OBSTACK_CHUNK_FREE);
	}

      element = (bitmap_element *) obstack_alloc (&bitmap_obstack,
						  sizeof (bitmap_element));
    }

#if BITMAP_ELEMENT_WORDS == 2
  element->bits[0] = element->bits[1] = 0;
#else
  for (i = 0; i < BITMAP_ELEMENT_WORDS; i++)
    element->bits[i] = 0;
#endif

  return element;
}

/* Return nonzero if all bits in an element are zero.  */

static INLINE int
bitmap_element_zerop (element)
     bitmap_element *element;
{
#if BITMAP_ELEMENT_WORDS == 2
  return (element->bits[0] | element->bits[1]) == 0;
#else
  int i;

  for (i = 0; i < BITMAP_ELEMENT_WORDS; i++)
    if (element->bits[i] != 0)
      return 0;

  return 1;
#endif
}

/* Link the bitmap element into the current bitmap linked list.  */

static INLINE void
bitmap_element_link (head, element)
     bitmap head;
     bitmap_element *element;
{
  unsigned int indx = element->indx;
  bitmap_element *ptr;

  /* If this is the first and only element, set it in.  */
  if (head->first == 0)
    {
      element->next = element->prev = 0;
      head->first = element;
    }

  /* If this index is less than that of the current element, it goes someplace
     before the current element.  */
  else if (indx < head->indx)
    {
      for (ptr = head->current;
	   ptr->prev != 0 && ptr->prev->indx > indx;
	   ptr = ptr->prev)
	;

      if (ptr->prev)
	ptr->prev->next = element;
      else
	head->first = element;

      element->prev = ptr->prev;
      element->next = ptr;
      ptr->prev = element;
    }

  /* Otherwise, it must go someplace after the current element.  */
  else
    {
      for (ptr = head->current;
	   ptr->next != 0 && ptr->next->indx < indx;
	   ptr = ptr->next)
	;

      if (ptr->next)
	ptr->next->prev = element;

      element->next = ptr->next;
      element->prev = ptr;
      ptr->next = element;
    }

  /* Set up so this is the first element searched.  */
  head->current = element;
  head->indx = indx;
}

/* Clear a bitmap by freeing the linked list.  */

INLINE void
bitmap_clear (head)
     bitmap head;
{
  bitmap_element *element, *next;

  for (element = head->first; element != 0; element = next)
    {
      next = element->next;
      element->next = bitmap_free;
      bitmap_free = element;
    }

  head->first = head->current =  0;
}

/* Copy a bitmap to another bitmap */

void
bitmap_copy (to, from)
     bitmap to;
     bitmap from;
{
  bitmap_element *from_ptr, *to_ptr = 0;
#if BITMAP_ELEMENT_WORDS != 2
  int i;
#endif

  bitmap_clear (to);

  /* Copy elements in forward direction one at a time */
  for (from_ptr = from->first; from_ptr; from_ptr = from_ptr->next)
    {
      bitmap_element *to_elt = bitmap_element_allocate ();

      to_elt->indx = from_ptr->indx;

#if BITMAP_ELEMENT_WORDS == 2
      to_elt->bits[0] = from_ptr->bits[0];
      to_elt->bits[1] = from_ptr->bits[1];
#else
      for (i = 0; i < BITMAP_ELEMENT_WORDS; i++)
	to_elt->bits[i] = from_ptr->bits[i];
#endif

      /* Here we have a special case of bitmap_element_link, for the case
	 where we know the links are being entered in sequence.  */
      if (to_ptr == 0)
	{
	  to->first = to->current = to_elt;
	  to->indx = from_ptr->indx;
	  to_elt->next = to_elt->prev = 0;
	}
      else
	{
	  to_elt->prev = to_ptr;
	  to_elt->next = 0;
	  to_ptr->next = to_elt;
	}

      to_ptr = to_elt;
    }
}

/* Find a bitmap element that would hold a bitmap's bit.
   Update the `current' field even if we can't find an element that
   would hold the bitmap's bit to make eventual allocation
   faster.  */

static INLINE bitmap_element *
bitmap_find_bit (head, bit)
     bitmap head;
     unsigned int bit;
{
  bitmap_element *element;
  unsigned HOST_WIDE_INT indx = bit / BITMAP_ELEMENT_ALL_BITS;

  if (head->current == 0)
    return 0;

  if (head->indx > indx)
    for (element = head->current;
	 element->prev != 0 && element->indx > indx;
	 element = element->prev)
      ;

  else
    for (element = head->current;
	 element->next != 0 && element->indx < indx;
	 element = element->next)
      ;

  /* `element' is the nearest to the one we want.  If it's not the one we
     want, the one we want doesn't exist.  */
  head->current = element;
  head->indx = element->indx;
  if (element != 0 && element->indx != indx)
    element = 0;

  return element;
}

/* Clear a single bit in a bitmap.  */

void
bitmap_clear_bit (head, bit)
     bitmap head;
     int bit;
{
  bitmap_element *ptr = bitmap_find_bit (head, bit);

  if (ptr != 0)
    {
      unsigned bit_num  = bit % (unsigned) HOST_BITS_PER_WIDE_INT;
      unsigned word_num = ((bit / (unsigned) HOST_BITS_PER_WIDE_INT)
			   % BITMAP_ELEMENT_WORDS);
      ptr->bits[word_num] &= ~ (((unsigned HOST_WIDE_INT) 1) << bit_num);

      /* If we cleared the entire word, free up the element */
      if (bitmap_element_zerop (ptr))
	bitmap_element_free (head, ptr);
    }
}


/* Set a single bit in a bitmap.  */

void
bitmap_set_bit (head, bit)
     bitmap head;
     int bit;
{
  bitmap_element *ptr = bitmap_find_bit (head, bit);
  unsigned word_num
    = ((bit / (unsigned) HOST_BITS_PER_WIDE_INT) % BITMAP_ELEMENT_WORDS);
  unsigned bit_num  = bit % (unsigned) HOST_BITS_PER_WIDE_INT;
  unsigned HOST_WIDE_INT bit_val = ((unsigned HOST_WIDE_INT) 1) << bit_num;

  if (ptr == 0)
    {
      ptr = bitmap_element_allocate ();
      ptr->indx = bit / BITMAP_ELEMENT_ALL_BITS;
      ptr->bits[word_num] = bit_val;
      bitmap_element_link (head, ptr);
    }
  else
    ptr->bits[word_num] |= bit_val;
}

/* Return whether a bit is set within a bitmap.  */

int
bitmap_bit_p (head, bit)
     bitmap head;
     int bit;
{
  bitmap_element *ptr;
  unsigned bit_num;
  unsigned word_num;

  ptr = bitmap_find_bit (head, bit);
  if (ptr == 0)
    return 0;

  bit_num = bit % (unsigned) HOST_BITS_PER_WIDE_INT;
  word_num
    = ((bit / (unsigned) HOST_BITS_PER_WIDE_INT) % BITMAP_ELEMENT_WORDS);

  return
    (ptr->bits[word_num] & (((unsigned HOST_WIDE_INT) 1) << bit_num)) != 0;
}

/* Store in bitmap TO the result of combining bitmap FROM1 and
   FROM2 using a specific bit manipulation.  */

void
bitmap_operation (to, from1, from2, operation)
     bitmap to;
     bitmap from1;
     bitmap from2;
     enum bitmap_bits operation;
{
  bitmap_element *delete_list = 0;
  bitmap_element *from1_ptr = from1->first;
  bitmap_element *from2_ptr = from2->first;
  unsigned int indx1
    = (from1_ptr) ? from1_ptr->indx : ~ (unsigned HOST_WIDE_INT) 0;
  unsigned int indx2
    = (from2_ptr) ? from2_ptr->indx : ~ (unsigned HOST_WIDE_INT) 0;
  bitmap_element *to_ptr = 0;
  bitmap_element *from1_tmp;
  bitmap_element *from2_tmp;
  unsigned int indx;
#if BITMAP_ELEMENT_WORDS != 2
  int i;
#endif

  /* To simplify things, always create a new list.  If the old list was one
     of the inputs, free it later.  Otherwise, free it now.  */
  if (to == from1 || to == from2)
    {
      delete_list = to->first;
      to->first = to->current = 0;
    }
  else
    bitmap_clear (to);

  while (from1_ptr != 0 || from2_ptr != 0)
    {
      /* Figure out whether we need to substitute zero elements for
	 missing links.  */
      if (indx1 == indx2)
	{
	  indx = indx1;
	  from1_tmp = from1_ptr;
	  from2_tmp = from2_ptr;
	  from1_ptr = from1_ptr->next;
	  indx1 = (from1_ptr) ? from1_ptr->indx : ~ (unsigned HOST_WIDE_INT) 0;
	  from2_ptr = from2_ptr->next;
	  indx2 = (from2_ptr) ? from2_ptr->indx : ~ (unsigned HOST_WIDE_INT) 0;
	}
      else if (indx1 < indx2)
	{
	  indx = indx1;
	  from1_tmp = from1_ptr;
	  from2_tmp = &bitmap_zero;
	  from1_ptr = from1_ptr->next;
	  indx1 = (from1_ptr) ? from1_ptr->indx : ~ (unsigned HOST_WIDE_INT) 0;
	}
      else
	{
	  indx = indx2;
	  from1_tmp = &bitmap_zero;
	  from2_tmp = from2_ptr;
	  from2_ptr = from2_ptr->next;
	  indx2 = (from2_ptr) ? from2_ptr->indx : ~ (unsigned HOST_WIDE_INT) 0;
	}

      if (to_ptr == 0)
	to_ptr = bitmap_element_allocate ();

      /* Do the operation, and if any bits are set, link it into the
	 linked list.  */
      switch (operation)
	{
	default:
	  abort ();

	case BITMAP_AND:
#if BITMAP_ELEMENT_WORDS == 2
	  to_ptr->bits[0] = from1_tmp->bits[0] & from2_tmp->bits[0];
	  to_ptr->bits[1] = from1_tmp->bits[1] & from2_tmp->bits[1];
#else
	  for (i = BITMAP_ELEMENT_WORDS - 1; i >= 0; i--)
	    to_ptr->bits[i] = from1_tmp->bits[i] & from2_tmp->bits[i];
#endif
	  break;

	case BITMAP_AND_COMPL:
#if BITMAP_ELEMENT_WORDS == 2
	  to_ptr->bits[0] = from1_tmp->bits[0] & ~ from2_tmp->bits[0];
	  to_ptr->bits[1] = from1_tmp->bits[1] & ~ from2_tmp->bits[1];
#else
	  for (i = BITMAP_ELEMENT_WORDS - 1; i >= 0; i--)
	    to_ptr->bits[i] = from1_tmp->bits[i] & ~ from2_tmp->bits[i];
#endif
	  break;

	case BITMAP_IOR:
#if BITMAP_ELEMENT_WORDS == 2
	  to_ptr->bits[0] = from1_tmp->bits[0] | from2_tmp->bits[0];
	  to_ptr->bits[1] = from1_tmp->bits[1] | from2_tmp->bits[1];
#else
	  for (i = BITMAP_ELEMENT_WORDS - 1; i >= 0; i--)
	    to_ptr->bits[i] = from1_tmp->bits[i] | from2_tmp->bits[i];
#endif
	  break;
	}

      if (! bitmap_element_zerop (to_ptr))
	{
	  to_ptr->indx = indx;
	  bitmap_element_link (to, to_ptr);
	  to_ptr = 0;
	}
    }

  /* If we have an unallocated element due to the last element being 0,
     release it back to the free pool.  Don't bother calling
     bitmap_element_free since it was never linked into a bitmap.  */
  if (to_ptr != 0)
    {
      to_ptr->next = bitmap_free;
      bitmap_free = to_ptr;
    }

  /* If the output bitmap was one of the inputs, free up its
     elements now that we're done.  */
  for (; delete_list != 0; delete_list = to_ptr)
    {
      to_ptr = delete_list->next;
      delete_list->next = bitmap_free;
      bitmap_free = delete_list;
    }
}

/* Or into bitmap TO bitmap FROM1 and'ed with the complement of
   bitmap FROM2. */

void
bitmap_ior_and_compl (to, from1, from2)
     bitmap to;
     bitmap from1;
     bitmap from2;
{
  bitmap_head tmp;

  tmp.first = tmp.current = 0;

  bitmap_operation (&tmp, from1, from2, BITMAP_AND_COMPL);
  bitmap_operation (to, to, &tmp, BITMAP_IOR);
  bitmap_clear (&tmp);
}

/* Initialize a bitmap header.  */

bitmap
bitmap_initialize (head)
     bitmap head;
{
  head->first = head->current = 0;

  return head;
}

/* Debugging function to print out the contents of a bitmap.  */

void
bitmap_debug_file (file, head)
     FILE *file;
     bitmap head;
{
  bitmap_element *ptr;

  fprintf (file, "\nfirst = ");
  fprintf (file, HOST_PTR_PRINTF, head->first);
  fprintf (file, " current = ");
  fprintf (file, HOST_PTR_PRINTF, head->current);
  fprintf (file, " indx = %u\n", head->indx);

  for (ptr = head->first; ptr; ptr = ptr->next)
    {
      int i, j, col = 26;

      fprintf (file, "\t");
      fprintf (file, HOST_PTR_PRINTF, ptr);
      fprintf (file, " next = ");
      fprintf (file, HOST_PTR_PRINTF, ptr->next);
      fprintf (file, " prev = ");
      fprintf (file, HOST_PTR_PRINTF, ptr->prev);
      fprintf (file, " indx = %u\n\t\tbits = {", ptr->indx);

      for (i = 0; i < BITMAP_ELEMENT_WORDS; i++)
	for (j = 0; j < HOST_BITS_PER_WIDE_INT; j++)
	  if ((ptr->bits[i] & (((unsigned HOST_WIDE_INT) 1) << j)) != 0)
	    {
	      if (col > 70)
		{
		  fprintf (file, "\n\t\t\t");
		  col = 24;
		}

	      fprintf (file, " %u", (ptr->indx * BITMAP_ELEMENT_ALL_BITS
				     + i * HOST_BITS_PER_WIDE_INT + j));
	      col += 4;
	    }

      fprintf (file, " }\n");
    }
}

/* Function to be called from the debugger to print the contents
   of a bitmap.  */

void
debug_bitmap (head)
     bitmap head;
{
  bitmap_debug_file (stdout, head);
}

/* Function to print out the contents of a bitmap.  Unlike bitmap_debug_file,
   it does not print anything but the bits.  */

void
bitmap_print (file, head, prefix, suffix)
     FILE *file;
     bitmap head;
     char *prefix;
     char *suffix;
{
  char *comma = "";
  int i;

  fputs (prefix, file);
  EXECUTE_IF_SET_IN_BITMAP (head, 0, i,
			    {
			      fprintf (file, "%s%d", comma, i);
			      comma = ", ";
			    });
  fputs (suffix, file);
}

/* Release any memory allocated by bitmaps.  */

void
bitmap_release_memory ()
{
  bitmap_free = 0;
  if (bitmap_obstack_init)
    {
      bitmap_obstack_init = FALSE;
      obstack_free (&bitmap_obstack, NULL_PTR);
    }
}
