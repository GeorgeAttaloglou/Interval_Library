/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_IDENTIFIER = 258,            /* T_IDENTIFIER  */
    T_NUMBER = 259,                /* T_NUMBER  */
    T_INTERVAL = 260,              /* T_INTERVAL  */
    T_INTERVALVECTOR = 261,        /* T_INTERVALVECTOR  */
    T_POS_INFINITY = 262,          /* T_POS_INFINITY  */
    T_NEG_INFINITY = 263,          /* T_NEG_INFINITY  */
    T_ASSIGN = 264,                /* T_ASSIGN  */
    T_PI = 265,                    /* T_PI  */
    T_TWO_PI = 266,                /* T_TWO_PI  */
    T_HALF_PI = 267,               /* T_HALF_PI  */
    T_EMPTY_SET = 268,             /* T_EMPTY_SET  */
    T_ALL_REALS = 269,             /* T_ALL_REALS  */
    T_ZERO = 270,                  /* T_ZERO  */
    T_ONE = 271,                   /* T_ONE  */
    T_POS_REALS = 272,             /* T_POS_REALS  */
    T_NEG_REALS = 273,             /* T_NEG_REALS  */
    T_LPAREN = 274,                /* T_LPAREN  */
    T_RPAREN = 275,                /* T_RPAREN  */
    T_COMMA = 276,                 /* T_COMMA  */
    T_COLON = 277,                 /* T_COLON  */
    T_SEMICOLON = 278,             /* T_SEMICOLON  */
    T_PLUS = 279,                  /* T_PLUS  */
    T_MINUS = 280,                 /* T_MINUS  */
    T_MULT = 281,                  /* T_MULT  */
    T_DIVIDE = 282                 /* T_DIVIDE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.y"

    char* id;     // For identifiers
    double num;   // For numbers

#line 96 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
