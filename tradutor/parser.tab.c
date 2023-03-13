/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <ctype.h>
#include "sym.h"

extern int yylineno;
extern int global_scope;
extern VAR *SymTab;

FILE * output;

void ScopeTab(){
	int i;
	for(i = 0; i < global_scope; i++){ 
		fprintf(output, "\t");
	}
}

#define AddVAR(n) SymTab=MakeVAR(n,SymTab)
#define ASSERT(x,y) if((x)) printf("%s on line %d\n",(y),yylineno)

#line 88 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DLET = 258,
    DCONST = 259,
    DVAR = 260,
    DFUNC = 261,
    DAFUNC = 262,
    VSTR = 263,
    VINT = 264,
    VBOOL = 265,
    VFLOAT = 266,
    IDENTIFIER = 267,
    CIF = 268,
    CELSE = 269,
    ASSGNOP = 270,
    EXPGT = 271,
    EXPLT = 272,
    EXPEQ = 273,
    EXPDF = 274,
    NULLCOALESCING = 275,
    LOGOR = 276,
    LOGAND = 277,
    FRETURN = 278,
    FBREAK = 279,
    FCONTINUE = 280,
    SEMICOLON = 281,
    LFOR = 282,
    LOF = 283,
    LIN = 284,
    LWHILE = 285,
    CBLOCK = 286,
    CINLINE = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "parser.y" /* yacc.c:355  */

	char* ystr;

#line 165 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 182 "parser.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

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
      44,    45,    40,    39,    48,    38,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,     2,
      36,    37,    35,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    56,    60,    61,    64,    65,    68,    69,
      70,    71,    72,    73,    76,    77,    82,    83,    86,    86,
      97,    97,   103,   103,   109,   109,   118,   126,   131,   139,
     147,   155,   155,   158,   160,   158,   169,   177,   187,   189,
     187,   196,   196,   205,   206,   209,   210,   211,   213,   211,
     216,   218,   216,   223,   224,   225,   226,   229,   233,   229,
     237,   238,   242,   238,   245,   249,   245,   260,   261,   264,
     265,   268,   271,   276,   277,   278,   279,   280,   283,   285,
     286,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DLET", "DCONST", "DVAR", "DFUNC",
  "DAFUNC", "VSTR", "VINT", "VBOOL", "VFLOAT", "IDENTIFIER", "CIF",
  "CELSE", "ASSGNOP", "EXPGT", "EXPLT", "EXPEQ", "EXPDF", "NULLCOALESCING",
  "LOGOR", "LOGAND", "FRETURN", "FBREAK", "FCONTINUE", "SEMICOLON", "LFOR",
  "LOF", "LIN", "LWHILE", "CBLOCK", "CINLINE", "'?'", "':'", "'>'", "'<'",
  "'='", "'-'", "'+'", "'*'", "'/'", "'['", "']'", "'('", "')'", "'{'",
  "'}'", "','", "$accept", "goal", "program", "semicolon_not", "statement",
  "flow", "loop", "$@1", "$@2", "$@3", "$@4", "declarations", "$@5", "$@6",
  "$@7", "assigns", "anonymFunction", "$@8", "$@9", "$@10",
  "funcParamsNull", "funcParams", "$@11", "$@12", "$@13", "$@14",
  "funcArgsNull", "conditional", "$@15", "$@16", "conditionalElse", "$@17",
  "$@18", "$@19", "$@20", "arr_expression", "arr_values", "arr_index",
  "expression", YY_NULLPTR
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
     285,   286,   287,    63,    58,    62,    60,    61,    45,    43,
      42,    47,    91,    93,    40,    41,   123,   125,    44
};
# endif

