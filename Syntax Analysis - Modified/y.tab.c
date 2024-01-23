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
#line 1 "parser.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<ctype.h>
    extern FILE *yyin;

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

#line 96 "y.tab.c"

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
    STRING_CONST = 273,            /* STRING_CONST  */
    INT_CONST = 274,               /* INT_CONST  */
    FLOAT_CONST = 275,             /* FLOAT_CONST  */
    CHAR_CONST = 276,              /* CHAR_CONST  */
    SIGNED_CONST = 277,            /* SIGNED_CONST  */
    INT = 278,                     /* INT  */
    FLOAT = 279,                   /* FLOAT  */
    CHAR = 280,                    /* CHAR  */
    IF = 281,                      /* IF  */
    ELSE = 282,                    /* ELSE  */
    WHILE = 283,                   /* WHILE  */
    FOR = 284,                     /* FOR  */
    RETURN = 285,                  /* RETURN  */
    BREAK = 286,                   /* BREAK  */
    CONTINUE = 287,                /* CONTINUE  */
    CASE = 288,                    /* CASE  */
    DEFAULT = 289,                 /* DEFAULT  */
    SWITCH = 290,                  /* SWITCH  */
    VOID = 291,                    /* VOID  */
    MAIN = 292,                    /* MAIN  */
    PRINTF = 293,                  /* PRINTF  */
    ID = 294,                      /* ID  */
    COLON = 295,                   /* COLON  */
    SEMICOLON = 296,               /* SEMICOLON  */
    COMMA = 297,                   /* COMMA  */
    LPAREN = 298,                  /* LPAREN  */
    RPAREN = 299,                  /* RPAREN  */
    LBRACE = 300,                  /* LBRACE  */
    RBRACE = 301,                  /* RBRACE  */
    LBRACKET = 302,                /* LBRACKET  */
    RBRACKET = 303,                /* RBRACKET  */
    HASH = 304,                    /* HASH  */
    DQ = 305,                      /* DQ  */
    ARR = 306,                     /* ARR  */
    ARR2D = 307,                   /* ARR2D  */
    ARR_E = 308,                   /* ARR_E  */
    FUNC = 309,                    /* FUNC  */
    TYPE_SPEC = 310,               /* TYPE_SPEC  */
    FUNC_NAME = 311                /* FUNC_NAME  */
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
#define STRING_CONST 273
#define INT_CONST 274
#define FLOAT_CONST 275
#define CHAR_CONST 276
#define SIGNED_CONST 277
#define INT 278
#define FLOAT 279
#define CHAR 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define FOR 284
#define RETURN 285
#define BREAK 286
#define CONTINUE 287
#define CASE 288
#define DEFAULT 289
#define SWITCH 290
#define VOID 291
#define MAIN 292
#define PRINTF 293
#define ID 294
#define COLON 295
#define SEMICOLON 296
#define COMMA 297
#define LPAREN 298
#define RPAREN 299
#define LBRACE 300
#define RBRACE 301
#define LBRACKET 302
#define RBRACKET 303
#define HASH 304
#define DQ 305
#define ARR 306
#define ARR2D 307
#define ARR_E 308
#define FUNC 309
#define TYPE_SPEC 310
#define FUNC_NAME 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_STRING_CONST = 18,              /* STRING_CONST  */
  YYSYMBOL_INT_CONST = 19,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 20,               /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 21,                /* CHAR_CONST  */
  YYSYMBOL_SIGNED_CONST = 22,              /* SIGNED_CONST  */
  YYSYMBOL_INT = 23,                       /* INT  */
  YYSYMBOL_FLOAT = 24,                     /* FLOAT  */
  YYSYMBOL_CHAR = 25,                      /* CHAR  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 32,                  /* CONTINUE  */
  YYSYMBOL_CASE = 33,                      /* CASE  */
  YYSYMBOL_DEFAULT = 34,                   /* DEFAULT  */
  YYSYMBOL_SWITCH = 35,                    /* SWITCH  */
  YYSYMBOL_VOID = 36,                      /* VOID  */
  YYSYMBOL_MAIN = 37,                      /* MAIN  */
  YYSYMBOL_PRINTF = 38,                    /* PRINTF  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_COLON = 40,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_LPAREN = 43,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 44,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 45,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 46,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 47,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 48,                  /* RBRACKET  */
  YYSYMBOL_HASH = 49,                      /* HASH  */
  YYSYMBOL_DQ = 50,                        /* DQ  */
  YYSYMBOL_ARR = 51,                       /* ARR  */
  YYSYMBOL_ARR2D = 52,                     /* ARR2D  */
  YYSYMBOL_ARR_E = 53,                     /* ARR_E  */
  YYSYMBOL_FUNC = 54,                      /* FUNC  */
  YYSYMBOL_TYPE_SPEC = 55,                 /* TYPE_SPEC  */
  YYSYMBOL_FUNC_NAME = 56,                 /* FUNC_NAME  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_S = 58,                         /* S  */
  YYSYMBOL_begin = 59,                     /* begin  */
  YYSYMBOL_Type = 60,                      /* Type  */
  YYSYMBOL_Func_Decl = 61,                 /* Func_Decl  */
  YYSYMBOL_Para_List = 62,                 /* Para_List  */
  YYSYMBOL_Para = 63,                      /* Para  */
  YYSYMBOL_Stmt_List = 64,                 /* Stmt_List  */
  YYSYMBOL_Stmt = 65,                      /* Stmt  */
  YYSYMBOL_SWITCH_STMT = 66,               /* SWITCH_STMT  */
  YYSYMBOL_CASE_STMT = 67,                 /* CASE_STMT  */
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
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  251

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    48,    49,    52,    52,    52,    52,    55,
      56,    59,    59,    62,    65,    65,    65,    65,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    71,    73,    74,    77,    77,    80,    81,    82,    85,
      88,    88,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    94,    94,    94,    94,    94,    97,    97,    97,   100,
     101,   102,   103,   104,   107,   107,   110,   113,   113,   113,
     116,   116,   119,   122,   125,   125,   125,   128,   128,   128,
     128,   129,   130,   133,   134,   137,   137,   140,   141,   142,
     143,   144,   145,   148,   148,   148,   148,   150,   153
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
  "DIV", "MOD", "NOT", "STRING_CONST", "INT_CONST", "FLOAT_CONST",
  "CHAR_CONST", "SIGNED_CONST", "INT", "FLOAT", "CHAR", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "BREAK", "CONTINUE", "CASE", "DEFAULT",
  "SWITCH", "VOID", "MAIN", "PRINTF", "ID", "COLON", "SEMICOLON", "COMMA",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "HASH",
  "DQ", "ARR", "ARR2D", "ARR_E", "FUNC", "TYPE_SPEC", "FUNC_NAME",
  "$accept", "S", "begin", "Type", "Func_Decl", "Para_List", "Para",
  "Stmt_List", "Stmt", "SWITCH_STMT", "CASE_STMT", "Brk_cnt", "For_stmt",
  "While_stmt", "Expr", "COMP_OP", "TERM", "FACTOR", "Assgn", "ASSGN_TAIL",
  "Decl", "DECL_TAIL", "If_stmt", "MAT", "UNMAT", "Return", "Const",
  "Print", "Var_List", "Func_Call", "Mixed_List", "Arr_Decl", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,   -92,   -92,   -92,   -92,    16,   -92,   -30,    83,   -92,
     -21,   -92,    20,     7,     8,    17,   -92,   227,   -92,    83,
      10,   -92,   -92,   -92,   -92,    23,    24,    38,   173,    41,
      43,    42,    45,    94,   -92,   287,   227,    53,    58,   -28,
      59,   227,   -92,   -92,   -92,   -92,   373,    99,   -92,    68,
      81,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     227,   287,   287,   316,    86,   -92,    89,   107,   -92,   -92,
     110,   132,    -2,   -92,    25,   105,   134,   298,     4,   111,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   287,   287,   287,   287,   287,   -92,   -92,   108,    66,
      85,   154,   287,   112,   130,   129,   131,   -92,   152,   -92,
     136,    36,   133,   157,   -92,   227,   127,   137,   140,   141,
     138,   273,   139,   -92,   165,    99,   -92,   -92,   -92,   -92,
     -92,   142,   143,   287,   226,   170,     9,   287,   287,   150,
     146,   171,   172,   312,   186,   -92,   -92,     1,    96,   -92,
      96,   185,   168,   135,     9,   179,   227,   227,   -26,   180,
     287,   280,   294,   191,     6,   197,   200,   -92,   201,   216,
     238,   287,   242,   -92,   -92,   -92,   325,   -92,   -92,   -32,
     199,   218,   225,     3,   -26,   -26,   252,   254,   234,   229,
     171,   235,   -92,   236,   287,   198,   231,   239,   237,   -92,
     263,   269,   -92,   265,   295,   271,   278,   275,   285,   227,
     -92,   -92,   -92,   -92,   157,   -26,   310,   -92,   286,   288,
     283,   227,   300,   305,   308,   -92,   227,   -92,   -92,   -92,
     287,   -92,   302,   227,   313,   310,   227,   227,     6,   212,
     -92,   314,   -92,   315,   319,   -92,   -26,   -92,   -92,   -92,
     -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     6,     7,     8,     0,     2,     0,     4,     1,
       0,     3,     0,     0,     0,     0,    12,     0,    13,     0,
       0,    77,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    30,     0,     0,     0,     0,     0,
       0,    15,    19,    22,    24,    26,    25,    41,    55,     0,
       0,    27,    70,    71,    20,    58,    18,    21,    23,    11,
       0,     0,     0,     0,     0,    76,     0,     0,    35,    34,
       0,     0,     0,    57,     0,     0,     0,     0,    69,     0,
      10,    14,    48,    47,    50,    46,    43,    45,    42,    44,
      49,     0,     0,     0,     0,     0,    28,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,    75,
       0,     0,     0,    65,    56,    16,     0,    95,     0,    96,
       0,     0,     0,    66,     0,    40,    51,    52,    53,    54,
       9,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    17,    81,     0,    89,
       0,     0,     0,    69,    69,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,    85,     0,    83,     0,     0,
       0,     0,     0,    93,    94,    90,     0,    68,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,    61,     0,     0,     0,    97,
       0,    72,    39,     0,     0,     0,     0,     0,     0,     0,
      31,    86,    84,    92,    65,     0,    82,    88,     0,     0,
       0,     0,     0,     0,     0,    82,     0,    33,    64,    60,
      63,    87,     0,     0,     0,     0,     0,     0,     0,     0,
      98,     0,    38,     0,     0,    32,     0,    73,    36,    37,
      62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   346,     2,   -92,   -92,   339,   -36,   -92,   -92,
     124,   -92,   -92,   -92,   -34,   -92,   277,    39,   -60,   156,
     303,   -91,   -92,   -92,   -92,   -92,   -20,   -92,   181,   -92,
     -90,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    39,     8,    15,    16,    40,    41,    42,
     189,    43,    44,    45,    46,    91,    47,    48,    49,   145,
      50,   123,    51,    52,    53,    54,    55,    56,   166,    57,
     120,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      75,    74,     7,   105,   171,    81,   171,   121,    67,   199,
       7,    78,   160,   101,    14,   200,     9,    21,    22,    23,
      24,    14,    12,    79,    98,   103,    10,    99,   100,    82,
      83,    84,    85,    86,    87,    88,    89,    73,   113,   187,
     188,    35,    90,     1,     2,     3,   122,    18,   172,    66,
     204,   122,    17,   169,   112,    60,     4,   119,   173,    19,
     174,    20,   177,   178,    13,   104,    61,    62,   134,   114,
      82,    83,    84,    85,    86,    87,    88,    89,   141,   146,
     142,    63,    68,    90,    69,    70,   198,   153,    71,    82,
      83,    84,    85,    86,    87,    88,    89,    72,   182,   113,
      76,    77,    90,   161,   162,    80,     1,     2,     3,    96,
     131,    92,    93,    94,    95,    21,    22,    23,    24,     4,
     180,   181,    97,   119,   205,   206,   153,   107,   119,   132,
     119,   126,   127,   128,   129,   117,   108,   195,   160,    82,
      83,    84,    85,    86,    87,    88,    89,    66,   109,   110,
     111,   115,    90,   116,   130,   229,   119,   133,   124,   135,
     214,    82,    83,    84,    85,    86,    87,    88,    89,   136,
     137,   139,   138,   227,    90,   147,   143,   122,   154,   148,
     140,   149,   151,   150,   155,   234,   250,   156,   157,   159,
     238,   164,    21,    22,    23,    24,   239,   241,   163,   144,
     243,   244,    82,    83,    84,    85,    86,    87,    88,    89,
     165,   176,    64,   167,    65,    90,    82,    83,    84,    85,
      86,    87,    88,    89,    66,   170,   175,   179,   183,    90,
      82,    83,    84,    85,    86,    87,    88,    89,   186,   190,
     215,   194,   192,    90,   191,   201,    21,    22,    23,    24,
       1,     2,     3,    25,   246,    26,    27,    28,    29,    30,
     193,   196,    31,     4,   202,    32,    33,   158,    34,   203,
      35,   207,    36,   208,   209,   210,   212,   213,    37,   216,
     217,   218,   219,    38,    82,    83,    84,    85,    86,    87,
      88,    89,    21,    22,    23,    24,   220,    90,    82,    83,
      84,    85,    86,    87,    88,    89,    21,    22,    23,    24,
     221,    90,    73,   230,   222,   223,    35,    21,    22,    23,
      24,   184,   224,   225,    66,   226,    73,   231,   233,   152,
      35,    21,    22,    23,    24,   185,   232,   117,    66,     1,
       2,     3,   118,   240,    21,    22,    23,    24,   235,    66,
     236,   117,     4,   237,    11,   101,   168,   102,    59,   242,
     247,   248,   245,    66,   117,   249,   106,   103,   125,   197,
     228,   211,     0,     0,     0,     0,    66,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
      90
};

