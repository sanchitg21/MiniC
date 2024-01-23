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
#line 1 "sem_parser.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<ctype.h>
    #include<limits.h>
    extern FILE *yyin;
    #include "table.c"

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

        
    int list_c = 0;
    char *listType[100];
    char *returnType_func = "VOID";
    
    void insertEntry(char* t);


#line 106 "y.tab.c"

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

#line 276 "y.tab.c"

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
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MUL = 5,                        /* MUL  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_MOD = 7,                        /* MOD  */
  YYSYMBOL_LOR = 8,                        /* LOR  */
  YYSYMBOL_LAND = 9,                       /* LAND  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_NE = 11,                        /* NE  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_LE = 13,                        /* LE  */
  YYSYMBOL_GT = 14,                        /* GT  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_NOT = 16,                       /* NOT  */
  YYSYMBOL_ASSIGN = 17,                    /* ASSIGN  */
  YYSYMBOL_ARR = 18,                       /* ARR  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_STRING_CONST = 20,              /* STRING_CONST  */
  YYSYMBOL_INT_CONST = 21,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 22,               /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 23,                /* CHAR_CONST  */
  YYSYMBOL_SIGNED_CONST = 24,              /* SIGNED_CONST  */
  YYSYMBOL_FUNC_NAME = 25,                 /* FUNC_NAME  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_FLOAT = 27,                     /* FLOAT  */
  YYSYMBOL_CHAR = 28,                      /* CHAR  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_BREAK = 34,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 35,                  /* CONTINUE  */
  YYSYMBOL_CASE = 36,                      /* CASE  */
  YYSYMBOL_DEFAULT = 37,                   /* DEFAULT  */
  YYSYMBOL_SWITCH = 38,                    /* SWITCH  */
  YYSYMBOL_VOID = 39,                      /* VOID  */
  YYSYMBOL_MAIN = 40,                      /* MAIN  */
  YYSYMBOL_PRINTF = 41,                    /* PRINTF  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_LPAREN = 44,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 45,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 46,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 47,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 48,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 49,                  /* RBRACKET  */
  YYSYMBOL_HASH = 50,                      /* HASH  */
  YYSYMBOL_DQ = 51,                        /* DQ  */
  YYSYMBOL_COLON = 52,                     /* COLON  */
  YYSYMBOL_ARR2D = 53,                     /* ARR2D  */
  YYSYMBOL_ARR_E = 54,                     /* ARR_E  */
  YYSYMBOL_TYPE_SPEC = 55,                 /* TYPE_SPEC  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_S = 57,                         /* S  */
  YYSYMBOL_begin = 58,                     /* begin  */
  YYSYMBOL_Type = 59,                      /* Type  */
  YYSYMBOL_Func_Decl = 60,                 /* Func_Decl  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_Para_List = 63,                 /* Para_List  */
  YYSYMBOL_Stmt_List = 64,                 /* Stmt_List  */
  YYSYMBOL_Stmt = 65,                      /* Stmt  */
  YYSYMBOL_Switch_stmt = 66,               /* Switch_stmt  */
  YYSYMBOL_Case_stmt = 67,                 /* Case_stmt  */
  YYSYMBOL_Brk_cnt = 68,                   /* Brk_cnt  */
  YYSYMBOL_For_stmt = 69,                  /* For_stmt  */
  YYSYMBOL_While_stmt = 70,                /* While_stmt  */
  YYSYMBOL_Expr = 71,                      /* Expr  */
  YYSYMBOL_COMP_OP = 72,                   /* COMP_OP  */
  YYSYMBOL_TERM = 73,                      /* TERM  */
  YYSYMBOL_FACTOR = 74,                    /* FACTOR  */
  YYSYMBOL_Assgn = 75,                     /* Assgn  */
  YYSYMBOL_ASSGN_TAIL = 76,                /* ASSGN_TAIL  */
  YYSYMBOL_Decl = 77,                      /* Decl  */
  YYSYMBOL_DECL_TAIL = 78,                 /* DECL_TAIL  */
  YYSYMBOL_If_stmt = 79,                   /* If_stmt  */
  YYSYMBOL_MAT = 80,                       /* MAT  */
  YYSYMBOL_UNMAT = 81,                     /* UNMAT  */
  YYSYMBOL_Return = 82,                    /* Return  */
  YYSYMBOL_Const = 83,                     /* Const  */
  YYSYMBOL_Print = 84,                     /* Print  */
  YYSYMBOL_Var_List = 85,                  /* Var_List  */
  YYSYMBOL_Func_Call = 86,                 /* Func_Call  */
  YYSYMBOL_Mixed_List = 87,                /* Mixed_List  */
  YYSYMBOL_Arr_Decl = 88                   /* Arr_Decl  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


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
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    58,    59,    62,    63,    64,    65,    68,
      68,    69,    69,    72,    73,    76,    77,    78,    79,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    86,    88,    89,    91,    91,    94,    95,    96,
      99,   102,   110,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   124,   125,   126,   127,   128,   129,   132,   133,
     147,   150,   151,   152,   153,   154,   156,   157,   160,   161,
     164,   165,   166,   169,   169,   172,   175,   178,   179,   180,
     183,   184,   185,   186,   187,   188,   191,   192,   197,   198,
     200,   203,   206,   207,   211,   214,   219,   220,   221,   222,
     224,   227
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
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "LOR", "LAND", "EQ", "NE", "LT", "LE", "GT", "GE", "NOT",
  "ASSIGN", "ARR", "ID", "STRING_CONST", "INT_CONST", "FLOAT_CONST",
  "CHAR_CONST", "SIGNED_CONST", "FUNC_NAME", "INT", "FLOAT", "CHAR", "IF",
  "ELSE", "WHILE", "FOR", "RETURN", "BREAK", "CONTINUE", "CASE", "DEFAULT",
  "SWITCH", "VOID", "MAIN", "PRINTF", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "HASH", "DQ",
  "COLON", "ARR2D", "ARR_E", "TYPE_SPEC", "$accept", "S", "begin", "Type",
  "Func_Decl", "$@1", "$@2", "Para_List", "Stmt_List", "Stmt",
  "Switch_stmt", "Case_stmt", "Brk_cnt", "For_stmt", "While_stmt", "Expr",
  "COMP_OP", "TERM", "FACTOR", "Assgn", "ASSGN_TAIL", "Decl", "DECL_TAIL",
  "If_stmt", "MAT", "UNMAT", "Return", "Const", "Print", "Var_List",
  "Func_Call", "Mixed_List", "Arr_Decl", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-154)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      45,  -154,  -154,  -154,  -154,    16,  -154,   -17,    45,  -154,
     -21,  -154,    45,    49,   -18,    26,  -154,    28,    45,    31,
     250,    66,    40,    42,    79,  -154,  -154,  -154,  -154,    62,
      65,    72,    73,   215,    76,    77,    83,    93,  -154,    70,
     250,    60,    86,   250,  -154,  -154,  -154,  -154,   349,   171,
    -154,   100,   104,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,   250,   123,   293,   102,    70,    70,   314,   101,
     106,  -154,   108,  -154,  -154,   133,   134,  -154,    22,   135,
     105,     7,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,    70,    70,    70,    70,    70,    70,  -154,
    -154,   136,   131,   137,    89,   150,   152,   154,   153,    32,
      50,   147,   182,    70,   183,   161,   193,   219,  -154,  -154,
     197,   -34,  -154,   250,   222,   304,   225,  -154,   171,  -154,
    -154,  -154,  -154,  -154,  -154,     1,   279,   226,  -154,   117,
    -154,   117,   204,   201,   202,   229,    70,   207,     8,    70,
      70,   203,   205,   234,   212,  -154,   206,   236,   148,    37,
      70,   235,   228,   241,   270,  -154,  -154,  -154,   250,   250,
     246,    63,    70,   216,   251,   242,    19,   256,   261,  -154,
     -29,   286,  -154,    70,  -154,   157,   264,  -154,   277,    70,
     273,   274,     4,   285,    63,    63,   313,   315,   283,   291,
     234,   297,  -154,   322,   302,   300,   148,    63,   329,  -154,
      89,   317,  -154,   328,   305,   307,   309,   301,   303,   250,
    -154,  -154,  -154,   318,  -154,   324,  -154,  -154,    70,  -154,
     323,   319,   250,   325,   326,  -154,   250,  -154,   331,  -154,
     198,   250,   329,   327,   250,   250,    19,  -154,    63,   330,
    -154,   332,   333,  -154,  -154,  -154,  -154,  -154
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     6,     7,     8,     0,     2,     0,     4,     1,
       0,     3,    11,     0,     0,     9,    14,     0,     0,     0,
       0,     0,     0,     0,    59,    80,    81,    82,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,    18,    29,    22,    24,    26,    25,    42,
      57,     0,     0,    27,    73,    74,    20,    60,    19,    21,
      23,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,    36,    35,     0,     0,    59,     0,     0,
       0,    72,    12,    17,    49,    48,    51,    47,    44,    46,
      43,    45,    50,     0,     0,     0,     0,     0,     0,    28,
      30,     0,     0,     0,    67,    98,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
       0,     0,    58,    15,     0,     0,     0,    69,    41,    52,
      53,    54,    55,    56,    10,    83,     0,     0,    61,     0,
      92,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,     0,     0,     0,     0,    16,     0,     0,    72,    72,
       0,     0,     0,     0,     0,    96,    97,    93,     0,     0,
       0,     0,     0,     0,     0,    83,     0,    88,     0,    86,
       0,     0,    68,     0,    70,    63,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,    72,     0,    84,    95,
      67,    75,    40,     0,     0,     0,     0,     0,     0,     0,
      32,    89,    87,     0,    91,     0,    71,    62,     0,    66,
       0,     0,     0,     0,     0,    84,     0,    34,     0,    90,
      65,     0,     0,     0,     0,     0,     0,   101,     0,     0,
      39,     0,     0,    33,    64,    76,    37,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,   362,     2,  -154,  -154,  -154,  -154,   -40,  -154,
    -154,   129,  -154,  -154,  -154,   -38,  -154,   288,    91,   -64,
     166,   310,  -153,  -154,  -154,  -154,  -154,   -26,  -154,   184,
    -154,  -124,  -154
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    41,     8,    19,    14,    15,    42,    43,
      44,   199,    45,    46,    47,    48,    93,    49,    50,    51,
     138,    52,   127,    53,    54,    55,    56,    57,    58,   178,
      59,   108,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    78,     7,    83,   115,   182,   184,    72,    10,   153,
       7,   154,   163,   202,    13,   165,     9,   166,   160,   203,
      21,   160,   101,    12,   125,   172,   104,    17,   109,   110,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   107,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   161,
     126,   126,   213,   226,   183,   197,   198,   205,    84,    85,
      86,    87,    88,    89,    90,    91,    92,   122,    16,    18,
     114,     1,     2,     3,    20,   147,    22,   143,    80,    81,
     126,   111,   112,   155,     4,    61,    62,   158,    69,    77,
      63,    25,    26,    27,    28,   144,    64,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    65,   193,   104,    66,
     107,   173,   174,   107,    39,   107,    67,    68,    73,    74,
      69,   105,   185,    25,    26,    27,    28,    75,   190,   191,
     215,   216,   137,    82,   158,    69,   105,    76,    25,    26,
      27,    28,    99,   227,   102,   206,   100,   106,   118,   117,
     119,   210,   120,   124,   121,   107,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    94,    95,    96,    97,    98,   237,
     135,   136,   123,   134,   254,   129,   130,   131,   132,   133,
     240,   126,   243,   139,   140,   145,   246,   141,   142,   146,
     207,   249,   148,   149,   251,   252,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    69,    70,   150,    25,    26,    27,    28,
     151,   248,   152,   156,   159,   164,   167,   168,   169,   171,
     170,   176,   175,   177,   179,   180,   186,    71,   194,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    23,    24,
     187,    25,    26,    27,    28,    29,     1,     2,     3,    30,
     181,    31,    32,    33,    34,    35,   188,   189,    36,     4,
     196,    37,    38,   195,    39,   192,    40,    69,   105,   200,
      25,    26,    27,    28,    69,   105,   201,    25,    26,    27,
      28,    69,    77,   208,    25,    26,    27,    28,   103,   209,
     211,   212,    69,    77,   162,    25,    26,    27,    28,   157,
     214,   204,   111,   112,   217,   219,   218,    39,   220,   222,
       1,     2,     3,   223,   224,   225,   228,   230,    39,   231,
     235,   232,   233,     4,   234,   236,   113,    84,    85,    86,
      87,    88,    89,    90,    91,    92,   239,   238,   242,   241,
      11,   244,   245,   247,   250,   253,   229,   255,   116,   256,
     257,   128,     0,     0,   221
};

static const yytype_int16 yycheck[] =
{
      40,    39,     0,    43,    68,   158,   159,    33,    25,    43,
       8,    45,   136,    42,    12,   139,     0,   141,    17,    48,
      18,    17,    62,    44,    17,    17,    64,    45,    66,    67,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    65,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    48,
      43,    43,    48,   206,    17,    36,    37,   181,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    45,    19,    43,
      68,    26,    27,    28,    46,   113,    45,    45,    18,    19,
      43,    18,    19,   123,    39,    19,    46,   125,    18,    19,
      48,    21,    22,    23,    24,    45,    17,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    44,   171,   146,    44,
     136,   149,   150,   139,    44,   141,    44,    44,    42,    42,
      18,    19,   160,    21,    22,    23,    24,    44,   168,   169,
     194,   195,    43,    47,   172,    18,    19,    44,    21,    22,
      23,    24,    42,   207,    21,   183,    42,    45,    42,    48,
      42,   189,    19,    48,    20,   181,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     3,     4,     5,     6,     7,   219,
      49,    44,    47,    47,   248,    94,    95,    96,    97,    98,
     228,    43,   232,    43,    42,    48,   236,    43,    45,    17,
      43,   241,    19,    42,   244,   245,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    18,    19,    42,    21,    22,    23,    24,
      21,    43,    45,    21,    19,    19,    42,    46,    46,    42,
      21,    46,    49,    19,    42,    49,    21,    42,    42,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    18,    19,
      42,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      44,    31,    32,    33,    34,    35,    45,    17,    38,    39,
      48,    41,    42,    42,    44,    49,    46,    18,    19,    43,
      21,    22,    23,    24,    18,    19,    45,    21,    22,    23,
      24,    18,    19,    49,    21,    22,    23,    24,    25,    42,
      47,    47,    18,    19,    45,    21,    22,    23,    24,    25,
      45,    45,    18,    19,    21,    52,    21,    44,    47,    42,
      26,    27,    28,    21,    42,    45,    17,    30,    44,    21,
      49,    46,    45,    39,    45,    52,    42,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    42,    49,    49,    46,
       8,    46,    46,    42,    47,   246,   210,    47,    68,    47,
      47,    93,    -1,    -1,   200
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    27,    28,    39,    57,    58,    59,    60,     0,
      25,    58,    44,    59,    62,    63,    19,    45,    43,    61,
      46,    59,    45,    18,    19,    21,    22,    23,    24,    25,
      29,    31,    32,    33,    34,    35,    38,    41,    42,    44,
      46,    59,    64,    65,    66,    68,    69,    70,    71,    73,
      74,    75,    77,    79,    80,    81,    82,    83,    84,    86,
      88,    19,    46,    48,    17,    44,    44,    44,    44,    18,
      19,    42,    83,    42,    42,    44,    44,    19,    71,    64,
      18,    19,    47,    64,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    72,     3,     4,     5,     6,     7,    42,
      42,    64,    21,    25,    71,    19,    45,    83,    87,    71,
      71,    18,    19,    42,    59,    75,    77,    48,    42,    42,
      19,    20,    45,    47,    48,    17,    43,    78,    73,    74,
      74,    74,    74,    74,    47,    49,    44,    43,    76,    43,
      42,    43,    45,    45,    45,    48,    17,    71,    19,    42,
      42,    21,    45,    43,    45,    64,    21,    25,    71,    19,
      17,    48,    45,    87,    19,    87,    87,    42,    46,    46,
      21,    42,    17,    71,    71,    49,    46,    19,    85,    42,
      49,    44,    78,    17,    78,    71,    21,    42,    45,    17,
      64,    64,    49,    75,    42,    42,    48,    36,    37,    67,
      43,    45,    42,    48,    45,    87,    71,    43,    49,    42,
      71,    47,    47,    48,    45,    75,    75,    21,    21,    52,
      47,    85,    42,    21,    42,    45,    78,    75,    17,    76,
      30,    21,    46,    45,    45,    49,    52,    64,    49,    42,
      71,    46,    49,    64,    46,    46,    64,    42,    43,    64,
      47,    64,    64,    67,    75,    47,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    61,
      60,    62,    60,    63,    63,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    67,    67,    68,    68,    69,    69,    69,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    79,    79,    80,    81,    82,    82,    82,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86,    86,    86,    87,    87,    87,    87,
      88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     0,
       9,     0,     8,     4,     2,     3,     4,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     7,     5,     3,     2,     2,    11,    11,    10,
       7,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     1,     3,     1,
       1,     4,     8,     6,    11,     9,     5,     0,     5,     3,
       3,     5,     0,     1,     1,     7,    11,     3,     3,     2,
       1,     1,     1,     4,     7,     1,     5,     7,     1,     3,
       8,     7,     4,     5,     6,     7,     3,     3,     1,     1,
       6,     9
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
#line 55 "sem_parser.y"
         {printf("reaching here\n");}
#line 1533 "y.tab.c"
    break;

  case 4: /* begin: Func_Decl  */
