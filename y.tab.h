/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
/* "%code requires" blocks.  */
#line 12 "synt.y" /* yacc.c:1910  */

  #include "TypeGlobale.h"

#line 48 "y.tab.h" /* yacc.c:1910  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    mc_lang = 258,
    id = 259,
    mc_fin = 260,
    mc_dec = 261,
    mc_fdec = 262,
    mc_deb = 263,
    bib_inOut = 264,
    bib_tab = 265,
    bib_arithm = 266,
    mc_CONST = 267,
    mc_While = 268,
    mc_Faire = 269,
    mc_Fait = 270,
    mc_EXECUT = 271,
    mc_IF = 272,
    mc_IntVal = 273,
    mc_ReelVal = 274,
    mc_StringVal = 275,
    mc_int = 276,
    mc_float = 277,
    mc_string = 278,
    mc_vardec = 279,
    mc_input = 280,
    mc_Output = 281,
    aff = 282,
    leOp = 283,
    geOp = 284,
    neOp = 285,
    moin = 286
  };
#endif
/* Tokens.  */
#define mc_lang 258
#define id 259
#define mc_fin 260
#define mc_dec 261
#define mc_fdec 262
#define mc_deb 263
#define bib_inOut 264
#define bib_tab 265
#define bib_arithm 266
#define mc_CONST 267
#define mc_While 268
#define mc_Faire 269
#define mc_Fait 270
#define mc_EXECUT 271
#define mc_IF 272
#define mc_IntVal 273
#define mc_ReelVal 274
#define mc_StringVal 275
#define mc_int 276
#define mc_float 277
#define mc_string 278
#define mc_vardec 279
#define mc_input 280
#define mc_Output 281
#define aff 282
#define leOp 283
#define geOp 284
#define neOp 285
#define moin 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "synt.y" /* yacc.c:1910  */

  typeG typeG;
  Etype SauvType;
  int ent;

#line 128 "y.tab.h" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
