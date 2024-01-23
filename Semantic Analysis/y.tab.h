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
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MUL = 260,                     /* MUL  */
    DIV = 261,                     /* DIV  */
    MOD = 262,                     /* MOD  */
    LOR = 263,                     /* LOR  */
    LAND = 264,                    /* LAND  */
    EQ = 265,                      /* EQ  */
    NE = 266,                      /* NE  */
    LT = 267,                      /* LT  */
    LE = 268,                      /* LE  */
    GT = 269,                      /* GT  */
    GE = 270,                      /* GE  */
    NOT = 271,                     /* NOT  */
    ASSIGN = 272,                  /* ASSIGN  */
    ARR = 273,                     /* ARR  */
    ID = 274,                      /* ID  */
    STRING_CONST = 275,            /* STRING_CONST  */
    INT_CONST = 276,               /* INT_CONST  */
    FLOAT_CONST = 277,             /* FLOAT_CONST  */
    CHAR_CONST = 278,              /* CHAR_CONST  */
    SIGNED_CONST = 279,            /* SIGNED_CONST  */
    FUNC_NAME = 280,               /* FUNC_NAME  */
    INT = 281,                     /* INT  */
    FLOAT = 282,                   /* FLOAT  */
    CHAR = 283,                    /* CHAR  */
    IF = 284,                      /* IF  */
    ELSE = 285,                    /* ELSE  */
    WHILE = 286,                   /* WHILE  */
    FOR = 287,                     /* FOR  */
    RETURN = 288,                  /* RETURN  */
    BREAK = 289,                   /* BREAK  */
    CONTINUE = 290,                /* CONTINUE  */
    CASE = 291,                    /* CASE  */
    DEFAULT = 292,                 /* DEFAULT  */
    SWITCH = 293,                  /* SWITCH  */
    VOID = 294,                    /* VOID  */
    MAIN = 295,                    /* MAIN  */
    PRINTF = 296,                  /* PRINTF  */
    SEMICOLON = 297,               /* SEMICOLON  */
    COMMA = 298,                   /* COMMA  */
    LPAREN = 299,                  /* LPAREN  */
    RPAREN = 300,                  /* RPAREN  */
    LBRACE = 301,                  /* LBRACE  */
    RBRACE = 302,                  /* RBRACE  */
    LBRACKET = 303,                /* LBRACKET  */
    RBRACKET = 304,                /* RBRACKET  */
    HASH = 305,                    /* HASH  */
    DQ = 306,                      /* DQ  */
    COLON = 307,                   /* COLON  */
    ARR2D = 308,                   /* ARR2D  */
    ARR_E = 309,                   /* ARR_E  */
    TYPE_SPEC = 310                /* TYPE_SPEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PLUS 258
#define MINUS 259
#define MUL 260
#define DIV 261
#define MOD 262
#define LOR 263
#define LAND 264
#define EQ 265
#define NE 266
#define LT 267
#define LE 268
#define GT 269
#define GE 270
#define NOT 271
#define ASSIGN 272
#define ARR 273
#define ID 274
#define STRING_CONST 275
#define INT_CONST 276
#define FLOAT_CONST 277
#define CHAR_CONST 278
#define SIGNED_CONST 279
#define FUNC_NAME 280
#define INT 281
#define FLOAT 282
#define CHAR 283
#define IF 284
#define ELSE 285
#define WHILE 286
#define FOR 287
#define RETURN 288
#define BREAK 289
#define CONTINUE 290
#define CASE 291
#define DEFAULT 292
#define SWITCH 293
#define VOID 294
#define MAIN 295
#define PRINTF 296
#define SEMICOLON 297
#define COMMA 298
#define LPAREN 299
#define RPAREN 300
#define LBRACE 301
#define RBRACE 302
#define LBRACKET 303
#define RBRACKET 304
#define HASH 305
#define DQ 306
#define COLON 307
#define ARR2D 308
#define ARR_E 309
#define TYPE_SPEC 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "sem_parser.y"

    struct{
        char *lexeme;
        float val;
    }n;

#line 184 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
