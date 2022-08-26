/* Definitions for CPP library.
   Copyright (C) 1995, 96-98, 1999 Free Software Foundation, Inc.
   Written by Per Bothner, 1994-95.

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

 In other words, you are welcome to use, share and improve this program.
 You are forbidden to forbid anyone else to use, share and improve
 what you give them.   Help stamp out software-hoarding!  */
#ifndef __GCC_CPPLIB__
#define __GCC_CPPLIB__

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char U_CHAR;

typedef struct cpp_reader cpp_reader;
typedef struct cpp_buffer cpp_buffer;
typedef struct cpp_options cpp_options;
typedef struct hashnode cpp_hashnode;

enum cpp_token {
  CPP_EOF = -1,
  CPP_OTHER = 0,
  CPP_COMMENT = 1,
  CPP_HSPACE,
  CPP_VSPACE, /* newlines and #line directives */
  CPP_NAME,
  CPP_NUMBER,
  CPP_CHAR,
  CPP_STRING,
  CPP_DIRECTIVE,
  CPP_LPAREN,   /* "(" */
  CPP_RPAREN,   /* ")" */
  CPP_LBRACE,   /* "{" */
  CPP_RBRACE,   /* "}" */
  CPP_COMMA,    /* "," */
  CPP_SEMICOLON,/* ";" */
  CPP_3DOTS,    /* "..." */
#if 0
  CPP_ANDAND, /* "&&" */
  CPP_OROR,   /* "||" */
  CPP_LSH,    /* "<<" */
  CPP_RSH,    /* ">>" */
  CPP_EQL,    /* "==" */
  CPP_NEQ,    /* "!=" */
  CPP_LEQ,    /* "<=" */
  CPP_GEQ,    /* ">=" */
  CPP_PLPL,   /* "++" */
  CPP_MINMIN, /* "--" */
#endif
  /* POP_TOKEN is returned when we've popped a cpp_buffer. */
  CPP_POP
};

typedef enum cpp_token (*parse_underflow_t) PARAMS((cpp_reader *));
typedef int (*parse_cleanup_t) PARAMS((cpp_buffer *, cpp_reader *));

/* A parse_marker indicates a previous position,
   which we can backtrack to. */

struct parse_marker {
  cpp_buffer *buf;
  struct parse_marker *next;
  int position;
};

extern void parse_set_mark PARAMS ((struct parse_marker *, cpp_reader *));
extern void parse_clear_mark PARAMS ((struct parse_marker *));
extern void parse_goto_mark PARAMS((struct parse_marker *, cpp_reader *));
extern void parse_move_mark PARAMS((struct parse_marker *, cpp_reader *));

extern int cpp_handle_option PARAMS ((cpp_reader *, int, char **));
extern int cpp_handle_options PARAMS ((cpp_reader *, int, char **));
extern enum cpp_token cpp_get_token PARAMS ((cpp_reader *));
extern void cpp_skip_hspace PARAMS((cpp_reader *));
extern enum cpp_token cpp_get_non_space_token PARAMS ((cpp_reader *));

/* This frees resources used by PFILE. */
extern void cpp_cleanup PARAMS ((cpp_reader *PFILE));

/* If we have a huge buffer, may need to cache more recent counts */
#define CPP_LINE_BASE(BUF) ((BUF)->buf + (BUF)->line_base)

struct cpp_buffer {
  unsigned char *buf;
  unsigned char *cur;
  unsigned char *rlimit; /* end of valid data */
  unsigned char *alimit; /* end of allocated buffer */
  unsigned char *prev;  /* start of current token */

  char *fname;
  /* Filename specified with #line command.  */
  char *nominal_fname;
  /* Actual directory of this file, used only for "" includes */
  struct file_name_list *actual_dir;

  /* Pointer into the include hash table.  Used for include_next and
     to record control macros.
     ->fname is an alias to ->ihash->fname. */
  struct include_hash *ihash;

