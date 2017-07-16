/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "grammar.y" /* yacc.c:339  */

/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2017, plures
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "grammar.h"
#include "lexer.h"

static char_opt_t none_char = {None, '\0'};
static int64_opt_t none_int64 = {None, 0};

#undef yyerror
#undef yylex

void
yyerror(YYLTYPE *loc, yyscan_t scanner, ndt_t **ast, ndt_context_t *ctx, const char *msg)
{
    (void)scanner;
    (void)ast;

    ndt_err_format(ctx, NDT_ParseError, "%d:%d: %s\n", loc->first_line,
                   loc->first_column, msg);
}

int
yylex(YYSTYPE *val, YYLTYPE *loc, yyscan_t scanner, ndt_context_t *ctx)
{
    return lexfunc(val, loc, scanner, ctx);
}

#line 126 "grammar.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.h".  */
#ifndef YY_YY_GRAMMAR_H_INCLUDED
# define YY_YY_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 61 "grammar.y" /* yacc.c:355  */

  #include "ndtypes.h"
  #include "seq.h"
  #include "parsefuncs.h"
  #define YY_TYPEDEF_YY_SCANNER_T
  typedef void * yyscan_t;

#line 164 "grammar.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ENDMARKER = 0,
    ANY_KIND = 258,
    SCALAR_KIND = 259,
    VOID = 260,
    BOOL = 261,
    SIGNED_KIND = 262,
    INT8 = 263,
    INT16 = 264,
    INT32 = 265,
    INT64 = 266,
    UNSIGNED_KIND = 267,
    UINT8 = 268,
    UINT16 = 269,
    UINT32 = 270,
    UINT64 = 271,
    FLOAT_KIND = 272,
    FLOAT16 = 273,
    FLOAT32 = 274,
    FLOAT64 = 275,
    COMPLEX_KIND = 276,
    COMPLEX32 = 277,
    COMPLEX64 = 278,
    COMPLEX128 = 279,
    CATEGORICAL = 280,
    INTPTR = 281,
    UINTPTR = 282,
    SIZE = 283,
    CHAR = 284,
    STRING = 285,
    FIXED_STRING_KIND = 286,
    FIXED_STRING = 287,
    BYTES = 288,
    FIXED_BYTES_KIND = 289,
    FIXED_BYTES = 290,
    POINTER = 291,
    VAR = 292,
    COMMA = 293,
    COLON = 294,
    LPAREN = 295,
    RPAREN = 296,
    LBRACE = 297,
    RBRACE = 298,
    LBRACK = 299,
    RBRACK = 300,
    STAR = 301,
    ELLIPSIS = 302,
    RARROW = 303,
    EQUAL = 304,
    QUESTIONMARK = 305,
    BAR = 306,
    ERRTOKEN = 307,
    INTEGER = 308,
    FLOATNUMBER = 309,
    STRINGLIT = 310,
    NAME_LOWER = 311,
    NAME_UPPER = 312,
    NAME_OTHER = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 89 "grammar.y" /* yacc.c:355  */

    ndt_t *ndt;
    ndt_field_t *field;
    ndt_field_seq_t *field_seq;
    ndt_memory_t *typed_value;
    ndt_memory_seq_t *typed_value_seq;
    ndt_attr_t *attribute;
    ndt_attr_seq_t *attribute_seq;
    enum ndt_variadic variadic_flag;
    enum ndt_encoding encoding;
    char *string;
    ndt_string_seq_t *string_seq;

#line 250 "grammar.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (yyscan_t scanner, ndt_t **ast, ndt_context_t *ctx);
/* "%code provides" blocks.  */
#line 69 "grammar.y" /* yacc.c:355  */

  #define YY_DECL extern int lexfunc(YYSTYPE *yylval_param, YYLTYPE *yylloc_param, yyscan_t yyscanner, ndt_context_t *ctx)
  extern int lexfunc(YYSTYPE *, YYLTYPE *, yyscan_t, ndt_context_t *);
  void yyerror(YYLTYPE *loc, yyscan_t scanner, ndt_t **ast, ndt_context_t *ctx, const char *msg);

#line 280 "grammar.c" /* yacc.c:355  */

#endif /* !YY_YY_GRAMMAR_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 286 "grammar.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  120
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   553

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   195,   195,   199,   200,   201,   204,   205,   208,   209,
     212,   213,   214,   215,   216,   217,   220,   221,   222,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   236,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   261,
     262,   263,   264,   267,   268,   269,   270,   273,   274,   275,
     278,   279,   280,   284,   285,   286,   289,   290,   293,   296,
     297,   300,   303,   306,   309,   312,   315,   316,   319,   320,
     321,   324,   325,   328,   329,   330,   333,   334,   335,   338,
     339,   342,   343,   346,   347,   348,   351,   352,   355,   356,
     359,   360,   361,   364,   365,   368,   369,   372,   373,   376,
     377,   380,   381,   382,   383,   386,   387,   390,   391,   394,
     395,   398,   400,   402,   404,   406
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "ANY_KIND", "SCALAR_KIND",
  "VOID", "BOOL", "SIGNED_KIND", "INT8", "INT16", "INT32", "INT64",
  "UNSIGNED_KIND", "UINT8", "UINT16", "UINT32", "UINT64", "FLOAT_KIND",
  "FLOAT16", "FLOAT32", "FLOAT64", "COMPLEX_KIND", "COMPLEX32",
  "COMPLEX64", "COMPLEX128", "CATEGORICAL", "INTPTR", "UINTPTR", "SIZE",
  "CHAR", "STRING", "FIXED_STRING_KIND", "FIXED_STRING", "BYTES",
  "FIXED_BYTES_KIND", "FIXED_BYTES", "POINTER", "VAR", "COMMA", "COLON",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "STAR",
  "ELLIPSIS", "RARROW", "EQUAL", "QUESTIONMARK", "BAR", "ERRTOKEN",
  "INTEGER", "FLOATNUMBER", "STRINGLIT", "NAME_LOWER", "NAME_UPPER",
  "NAME_OTHER", "$accept", "input", "datashape", "array", "dimensions",
  "dimensions_nooption", "dimensions_tail", "dtype", "scalar", "signed",
  "unsigned", "ieee_float", "ieee_complex", "alias", "character", "string",
  "fixed_string", "encoding", "bytes", "fixed_bytes", "pointer",
  "categorical", "typed_value_seq", "typed_value", "variadic_flag",
  "comma_variadic_flag", "tuple_type", "tuple_field_seq", "tuple_field",
  "record_type", "record_field_seq", "record_field", "record_field_name",
  "arguments_opt", "attribute_seq", "attribute", "untyped_value_seq",
  "untyped_value", "integer_seq_opt", "integer_seq", "integer_pair_seq",
  "function_type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

