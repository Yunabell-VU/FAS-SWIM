/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

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

#ifndef YY_NED2YY_NED2_TAB_HH_INCLUDED
# define YY_NED2YY_NED2_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int ned2yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IMPORT = 258,
    PACKAGE = 259,
    PROPERTY = 260,
    MODULE = 261,
    SIMPLE = 262,
    NETWORK = 263,
    CHANNEL = 264,
    MODULEINTERFACE = 265,
    CHANNELINTERFACE = 266,
    EXTENDS = 267,
    LIKE = 268,
    TYPES = 269,
    PARAMETERS = 270,
    GATES = 271,
    SUBMODULES = 272,
    CONNECTIONS = 273,
    ALLOWUNCONNECTED = 274,
    DOUBLE_ = 275,
    INT_ = 276,
    STRING_ = 277,
    BOOL_ = 278,
    OBJECT_ = 279,
    XML_ = 280,
    VOLATILE_ = 281,
    INPUT_ = 282,
    OUTPUT_ = 283,
    INOUT_ = 284,
    IF = 285,
    FOR = 286,
    RIGHTARROW = 287,
    LEFTARROW = 288,
    DBLARROW = 289,
    TO = 290,
    THIS_ = 291,
    PARENT = 292,
    DEFAULT = 293,
    ASK = 294,
    CONST_ = 295,
    SIZEOF = 296,
    INDEX_ = 297,
    EXISTS = 298,
    TYPENAME = 299,
    XMLDOC = 300,
    TRUE_ = 301,
    FALSE_ = 302,
    NAN_ = 303,
    INF_ = 304,
    UNDEFINED_ = 305,
    NULLPTR_ = 306,
    NULL_ = 307,
    NAME = 308,
    PROPNAME = 309,
    INTCONSTANT = 310,
    REALCONSTANT = 311,
    STRINGCONSTANT = 312,
    CHARCONSTANT = 313,
    PLUSPLUS = 314,
    DOUBLEASTERISK = 315,
    EQ = 316,
    NE = 317,
    GE = 318,
    LE = 319,
    SPACESHIP = 320,
    AND = 321,
    OR = 322,
    XOR = 323,
    SHIFT_LEFT = 324,
    SHIFT_RIGHT = 325,
    DOUBLECOLON = 326,
    EXPRESSION_SELECTOR = 327,
    COMMONCHAR = 328,
    INVALID_CHAR = 329,
    MATCH = 330,
    UMIN_ = 331,
    NEG_ = 332,
    NOT_ = 333
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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


extern YYSTYPE ned2yylval;
extern YYLTYPE ned2yylloc;
int ned2yyparse (omnetpp::nedxml::ParseContext *np);

#endif /* !YY_NED2YY_NED2_TAB_HH_INCLUDED  */