  long line_base;
  long lineno; /* Line number at CPP_LINE_BASE. */
  long colno; /* Column number at CPP_LINE_BASE. */
  parse_underflow_t underflow;
  parse_cleanup_t cleanup;
  void *data;
  struct parse_marker *marks;
  /* Value of if_stack at start of this file.
     Used to prohibit unmatched #endif (etc) in an include file.  */
  struct if_stack *if_stack;


  /* True if this is a header file included using <FILENAME>.  */
  char system_header_p;
  char seen_eof;

  /* True if buffer contains escape sequences.
     Currently there are three kinds:
     "@-" means following identifier should not be macro-expanded.
     "@ " means a token-separator.  This turns into " " in final output
          if not stringizing and needed to separate tokens; otherwise nothing.
     "@@" means a normal '@'.
     (An '@' inside a string stands for itself and is never an escape.) */
  char has_escapes;
};

struct cpp_pending;  /* Forward declaration - for C++. */
struct file_name_map_list;

/* Maximum nesting of cpp_buffers.  We use a static limit, partly for
   efficiency, and partly to limit runaway recursion.  */
#define CPP_STACK_MAX 200

/* A cpp_reader encapsulates the "state" of a pre-processor run.
   Applying cpp_get_token repeatedly yields a stream of pre-processor
   tokens.  Usually, there is only one cpp_reader object active. */

struct cpp_reader
{
  parse_underflow_t get_token;
  cpp_buffer *buffer;
  cpp_options *opts;

  /* A buffer used for both for cpp_get_token's output, and also internally. */
  unsigned char *token_buffer;
  /* Allocated size of token_buffer.  CPP_RESERVE allocates space.  */
  unsigned int token_buffer_size;
  /* End of the written part of token_buffer. */
  unsigned char *limit;

  /* Error counter for exit code */
  int errors;

  /* Line where a newline was first seen in a string constant.  */
  int multiline_string_line;

  /* Current depth in #include directives that use <...>.  */
  int system_include_depth;

  /* Hash table of other included files.  See cppfiles.c */
#define ALL_INCLUDE_HASHSIZE 71
  struct include_hash *all_include_files[ALL_INCLUDE_HASHSIZE];

  /* Chain of `actual directory' file_name_list entries,
     for "" inclusion. */
  struct file_name_list *actual_dirs;

  /* Current maximum length of directory names in the search path
     for include files.  (Altered as we get more of them.)  */
  unsigned int max_include_len;

  struct if_stack *if_stack;

  /* Nonzero means we are inside an IF during a -pcp run.  In this mode
     macro expansion is done, and preconditions are output for all macro
     uses requiring them. */
  char pcp_inside_if;

  /* Nonzero means we have printed (while error reporting) a list of
     containing files that matches the current status. */
  char input_stack_listing_current;

  /* If non-zero, macros are not expanded. */
  char no_macro_expand;

  /* Print column number in error messages. */
  char show_column;

  /* We're printed a warning recommending against using #import. */
  char import_warning;

  /* If true, character between '<' and '>' are a single (string) token. */
  char parsing_include_directive;

  /* True if escape sequences (as described for has_escapes in
     parse_buffer) should be emitted. */
  char output_escapes;

  /* 0: Have seen non-white-space on this line.
     1: Only seen white space so far on this line.
     2: Only seen white space so far in this file. */
   char only_seen_white;

  /* Nonzero means this file was included with a -imacros or -include
     command line and should not be recorded as an include file.  */

  int no_record_file;

  long lineno;

  struct tm *timebuf;

  /* Buffer of -M output.  */
  char *deps_buffer;

  /* Number of bytes allocated in above.  */
  int deps_allocated_size;

  /* Number of bytes used.  */
  int deps_size;

  /* Number of bytes since the last newline.  */
  int deps_column;

#ifdef __cplusplus
  ~cpp_reader () { cpp_cleanup (this); }
#endif

  cpp_buffer buffer_stack[CPP_STACK_MAX];
};