#line 59 "sem_parser.y"
                  {printf("here as well\n");}
#line 1539 "y.tab.c"
    break;

  case 5: /* Type: INT  */
#line 62 "sem_parser.y"
           {(yyval.n).lexeme = "INT";}
#line 1545 "y.tab.c"
    break;

  case 6: /* Type: FLOAT  */
#line 63 "sem_parser.y"
            {(yyval.n).lexeme = "FLOAT";}
#line 1551 "y.tab.c"
    break;

  case 7: /* Type: CHAR  */
#line 64 "sem_parser.y"
           {(yyval.n).lexeme = "CHAR";}
#line 1557 "y.tab.c"
    break;

  case 8: /* Type: VOID  */
#line 65 "sem_parser.y"
           {(yyval.n).lexeme = "VOID";}
#line 1563 "y.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 68 "sem_parser.y"
                                            {insertFunc((yyvsp[-2].n).lexeme,(yyvsp[-3].n).lexeme); updateFunc((int)(yyvsp[0].n).val, dec); decCounter = 0;}
#line 1569 "y.tab.c"
    break;

  case 10: /* Func_Decl: Type FUNC_NAME LPAREN Para_List $@1 RPAREN LBRACE Stmt_List RBRACE  */
#line 68 "sem_parser.y"
                                                                                                                                                            {if(strcmp((yyvsp[-8].n).lexeme,returnType_func)!=0){printf("ERROR : Unexpected Return Type");exit(0);}print_Id_Table(); id_count = 0;returnType_func = "VOID";}