#define YYPACT_NINF -86

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-86)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     136,    -6,     0,     2,     8,   -86,   -86,   -86,   -86,    51,
     -17,    92,   -86,   -86,    25,    28,    75,    61,   -86,    63,
     -86,   -86,   -86,   -86,   -86,    49,   -86,   359,    81,    82,
      90,    65,    92,    92,    66,    92,   -40,   359,     5,    92,
     -86,    64,   151,   -86,   -86,   136,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,   -86,   359,    68,    66,    67,   184,
     217,    92,   103,    93,   247,   -86,    92,   -86,    77,    41,
      41,    41,    41,   366,   366,   366,   307,    41,    41,   -23,
     -23,   -86,   -86,   359,    10,   359,   359,   109,   110,   -86,
     -86,    66,    78,    84,    -2,    92,    83,   -86,   -86,    92,
      86,   109,   -86,    16,    80,    91,   -86,    92,   -86,   -86,
     -86,    -9,   333,   -86,   366,   -86,   105,    92,    87,    89,
      85,   359,   136,   106,   108,   126,   136,   109,   147,   112,
     -86,   -86,   -86,   -86,   111,   116,    -8,   113,   117,   120,
     128,   110,   109,   109,   136,   129,   -86,   -86,   131,   -86,
     133,   -86,   -86,   -86,   134,   142,   136,   136,   -86,   -86,
     136,   -86,    17,   -86,   135,   138,   136,   136,   141,   139,
     -86,   -86,   -86,   146,   148,   -86,    92,   136,   -86,   -86,
     277,   -86,   150,   160,   -86,   -86,   136,   -86,   161,   142,
     -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,    73,    75,    74,    76,    77,
       0,    14,    16,    17,     0,     0,     0,     0,     2,     6,
      13,    12,     9,    10,    11,    80,    79,     8,    26,     0,
      27,     0,     0,     0,    53,     0,    77,    15,     0,     0,
      67,     0,    69,     1,     7,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    33,    36,     0,    53,     0,    54,
       0,     0,     0,     0,     0,    68,     0,     5,     0,    85,
      86,    87,    88,    81,    84,    83,     0,    90,    89,    92,
      91,    93,    94,    28,     0,    30,    29,    43,    71,    56,
      78,    53,     0,     0,    26,     0,     0,    70,    72,     0,
       0,    43,    32,    45,    46,     0,    44,     0,    55,    57,
      71,     0,     0,    24,    82,    38,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,    43,     0,     0,
      48,    51,    34,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    22,     0,    25,
       0,    41,    49,    52,     0,    60,     0,     0,    18,    39,
       0,    35,     0,    59,     0,     0,     0,     0,     0,     0,
      61,    21,    23,     0,     0,    42,     0,     0,    19,    40,
       0,    62,     0,     0,    64,    63,     0,    65,     0,    60,
      66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,   -44,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   156,   -86,   -86,   -86,   -82,   -86,   -86,   -86,   -86,
     -38,   -85,   -86,   -86,   -86,   -86,   -42,   -86,   -86,   -86,
     -19,   -86,   -86,   -86,   -86,    76,   -14,   -86,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    45,    19,    20,    21,   176,   166,   167,
     136,    22,    94,    97,   154,    23,   112,   137,   177,   170,
     115,   116,   128,   152,   129,   153,    68,    24,   132,   155,
     173,   187,   193,   196,   198,    25,    41,    26,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    77,    71,   133,    34,    42,    28,    32,    72,     2,
       3,     4,    29,    61,    30,   114,   110,    59,    60,    66,
      31,    65,    42,    69,    70,    99,   121,    35,    74,   114,
     179,    32,    78,    16,   127,    42,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    95,    96,   147,   111,   114,    69,   103,   127,   118,
      42,    43,   107,   180,   -47,    42,    32,   162,   163,    38,
     114,   114,    39,   126,     5,     6,     7,     8,    36,    57,
      58,    59,    60,     5,     6,     7,     8,    36,   143,    44,
      69,    46,   148,    33,   122,    34,    61,    62,   124,   149,
       5,     6,     7,     8,    36,    63,   131,    75,    16,    64,
     164,    98,   100,   139,    67,   104,    42,    16,    40,   105,
     108,   113,   174,   175,   119,   117,   178,   120,   -50,   123,
     125,   142,   183,   184,    16,   140,   130,   141,   146,     1,
       2,     3,     4,   191,     5,     6,     7,     8,     9,    10,
     138,   144,   197,   145,   150,   151,   172,   156,   158,    11,
      12,    13,   157,    14,   159,   160,    15,    47,    48,    49,
      50,    51,    52,    53,   161,   190,   165,   168,    16,   169,
     200,   171,   181,   186,    54,   182,    55,    56,   185,    57,
      58,    59,    60,   188,    73,   189,   194,   134,     0,    76,
      47,    48,    49,    50,    51,    52,    53,   195,   199,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,    55,
      56,     0,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,   101,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,    55,    56,     0,    57,    58,    59,    60,     0,
       0,     0,   102,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,    55,    56,     0,    57,    58,    59,    60,     0,
       0,     0,   106,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,    55,    56,     0,    57,    58,    59,    60,     0,
       0,     0,   192,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,   109,    55,    56,     0,    57,    58,    59,    60,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,    54,     0,    55,    56,
       0,    57,    58,    59,    60,    47,    48,    49,    50,    51,
      52,    53,    47,    48,    49,    50,     0,     0,     0,     0,
       0,     0,    54,     0,    55,    56,     0,    57,    58,    59,
      60,    55,    56,     0,    57,    58,    59,    60
};