#define CPP_FATAL_LIMIT 1000
/* True if we have seen a "fatal" error. */
#define CPP_FATAL_ERRORS(READER) ((READER)->errors >= CPP_FATAL_LIMIT)

#define CPP_BUF_PEEK(BUFFER) \
  ((BUFFER)->cur < (BUFFER)->rlimit ? *(BUFFER)->cur : EOF)
#define CPP_BUF_GET(BUFFER) \
  ((BUFFER)->cur < (BUFFER)->rlimit ? *(BUFFER)->cur++ : EOF)
#define CPP_FORWARD(BUFFER, N) ((BUFFER)->cur += (N))

/* Macros for manipulating the token_buffer. */

#define CPP_OUT_BUFFER(PFILE) ((PFILE)->token_buffer)

/* Number of characters currently in PFILE's output buffer. */
#define CPP_WRITTEN(PFILE) ((size_t)((PFILE)->limit - (PFILE)->token_buffer))
#define CPP_PWRITTEN(PFILE) ((PFILE)->limit)

/* Make sure PFILE->token_buffer has space for at least N more characters. */
#define CPP_RESERVE(PFILE, N) \
  (CPP_WRITTEN (PFILE) + (size_t)(N) > (PFILE)->token_buffer_size \
   && (cpp_grow_buffer (PFILE, N), 0))

/* Append string STR (of length N) to PFILE's output buffer.
   Assume there is enough space. */
#define CPP_PUTS_Q(PFILE, STR, N) \
  (bcopy (STR, (PFILE)->limit, (N)), (PFILE)->limit += (N))
/* Append string STR (of length N) to PFILE's output buffer.  Make space. */
#define CPP_PUTS(PFILE, STR, N) CPP_RESERVE(PFILE, N), CPP_PUTS_Q(PFILE, STR,N)
/* Append character CH to PFILE's output buffer.  Assume sufficient space. */
#define CPP_PUTC_Q(PFILE, CH) (*(PFILE)->limit++ = (CH))
/* Append character CH to PFILE's output buffer.  Make space if need be. */
#define CPP_PUTC(PFILE, CH) (CPP_RESERVE (PFILE, 1), CPP_PUTC_Q (PFILE, CH))
/* Make sure PFILE->limit is followed by '\0'. */
#define CPP_NUL_TERMINATE_Q(PFILE) (*(PFILE)->limit = 0)
#define CPP_NUL_TERMINATE(PFILE) (CPP_RESERVE(PFILE, 1), *(PFILE)->limit = 0)
#define CPP_ADJUST_WRITTEN(PFILE,DELTA) ((PFILE)->limit += (DELTA))
#define CPP_SET_WRITTEN(PFILE,N) ((PFILE)->limit = (PFILE)->token_buffer + (N))

#define CPP_OPTIONS(PFILE) ((PFILE)->opts)

#define CPP_BUFFER(PFILE) ((PFILE)->buffer)
#define CPP_PREV_BUFFER(BUFFER) ((BUFFER)+1)
/* The bottom of the buffer stack. */
#define CPP_NULL_BUFFER(PFILE) (&(PFILE)->buffer_stack[CPP_STACK_MAX])

/* Pointed to by cpp_reader.opts. */
struct cpp_options {
  char *in_fname;

  /* Name of output file, for error messages.  */
  char *out_fname;

  struct file_name_map_list *map_list;

  /* Non-0 means -v, so print the full set of include dirs.  */
  char verbose;

  /* Nonzero means use extra default include directories for C++.  */

  char cplusplus;

  /* Nonzero means handle cplusplus style comments */

  char cplusplus_comments;

  /* Nonzero means handle #import, for objective C.  */

  char objc;

  /* Nonzero means this is an assembly file, and allow
     unknown directives, which could be comments.  */

  int lang_asm;

  /* Nonzero means turn NOTREACHED into #pragma NOTREACHED etc */

  char for_lint;

  /* Nonzero means handle CHILL comment syntax
     and output CHILL string delimiter for __DATE___ etc. */

  char chill;