#define YYPACT_NINF -197

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-197)))

#define YYTABLE_NINF -102

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     182,  -197,  -197,   -22,   -22,  -197,   -22,   -22,   -22,   -22,
    -197,   -22,   -22,   -22,   -22,  -197,   -22,   -22,   -22,  -197,
     -22,   -22,   -22,    10,   -22,   -22,   -22,    21,  -197,  -197,
      23,   -22,  -197,    47,    49,    62,   246,   -14,   -28,    52,
     468,    75,  -197,     5,   116,   118,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,    80,  -197,  -197,    64,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,    71,  -197,  -197,  -197,    77,    81,  -197,
      64,   182,    82,    87,     9,    99,    26,  -197,    88,   100,
     102,  -197,   104,  -197,   105,  -197,  -197,  -197,   103,   107,
     -21,   -12,   110,   413,  -197,  -197,   413,   358,   413,    97,
    -197,  -197,   182,   101,     8,  -197,   112,   113,   114,    45,
    -197,  -197,   108,    58,    59,   115,   119,    65,    70,   413,
      73,    64,  -197,   302,   120,     1,   121,   182,  -197,    13,
     111,    64,   468,  -197,  -197,  -197,  -197,   101,   122,    72,
    -197,   413,  -197,   -16,    64,  -197,   182,   182,   182,    71,
    -197,  -197,    77,  -197,  -197,  -197,   106,   117,  -197,   123,
     109,  -197,   104,   -27,    30,   -26,  -197,   104,    74,  -197,
    -197,  -197,   124,   126,   101,   -23,  -197,    29,  -197,  -197,
    -197,  -197,    39,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,   128,  -197,  -197,   125,   413,   130,  -197,
      73,   132,  -197,   182,    64,  -197,  -197,    43,  -197,  -197,
     127,  -197,   133,   104,   134,  -197,   -24,    39,  -197,  -197,
     182,   137,   182,  -197,  -197,  -197,   172,  -197,   182,  -197
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    20,   103,   103,    31,   103,   103,   103,   103,
      33,   103,   103,   103,   103,    35,   103,   103,   103,    37,
     103,   103,   103,     0,   103,   103,   103,    66,    68,    42,
       0,   103,    45,     0,     0,   115,    81,    81,     0,     0,
       0,     0,    25,    28,     0,     0,     3,     6,     8,     4,
      21,    32,    34,    36,    38,    39,    40,    41,    43,    44,
      46,    48,    47,    22,    23,    24,     0,    29,    30,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,     0,     0,    72,
       0,     0,     0,     0,    82,    25,    28,   102,    91,     0,
      83,    89,    83,    96,     0,    82,   100,   101,     0,    83,
       0,     0,     0,     0,     9,     5,     0,     0,     0,     0,
       1,     2,     0,     0,     0,   105,     0,     0,     0,     0,
      76,    71,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,    86,    84,     0,    84,     0,     0,    93,    84,
       0,     0,     0,    18,    14,    16,    10,    25,     0,     0,
      11,     0,   121,     0,     0,   104,     0,     0,     0,     0,
      75,    67,     0,    69,    73,    74,     0,     0,   116,     0,
       0,    12,    83,     0,    85,    25,    90,    83,     0,    87,
      85,    97,     0,    98,   100,     0,    94,     0,    17,    26,
      27,    15,     0,   112,   113,   114,   111,   107,   106,    78,
      79,    80,    77,     0,   119,   118,     0,     0,     0,    92,
       0,     0,    88,     0,     0,    95,     7,     0,   109,    70,
       0,    13,     0,    83,     0,   122,     0,     0,   108,   120,
       0,     0,     0,    99,   110,   123,     0,   124,     0,   125
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,     0,  -197,   -34,   -33,  -108,   -38,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,   -15,  -197,  -197,
    -197,  -197,  -197,    -9,   138,   -97,  -197,  -197,    22,  -197,
     -36,  -128,  -197,   522,   -87,    57,  -197,  -196,  -197,  -197,
    -197,  -197
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    44,    98,    46,    47,    48,   154,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   132,    59,    60,
      61,    62,   129,   130,    99,   144,    63,   100,   101,    64,
     102,   103,   104,    67,   124,   125,   227,   207,    93,   137,
     138,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   109,   115,   134,   112,   146,   228,   114,   156,    35,
     160,   164,   150,  -100,   164,   164,    35,   191,    66,    39,
     225,   191,   110,   163,   219,    41,    39,   243,   202,   111,
     159,   181,    41,   105,   118,   119,   111,   203,   204,   205,
     206,   244,   106,   107,    97,   117,   164,   140,   190,   165,
      83,   118,   119,   201,   183,   113,   188,   106,   107,    97,
     190,    87,   195,    88,   197,  -101,   117,   164,   220,   194,
     107,    97,   118,   119,   226,   155,   113,   114,   155,   153,
     155,   237,   153,   169,   153,   218,   170,    90,   238,    91,
     221,   135,   203,   204,   205,   206,   172,   164,   113,   173,
     174,   155,    92,   177,   182,   153,   178,   187,   179,   231,
     164,   180,   164,   200,   198,   222,   120,   158,   121,   114,
     123,   116,   162,   155,   126,   127,   128,   153,   122,   106,
     107,    97,   131,   139,   133,   136,   241,   236,  -100,   141,
     143,   142,   145,   161,   147,   149,   148,   193,   151,   171,
     163,   166,   167,   168,   196,   217,   175,   213,   176,   214,
     212,   189,   192,   199,   230,   186,   209,   210,   211,   229,
     215,   232,   223,   234,     0,   108,   216,   224,   246,   155,
     239,   240,   242,   153,   233,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     248,   208,    36,   235,    37,     0,    38,     0,     0,    39,
       0,     0,    40,     0,     0,    41,     0,     0,    42,    43,
     245,     0,   247,     0,     0,     0,     0,     0,   249,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,     0,    37,     0,
      38,     0,     0,    94,     0,     0,    40,     0,     0,    41,
       0,     0,    95,    96,    97,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,     0,    37,     0,    38,     0,     0,   184,
       0,     0,    40,     0,     0,    41,     0,     0,   185,    96,
      97,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,     0,
      37,     0,    38,     0,     0,    39,     0,     0,    40,     0,
       0,    41,     0,     0,   157,    43,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,     0,    37,     0,     0,     0,     0,
      39,     0,     0,   152,     0,     0,    41,     0,     0,    42,
      43,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,     0,
      37,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,    41,     0,     0,    42,    43,    68,     0,    69,    70,
      71,    72,     0,    73,    74,    75,    76,     0,    77,    78,
      79,     0,    80,    81,    82,     0,    84,    85,    86,     0,
       0,     0,     0,    89
};

