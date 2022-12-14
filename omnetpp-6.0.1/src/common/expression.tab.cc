/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         expressionyyparse
#define yylex           expressionyylex
#define yyerror         expressionyyerror
#define yydebug         expressionyydebug
#define yynerrs         expressionyynerrs

#define yylval          expressionyylval
#define yychar          expressionyychar

/* First part of user prologue.  */
#line 17 "expression.y"


#include <cmath>
#include <cstdio>
#include <cstdlib>
#include "commonutil.h"
#include "expressionyydefs.h"

#define YYDEBUG 1           /* allow debugging */
#define YYDEBUGGING_ON 0    /* turn on/off debugging */

#if YYDEBUG != 0
#define YYERROR_VERBOSE     /* more detailed error messages */
#include <cstring>         /* YYVERBOSE needs it */
#endif

#include "expression.h"
#include "exception.h"
#include "stringutil.h"
#include "unitconversion.h"

using namespace omnetpp;
using namespace omnetpp::common;
using namespace omnetpp::common::expression;

typedef Expression::AstNode AstNode;
typedef Expression::AstNode::Type AstNodeType;

namespace omnetpp { class cObject; };


#line 110 "expression.tab.cc"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 216 "expression.tab.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE expressionyylval;

int expressionyyparse (AstNode *&resultAstTree);

#endif /* !YY_EXPRESSIONYY_EXPRESSION_TAB_HH_INCLUDED  */

/* Second part of user prologue.  */
#line 90 "expression.y"

#define yyin expressionyyin
#define yyout expressionyyout
#define yyrestart expressionyyrestart
#define yy_scan_string expressionyy_scan_string
#define yy_delete_buffer expressionyy_delete_buffer
extern FILE *yyin;
extern FILE *yyout;
struct yy_buffer_state;
struct yy_buffer_state *yy_scan_string(const char *str);
void yy_delete_buffer(struct yy_buffer_state *);
void yyrestart(FILE *);
int yylex();
void yyerror (AstNode *&dummy, const char *s);

LineColumn xpos, xprevpos;

static char *join(const char *s1, const char *s2, const char *s3=nullptr)
{
    char *d = new char[strlen(s1) + strlen(s2) + strlen(s3?s3:"") + 4];
    strcpy(d, s1);
    strcat(d, " ");
    strcat(d, s2);
    if (s3) {strcat(d, " "); strcat(d, s3);}
    return d;
}

static char *concat(const char *s1, const char *s2, const char *s3=nullptr, const char *s4=nullptr)
{
    char *d = new char[strlen(s1) + strlen(s2) + strlen(s3?s3:"") + strlen(s4?s4:"") + 1];
    strcpy(d, s1);
    strcat(d, s2);
    if (s3) strcat(d, s3);
    if (s4) strcat(d, s4);
    return d;
}

static AstNode *newConstant(const ExprValue& c)
{
    return new AstNode(c);
}

static AstNode *newOp(const char *name, AstNode *child1, AstNode *child2=nullptr, AstNode *child3=nullptr)
{
    AstNode *node = new AstNode(AstNode::OP, name);
    node->children.push_back(child1);
    if (child2)
        node->children.push_back(child2);
    if (child3)
        node->children.push_back(child3);
    return node;
}

static double parseQuantity(const char *text, std::string& unit)
{
    try {
        // evaluate quantities like "5s 230ms"
        return UnitConversion::parseQuantity(text, unit);
    }
    catch (std::exception& e) {
        AstNode *dummy;
        yyerror(dummy, e.what());
        return 0;
    }
}

static bool isIntegerValued(double d)
{
    if (std::isnan(d) || d < (double)INT64_MIN || d > (double)INT64_MAX)  // just to avoid UndefinedBehaviorSanitizer message "<value> is outside the range of representable values of type 'long'"
        return false;

    // check that when converted to integer and back to double, it stays the same
    intval_t l = (intval_t)d;
    return d == l;
}


#line 310 "expression.tab.cc"


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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   585

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

