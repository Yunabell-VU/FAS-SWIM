/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_EXPRESSIONYY_EXPRESSION_TAB_HH_INCLUDED
# define YY_EXPRESSIONYY_EXPRESSION_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int expressionyydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TRUE_ = 258,
    FALSE_ = 259,
    NAN_ = 260,
    INF_ = 261,
    UNDEFINED_ = 262,
    NULLPTR_ = 263,
    NULL_ = 264,
    NAME = 265,
    INTCONSTANT = 266,
    REALCONSTANT = 267,
    STRINGCONSTANT = 268,
    EQ = 269,
    NE = 270,
    GE = 271,
    LE = 272,
    SPACESHIP = 273,
    AND = 274,
    OR = 275,
    XOR = 276,
    SHIFT_LEFT = 277,
    SHIFT_RIGHT = 278,
    DOUBLECOLON = 279,
    INVALID_CHAR = 280,
    MATCH = 281,
    UMIN_ = 282,
    NEG_ = 283,
    NOT_ = 284
  };
#endif
/* Tokens.  */
#define TRUE_ 258
#define FALSE_ 259
#define NAN_ 260
#define INF_ 261
#define UNDEFINED_ 262
#define NULLPTR_ 263
#define NULL_ 264
#define NAME 265
#define INTCONSTANT 266
#define REALCONSTANT 267
#define STRINGCONSTANT 268
#define EQ 269
#define NE 270
#define GE 271
#define LE 272
#define SPACESHIP 273
#define AND 274
#define OR 275
#define XOR 276
#define SHIFT_LEFT 277
#define SHIFT_RIGHT 278
#define DOUBLECOLON 279
#define INVALID_CHAR 280
#define MATCH 281
#define UMIN_ 282
#define NEG_ 283
#define NOT_ 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "expression.y"

  const char *str;
  AstNode *node;

#line 120 "expression.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE expressionyylval;

int expressionyyparse (AstNode *&resultAstTree);

#endif /* !YY_EXPRESSIONYY_EXPRESSION_TAB_HH_INCLUDED  */