static const yytype_int16 yycheck[] =
{
       0,    37,    40,    90,    38,   102,   202,    40,   116,    37,
     118,    38,   109,    39,    38,    38,    37,   145,    40,    47,
      43,   149,    50,    49,    51,    53,    47,    51,    44,    57,
     117,   139,    53,    47,    46,    47,    57,    53,    54,    55,
      56,   237,    56,    57,    58,    40,    38,    38,    47,    41,
      40,    46,    47,   161,   141,    46,   143,    56,    57,    58,
      47,    40,   149,    40,   151,    39,    40,    38,    38,    56,
      57,    58,    46,    47,    45,   113,    46,   110,   116,   113,
     118,    38,   116,    38,   118,   182,    41,    40,    45,    40,
     187,    91,    53,    54,    55,    56,    38,    38,    46,    41,
      41,   139,    40,    38,   140,   139,    41,   143,    38,   217,
      38,    41,    38,    41,   152,    41,     0,   117,     0,   152,
      56,    46,   122,   161,    53,    54,    55,   161,    48,    56,
      57,    58,    55,    46,    53,    53,   233,   224,    39,    51,
      38,    41,    38,    46,    39,    38,    43,   147,    38,    41,
      49,    39,    39,    39,    43,    46,    41,   172,    39,    53,
     169,    41,    41,    41,    39,   143,   166,   167,   168,    41,
      53,    41,    48,    41,    -1,    37,    53,    51,    41,   217,
      53,    48,    48,   217,   220,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      48,   164,    40,   223,    42,    -1,    44,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    -1,    -1,    56,    57,
     240,    -1,   242,    -1,    -1,    -1,    -1,    -1,   248,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    -1,    42,    -1,
      44,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      -1,    -1,    56,    57,    58,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    -1,    -1,    56,    57,
      58,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    -1,    -1,    56,    57,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    50,    -1,    -1,    53,    -1,    -1,    56,
      57,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    57,     4,    -1,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    -1,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    40,    42,    44,    47,
      50,    53,    56,    57,    60,    61,    62,    63,    64,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    77,
      78,    79,    80,    85,    88,   100,    40,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    40,    92,    92,    92,    40,    40,    92,
      40,    40,    40,    97,    47,    56,    57,    58,    61,    83,
      86,    87,    89,    90,    91,    47,    56,    57,    83,    89,
      50,    57,    63,    46,    64,    66,    46,    40,    46,    47,
       0,     0,    48,    56,    93,    94,    53,    54,    55,    81,
      82,    55,    76,    53,    93,    61,    53,    98,    99,    46,
      38,    51,    41,    38,    84,    38,    84,    39,    43,    38,
      84,    38,    50,    63,    65,    66,    65,    56,    61,    93,
      65,    46,    61,    49,    38,    41,    39,    39,    39,    38,
      41,    41,    38,    41,    41,    41,    39,    38,    41,    38,
      41,    65,    89,    93,    47,    56,    87,    89,    93,    41,
      47,    90,    41,    61,    56,    93,    43,    93,    66,    41,
      41,    65,    44,    53,    54,    55,    56,    96,    94,    61,
      61,    61,    82,    76,    53,    53,    53,    46,    84,    51,
      38,    84,    41,    48,    51,    43,    45,    95,    96,    41,
      39,    65,    41,    89,    41,    61,    93,    38,    45,    53,
      48,    84,    48,    51,    96,    61,    41,    61,    48,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      71,    71,    71,    72,    72,    72,    73,    73,    74,    75,
      75,    76,    77,    78,    79,    80,    81,    81,    82,    82,
      82,    83,    83,    84,    84,    84,    85,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    89,    89,    90,    90,
      91,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     5,     1,     2,
       3,     3,     4,     6,     3,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     4,     1,     4,
       6,     1,     2,     4,     4,     4,     1,     3,     3,     3,
       3,     0,     1,     0,     1,     2,     3,     4,     5,     1,
       3,     1,     4,     3,     4,     5,     1,     3,     3,     6,
       1,     1,     1,     0,     3,     1,     3,     3,     5,     1,
       3,     1,     1,     1,     1,     0,     3,     1,     3,     3,
       5,     3,     6,     8,     8,    10
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, scanner, ast, ctx, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, scanner, ast, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, ndt_t **ast, ndt_context_t *ctx)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (ast);
  YYUSE (ctx);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, ndt_t **ast, ndt_context_t *ctx)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, ast, ctx);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t scanner, ndt_t **ast, ndt_context_t *ctx)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , scanner, ast, ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, ast, ctx); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, ndt_t **ast, ndt_context_t *ctx)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (ast);
  YYUSE (ctx);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 53: /* INTEGER  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1430 "grammar.c" /* yacc.c:1257  */
        break;

    case 54: /* FLOATNUMBER  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1436 "grammar.c" /* yacc.c:1257  */
        break;

    case 55: /* STRINGLIT  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1442 "grammar.c" /* yacc.c:1257  */
        break;

    case 56: /* NAME_LOWER  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1448 "grammar.c" /* yacc.c:1257  */
        break;

    case 57: /* NAME_UPPER  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1454 "grammar.c" /* yacc.c:1257  */
        break;

    case 58: /* NAME_OTHER  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1460 "grammar.c" /* yacc.c:1257  */
        break;

    case 60: /* input  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1466 "grammar.c" /* yacc.c:1257  */
        break;

    case 61: /* datashape  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1472 "grammar.c" /* yacc.c:1257  */
        break;

    case 62: /* array  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1478 "grammar.c" /* yacc.c:1257  */
        break;

    case 63: /* dimensions  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1484 "grammar.c" /* yacc.c:1257  */
        break;

    case 64: /* dimensions_nooption  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1490 "grammar.c" /* yacc.c:1257  */
        break;

    case 65: /* dimensions_tail  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1496 "grammar.c" /* yacc.c:1257  */
        break;

    case 66: /* dtype  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1502 "grammar.c" /* yacc.c:1257  */
        break;

    case 67: /* scalar  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1508 "grammar.c" /* yacc.c:1257  */
        break;

    case 68: /* signed  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1514 "grammar.c" /* yacc.c:1257  */
        break;

    case 69: /* unsigned  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1520 "grammar.c" /* yacc.c:1257  */
        break;

    case 70: /* ieee_float  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1526 "grammar.c" /* yacc.c:1257  */
        break;

    case 71: /* ieee_complex  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1532 "grammar.c" /* yacc.c:1257  */
        break;

    case 72: /* alias  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1538 "grammar.c" /* yacc.c:1257  */
        break;

    case 73: /* character  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1544 "grammar.c" /* yacc.c:1257  */
        break;

    case 74: /* string  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1550 "grammar.c" /* yacc.c:1257  */
        break;

    case 75: /* fixed_string  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1556 "grammar.c" /* yacc.c:1257  */
        break;

    case 77: /* bytes  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1562 "grammar.c" /* yacc.c:1257  */
        break;

    case 78: /* fixed_bytes  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1568 "grammar.c" /* yacc.c:1257  */
        break;

    case 79: /* pointer  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1574 "grammar.c" /* yacc.c:1257  */
        break;

    case 80: /* categorical  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1580 "grammar.c" /* yacc.c:1257  */
        break;

    case 81: /* typed_value_seq  */
