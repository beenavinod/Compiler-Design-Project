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
#line 1 "InterCodeGen.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	void yyerror(const char*);
	int yylex();

	extern FILE * yyin, *yyout;

	FILE *fp_icg, *fp_quad;
	
	extern int line;
	
	char buffer[100];
	int ln = 0, tempno = 0;

	int assignop = -1;		//assignment operator == += -=
	int unaryop = -1;		//unary operator type
	int exprno = -1;		//FOR loop , 3rd expression
	int m = 0;				//string length for buffer
	int literal = -1;       //literal or not
	int paramno = 0;		//Number of parameters

	char intbuf[20];
	char secIDbuf[20];




#line 97 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    HASH = 258,
    INCLUDE = 259,
    STDIO = 260,
    STDLIB = 261,
    MATH = 262,
    STRING = 263,
    TIME = 264,
    IOSTREAM = 265,
    STRING_LITERAL = 266,
    HEADER_LITERAL = 267,
    PRINT = 268,
    RETURN = 269,
    UMINUS = 270,
    INTEGER_LITERAL = 271,
    CHARACTER_LITERAL = 272,
    FLOAT_LITERAL = 273,
    IDENTIFIER = 274,
    FOR = 275,
    IF = 276,
    DO = 277,
    WHILE = 278,
    INC_OP = 279,
    DEC_OP = 280,
    LE_OP = 281,
    GE_OP = 282,
    EQ_OP = 283,
    NE_OP = 284,
    MUL_ASSIGN = 285,
    DIV_ASSIGN = 286,
    MOD_ASSIGN = 287,
    ADD_ASSIGN = 288,
    SUB_ASSIGN = 289,
    CHAR = 290,
    INT = 291,
    FLOAT = 292,
    VOID = 293
  };
#endif
/* Tokens.  */
#define HASH 258
#define INCLUDE 259
#define STDIO 260
#define STDLIB 261
#define MATH 262
#define STRING 263
#define TIME 264
#define IOSTREAM 265
#define STRING_LITERAL 266
#define HEADER_LITERAL 267
#define PRINT 268
#define RETURN 269
#define UMINUS 270
#define INTEGER_LITERAL 271
#define CHARACTER_LITERAL 272
#define FLOAT_LITERAL 273
#define IDENTIFIER 274
#define FOR 275
#define IF 276
#define DO 277
#define WHILE 278
#define INC_OP 279
#define DEC_OP 280
#define LE_OP 281
#define GE_OP 282
#define EQ_OP 283
#define NE_OP 284
#define MUL_ASSIGN 285
#define DIV_ASSIGN 286
#define MOD_ASSIGN 287
#define ADD_ASSIGN 288
#define SUB_ASSIGN 289
#define CHAR 290
#define INT 291
#define FLOAT 292
#define VOID 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "InterCodeGen.y" /* yacc.c:355  */
	
	char sval[300];

#line 217 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 234 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    19,     2,     2,
      50,    51,    18,    15,    52,    16,     2,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    49,
      45,    20,    46,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,    56,     2,     2,     2,
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
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    77,    78,    79,    84,    85,    90,    91,
      96,    97,    98,    99,   100,   101,   106,   107,   112,   113,
     114,   120,   121,   122,   123,   124,   129,   130,   135,   140,
     141,   142,   143,   148,   147,   163,   170,   162,   331,   336,
     331,   357,   366,   374,   382,   390,   403,   415,   427,   439,
     455,   471,   487,   506,   507,   508,   509,   514,   515,   520,
     535,   540,   541,   627,   628,   629,   630,   631,   632,   637,
     639,   646,   638,   675,   676,   681,   682,   687,   688,   689,
     690,   691,   696,   697,   709,   724,   725,   761,   762,   763,
     764,   765,   766,   771,   772,   782,   796,   797,   807,   817,
     827,   841,   842,   853,   867,   868,   878,   888,   902,   903,
     907,   915,   924,   930,   934,   935,   940,   941,   946,   947,
     952,   957
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HASH", "INCLUDE", "STDIO", "STDLIB",
  "MATH", "STRING", "TIME", "IOSTREAM", "STRING_LITERAL", "HEADER_LITERAL",
  "PRINT", "RETURN", "'+'", "'-'", "'/'", "'*'", "'%'", "'='", "UMINUS",
  "INTEGER_LITERAL", "CHARACTER_LITERAL", "FLOAT_LITERAL", "IDENTIFIER",
  "FOR", "IF", "DO", "WHILE", "INC_OP", "DEC_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "CHAR", "INT", "FLOAT", "VOID", "'<'", "'>'", "'{'", "'}'",
  "';'", "'('", "')'", "','", "'?'", "':'", "'!'", "'~'", "\"INC_OP\"",
  "\"DEC_OP\"", "$accept", "S", "program", "translation_unit", "ext_dec",
  "libraries", "compound_statement", "block_item_list", "block_item",
  "printstat", "declaration", "statement", "selection_statement", "$@1",
  "iteration_statement", "$@2", "$@3", "$@4", "$@5", "expr",
  "type_specifier", "init_declarator_list", "init_declarator",
  "assignment_expression", "assignment_operator", "conditional_expression",
  "$@6", "$@7", "expression_statement", "expression", "primary_expression",
  "postfix_expression", "unary_expression", "unary_operator",
  "equality_expression", "relational_expression", "additive_expression",
  "multiplicative_expression", "function_definition", "function_call",
  "declarator", "parameter_list", "parameter_declaration",
  "identifier_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    43,    45,    47,    42,    37,
      61,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,    60,    62,   123,   125,    59,
      40,    41,    44,    63,    58,    33,   126,   294,   295
};
# endif