#define YYUNDEFTOK  2
#define YYMAXUTOK   284

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    33,     2,    39,    34,     2,
      46,    47,    37,    35,    51,    36,    45,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,     2,
      29,    28,    30,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    32,    53,    48,     2,     2,     2,
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
      25,    31,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   171,   171,   176,   177,   178,   179,   180,   181,   183,
     184,   186,   191,   193,   195,   197,   199,   201,   204,   221,
     223,   225,   227,   229,   231,   233,   235,   237,   240,   242,
     244,   247,   251,   254,   256,   258,   261,   264,   266,   268,
     273,   278,   283,   285,   287,   292,   294,   299,   301,   306,
     307,   312,   314,   319,   320,   321,   326,   328,   333,   338,
     340,   341,   342,   343,   344,   346,   348,   350,   352,   354,
     356,   358,   360,   362,   367,   369,   374,   376,   381,   382,
     383,   384,   388,   393,   395,   400,   402,   404,   406,   408,
     421,   423,   425,   430,   432,   437,   438,   439,   441
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TRUE_", "FALSE_", "NAN_", "INF_",
  "UNDEFINED_", "NULLPTR_", "NULL_", "NAME", "INTCONSTANT", "REALCONSTANT",
  "STRINGCONSTANT", "EQ", "NE", "GE", "LE", "SPACESHIP", "AND", "OR",
  "XOR", "SHIFT_LEFT", "SHIFT_RIGHT", "DOUBLECOLON", "INVALID_CHAR", "'?'",
  "':'", "'='", "'<'", "'>'", "MATCH", "'|'", "'#'", "'&'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'^'", "UMIN_", "NEG_", "NOT_", "'!'", "'.'", "'('",
  "')'", "'~'", "'['", "']'", "','", "'{'", "'}'", "$accept", "expression",
  "expr", "operation", "functioncall", "methodcall", "array", "object",
  "qname", "opt_exprlist", "exprlist", "opt_keyvaluelist", "keyvaluelist",
  "keyvalue", "key", "variable", "member", "literal", "stringliteral",
  "boolliteral", "numliteral", "otherliteral", "quantity", "qnumber", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    63,    58,    61,    60,
      62,   281,   124,    35,    38,    43,    45,    42,    47,    37,
      94,   282,   283,   284,    33,    46,    40,    41,   126,    91,
      93,    44,   123,   125
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -99

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     155,   -46,   -46,    26,    43,   -46,   -46,   -46,    74,    44,
      47,   -46,   155,   155,   155,   155,    83,   166,    21,   300,
     -46,   -46,   -46,   -46,   -30,   -46,   -46,   -46,   -46,   -46,
     -46,    12,    49,    89,   155,   155,   -25,   -25,    11,   -25,
     -46,   300,   -45,   -46,   -46,    26,    43,   -46,   -46,   -46,
      44,    47,   -46,   131,    50,    53,   -46,    79,    12,   -46,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   -46,   111,   166,   -46,   -46,   -46,
     -46,   112,   -46,   100,   -46,    78,    77,   194,   -46,   -46,
     105,    43,    44,    47,    12,   -46,   166,   155,   421,   421,
     445,   445,   464,   396,   332,   364,   145,   145,   268,   421,
     445,   445,   483,   502,   521,   540,   -36,   -36,    57,    57,
      57,    57,   -39,   -46,   -46,    81,   -46,   -46,   155,   -46,
     -46,   300,   -46,   300,   155,   155,   155,   -46,   300,    92,
     231,   -46,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    83,    84,    87,    88,    90,    92,    91,    74,    85,
      86,    82,     0,     0,     0,     0,     0,    55,     0,     2,
       9,     5,     7,     6,     0,     4,     3,    78,    79,    80,
      81,    89,     0,     0,    50,     0,    18,    31,     0,    36,
      42,    52,     0,    70,    71,    67,    68,    73,    72,    60,
      61,    62,    59,     0,     0,    53,    57,     0,    63,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,    55,    97,    98,    95,
      96,     0,    94,    48,    47,     0,    49,     0,     8,    43,
       0,    69,    64,    65,    66,    45,    54,     0,    20,    21,
      23,    25,    26,    28,    29,    30,    37,    38,     0,    19,
      24,    22,    27,    34,    35,    33,    12,    13,    14,    15,
      16,    17,    76,    10,    11,     0,    93,    40,     0,    75,
      44,    51,    56,    58,     0,    50,     0,    46,    39,     0,
       0,    41,    77
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,    97,    -5,
     129,    61,   -46,    42,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,    -1,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    41,    20,    21,   133,    22,    23,    24,    95,
      96,    54,    55,    56,    57,    25,   134,    26,    27,    28,
      29,    30,    31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    80,    81,    82,    83,    99,   100,   145,    84,    85,
     146,    91,    36,    37,    38,    39,    58,    87,    88,    84,
      85,    59,    86,    89,    90,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    97,   -97,    70,    91,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   104,   -98,   -95,    84,    85,   -96,    98,    92,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    91,    58,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    83,    33,    93,
     141,    84,    85,   105,   106,    58,   107,   143,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      34,   132,   136,    35,    33,   137,   -48,    13,   138,    14,
      94,    15,    16,    40,   147,    17,    87,   101,   141,   151,
     149,    12,   102,   103,   148,    42,   150,   135,   142,    13,
       0,    14,     0,    15,    16,   140,     0,    17,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    43,
      44,    45,    46,     0,    47,    48,    49,    50,    51,    52,
      78,    79,    80,    81,    82,    83,     0,     0,     0,    84,
      85,    12,     0,     0,     0,     0,     0,     0,     0,    13,
       0,    14,    53,    15,    16,     0,     0,    17,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,    84,    85,
       0,     0,     0,     0,   139,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,    70,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,    84,    85,     0,     0,     0,
       0,   152,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,   144,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,    84,    85,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    84,    85,    60,    61,    62,    63,
      64,    65,     0,    67,    68,    69,     0,     0,     0,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,    84,    85,    60,    61,
      62,    63,    64,    65,     0,     0,    68,    69,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,    84,    85,
      60,    61,    62,    63,    64,     0,     0,     0,    68,    69,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    62,    63,    64,
      84,    85,     0,    68,    69,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,    64,     0,    84,    85,    68,    69,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    68,    69,     0,    84,
      85,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    68,    69,     0,    84,    85,
       0,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    68,    69,     0,    84,    85,     0,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    68,    69,     0,    84,    85,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    68,    69,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    84,    85
};

