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
#line 15 "parser.y" /* yacc.c:1909  */

    #include "Expression.hpp"
    #include "Statement.hpp"
    #include "Types.hpp"

#line 50 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.hpp" /* yacc.c:1909  */

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
#line 22 "parser.y" /* yacc.c:1909  */

int i_val;
char char_val;
char* str_val;
AbsType* type_val;
Expr* expr_val;
Statement* stm_val;

#line 138 "/home/chill/Documents/workspace/cs5300/Final_Project/Compiler/parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_CHILL_DOCUMENTS_WORKSPACE_CS5300_FINAL_PROJECT_COMPILER_PARSER_HPP_INCLUDED  */
