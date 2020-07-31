/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "ast.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <limits.h>
	// #define COUNT 10		//use while printing AST

	void yyerror(const char*);
	int yylex();
	extern FILE * yyin, *yyout;

	int x=0;	

	extern int line;
	
	int scope = 0;

	int unaryop = -1;		//unary operator type
	int assignop = -1;		//assignment operator == += -=
	int datatype = -1;		//type specifier
	int assigntype = -1;	//RHS type 
	int idcheck = -1;		//check if ID 
	int check_un = 0;		//check for undeclared variables


	char tempStr[100];		//sprintf

	struct node{
		char token[20];
		char name[20];
		int dtype;
		int scope;
		int lineno;
		int valid;
		union value{
			float f;
			int i;
			char c;
		}val;
		
		struct node *link;

	}*first = NULL, *tmp, *crt, *lhs;

	typedef struct Node{
		struct Node *left;
		struct Node *right;
		char token[100];
		struct Node *val;
		int level;
	}Node;

	typedef struct tree_stack{
		Node *node;
		struct tree_stack *next;
	}tree_stack;

	tree_stack *tree_top = NULL;
	char preBuf[1000000];

	struct node * checksym(char *);
	void addsymbol(struct node *,char *);	
	void addInt(struct node *, int, int);
	void addFloat(struct node *, int, float);
	void addChar(struct node *, int, char);
	void addfunc(struct node *t, int, char *);
	void printsymtable();

	struct node * addtosymbol(struct node * n);
	void cleansymbol();


	//AST 
	void create_node(char *token, int leaf);
	void push_tree(Node *newnode);
	Node *pop_tree();
	void preorder(Node* root);
	void printtree(Node* root);
	int getmaxlevel(Node *root);
	void printGivenLevel(Node* root, int level, int h);
	void get_levels(Node *root, int level);



/* Line 371 of yacc.c  */
#line 153 "ast.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "ast.tab.h".  */
#ifndef YY_YY_AST_TAB_H_INCLUDED
# define YY_YY_AST_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HASH = 258,
     INCLUDE = 259,
     STDIO = 260,
     STDLIB = 261,
     MATH = 262,
     STRING = 263,
     TIME = 264,
     STRING_LITERAL = 265,
     HEADER_LITERAL = 266,
     PRINT = 267,
     RETURN = 268,
     INTEGER_LITERAL = 269,
     CHARACTER_LITERAL = 270,
     FLOAT_LITERAL = 271,
     IDENTIFIER = 272,
     INC_OP = 273,
     DEC_OP = 274,
     LE_OP = 275,
     GE_OP = 276,
     EQ_OP = 277,
     NE_OP = 278,
     MUL_ASSIGN = 279,
     DIV_ASSIGN = 280,
     MOD_ASSIGN = 281,
     ADD_ASSIGN = 282,
     SUB_ASSIGN = 283,
     CHAR = 284,
     INT = 285,
     FLOAT = 286,
     VOID = 287,
     FOR = 288,
     WHILE = 289,
     IF = 290
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 92 "ast.y"

	int ival;
	float fval;
	char cval;
	char string[128];
	struct node *ptr;