#line 186 "grammar.y" /* yacc.c:1257  */
      { ndt_memory_seq_del(((*yyvaluep).typed_value_seq)); }
#line 1586 "grammar.c" /* yacc.c:1257  */
        break;

    case 82: /* typed_value  */
#line 185 "grammar.y" /* yacc.c:1257  */
      { ndt_memory_del(((*yyvaluep).typed_value)); }
#line 1592 "grammar.c" /* yacc.c:1257  */
        break;

    case 85: /* tuple_type  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1598 "grammar.c" /* yacc.c:1257  */
        break;

    case 86: /* tuple_field_seq  */
#line 184 "grammar.y" /* yacc.c:1257  */
      { ndt_field_seq_del(((*yyvaluep).field_seq)); }
#line 1604 "grammar.c" /* yacc.c:1257  */
        break;

    case 87: /* tuple_field  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_field_del(((*yyvaluep).field)); }
#line 1610 "grammar.c" /* yacc.c:1257  */
        break;

    case 88: /* record_type  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1616 "grammar.c" /* yacc.c:1257  */
        break;

    case 89: /* record_field_seq  */
#line 184 "grammar.y" /* yacc.c:1257  */
      { ndt_field_seq_del(((*yyvaluep).field_seq)); }
#line 1622 "grammar.c" /* yacc.c:1257  */
        break;

    case 90: /* record_field  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_field_del(((*yyvaluep).field)); }
#line 1628 "grammar.c" /* yacc.c:1257  */
        break;

    case 91: /* record_field_name  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1634 "grammar.c" /* yacc.c:1257  */
        break;

    case 92: /* arguments_opt  */