#line 1575 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 69 "sem_parser.y"
                                  {insertFunc((yyvsp[-1].n).lexeme,(yyvsp[-2].n).lexeme);}
#line 1581 "y.tab.c"
    break;

  case 12: /* Func_Decl: Type FUNC_NAME LPAREN $@2 RPAREN LBRACE Stmt_List RBRACE  */
#line 69 "sem_parser.y"
                                                                                                    {printf("return %s return Type %s\n",(yyvsp[-7].n).lexeme,returnType_func);if((strcmp((yyvsp[-7].n).lexeme,returnType_func)!=0)){printf("ERROR : Unexpected Return Type");exit(0);}print_Id_Table();id_count = 0;returnType_func = "VOID";}
#line 1587 "y.tab.c"
    break;

  case 13: /* Para_List: Para_List COMMA Type ID  */
#line 72 "sem_parser.y"
                                    {(yyval.n).val = (yyvsp[-3].n).val + 1; insertID((yyvsp[0].n).lexeme, (yyvsp[-1].n).lexeme); dec[decCounter].type = (yyvsp[-1].n).lexeme; dec[decCounter].name = (yyvsp[0].n).lexeme; decCounter++;}
#line 1593 "y.tab.c"
    break;

  case 14: /* Para_List: Type ID  */