  /* Nonzero means copy comments into the output file.  */

  char put_out_comments;

  /* Nonzero means don't process the ANSI trigraph sequences.  */

  char no_trigraphs;

  /* Nonzero means print the names of included files rather than
     the preprocessed output.  1 means just the #include "...",
     2 means #include <...> as well.  */

  char print_deps;

  /* Nonzero if missing .h files in -M output are assumed to be generated
     files and not errors.  */

  char print_deps_missing_files;

  /* If true, fopen (deps_file, "a") else fopen (deps_file, "w"). */
  char print_deps_append;

  /* Nonzero means print names of header files (-H).  */

  char print_include_names;

  /* Nonzero means try to make failure to fit ANSI C an error.  */

  char pedantic_errors;

  /* Nonzero means don't print warning messages.  -w.  */

  char inhibit_warnings;

  /* Nonzero means warn if slash-star appears in a comment.  */

  char warn_comments;

  /* Nonzero means warn if there are any trigraphs.  */

  char warn_trigraphs;

  /* Nonzero means warn if #import is used.  */

  char warn_import;

  /* Nonzero means warn if a macro argument is (or would be)
     stringified with -traditional.  */

  char warn_stringify;

  /* Nonzero means turn warnings into errors.  */

  char warnings_are_errors;

  /* Nonzero causes output not to be done,
     but directives such as #define that have side effects
     are still obeyed.  */

  char no_output;

  /* Nonzero means we should look for header.gcc files that remap file
     names.  */
  char remap;

  /* Nonzero means don't output line number information.  */

  char no_line_commands;

/* Nonzero means output the text in failing conditionals,
   inside #failed ... #endfailed.  */

  char output_conditionals;

  /* Nonzero means -I- has been seen,
     so don't look for #include "foo" the source-file directory.  */
  char ignore_srcdir;

  /* Zero means dollar signs are punctuation.
     This used to be needed for conformance to the C Standard,
     before the C Standard was corrected.  */
  char dollars_in_ident;

  /* Nonzero means try to imitate old fashioned non-ANSI preprocessor.  */
  char traditional;

  /* Nonzero means warn if undefined identifiers are evaluated in an #if.  */
  char warn_undef;

  /* Nonzero for the 1989 C Standard, including corrigenda and amendments.  */
  char c89;

  /* Nonzero means give all the error messages the ANSI standard requires.  */
  char pedantic;

  char done_initializing;

  /* Search paths for include files.  system_include, after_include are
     only used during option parsing. */
  struct file_name_list *quote_include;	 /* First dir to search for "file" */
  struct file_name_list *bracket_include;/* First dir to search for <file> */
  struct file_name_list *system_include; /* First dir with system headers  */
  struct file_name_list *after_include;  /* Headers to search after system */

  /* Directory prefix that should replace `/usr' in the standard
     include file directories.  */
  char *include_prefix;

  char inhibit_predefs;
  char no_standard_includes;
  char no_standard_cplusplus_includes;

/* dump_only means inhibit output of the preprocessed text
             and instead output the definitions of all user-defined
             macros in a form suitable for use as input to cccp.
   dump_names means pass #define and the macro name through to output.
   dump_definitions means pass the whole definition (plus #define) through
*/

  enum {dump_none = 0, dump_only, dump_names, dump_definitions}
     dump_macros;

/* Nonzero means pass all #define and #undef directives which we actually
   process through to the output stream.  This feature is used primarily
   to allow cc1 to record the #defines and #undefs for the sake of
   debuggers which understand about preprocessor macros, but it may
   also be useful with -E to figure out how symbols are defined, and
   where they are defined.  */
  int debug_output;

  /* Nonzero means pass #include lines through to the output,
     even if they are ifdefed out.  */
  int dump_includes;

  /* Pending -D, -U and -A options, in reverse order. */
  struct cpp_pending *pending;

  /* File name which deps are being written to.
     This is 0 if deps are being written to stdout.  */
  char *deps_file;

  /* Target-name to write with the dependency information.  */
  char *deps_target;
};