#line 188 "grammar.y" /* yacc.c:1257  */
      { ndt_attr_seq_del(((*yyvaluep).attribute_seq)); }
#line 1640 "grammar.c" /* yacc.c:1257  */
        break;

    case 93: /* attribute_seq  */
#line 188 "grammar.y" /* yacc.c:1257  */
      { ndt_attr_seq_del(((*yyvaluep).attribute_seq)); }
#line 1646 "grammar.c" /* yacc.c:1257  */
        break;

    case 94: /* attribute  */
#line 187 "grammar.y" /* yacc.c:1257  */
      { ndt_attr_del(((*yyvaluep).attribute)); }
#line 1652 "grammar.c" /* yacc.c:1257  */
        break;

    case 95: /* untyped_value_seq  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_string_seq_del(((*yyvaluep).string_seq)); }
#line 1658 "grammar.c" /* yacc.c:1257  */
        break;

    case 96: /* untyped_value  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1664 "grammar.c" /* yacc.c:1257  */
        break;

    case 97: /* integer_seq_opt  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_string_seq_del(((*yyvaluep).string_seq)); }
#line 1670 "grammar.c" /* yacc.c:1257  */
        break;

    case 98: /* integer_seq  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_string_seq_del(((*yyvaluep).string_seq)); }
#line 1676 "grammar.c" /* yacc.c:1257  */
        break;

    case 99: /* integer_pair_seq  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_string_seq_del(((*yyvaluep).string_seq)); }
#line 1682 "grammar.c" /* yacc.c:1257  */
        break;

    case 100: /* function_type  */
#line 182 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1688 "grammar.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, ndt_t **ast, ndt_context_t *ctx)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 79 "grammar.y" /* yacc.c:1429  */
{
   yylloc.first_line = 1;
   yylloc.first_column = 1;
   yylloc.last_line = 1;
   yylloc.last_column = 1;
}

#line 1804 "grammar.c" /* yacc.c:1429  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner, ctx);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 195 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[-1].ndt);  *ast = (yyval.ndt); YYACCEPT; }
#line 1993 "grammar.c" /* yacc.c:1646  */
    break;

  case 3:
#line 199 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 1999 "grammar.c" /* yacc.c:1646  */
    break;

  case 4:
#line 200 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2005 "grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 201 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_option((yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2011 "grammar.c" /* yacc.c:1646  */
    break;

  case 6:
#line 204 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_array((yyvsp[0].ndt), NULL, none_int64, none_int64, none_char, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2017 "grammar.c" /* yacc.c:1646  */
    break;

  case 7:
#line 205 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_array((yyvsp[-3].ndt), (yyvsp[-1].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2023 "grammar.c" /* yacc.c:1646  */
    break;

  case 8:
#line 208 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2029 "grammar.c" /* yacc.c:1646  */
    break;

  case 9:
#line 209 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_dim_option((yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2035 "grammar.c" /* yacc.c:1646  */
    break;

  case 10:
#line 212 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fixed_dim((yyvsp[-2].string), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2041 "grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 213 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_symbolic_dim((yyvsp[-2].string), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2047 "grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 214 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_var_dim((yyvsp[-2].string_seq), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2053 "grammar.c" /* yacc.c:1646  */
    break;

  case 13:
#line 215 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_var_dim_offsets((yyvsp[-3].string_seq), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2059 "grammar.c" /* yacc.c:1646  */
    break;

  case 14:
#line 216 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_ellipsis_dim(NULL, (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2065 "grammar.c" /* yacc.c:1646  */
    break;

  case 15:
#line 217 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_ellipsis_dim((yyvsp[-3].string), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2071 "grammar.c" /* yacc.c:1646  */
    break;

  case 16:
#line 220 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2077 "grammar.c" /* yacc.c:1646  */
    break;

  case 17:
#line 221 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_item_option((yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2083 "grammar.c" /* yacc.c:1646  */
    break;

  case 18:
#line 222 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2089 "grammar.c" /* yacc.c:1646  */
    break;

  case 19:
#line 225 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_any_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2095 "grammar.c" /* yacc.c:1646  */
    break;

  case 20:
#line 226 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_scalar_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2101 "grammar.c" /* yacc.c:1646  */
    break;

  case 21:
#line 227 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2107 "grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 228 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2113 "grammar.c" /* yacc.c:1646  */
    break;

  case 23:
#line 229 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2119 "grammar.c" /* yacc.c:1646  */
    break;

  case 24:
#line 230 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2125 "grammar.c" /* yacc.c:1646  */
    break;

  case 25:
#line 231 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_nominal((yyvsp[0].string), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2131 "grammar.c" /* yacc.c:1646  */
    break;

  case 26:
#line 232 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_constr((yyvsp[-3].string), (yyvsp[-1].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2137 "grammar.c" /* yacc.c:1646  */
    break;

  case 27:
#line 233 "grammar.y" /* yacc.c:1646  */
    { (void)(yyvsp[-3].string); (void)(yyvsp[-1].attribute_seq); ndt_free((yyvsp[-3].string)); ndt_attr_seq_del((yyvsp[-1].attribute_seq)); (yyval.ndt) = NULL;
                                            ndt_err_format(ctx, NDT_NotImplementedError, "general attributes are not implemented");
                                            YYABORT; }
#line 2145 "grammar.c" /* yacc.c:1646  */
    break;

  case 28:
