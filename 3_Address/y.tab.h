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
    PLUS = 259,                    /* PLUS  */
    MINUS = 260,                   /* MINUS  */
    MUL = 261,                     /* MUL  */
    DIV = 262,                     /* DIV  */
    MOD = 263,                     /* MOD  */
    ARR = 264,                     /* ARR  */
    ARR2D = 265,                   /* ARR2D  */
    SIGNED_CONST = 266,            /* SIGNED_CONST  */
    HASH = 267,                    /* HASH  */
    DQ = 268,                      /* DQ  */
    TYPE_SPEC = 269,               /* TYPE_SPEC  */
    ARR_E = 270,                   /* ARR_E  */
    LPAREN = 271,                  /* LPAREN  */
    RPAREN = 272,                  /* RPAREN  */
    LBRACE = 273,                  /* LBRACE  */
    RBRACE = 274,                  /* RBRACE  */
    LBRACKET = 275,                /* LBRACKET  */
    RBRACKET = 276,                /* RBRACKET  */
    SEMICOLON = 277,               /* SEMICOLON  */
    COMMA = 278,                   /* COMMA  */
    COLON = 279,                   /* COLON  */
    IF = 280,                      /* IF  */
    ELSE = 281,                    /* ELSE  */
    WHILE = 282,                   /* WHILE  */
    FOR = 283,                     /* FOR  */
    SWITCH = 284,                  /* SWITCH  */
    CONTINUE = 285,                /* CONTINUE  */
    BREAK = 286,                   /* BREAK  */
    RETURN = 287,                  /* RETURN  */
    PRINTF = 288,                  /* PRINTF  */
    DEFAULT = 289,                 /* DEFAULT  */
    CASE = 290,                    /* CASE  */
    INT = 291,                     /* INT  */
    FLOAT = 292,                   /* FLOAT  */
    CHAR = 293,                    /* CHAR  */
    VOID = 294,                    /* VOID  */
    GE = 295,                      /* GE  */
    LE = 296,                      /* LE  */
    NE = 297,                      /* NE  */
    LAND = 298,                    /* LAND  */
    LOR = 299,                     /* LOR  */
    NOT = 300,                     /* NOT  */
    EQ = 301,                      /* EQ  */
    LT = 302,                      /* LT  */
    GT = 303,                      /* GT  */
    ID = 304,                      /* ID  */
    INT_CONST = 305,               /* INT_CONST  */
    FLOAT_CONST = 306,             /* FLOAT_CONST  */
    CHAR_CONST = 307,              /* CHAR_CONST  */
    FUNC_NAME = 308,               /* FUNC_NAME  */
    STRING_CONST = 309             /* STRING_CONST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ASSIGN 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define ARR 264
#define ARR2D 265
#define SIGNED_CONST 266
#define HASH 267
#define DQ 268
#define TYPE_SPEC 269
#define ARR_E 270
#define LPAREN 271
#define RPAREN 272
#define LBRACE 273
#define RBRACE 274
#define LBRACKET 275
#define RBRACKET 276
#define SEMICOLON 277
#define COMMA 278
#define COLON 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define FOR 283
#define SWITCH 284
#define CONTINUE 285
#define BREAK 286
#define RETURN 287
#define PRINTF 288
#define DEFAULT 289
#define CASE 290
#define INT 291
#define FLOAT 292
#define CHAR 293
#define VOID 294
#define GE 295
#define LE 296
#define NE 297
#define LAND 298
#define LOR 299
#define NOT 300
#define EQ 301
#define LT 302
#define GT 303
#define ID 304
#define INT_CONST 305
#define FLOAT_CONST 306
#define CHAR_CONST 307
#define FUNC_NAME 308
#define STRING_CONST 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "three.y"

    char* lexeme;

#line 179 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
