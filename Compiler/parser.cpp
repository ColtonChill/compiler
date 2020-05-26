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

#include <iostream>
#include <map>

#include "Expression.hpp"
#include "Statement.hpp"
#include "Types.hpp"
#include "symbol_table.hpp"
#include "Interface.hpp"
// #include "functions.hpp"

extern int yylex();
void yyerror(const char*);

#line 81 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:339  */

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
   by #include "parser.hpp".  */
#ifndef YY_YY_HOME_CHILL_DOCUMENTS_WORKSPACE_CS5300_FINAL_PROJECT_COMPILER_PARSER_HPP_INCLUDED
# define YY_YY_HOME_CHILL_DOCUMENTS_WORKSPACE_CS5300_FINAL_PROJECT_COMPILER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "parser.y" /* yacc.c:355  */

    #include "Expression.hpp"
    #include "Statement.hpp"
    #include "Types.hpp"

#line 117 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    OCT = 259,
    HEX = 260,
    STRING = 261,
    ADD = 262,
    SUB = 263,
    MULT = 264,
    DIV = 265,
    MOD = 266,
    OPENP = 267,
    CLOSEP = 268,
    OPENB = 269,
    CLOSEB = 270,
    DONE = 271,
    INT = 272,
    GETS = 273,
    EQUALS = 274,
    LT = 275,
    LTQ = 276,
    GT = 277,
    GTQ = 278,
    NEQ = 279,
    AND = 280,
    OR = 281,
    NOT = 282,
    DOT = 283,
    COMMA = 284,
    COLON = 285,
    CRETURN = 286,
    BACKSPACE = 287,
    FORMFEED = 288,
    SQUOTE = 289,
    DQUOTE = 290,
    VAR = 291,
    CHR = 292,
    ARRAY = 293,
    IF = 294,
    ELSEIF = 295,
    ELSE = 296,
    RECORD = 297,
    THEN = 298,
    WRITE = 299,
    BEG = 300,
    END = 301,
    OF = 302,
    REF = 303,
    TO = 304,
    ORD = 305,
    REPEAT = 306,
    TYPE = 307,
    CONST = 308,
    FOR = 309,
    PRED = 310,
    RETURN = 311,
    UNTIL = 312,
    DO = 313,
    FORWARD = 314,
    PROCEDURE = 315,
    STOP = 316,
    DOWNTO = 317,
    FUNCTION = 318,
    READ = 319,
    SUCC = 320,
    WHILE = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "parser.y" /* yacc.c:355  */

int i_val;
char char_val;
char* str_val;
AbsType* type_val;
Expr* expr_val;
Statement* stm_val;

#line 205 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_CHILL_DOCUMENTS_WORKSPACE_CS5300_FINAL_PROJECT_COMPILER_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 222 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   461

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   150,   151,   153,   154,   156,   157,   159,
     160,   162,   163,   165,   166,   168,   169,   170,   172,   173,
     175,   176,   178,   179,   180,   182,   184,   186,   187,   189,
     191,   193,   194,   196,   198,   199,   200,   202,   203,   205,
     207,   208,   210,   211,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   224,   226,   228,   229,   231,   232,
     234,   236,   238,   240,   241,   243,   245,   246,   248,   250,
     252,   253,   255,   257,   258,   260,   261,   263,   265,   266,
     268,   270,   271,   273,   274,   275,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   294,   295,   296,   297,   298,   300,   301,   302,
     303,   304
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "OCT", "HEX", "STRING", "ADD",
  "SUB", "MULT", "DIV", "MOD", "OPENP", "CLOSEP", "OPENB", "CLOSEB",
  "DONE", "INT", "GETS", "EQUALS", "LT", "LTQ", "GT", "GTQ", "NEQ", "AND",
  "OR", "NOT", "DOT", "COMMA", "COLON", "CRETURN", "BACKSPACE", "FORMFEED",
  "SQUOTE", "DQUOTE", "VAR", "CHR", "ARRAY", "IF", "ELSEIF", "ELSE",
  "RECORD", "THEN", "WRITE", "BEG", "END", "OF", "REF", "TO", "ORD",
  "REPEAT", "TYPE", "CONST", "FOR", "PRED", "RETURN", "UNTIL", "DO",
  "FORWARD", "PROCEDURE", "STOP", "DOWNTO", "FUNCTION", "READ", "SUCC",
  "WHILE", "$accept", "daProgram", "ConstDecl", "ConstList", "TypeDecl",
  "TypeList", "VarDecl", "VarList", "DefinitionBlock", "ProcedureDecl",
  "FunctionDecl", "Type", "SimpleType", "RecordType", "RecordList",
  "Record", "ArrayType", "Parameters", "Parameter", "VarOption",
  "MainBlock", "CodeBlock", "SemiOpt", "CodeOpt", "SomeStatement",
  "Assignment", "IfStatement", "ElifBlock", "ElseBlock", "WhileStatement",
  "RepeatStatement", "ForStatement", "ToDownto", "StopStatement",
  "ReturnStatement", "ReadStatement", "WriteStatement", "WriteOpt",
  "ProcedureCall", "ExpressionList", "ExtraTerm", "IDList", "ExtraID",
  "LvalList", "ExtraLval", "LValue", "Expression", "Term", "Factor", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