#line 236 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_typevar((yyvsp[0].string), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2151 "grammar.c" /* yacc.c:1646  */
    break;

  case 29:
#line 239 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Void, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2157 "grammar.c" /* yacc.c:1646  */
    break;

  case 30:
#line 240 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Bool, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2163 "grammar.c" /* yacc.c:1646  */
    break;

  case 31:
#line 241 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_signed_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2169 "grammar.c" /* yacc.c:1646  */
    break;

  case 32:
#line 242 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2175 "grammar.c" /* yacc.c:1646  */
    break;

  case 33:
#line 243 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_unsigned_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2181 "grammar.c" /* yacc.c:1646  */
    break;

  case 34:
#line 244 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2187 "grammar.c" /* yacc.c:1646  */
    break;

  case 35:
#line 245 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_float_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2193 "grammar.c" /* yacc.c:1646  */
    break;

  case 36:
#line 246 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2199 "grammar.c" /* yacc.c:1646  */
    break;

  case 37:
#line 247 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_complex_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2205 "grammar.c" /* yacc.c:1646  */
    break;

  case 38:
#line 248 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2211 "grammar.c" /* yacc.c:1646  */
    break;

  case 39:
#line 249 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2217 "grammar.c" /* yacc.c:1646  */
    break;

  case 40:
#line 250 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2223 "grammar.c" /* yacc.c:1646  */
    break;

  case 41:
#line 251 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2229 "grammar.c" /* yacc.c:1646  */
    break;

  case 42:
#line 252 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_fixed_string_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2235 "grammar.c" /* yacc.c:1646  */
    break;

  case 43:
#line 253 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2241 "grammar.c" /* yacc.c:1646  */
    break;

  case 44:
#line 254 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2247 "grammar.c" /* yacc.c:1646  */
    break;

  case 45:
#line 255 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_fixed_bytes_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2253 "grammar.c" /* yacc.c:1646  */
    break;

  case 46:
#line 256 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2259 "grammar.c" /* yacc.c:1646  */
    break;

  case 47:
#line 257 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2265 "grammar.c" /* yacc.c:1646  */
    break;

  case 48:
#line 258 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2271 "grammar.c" /* yacc.c:1646  */
    break;

  case 49:
#line 261 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Int8, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2277 "grammar.c" /* yacc.c:1646  */
    break;

  case 50:
#line 262 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Int16, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2283 "grammar.c" /* yacc.c:1646  */
    break;

  case 51:
#line 263 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Int32, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2289 "grammar.c" /* yacc.c:1646  */
    break;

  case 52:
#line 264 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Int64, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2295 "grammar.c" /* yacc.c:1646  */
    break;

  case 53:
#line 267 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Uint8, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2301 "grammar.c" /* yacc.c:1646  */
    break;

  case 54:
#line 268 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Uint16, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2307 "grammar.c" /* yacc.c:1646  */
    break;

  case 55:
#line 269 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Uint32, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2313 "grammar.c" /* yacc.c:1646  */
    break;

  case 56:
#line 270 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Uint64, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2319 "grammar.c" /* yacc.c:1646  */
    break;

  case 57:
#line 273 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Float16, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2325 "grammar.c" /* yacc.c:1646  */
    break;

  case 58:
#line 274 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Float32, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2331 "grammar.c" /* yacc.c:1646  */
    break;

  case 59:
#line 275 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Float64, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2337 "grammar.c" /* yacc.c:1646  */
    break;

  case 60:
#line 278 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Complex32, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2343 "grammar.c" /* yacc.c:1646  */
    break;

  case 61:
#line 279 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Complex64, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2349 "grammar.c" /* yacc.c:1646  */
    break;

  case 62:
#line 280 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_primitive(Complex128, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2355 "grammar.c" /* yacc.c:1646  */
    break;

  case 63:
#line 284 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_alias(Intptr, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2361 "grammar.c" /* yacc.c:1646  */
    break;

  case 64:
#line 285 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_alias(Uintptr, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2367 "grammar.c" /* yacc.c:1646  */
    break;

  case 65:
#line 286 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_alias(Size, (yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2373 "grammar.c" /* yacc.c:1646  */
    break;

  case 66:
#line 289 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_char(Utf32, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2379 "grammar.c" /* yacc.c:1646  */
    break;

  case 67:
#line 290 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_char((yyvsp[-1].encoding), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2385 "grammar.c" /* yacc.c:1646  */
    break;

  case 68:
#line 293 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_string(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2391 "grammar.c" /* yacc.c:1646  */
    break;

  case 69:
#line 296 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fixed_string((yyvsp[-1].string), Utf8, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2397 "grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 297 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fixed_string((yyvsp[-3].string), (yyvsp[-1].encoding), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2403 "grammar.c" /* yacc.c:1646  */
    break;

  case 71:
#line 300 "grammar.y" /* yacc.c:1646  */
    { (yyval.encoding) = ndt_encoding_from_string((yyvsp[0].string), ctx); if ((yyval.encoding) == ErrorEncoding) YYABORT; }
#line 2409 "grammar.c" /* yacc.c:1646  */
    break;

  case 72:
#line 303 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_bytes((yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2415 "grammar.c" /* yacc.c:1646  */
    break;

  case 73:
#line 306 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fixed_bytes((yyvsp[-1].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2421 "grammar.c" /* yacc.c:1646  */
    break;

  case 74:
#line 309 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_pointer((yyvsp[-1].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2427 "grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 312 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_categorical((yyvsp[-1].typed_value_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2433 "grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 315 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value_seq) = ndt_memory_seq_new((yyvsp[0].typed_value), ctx); if ((yyval.typed_value_seq) == NULL) YYABORT; }
#line 2439 "grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 316 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value_seq) = ndt_memory_seq_append((yyvsp[-2].typed_value_seq), (yyvsp[0].typed_value), ctx); if ((yyval.typed_value_seq) == NULL) YYABORT; }
#line 2445 "grammar.c" /* yacc.c:1646  */
    break;

  case 78:
#line 319 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value) = ndt_memory_from_number((yyvsp[-2].string), (yyvsp[0].ndt), ctx); if ((yyval.typed_value) == NULL) YYABORT; }
#line 2451 "grammar.c" /* yacc.c:1646  */
    break;

  case 79:
#line 320 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value) = ndt_memory_from_number((yyvsp[-2].string), (yyvsp[0].ndt), ctx); if ((yyval.typed_value) == NULL) YYABORT; }
#line 2457 "grammar.c" /* yacc.c:1646  */
    break;

  case 80:
#line 321 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value) = ndt_memory_from_string((yyvsp[-2].string), (yyvsp[0].ndt), ctx); if ((yyval.typed_value) == NULL) YYABORT; }
#line 2463 "grammar.c" /* yacc.c:1646  */
    break;

  case 81:
#line 324 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Nonvariadic; }
#line 2469 "grammar.c" /* yacc.c:1646  */
    break;

  case 82:
#line 325 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Variadic; }
#line 2475 "grammar.c" /* yacc.c:1646  */
    break;

  case 83:
#line 328 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Nonvariadic; }
#line 2481 "grammar.c" /* yacc.c:1646  */
    break;

  case 84:
#line 329 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Nonvariadic; }
#line 2487 "grammar.c" /* yacc.c:1646  */
    break;

  case 85:
#line 330 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Variadic; }
#line 2493 "grammar.c" /* yacc.c:1646  */
    break;

  case 86:
#line 333 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_tuple((yyvsp[-1].variadic_flag), NULL, NULL, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2499 "grammar.c" /* yacc.c:1646  */
    break;

  case 87:
#line 334 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_tuple((yyvsp[-1].variadic_flag), (yyvsp[-2].field_seq), NULL, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2505 "grammar.c" /* yacc.c:1646  */
    break;

  case 88:
#line 335 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_tuple(Nonvariadic, (yyvsp[-3].field_seq), (yyvsp[-1].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2511 "grammar.c" /* yacc.c:1646  */
    break;

  case 89:
#line 338 "grammar.y" /* yacc.c:1646  */
    { (yyval.field_seq) = ndt_field_seq_new((yyvsp[0].field), ctx); if ((yyval.field_seq) == NULL) YYABORT; }
#line 2517 "grammar.c" /* yacc.c:1646  */
    break;

  case 90:
#line 339 "grammar.y" /* yacc.c:1646  */
    { (yyval.field_seq) = ndt_field_seq_append((yyvsp[-2].field_seq), (yyvsp[0].field), ctx); if ((yyval.field_seq) == NULL) YYABORT; }
#line 2523 "grammar.c" /* yacc.c:1646  */
    break;

  case 91:
#line 342 "grammar.y" /* yacc.c:1646  */
    { (yyval.field) = mk_field(NULL, (yyvsp[0].ndt), NULL, ctx); if ((yyval.field) == NULL) YYABORT; }
#line 2529 "grammar.c" /* yacc.c:1646  */
    break;

  case 92:
#line 343 "grammar.y" /* yacc.c:1646  */
    { (yyval.field) = mk_field(NULL, (yyvsp[-3].ndt), (yyvsp[-1].attribute_seq), ctx); if ((yyval.field) == NULL) YYABORT; }
#line 2535 "grammar.c" /* yacc.c:1646  */
    break;

  case 93:
#line 346 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_record((yyvsp[-1].variadic_flag), NULL, NULL, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2541 "grammar.c" /* yacc.c:1646  */
    break;

  case 94:
#line 347 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_record((yyvsp[-1].variadic_flag), (yyvsp[-2].field_seq), NULL, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2547 "grammar.c" /* yacc.c:1646  */
    break;

  case 95:
#line 348 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_record(Nonvariadic, (yyvsp[-3].field_seq), (yyvsp[-1].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2553 "grammar.c" /* yacc.c:1646  */
    break;

  case 96:
#line 351 "grammar.y" /* yacc.c:1646  */
    { (yyval.field_seq) = ndt_field_seq_new((yyvsp[0].field), ctx); if ((yyval.field_seq) == NULL) YYABORT; }
#line 2559 "grammar.c" /* yacc.c:1646  */
    break;

  case 97:
#line 352 "grammar.y" /* yacc.c:1646  */
    { (yyval.field_seq) = ndt_field_seq_append((yyvsp[-2].field_seq), (yyvsp[0].field), ctx); if ((yyval.field_seq) == NULL) YYABORT; }
#line 2565 "grammar.c" /* yacc.c:1646  */
    break;

  case 98:
#line 355 "grammar.y" /* yacc.c:1646  */
    { (yyval.field) = mk_field((yyvsp[-2].string), (yyvsp[0].ndt), NULL, ctx); if ((yyval.field) == NULL) YYABORT; }
#line 2571 "grammar.c" /* yacc.c:1646  */
    break;

  case 99:
#line 356 "grammar.y" /* yacc.c:1646  */
    { (yyval.field) = mk_field((yyvsp[-5].string), (yyvsp[-3].ndt), (yyvsp[-1].attribute_seq), ctx); if ((yyval.field) == NULL) YYABORT; }