#define CPP_TRADITIONAL(PFILE) (CPP_OPTIONS(PFILE)-> traditional)
#define CPP_WARN_UNDEF(PFILE) (CPP_OPTIONS(PFILE)->warn_undef)
#define CPP_C89(PFILE) (CPP_OPTIONS(PFILE)->c89)
#define CPP_PEDANTIC(PFILE) (CPP_OPTIONS (PFILE)->pedantic)
#define CPP_PRINT_DEPS(PFILE) (CPP_OPTIONS (PFILE)->print_deps)

/* List of directories to look for include files in. */
struct file_name_list
{
  struct file_name_list *next;
  struct file_name_list *alloc; /* for the cache of
				   current directory entries */
  char *name;
  unsigned int nlen;
  /* We use these to tell if the directory mentioned here is a duplicate
     of an earlier directory on the search path. */
  ino_t ino;
  dev_t dev;
  /* If the following is nonzero, it is a C-language system include
     directory.  */
  int sysp;
  /* Mapping of file names for this directory.
     Only used on MS-DOS and related platforms. */
  struct file_name_map *name_map;
};
#define ABSOLUTE_PATH ((struct file_name_list *)-1)

/* This structure is used for the table of all includes.  It is
   indexed by the `short name' (the name as it appeared in the
   #include statement) which is stored in *nshort.  */
struct include_hash
{
  struct include_hash *next;
  /* Next file with the same short name but a
     different (partial) pathname). */
  struct include_hash *next_this_file;

  /* Location of the file in the include search path.
     Used for include_next */
  struct file_name_list *foundhere;
  char *name;		/* (partial) pathname of file */
  char *nshort;		/* name of file as referenced in #include */
  char *control_macro;	/* macro, if any, preventing reinclusion - see
			   redundant_include_p */
  char *buf, *limit;	/* for file content cache, not yet implemented */
};
    
/* If a buffer's dir field is SELF_DIR_DUMMY, it means the file was found
   via the same directory as the file that #included it.  */
#define SELF_DIR_DUMMY ((struct file_name_list *) (~0))

    
/* Name under which this program was invoked.  */

extern char *progname;

/* The structure of a node in the hash table.  The hash table
   has entries for all tokens defined by #define commands (type T_MACRO),
   plus some special tokens like __LINE__ (these each have their own
   type, and the appropriate code is run when that type of node is seen.
   It does not contain control words like "#define", which are recognized
   by a separate piece of code. */

/* different flavors of hash nodes --- also used in keyword table */
enum node_type {
 T_DEFINE = 1,	/* the `#define' keyword */
 T_INCLUDE,	/* the `#include' keyword */
 T_INCLUDE_NEXT, /* the `#include_next' keyword */
 T_IMPORT,      /* the `#import' keyword */
 T_IFDEF,	/* the `#ifdef' keyword */
 T_IFNDEF,	/* the `#ifndef' keyword */
 T_IF,		/* the `#if' keyword */
 T_ELSE,	/* `#else' */
 T_PRAGMA,	/* `#pragma' */
 T_ELIF,	/* `#elif' */
 T_UNDEF,	/* `#undef' */
 T_LINE,	/* `#line' */
 T_ERROR,	/* `#error' */
 T_WARNING,	/* `#warning' */
 T_ENDIF,	/* `#endif' */
 T_SCCS,	/* `#sccs', used on system V.  */
 T_IDENT,	/* `#ident', used on system V.  */
 T_ASSERT,	/* `#assert', taken from system V.  */
 T_UNASSERT,	/* `#unassert', taken from system V.  */
 T_SPECLINE,	/* special symbol `__LINE__' */
 T_DATE,	/* `__DATE__' */
 T_FILE,	/* `__FILE__' */
 T_BASE_FILE,	/* `__BASE_FILE__' */
 T_INCLUDE_LEVEL, /* `__INCLUDE_LEVEL__' */
 T_VERSION,	/* `__VERSION__' */
 T_SIZE_TYPE,   /* `__SIZE_TYPE__' */
 T_PTRDIFF_TYPE,   /* `__PTRDIFF_TYPE__' */
 T_WCHAR_TYPE,   /* `__WCHAR_TYPE__' */
 T_USER_LABEL_PREFIX_TYPE, /* `__USER_LABEL_PREFIX__' */
 T_REGISTER_PREFIX_TYPE,   /* `__REGISTER_PREFIX__' */
 T_TIME,	/* `__TIME__' */
 T_CONST,	/* Constant value, used by `__STDC__' */
 T_MACRO,	/* macro defined by `#define' */
 T_DISABLED,	/* macro temporarily turned off for rescan */
 T_SPEC_DEFINED, /* special `defined' macro for use in #if statements */
 T_PCSTRING,	/* precompiled string (hashval is KEYDEF *) */
 T_UNUSED	/* Used for something not defined.  */
 };