#line 73 "sem_parser.y"
                    {(yyval.n).val = 1; insertID((yyvsp[0].n).lexeme, (yyvsp[-1].n).lexeme); dec[decCounter].type = (yyvsp[-1].n).lexeme; dec[decCounter].name = (yyvsp[0].n).lexeme; decCounter++;}
#line 1599 "y.tab.c"
    break;

  case 20: /* Stmt: Return  */
#line 83 "sem_parser.y"
                      {}
#line 1605 "y.tab.c"
    break;

  case 32: /* Switch_stmt: SWITCH LPAREN ID RPAREN LBRACE Case_stmt RBRACE  */
#line 86 "sem_parser.y"
                                                              {if(strcmp(findIdType((yyvsp[-4].n).lexeme),"INT")!=0){printf("ERROR: Unexpected variable type passed in Switch\n"); exit(0);}}
#line 1611 "y.tab.c"
    break;

  case 41: /* Expr: Expr COMP_OP TERM  */
#line 102 "sem_parser.y"
                         {if(strcmp((yyvsp[-2].n).lexeme, (yyvsp[0].n).lexeme)!=0){
                                print_Id_Table();
                                printf("ERROR: Unexpected type for expression\n");
                                exit(0);
                            }
                            (yyval.n).lexeme = (yyvsp[-2].n).lexeme;
                            (yyval.n).val = (float)comparator((yyvsp[-2].n).val,(yyvsp[0].n).val,(yyvsp[-1].n).lexeme);
                         }
