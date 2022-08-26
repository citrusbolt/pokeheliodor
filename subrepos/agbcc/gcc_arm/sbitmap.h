/* Simple bitmaps.
   Copyright (C) 1999 Free Software Foundation, Inc.

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

/* It's not clear yet whether using bitmap.[ch] will be a win.
   It should be straightforward to convert so for now we keep things simple
   while more important issues are dealt with.  */

#define SBITMAP_ELT_BITS HOST_BITS_PER_WIDE_INT
#define SBITMAP_ELT_TYPE unsigned HOST_WIDE_INT

typedef struct simple_bitmap_def {
  /* Number of bits.  */
  int n_bits;
  /* Size in elements.  */
  int size;
  /* Size in bytes.  */
  int bytes;
  /* The elements.  */
  SBITMAP_ELT_TYPE elms[1];
} *sbitmap;

typedef SBITMAP_ELT_TYPE *sbitmap_ptr;

/* Return the set size needed for N elements.  */
#define SBITMAP_SET_SIZE(n) (((n) + SBITMAP_ELT_BITS - 1) / SBITMAP_ELT_BITS)

/* set bit number bitno in the bitmap */
#define SET_BIT(bitmap, bitno)					\
  ((bitmap)->elms [(bitno) / SBITMAP_ELT_BITS]			\
   |= (SBITMAP_ELT_TYPE) 1 << (bitno) % SBITMAP_ELT_BITS)

/* test if bit number bitno in the bitmap is set */
#define TEST_BIT(bitmap, bitno) \
((bitmap)->elms [(bitno) / SBITMAP_ELT_BITS] >> (bitno) % SBITMAP_ELT_BITS & 1)

/* reset bit number bitno in the bitmap  */
#define RESET_BIT(bitmap, bitno)				\
  ((bitmap)->elms [(bitno) / SBITMAP_ELT_BITS]			\
   &= ~((SBITMAP_ELT_TYPE) 1 << (bitno) % SBITMAP_ELT_BITS))

/* Loop over all elements of SBITSET, starting with MIN.  */
#define EXECUTE_IF_SET_IN_SBITMAP(SBITMAP, MIN, N, CODE)		\
do {									\
  unsigned int bit_num_ = (MIN) % (unsigned) SBITMAP_ELT_BITS;		\
  unsigned int word_num_ = (MIN) / (unsigned) SBITMAP_ELT_BITS;		\
  unsigned int size_ = (SBITMAP)->size;					\
  SBITMAP_ELT_TYPE *ptr_ = (SBITMAP)->elms;				\
									\
  while (word_num_ < size_)						\
    {									\
      SBITMAP_ELT_TYPE word_ = ptr_[word_num_];				\
      if (word_ != 0)							\
	{								\
	  for (; bit_num_ < SBITMAP_ELT_BITS; ++bit_num_)		\
	    {								\
	      SBITMAP_ELT_TYPE mask_ = (SBITMAP_ELT_TYPE)1 << bit_num_;	\
	      if ((word_ & mask_) != 0)					\
		{							\
		  word_ &= ~mask_;					\
		  (N) = word_num_ * SBITMAP_ELT_BITS + bit_num_;	\
		  CODE;							\
		  if (word_ == 0)					\
		    break;						\
		}							\
	    }								\
	}								\
      bit_num_ = 0;							\
      word_num_++;							\
   }									\
} while (0)

#define sbitmap_free(map)		free(map)
#define sbitmap_vector_free(vec)	free(vec)

extern void dump_sbitmap PROTO ((FILE *, sbitmap));
extern void dump_sbitmap_vector PROTO ((FILE *, char *, char *,
					sbitmap *, int));

extern sbitmap sbitmap_alloc PROTO ((int));
extern sbitmap *sbitmap_vector_alloc PROTO ((int, int));

extern void sbitmap_copy PROTO ((sbitmap, sbitmap));
extern void sbitmap_zero PROTO ((sbitmap));
extern void sbitmap_ones PROTO ((sbitmap));
extern void sbitmap_vector_zero PROTO ((sbitmap *, int));
extern void sbitmap_vector_ones PROTO ((sbitmap *, int));

extern int sbitmap_union_of_diff PROTO ((sbitmap, sbitmap, sbitmap, sbitmap));
extern void sbitmap_difference PROTO ((sbitmap, sbitmap, sbitmap));
extern void sbitmap_not PROTO ((sbitmap, sbitmap));
extern int sbitmap_a_or_b_and_c PROTO ((sbitmap, sbitmap, sbitmap, sbitmap));
extern int sbitmap_a_and_b_or_c PROTO ((sbitmap, sbitmap, sbitmap, sbitmap));
extern int sbitmap_a_and_b PROTO ((sbitmap, sbitmap, sbitmap));
extern int sbitmap_a_or_b PROTO ((sbitmap, sbitmap, sbitmap));

struct int_list;
extern void sbitmap_intersect_of_predsucc PROTO ((sbitmap, sbitmap *,
						  int, struct int_list **));
#define sbitmap_intersect_of_predecessors  sbitmap_intersect_of_predsucc
#define sbitmap_intersect_of_successors    sbitmap_intersect_of_predsucc

extern void sbitmap_union_of_predsucc PROTO ((sbitmap, sbitmap *, int,
					      struct int_list **));
#define sbitmap_union_of_predecessors  sbitmap_union_of_predsucc
#define sbitmap_union_of_successors    sbitmap_union_of_predsucc