static const yytype_int16 yycheck[] =
{
      11,    45,    42,    12,    44,    16,    12,    15,     3,     4,
       5,     6,    12,    15,    12,    97,     6,    40,    41,    33,
      12,    32,    33,    34,    35,    67,    28,    44,    39,   111,
      13,    15,    46,    42,    42,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   135,    44,   137,    67,    71,    42,   101,
      71,     0,    76,    46,    48,    76,    15,   152,   153,    44,
     152,   153,    44,   111,     8,     9,    10,    11,    12,    38,
      39,    40,    41,     8,     9,    10,    11,    12,   132,    26,
     101,    42,   136,    42,   105,    44,    15,    15,   109,   137,
       8,     9,    10,    11,    12,    15,   117,    43,    42,    44,
     154,    43,    45,   127,    48,    12,   127,    42,    43,    26,
      43,    12,   166,   167,    46,    15,   170,    43,    48,    46,
      44,    46,   176,   177,    42,    48,    45,    48,    12,     3,
       4,     5,     6,   187,     8,     9,    10,    11,    12,    13,
      45,    45,   196,    45,     7,    43,    14,    46,    45,    23,
      24,    25,    46,    27,    47,    45,    30,    16,    17,    18,
      19,    20,    21,    22,    46,   186,    47,    46,    42,    46,
     199,    47,    47,    44,    33,    47,    35,    36,    47,    38,
      39,    40,    41,    47,    38,    47,    46,   121,    -1,    48,
      16,    17,    18,    19,    20,    21,    22,    47,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    16,    17,    18,    19,    20,
      21,    22,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    35,    36,    -1,    38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    10,    11,    12,
      13,    23,    24,    25,    27,    30,    42,    50,    51,    53,
      54,    55,    60,    64,    76,    84,    86,    87,    12,    12,
      12,    12,    15,    42,    44,    44,    12,    87,    44,    44,
      43,    85,    87,     0,    26,    52,    42,    16,    17,    18,
      19,    20,    21,    22,    33,    35,    36,    38,    39,    40,
      41,    15,    15,    15,    44,    87,    85,    48,    75,    87,
      87,    42,     3,    60,    87,    43,    48,    51,    85,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    61,    87,    87,    62,    43,    75,
      45,    48,    45,    85,    12,    26,    45,    85,    43,    34,
       6,    44,    65,    12,    64,    69,    70,    15,    75,    46,
      43,    28,    87,    46,    87,    44,    69,    42,    71,    73,
      45,    87,    77,    12,    84,    26,    59,    66,    45,    85,
      48,    48,    46,    51,    45,    45,    12,    64,    51,    69,
       7,    43,    72,    74,    63,    78,    46,    46,    45,    47,
      45,    46,    70,    70,    51,    47,    57,    58,    46,    46,
      68,    47,    14,    79,    51,    51,    56,    67,    51,    13,
      46,    47,    47,    51,    51,    47,    44,    80,    47,    47,
      87,    51,    45,    81,    46,    47,    82,    51,    83,    47,
      79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    56,    55,
      57,    55,    58,    55,    59,    55,    60,    60,    60,    60,
      60,    61,    60,    62,    63,    60,    64,    64,    66,    67,
      65,    68,    65,    69,    69,    70,    70,    71,    72,    70,
      73,    74,    70,    75,    75,    75,    75,    77,    78,    76,
      79,    80,    81,    79,    82,    83,    79,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     0,    12,
       0,    11,     0,    11,     0,     8,     2,     2,     4,     4,
       4,     0,     5,     0,     0,    10,     3,     6,     0,     0,
       9,     0,     8,     0,     1,     1,     1,     0,     0,     5,
       0,     0,     5,     0,     1,     3,     2,     0,     0,    10,
       0,     0,     0,     6,     0,     0,    11,     2,     3,     1,
       3,     4,     4,     1,     1,     1,     1,     1,     4,     1,
       1,     3,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 55 "parser.y" /* yacc.c:1646  */
    { global_scope = 0; }
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 68 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[0].ystr) != ""){ ScopeTab(); fprintf(output, "%s\n", (yyvsp[0].ystr));} }
#line 1444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 69 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[0].ystr) != ""){ ScopeTab(); fprintf(output, "%s\n", (yyvsp[0].ystr));}}
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 70 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].ystr) != ""){ ScopeTab(); fprintf(output, "%s\n", (yyvsp[0].ystr));}}
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 71 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr)=""; }
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 72 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr)="";}
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 73 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].ystr) != ""){ ScopeTab(); fprintf(output, "%s\n", (yyvsp[0].ystr));}}
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 76 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr)="return"; }
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 77 "parser.y" /* yacc.c:1646  */
    {
	char t[1000]; 
	sprintf(t, "return %s", (yyvsp[0].ystr)); 
	(yyval.ystr)=stringpool(t);
}
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr)="break";}
#line 1496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr)="continue";}
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 86 "parser.y" /* yacc.c:1646  */
    {
	ScopeTab();
	fprintf(output, "%s\n", (yyvsp[-6].ystr));
	ScopeTab();
	fprintf(output, "while %s:\n", (yyvsp[-4].ystr)); 
	global_scope += 1;
}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 92 "parser.y" /* yacc.c:1646  */
    {
	ScopeTab();
	fprintf(output, "%s\n", (yyvsp[-5].ystr)); 
	global_scope -= 1;
}
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 97 "parser.y" /* yacc.c:1646  */
    {
	fprintf(output, "for %s in %s:\n", (yyvsp[-4].ystr), (yyvsp[-2].ystr)); 
	global_scope += 1;
}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "parser.y" /* yacc.c:1646  */
    {
	global_scope -= 1;
}
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 103 "parser.y" /* yacc.c:1646  */
    {
	fprintf(output, "for %s in %s:\n", (yyvsp[-4].ystr), (yyvsp[-2].ystr)); 
	global_scope += 1;
}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 106 "parser.y" /* yacc.c:1646  */
    {
	global_scope -= 1;
}
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 109 "parser.y" /* yacc.c:1646  */
    {
	fprintf(output, "while %s:\n", (yyvsp[-2].ystr)); 
	global_scope += 1;
}
#line 1567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 112 "parser.y" /* yacc.c:1646  */
    {
	ScopeTab();
	global_scope -= 1;
}
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 118 "parser.y" /* yacc.c:1646  */
    {
	// VAR *p = FindVAR($2);
	// ASSERT((p!=NULL), "Identificador já declarado");
	// AddVAR($2);
	char t[1000]; 
	sprintf(t, "%s = None", (yyvsp[0].ystr)); 
	(yyval.ystr)=stringpool(t);
}
#line 1589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 126 "parser.y" /* yacc.c:1646  */
    {
	char t[1000]; 
	sprintf(t, "%s = None", (yyvsp[0].ystr)); 
	(yyval.ystr)=stringpool(t);
}
#line 1599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 131 "parser.y" /* yacc.c:1646  */
    {	
	char t[1000];
	char w[1000];  
	sprintf(t, "%s =", (yyvsp[-2].ystr)); 
	sprintf(w, "%s", (yyvsp[0].ystr)); 
	sprintf(t, "%s %s", t, w);
	(yyval.ystr)=stringpool(t);
}
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 139 "parser.y" /* yacc.c:1646  */
    {
	char t[1000];
	char w[1000];  
	sprintf(t, "%s =", (yyvsp[-2].ystr)); 
	sprintf(w, "%s", (yyvsp[0].ystr)); 
	sprintf(t, "%s %s", t, w);
	(yyval.ystr)=stringpool(t);
}
#line 1625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 147 "parser.y" /* yacc.c:1646  */
    {
	char t[1000];
	char w[1000];  
	sprintf(t, "%s =", (yyvsp[-2].ystr)); 
	sprintf(w, "%s", (yyvsp[0].ystr)); 
	sprintf(t, "%s %s", t, w);
	(yyval.ystr)=stringpool(t);
}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 155 "parser.y" /* yacc.c:1646  */
    {
	fprintf(output, "def %s", (yyvsp[-1].ystr));
}
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = ""; }
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 158 "parser.y" /* yacc.c:1646  */
    { 
	fprintf(output, "def %s(", (yyvsp[-1].ystr));
}
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 160 "parser.y" /* yacc.c:1646  */
    { 
	fprintf(output, "):\n");
	global_scope += 1;
}
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 163 "parser.y" /* yacc.c:1646  */
    { 
	(yyval.ystr) = "";
	global_scope -= 1;
}
#line 1678 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 169 "parser.y" /* yacc.c:1646  */
    {	
	char t[1000];
	char w[1000];  
	sprintf(t, "%s =", (yyvsp[-2].ystr)); 
	sprintf(w, "%s", (yyvsp[0].ystr)); 
	sprintf(t, "%s %s", t, w);
	(yyval.ystr)=stringpool(t);
}
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 177 "parser.y" /* yacc.c:1646  */
    {
	char t[1000];
	char w[1000];  
	sprintf(t, "%s[%s] =", (yyvsp[-5].ystr), (yyvsp[-3].ystr)); 
	sprintf(w, "%s", (yyvsp[0].ystr)); 
	sprintf(t, "%s %s", t, w);
	(yyval.ystr)=stringpool(t);
}
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 187 "parser.y" /* yacc.c:1646  */
    { 
	fprintf(output, "(");
}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 189 "parser.y" /* yacc.c:1646  */
    { 
	fprintf(output, "):\n");
	global_scope += 1; 
}
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 192 "parser.y" /* yacc.c:1646  */
    { 
	global_scope -= 1; 
	(yyval.ystr) = "";
}
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 196 "parser.y" /* yacc.c:1646  */
    { 
	fprintf(output, "(%s):\n", (yyvsp[-3].ystr));
	global_scope += 1; 
}
#line 1739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 199 "parser.y" /* yacc.c:1646  */
    { 
	(yyval.ystr) = "";
	global_scope -= 1; 
}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = ""; }
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 206 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s", (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr); fprintf(output, "%s", (yyvsp[0].ystr));}
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr); fprintf(output, "%s", (yyvsp[0].ystr)); }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 211 "parser.y" /* yacc.c:1646  */
    {	
	fprintf(output, "%s", (yyvsp[0].ystr));
}
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 213 "parser.y" /* yacc.c:1646  */
    {	
	fprintf(output, ", ");
}
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 216 "parser.y" /* yacc.c:1646  */
    {	
	fprintf(output, "%s", (yyvsp[0].ystr));
}
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 218 "parser.y" /* yacc.c:1646  */
    {	
	fprintf(output, ", ");
}
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = ""; }
#line 1810 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 224 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s", (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t);}
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 225 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s, %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 1822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 226 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, ", %s", (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 1828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 229 "parser.y" /* yacc.c:1646  */
    { 
	ScopeTab();
	fprintf(output, "if %s:\n", (yyvsp[-2].ystr)); 
	global_scope += 1;
}
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 233 "parser.y" /* yacc.c:1646  */
    {
	global_scope -= 1;
}
#line 1846 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 238 "parser.y" /* yacc.c:1646  */
    { 
	ScopeTab();
	fprintf(output, "else:\n");
	global_scope += 1;
}
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 242 "parser.y" /* yacc.c:1646  */
    {
	global_scope -= 1;
}
#line 1864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 245 "parser.y" /* yacc.c:1646  */
    { 
	ScopeTab();
	fprintf(output, "elif %s:\n",(yyvsp[-2].ystr));
	global_scope += 1;
}
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 249 "parser.y" /* yacc.c:1646  */
    {
	global_scope -= 1;
}
#line 1882 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr)="[ ]";}
#line 1888 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 261 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "[ %s ]", (yyvsp[-1].ystr)); (yyval.ystr)=stringpool(t); }
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr); }
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 265 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s, %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 268 "parser.y" /* yacc.c:1646  */
    {
	char t[1000]; sprintf(t, "%s[%s]", (yyvsp[-3].ystr), (yyvsp[-1].ystr)); (yyval.ystr)=stringpool(t);
}
#line 1914 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 271 "parser.y" /* yacc.c:1646  */
    {
	char t[1000]; sprintf(t, "%s[%s]", (yyvsp[-3].ystr), (yyvsp[-1].ystr)); (yyval.ystr)=stringpool(t);
}
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr); }
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 277 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr) == stringpool("true") ? "True" : "False"; }
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr)= (yyvsp[0].ystr);  }
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr)= (yyvsp[0].ystr); }
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 280 "parser.y" /* yacc.c:1646  */
    {	
	(yyval.ystr)= (yyvsp[0].ystr); 
}
#line 1954 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 283 "parser.y" /* yacc.c:1646  */
    {
 char t[1000]; sprintf(t, "%s( %s )", (yyvsp[-3].ystr), (yyvsp[-1].ystr)); (yyval.ystr)=stringpool(t);}
#line 1961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr); }
#line 1967 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr); }
#line 1973 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 288 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s or %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 1979 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 289 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s if %s else %s", (yyvsp[-2].ystr), (yyvsp[-4].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 1985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 290 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s and %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 1991 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 291 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s or %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t);}
#line 1997 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 292 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s >= %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2003 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 293 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s <= %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2009 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 294 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s == %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 295 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s != %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2021 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 296 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s < %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2027 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 297 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s > %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 298 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s + %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2039 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 299 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s - %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2045 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 300 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s * %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2051 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 301 "parser.y" /* yacc.c:1646  */
    { char t[1000]; sprintf(t, "%s / %s", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr)=stringpool(t); }
#line 2057 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2061 "parser.tab.c" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 305 "parser.y" /* yacc.c:1906  */


int main( int argc, char *argv[] ) {
	output = fopen("output.py","w");
	init_stringpool(10000); //memória que vai guardar as strings
	if ( yyparse () == 0) printf("\n\n ----- Code without errors ----- \n\n");
}

int yyerror(char *s) { /* Called by yyparse on error */
	printf ("\n%s on line %d\n", s, yylineno );
}
