/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_IDENTIFIER = 258,
     T_NUMBER = 259,
     T_INTERVAL = 260,
     T_INTERVALVECTOR = 261,
     T_POS_INFINITY = 262,
     T_NEG_INFINITY = 263,
     T_ASSIGN = 264,
     T_PI = 265,
     T_TWO_PI = 266,
     T_HALF_PI = 267,
     T_EMPTY_SET = 268,
     T_ALL_REALS = 269,
     T_ZERO = 270,
     T_ONE = 271,
     T_POS_REALS = 272,
     T_NEG_REALS = 273,
     T_LPAREN = 274,
     T_RPAREN = 275,
     T_COMMA = 276,
     T_COLON = 277,
     T_SEMICOLON = 278,
     T_PLUS = 279,
     T_MINUS = 280,
     T_MULT = 281,
     T_DIVIDE = 282
   };
#endif
/* Tokens.  */
#define T_IDENTIFIER 258
#define T_NUMBER 259
#define T_INTERVAL 260
#define T_INTERVALVECTOR 261
#define T_POS_INFINITY 262
#define T_NEG_INFINITY 263
#define T_ASSIGN 264
#define T_PI 265
#define T_TWO_PI 266
#define T_HALF_PI 267
#define T_EMPTY_SET 268
#define T_ALL_REALS 269
#define T_ZERO 270
#define T_ONE 271
#define T_POS_REALS 272
#define T_NEG_REALS 273
#define T_LPAREN 274
#define T_RPAREN 275
#define T_COMMA 276
#define T_COLON 277
#define T_SEMICOLON 278
#define T_PLUS 279
#define T_MINUS 280
#define T_MULT 281
#define T_DIVIDE 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "parser.y"
{
    char* id;     // For identifiers
    double num;   // For numbers
}
/* Line 1529 of yacc.c.  */
#line 108 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