#define YYPACT_NINF -180

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-180)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-80)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -40,  -180,    31,    23,    55,  -180,  -180,    42,    77,    97,
    -180,  -180,    74,    83,   102,     8,    96,  -180,   110,    74,
    -180,    74,   103,   105,   107,   109,  -180,    56,   286,   123,
    -180,     6,    95,   125,   114,   132,   139,  -180,  -180,   115,
     131,  -180,   306,   435,    74,    74,    74,    74,    74,   155,
     106,   106,  -180,    74,    74,    74,    74,    74,    74,    74,
      74,   110,   110,   110,  -180,   145,  -180,   144,  -180,  -180,
    -180,     6,   133,  -180,  -180,   151,   152,  -180,   148,    74,
    -180,   326,   346,   366,   386,   406,  -180,   123,   123,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,  -180,  -180,  -180,
      74,   119,  -180,   150,  -180,   121,     3,  -180,  -180,  -180,
     266,  -180,  -180,  -180,  -180,  -180,   226,  -180,  -180,   146,
    -180,  -180,    74,   167,  -180,   179,    74,  -180,   171,    74,
     168,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,    69,    49,    50,  -180,    74,     6,   193,  -180,   130,
    -180,    76,   435,  -180,   149,    15,  -180,    74,   170,   -24,
     158,   426,   174,  -180,    74,    74,    74,   176,   179,  -180,
     435,   -26,  -180,  -180,  -180,  -180,     6,   156,  -180,  -180,
     246,   435,   129,  -180,    60,   159,   186,   161,   180,   188,
       6,    52,  -180,  -180,  -180,  -180,    74,  -180,  -180,  -180,
     195,     6,   -13,  -180,    74,  -180,   182,   173,  -180,  -180,
     213,   161,   201,  -180,  -180,  -180,  -180,   214,  -180,   189,
    -180,  -180,  -180
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     6,     0,     8,     3,     1,    10,    12,     0,     7,
      14,    17,     0,     0,    11,    38,    85,   110,     0,     0,
     109,     0,     0,     0,     0,     0,   111,   108,     0,    97,
     106,     0,     0,     0,    41,     0,     0,    15,    16,     0,
      76,   105,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,    28,     0,    22,    23,
      24,     0,    77,    40,    43,     0,     0,     2,     0,     0,
     107,     0,     0,     0,     0,     0,    83,    96,    95,    89,
      93,    91,    94,    92,    90,    87,    86,   104,   103,   102,
       0,    79,     9,     0,    78,     0,     0,    32,    32,    72,
      73,    98,    99,   100,   101,    84,     0,    26,    27,     0,
      13,    37,     0,     0,    43,     0,    67,    65,     0,     0,
      41,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,    41,    41,    75,     0,     0,     0,    71,     0,
      85,     0,    66,    82,     0,    42,    39,     0,     0,    36,
       0,     0,     0,    43,     0,     0,     0,     0,     0,    43,
      54,    12,    35,    34,    31,    79,     0,     0,    29,    57,
       0,    61,     0,    68,    80,     0,     0,    38,     0,     0,
       0,    59,    69,    70,    63,    64,     0,    81,    60,    18,
       0,     0,    12,    30,     0,    43,     0,     0,    19,    33,
       0,    38,     0,    58,    55,    43,    20,     0,    43,     0,
      21,    56,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,  -180,  -180,  -180,  -180,  -157,  -180,  -180,  -180,
    -180,   -70,  -180,  -180,  -180,  -180,  -180,   124,  -180,  -180,
    -179,  -120,   -31,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,   134,  -180,
    -180,   -96,  -180,  -180,  -180,   -95,   -19,    90,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     7,     9,    11,    14,    15,    37,
      38,    67,    68,    69,   101,   118,    70,   142,   174,   175,
      39,   105,   159,   106,   130,   131,   132,   191,   206,   133,
     134,   135,   196,   136,   137,   138,   139,   164,    26,    78,
      79,    32,    33,   167,   168,    27,    28,    29,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   103,    43,    74,   149,   119,    16,    41,   200,    64,
      10,   141,   172,     1,   187,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,    10,   173,    81,    82,    83,    84,    85,
     151,     5,   217,   186,    89,    90,    91,    92,    93,    94,
      95,    96,   122,   179,    65,   211,   210,   123,    66,   185,
      97,    98,    99,    34,   124,   -40,   -40,   125,     8,   126,
     110,   -40,   158,   160,   127,    73,    73,   128,    35,   129,
      48,    36,   -40,   184,    48,     6,   162,    16,    10,   188,
      17,   116,    18,    48,    49,   213,    19,   157,    49,   197,
      48,    20,   204,   205,   166,   219,    12,    49,   221,   156,
      13,    21,    31,   147,    49,   -79,   189,   152,    40,    16,
     154,    22,    17,    16,    18,    44,    17,    45,    19,    46,
     203,    47,    19,    20,    23,    71,   161,    20,    72,    24,
      73,   209,    61,    62,    63,    75,    50,    51,   170,    25,
      87,    88,    76,    77,   -74,   180,   181,   182,    53,    54,
      55,    56,    57,    58,    59,    60,    50,    51,    86,   100,
     102,   109,   104,   107,   108,   117,   120,   121,    53,    54,
      55,    56,    57,    58,    59,    60,   146,   207,   194,   148,
      50,    51,   150,   153,   155,   212,   171,   165,   176,   183,
     178,   195,    53,    54,    55,    56,    57,    58,    59,    60,
      50,    51,   199,   190,   202,   198,    34,   169,    50,    51,
     201,   208,    53,    54,    55,    56,    57,    58,    59,    60,
      53,    54,    55,    56,    57,    58,    59,    60,   214,   216,
     220,   215,   143,    50,    51,   222,   163,     0,     0,     0,
     140,     0,     0,     0,   218,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,     0,   145,     0,     0,   192,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,   144,     0,     0,     0,     0,
       0,     0,    52,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,     0,     0,     0,     0,   111,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,     0,     0,     0,     0,   112,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,     0,     0,     0,     0,   114,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,     0,     0,     0,     0,     0,
       0,   115,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    50,    51,     0,     0,     0,     0,     0,
       0,   177,    50,    51,     0,    53,    54,    55,    56,    57,
      58,    59,    60,     0,    53,    54,    55,    56,    57,    58,
      59,    60
};