/* Line 387 of yacc.c  */
#line 240 "ast.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_AST_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 268 "ast.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,    18,     2,     2,
      47,    48,    17,    14,    49,    15,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    46,
      42,    19,    43,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,    53,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    54,    55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    12,    17,    19,    21,    24,    26,
      28,    30,    32,    34,    36,    38,    41,    45,    47,    50,
      52,    54,    57,    60,    63,    67,    71,    75,    77,    79,
      81,    83,    89,    97,   103,   105,   107,   109,   111,   113,
     117,   118,   123,   125,   127,   128,   133,   135,   137,   139,
     141,   143,   145,   147,   153,   155,   158,   160,   164,   166,
     168,   170,   172,   176,   178,   181,   184,   186,   189,   191,
     193,   195,   197,   199,   201,   203,   207,   211,   213,   217,
     221,   225,   229,   231,   235,   239,   241,   245,   249,   253,
     257,   260,   265,   269,   271,   276,   281,   285,   287,   291,
     294,   296,   298
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    -1,     3,     4,    42,    61,    43,
      58,    -1,     3,     4,    11,    58,    -1,    59,    -1,    60,
      -1,    59,    60,    -1,    66,    -1,    88,    -1,     5,    -1,
       6,    -1,     7,    -1,     8,    -1,     9,    -1,    44,    45,
      -1,    44,    63,    45,    -1,    64,    -1,    63,    64,    -1,
      66,    -1,    67,    -1,    89,    46,    -1,    13,    78,    -1,
      65,    46,    -1,    12,    42,    10,    -1,    12,    42,    79,
      -1,    70,    71,    46,    -1,    62,    -1,    78,    -1,    69,
      -1,    68,    -1,    41,    47,    79,    48,    67,    -1,    39,
      47,    78,    78,    79,    48,    67,    -1,    40,    47,    79,
      48,    67,    -1,    38,    -1,    35,    -1,    36,    -1,    37,
      -1,    72,    -1,    71,    49,    72,    -1,    -1,    23,    73,
      19,    74,    -1,    23,    -1,    77,    -1,    -1,    82,    75,
      76,    74,    -1,    19,    -1,    33,    -1,    34,    -1,    30,
      -1,    31,    -1,    32,    -1,    84,    -1,    84,    50,    79,
      51,    77,    -1,    46,    -1,    79,    46,    -1,    74,    -1,
      79,    49,    74,    -1,    23,    -1,    20,    -1,    22,    -1,
      21,    -1,    47,    79,    48,    -1,    80,    -1,    81,    24,
      -1,    81,    25,    -1,    81,    -1,    83,    82,    -1,    14,
      -1,    15,    -1,    52,    -1,    53,    -1,    54,    -1,    55,
      -1,    85,    -1,    84,    28,    85,    -1,    84,    29,    85,
      -1,    86,    -1,    85,    42,    86,    -1,    85,    43,    86,
      -1,    85,    26,    86,    -1,    85,    27,    86,    -1,    87,
      -1,    86,    14,    87,    -1,    86,    15,    87,    -1,    82,
      -1,    87,    17,    82,    -1,    87,    16,    82,    -1,    87,
      18,    82,    -1,    70,    90,    62,    -1,    90,    62,    -1,
      90,    47,    93,    48,    -1,    90,    47,    48,    -1,    23,
      -1,    90,    47,    91,    48,    -1,    90,    47,    93,    48,
      -1,    90,    47,    48,    -1,    92,    -1,    91,    49,    92,
      -1,    70,    23,    -1,    70,    -1,    23,    -1,    93,    49,
      23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   142,   143,   144,   149,   150,   155,   156,
     161,   162,   163,   164,   165,   170,   171,   176,   177,   185,
     186,   187,   188,   192,   197,   198,   203,   208,   220,   221,
     222,   228,   236,   243,   251,   252,   253,   254,   259,   260,
     265,   265,   376,   443,   444,   444,   693,   694,   695,   696,
     697,   698,   703,   704,   719,   720,   725,   726,   731,   764,
     773,   791,   809,   820,   821,   822,   827,   828,   856,   857,
     858,   859,   860,   861,   866,   867,   876,   888,   889,   898,
     907,   916,   929,   930,   935,   944,   945,   950,   964,   983,
    1001,  1028,  1029,  1034,  1041,  1042,  1043,  1048,  1049,  1054,
    1055,  1060,  1061
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HASH", "INCLUDE", "STDIO", "STDLIB",
  "MATH", "STRING", "TIME", "STRING_LITERAL", "HEADER_LITERAL", "PRINT",
  "RETURN", "'+'", "'-'", "'/'", "'*'", "'%'", "'='", "INTEGER_LITERAL",
  "CHARACTER_LITERAL", "FLOAT_LITERAL", "IDENTIFIER", "INC_OP", "DEC_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "CHAR", "INT", "FLOAT", "VOID",
  "FOR", "WHILE", "IF", "'<'", "'>'", "'{'", "'}'", "';'", "'('", "')'",
  "','", "'?'", "':'", "'!'", "'~'", "\"INC_OP\"", "\"DEC_OP\"", "$accept",
  "S", "program", "translation_unit", "ext_dec", "libraries",
  "compound_statement", "block_item_list", "block_item", "printstat",
  "declaration", "statement", "conditional_statement",
  "iteration_statement", "type_specifier", "init_declarator_list",
  "init_declarator", "$@1", "assignment_expression", "$@2",
  "assignment_operator", "conditional_expression", "expression_statement",
  "expression", "primary_expression", "postfix_expression",
  "unary_expression", "unary_operator", "equality_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "function_definition", "function_call",
  "declarator", "parameter_list", "parameter_declaration",
  "identifier_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    43,    45,    47,    42,    37,    61,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    60,    62,   123,   125,    59,    40,    41,    44,
      63,    58,    33,   126,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    65,    65,    66,    67,    67,    67,
      67,    68,    69,    69,    70,    70,    70,    70,    71,    71,
      73,    72,    72,    74,    75,    74,    76,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    86,    87,    87,    87,    87,    88,
      88,    89,    89,    90,    90,    90,    90,    91,    91,    92,
      92,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     4,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     2,     1,
       1,     2,     2,     2,     3,     3,     3,     1,     1,     1,
       1,     5,     7,     5,     1,     1,     1,     1,     1,     3,
       0,     4,     1,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     2,     1,     3,     1,     1,
       1,     1,     3,     1,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       2,     4,     3,     1,     4,     4,     3,     1,     3,     2,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    93,    35,    36,    37,    34,     0,     2,     5,
       6,     8,     0,     9,     0,     0,     1,     7,    42,     0,
      38,     0,     0,     0,    90,     0,     0,     0,    26,     0,
      89,     0,     0,    68,    69,    59,    61,    60,    58,     0,
       0,     0,    15,    54,     0,    70,    71,    72,    73,    27,
       0,    17,     0,    19,    20,    30,    29,     0,    56,    43,
      28,     0,    63,    66,    85,     0,    52,    74,    77,    82,
       0,     0,   101,    96,   100,     0,    97,     0,     4,    10,
      11,    12,    13,    14,     0,     0,    42,    39,     0,    58,
      22,     0,     0,     0,     0,    16,    18,    23,    55,     0,
      64,    65,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,    99,    94,
       0,    95,     0,     0,    41,    24,    25,     0,     0,     0,
      62,    57,    46,    49,    50,    51,    47,    48,     0,    85,
      75,    76,     0,    80,    81,    78,    79,    83,    84,    87,
      86,    88,    92,     0,    98,   102,     3,     0,     0,     0,
      45,     0,    91,     0,    33,    31,    53,     0,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    84,    49,    50,    51,    52,
      11,    54,    55,    56,    12,    19,    20,    27,    58,   102,
     138,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    13,    70,    14,    75,    76,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -147
