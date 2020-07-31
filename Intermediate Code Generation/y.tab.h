/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 40 "InterCodeGen.y" /* yacc.c:1909  */
	
	char sval[300];

#line 134 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