#line 1624 "y.tab.c"
    break;

  case 42: /* Expr: TERM  */
#line 110 "sem_parser.y"
           {(yyval.n).lexeme = (yyvsp[0].n).lexeme; (yyval.n).val = (yyvsp[0].n).val;}
#line 1630 "y.tab.c"
    break;

  case 43: /* COMP_OP: GT  */
#line 113 "sem_parser.y"
             {(yyval.n).lexeme = (yyvsp[0].n).lexeme;}
#line 1636 "y.tab.c"
    break;

  case 44: /* COMP_OP: LT  */
#line 114 "sem_parser.y"
         {(yyval.n).lexeme = (yyvsp[0].n).lexeme;}
#line 1642 "y.tab.c"
    break;

  case 45: /* COMP_OP: GE  */
#line 115 "sem_parser.y"
         {(yyval.n).lexeme = (yyvsp[0].n).lexeme;}
#line 1648 "y.tab.c"
    break;

  case 46: /* COMP_OP: LE  */
#line 116 "sem_parser.y"
         {(yyval.n).lexeme = (yyvsp[0].n).lexeme;}
#line 1654 "y.tab.c"
    break;

  case 47: /* COMP_OP: NE  */
#line 117 "sem_parser.y"
         {(yyval.n).lexeme = (yyvsp[0].n).lexeme;}
#line 1660 "y.tab.c"
    break;

  case 48: /* COMP_OP: LAND  */
#line 118 "sem_parser.y"
           {(yyval.n).lexeme = (yyvsp[0].n).lexeme;}
#line 1666 "y.tab.c"
    break;

  case 49: /* COMP_OP: LOR  */