/* Structure returned by create_definition */
typedef struct macrodef MACRODEF;
struct macrodef
{
  struct definition *defn;
  unsigned char *symnam;
  int symlen;
};

/* Structure allocated for every #define.  For a simple replacement
   such as
   	#define foo bar ,
   nargs = -1, the `pattern' list is null, and the expansion is just
   the replacement text.  Nargs = 0 means a functionlike macro with no args,
   e.g.,
       #define getchar() getc (stdin) .
   When there are args, the expansion is the replacement text with the
   args squashed out, and the reflist is a list describing how to
   build the output from the input: e.g., "3 chars, then the 1st arg,
   then 9 chars, then the 3rd arg, then 0 chars, then the 2nd arg".
   The chars here come from the expansion.  Whatever is left of the
   expansion after the last arg-occurrence is copied after that arg.
   Note that the reflist can be arbitrarily long---
   its length depends on the number of times the arguments appear in
   the replacement text, not how many args there are.  Example:
   #define f(x) x+x+x+x+x+x+x would have replacement text "++++++" and
   pattern list
     { (0, 1), (1, 1), (1, 1), ..., (1, 1), NULL }
   where (x, y) means (nchars, argno). */

typedef struct definition DEFINITION;
struct definition {
  int nargs;
  int length;			/* length of expansion string */
  int predefined;		/* True if the macro was builtin or */
				/* came from the command line */
  unsigned char *expansion;
  int line;			/* Line number of definition */
  char *file;			/* File of definition */
  char rest_args;		/* Nonzero if last arg. absorbs the rest */
  struct reflist {
    struct reflist *next;
    char stringify;		/* nonzero if this arg was preceded by a
				   # operator. */
    char raw_before;		/* Nonzero if a ## operator before arg. */
    char raw_after;		/* Nonzero if a ## operator after arg. */
    char rest_args;		/* Nonzero if this arg. absorbs the rest */
    int nchars;			/* Number of literal chars to copy before
				   this arg occurrence.  */
    int argno;			/* Number of arg to substitute (origin-0) */
  } *pattern;
  union {
    /* Names of macro args, concatenated in reverse order
       with comma-space between them.
       The only use of this is that we warn on redefinition
       if this differs between the old and new definitions.  */
    unsigned char *argnames;
  } args;
};

extern unsigned char is_idchar[256];
extern unsigned char is_hor_space[256];
extern unsigned char is_space[256];

/* Stack of conditionals currently in progress
   (including both successful and failing conditionals).  */

struct if_stack {
  struct if_stack *next;	/* for chaining to the next stack frame */
  char *fname;		/* copied from input when frame is made */
  int lineno;			/* similarly */
  int if_succeeded;		/* true if a leg of this if-group
				    has been passed through rescan */
  unsigned char *control_macro;	/* For #ifndef at start of file,
				   this is the macro name tested.  */
  enum node_type type;		/* type of last directive seen in this group */
};
typedef struct if_stack IF_STACK_FRAME;

/* Find the largest host integer type and set its size and type.
   Watch out: on some crazy hosts `long' is shorter than `int'.  */