static const yytype_int16 yycheck[] =
{
       0,    37,    38,    39,    40,    50,    51,    46,    44,    45,
      49,    31,    12,    13,    14,    15,    17,     5,     6,    44,
      45,     0,    52,    11,    12,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    35,    10,    26,    58,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    53,    10,    10,    44,    45,    10,    47,    10,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   104,    86,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    40,    24,    10,
     100,    44,    45,    53,    51,   106,    27,   107,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    36,
      46,    10,    10,    49,    24,    47,    52,    44,    51,    46,
      33,    48,    49,    50,    53,    52,     5,     6,   138,    47,
     145,    36,    11,    12,   144,    16,   146,    86,   106,    44,
      -1,    46,    -1,    48,    49,    50,    -1,    52,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    13,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    44,
      45,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    46,    36,    48,    49,    -1,    -1,    52,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    44,    45,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    45,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    44,    45,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    44,    45,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    16,    17,    18,
      44,    45,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    18,    -1,    44,    45,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    22,    23,    -1,    44,
      45,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    22,    23,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    22,    23,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    22,    23,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    22,    23,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    36,    44,    46,    48,    49,    52,    55,    56,
      57,    58,    60,    61,    62,    69,    71,    72,    73,    74,
      75,    76,    77,    24,    46,    49,    56,    56,    56,    56,
      50,    56,    64,     3,     4,     5,     6,     8,     9,    10,
      11,    12,    13,    36,    65,    66,    67,    68,    76,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      26,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    44,    45,    52,     5,     6,    11,
      12,    77,    10,    10,    62,    63,    64,    56,    47,    50,
      51,     6,    11,    12,    76,    53,    51,    27,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    10,    59,    70,    65,    10,    47,    51,    50,
      50,    56,    67,    56,    27,    46,    49,    53,    56,    63,
      56,    47,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    59,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    66,    66,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    71,    71,
      71,    71,    72,    73,    73,    74,    74,    74,    74,    74,
      75,    75,    75,    76,    76,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     2,     3,     3,     5,
       4,     4,     2,     3,     4,     3,     4,     3,     1,     1,
       0,     3,     1,     1,     2,     0,     3,     1,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (resultAstTree, YY_("syntax error: cannot back up")); \
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
                  Type, Value, resultAstTree); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, AstNode *&resultAstTree)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (resultAstTree);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, AstNode *&resultAstTree)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, resultAstTree);
  YYFPRINTF (yyo, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, AstNode *&resultAstTree)
{
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , resultAstTree);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, resultAstTree); \
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, AstNode *&resultAstTree)
{
  YYUSE (yyvaluep);
  YYUSE (resultAstTree);
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
yyparse (AstNode *&resultAstTree)
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 172 "expression.y"
    { resultAstTree = (yyvsp[0].node); }
#line 1588 "expression.tab.cc"
    break;

  case 8:
#line 182 "expression.y"
    { (yyvsp[-1].node)->parenthesized = true; (yyval.node) = (yyvsp[-1].node); }
#line 1594 "expression.tab.cc"
    break;

  case 10:
#line 185 "expression.y"
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->children.insert((yyval.node)->children.begin(), (yyvsp[-2].node)); }
#line 1600 "expression.tab.cc"
    break;

  case 11:
#line 187 "expression.y"
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->children.insert((yyval.node)->children.begin(), (yyvsp[-2].node)); }
#line 1606 "expression.tab.cc"
    break;

  case 12:
#line 192 "expression.y"
    { (yyval.node) = newOp("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1612 "expression.tab.cc"
    break;

  case 13:
#line 194 "expression.y"
    { (yyval.node) = newOp("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1618 "expression.tab.cc"
    break;

  case 14:
#line 196 "expression.y"
    { (yyval.node) = newOp("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1624 "expression.tab.cc"
    break;

  case 15:
#line 198 "expression.y"
    { (yyval.node) = newOp("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1630 "expression.tab.cc"
    break;

  case 16:
#line 200 "expression.y"
    { (yyval.node) = newOp("%", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1636 "expression.tab.cc"
    break;

  case 17:
#line 202 "expression.y"
    { (yyval.node) = newOp("^", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1642 "expression.tab.cc"
    break;

  case 18:
#line 206 "expression.y"
    {
                    AstNode *arg = (yyvsp[0].node);
                    if (arg->type == AstNode::CONSTANT && arg->constant.getType() == ExprValue::DOUBLE) {
                        arg->constant.setPreservingUnit(-arg->constant.doubleValue());
                        (yyval.node) = (yyvsp[0].node);
                    }
                    else if (arg->type == AstNode::CONSTANT && arg->constant.getType() == ExprValue::INT) {
                        arg->constant.setPreservingUnit(-arg->constant.intValue());
                        (yyval.node) = (yyvsp[0].node);
                    }
                    else {
                        (yyval.node) = newOp("-", arg);
                    }
                }
#line 1661 "expression.tab.cc"
    break;

  case 19:
#line 222 "expression.y"
    { (yyval.node) = newOp("=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1667 "expression.tab.cc"
    break;

  case 20:
#line 224 "expression.y"
    { (yyval.node) = newOp("==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1673 "expression.tab.cc"
    break;

  case 21:
#line 226 "expression.y"
    { (yyval.node) = newOp("!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1679 "expression.tab.cc"
    break;

  case 22:
#line 228 "expression.y"
    { (yyval.node) = newOp(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1685 "expression.tab.cc"
    break;

  case 23:
#line 230 "expression.y"
    { (yyval.node) = newOp(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1691 "expression.tab.cc"
    break;

  case 24:
#line 232 "expression.y"
    { (yyval.node) = newOp("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1697 "expression.tab.cc"
    break;

  case 25:
#line 234 "expression.y"
    { (yyval.node) = newOp("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1703 "expression.tab.cc"
    break;

  case 26:
#line 236 "expression.y"
    { (yyval.node) = newOp("<=>", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1709 "expression.tab.cc"
    break;

  case 27:
#line 238 "expression.y"
    { (yyval.node) = newOp("=~", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1715 "expression.tab.cc"
    break;

  case 28:
#line 241 "expression.y"
    { (yyval.node) = newOp("&&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1721 "expression.tab.cc"
    break;

  case 29:
#line 243 "expression.y"
    { (yyval.node) = newOp("||", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1727 "expression.tab.cc"
    break;

  case 30:
#line 245 "expression.y"
    { (yyval.node) = newOp("##", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1733 "expression.tab.cc"
    break;

  case 31:
#line 249 "expression.y"
    { (yyval.node) = newOp("!", (yyvsp[0].node)); }
#line 1739 "expression.tab.cc"
    break;

  case 32:
#line 252 "expression.y"
    { (yyval.node) = newOp("_!", (yyvsp[-1].node)); /*!!!*/ }
#line 1745 "expression.tab.cc"
    break;

  case 33:
#line 255 "expression.y"
    { (yyval.node) = newOp("&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1751 "expression.tab.cc"
    break;

  case 34:
#line 257 "expression.y"
    { (yyval.node) = newOp("|", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1757 "expression.tab.cc"
    break;

  case 35:
#line 259 "expression.y"
    { (yyval.node) = newOp("#", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1763 "expression.tab.cc"
    break;

  case 36:
#line 263 "expression.y"
    { (yyval.node) = newOp("~", (yyvsp[0].node)); }
#line 1769 "expression.tab.cc"
    break;

  case 37:
#line 265 "expression.y"
    { (yyval.node) = newOp("<<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1775 "expression.tab.cc"
    break;

  case 38:
#line 267 "expression.y"
    { (yyval.node) = newOp(">>", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1781 "expression.tab.cc"
    break;

  case 39:
#line 269 "expression.y"
    { (yyval.node) = newOp("?:", (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1787 "expression.tab.cc"
    break;

  case 40:
#line 274 "expression.y"
    { (yyvsp[-1].node)->type = AstNode::FUNCTION; (yyvsp[-1].node)->name = (yyvsp[-3].str); delete [] (yyvsp[-3].str); (yyval.node) = (yyvsp[-1].node); }
#line 1793 "expression.tab.cc"
    break;

  case 41:
#line 279 "expression.y"
    { (yyvsp[-1].node)->type = AstNode::METHOD; (yyvsp[-1].node)->name = (yyvsp[-3].str); delete [] (yyvsp[-3].str); (yyval.node) = (yyvsp[-1].node); }
#line 1799 "expression.tab.cc"
    break;

  case 42:
#line 284 "expression.y"
    { (yyval.node) = new AstNode(AstNode::ARRAY, ""); }
#line 1805 "expression.tab.cc"
    break;

  case 43:
#line 286 "expression.y"
    { (yyvsp[-1].node)->type = AstNode::ARRAY; (yyval.node) = (yyvsp[-1].node); }
#line 1811 "expression.tab.cc"
    break;

  case 44:
#line 288 "expression.y"
    { (yyvsp[-2].node)->type = AstNode::ARRAY; (yyval.node) = (yyvsp[-2].node); }
#line 1817 "expression.tab.cc"
    break;

  case 45:
#line 293 "expression.y"
    { (yyvsp[-1].node)->type = AstNode::OBJECT; (yyval.node) = (yyvsp[-1].node); }
#line 1823 "expression.tab.cc"
    break;

  case 46:
#line 295 "expression.y"
    { (yyvsp[-1].node)->type = AstNode::OBJECT; (yyvsp[-1].node)->name = (yyvsp[-3].str); delete [] (yyvsp[-3].str); (yyval.node) = (yyvsp[-1].node); }
#line 1829 "expression.tab.cc"
    break;

  case 47:
#line 300 "expression.y"
    { (yyval.str) = concat((yyvsp[-2].str), "::", (yyvsp[0].str)); delete [] (yyvsp[-2].str); delete [] (yyvsp[0].str); }
#line 1835 "expression.tab.cc"
    break;

  case 48:
#line 302 "expression.y"
    { (yyval.str) = (yyvsp[0].str); }
#line 1841 "expression.tab.cc"
    break;

  case 50:
#line 308 "expression.y"
    { (yyval.node) = new AstNode(); }
#line 1847 "expression.tab.cc"
    break;

  case 51:
#line 313 "expression.y"
    { (yyvsp[-2].node)->children.push_back((yyvsp[0].node)); (yyval.node) = (yyvsp[-2].node); }
#line 1853 "expression.tab.cc"
    break;

  case 52:
#line 315 "expression.y"
    { (yyval.node) = new AstNode(); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1859 "expression.tab.cc"
    break;

  case 55:
#line 322 "expression.y"
    { (yyval.node) = new AstNode(); }
#line 1865 "expression.tab.cc"
    break;

  case 56:
#line 327 "expression.y"
    { (yyvsp[-2].node)->children.push_back((yyvsp[0].node)); (yyval.node) = (yyvsp[-2].node); }
#line 1871 "expression.tab.cc"
    break;

  case 57:
#line 329 "expression.y"
    { (yyval.node) = new AstNode(); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1877 "expression.tab.cc"
    break;

  case 58:
#line 334 "expression.y"
    { (yyval.node) = new AstNode(AstNode::KEYVALUE, (yyvsp[-2].str)); (yyval.node)->children.push_back((yyvsp[0].node)); delete [] (yyvsp[-2].str); }
#line 1883 "expression.tab.cc"
    break;

  case 59:
#line 339 "expression.y"
    { (yyval.str) = opp_strdup(opp_parsequotedstr((yyvsp[0].str),0).c_str()); delete [] (yyvsp[0].str); }
#line 1889 "expression.tab.cc"
    break;

  case 64:
#line 345 "expression.y"
    { (yyval.str) = concat("-", (yyvsp[0].str)); delete [] (yyvsp[0].str); }
#line 1895 "expression.tab.cc"
    break;

  case 65:
#line 347 "expression.y"
    { (yyval.str) = concat("-", (yyvsp[0].str)); delete [] (yyvsp[0].str); }
#line 1901 "expression.tab.cc"
    break;

  case 66:
#line 349 "expression.y"
    { (yyval.str) = concat("-", (yyvsp[0].str)); delete [] (yyvsp[0].str); }
#line 1907 "expression.tab.cc"
    break;

  case 67:
#line 351 "expression.y"
    { (yyval.str) = opp_strdup("nan"); }
#line 1913 "expression.tab.cc"
    break;

  case 68:
#line 353 "expression.y"
    { (yyval.str) = opp_strdup("inf"); }
#line 1919 "expression.tab.cc"
    break;

  case 69:
#line 355 "expression.y"
    { (yyval.str) = opp_strdup("-inf"); }
#line 1925 "expression.tab.cc"
    break;

  case 70:
#line 357 "expression.y"
    { (yyval.str) = opp_strdup("true"); }
#line 1931 "expression.tab.cc"
    break;

  case 71:
#line 359 "expression.y"
    { (yyval.str) = opp_strdup("false"); }
#line 1937 "expression.tab.cc"
    break;

  case 72:
#line 361 "expression.y"
    { (yyval.str) = opp_strdup("null"); }
#line 1943 "expression.tab.cc"
    break;

  case 73:
#line 363 "expression.y"
    { (yyval.str) = opp_strdup("nullptr"); }
#line 1949 "expression.tab.cc"
    break;

  case 74:
#line 368 "expression.y"
    { (yyval.node) = new AstNode(AstNode::IDENT, (yyvsp[0].str)); delete [] (yyvsp[0].str); }
#line 1955 "expression.tab.cc"
    break;

  case 75:
#line 370 "expression.y"
    { (yyval.node) = new AstNode(AstNode::IDENT_W_INDEX, (yyvsp[-3].str)); delete [] (yyvsp[-3].str); (yyval.node)->children.push_back((yyvsp[-1].node)); }
#line 1961 "expression.tab.cc"
    break;

  case 76:
#line 375 "expression.y"
    { (yyval.node) = new AstNode(AstNode::MEMBER, (yyvsp[0].str)); delete [] (yyvsp[0].str); }
#line 1967 "expression.tab.cc"
    break;

  case 77:
#line 377 "expression.y"
    { (yyval.node) = new AstNode(AstNode::MEMBER_W_INDEX, (yyvsp[-3].str)); delete [] (yyvsp[-3].str); (yyval.node)->children.push_back((yyvsp[-1].node)); }
#line 1973 "expression.tab.cc"
    break;

  case 82:
#line 389 "expression.y"
    { (yyval.node) = newConstant(opp_parsequotedstr((yyvsp[0].str),0)); delete [] (yyvsp[0].str); }
#line 1979 "expression.tab.cc"
    break;

  case 83:
#line 394 "expression.y"
    { (yyval.node) = newConstant(true); }
#line 1985 "expression.tab.cc"
    break;

  case 84:
#line 396 "expression.y"
    { (yyval.node) = newConstant(false); }
#line 1991 "expression.tab.cc"
    break;

  case 85:
#line 401 "expression.y"
    { (yyval.node) = newConstant((intval_t)opp_atoll((yyvsp[0].str))); delete [] (yyvsp[0].str); }
#line 1997 "expression.tab.cc"
    break;

  case 86:
#line 403 "expression.y"
    { (yyval.node) = newConstant(opp_atof((yyvsp[0].str))); delete [] (yyvsp[0].str); }
#line 2003 "expression.tab.cc"
    break;

  case 87:
#line 405 "expression.y"
    { (yyval.node) = newConstant(std::nan("")); }
#line 2009 "expression.tab.cc"
    break;

  case 88:
#line 407 "expression.y"
    { (yyval.node) = newConstant(1/0.0); }
#line 2015 "expression.tab.cc"
    break;

  case 89:
#line 409 "expression.y"
    {
                  std::string unit;
                  double d = parseQuantity((yyvsp[0].str), unit);
                  if (isIntegerValued(d))
                      (yyval.node) = newConstant(ExprValue((intval_t)d, unit.c_str()));
                  else
                      (yyval.node) = newConstant(ExprValue(d, unit.c_str()));
                  delete [] (yyvsp[0].str);
                }
#line 2029 "expression.tab.cc"
    break;

  case 90:
#line 422 "expression.y"
    { (yyval.node) = newConstant(ExprValue()); }
#line 2035 "expression.tab.cc"
    break;

  case 91:
#line 424 "expression.y"
    { (yyval.node) = newConstant(any_ptr(nullptr)); }
#line 2041 "expression.tab.cc"
    break;

  case 92:
#line 426 "expression.y"
    { (yyval.node) = newConstant(any_ptr(nullptr)); }
#line 2047 "expression.tab.cc"
    break;

  case 93:
#line 431 "expression.y"
    { (yyval.str) = join((yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str)); delete [] (yyvsp[-2].str); delete [] (yyvsp[-1].str); delete [] (yyvsp[0].str); }
#line 2053 "expression.tab.cc"
    break;

  case 94:
#line 433 "expression.y"
    { (yyval.str) = join((yyvsp[-1].str), (yyvsp[0].str)); delete [] (yyvsp[-1].str); delete [] (yyvsp[0].str); }
#line 2059 "expression.tab.cc"
    break;

  case 97:
#line 440 "expression.y"
    { (yyval.str) = opp_strdup("nan"); }
#line 2065 "expression.tab.cc"
    break;

  case 98:
#line 442 "expression.y"
    { (yyval.str) = opp_strdup("inf"); }
#line 2071 "expression.tab.cc"
    break;


#line 2075 "expression.tab.cc"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
      yyerror (resultAstTree, YY_("syntax error"));
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
        yyerror (resultAstTree, yymsgp);
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
                      yytoken, &yylval, resultAstTree);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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
                  yystos[yystate], yyvsp, resultAstTree);
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
  yyerror (resultAstTree, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, resultAstTree);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, resultAstTree);
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
#line 444 "expression.y"


//----------------------------------------------------------------------

AstNode *Expression::parseToAst(const char *text) const
{
    NONREENTRANT_PARSER();

    // reset the lexer
    xpos.co = 0;
    xpos.li = 1;
    xprevpos = xpos;

    yyin = nullptr;
    yyout = stderr; // not used anyway

    // alloc buffer
    struct yy_buffer_state *handle = yy_scan_string(text);
    if (!handle)
        throw std::runtime_error("Parser is unable to allocate work memory");

    // parse
    AstNode *result;
    try
    {
        yyparse(result);
    }
    catch (std::exception& e)
    {
        yy_delete_buffer(handle);
        throw;
    }
    yy_delete_buffer(handle);

    return result;
}

void yyerror(AstNode *&dummy, const char *s)
{
    // chop newline
    char buf[250];
    strcpy(buf, s);
    if (buf[strlen(buf)-1] == '\n')
        buf[strlen(buf)-1] = '\0';

    throw std::runtime_error(buf);
}
