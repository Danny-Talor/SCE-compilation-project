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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    BOOL = 258,                    /* BOOL  */
    CHAR = 259,                    /* CHAR  */
    INT = 260,                     /* INT  */
    REAL = 261,                    /* REAL  */
    STRING = 262,                  /* STRING  */
    INTP = 263,                    /* INTP  */
    CHARP = 264,                   /* CHARP  */
    REALP = 265,                   /* REALP  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    VAR = 270,                     /* VAR  */
    FUNCARGS = 271,                /* FUNCARGS  */
    FUNC = 272,                    /* FUNC  */
    RETURN = 273,                  /* RETURN  */
    NULLP = 274,                   /* NULLP  */
    VOID = 275,                    /* VOID  */
    DO = 276,                      /* DO  */
    MAIN = 277,                    /* MAIN  */
    AND = 278,                     /* AND  */
    DIV = 279,                     /* DIV  */
    ASSIGN = 280,                  /* ASSIGN  */
    EQ = 281,                      /* EQ  */
    GT = 282,                      /* GT  */
    GTE = 283,                     /* GTE  */
    LT = 284,                      /* LT  */
    LTE = 285,                     /* LTE  */
    SUB = 286,                     /* SUB  */
    NOT = 287,                     /* NOT  */
    NEQ = 288,                     /* NEQ  */
    OR = 289,                      /* OR  */
    ADD = 290,                     /* ADD  */
    MUL = 291,                     /* MUL  */
    ADDRESS = 292,                 /* ADDRESS  */
    ID = 293,                      /* ID  */
    DER_ID = 294,                  /* DER_ID  */
    TRUE_VAL = 295,                /* TRUE_VAL  */
    FALSE_VAL = 296,               /* FALSE_VAL  */
    DEC_INT = 297,                 /* DEC_INT  */
    HEX_INT = 298,                 /* HEX_INT  */
    CHAR_VAL = 299,                /* CHAR_VAL  */
    STRING_VAL = 300,              /* STRING_VAL  */
    REAL_VAL = 301,                /* REAL_VAL  */
    UNARY = 302                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BOOL 258
#define CHAR 259
#define INT 260
#define REAL 261
#define STRING 262
#define INTP 263
#define CHARP 264
#define REALP 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define VAR 270
#define FUNCARGS 271
#define FUNC 272
#define RETURN 273
#define NULLP 274
#define VOID 275
#define DO 276
#define MAIN 277
#define AND 278
#define DIV 279
#define ASSIGN 280
#define EQ 281
#define GT 282
#define GTE 283
#define LT 284
#define LTE 285
#define SUB 286
#define NOT 287
#define NEQ 288
#define OR 289
#define ADD 290
#define MUL 291
#define ADDRESS 292
#define ID 293
#define DER_ID 294
#define TRUE_VAL 295
#define FALSE_VAL 296
#define DEC_INT 297
#define HEX_INT 298
#define CHAR_VAL 299
#define STRING_VAL 300
#define REAL_VAL 301
#define UNARY 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 71 "part1.y"

    char *string;
    struct node *node;

#line 166 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