#ifndef HOST_WIDE_INT
#include "machmode.h"
#endif

extern void cpp_buf_line_and_col PARAMS((cpp_buffer *, long *, long *));
extern cpp_buffer* cpp_file_buffer PARAMS((cpp_reader *));
extern void cpp_define PARAMS ((cpp_reader*, unsigned char *));

extern void cpp_error PVPROTO ((cpp_reader *, const char *, ...))
  ATTRIBUTE_PRINTF_2;
extern void cpp_warning PVPROTO ((cpp_reader *, const char *, ...))
  ATTRIBUTE_PRINTF_2;
extern void cpp_pedwarn PVPROTO ((cpp_reader *, const char *, ...))
  ATTRIBUTE_PRINTF_2;
extern void cpp_error_with_line PVPROTO ((cpp_reader *, int, int, const char *, ...))
  ATTRIBUTE_PRINTF_4;
extern void cpp_pedwarn_with_line PVPROTO ((cpp_reader *, int, int, const char *, ...))
  ATTRIBUTE_PRINTF_4;
extern void cpp_pedwarn_with_file_and_line PVPROTO ((cpp_reader *, char *, int, const char *, ...))
  ATTRIBUTE_PRINTF_4;
extern void cpp_message_from_errno PROTO ((cpp_reader *, int, const char *));
extern void cpp_error_from_errno PROTO ((cpp_reader *, const char *));
extern void cpp_perror_with_name PROTO ((cpp_reader *, const char *));
extern void v_cpp_message PROTO ((cpp_reader *, int, const char *, va_list));

extern void cpp_grow_buffer PARAMS ((cpp_reader *, long));
extern HOST_WIDE_INT cpp_parse_escape PARAMS ((cpp_reader *, char **, HOST_WIDE_INT));
extern cpp_buffer *cpp_push_buffer PARAMS ((cpp_reader *,
					    unsigned char *, long));
extern cpp_buffer *cpp_pop_buffer PARAMS ((cpp_reader *));

extern cpp_hashnode *cpp_lookup PARAMS ((cpp_reader *, const unsigned char *,
					 int, int));
extern void cpp_reader_init PARAMS ((cpp_reader *));
extern void cpp_options_init PARAMS ((cpp_options *));
extern int cpp_start_read PARAMS ((cpp_reader *, char *));
extern int cpp_read_check_assertion PARAMS ((cpp_reader *));
extern int scan_decls PARAMS ((cpp_reader *, int, char **));
extern void skip_rest_of_line PARAMS ((cpp_reader *));
extern void cpp_finish PARAMS ((cpp_reader *));

/* From cpperror.c */
extern void cpp_fatal PVPROTO ((cpp_reader *, const char *, ...))
  ATTRIBUTE_PRINTF_2;
extern void cpp_message PVPROTO ((cpp_reader *, int, const char *, ...))
  ATTRIBUTE_PRINTF_3;
extern void cpp_pfatal_with_name PROTO ((cpp_reader *, const char *));
extern void cpp_file_line_for_message PROTO ((cpp_reader *, char *, int, int));
extern void cpp_print_containing_files PROTO ((cpp_reader *));

/* In cppfiles.c */
extern void append_include_chain	PROTO ((cpp_reader *,
						struct file_name_list **,
						const char *, int));
extern void merge_include_chains	PROTO ((struct cpp_options *));
extern int find_include_file		PROTO ((cpp_reader *, char *,
						struct file_name_list *,
						struct include_hash **,
						int *));
extern int finclude			PROTO ((cpp_reader *, int,
					        struct include_hash *));
extern void deps_output			PROTO ((cpp_reader *, char *, int));
extern struct include_hash *include_hash PROTO ((cpp_reader *, char *, int));

#ifndef INCLUDE_LEN_FUDGE
#define INCLUDE_LEN_FUDGE 0
#endif

    
#ifdef __cplusplus
}
#endif
#endif /* __GCC_CPPLIB__ */