static const yytype_int16 yycheck[] =
{
      36,    35,     0,    63,     3,    41,     3,     3,    28,    41,
       8,    39,     3,    39,    12,    47,     0,    19,    20,    21,
      22,    19,    43,    51,    60,    51,    56,    61,    62,     4,
       5,     6,     7,     8,     9,    10,    11,    39,    72,    33,
      34,    43,    17,    23,    24,    25,    42,    39,    47,    51,
      47,    42,    45,   143,    56,    45,    36,    77,   148,    42,
     150,    44,   153,   154,    44,    63,    43,    43,   102,    44,
       4,     5,     6,     7,     8,     9,    10,    11,    42,   115,
      44,    43,    41,    17,    41,    43,   176,   121,    43,     4,
       5,     6,     7,     8,     9,    10,    11,     3,   158,   133,
      47,    43,    17,   137,   138,    46,    23,    24,    25,    41,
      44,    12,    13,    14,    15,    19,    20,    21,    22,    36,
     156,   157,    41,   143,   184,   185,   160,    41,   148,    44,
     150,    92,    93,    94,    95,    39,    47,   171,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    51,    41,    39,
      18,    46,    17,    19,    46,   215,   176,     3,    47,    47,
     194,     4,     5,     6,     7,     8,     9,    10,    11,    39,
      41,    19,    41,   209,    17,    48,    43,    42,    39,    42,
      44,    41,    44,    42,    19,   221,   246,    45,    45,    19,
     226,    45,    19,    20,    21,    22,   230,   233,    48,    42,
     236,   237,     4,     5,     6,     7,     8,     9,    10,    11,
      39,    43,    39,    41,    41,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    51,    39,    41,    48,    48,    17,
       4,     5,     6,     7,     8,     9,    10,    11,    47,    42,
      42,     3,    41,    17,    44,    46,    19,    20,    21,    22,
      23,    24,    25,    26,    42,    28,    29,    30,    31,    32,
      44,    19,    35,    36,    46,    38,    39,    41,    41,    44,
      43,    19,    45,    19,    40,    46,    41,    41,    51,    48,
      41,    44,    19,    56,     4,     5,     6,     7,     8,     9,
      10,    11,    19,    20,    21,    22,    27,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    19,    20,    21,    22,
      45,    17,    39,     3,    19,    44,    43,    19,    20,    21,
      22,    41,    44,    48,    51,    40,    39,    41,    45,    56,
      43,    19,    20,    21,    22,    41,    48,    39,    51,    23,
      24,    25,    44,    41,    19,    20,    21,    22,    48,    51,
      45,    39,    36,    45,     8,    39,    44,    41,    19,    46,
      46,    46,   238,    51,    39,    46,    63,    51,    91,    44,
     214,   190,    -1,    -1,    -1,    -1,    51,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    24,    25,    36,    58,    59,    60,    61,     0,
      56,    59,    43,    44,    60,    62,    63,    45,    39,    42,
      44,    19,    20,    21,    22,    26,    28,    29,    30,    31,
      32,    35,    38,    39,    41,    43,    45,    51,    56,    60,
      64,    65,    66,    68,    69,    70,    71,    73,    74,    75,
      77,    79,    80,    81,    82,    83,    84,    86,    88,    63,
      45,    43,    43,    43,    39,    41,    51,    83,    41,    41,
      43,    43,     3,    39,    71,    64,    47,    43,    39,    51,
      46,    64,     4,     5,     6,     7,     8,     9,    10,    11,
      17,    72,    12,    13,    14,    15,    41,    41,    64,    71,
      71,    39,    41,    51,    60,    75,    77,    41,    47,    41,
      39,    18,    56,    71,    44,    46,    19,    39,    44,    83,
      87,     3,    42,    78,    47,    73,    74,    74,    74,    74,
      46,    44,    44,     3,    71,    47,    39,    41,    41,    19,
      44,    42,    44,    43,    42,    76,    64,    48,    42,    41,
      42,    44,    56,    71,    39,    19,    45,    45,    41,    19,
       3,    71,    71,    48,    45,    39,    85,    41,    44,    87,
      39,     3,    47,    87,    87,    41,    43,    78,    78,    48,
      64,    64,    75,    48,    41,    41,    47,    33,    34,    67,
      42,    44,    41,    44,     3,    71,    19,    44,    87,    41,
      47,    46,    46,    44,    47,    75,    75,    19,    19,    40,
      46,    85,    41,    41,    71,    42,    48,    41,    44,    19,
      27,    45,    19,    44,    44,    48,    40,    64,    76,    75,
       3,    41,    48,    45,    64,    48,    45,    45,    64,    71,
      41,    64,    46,    64,    64,    67,    42,    46,    46,    46,
      75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    61,
      61,    62,    62,    63,    64,    64,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    67,    67,    68,    68,    69,    69,    69,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    73,    74,    74,    74,    75,
      75,    75,    75,    75,    76,    76,    77,    78,    78,    78,
      79,    79,    80,    81,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     8,
       7,     3,     1,     2,     2,     1,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     7,     5,     3,     2,     2,    11,    11,    10,     7,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     4,
       8,     6,    11,     8,     5,     0,     3,     3,     3,     0,
       1,     1,     7,    11,     3,     3,     2,     1,     1,     1,
       1,     4,     7,     5,     7,     1,     3,     8,     7,     4,
       5,     6,     7,     3,     3,     1,     1,     6,     9
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
#line 45 "parser.y"
         {printf("reaching here\n");}
#line 1512 "y.tab.c"
    break;

  case 4: /* begin: Func_Decl  */
#line 49 "parser.y"
                  {printf("here as well\n");}
#line 1518 "y.tab.c"
    break;


#line 1522 "y.tab.c"

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

#line 176 "parser.y"


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