#line 119 "sem_parser.y"
          {(yyval.n).lexeme = (yyvsp[0].n).lexeme;}
#line 1672 "y.tab.c"
    break;

  case 50: /* COMP_OP: NOT  */
#line 120 "sem_parser.y"
          {(yyval.n).lexeme = (yyvsp[0].n).lexeme;}
#line 1678 "y.tab.c"
    break;

  case 51: /* COMP_OP: EQ  */
#line 121 "sem_parser.y"
         {(yyval.n).lexeme = (yyvsp[0].n).lexeme;}
#line 1684 "y.tab.c"
    break;

  case 52: /* TERM: TERM PLUS FACTOR  */
#line 124 "sem_parser.y"
                        {termsolve1((yyvsp[-2].n).lexeme,(yyvsp[0].n).lexeme,(yyval.n).lexeme,(yyval.n).val,(yyvsp[-2].n).val,(yyvsp[0].n).val);}
#line 1690 "y.tab.c"
    break;

  case 53: /* TERM: TERM MINUS FACTOR  */
#line 125 "sem_parser.y"
                        {termsolve2((yyvsp[-2].n).lexeme,(yyvsp[0].n).lexeme,(yyval.n).lexeme,(yyval.n).val,(yyvsp[-2].n).val,(yyvsp[0].n).val);}
#line 1696 "y.tab.c"
    break;

  case 54: /* TERM: TERM MUL FACTOR  */
#line 126 "sem_parser.y"
                      {termsolve3((yyvsp[-2].n).lexeme,(yyvsp[0].n).lexeme,(yyval.n).lexeme,(yyval.n).val,(yyvsp[-2].n).val,(yyvsp[0].n).val);}
#line 1702 "y.tab.c"
    break;

  case 55: /* TERM: TERM DIV FACTOR  */
#line 127 "sem_parser.y"
                      {termsolve4((yyvsp[-2].n).lexeme,(yyvsp[0].n).lexeme,(yyval.n).lexeme,(yyval.n).val,(yyvsp[-2].n).val,(yyvsp[0].n).val);}
#line 1708 "y.tab.c"
    break;

  case 56: /* TERM: TERM MOD FACTOR  */
#line 128 "sem_parser.y"
                      {termsolve5((yyvsp[-2].n).lexeme,(yyvsp[0].n).lexeme,(yyval.n).lexeme,(yyval.n).val,(yyvsp[-2].n).val,(yyvsp[0].n).val);}
#line 1714 "y.tab.c"
    break;

  case 57: /* TERM: FACTOR  */
#line 129 "sem_parser.y"
             {termsolve6((yyval.n).lexeme,(yyvsp[0].n).lexeme);}
#line 1720 "y.tab.c"
    break;

  case 58: /* FACTOR: LPAREN Expr RPAREN  */
#line 132 "sem_parser.y"
                            {(yyval.n).lexeme = (yyvsp[-1].n).lexeme; (yyval.n).val = (yyvsp[-1].n).val;}
#line 1726 "y.tab.c"
    break;

  case 59: /* FACTOR: ID  */
#line 133 "sem_parser.y"
        {bool found = true;
             for(int i = 0; i<id_count; i++){
                if(strcmp(id_table[i].name,(yyvsp[0].n).lexeme)==0){
                    found = false;
                    (yyval.n).lexeme = id_table[i].type;
                    (yyval.n).val = id_table[i].val;
                    break;
                }
            }
            if(found){  
                printf("ERROR: Undeclared variable %s\n", (yyvsp[0].n).lexeme);
                exit(0);
            }
        }
#line 1745 "y.tab.c"
    break;

  case 60: /* FACTOR: Const  */
#line 147 "sem_parser.y"
            { (yyval.n).lexeme = (yyvsp[0].n).lexeme; (yyval.n).val = (yyvsp[0].n).val;}
#line 1751 "y.tab.c"
    break;

  case 61: /* Assgn: ID ASSIGN Expr ASSGN_TAIL  */
#line 150 "sem_parser.y"
                                  {assign1((yyvsp[-3].n).lexeme,(yyvsp[-1].n).lexeme,(yyvsp[-1].n).val);}
#line 1757 "y.tab.c"
    break;

  case 62: /* Assgn: ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn  */
#line 151 "sem_parser.y"
                                                                    {assign2((yyvsp[-7].n).lexeme,(yyvsp[-5].n).lexeme,(yyvsp[-5].n).val);}
#line 1763 "y.tab.c"
    break;

  case 63: /* Assgn: ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr  */
#line 152 "sem_parser.y"
                                                    { assign3((yyvsp[-5].n).lexeme,(yyvsp[-3].n).lexeme,(yyvsp[-3].n).val); }