static const yytype_int16 yypact[] =
{
      43,    32,  -147,  -147,  -147,  -147,  -147,    45,  -147,    89,
    -147,  -147,    20,  -147,   -13,    -5,  -147,  -147,    48,   -23,
    -147,   -13,    96,   182,  -147,    43,    11,    28,  -147,    29,
    -147,    60,    68,  -147,  -147,  -147,  -147,  -147,    83,   119,
     141,   146,  -147,  -147,   142,  -147,  -147,  -147,  -147,  -147,
     132,  -147,   152,  -147,  -147,  -147,  -147,    29,  -147,  -147,
    -147,   112,  -147,    62,   206,   142,   -20,    42,    79,   174,
     170,   161,  -147,  -147,   218,    49,  -147,    80,  -147,  -147,
    -147,  -147,  -147,  -147,   192,   142,   228,  -147,    18,  -147,
    -147,    68,   142,   142,    90,  -147,  -147,  -147,  -147,   142,
    -147,  -147,   212,  -147,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,  -147,   186,  -147,  -147,
      39,  -147,   225,    43,  -147,  -147,   200,    68,   111,   154,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,   142,  -147,
      42,    42,   -24,    79,    79,    79,    79,   174,   174,  -147,
    -147,  -147,   203,   162,  -147,  -147,  -147,   142,   160,   160,
    -147,   142,   204,   178,  -147,  -147,  -147,   160,  -147
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   -22,  -147,   243,  -147,     1,  -147,   205,  -147,
     -15,  -146,  -147,  -147,   -21,  -147,   224,  -147,   -75,  -147,
    -147,    93,   -27,   -44,  -147,  -147,   -54,  -147,  -147,   124,
      -4,   121,  -147,  -147,    -8,  -147,   136,   140
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -97
static const yytype_int16 yytable[] =
{
      94,    57,    74,    78,    21,    90,    25,    53,   104,   105,
     124,   103,   164,   165,    71,    24,    79,    80,    81,    82,
      83,   168,    30,    28,   131,    99,    29,   161,   125,    57,
     106,    22,    33,    34,    23,    53,    15,    26,    35,    36,
      37,    89,    71,    18,   126,    16,     1,    85,   128,   129,
     139,   139,    86,   139,   139,   139,   139,   139,   139,   149,
     150,   151,   142,   160,   127,    44,     2,   -40,   107,   108,
      45,    46,    47,    48,     3,     4,     5,     6,     3,     4,
       5,     6,    33,    34,   109,   110,   100,   101,    35,    36,
      37,    89,   -93,   111,   112,   -93,    74,   119,   120,    74,
     157,   156,    88,   143,   144,   145,   146,   139,    31,    32,
      33,    34,     2,   163,    43,    44,    35,    36,    37,    38,
      45,    46,    47,    48,     3,     4,     5,     6,   121,   122,
     -93,     3,     4,     5,     6,    39,    40,    41,   130,    99,
      22,    42,    43,    44,    31,    32,    33,    34,    45,    46,
      47,    48,    35,    36,    37,    38,    33,    34,    98,   158,
      99,    99,    35,    36,    37,    89,    91,     3,     4,     5,
       6,    39,    40,    41,    33,    34,    22,    95,    43,    44,
      35,    36,    37,    89,    45,    46,    47,    48,    92,    44,
     113,   114,   115,    93,    45,    46,    47,    48,    97,    39,
      40,    41,   159,    99,    22,    72,    43,    44,   117,    72,
     162,   122,    45,    46,    47,    48,   116,     3,     4,     5,
       6,     3,     4,     5,     6,   -44,   167,    99,   140,   141,
      73,   132,   147,   148,   152,   123,   -44,   -44,   -44,   -44,
     -44,   118,   133,   134,   135,   136,   137,   -40,   155,    99,
     -96,   -95,    17,    87,   166,    96,   154,   153
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-147)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      44,    22,    23,    25,    12,    32,    11,    22,    28,    29,
      85,    65,   158,   159,    22,    14,     5,     6,     7,     8,
       9,   167,    21,    46,    99,    49,    49,    51,    10,    50,
      50,    44,    14,    15,    47,    50,     4,    42,    20,    21,
      22,    23,    50,    23,    88,     0,     3,    19,    92,    93,
     104,   105,    23,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   106,   138,    91,    47,    23,    19,    26,    27,
      52,    53,    54,    55,    35,    36,    37,    38,    35,    36,
      37,    38,    14,    15,    42,    43,    24,    25,    20,    21,
      22,    23,    44,    14,    15,    47,   117,    48,    49,   120,
     127,   123,    42,   107,   108,   109,   110,   161,    12,    13,
      14,    15,    23,   157,    46,    47,    20,    21,    22,    23,
      52,    53,    54,    55,    35,    36,    37,    38,    48,    49,
      47,    35,    36,    37,    38,    39,    40,    41,    48,    49,
      44,    45,    46,    47,    12,    13,    14,    15,    52,    53,
      54,    55,    20,    21,    22,    23,    14,    15,    46,    48,
      49,    49,    20,    21,    22,    23,    47,    35,    36,    37,
      38,    39,    40,    41,    14,    15,    44,    45,    46,    47,
      20,    21,    22,    23,    52,    53,    54,    55,    47,    47,
      16,    17,    18,    47,    52,    53,    54,    55,    46,    39,
      40,    41,    48,    49,    44,    23,    46,    47,    47,    23,
      48,    49,    52,    53,    54,    55,    46,    35,    36,    37,
      38,    35,    36,    37,    38,    19,    48,    49,   104,   105,
      48,    19,   111,   112,    48,    43,    30,    31,    32,    33,
      34,    23,    30,    31,    32,    33,    34,    19,    23,    49,
      47,    47,     9,    29,   161,    50,   120,   117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    23,    35,    36,    37,    38,    57,    58,    59,
      60,    66,    70,    88,    90,     4,     0,    60,    23,    71,
      72,    90,    44,    47,    62,    11,    42,    73,    46,    49,
      62,    12,    13,    14,    15,    20,    21,    22,    23,    39,
      40,    41,    45,    46,    47,    52,    53,    54,    55,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    74,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      89,    90,    23,    48,    70,    91,    92,    93,    58,     5,
       6,     7,     8,     9,    61,    19,    23,    72,    42,    23,
      78,    47,    47,    47,    79,    45,    64,    46,    46,    49,
      24,    25,    75,    82,    28,    29,    50,    26,    27,    42,
      43,    14,    15,    16,    17,    18,    46,    47,    23,    48,
      49,    48,    49,    43,    74,    10,    79,    78,    79,    79,
      48,    74,    19,    30,    31,    32,    33,    34,    76,    82,
      85,    85,    79,    86,    86,    86,    86,    87,    87,    82,
      82,    82,    48,    93,    92,    23,    58,    78,    48,    48,
      74,    51,    48,    79,    67,    67,    77,    48,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 128 "ast.y"
    {
				/*
				Todo: 
				Write a function to clean symbol symbol. Remove entries with dtype = -1. 
				Or just don't print it in symbol table
				cleansymbol();
				*/
				cleansymbol();	//I wrote a function already to remove dtype = -1
                printsymtable();
                return 0;
            }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 178 "ast.y"
    {
				create_node("stmt", 0);
			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 189 "ast.y"
    {
				create_node("return", 1);
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 208 "ast.y"
    {
						struct node *ftp;
						ftp = first;
						while(ftp!=NULL){
							if(ftp->scope == scope && ftp->valid == 1){
								ftp->valid = 0;
							}
							ftp=ftp->link;
						}
						scope--;

					}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 229 "ast.y"
    {
			create_node("if", 0);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 237 "ast.y"
    { 
				// create_node("cond", 0); 
				// create_node("body", 0);
				create_node("for", 0); 
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 244 "ast.y"
    {
				create_node("while", 0);
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 251 "ast.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 252 "ast.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 253 "ast.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 254 "ast.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 265 "ast.y"
    { create_node((yyvsp[(1) - (1)].ptr)->name, 1); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 266 "ast.y"
    {	


						if((yyvsp[(1) - (4)].ptr)->dtype !=- 1 && (yyvsp[(1) - (4)].ptr)->scope < scope && (yyvsp[(1) - (4)].ptr)->valid == 1){
							// printf("case 1 \n" );
																		
							struct node *ftp, *nnode;
							nnode = (struct node *)malloc(sizeof(struct node));
							ftp = first;
							while(ftp->link!=NULL){
								ftp = ftp->link;
							}
							addsymbol(nnode,(yyvsp[(1) - (4)].ptr)->name);	
							ftp->link = nnode;
							nnode->link = NULL;
							(yyvsp[(1) - (4)].ptr) = nnode;

							if (datatype == 0){	
								
								addInt((yyvsp[(1) - (4)].ptr), 0, (yyvsp[(4) - (4)].fval));
								if(assigntype == 1){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'float\' to \'int\' \n\n");
								}
							}
							else if(datatype == 1){
								
								addFloat((yyvsp[(1) - (4)].ptr), 1, (yyvsp[(4) - (4)].fval));
								if(assigntype == 2){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'char\' to \'float\' \n\n");
								}
							}
							else if(datatype == 2){
								float tempf = (float)(yyvsp[(4) - (4)].fval);
								addChar((yyvsp[(1) - (4)].ptr), 2, (int)tempf);

								if(assigntype == 1){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'float\' to \'char\' \n\n");
								}
							}
							x = datatype;
							
							create_node("=", 0);

						}

						
						else if((yyvsp[(1) - (4)].ptr)->dtype !=- 1){

								printf("Line:%d: ", line);
								printf("\033[1;31m");
								printf("error: ");
								printf("\033[0m");
								printf("redefinition of \'%s\' \n",  (yyvsp[(1) - (4)].ptr)->name);
						}
						else{
							
							
							create_node("=", 0);

							if (datatype == 0){	
								
								addInt((yyvsp[(1) - (4)].ptr), 0, (yyvsp[(4) - (4)].fval));
								if(assigntype == 1){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'float\' to \'int\' \n\n");
								}
							}
							else if(datatype == 1){
								
								addFloat((yyvsp[(1) - (4)].ptr), 1, (yyvsp[(4) - (4)].fval));
								if(assigntype == 2){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'char\' to \'float\' \n\n");
								}
							}
							else if(datatype == 2){
								float tempf = (float)(yyvsp[(4) - (4)].fval);
								addChar((yyvsp[(1) - (4)].ptr), 2, (int)tempf);

								if(assigntype == 1){
									printf("Line:%d: ", line);
									printf("\033[1;35m"); 
									printf("warning: ");
									printf("\033[0m");
									printf("implicit conversion from \'float\' to \'char\' \n\n");
								}
							}
							x = datatype;
							
						}
					}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 376 "ast.y"
    {	//previous. a , dtype = 1(int)
						// printf("type = %d\nscope = %d\nvalid = %d", $1->dtype, $1->scope, $1->valid);
						if((yyvsp[(1) - (1)].ptr)->dtype !=- 1 && (yyvsp[(1) - (1)].ptr)->scope < scope && (yyvsp[(1) - (1)].ptr)->valid == 1){
							// printf("case 1 \n" );
																		
							struct node *ftp, *nnode;
							nnode = (struct node *)malloc(sizeof(struct node));
							ftp = first;
							while(ftp->link!=NULL){
								ftp = ftp->link;
							}
							addsymbol(nnode,(yyvsp[(1) - (1)].ptr)->name);	
							ftp->link = nnode;
							nnode->link = NULL;							
							(yyvsp[(1) - (1)].ptr) = nnode;
							
							if (datatype == 0){	
								addInt((yyvsp[(1) - (1)].ptr), 0, INT_MIN);
							}
							else if(datatype == 1){
								addFloat((yyvsp[(1) - (1)].ptr), 1, INT_MIN);
							}
							else if(datatype == 2){
								addChar((yyvsp[(1) - (1)].ptr), 2, '-');
		
							}
							x = datatype;

							char buff[20];
							strcpy(buff, "Dc ");
							strcat(buff, (yyvsp[(1) - (1)].ptr)->name);
							create_node(buff, 1);

						}
						else if((yyvsp[(1) - (1)].ptr)->dtype !=- 1 ){
							printf("Line:%d: ", line);
							printf("\033[1;31m");
							printf("error: ");
							printf("\033[0m");
							printf("redefinition of \'%s\' \n", (yyvsp[(1) - (1)].ptr)->name);
						
						}else{
							

							if (datatype == 0){	
								addInt((yyvsp[(1) - (1)].ptr), 0, INT_MIN);
							}
							else if(datatype == 1){
								addFloat((yyvsp[(1) - (1)].ptr), 1, INT_MIN);
							}
							else if(datatype == 2){
								addChar((yyvsp[(1) - (1)].ptr), 2, '-');
		
							}
							x = datatype;

							char buff[20];
							strcpy(buff, "Dc ");
							strcat(buff, (yyvsp[(1) - (1)].ptr)->name);
							create_node(buff, 1);
						
						}
					}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 443 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 444 "ast.y"
    { crt = lhs; }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 445 "ast.y"
    {							
				switch(assignop){
					case 0: if(idcheck == 1){
								create_node("=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[(4) - (4)].fval);
									
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 1: if(idcheck == 1){
								create_node("+=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) + (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[(1) - (4)].fval)+ (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) + (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 2:	if(idcheck == 1){
							create_node("-=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) - (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[(1) - (4)].fval) - (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) - (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 3:	if(idcheck == 1){
								create_node("*=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) * (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[(1) - (4)].fval) * (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) * (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 4:	if(idcheck == 1){
								create_node("/=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) / (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (yyvsp[(1) - (4)].fval) / (yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) / (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;

					case 5:	if(idcheck == 1){
								create_node("%=", 0);
								if(crt->dtype == 0){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'int\' \n\n");
									}
									crt->val.i = (int)(yyvsp[(1) - (4)].fval) % (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 1){
									if(assigntype == 2){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'char\' to \'float\' \n\n");
									}
									crt->val.f = (int)(yyvsp[(1) - (4)].fval) % (int)(yyvsp[(4) - (4)].fval);
								}
								else if(crt->dtype == 2){
									if(assigntype == 1){
										printf("Line:%d: ", line);
										printf("\033[1;35m"); 
										printf("warning: ");
										printf("\033[0m");
										printf("implicit conversion from \'float\' to \'char\' \n\n");
									}
									crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) % (int)(yyvsp[(4) - (4)].fval));
								}
							}
							else{
								printf("We'll see later\n");
							}
							crt = NULL;
							break;


				}
				assignop = -1;
				assigntype = -1;
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 693 "ast.y"
    {	assignop = 0;	}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 694 "ast.y"
    {	assignop = 1;	}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 695 "ast.y"
    {	assignop = 2;	}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 696 "ast.y"
    {	assignop = 3;	}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 697 "ast.y"
    {	assignop = 4;	}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 698 "ast.y"
    {	assignop = 5;	}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 703 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 705 "ast.y"
    {
				create_node("else", 0);
				create_node("if", 0);
				if((yyvsp[(1) - (5)].fval) == 1){
					(yyval.fval) = (yyvsp[(3) - (5)].fval);

				}else{
					(yyval.fval) = (yyvsp[(5) - (5)].fval);
				}
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 719 "ast.y"
    {				}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 720 "ast.y"
    {				}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 725 "ast.y"
    {		}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 726 "ast.y"
    {		}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 732 "ast.y"
    {					
					idcheck = 1;
					lhs = (yyvsp[(1) - (1)].ptr);
					if((yyvsp[(1) - (1)].ptr)->dtype == -1){

						printf("Line:%d: ", line);
						printf("\033[1;31m");
						printf("error: ");
						printf("\033[0m");
						printf("use of undeclared identifier \'%s\' \n\n", (yyvsp[(1) - (1)].ptr)->name);

						check_un = 0;		// set check_un = -1

					}
					else if((yyvsp[(1) - (1)].ptr)->dtype == 0){
						(yyval.fval) = (yyvsp[(1) - (1)].ptr)->val.i;
						assigntype = 0;
						create_node((yyvsp[(1) - (1)].ptr)->name, 1);
					}
					else if((yyvsp[(1) - (1)].ptr)->dtype == 1){
						(yyval.fval) = (yyvsp[(1) - (1)].ptr)->val.f;
						assigntype = 1;
						create_node((yyvsp[(1) - (1)].ptr)->name, 1);
					}
					else if((yyvsp[(1) - (1)].ptr)->dtype == 2){
						(yyval.fval) = (yyvsp[(1) - (1)].ptr)->val.c;
						assigntype = 2;
						create_node((yyvsp[(1) - (1)].ptr)->name, 1);
					}
						
									
				}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 765 "ast.y"
    {
					(yyval.fval) = (yyvsp[(1) - (1)].ival);
					assigntype = 0;
				
					sprintf(tempStr, "%d", (int)(yyvsp[(1) - (1)].ival));
					create_node(tempStr, 1);
				}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 774 "ast.y"
    {	
					assigntype = 1;
					if(datatype == 1){
						(yyval.fval) = (yyvsp[(1) - (1)].fval);
					}
					else if(datatype == 0){
						
						(yyval.fval) = (int)(yyvsp[(1) - (1)].fval);
					}
					else if(datatype == 2){

						(yyval.fval) = (int)(yyvsp[(1) - (1)].fval);
					}

					sprintf(tempStr, "%f", (yyvsp[(1) - (1)].fval));
					create_node(tempStr, 1);
				}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 792 "ast.y"
    {	
					assigntype = 2;
					if(datatype == 2){
						int tempc = (int)(yyvsp[(1) - (1)].cval);
						(yyval.fval) =  (float)tempc;
					}
					else if(datatype == 0){
						(yyval.fval) = (int)(yyvsp[(1) - (1)].cval);
					}
					else if(datatype == 1){
						
						(yyval.fval) = (int)(yyvsp[(1) - (1)].cval);
					}

					sprintf(tempStr, "%c", (yyvsp[(1) - (1)].cval));
					create_node(tempStr, 1);
				}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 810 "ast.y"
    {
					(yyval.fval) = (yyvsp[(2) - (3)].fval);
				}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 820 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 821 "ast.y"
    {	(yyvsp[(1) - (2)].fval)++; (yyval.fval) = (yyvsp[(1) - (2)].fval);	create_node("++", 0); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 822 "ast.y"
    {	(yyvsp[(1) - (2)].fval)--; (yyval.fval) = (yyvsp[(1) - (2)].fval);	create_node("--", 0); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 827 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 829 "ast.y"
    {
					switch(unaryop){
						case 1:	(yyval.fval) = (yyvsp[(2) - (2)].fval);
								create_node("'+'", 0);
								break;
						case 2:	(yyval.fval) = -(yyvsp[(2) - (2)].fval);
								create_node("'+'", 0);
								break;
						case 3:	(yyval.fval) = !(yyvsp[(2) - (2)].fval);
								create_node("!", 0);
								break;
						case 4:	(yyval.fval) = ~((int)(yyvsp[(2) - (2)].fval));
								create_node("~", 0);
								break;	
						case 5:	(yyval.fval) = ++(yyvsp[(2) - (2)].fval);
								create_node("++", 0);							
								break;
						case 6:	(yyval.fval) = --(yyvsp[(2) - (2)].fval);
								create_node("--", 0);
								break;		
					}
					unaryop = -1;
				}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 856 "ast.y"
    {	unaryop = 1;	}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 857 "ast.y"
    {	unaryop = 2;	}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 858 "ast.y"
    {	unaryop = 3;	}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 859 "ast.y"
    {	unaryop = 4;	}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 860 "ast.y"
    {	unaryop = 5;	}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 861 "ast.y"
    {	unaryop = 6;	}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 866 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 868 "ast.y"
    { 
					create_node("==", 0);
					if((yyvsp[(1) - (3)].fval) == (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 877 "ast.y"
    { 
					create_node("!=", 0);
					if((yyvsp[(1) - (3)].fval) != (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;
				}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 888 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 890 "ast.y"
    { 
					create_node("<", 0);
					if((yyvsp[(1) - (3)].fval) < (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 899 "ast.y"
    { 
					create_node(">", 0);
					if((yyvsp[(1) - (3)].fval) > (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 908 "ast.y"
    { 
					create_node("<=", 0);
					if((yyvsp[(1) - (3)].fval) <= (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 917 "ast.y"
    { 
					create_node(">=", 0);
					if((yyvsp[(1) - (3)].fval) >= (yyvsp[(3) - (3)].fval))
						(yyval.fval) = 1;
					else
						(yyval.fval) = 0;

				}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 929 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 931 "ast.y"
    {	
				create_node("+", 0);
				(yyval.fval) = (yyvsp[(1) - (3)].fval) + (yyvsp[(3) - (3)].fval);	
			}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 936 "ast.y"
    {	
				create_node("-", 0);
				(yyval.fval) = (yyvsp[(1) - (3)].fval) - (yyvsp[(3) - (3)].fval);	
			}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 944 "ast.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 946 "ast.y"
    {	
						create_node("*", 0);	
						(yyval.fval) = (yyvsp[(1) - (3)].fval) * (yyvsp[(3) - (3)].fval);	
					}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 951 "ast.y"
    {	
						if((yyvsp[(3) - (3)].fval) == 0){
							printf("Line:%d: ", line);
							printf("\033[1;35m"); 
							printf("warning: ");
							printf("\033[0m");
							printf("division by zero is undefined\n\n");
							(yyval.fval) = INT_MAX;		//junk value in real
						}else{
							(yyval.fval) = (yyvsp[(1) - (3)].fval) / (yyvsp[(3) - (3)].fval);	
							create_node("/", 0);
						}
					}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 965 "ast.y"
    {	
						if(assigntype == 1){
							printf("Line:%d: ", line);
							printf("\033[1;31m");
							printf("error: ");
							printf("\033[0m");
							printf("invalid operands to binary expression (\'float\' and \'float\') \n\n");
							}else{								
								(yyval.fval) = (int)(yyvsp[(1) - (3)].fval) % (int)(yyvsp[(3) - (3)].fval);	
								create_node("%", 0);
							}
						}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 984 "ast.y"
    {
					create_node((yyvsp[(2) - (3)].string), 3);
					struct node *ftp;
					ftp = first;
					while(ftp!=NULL){
						if(ftp->scope == scope && ftp->valid == 1){
							ftp->valid = 0;
						}
						else if(strcmp(ftp->token, "param") == 0 && ftp->valid == 1){
							ftp->valid = 0;
						}

						ftp=ftp->link;
					}
					scope--;

				}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 1002 "ast.y"
    {	
					create_node((yyvsp[(1) - (2)].string), 3);
					printf("Line:%d: ", line);
					printf("\033[1;35m"); 
					printf("warning: ");
					printf("\033[0m");
					printf("type specifier missing, defaults to \'int\' \n");

					struct node *ftp;
					ftp = first;
					while(ftp!=NULL){
						if(ftp->scope == scope && ftp->valid == 1){
							ftp->valid = 0;
						}
						else if(strcmp(ftp->token, "param") == 0 && ftp->valid == 1){
							ftp->valid = 0;
						}

						ftp=ftp->link;
					}
					scope--;
				}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 1035 "ast.y"
    {	
					// printf("OKAY : %s\n", $1->name);
					// create_node($1->name, 1);
					addfunc((yyvsp[(1) - (1)].ptr), datatype, "function");	
					strcpy((yyval.string), (yyvsp[(1) - (1)].ptr)->name); 								
				}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 1041 "ast.y"
    { }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1042 "ast.y"
    { }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 1043 "ast.y"
    { }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 1048 "ast.y"
    {}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 1049 "ast.y"
    {}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1054 "ast.y"
    {	addfunc((yyvsp[(2) - (2)].ptr), datatype, "param");	}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 1055 "ast.y"
    {}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1060 "ast.y"
    {		}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 1061 "ast.y"
    {		}
    break;


/* Line 1792 of yacc.c  */
#line 2737 "ast.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 1065 "ast.y"



void yyerror(const char *str){
	fflush(stdout);
	printf("Line:%d: ", line);
	printf("\033[1;31m");
	printf("error: ");
	printf("\033[0m");
	printf("%s\n", str);
}


int main(){
	yyin = fopen("input.c", "r");
	yyout = fopen("output.c", "w");


	tree_top = (tree_stack*)malloc(sizeof(tree_stack));
	tree_top->node = NULL;
	tree_top->next = NULL;
	struct Node *root;

	printf("\n");
	yyparse();

	root = pop_tree();
	get_levels(root, 1);

	printtree(root);
	

	preorder(root);
	printf("\n\nPreorder Traversal\n\n");
	printf("%s\n", preBuf);

	fclose(yyout);
	return 0;
}


void addfunc(struct node *t,int type, char *s){
	if(t->dtype == -1) {
        t->dtype = type;
        t->val.i = 0;
        strcpy(t->token, s);
    }
}


void addInt(struct node *t,int type,int val) {
    if(t->dtype == -1) {
        t->dtype = type;
        t->val.i = val;
        strcpy(t->token, "identifier");
    }
}


void addFloat(struct node *t,int type,float val) {
    if(t->dtype == -1) {
        t->dtype = type;
        t->val.f = (float)val;
        strcpy(t->token, "identifier");
    }
}


void addChar(struct node *t,int type, char val) {
   	if(t->dtype == -1) {
   	    t->dtype = type;
   	    t->val.c = (char)val;
   	    strcpy(t->token, "identifier");
   	}
}


struct node * addtosymbol(struct node * n){
	if(first == NULL){
		first = n;
	}
	else{
		struct  node * ftp = first;
		while(ftp->link !=NULL) {
			ftp = ftp->link;
		}
		ftp->link = n;
	}
	return n;
}


struct node * checksym(char *vname) {
	struct node *ftp;
	struct node *rp;
	struct node *nnode;
	struct node *same;

	//not memory efficient
	// nnode = (struct node *)malloc(sizeof(struct node));
	// addsymbol(nnode,vname);


	if(first == NULL) {
		nnode = (struct node *)malloc(sizeof(struct node));
		addsymbol(nnode,vname);
	    first = nnode;
	}
	else {
	    ftp = first;
	    while(ftp!=NULL) {

	        if(strcmp(vname,ftp->name) == 0){
	            if(ftp->scope > scope && ftp->valid == 1) {	          	
					same = ftp; 
	            	return same;
	            }	
	            else if(ftp->scope == scope && ftp->valid == 1){
	            	same = ftp;
	            	return same;
	            }          	
	            else if(ftp->scope < scope && ftp->valid == 1){
	         		check_un = 1;	//no error 

	         		same = ftp;
	            	return same;
	         			            		         				         		       	         
	            } 
	          	else if(ftp->scope > scope && ftp->valid == 0){
	          		check_un = 0;	//undeclared
	          	}

	        }            
	        rp = ftp;
	        ftp = ftp->link;
	    }
	    nnode = (struct node *)malloc(sizeof(struct node));
		addsymbol(nnode,vname);

	    rp->link = nnode;
	}
	return nnode;
}


void addsymbol(struct node *tp, char *vname) {
    strcpy(tp->name,vname);
    tp->dtype = -1;
    tp->link = NULL;
    tp->scope = scope;
    tp->valid = 1;
    tp->lineno = line;
}


void cleansymbol(){
	struct node** pp = &first; 
    while (*pp) { 
  
        struct node* entry = *pp; 
 
        if (entry->dtype == -1  ) { 
            *pp = entry->link; 
            free(entry); 
        }
        else if(strcmp(entry->name,"main")== 0 && strcmp(entry->token, "function")==0){	//remove main entry from symbol table
        	*pp = entry->link; 
            free(entry); 
        }
        // Else move to next 
        else
            pp = &(entry->link); 
    } 
}


void printsymtable(){
	struct node *ftp;
    ftp=first;
    //blue
    printf("\n\nSymbol Table\n\n");
    //white

	printf("   Symbol\t\tName\t  Type\t      Scope\t   Line Number\t       Value \n");
	printf("-------------------------------------------------------------------------------------------------\n");
   
    while(ftp!=NULL) {
        char data_type[10];
        if(ftp->dtype==0)
        	strcpy(data_type,"int");
        if(ftp->dtype==1)
        	strcpy(data_type,"float");
        if(ftp->dtype==2)
        	strcpy(data_type,"char");
        if(ftp->dtype==3)
        	strcpy(data_type,"void");

        printf("%11s\t%12s\t%6s\t\t%d\t\t%d\t\t",ftp->token, ftp->name, data_type, ftp->scope, ftp->lineno);

        if(ftp->dtype == 0){
        	if(ftp->val.i == INT_MIN)
        		printf("-\n");
        	else
           		printf("%d\n",ftp->val.i);
        }
        else if(ftp->dtype == 1){
        	if(ftp->val.f == INT_MIN)
        		printf("-\n");
        	else
           		printf("%f\n",ftp->val.f);
       	}
        else if(ftp->dtype == 2){
            printf("%c\n",ftp->val.c);
        }
        else if(strcmp(ftp->token, "function")==0){
        	printf("-\n");
        }
        else{
	        printf("-	Delete it\n");
	    }
        ftp=ftp->link;
    }
    printf("\n\n\n");
}


void create_node(char *token, int leaf) {
	Node *l;
	Node *r;
	if(leaf==0) {

		r = pop_tree();
		l = pop_tree();
	}
	else if(leaf ==1) {
		l = NULL;
		r = NULL;
	}
	else {
		l = pop_tree();
		r = NULL;
	}

	Node *newnode = (Node*)malloc(sizeof(Node));
	strcpy(newnode->token, token);
	newnode->left = l;
	newnode->right = r;
	push_tree(newnode);
}


void push_tree(Node *newnode){
	tree_stack *temp= (tree_stack*)malloc(sizeof(tree_stack));
	temp->node = newnode;
	temp->next = tree_top;
	tree_top = temp;
}


Node* pop_tree(){
	tree_stack *temp = tree_top;
	tree_top = tree_top->next;
	Node *retnode = temp->node;
	if(temp != NULL)
		free(temp);
	return retnode;
}


void printtree(Node* root){
    int h = getmaxlevel(root)-1;
    int i;
	printf("\n\nAbstract Syntax Tree\n\n");

    for (i=1; i<=h; i++){
		printf("\t");
		int j;
		for(j=0;j<=h+1-i;j++){
			printf("      ");
		}
        printGivenLevel(root, i,h);

        printf("\n\n\n");
    }
}


int getmaxlevel(Node *root){
	int count=0;
	Node *temp= root;
	while(temp->left!=NULL){
		count++;
		temp=temp->left;
	}
	return count*2;
}


void printGivenLevel(Node* root, int level, int h){
    if (root == NULL)
        return;
    if (level == 1){
    	int j;
		for(j=0; j<=h-1-level-6; j++){
			printf(" ");
		}
	    printf("%s ", root->token);
	}
    else if (level > 1){
        printGivenLevel(root->left, level-1,h);
        int j;
		for(j=0; j<=h-1-level-6; j++){
			printf(" ");
		}
        printGivenLevel(root->right, level-1,h);
    }
}


void preorder(Node * node){
	if (node == NULL)
		return;

	if(node->left!=NULL && node->right!=NULL)
		strcat(preBuf, "   ( ");
	strcat(preBuf, node->token);
	strcat(preBuf, "   ");

	preorder(node-> left);

	
	if(node->right){
		preorder(node-> right);
	}
	
	if(node->left!=NULL && node->right!=NULL)
		strcat(preBuf, ")   ");
	// printf("\n");
	
}

void get_levels(Node *root, int level){
	root->level = level;
	if(root->left == NULL && root->right == NULL){
		return;
	}
	if(root->left == NULL){
		get_levels(root->right, level+1);
	}
	else if(root->right == NULL){
		get_levels(root->left, level+1);
	}
	else{
		get_levels(root->left, level+1);
		get_levels(root->right, level+1);
	}
}