static const yytype_int16 yycheck[] =
{
      19,    71,    21,    34,   124,   101,     3,    18,   187,     3,
      36,   106,    36,    53,   171,    19,    20,    21,    22,    23,
      24,    25,    26,    36,    48,    44,    45,    46,    47,    48,
     125,     0,   211,    59,    53,    54,    55,    56,    57,    58,
      59,    60,    39,   163,    38,   202,    59,    44,    42,   169,
      61,    62,    63,    45,    51,    40,    41,    54,     3,    56,
      79,    46,    13,    13,    61,    16,    16,    64,    60,    66,
      14,    63,    57,   168,    14,    52,   146,     3,    36,   175,
       6,   100,     8,    14,    28,   205,    12,    18,    28,    29,
      14,    17,    40,    41,    18,   215,    19,    28,   218,   130,
       3,    27,    19,   122,    28,     3,   176,   126,    12,     3,
     129,    37,     6,     3,     8,    12,     6,    12,    12,    12,
     190,    12,    12,    17,    50,    30,   145,    17,     3,    55,
      16,   201,     9,    10,    11,     3,     7,     8,   157,    65,
      50,    51,     3,    28,    13,   164,   165,   166,    19,    20,
      21,    22,    23,    24,    25,    26,     7,     8,     3,    14,
      16,    13,    29,    12,    12,    46,    16,    46,    19,    20,
      21,    22,    23,    24,    25,    26,    30,   196,    49,    12,
       7,     8,     3,    12,    16,   204,    16,    57,    30,    13,
      16,    62,    19,    20,    21,    22,    23,    24,    25,    26,
       7,     8,    16,    47,    16,    46,    45,    58,     7,     8,
      30,    16,    19,    20,    21,    22,    23,    24,    25,    26,
      19,    20,    21,    22,    23,    24,    25,    26,    46,    16,
      16,    58,   108,     7,     8,    46,    43,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    43,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    -1,    30,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,     7,     8,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    19,    20,    21,    22,    23,    24,
      25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    68,    69,    70,     0,    52,    71,     3,    72,
      36,    73,    19,     3,    74,    75,     3,     6,     8,    12,
      17,    27,    37,    50,    55,    65,   105,   112,   113,   114,
     115,    19,   108,   109,    45,    60,    63,    76,    77,    87,
      12,   115,   113,   113,    12,    12,    12,    12,    14,    28,
       7,     8,    16,    19,    20,    21,    22,    23,    24,    25,
      26,     9,    10,    11,     3,    38,    42,    78,    79,    80,
      83,    30,     3,    16,    89,     3,     3,    28,   106,   107,
      13,   113,   113,   113,   113,   113,     3,   114,   114,   113,
     113,   113,   113,   113,   113,   113,   113,   115,   115,   115,
      14,    81,    16,    78,    29,    88,    90,    12,    12,    13,
     113,    13,    13,    13,    13,    15,   113,    46,    82,   108,
      16,    46,    39,    44,    51,    54,    56,    61,    64,    66,
      91,    92,    93,    96,    97,    98,   100,   101,   102,   103,
     105,   112,    84,    84,    29,    30,    30,   113,    12,    88,
       3,   112,   113,    12,   113,    16,    89,    18,    13,    89,
      13,   113,    78,    43,   104,    57,    18,   110,   111,    58,
     113,    16,    36,    48,    85,    86,    30,    15,    16,    88,
     113,   113,   113,    13,   112,    88,    59,    73,   108,    78,
      47,    94,    13,    29,    49,    62,    99,    29,    46,    16,
      87,    30,    16,    78,    40,    41,    95,   113,    16,    78,
      59,    73,   113,    88,    46,    58,    16,    87,    43,    88,
      16,    88,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    79,    80,    81,    81,    82,
      83,    84,    84,    85,    86,    86,    86,    87,    87,    88,
      89,    89,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    92,    93,    94,    94,    95,    95,
      96,    97,    98,    99,    99,   100,   101,   101,   102,   103,
     104,   104,   105,   106,   106,   107,   107,   108,   109,   109,
     110,   111,   111,   112,   112,   112,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   115,   115,   115,
     115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     0,     5,     0,     2,     0,     5,
       0,     2,     0,     5,     0,     2,     2,     0,     8,     9,
      10,    11,     1,     1,     1,     1,     3,     2,     0,     4,
       8,     3,     0,     4,     1,     1,     0,     4,     0,     3,
       1,     0,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     7,     5,     0,     2,     0,
       5,     4,     9,     1,     1,     1,     2,     1,     4,     5,
       3,     0,     4,     2,     0,     3,     0,     2,     3,     0,
       2,     3,     0,     3,     4,     1,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     4,
       4,     4,     3,     3,     3,     2,     1,     3,     1,     1,
       1,     1
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
#line 148 "parser.y" /* yacc.c:1646  */
    {c::EmitMain((yyvsp[-3].stm_val),(yyvsp[-2].stm_val),(yyvsp[-1].stm_val));}
#line 1515 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 150 "parser.y" /* yacc.c:1646  */
    {}
#line 1521 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 151 "parser.y" /* yacc.c:1646  */
    {}
#line 1527 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 153 "parser.y" /* yacc.c:1646  */
    {c::SaveConst((yyvsp[-3].str_val),(yyvsp[-1].expr_val));}
#line 1533 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 154 "parser.y" /* yacc.c:1646  */
    {}
#line 1539 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 156 "parser.y" /* yacc.c:1646  */
    {}
#line 1545 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 157 "parser.y" /* yacc.c:1646  */
    {}
#line 1551 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "parser.y" /* yacc.c:1646  */
    {c::SaveType((yyvsp[-3].str_val),(yyvsp[-1].type_val));}
#line 1557 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 160 "parser.y" /* yacc.c:1646  */
    {}
#line 1563 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[0].stm_val);}
#line 1569 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1575 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeVarDecl((yyvsp[-4].stm_val),(yyvsp[-3].stm_val),(yyvsp[-1].type_val));}
#line 1581 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1587 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeStop();}
#line 1593 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeStop();}
#line 1599 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1605 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 172 "parser.y" /* yacc.c:1646  */
    {}
#line 1611 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 173 "parser.y" /* yacc.c:1646  */
    {}
#line 1617 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 175 "parser.y" /* yacc.c:1646  */
    {}
#line 1623 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 176 "parser.y" /* yacc.c:1646  */
    {}
#line 1629 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.type_val) = (yyvsp[0].type_val);}
#line 1635 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.type_val) = (yyvsp[0].type_val);}
#line 1641 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.type_val) = (yyvsp[0].type_val);}
#line 1647 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.type_val) = c::LoadType((yyvsp[0].str_val));}
#line 1653 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.type_val)=(yyvsp[-1].type_val);}
#line 1659 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 186 "parser.y" /* yacc.c:1646  */
    {(yyval.type_val) = c::MakeRecord((yyvsp[-1].type_val),(yyvsp[0].type_val));}
#line 1665 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.type_val) = nullptr;}
#line 1671 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.type_val) = c::MakeRecord((yyvsp[-3].stm_val),(yyvsp[-1].type_val));}
#line 1677 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.type_val) = c::MakeArray((yyvsp[-5].expr_val),(yyvsp[-3].expr_val),(yyvsp[0].type_val));}
#line 1683 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 193 "parser.y" /* yacc.c:1646  */
    {}
#line 1689 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 194 "parser.y" /* yacc.c:1646  */
    {}
#line 1695 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 196 "parser.y" /* yacc.c:1646  */
    {c::MakeVarDecl((yyvsp[-3].stm_val),(yyvsp[-2].stm_val),(yyvsp[0].type_val));}
#line 1701 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1707 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1713 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1719 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[-1].stm_val);}
#line 1725 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 203 "parser.y" /* yacc.c:1646  */
    {}
#line 1731 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeMain((yyvsp[-2].stm_val),(yyvsp[-1].stm_val));}
#line 1737 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 207 "parser.y" /* yacc.c:1646  */
    {}
#line 1743 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 208 "parser.y" /* yacc.c:1646  */
    {}
#line 1749 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeMain((yyvsp[-2].stm_val),(yyvsp[-1].stm_val));}
#line 1755 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1761 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[0].stm_val);}
#line 1767 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[0].stm_val);}
#line 1773 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[0].stm_val);}
#line 1779 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[0].stm_val);}
#line 1785 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[0].stm_val);}
#line 1791 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[0].stm_val);}
#line 1797 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 219 "parser.y" /* yacc.c:1646  */
    {}
#line 1803 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 220 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[0].stm_val);}
#line 1809 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 221 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = (yyvsp[0].stm_val);}
#line 1815 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 222 "parser.y" /* yacc.c:1646  */
    {}
#line 1821 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 224 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeVarAssignment((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 1827 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 226 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeIf((yyvsp[-5].expr_val),(yyvsp[-3].stm_val),(yyvsp[-2].stm_val),(yyvsp[-1].stm_val));}
#line 1833 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeElif((yyvsp[-4].stm_val),(yyvsp[-2].expr_val),(yyvsp[0].stm_val));}
#line 1839 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 229 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1845 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 231 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val)=(yyvsp[0].stm_val);}
#line 1851 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 232 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1857 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 234 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeWhileStm((yyvsp[-3].expr_val),(yyvsp[-1].stm_val));}
#line 1863 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 236 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeRepeat((yyvsp[-2].stm_val),(yyvsp[0].expr_val));}
#line 1869 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 238 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeFor((yyvsp[-7].expr_val),(yyvsp[-5].expr_val),(yyvsp[-4].i_val),(yyvsp[-3].expr_val),(yyvsp[-1].stm_val));}
#line 1875 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 240 "parser.y" /* yacc.c:1646  */
    {(yyval.i_val) = 1;}
#line 1881 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 241 "parser.y" /* yacc.c:1646  */
    {(yyval.i_val) = -1;}
#line 1887 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeStop();}
#line 1893 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 245 "parser.y" /* yacc.c:1646  */
    {}
#line 1899 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 246 "parser.y" /* yacc.c:1646  */
    {}
#line 1905 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 248 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeRead((yyvsp[-1].stm_val));}
#line 1911 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeWrite((yyvsp[-2].stm_val),(yyvsp[-1].expr_val));}
#line 1917 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeWrite((yyvsp[-2].stm_val), (yyvsp[-1].expr_val));}
#line 1923 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1929 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 255 "parser.y" /* yacc.c:1646  */
    {}
#line 1935 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 257 "parser.y" /* yacc.c:1646  */
    {}
#line 1941 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 258 "parser.y" /* yacc.c:1646  */
    {}
#line 1947 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 260 "parser.y" /* yacc.c:1646  */
    {}
#line 1953 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 261 "parser.y" /* yacc.c:1646  */
    {}
#line 1959 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 263 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeIDList((yyvsp[-1].stm_val),(yyvsp[0].str_val));}
#line 1965 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeIDList((yyvsp[-2].stm_val),(yyvsp[-1].str_val));}
#line 1971 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1977 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 268 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeLvalList((yyvsp[-1].stm_val),(yyvsp[0].expr_val));}
#line 1983 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = c::MakeLvalList((yyvsp[-2].stm_val),(yyvsp[-1].expr_val));}
#line 1989 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.stm_val) = nullptr;}
#line 1995 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val)=c::MakeRecordMember((yyvsp[-2].expr_val),(yyvsp[0].str_val));}
#line 2001 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeArrayReference((yyvsp[-3].expr_val),(yyvsp[-1].expr_val));}
#line 2007 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeID((yyvsp[0].str_val));}
#line 2013 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeOr((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2019 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeAnd((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2025 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 279 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeNot((yyvsp[0].expr_val));}
#line 2031 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 280 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeEquals((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2037 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 281 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeNEQ((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2043 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 282 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeLTQ((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2049 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeGTQ((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2055 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 284 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeLT((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2061 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeGT((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2067 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeSub((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2073 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeAdd((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2079 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = (yyvsp[0].expr_val);}
#line 2085 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 289 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeChr((yyvsp[-1].expr_val));}
#line 2091 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 290 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeOrd((yyvsp[-1].expr_val));}
#line 2097 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 291 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val)=c::MakePred((yyvsp[-1].expr_val));}
#line 2103 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val)=c::MakeSucc((yyvsp[-1].expr_val));}
#line 2109 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 294 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeMod((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2115 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 295 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeDiv((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2121 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeMult((yyvsp[-2].expr_val),(yyvsp[0].expr_val));}
#line 2127 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeNegative((yyvsp[0].expr_val));}
#line 2133 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = (yyvsp[0].expr_val);}
#line 2139 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 300 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = (yyvsp[-1].expr_val);}
#line 2145 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 301 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = (yyvsp[0].expr_val);}
#line 2151 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeInt((yyvsp[0].i_val));}
#line 2157 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = c::MakeStr((yyvsp[0].str_val));}
#line 2163 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 304 "parser.y" /* yacc.c:1646  */
    {(yyval.expr_val) = nullptr; std::cerr<<"That's a funciton call!"<<std::endl;}
#line 2169 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
    break;


#line 2173 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.cpp" /* yacc.c:1646  */
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
#line 308 "parser.y" /* yacc.c:1906  */


void yyerror(const char* msg)
{
  std::cerr << "line " << symbol_table.getLineCount() << ": "<< msg << std::endl;
}