#line 1769 "y.tab.c"
    break;

  case 64: /* Assgn: ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn  */
#line 153 "sem_parser.y"
                                                                                            {assign4((yyvsp[-10].n).lexeme,(yyvsp[-8].n).lexeme,(yyvsp[-8].n).val,(yyvsp[-5].n).val);}
#line 1775 "y.tab.c"
    break;

  case 65: /* Assgn: ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN Expr  */
#line 154 "sem_parser.y"
                                                                                { assign5((yyvsp[-8].n).lexeme,(yyvsp[-6].n).lexeme,(yyvsp[-6].n).val,(yyvsp[-3].n).val); }
#line 1781 "y.tab.c"
    break;

  case 66: /* ASSGN_TAIL: COMMA ID ASSIGN Expr ASSGN_TAIL  */
#line 156 "sem_parser.y"
                                             {typeCheck((yyvsp[-3].n).lexeme,(yyvsp[-1].n).lexeme); updateID((yyvsp[-3].n).lexeme,(yyvsp[-1].n).val);}
#line 1787 "y.tab.c"
    break;

  case 68: /* Decl: Type ID ASSIGN Expr DECL_TAIL  */
#line 160 "sem_parser.y"
                                     {declsolve1((yyval.n).lexeme,(yyvsp[-4].n).lexeme,(yyvsp[-3].n).lexeme,(yyvsp[-1].n).lexeme,(yyvsp[-1].n).val);}
#line 1793 "y.tab.c"
    break;

  case 69: /* Decl: Type ID DECL_TAIL  */
#line 161 "sem_parser.y"
                        {declsolve2((yyval.n).lexeme,(yyvsp[-2].n).lexeme,(yyvsp[-1].n).lexeme);}
#line 1799 "y.tab.c"
    break;

  case 70: /* DECL_TAIL: COMMA ID DECL_TAIL  */
#line 164 "sem_parser.y"
                               {decltail1((yyvsp[-1].n).lexeme);}
#line 1805 "y.tab.c"
    break;

  case 71: /* DECL_TAIL: COMMA ID ASSIGN Expr DECL_TAIL  */
#line 165 "sem_parser.y"
                                     {decltail2((yyvsp[-3].n).lexeme,(yyvsp[-1].n).lexeme,(yyvsp[-1].n).val);}
#line 1811 "y.tab.c"
    break;

  case 77: /* Return: RETURN ID SEMICOLON  */
#line 178 "sem_parser.y"
                             {returnType_func = findIdType((yyvsp[-1].n).lexeme);printf("return type :%s\n",returnType_func);}
#line 1817 "y.tab.c"
    break;

  case 78: /* Return: RETURN Const SEMICOLON  */
#line 179 "sem_parser.y"
                                 {returnType_func = (yyvsp[-1].n).lexeme; }
#line 1823 "y.tab.c"
    break;

  case 80: /* Const: INT_CONST  */
#line 183 "sem_parser.y"
                  {(yyval.n).val = (yyvsp[0].n).val;(yyval.n).lexeme = "INT";}
#line 1829 "y.tab.c"
    break;

  case 81: /* Const: FLOAT_CONST  */
#line 184 "sem_parser.y"
                  {(yyval.n).val = (yyvsp[0].n).val;(yyval.n).lexeme = "FLOAT";}
#line 1835 "y.tab.c"
    break;

  case 82: /* Const: CHAR_CONST  */
#line 185 "sem_parser.y"
                 {(yyval.n).val = (yyvsp[0].n).val;(yyval.n).lexeme = "CHAR";}
#line 1841 "y.tab.c"
    break;

  case 83: /* Const: ARR LBRACKET INT_CONST RBRACKET  */
#line 186 "sem_parser.y"
                                      {if((yyvsp[-1].n).val < 0 || !findArrSize((yyvsp[-3].n).lexeme, 0, (yyvsp[-1].n).val)){printf("ERROR: Array %s out of bounds\n", (yyvsp[-3].n).lexeme); exit(0);} (yyval.n).lexeme = findArrType((yyvsp[-3].n).lexeme); (yyval.n).val = findArrVal((yyvsp[-3].n).lexeme, 0, (yyvsp[-1].n).val);}
#line 1847 "y.tab.c"
    break;

  case 84: /* Const: ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET  */
#line 187 "sem_parser.y"
                                                                  {if((yyvsp[-4].n).val < 0 || (yyvsp[-1].n).val < 0 || !findArrSize((yyvsp[-6].n).lexeme, (yyvsp[-4].n).val, (yyvsp[-1].n).val)){printf("ERROR: Array %s out of bounds\n", (yyvsp[-6].n).lexeme); exit(0);} (yyval.n).lexeme = findArrType((yyvsp[-6].n).lexeme); (yyval.n).val = findArrVal((yyvsp[-6].n).lexeme, (yyvsp[-4].n).val, (yyvsp[-1].n).val);}