#define YYPACT_NINF -100

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define YYTABLE_NINF -116

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,    24,  -100,  -100,  -100,  -100,  -100,    32,  -100,   198,
    -100,  -100,    22,  -100,   -32,    -3,  -100,  -100,    15,   -30,
    -100,   -32,   105,   -17,  -100,    41,   238,   180,  -100,    43,
    -100,  -100,    39,   158,  -100,  -100,  -100,  -100,  -100,    53,
      58,    61,  -100,  -100,  -100,   180,  -100,  -100,  -100,  -100,
    -100,   143,  -100,    64,  -100,  -100,  -100,  -100,    43,  -100,
    -100,  -100,   -29,  -100,   -20,   102,   180,   -22,    42,    81,
      98,    76,    83,  -100,  -100,   112,    49,  -100,    72,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,   118,  -100,  -100,   125,
    -100,   168,  -100,   158,   180,   121,    84,  -100,  -100,  -100,
    -100,   180,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
     180,  -100,   180,   180,   141,   180,   180,   180,   180,   180,
     180,   180,   180,   180,  -100,    51,  -100,  -100,    37,  -100,
     172,    41,    92,  -100,    99,   180,  -100,  -100,  -100,  -100,
      42,    42,   180,    81,    81,    81,    81,    98,    98,  -100,
    -100,  -100,   156,   137,  -100,  -100,  -100,  -100,   180,   158,
    -100,   159,   175,   162,   166,  -100,    14,  -100,   170,  -100,
      74,  -100,    14,   180,   189,   226,   227,   202,  -100,  -100,
     229,  -100,  -100,   233,   234,   235,   236,  -100,  -100,    14,
     160,  -100,  -100,  -100,  -100,  -100,   237,   239,   240,   241,
    -100,  -100,  -100,  -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   112,    54,    55,    56,    53,     0,     2,     5,
       6,     8,     0,     9,     0,     0,     1,     7,    60,     0,
      57,     0,     0,     0,   109,     0,     0,     0,    28,     0,
     108,    20,     0,     0,    87,    88,    78,    80,    79,    77,
       0,     0,    38,    16,    73,     0,    89,    90,    91,    92,
      29,     0,    18,     0,    21,    22,    32,    31,     0,    75,
      61,    30,     0,    82,    85,   104,     0,    69,    93,    96,
     101,     0,     0,   120,   115,   119,     0,   116,     0,     4,
      10,    11,    12,    13,    14,    15,     0,    77,    59,    60,
      58,     0,    23,     0,     0,     0,     0,    17,    19,    25,
      74,     0,    83,    84,    63,    66,    67,    68,    64,    65,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,   118,   113,     0,   114,
       0,     0,     0,    35,     0,     0,    81,    76,    62,   104,
      94,    95,     0,    99,   100,    97,    98,   102,   103,   106,
     105,   107,   111,     0,   117,   121,     3,    26,     0,     0,
      33,     0,    71,   110,     0,    36,     0,    39,     0,    27,
       0,    34,     0,     0,     0,     0,     0,     0,    40,    72,
       0,    41,    42,     0,     0,     0,     0,    43,    44,     0,
       0,    47,    48,    45,    46,    37,     0,     0,     0,     0,
      49,    50,    52,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,   -19,  -100,   251,  -100,     0,  -100,   213,  -100,
      -6,   -99,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
     -18,  -100,   242,   -24,  -100,    93,  -100,  -100,   -33,   -44,
    -100,  -100,   -64,  -100,  -100,   109,   116,   130,  -100,  -100,
      -5,  -100,   139,   140
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    86,    50,    51,    52,    53,
      11,    55,    56,   166,    57,   159,   170,    95,   172,   177,
      12,    19,    20,    59,   110,    60,   114,   168,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    13,    71,
      14,    76,    77,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    96,   111,    88,    58,    75,    79,    21,    73,    25,
     102,   103,   112,   113,    24,    22,    54,    72,    23,    28,
     100,    30,    29,   101,     3,     4,     5,     6,    15,    34,
      35,   -70,    16,    58,    74,    27,    36,    37,    38,    87,
      40,    41,    26,    42,     1,    54,    72,    18,   139,   139,
     134,   139,   139,   139,   139,   139,   139,   149,   150,   151,
     133,    22,  -112,    44,    45,  -112,     2,   171,    89,    46,
      47,    48,    49,   178,   115,   116,    73,   137,     3,     4,
       5,     6,     3,     4,     5,     6,   138,   117,   118,    91,
     195,   161,     3,     4,     5,     6,   119,   120,   162,   174,
     127,   128,   152,  -112,   175,   176,    31,    75,    93,   139,
      75,    94,   156,    99,   164,   121,   122,   123,    32,    33,
      34,    35,   104,   129,   130,   124,   165,    36,    37,    38,
      39,    40,    41,   125,    42,   136,   101,   126,   105,   106,
     107,   108,   109,   157,   158,    27,     3,     4,     5,     6,
     160,   101,    22,    43,    44,    45,    32,    33,    34,    35,
      46,    47,    48,    49,   131,    36,    37,    38,    39,    40,
      41,   135,    42,    34,    35,   196,   197,   198,   199,   132,
      36,    37,    38,    87,     3,     4,     5,     6,   163,   130,
      22,    97,    44,    45,   142,    34,    35,   155,    46,    47,
      48,    49,    36,    37,    38,    87,  -115,    44,    45,   180,
     167,   101,  -114,    46,    47,    48,    49,   169,   101,   181,
     182,   140,   141,     2,   173,   183,   184,   101,   185,   186,
      45,   143,   144,   145,   146,    46,    47,    48,    49,     3,
       4,     5,     6,    80,    81,    82,    83,    84,    85,   147,
     148,   187,   188,   189,   190,   191,   192,   193,   194,   200,
      17,   201,   202,   203,    98,   153,   179,   154,     0,     0,
       0,    90
};

