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
    ASSIGN = 258,                  /* ASSIGN  */
    LOR = 259,                     /* LOR  */
    LAND = 260,                    /* LAND  */
    EQ = 261,                      /* EQ  */
    NE = 262,                      /* NE  */
    LT = 263,                      /* LT  */
    LE = 264,                      /* LE  */
    GT = 265,                      /* GT  */
    GE = 266,                      /* GE  */
    PLUS = 267,                    /* PLUS  */
    MINUS = 268,                   /* MINUS  */
    MUL = 269,                     /* MUL  */
    DIV = 270,                     /* DIV  */
    MOD = 271,                     /* MOD  */
    NOT = 272,                     /* NOT  */
    NUL = 273,                     /* NUL  */
    GLOBAL = 274,                  /* GLOBAL  */
    QM = 275,                      /* QM  */
    FUNC_C = 276,                  /* FUNC_C  */
    ID = 277,                      /* ID  */
    INT_CONST = 278,               /* INT_CONST  */
    FLOAT_CONST = 279,             /* FLOAT_CONST  */
    CHAR_CONST = 280,              /* CHAR_CONST  */
    FUNC_NAME = 281,               /* FUNC_NAME  */
    STRING_CONST = 282,            /* STRING_CONST  */
    ARR = 283,                     /* ARR  */
    ARR_D = 284,                   /* ARR_D  */
    SIGNED_CONST = 285,            /* SIGNED_CONST  */
    INT = 286,                     /* INT  */
    FLOAT = 287,                   /* FLOAT  */
    CHAR = 288,                    /* CHAR  */
    IF = 289,                      /* IF  */
    ELSE = 290,                    /* ELSE  */
    WHILE = 291,                   /* WHILE  */
    FOR = 292,                     /* FOR  */
    RETURN = 293,                  /* RETURN  */
    BREAK = 294,                   /* BREAK  */
    CONTINUE = 295,                /* CONTINUE  */
    CASE = 296,                    /* CASE  */
    DEFAULT = 297,                 /* DEFAULT  */
    SWITCH = 298,                  /* SWITCH  */
    VOID = 299,                    /* VOID  */
    PRINTF = 300,                  /* PRINTF  */
    COLON = 301,                   /* COLON  */
    SEMICOLON = 302,               /* SEMICOLON  */
    COMMA = 303,                   /* COMMA  */
    LPAREN = 304,                  /* LPAREN  */
    RPAREN = 305,                  /* RPAREN  */
    LBRACE = 306,                  /* LBRACE  */
    RBRACE = 307,                  /* RBRACE  */
    LBRACKET = 308,                /* LBRACKET  */
    RBRACKET = 309,                /* RBRACKET  */
    HASH = 310,                    /* HASH  */
    DQ = 311,                      /* DQ  */
    ARR2D = 312,                   /* ARR2D  */
    ARR_E = 313,                   /* ARR_E  */
    TYPE_SPEC = 314                /* TYPE_SPEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ASSIGN 258
#define LOR 259
#define LAND 260
#define EQ 261
#define NE 262
#define LT 263
#define LE 264
#define GT 265
#define GE 266
#define PLUS 267
#define MINUS 268
#define MUL 269
#define DIV 270
#define MOD 271
#define NOT 272
#define NUL 273
#define GLOBAL 274
#define QM 275
#define FUNC_C 276
#define ID 277
#define INT_CONST 278
#define FLOAT_CONST 279
#define CHAR_CONST 280
#define FUNC_NAME 281
#define STRING_CONST 282
#define ARR 283
#define ARR_D 284
#define SIGNED_CONST 285
#define INT 286
#define FLOAT 287
#define CHAR 288
#define IF 289
#define ELSE 290
#define WHILE 291
#define FOR 292
#define RETURN 293
#define BREAK 294
#define CONTINUE 295
#define CASE 296
#define DEFAULT 297
#define SWITCH 298
#define VOID 299
#define PRINTF 300
#define COLON 301
#define SEMICOLON 302
#define COMMA 303
#define LPAREN 304
#define RPAREN 305
#define LBRACE 306
#define RBRACE 307
#define LBRACKET 308
#define RBRACKET 309
#define HASH 310
#define DQ 311
#define ARR2D 312
#define ARR_E 313
#define TYPE_SPEC 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "ast.y"

    int ival;
    nodeType *nPtr;
    char string[100];

#line 191 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