#line 1853 "y.tab.c"
    break;

  case 87: /* Print: PRINTF LPAREN STRING_CONST COMMA Var_List RPAREN SEMICOLON  */
#line 192 "sem_parser.y"
                                                                 {
                                                    printsolve((yyvsp[-4].n).lexeme,listType[list_c - 1],list_c);
                                                    }
#line 1861 "y.tab.c"
    break;

  case 88: /* Var_List: ID  */
#line 197 "sem_parser.y"
              {listType[list_c] = findIdType((yyvsp[0].n).lexeme); list_c++;}
#line 1867 "y.tab.c"
    break;

  case 89: /* Var_List: ID COMMA Var_List  */
#line 198 "sem_parser.y"
                                 {listType[list_c] = findIdType((yyvsp[-2].n).lexeme); list_c++;}
#line 1873 "y.tab.c"
    break;

  case 90: /* Func_Call: Type ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON  */
#line 200 "sem_parser.y"
                                                                        {
                                                            funccall1((yyvsp[-4].n).lexeme,list_c,listType,(yyvsp[-7].n).lexeme);
                                                        }
#line 1881 "y.tab.c"
    break;

  case 91: /* Func_Call: Type ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON  */
#line 203 "sem_parser.y"
                                                           {
                                                funccall2((yyvsp[-3].n).lexeme,(yyvsp[-5].n).lexeme,(yyvsp[-6].n).lexeme,list_c);
                                                }
#line 1889 "y.tab.c"
    break;

  case 92: /* Func_Call: FUNC_NAME LPAREN RPAREN SEMICOLON  */
#line 206 "sem_parser.y"
                                            {findFunc((yyvsp[-3].n).lexeme);}
#line 1895 "y.tab.c"
    break;

  case 93: /* Func_Call: FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON  */
#line 207 "sem_parser.y"
                                                       {
                                            funccall3((yyvsp[-4].n).lexeme,list_c,listType);
                                            }
#line 1903 "y.tab.c"
    break;

  case 94: /* Func_Call: ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON  */
#line 211 "sem_parser.y"
                                                      {
                                                funccall4((yyvsp[-5].n).lexeme,(yyvsp[-3].n).lexeme,list_c);
                                            }
#line 1911 "y.tab.c"
    break;

  case 95: /* Func_Call: ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON  */
#line 214 "sem_parser.y"
                                                                 {
                                                funccall5((yyvsp[-6].n).lexeme,(yyvsp[-4].n).lexeme,list_c);
                                            }
#line 1919 "y.tab.c"
    break;

  case 96: /* Mixed_List: ID COMMA Mixed_List  */
#line 219 "sem_parser.y"
                                {listType[list_c] = findIdType((yyvsp[-2].n).lexeme); list_c++;}
#line 1925 "y.tab.c"
    break;

  case 97: /* Mixed_List: Const COMMA Mixed_List  */
#line 220 "sem_parser.y"
                             {listType[list_c] = (yyvsp[-2].n).lexeme; list_c++;}
#line 1931 "y.tab.c"
    break;

  case 98: /* Mixed_List: ID  */
#line 221 "sem_parser.y"
         {listType[list_c] = findIdType((yyvsp[0].n).lexeme); list_c++;}
#line 1937 "y.tab.c"
    break;

  case 99: /* Mixed_List: Const  */
#line 222 "sem_parser.y"
            {listType[list_c] = (yyvsp[0].n).lexeme; list_c++;}
#line 1943 "y.tab.c"
    break;

  case 100: /* Arr_Decl: Type ARR LBRACKET INT_CONST RBRACKET SEMICOLON  */
#line 224 "sem_parser.y"
                                                          {insertArr((yyvsp[-4].n).lexeme, (yyvsp[-5].n).lexeme, 0, (yyvsp[-2].n).val);}
#line 1949 "y.tab.c"
    break;

  case 101: /* Arr_Decl: Type ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET SEMICOLON  */
#line 227 "sem_parser.y"
                                                                                      {insertArr((yyvsp[-7].n).lexeme, (yyvsp[-8].n).lexeme, (yyvsp[-5].n).val, (yyvsp[-2].n).val);}
#line 1955 "y.tab.c"
    break;


#line 1959 "y.tab.c"

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

#line 245 "sem_parser.y"


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
    if(mlc == 0)
        return 1;
    return 0;
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



int main(int argc , char *argv[]){
    yyin = fopen(argv[1],"r");
    main_list = (struct ll *)malloc(sizeof(struct ll));
    main_list->head = NULL;
    main_list->tail = NULL;
    main_list->count = 0;
    mlc = 0;
    yyparse();
    dis();
}

void yyerror(){
    printf("Invalid statement\n");
}