static const yytype_int16 yycheck[] =
{
      33,    45,    66,    27,    22,    23,    25,    12,    25,    12,
      30,    31,    34,    35,    14,    47,    22,    22,    50,    49,
      49,    21,    52,    52,    41,    42,    43,    44,     4,    15,
      16,    53,     0,    51,    51,    20,    22,    23,    24,    25,
      26,    27,    45,    29,     3,    51,    51,    25,   112,   113,
      94,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      93,    47,    47,    49,    50,    50,    25,   166,    25,    55,
      56,    57,    58,   172,    32,    33,    25,   101,    41,    42,
      43,    44,    41,    42,    43,    44,   110,    45,    46,    50,
     189,   135,    41,    42,    43,    44,    15,    16,   142,    25,
      51,    52,    51,    50,    30,    31,     1,   125,    50,   173,
     128,    50,   131,    49,   158,    17,    18,    19,    13,    14,
      15,    16,    20,    51,    52,    49,   159,    22,    23,    24,
      25,    26,    27,    50,    29,    51,    52,    25,    36,    37,
      38,    39,    40,    51,    52,    20,    41,    42,    43,    44,
      51,    52,    47,    48,    49,    50,    13,    14,    15,    16,
      55,    56,    57,    58,    46,    22,    23,    24,    25,    26,
      27,    50,    29,    15,    16,    15,    16,    17,    18,    11,
      22,    23,    24,    25,    41,    42,    43,    44,    51,    52,
      47,    48,    49,    50,    53,    15,    16,    25,    55,    56,
      57,    58,    22,    23,    24,    25,    50,    49,    50,    20,
      51,    52,    50,    55,    56,    57,    58,    51,    52,    30,
      31,   112,   113,    25,    54,    36,    37,    52,    39,    40,
      50,   115,   116,   117,   118,    55,    56,    57,    58,    41,
      42,    43,    44,     5,     6,     7,     8,     9,    10,   119,
     120,    25,    25,    51,    25,    22,    22,    22,    22,    22,
       9,    22,    22,    22,    51,   125,   173,   128,    -1,    -1,
      -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    25,    41,    42,    43,    44,    60,    61,    62,
      63,    69,    79,    97,    99,     4,     0,    63,    25,    80,
      81,    99,    47,    50,    65,    12,    45,    20,    49,    52,
      65,     1,    13,    14,    15,    16,    22,    23,    24,    25,
      26,    27,    29,    48,    49,    50,    55,    56,    57,    58,
      65,    66,    67,    68,    69,    70,    71,    73,    79,    82,
      84,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    98,    99,    25,    51,    79,   100,   101,   102,    61,
       5,     6,     7,     8,     9,    10,    64,    25,    82,    25,
      81,    50,    87,    50,    50,    76,    88,    48,    67,    49,
      49,    52,    30,    31,    20,    36,    37,    38,    39,    40,
      83,    91,    34,    35,    85,    32,    33,    45,    46,    15,
      16,    17,    18,    19,    49,    50,    25,    51,    52,    51,
      52,    46,    11,    87,    88,    50,    51,    82,    82,    91,
      94,    94,    53,    95,    95,    95,    95,    96,    96,    91,
      91,    91,    51,   102,   101,    25,    61,    51,    52,    74,
      51,    88,    88,    51,    88,    87,    72,    51,    86,    51,
      75,    70,    77,    54,    25,    30,    31,    78,    70,    84,
      20,    30,    31,    36,    37,    39,    40,    25,    25,    51,
      25,    22,    22,    22,    22,    70,    15,    16,    17,    18,
      22,    22,    22,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    68,    68,    69,    70,
      70,    70,    70,    72,    71,    74,    75,    73,    76,    77,
      73,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    84,
      85,    86,    84,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    90,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    92,    93,    93,    93,    94,    94,    94,    94,
      94,    95,    95,    95,    96,    96,    96,    96,    97,    97,
      98,    98,    99,    99,    99,    99,   100,   100,   101,   101,
     102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     4,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     4,     6,     3,     1,
       1,     1,     1,     0,     6,     0,     0,     9,     0,     0,
       7,     2,     2,     2,     2,     3,     3,     3,     3,     5,
       5,     5,     5,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     7,     1,     2,     1,     3,     1,     1,     1,
       1,     3,     1,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     2,
       4,     3,     1,     4,     4,     3,     1,     3,     2,     1,
       1,     3
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
        case 20:
#line 114 "InterCodeGen.y" /* yacc.c:1646  */
    { }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 148 "InterCodeGen.y" /* yacc.c:1646  */
    {
			fprintf(fp_icg, "ifFalse t%d goto L%d\n", --tempno, ln);
			fprintf(fp_quad, "\tifFalse\t\tt%d\t\t  \t\tL%d\n", tempno, ln);
			tempno++;
		}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 154 "InterCodeGen.y" /* yacc.c:1646  */
    {	
			fprintf(fp_icg, "L%d:\n", ln);
			fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
			ln++;
		}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 163 "InterCodeGen.y" /* yacc.c:1646  */
    { 
			fprintf(fp_icg,"L%d:\n", ln);
			fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
			ln++;

		}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 170 "InterCodeGen.y" /* yacc.c:1646  */
    {
			fprintf(fp_icg, "ifFalse t%d goto L%d\n", --tempno, ln);
			fprintf(fp_quad, "\tifFalse\t\tt%d\t\t  \t\tL%d\n", tempno, ln);
			tempno++;
		}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 176 "InterCodeGen.y" /* yacc.c:1646  */
    {
		
			//expression 3

			switch(exprno){
				case 0:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s + 1\n",buffer, (yyvsp[-2].sval));
						fprintf(fp_quad, "\t+\t\t%s\t\t1 \t\t%s\n", (yyvsp[-2].sval), buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 1:	
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s - 1\n",buffer, (yyvsp[-2].sval));
						fprintf(fp_quad, "\t-\t\t%s\t\t1 \t\t%s\n", (yyvsp[-2].sval), buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 2:	
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s + 1\n",buffer, (yyvsp[-2].sval));
						fprintf(fp_quad, "\t+\t\t%s\t\t1 \t\t%s\n", (yyvsp[-2].sval), buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 3:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s - 1\n",buffer, (yyvsp[-2].sval));
						fprintf(fp_quad, "\t-\t\t%s\t\t1 \t\t%s\n", (yyvsp[-2].sval), buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 4:						
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s + %s\n",buffer, (yyvsp[-2].sval), intbuf);
						fprintf(fp_quad, "\t+\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), intbuf, buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 5:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s - %s\n",buffer, (yyvsp[-2].sval), intbuf);
						fprintf(fp_quad, "\t-\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), intbuf, buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 6:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s * %s\n",buffer, (yyvsp[-2].sval), intbuf);
						fprintf(fp_quad, "\t*\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), intbuf, buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 7:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s / %s\n",buffer, (yyvsp[-2].sval), intbuf);
						fprintf(fp_quad, "\t/\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), intbuf, buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 8:	
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s + %s\n",buffer, secIDbuf, intbuf);
						fprintf(fp_quad, "\t+\t\t%s\t\t%s\t\t%s\n", secIDbuf, intbuf, buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 9:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s - %s\n",buffer, secIDbuf, intbuf);
						fprintf(fp_quad, "\t-\t\t%s\t\t%s\t\t%s\n", secIDbuf, intbuf, buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 10:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s * %s\n",buffer, secIDbuf, intbuf);
						fprintf(fp_quad, "\t*\t\t%s\t\t%s\t\t%s\n", secIDbuf, intbuf, buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;

				case 11:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s / %s\n",buffer, secIDbuf, intbuf);
						fprintf(fp_quad, "\t/\t\t%s\t\t%s\t\t%s\n", secIDbuf, intbuf, buffer);

						fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), buffer);
						fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-2].sval));
						break;
			}

			exprno = -1;

			//end of expression 3

			fprintf(fp_icg, "goto L%d\n", --ln);
			fprintf(fp_quad, "\tgoto\t\t  \t\t  \t\tL%d\n", ln);
			ln++;

			fprintf(fp_icg, "L%d:\n", ln);
			fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
			ln++;

		}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 331 "InterCodeGen.y" /* yacc.c:1646  */
    {
		fprintf(fp_icg,"L%d:\n", ln);
		fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
		ln++;
		}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 336 "InterCodeGen.y" /* yacc.c:1646  */
    {
			fprintf(fp_icg, "ifFalse t%d goto L%d\n", --tempno, ln);
			fprintf(fp_quad, "\tifFalse\t\tt%d\t\t  \t\tL%d\n", tempno, ln);
			tempno++;
		}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 341 "InterCodeGen.y" /* yacc.c:1646  */
    {
			fprintf(fp_icg, "goto L%d\n", --ln);
			fprintf(fp_quad, "\tgoto\t\t  \t\t  \t\tL%d\n", ln);
			ln++;

		fprintf(fp_icg,"L%d:\n", ln);
		fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
		ln++;
		
		}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 358 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			// printf("ID %s\n", $1);
			exprno = 0; 

			m = strlen((yyvsp[-1].sval));
			strncpy((yyval.sval), (yyvsp[-1].sval), m);
			(yyval.sval)[m] = '\0';
		}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 367 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 1;

			m = strlen((yyvsp[-1].sval));
			strncpy((yyval.sval), (yyvsp[-1].sval), m);
			(yyval.sval)[m] = '\0';
		}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 375 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 2;

			m = strlen((yyvsp[0].sval));
			strncpy((yyval.sval), (yyvsp[0].sval), m);
			(yyval.sval)[m] = '\0';
		}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 383 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 3; 

			m = strlen((yyvsp[0].sval));
			strncpy((yyval.sval), (yyvsp[0].sval), m);
			(yyval.sval)[m] = '\0';
		}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 391 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 4; 

			m = strlen((yyvsp[-2].sval));
			strncpy((yyval.sval), (yyvsp[-2].sval), m);
			(yyval.sval)[m] = '\0';

			m = strlen((yyvsp[0].sval));
			strncpy(intbuf, (yyvsp[0].sval), m);
			intbuf[m] = '\0';

		}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 404 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 5;
			
			m = strlen((yyvsp[-2].sval));
			strncpy((yyval.sval), (yyvsp[-2].sval), m);
			(yyval.sval)[m] = '\0';

			m = strlen((yyvsp[0].sval));
			strncpy(intbuf, (yyvsp[0].sval), m);
			intbuf[m] = '\0';
		}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 416 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 6;
			
			m = strlen((yyvsp[-2].sval));
			strncpy((yyval.sval), (yyvsp[-2].sval), m);
			(yyval.sval)[m] = '\0';

			m = strlen((yyvsp[0].sval));
			strncpy(intbuf, (yyvsp[0].sval), m);
			intbuf[m] = '\0';
		}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 428 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 7; 
			
			m = strlen((yyvsp[-2].sval));
			strncpy((yyval.sval), (yyvsp[-2].sval), m);
			(yyval.sval)[m] = '\0';

			m = strlen((yyvsp[0].sval));
			strncpy(intbuf, (yyvsp[0].sval), m);
			intbuf[m] = '\0';
		}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 440 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 8;

			m = strlen((yyvsp[-4].sval));
			strncpy((yyval.sval), (yyvsp[-4].sval), m);
			(yyval.sval)[m] = '\0';

			m = strlen((yyvsp[0].sval));
			strncpy(intbuf, (yyvsp[0].sval), m);
			intbuf[m] = '\0';

			m = strlen((yyvsp[-2].sval));
			strncpy(secIDbuf, (yyvsp[-2].sval), m);
			secIDbuf[m] = '\0';
		}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 456 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 9;
			
			m = strlen((yyvsp[-4].sval));
			strncpy((yyval.sval), (yyvsp[-4].sval), m);
			(yyval.sval)[m] = '\0';

			m = strlen((yyvsp[0].sval));
			strncpy(intbuf, (yyvsp[0].sval), m);
			intbuf[m] = '\0';

			m = strlen((yyvsp[-2].sval));
			strncpy(secIDbuf, (yyvsp[-2].sval), m);
			secIDbuf[m] = '\0';
		}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 472 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 10; 
			
			m = strlen((yyvsp[-4].sval));
			strncpy((yyval.sval), (yyvsp[-4].sval), m);
			(yyval.sval)[m] = '\0';

			m = strlen((yyvsp[0].sval));
			strncpy(intbuf, (yyvsp[0].sval), m);
			intbuf[m] = '\0';

			m = strlen((yyvsp[-2].sval));
			strncpy(secIDbuf, (yyvsp[-2].sval), m);
			secIDbuf[m] = '\0';
		}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 488 "InterCodeGen.y" /* yacc.c:1646  */
    {  
			exprno = 11; 

			m = strlen((yyvsp[-4].sval));
			strncpy((yyval.sval), (yyvsp[-4].sval), m);
			(yyval.sval)[m] = '\0';

			m = strlen((yyvsp[0].sval));
			strncpy(intbuf, (yyvsp[0].sval), m);
			intbuf[m] = '\0';

			m = strlen((yyvsp[-2].sval));
			strncpy(secIDbuf, (yyvsp[-2].sval), m);
			secIDbuf[m] = '\0';
		}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 521 "InterCodeGen.y" /* yacc.c:1646  */
    {
			if(tempno > 0 && literal == -1){
				fprintf(fp_icg, "%s = t%d\n", (yyvsp[-2].sval), --tempno); 
				fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, (yyvsp[-2].sval));
				tempno++;
			}
			//else if(tempno==0 || literal==0){
			else{
				fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), (yyvsp[0].sval)); 
				fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", (yyvsp[0].sval), (yyvsp[-2].sval));
				literal = -1;
			}
			
		}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 540 "InterCodeGen.y" /* yacc.c:1646  */
    {	strcpy((yyval.sval), (yyvsp[0].sval)); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 542 "InterCodeGen.y" /* yacc.c:1646  */
    {
			switch(assignop){
				case 0: if(tempno > 0 && literal==-1){
							fprintf(fp_icg, "%s = t%d\n", (yyvsp[-2].sval), --tempno); 
							fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, (yyvsp[-2].sval));
							tempno++;
						}
						//else if(tempno == 0){
						else{
							fprintf(fp_icg, "%s = %s\n", (yyvsp[-2].sval), (yyvsp[0].sval)); 
							fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", (yyvsp[0].sval), (yyvsp[-2].sval));
							literal=-1;							
						}
						break;

				case 1: 
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s + %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
						fprintf(fp_quad, "\t+\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

						fprintf(fp_icg, "%s = t%d\n", (yyvsp[-2].sval), --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, (yyvsp[-2].sval));
						tempno++;
					
						break;
				case 2:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s - %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
						fprintf(fp_quad, "\t-\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

						fprintf(fp_icg, "%s = t%d\n", (yyvsp[-2].sval), --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, (yyvsp[-2].sval));
						tempno++;

						break;
				case 3:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s * %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
						fprintf(fp_quad, "\t*\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

						fprintf(fp_icg, "%s = t%d\n", (yyvsp[-2].sval), --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, (yyvsp[-2].sval));
						tempno++;

						break;
				case 4:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s / %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
						fprintf(fp_quad, "\t/\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

						fprintf(fp_icg, "%s = t%d\n", (yyvsp[-2].sval), --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, (yyvsp[-2].sval));
						tempno++;

						break;
				case 5:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s %c %s\n",buffer, (yyvsp[-2].sval), '%',(yyvsp[0].sval));
						fprintf(fp_quad, "\t%c\t\t%s\t\t%s\t\t%s\n", '%', (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

						fprintf(fp_icg, "%s = t%d\n", (yyvsp[-2].sval), --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, (yyvsp[-2].sval));
						tempno++;

						break;
			}
			
			assignop = -1;

			
		}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 627 "InterCodeGen.y" /* yacc.c:1646  */
    { assignop = 0; 	}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 628 "InterCodeGen.y" /* yacc.c:1646  */
    { assignop = 1; 	}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 629 "InterCodeGen.y" /* yacc.c:1646  */
    { assignop = 2; 	}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 630 "InterCodeGen.y" /* yacc.c:1646  */
    { assignop = 3; 	}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 631 "InterCodeGen.y" /* yacc.c:1646  */
    { assignop = 4; 	}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 632 "InterCodeGen.y" /* yacc.c:1646  */
    { assignop = 5; 	}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 637 "InterCodeGen.y" /* yacc.c:1646  */
    {	strcpy((yyval.sval), (yyvsp[0].sval));  }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 639 "InterCodeGen.y" /* yacc.c:1646  */
    { 
			fprintf(fp_icg,"ifFalse t%d goto L%d\n", --tempno, ln); 
			fprintf(fp_quad, "\tifFalse\t\tt%d\t\t  \t\tL%d\n", tempno, ln);
			tempno++;		
			ln++;
		}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 646 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s\n", buffer, (yyvsp[0].sval));
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", (yyvsp[0].sval), buffer);

			fprintf(fp_icg,"goto L%d\n", ln);
			fprintf(fp_quad, "\tgoto\t\t  \t\t  \t\tL%d\n", ln);

			fprintf(fp_icg,"L%d:\n", --ln);
			fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
			ln++;
		}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 661 "InterCodeGen.y" /* yacc.c:1646  */
    {
			
			fprintf(fp_icg, "%s = %s\n", buffer, (yyvsp[0].sval));
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", (yyvsp[0].sval), buffer);

			fprintf(fp_icg,"L%d:\n", ln);
			fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
			ln++;
		}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 681 "InterCodeGen.y" /* yacc.c:1646  */
    {	strcpy((yyval.sval), (yyvsp[0].sval)); }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 687 "InterCodeGen.y" /* yacc.c:1646  */
    {	literal=0;strcpy((yyval.sval), (yyvsp[0].sval)); 	}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 688 "InterCodeGen.y" /* yacc.c:1646  */
    {	literal=0;strcpy((yyval.sval), (yyvsp[0].sval)); 	}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 689 "InterCodeGen.y" /* yacc.c:1646  */
    {	literal=0;strcpy((yyval.sval), (yyvsp[0].sval)); 	}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 690 "InterCodeGen.y" /* yacc.c:1646  */
    {	literal=0;strcpy((yyval.sval), (yyvsp[0].sval)); 	}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 691 "InterCodeGen.y" /* yacc.c:1646  */
    {	literal=0;strcpy((yyval.sval), (yyvsp[-1].sval)); 	}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 696 "InterCodeGen.y" /* yacc.c:1646  */
    {	strcpy((yyval.sval), (yyvsp[0].sval)); }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 698 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s + 1\n",buffer, (yyvsp[-1].sval));
			fprintf(fp_quad, "\t+\t\t%s\t\t1 \t\t%s\n", (yyvsp[-1].sval), buffer);

			fprintf(fp_icg, "%s = %s\n", (yyvsp[-1].sval), buffer);
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-1].sval));
			
		}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 710 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s - 1\n",buffer, (yyvsp[-1].sval));
			fprintf(fp_quad, "\t-\t\t%s\t\t1 \t\t%s\n", (yyvsp[-1].sval), buffer);

			fprintf(fp_icg, "%s = %s\n", (yyvsp[-1].sval), buffer);
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, (yyvsp[-1].sval));
		}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 724 "InterCodeGen.y" /* yacc.c:1646  */
    {	strcpy((yyval.sval), (yyvsp[0].sval)); }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 726 "InterCodeGen.y" /* yacc.c:1646  */
    {
			switch(unaryop){
				case 1: 
						sprintf(buffer,"t%d",tempno++);	
						m = strlen(buffer);
						buffer[m] = '\0';					
						fprintf(fp_icg, "%s = -%s\n",buffer, (yyvsp[0].sval));	
						fprintf(fp_quad, "\t-\t\t%s\t\t  \t\t%s\n", (yyvsp[0].sval), buffer);
						strncpy((yyval.sval), buffer, m+1);						
						break;

				case 4: 
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s + 1\n",buffer, (yyvsp[0].sval));
						fprintf(fp_quad, "\t+\t\t%s\t\t1 \t\t%s\n", (yyvsp[0].sval), buffer);
						strncpy((yyval.sval), buffer, m+1);		//check out
						break;

				case 5:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s - 1\n",buffer, (yyvsp[0].sval));
						fprintf(fp_quad, "\t-\t\t%s\t\t1 \t\t%s\n", (yyvsp[0].sval), buffer);
						strncpy((yyval.sval), buffer, m+1);		//check out
						break;
			}
			unaryop = -1;
		}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 761 "InterCodeGen.y" /* yacc.c:1646  */
    {	unaryop = 0; }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 762 "InterCodeGen.y" /* yacc.c:1646  */
    {	unaryop = 1; }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 763 "InterCodeGen.y" /* yacc.c:1646  */
    {	unaryop = 2; }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 764 "InterCodeGen.y" /* yacc.c:1646  */
    {	unaryop = 3; }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 765 "InterCodeGen.y" /* yacc.c:1646  */
    {	unaryop = 4; }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 766 "InterCodeGen.y" /* yacc.c:1646  */
    {	unaryop = 5; }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 771 "InterCodeGen.y" /* yacc.c:1646  */
    {	strcpy((yyval.sval), (yyvsp[0].sval)); }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 773 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s == %s\n", buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t==\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 783 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s != %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t!=\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 796 "InterCodeGen.y" /* yacc.c:1646  */
    {	strcpy((yyval.sval), (yyvsp[0].sval)); }
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 798 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s < %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t<\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 808 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s > %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t>\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 818 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s <= %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t<=\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 828 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s >= %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t>=\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 841 "InterCodeGen.y" /* yacc.c:1646  */
    {	strcpy((yyval.sval), (yyvsp[0].sval)); }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 843 "InterCodeGen.y" /* yacc.c:1646  */
    {
			// printf("%s + %s\n", $1, $3 );
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s + %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t+\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 854 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s - %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t-\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 869 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s * %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t*\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 879 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s / %s\n",buffer, (yyvsp[-2].sval), (yyvsp[0].sval));
			fprintf(fp_quad, "\t/\t\t%s\t\t%s\t\t%s\n", (yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 889 "InterCodeGen.y" /* yacc.c:1646  */
    {
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s %c %s\n",buffer, (yyvsp[-2].sval), '%',(yyvsp[0].sval));
			fprintf(fp_quad, "\t%c\t\t%s\t\t%s\t\t%s\n", '%',(yyvsp[-2].sval), (yyvsp[0].sval), buffer);

			strncpy((yyval.sval), buffer, m+1);		//check out
		}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 908 "InterCodeGen.y" /* yacc.c:1646  */
    {
			paramno++;	
			fprintf(fp_icg, "call(%s, %d)\n", (yyvsp[-3].sval), paramno);	
			fprintf(fp_quad, "\tcall\t\t%s\t\t%d\n", (yyvsp[-3].sval), paramno);

			paramno = 0;	
		}
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 916 "InterCodeGen.y" /* yacc.c:1646  */
    {
			fprintf(fp_icg, "call(%s, 0)\n", (yyvsp[-2].sval));	
			fprintf(fp_quad, "\tcall\t\t%s\t\t0\n", (yyvsp[-2].sval));
		}
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 925 "InterCodeGen.y" /* yacc.c:1646  */
    { 
			m = strlen((yyvsp[0].sval));
			strncpy((yyval.sval), (yyvsp[0].sval), m);	
			(yyval.sval)[m] = '\0';
		}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 931 "InterCodeGen.y" /* yacc.c:1646  */
    {
			
		}
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 953 "InterCodeGen.y" /* yacc.c:1646  */
    {
			fprintf(fp_icg, "param %s\n", (yyvsp[0].sval));
			fprintf(fp_quad, "\tparam\t\t%s\n", (yyvsp[0].sval));
		}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 958 "InterCodeGen.y" /* yacc.c:1646  */
    {
			fprintf(fp_icg, "param %s\n", (yyvsp[0].sval));
			fprintf(fp_quad, "\tparam\t\t%s\n", (yyvsp[0].sval));	
			
			paramno++; 
		}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2494 "y.tab.c" /* yacc.c:1646  */
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
#line 967 "InterCodeGen.y" /* yacc.c:1906  */



void yyerror(const char *str){
	fflush(stdout);
	printf("Line:%d: ", line);
	printf("\033[1;31m");
	printf("error: ");
	printf("\033[0m");
	printf("%s\n", str);
}


int main(){
	
	fp_icg 	 	= fopen("IntermediateCode/icg.txt", "w");
	fp_quad		= fopen("IntermediateCode/quad.txt", "w");
	printf("\n");
	

	fprintf(fp_quad, "\tOp\t\topr1\t\topr2\t\tResult\n");
	fprintf(fp_quad, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

	yyparse();
	
	fclose(fp_icg);
	


	printf("\n\nQuadruple Format\n\n");
	
	

	fclose(fp_quad);
	system("cat IntermediateCode/quad.txt");
		printf("\n\nIntermediate Code\n\n");
	system("cat IntermediateCode/icg.txt");
	
	return 0;
}

