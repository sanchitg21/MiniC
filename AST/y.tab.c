/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ast.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<ctype.h>

    #include "temp.c"
    extern FILE *yyin;
    int ex (nodeType *p, int flag);
    nodeType* opr(int oper, int nops, ...);
    nodeType* id(char *identifier);
    nodeType* con(char* value);

     struct node{
        char lexeme[100];
        char  token[100];
        int line_no;
        struct node *next;
    };

    struct ll{
        struct node *head;
        struct node *tail;
        int count;
    };

    struct ll *main_list = NULL;
    int mlc;


#line 103 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 280 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_LOR = 4,                        /* LOR  */
  YYSYMBOL_LAND = 5,                       /* LAND  */
  YYSYMBOL_EQ = 6,                         /* EQ  */
  YYSYMBOL_NE = 7,                         /* NE  */
  YYSYMBOL_LT = 8,                         /* LT  */
  YYSYMBOL_LE = 9,                         /* LE  */
  YYSYMBOL_GT = 10,                        /* GT  */
  YYSYMBOL_GE = 11,                        /* GE  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_MUL = 14,                       /* MUL  */
  YYSYMBOL_DIV = 15,                       /* DIV  */
  YYSYMBOL_MOD = 16,                       /* MOD  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_NUL = 18,                       /* NUL  */
  YYSYMBOL_GLOBAL = 19,                    /* GLOBAL  */
  YYSYMBOL_QM = 20,                        /* QM  */
  YYSYMBOL_FUNC_C = 21,                    /* FUNC_C  */
  YYSYMBOL_ID = 22,                        /* ID  */
  YYSYMBOL_INT_CONST = 23,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 24,               /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 25,                /* CHAR_CONST  */
  YYSYMBOL_FUNC_NAME = 26,                 /* FUNC_NAME  */
  YYSYMBOL_STRING_CONST = 27,              /* STRING_CONST  */
  YYSYMBOL_ARR = 28,                       /* ARR  */
  YYSYMBOL_ARR_D = 29,                     /* ARR_D  */
  YYSYMBOL_SIGNED_CONST = 30,              /* SIGNED_CONST  */
  YYSYMBOL_INT = 31,                       /* INT  */
  YYSYMBOL_FLOAT = 32,                     /* FLOAT  */
  YYSYMBOL_CHAR = 33,                      /* CHAR  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_RETURN = 38,                    /* RETURN  */
  YYSYMBOL_BREAK = 39,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 40,                  /* CONTINUE  */
  YYSYMBOL_CASE = 41,                      /* CASE  */
  YYSYMBOL_DEFAULT = 42,                   /* DEFAULT  */
  YYSYMBOL_SWITCH = 43,                    /* SWITCH  */
  YYSYMBOL_VOID = 44,                      /* VOID  */
  YYSYMBOL_PRINTF = 45,                    /* PRINTF  */
  YYSYMBOL_COLON = 46,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 47,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_LPAREN = 49,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 50,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 51,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 52,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 53,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 54,                  /* RBRACKET  */
  YYSYMBOL_HASH = 55,                      /* HASH  */
  YYSYMBOL_DQ = 56,                        /* DQ  */
  YYSYMBOL_ARR2D = 57,                     /* ARR2D  */
  YYSYMBOL_ARR_E = 58,                     /* ARR_E  */
  YYSYMBOL_TYPE_SPEC = 59,                 /* TYPE_SPEC  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_S = 61,                         /* S  */
  YYSYMBOL_begin = 62,                     /* begin  */
  YYSYMBOL_Type = 63,                      /* Type  */
  YYSYMBOL_Func_Decl = 64,                 /* Func_Decl  */
  YYSYMBOL_Para_List = 65,                 /* Para_List  */
  YYSYMBOL_Para = 66,                      /* Para  */
  YYSYMBOL_Stmt_List = 67,                 /* Stmt_List  */
  YYSYMBOL_Stmt = 68,                      /* Stmt  */
  YYSYMBOL_Brk_cnt = 69,                   /* Brk_cnt  */
  YYSYMBOL_For_stmt = 70,                  /* For_stmt  */
  YYSYMBOL_While_stmt = 71,                /* While_stmt  */
  YYSYMBOL_Switch_stmt = 72,               /* Switch_stmt  */
  YYSYMBOL_Case_stmt = 73,                 /* Case_stmt  */
  YYSYMBOL_Expr = 74,                      /* Expr  */
  YYSYMBOL_TERM = 75,                      /* TERM  */
  YYSYMBOL_FACTOR = 76,                    /* FACTOR  */
  YYSYMBOL_Assgn = 77,                     /* Assgn  */
  YYSYMBOL_Decl = 78,                      /* Decl  */
  YYSYMBOL_DECL_TAIL = 79,                 /* DECL_TAIL  */
  YYSYMBOL_If_stmt = 80,                   /* If_stmt  */
  YYSYMBOL_Return = 81,                    /* Return  */
  YYSYMBOL_Const = 82,                     /* Const  */
  YYSYMBOL_Print = 83,                     /* Print  */
  YYSYMBOL_Var_List = 84,                  /* Var_List  */
  YYSYMBOL_Func_Call = 85,                 /* Func_Call  */
  YYSYMBOL_Mixed_List = 86,                /* Mixed_List  */
  YYSYMBOL_ARR_DECL = 87                   /* ARR_DECL  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    67,    68,    71,    71,    71,    71,    74,
      75,    78,    78,    81,    84,    85,    86,    87,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     105,   106,   109,   110,   111,   114,   117,   120,   121,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   134,   135,
     136,   137,   138,   141,   142,   143,   146,   147,   148,   149,
     150,   151,   152,   153,   155,   158,   159,   160,   161,   164,
     165,   168,   169,   170,   173,   174,   175,   176,   177,   178,
     181,   182,   185,   186,   189,   190,   191,   192,   193,   194,
     197,   198,   199,   200,   202,   205
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN", "LOR",
  "LAND", "EQ", "NE", "LT", "LE", "GT", "GE", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "NOT", "NUL", "GLOBAL", "QM", "FUNC_C", "ID", "INT_CONST",
  "FLOAT_CONST", "CHAR_CONST", "FUNC_NAME", "STRING_CONST", "ARR", "ARR_D",
  "SIGNED_CONST", "INT", "FLOAT", "CHAR", "IF", "ELSE", "WHILE", "FOR",
  "RETURN", "BREAK", "CONTINUE", "CASE", "DEFAULT", "SWITCH", "VOID",
  "PRINTF", "COLON", "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "HASH", "DQ", "ARR2D", "ARR_E",
  "TYPE_SPEC", "$accept", "S", "begin", "Type", "Func_Decl", "Para_List",
  "Para", "Stmt_List", "Stmt", "Brk_cnt", "For_stmt", "While_stmt",
  "Switch_stmt", "Case_stmt", "Expr", "TERM", "FACTOR", "Assgn", "Decl",
  "DECL_TAIL", "If_stmt", "Return", "Const", "Print", "Var_List",
  "Func_Call", "Mixed_List", "ARR_DECL", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      55,  -124,  -124,  -124,  -124,     8,  -124,    -8,    55,  -124,
     -22,  -124,    26,   -40,     6,   -15,  -124,   222,  -124,    55,
       2,    29,  -124,  -124,  -124,    28,    19,  -124,    31,    35,
      56,   321,    36,    42,    60,    63,  -124,   301,   222,    -7,
      52,   222,  -124,  -124,  -124,  -124,    87,    88,  -124,    83,
      98,  -124,  -124,  -124,  -124,  -124,  -124,  -124,   222,   273,
     201,   111,   301,   301,   261,   100,    22,  -124,   102,  -124,
    -124,   128,    51,  -124,    32,   107,     4,   116,  -124,  -124,
    -124,   301,   301,   301,   301,   301,   301,   301,   301,   311,
     301,   301,   301,   301,  -124,  -124,   118,   122,   112,   125,
     127,   129,   126,   121,    40,    57,   175,   301,   161,   132,
     137,  -124,   164,  -124,   138,    23,  -124,   222,   289,   161,
     166,    88,    88,    88,    88,    88,    88,    88,    88,  -124,
    -124,  -124,  -124,  -124,  -124,   213,   311,   331,  -124,   331,
     143,     3,   141,   153,   301,   192,     7,   301,   301,   168,
     176,   206,   183,  -124,   184,   133,  -124,   178,   187,   190,
    -124,  -124,  -124,  -124,   301,   219,   222,   222,   311,   301,
     202,   210,   211,   -19,   220,   228,  -124,   252,   161,   -28,
    -124,   223,   147,   218,   227,   229,   237,   311,   311,   265,
     267,   254,   255,   206,   257,   259,   266,  -124,  -124,   286,
    -124,   311,   315,   285,  -124,   270,   277,   278,   276,   291,
     222,  -124,  -124,  -124,  -124,   293,   294,  -124,   301,   281,
     222,   296,   306,  -124,   222,  -124,  -124,   295,   157,   222,
     300,   222,   222,   -19,  -124,   311,   310,  -124,   312,   313,
    -124,  -124,  -124,  -124,  -124
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     6,     7,     8,     0,     2,     0,     4,     1,
       0,     3,     0,     0,     0,     0,    12,     0,    13,     0,
       0,    54,    74,    75,    76,     0,     0,    79,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    15,    22,    24,    25,    19,    57,    47,    52,     0,
       0,    26,    20,    55,    18,    21,    23,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,    31,
      30,     0,     0,    54,     0,     0,    67,     0,    64,    10,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,     0,     0,    58,    92,
       0,    93,     0,     0,     0,     0,    54,     0,     0,     0,
       0,    71,     0,    72,     0,     0,    53,    16,     0,     0,
       0,    45,    44,    46,    43,    39,    42,    40,    41,    59,
      48,    49,    50,    51,     9,     0,     0,     0,    86,     0,
       0,    77,     0,     0,     0,     0,    67,     0,     0,     0,
       0,     0,     0,    17,     0,    65,    68,     0,     0,     0,
      56,    90,    91,    87,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,    82,     0,    80,     0,     0,     0,
      88,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    94,     0,
      89,     0,    78,    69,    35,     0,     0,     0,     0,     0,
       0,    36,    83,    81,    85,     0,     0,    60,     0,     0,
       0,     0,     0,    78,     0,    38,    84,     0,    63,     0,
       0,     0,     0,     0,    95,     0,     0,    34,     0,     0,
      37,    62,    70,    32,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,   350,     5,  -124,  -124,   344,   -38,  -124,  -124,
    -124,  -124,  -124,   134,   -33,   288,    34,   -55,   302,  -118,
    -124,  -124,   -29,  -124,   185,  -124,  -123,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    39,     8,    15,    16,    40,    41,    42,
      43,    44,    45,   192,    46,    47,    48,    49,    50,    78,
      51,    52,    53,    54,   175,    55,   102,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      75,   156,    68,    80,    74,     7,   164,   118,     9,   109,
     169,    17,   159,     7,   161,    76,   162,    14,    10,   198,
      96,    77,   190,   191,    14,   199,    98,    12,    18,   104,
     105,   101,    59,    19,   129,    20,    81,    82,    83,    84,
      85,    86,    87,    88,    81,    82,    83,    84,    85,    86,
      87,    88,   119,    58,   196,   119,   165,     1,     2,     3,
     197,    81,    82,    83,    84,    85,    86,    87,    88,   108,
       4,   151,    61,   152,   145,   112,    13,    60,   115,   153,
      62,   160,   116,    69,    63,   155,     1,     2,     3,    70,
     142,    81,    82,    83,    84,    85,    86,    87,    88,     4,
      90,    91,    92,    93,    79,    64,   101,   143,   101,    71,
     101,    98,    72,   186,   170,   171,    81,    82,    83,    84,
      85,    86,    87,    88,   130,   131,   132,   133,   184,   185,
      94,   182,   206,   207,   103,    89,   155,    81,    82,    83,
      84,    85,    86,    87,    88,    95,   217,   111,   101,   113,
     114,    81,    82,    83,    84,    85,    86,    87,    88,   117,
     136,    81,    82,    83,    84,    85,    86,    87,    88,   120,
     134,   135,   225,   137,   138,   141,   140,   139,   144,   147,
     241,   178,   230,   146,   148,   228,   233,   149,   150,   157,
     163,   236,   166,   238,   239,   201,    81,    82,    83,    84,
      85,    86,    87,    88,   167,   235,    81,    82,    83,    84,
      85,    86,    87,    88,    81,    82,    83,    84,    85,    86,
      87,    88,   172,    99,    22,    23,    24,   173,   174,    66,
     176,    27,   179,   177,   180,    99,    22,    23,    24,   168,
     181,    66,   183,    27,    21,    22,    23,    24,    25,   187,
      26,   100,    27,     1,     2,     3,    28,   188,    29,    30,
      31,    32,    33,   158,   189,    34,     4,    35,   193,    36,
     200,    37,   202,    38,    99,    22,    23,    24,   194,   203,
      66,   204,    27,   106,    22,    23,    24,   205,   208,    26,
     209,    27,     1,     2,     3,    73,    22,    23,    24,    97,
     210,    66,   195,    27,   213,     4,   214,   211,   107,   216,
      37,    73,    22,    23,    24,   154,   215,    66,   218,    27,
     219,   220,    37,    73,    22,    23,    24,   221,   222,    66,
     223,    27,   229,   106,    22,    23,    24,   224,    37,    26,
     226,    27,   234,    65,    22,    23,    24,   231,   227,    66,
      37,    27,   237,    99,    22,    23,    24,   232,    11,    66,
      37,    27,   242,    57,   243,   244,   110,   240,    67,   121,
     122,   123,   124,   125,   126,   127,   128,     0,   212
};

static const yytype_int16 yycheck[] =
{
      38,   119,    31,    41,    37,     0,     3,     3,     0,    64,
       3,    51,   135,     8,   137,    22,   139,    12,    26,    47,
      58,    28,    41,    42,    19,    53,    59,    49,    22,    62,
      63,    60,     3,    48,    89,    50,     4,     5,     6,     7,
       8,     9,    10,    11,     4,     5,     6,     7,     8,     9,
      10,    11,    48,    51,   177,    48,    53,    31,    32,    33,
     178,     4,     5,     6,     7,     8,     9,    10,    11,    64,
      44,    48,    53,    50,   107,    53,    50,    49,    27,   117,
      49,   136,    50,    47,    49,   118,    31,    32,    33,    47,
      50,     4,     5,     6,     7,     8,     9,    10,    11,    44,
      12,    13,    14,    15,    52,    49,   135,    50,   137,    49,
     139,   144,    49,   168,   147,   148,     4,     5,     6,     7,
       8,     9,    10,    11,    90,    91,    92,    93,   166,   167,
      47,   164,   187,   188,    23,    48,   169,     4,     5,     6,
       7,     8,     9,    10,    11,    47,   201,    47,   177,    47,
      22,     4,     5,     6,     7,     8,     9,    10,    11,    52,
      48,     4,     5,     6,     7,     8,     9,    10,    11,    53,
      52,    49,   210,    48,    47,    54,    50,    48,     3,    47,
     235,    48,   220,    22,    47,   218,   224,    23,    50,    23,
      47,   229,    51,   231,   232,    48,     4,     5,     6,     7,
       8,     9,    10,    11,    51,    48,     4,     5,     6,     7,
       8,     9,    10,    11,     4,     5,     6,     7,     8,     9,
      10,    11,    54,    22,    23,    24,    25,    51,    22,    28,
      47,    30,    54,    49,    47,    22,    23,    24,    25,    47,
      50,    28,    23,    30,    22,    23,    24,    25,    26,    47,
      28,    50,    30,    31,    32,    33,    34,    47,    36,    37,
      38,    39,    40,    50,    53,    43,    44,    45,    48,    47,
      47,    49,    54,    51,    22,    23,    24,    25,    50,    52,
      28,    52,    30,    22,    23,    24,    25,    50,    23,    28,
      23,    30,    31,    32,    33,    22,    23,    24,    25,    26,
      46,    28,    50,    30,    47,    44,    47,    52,    47,    23,
      49,    22,    23,    24,    25,    26,    50,    28,     3,    30,
      35,    51,    49,    22,    23,    24,    25,    50,    50,    28,
      54,    30,    51,    22,    23,    24,    25,    46,    49,    28,
      47,    30,    47,    22,    23,    24,    25,    51,    54,    28,
      49,    30,    52,    22,    23,    24,    25,    51,     8,    28,
      49,    30,    52,    19,    52,    52,    64,   233,    47,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,   193
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    32,    33,    44,    61,    62,    63,    64,     0,
      26,    62,    49,    50,    63,    65,    66,    51,    22,    48,
      50,    22,    23,    24,    25,    26,    28,    30,    34,    36,
      37,    38,    39,    40,    43,    45,    47,    49,    51,    63,
      67,    68,    69,    70,    71,    72,    74,    75,    76,    77,
      78,    80,    81,    82,    83,    85,    87,    66,    51,     3,
      49,    53,    49,    49,    49,    22,    28,    47,    82,    47,
      47,    49,    49,    22,    74,    67,    22,    28,    79,    52,
      67,     4,     5,     6,     7,     8,     9,    10,    11,    48,
      12,    13,    14,    15,    47,    47,    67,    26,    74,    22,
      50,    82,    86,    23,    74,    74,    22,    47,    63,    77,
      78,    47,    53,    47,    22,    27,    50,    52,     3,    48,
      53,    75,    75,    75,    75,    75,    75,    75,    75,    77,
      76,    76,    76,    76,    52,    49,    48,    48,    47,    48,
      50,    54,    50,    50,     3,    74,    22,    47,    47,    23,
      50,    48,    50,    67,    26,    74,    79,    23,    50,    86,
      77,    86,    86,    47,     3,    53,    51,    51,    47,     3,
      74,    74,    54,    51,    22,    84,    47,    49,    48,    54,
      47,    50,    74,    23,    67,    67,    77,    47,    47,    53,
      41,    42,    73,    48,    50,    50,    86,    79,    47,    53,
      47,    48,    54,    52,    52,    50,    77,    77,    23,    23,
      46,    52,    84,    47,    47,    50,    23,    77,     3,    35,
      51,    50,    50,    54,    46,    67,    47,    54,    74,    51,
      67,    51,    51,    67,    47,    48,    67,    52,    67,    67,
      73,    77,    52,    52,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    67,    67,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    71,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      75,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    79,    79,    79,    79,    80,
      80,    81,    81,    81,    82,    82,    82,    82,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      86,    86,    86,    86,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     8,
       7,     3,     1,     2,     2,     1,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     2,    11,    11,    10,     7,     7,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     1,     1,     5,     1,     3,     3,
       8,     6,    11,     9,     2,     3,     5,     1,     3,     7,
      11,     3,     3,     2,     1,     1,     1,     4,     7,     1,
       5,     7,     1,     3,     8,     7,     4,     5,     6,     7,
       3,     3,     1,     1,     6,     9
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* S: begin  */
#line 64 "ast.y"
         {printf("reaching here\n"); ex((yyvsp[0].nPtr), 0);}