#line 2577 "grammar.c" /* yacc.c:1646  */
    break;

  case 100:
#line 359 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2583 "grammar.c" /* yacc.c:1646  */
    break;

  case 101:
#line 360 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2589 "grammar.c" /* yacc.c:1646  */
    break;

  case 102:
#line 361 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2595 "grammar.c" /* yacc.c:1646  */
    break;

  case 103:
#line 364 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute_seq) = NULL; }
#line 2601 "grammar.c" /* yacc.c:1646  */
    break;

  case 104:
#line 365 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute_seq) = (yyvsp[-1].attribute_seq); if ((yyval.attribute_seq) == NULL) YYABORT; }
#line 2607 "grammar.c" /* yacc.c:1646  */
    break;

  case 105:
#line 368 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute_seq) = ndt_attr_seq_new((yyvsp[0].attribute), ctx); if ((yyval.attribute_seq) == NULL) YYABORT; }
#line 2613 "grammar.c" /* yacc.c:1646  */
    break;

  case 106:
#line 369 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute_seq) = ndt_attr_seq_append((yyvsp[-2].attribute_seq), (yyvsp[0].attribute), ctx); if ((yyval.attribute_seq) == NULL) YYABORT; }
#line 2619 "grammar.c" /* yacc.c:1646  */
    break;

  case 107:
#line 372 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute) = mk_attr((yyvsp[-2].string), (yyvsp[0].string), ctx); if ((yyval.attribute) == NULL) YYABORT; }
#line 2625 "grammar.c" /* yacc.c:1646  */
    break;

  case 108:
#line 373 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute) = mk_attr_from_seq((yyvsp[-4].string), (yyvsp[-1].string_seq), ctx); if ((yyval.attribute) == NULL) YYABORT; }
#line 2631 "grammar.c" /* yacc.c:1646  */
    break;

  case 109:
#line 376 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = ndt_string_seq_new((yyvsp[0].string), ctx); if ((yyval.string_seq) == NULL) YYABORT; }
#line 2637 "grammar.c" /* yacc.c:1646  */
    break;

  case 110:
#line 377 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = ndt_string_seq_append((yyvsp[-2].string_seq), (yyvsp[0].string), ctx); if ((yyval.string_seq) == NULL) YYABORT; }
#line 2643 "grammar.c" /* yacc.c:1646  */
    break;

  case 111:
#line 380 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2649 "grammar.c" /* yacc.c:1646  */
    break;

  case 112:
#line 381 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2655 "grammar.c" /* yacc.c:1646  */
    break;

  case 113:
#line 382 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2661 "grammar.c" /* yacc.c:1646  */
    break;

  case 114:
#line 383 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2667 "grammar.c" /* yacc.c:1646  */
    break;

  case 115:
#line 386 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = NULL; }
#line 2673 "grammar.c" /* yacc.c:1646  */
    break;

  case 116:
#line 387 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = (yyvsp[-1].string_seq); if ((yyval.string_seq) == NULL) YYABORT; }
#line 2679 "grammar.c" /* yacc.c:1646  */
    break;

  case 117:
#line 390 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = ndt_string_seq_new((yyvsp[0].string), ctx); if ((yyval.string_seq) == NULL) YYABORT; }
#line 2685 "grammar.c" /* yacc.c:1646  */
    break;

  case 118:
#line 391 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = ndt_string_seq_append((yyvsp[-2].string_seq), (yyvsp[0].string), ctx); if ((yyval.string_seq) == NULL) YYABORT; }
#line 2691 "grammar.c" /* yacc.c:1646  */
    break;

  case 119:
#line 394 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = ndt_string_pair_seq_new((yyvsp[-2].string), (yyvsp[0].string), ctx); if ((yyval.string_seq) == NULL) YYABORT; }
#line 2697 "grammar.c" /* yacc.c:1646  */
    break;

  case 120:
#line 395 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = ndt_string_pair_seq_append((yyvsp[-4].string_seq), (yyvsp[-2].string), (yyvsp[0].string), ctx); if ((yyval.string_seq) == NULL) YYABORT; }
#line 2703 "grammar.c" /* yacc.c:1646  */
    break;

  case 121:
#line 399 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_function_from_tuple((yyvsp[0].ndt), (yyvsp[-2].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2709 "grammar.c" /* yacc.c:1646  */
    break;

  case 122:
#line 401 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_function((yyvsp[0].ndt), Nonvariadic, NULL, (yyvsp[-3].variadic_flag), (yyvsp[-4].field_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2715 "grammar.c" /* yacc.c:1646  */
    break;

  case 123:
#line 403 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_function((yyvsp[0].ndt), Variadic, NULL, (yyvsp[-3].variadic_flag), (yyvsp[-4].field_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2721 "grammar.c" /* yacc.c:1646  */
    break;

  case 124:
#line 405 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_function((yyvsp[0].ndt), Nonvariadic, (yyvsp[-6].field_seq), (yyvsp[-3].variadic_flag), (yyvsp[-4].field_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2727 "grammar.c" /* yacc.c:1646  */
    break;

  case 125:
#line 407 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_function((yyvsp[0].ndt), Variadic, (yyvsp[-8].field_seq), (yyvsp[-3].variadic_flag), (yyvsp[-4].field_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2733 "grammar.c" /* yacc.c:1646  */
    break;


#line 2737 "grammar.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, ast, ctx, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, scanner, ast, ctx, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, scanner, ast, ctx);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, scanner, ast, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, ast, ctx, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner, ast, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, scanner, ast, ctx);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