#line 1526 "y.tab.c"
    break;

  case 3: /* begin: Func_Decl begin  */
#line 67 "ast.y"
                         {(yyval.nPtr) = opr(GLOBAL, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1532 "y.tab.c"
    break;

  case 4: /* begin: Func_Decl  */
#line 68 "ast.y"
                  {printf("here as well\n");(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1538 "y.tab.c"
    break;

  case 9: /* Func_Decl: Type FUNC_NAME LPAREN Para_List RPAREN LBRACE Stmt_List RBRACE  */
#line 74 "ast.y"
                                                                           {(yyval.nPtr) = opr(FUNC_NAME, 3, id((yyvsp[-6].string)), (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}
#line 1544 "y.tab.c"
    break;

  case 10: /* Func_Decl: Type FUNC_NAME LPAREN RPAREN LBRACE Stmt_List RBRACE  */
#line 75 "ast.y"
                                                                 {(yyval.nPtr) = opr(FUNC_NAME, 3, id((yyvsp[-5].string)), opr(NUL, 0), (yyvsp[-1].nPtr));}
#line 1550 "y.tab.c"
    break;

  case 11: /* Para_List: Para_List COMMA Para  */
#line 78 "ast.y"
                                 {(yyval.nPtr) = opr(COMMA, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1556 "y.tab.c"
    break;

  case 12: /* Para_List: Para  */
#line 78 "ast.y"
                                                                     {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1562 "y.tab.c"
    break;

  case 13: /* Para: Type ID  */
#line 81 "ast.y"
               {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1568 "y.tab.c"
    break;

  case 14: /* Stmt_List: Stmt Stmt_List  */
#line 84 "ast.y"
                           {(yyval.nPtr) = opr(SEMICOLON, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1574 "y.tab.c"
    break;

  case 15: /* Stmt_List: Stmt  */
#line 85 "ast.y"
                   {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1580 "y.tab.c"
    break;

  case 16: /* Stmt_List: LBRACE Stmt_List RBRACE  */
#line 86 "ast.y"
                                      {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1586 "y.tab.c"
    break;

  case 17: /* Stmt_List: LBRACE Stmt_List RBRACE Stmt_List  */
#line 87 "ast.y"
                                                {(yyval.nPtr) = opr(SEMICOLON, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1592 "y.tab.c"
    break;

  case 18: /* Stmt: Print  */
#line 90 "ast.y"
             {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1598 "y.tab.c"
    break;

  case 20: /* Stmt: Return  */
#line 92 "ast.y"
                 {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1604 "y.tab.c"
    break;

  case 21: /* Stmt: Func_Call  */
#line 93 "ast.y"
                    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1610 "y.tab.c"
    break;

  case 22: /* Stmt: Brk_cnt  */
#line 94 "ast.y"
                  {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1616 "y.tab.c"
    break;

  case 23: /* Stmt: ARR_DECL  */
#line 95 "ast.y"
                   {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1622 "y.tab.c"
    break;

  case 24: /* Stmt: For_stmt  */
#line 96 "ast.y"
                   {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1628 "y.tab.c"
    break;

  case 25: /* Stmt: While_stmt  */
#line 97 "ast.y"
                     {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1634 "y.tab.c"
    break;

  case 26: /* Stmt: If_stmt  */
#line 98 "ast.y"
                  {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1640 "y.tab.c"
    break;

  case 27: /* Stmt: Assgn SEMICOLON  */
#line 99 "ast.y"
                          {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1646 "y.tab.c"
    break;

  case 28: /* Stmt: Decl SEMICOLON  */
#line 100 "ast.y"
                         {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1652 "y.tab.c"
    break;

  case 29: /* Stmt: SEMICOLON  */
#line 101 "ast.y"
                    {(yyval.nPtr) = opr(NUL, 0);}
#line 1658 "y.tab.c"
    break;

  case 30: /* Brk_cnt: CONTINUE SEMICOLON  */
#line 105 "ast.y"
                             {(yyval.nPtr) = opr(CONTINUE, 0);}
#line 1664 "y.tab.c"
    break;

  case 31: /* Brk_cnt: BREAK SEMICOLON  */
#line 106 "ast.y"
                          {(yyval.nPtr) = opr(BREAK, 0);}
#line 1670 "y.tab.c"
    break;

  case 32: /* For_stmt: FOR LPAREN Assgn SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE  */
#line 109 "ast.y"
                                                                                          {(yyval.nPtr) = opr(FOR, 4, (yyvsp[-8].nPtr), (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}
#line 1676 "y.tab.c"
    break;

  case 33: /* For_stmt: FOR LPAREN Decl SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE  */
#line 110 "ast.y"
                                                                                         {(yyval.nPtr) = opr(FOR, 4, (yyvsp[-8].nPtr), (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}
#line 1682 "y.tab.c"
    break;

  case 34: /* For_stmt: FOR LPAREN SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE  */
#line 111 "ast.y"
                                                                                    {{(yyval.nPtr) = opr(FOR, 4, opr(NUL, 0), (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}}
#line 1688 "y.tab.c"
    break;

  case 35: /* While_stmt: WHILE LPAREN Expr RPAREN LBRACE Stmt_List RBRACE  */
#line 114 "ast.y"
                                                              {(yyval.nPtr) = opr(WHILE, 2, (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}
#line 1694 "y.tab.c"
    break;

  case 36: /* Switch_stmt: SWITCH LPAREN ID RPAREN LBRACE Case_stmt RBRACE  */
#line 117 "ast.y"
                                                              {(yyval.nPtr) = opr(SWITCH, 2, id((yyvsp[-4].string)), (yyvsp[-1].nPtr));}
#line 1700 "y.tab.c"
    break;

  case 37: /* Case_stmt: CASE INT_CONST COLON Stmt_List Case_stmt  */
#line 120 "ast.y"
                                                     {(yyval.nPtr) = opr(CASE, 3, con((yyvsp[-3].string)), (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1706 "y.tab.c"
    break;

  case 38: /* Case_stmt: DEFAULT COLON Stmt_List  */
#line 121 "ast.y"
                              {(yyval.nPtr) = opr(DEFAULT, 1, (yyvsp[0].nPtr));}
#line 1712 "y.tab.c"
    break;

  case 39: /* Expr: Expr LT TERM  */
#line 123 "ast.y"
                    {(yyval.nPtr) = opr(LT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1718 "y.tab.c"
    break;

  case 40: /* Expr: Expr GT TERM  */
#line 124 "ast.y"
                    {(yyval.nPtr) = opr(GT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1724 "y.tab.c"
    break;

  case 41: /* Expr: Expr GE TERM  */
#line 125 "ast.y"
                    {(yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1730 "y.tab.c"
    break;

  case 42: /* Expr: Expr LE TERM  */
#line 126 "ast.y"
                    {(yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1736 "y.tab.c"
    break;

  case 43: /* Expr: Expr NE TERM  */
#line 127 "ast.y"
                    {(yyval.nPtr) = opr(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1742 "y.tab.c"
    break;

  case 44: /* Expr: Expr LAND TERM  */
#line 128 "ast.y"
                    {(yyval.nPtr) = opr(LAND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1748 "y.tab.c"
    break;

  case 45: /* Expr: Expr LOR TERM  */
#line 129 "ast.y"
                    {(yyval.nPtr) = opr(LOR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1754 "y.tab.c"
    break;

  case 46: /* Expr: Expr EQ TERM  */
#line 130 "ast.y"
                    {(yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1760 "y.tab.c"
    break;

  case 47: /* Expr: TERM  */
#line 131 "ast.y"
           {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1766 "y.tab.c"
    break;

  case 48: /* TERM: TERM PLUS FACTOR  */
#line 134 "ast.y"
                        {(yyval.nPtr) = opr(PLUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1772 "y.tab.c"
    break;

  case 49: /* TERM: TERM MINUS FACTOR  */
#line 135 "ast.y"
                        {(yyval.nPtr) = opr(MINUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1778 "y.tab.c"
    break;

  case 50: /* TERM: TERM MUL FACTOR  */
#line 136 "ast.y"
                        {(yyval.nPtr) = opr(MUL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1784 "y.tab.c"
    break;

  case 51: /* TERM: TERM DIV FACTOR  */
#line 137 "ast.y"
                        {(yyval.nPtr) = opr(DIV, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1790 "y.tab.c"
    break;

  case 53: /* FACTOR: LPAREN Expr RPAREN  */
#line 141 "ast.y"
                            {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1796 "y.tab.c"
    break;

  case 54: /* FACTOR: ID  */
#line 142 "ast.y"
             {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1802 "y.tab.c"
    break;

  case 55: /* FACTOR: Const  */
#line 143 "ast.y"
                {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1808 "y.tab.c"
    break;

  case 56: /* Assgn: ID ASSIGN Expr COMMA Assgn  */
#line 146 "ast.y"
                                   {(yyval.nPtr) = opr(COMMA, 2, opr(ASSIGN, 2, id((yyvsp[-4].string)), (yyvsp[-2].nPtr)), (yyvsp[0].nPtr));}
#line 1814 "y.tab.c"
    break;

  case 57: /* Assgn: Expr  */
#line 147 "ast.y"
               {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1820 "y.tab.c"
    break;

  case 58: /* Assgn: ID ASSIGN Expr  */
#line 148 "ast.y"
                         {(yyval.nPtr) = opr(ASSIGN, 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 1826 "y.tab.c"
    break;

  case 59: /* Assgn: Expr COMMA Assgn  */
#line 149 "ast.y"
                           {(yyval.nPtr) = opr(COMMA, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1832 "y.tab.c"
    break;

  case 60: /* Assgn: ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn  */
#line 150 "ast.y"
                                                                  {(yyval.nPtr) = opr(',', 2, opr('=', 2, opr(ARR, 3, id((yyvsp[-7].string)), opr(NUL, 0), con((yyvsp[-5].string))), (yyvsp[-2].nPtr)), (yyvsp[0].nPtr));}
#line 1838 "y.tab.c"
    break;

  case 61: /* Assgn: ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr  */
#line 151 "ast.y"
                                                    {(yyval.nPtr) = opr('=', 2, opr(ARR, 3, id((yyvsp[-5].string)), opr(NUL, 0), con((yyvsp[-3].string))), (yyvsp[0].nPtr));}
#line 1844 "y.tab.c"
    break;

  case 62: /* Assgn: ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn  */
#line 152 "ast.y"
                                                                                            {(yyval.nPtr) = opr(',', 2, opr('=', 2, opr(ARR, 3, id((yyvsp[-10].string)), con((yyvsp[-8].string)), con((yyvsp[-5].string))), (yyvsp[-2].nPtr)), (yyvsp[0].nPtr));}
#line 1850 "y.tab.c"
    break;

  case 63: /* Assgn: ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN Expr  */
#line 153 "ast.y"
                                                                                {(yyval.nPtr) = opr('=', 2, opr(ARR, 3, id((yyvsp[-8].string)), con((yyvsp[-6].string)), con((yyvsp[-3].string))), (yyvsp[0].nPtr));}
#line 1856 "y.tab.c"
    break;

  case 64: /* Decl: Type DECL_TAIL  */
#line 155 "ast.y"
                      {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1862 "y.tab.c"
    break;

  case 65: /* DECL_TAIL: ID ASSIGN Expr  */
#line 158 "ast.y"
                           {(yyval.nPtr) = opr(ASSIGN, 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 1868 "y.tab.c"
    break;

  case 66: /* DECL_TAIL: ID ASSIGN Expr COMMA DECL_TAIL  */
#line 159 "ast.y"
                                             {(yyval.nPtr) = opr(COMMA,2,opr(ASSIGN, 2, id((yyvsp[-4].string)), (yyvsp[-2].nPtr)),(yyvsp[0].nPtr));}
#line 1874 "y.tab.c"
    break;

  case 67: /* DECL_TAIL: ID  */
#line 160 "ast.y"
                 {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1880 "y.tab.c"
    break;

  case 68: /* DECL_TAIL: ID COMMA DECL_TAIL  */
#line 161 "ast.y"
                                 {(yyval.nPtr) = opr(COMMA, 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 1886 "y.tab.c"
    break;

  case 69: /* If_stmt: IF LPAREN Expr RPAREN LBRACE Stmt_List RBRACE  */
#line 164 "ast.y"
                                                        {(yyval.nPtr) = opr(IF, 2, (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}
#line 1892 "y.tab.c"
    break;

  case 70: /* If_stmt: IF LPAREN Expr RPAREN LBRACE Stmt_List RBRACE ELSE LBRACE Stmt_List RBRACE  */
#line 165 "ast.y"
                                                                                     {(yyval.nPtr) = opr(IF, 3, (yyvsp[-8].nPtr), (yyvsp[-5].nPtr), opr(ELSE, 1, (yyvsp[-1].nPtr)));}
#line 1898 "y.tab.c"
    break;

  case 71: /* Return: RETURN ID SEMICOLON  */
#line 168 "ast.y"
                             {(yyval.nPtr) = opr(RETURN, 1, id((yyvsp[-1].string)));}
#line 1904 "y.tab.c"
    break;

  case 72: /* Return: RETURN Const SEMICOLON  */
#line 169 "ast.y"
                                 {(yyval.nPtr) = opr(RETURN, 1, (yyvsp[-1].nPtr));}
#line 1910 "y.tab.c"
    break;

  case 73: /* Return: RETURN SEMICOLON  */
#line 170 "ast.y"
                               {(yyval.nPtr) = opr(RETURN, 1, opr(NUL, 0));}
#line 1916 "y.tab.c"
    break;

  case 74: /* Const: INT_CONST  */
#line 173 "ast.y"
                  {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1922 "y.tab.c"
    break;

  case 75: /* Const: FLOAT_CONST  */
#line 174 "ast.y"
                      {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1928 "y.tab.c"
    break;

  case 76: /* Const: CHAR_CONST  */
#line 175 "ast.y"
                     {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1934 "y.tab.c"
    break;

  case 77: /* Const: ARR LBRACKET INT_CONST RBRACKET  */
#line 176 "ast.y"
                                          {(yyval.nPtr) = opr(ARR, 3, id((yyvsp[-3].string)), opr(NUL,0), con((yyvsp[-1].string)));}
#line 1940 "y.tab.c"
    break;

  case 78: /* Const: ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET  */
#line 177 "ast.y"
                                                                    {(yyval.nPtr) = opr(ARR, 3, id((yyvsp[-6].string)), con((yyvsp[-4].string)), con((yyvsp[-1].string)));}
#line 1946 "y.tab.c"
    break;

  case 80: /* Print: PRINTF LPAREN STRING_CONST RPAREN SEMICOLON  */
#line 181 "ast.y"
                                                    {(yyval.nPtr) = opr(PRINTF, 1, con((yyvsp[-2].string)));}
#line 1952 "y.tab.c"
    break;

  case 81: /* Print: PRINTF LPAREN STRING_CONST COMMA Var_List RPAREN SEMICOLON  */
#line 182 "ast.y"
                                                                 {(yyval.nPtr) = opr(PRINTF, 2, con((yyvsp[-4].string)), (yyvsp[-2].nPtr));}
#line 1958 "y.tab.c"
    break;

  case 82: /* Var_List: ID  */
#line 185 "ast.y"
              {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1964 "y.tab.c"
    break;

  case 83: /* Var_List: ID COMMA Var_List  */
#line 186 "ast.y"
                                {(yyval.nPtr) = opr(COMMA, 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 1970 "y.tab.c"
    break;

  case 84: /* Func_Call: Type ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON  */
#line 189 "ast.y"
                                                                        {(yyval.nPtr) = opr(ASSIGN, 2, id((yyvsp[-6].string)), opr(FUNC_C, 2, id((yyvsp[-4].string)), (yyvsp[-2].nPtr)));}
#line 1976 "y.tab.c"
    break;

  case 85: /* Func_Call: Type ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON  */
#line 190 "ast.y"
                                                           {(yyval.nPtr) = opr(ASSIGN, 2, id((yyvsp[-5].string)), opr(FUNC_C, 1, id((yyvsp[-3].string))));}
#line 1982 "y.tab.c"
    break;

  case 86: /* Func_Call: FUNC_NAME LPAREN RPAREN SEMICOLON  */
#line 191 "ast.y"
                                            {(yyval.nPtr) = opr(FUNC_C, 1, id((yyvsp[-3].string)));}
#line 1988 "y.tab.c"
    break;

  case 87: /* Func_Call: FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON  */
#line 192 "ast.y"
                                                       {(yyval.nPtr) = opr(FUNC_C, 2, id((yyvsp[-4].string)), (yyvsp[-2].nPtr));}
#line 1994 "y.tab.c"
    break;

  case 88: /* Func_Call: ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON  */
#line 193 "ast.y"
                                                      {(yyval.nPtr) = opr(ASSIGN, 2, id((yyvsp[-5].string)), opr(FUNC_C, 1, id((yyvsp[-3].string))));}
#line 2000 "y.tab.c"
    break;

  case 89: /* Func_Call: ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON  */
#line 194 "ast.y"
                                                                 {(yyval.nPtr) = opr(ASSIGN, 2, id((yyvsp[-6].string)), opr(FUNC_C, 2, id((yyvsp[-4].string)), (yyvsp[-2].nPtr)));}
#line 2006 "y.tab.c"
    break;

  case 90: /* Mixed_List: ID COMMA Mixed_List  */
#line 197 "ast.y"
                                {(yyval.nPtr) = opr(COMMA, 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 2012 "y.tab.c"
    break;

  case 91: /* Mixed_List: Const COMMA Mixed_List  */
#line 198 "ast.y"
                                   {(yyval.nPtr) = opr(COMMA, 2, con((yyvsp[-2].nPtr)), (yyvsp[0].nPtr));}
#line 2018 "y.tab.c"
    break;

  case 92: /* Mixed_List: ID  */
#line 199 "ast.y"
               {(yyval.nPtr) = id((yyvsp[0].string));}
#line 2024 "y.tab.c"
    break;

  case 93: /* Mixed_List: Const  */
#line 200 "ast.y"
                {(yyval.nPtr) = con((yyvsp[0].nPtr));}
#line 2030 "y.tab.c"
    break;

  case 94: /* ARR_DECL: Type ARR LBRACKET INT_CONST RBRACKET SEMICOLON  */
#line 202 "ast.y"
                                                          {(yyval.nPtr) = opr(ARR, 3, id((yyvsp[-4].string)), opr(NUL, 0), con((yyvsp[-2].string)));}
#line 2036 "y.tab.c"
    break;

  case 95: /* ARR_DECL: Type ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET SEMICOLON  */
#line 205 "ast.y"
                                                                                      {(yyval.nPtr) = opr(ARR, 3, id((yyvsp[-7].string)), con((yyvsp[-5].string)), con((yyvsp[-2].string)));}
#line 2042 "y.tab.c"
    break;


#line 2046 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 223 "ast.y"



struct node *create_node(char *lexeme, char *token, int line_no){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->lexeme, lexeme);
    temp->line_no = line_no;
    strcpy(temp->token, token);
    temp->next = NULL;
    return temp;
}

void inserttoLL(char* lexeme, char* token, int line_no){
    struct node *temp = create_node(lexeme, token, line_no);
    if(main_list->head == NULL){
        main_list->head = temp;
        main_list->tail = temp;
    }
    else{
        main_list->tail->next = temp;
        main_list->tail = temp;
    }
    main_list->count++;
}

void dis(){
    struct node *temp = main_list->head;
    printf("--------------------------------------------------------------------\n");
    printf("Line No.\tLexeme\t\t\tToken\n");
    printf("--------------------------------------------------------------------\n");
    while(temp != NULL){
        printf("%d\t\t%s\t\t\t%s\n", temp->line_no, temp->lexeme, temp->token);
        temp = temp->next;
    }
    printf("--------------------------------------------------------------------\n");
}

int check_mlc()
{
    return 1;
}

void set_mlc()
{
    mlc = 1;
    return;
}

void reset_mlc()
{
    mlc = 0;
    return;
}

nodeType *con(char *value)
{
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
	strcpy(p->con.value, value);
    printf("The copied value %s\n", p->con.value);
	return p;
}

nodeType *id(char *identifier) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	strcpy(p->id.name,identifier);
//	printf("The copied identifier %s\n", p->id.name);
	return p;
}

nodeType *opr(int oper, int nops, ...)
{
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) +(nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
	return p;
}

int main(int argc , char *argv[]){
    yyin = fopen(argv[1],"r");
    main_list = (struct ll *)malloc(sizeof(struct ll));
    main_list->head = NULL;
    main_list->tail = NULL;
    main_list->count = 0;
    mlc = 0;
    yyparse();
    dis();
    return 0;
}

void yyerror(){
    printf("Invalid statement\n");
    exit(0);
}

