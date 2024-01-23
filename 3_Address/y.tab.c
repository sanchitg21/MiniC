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
#line 1 "three.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<ctype.h>
    extern FILE *yyin;
    
    int label = 0;
    int tempVariable = 0;

    char* genTempVariable(int x){
        char* temp = (char*)malloc(sizeof(char)*10);
        temp[0] = 'T';
        snprintf(temp, 10, "T%d", x);
        return temp;
    }

    int gencode(char* lhs, char* op, char* rhs){
        printf("T%d = %s %s %s\n", tempVariable, lhs, op, rhs);
        return tempVariable;
    }

    void assignment(char* lhs, char* rhs){
        //printf("in assign function");
        printf("%s = %s\n", lhs, rhs);
    }


#line 101 "y.tab.c"

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

#line 266 "y.tab.c"

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
  YYSYMBOL_PLUS = 4,                       /* PLUS  */
  YYSYMBOL_MINUS = 5,                      /* MINUS  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_MOD = 8,                        /* MOD  */
  YYSYMBOL_ARR = 9,                        /* ARR  */
  YYSYMBOL_ARR2D = 10,                     /* ARR2D  */
  YYSYMBOL_SIGNED_CONST = 11,              /* SIGNED_CONST  */
  YYSYMBOL_HASH = 12,                      /* HASH  */
  YYSYMBOL_DQ = 13,                        /* DQ  */
  YYSYMBOL_TYPE_SPEC = 14,                 /* TYPE_SPEC  */
  YYSYMBOL_ARR_E = 15,                     /* ARR_E  */
  YYSYMBOL_LPAREN = 16,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 17,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 20,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 21,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 22,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_COLON = 24,                     /* COLON  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_FOR = 28,                       /* FOR  */
  YYSYMBOL_SWITCH = 29,                    /* SWITCH  */
  YYSYMBOL_CONTINUE = 30,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_PRINTF = 33,                    /* PRINTF  */
  YYSYMBOL_DEFAULT = 34,                   /* DEFAULT  */
  YYSYMBOL_CASE = 35,                      /* CASE  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_FLOAT = 37,                     /* FLOAT  */
  YYSYMBOL_CHAR = 38,                      /* CHAR  */
  YYSYMBOL_VOID = 39,                      /* VOID  */
  YYSYMBOL_GE = 40,                        /* GE  */
  YYSYMBOL_LE = 41,                        /* LE  */
  YYSYMBOL_NE = 42,                        /* NE  */
  YYSYMBOL_LAND = 43,                      /* LAND  */
  YYSYMBOL_LOR = 44,                       /* LOR  */
  YYSYMBOL_NOT = 45,                       /* NOT  */
  YYSYMBOL_EQ = 46,                        /* EQ  */
  YYSYMBOL_LT = 47,                        /* LT  */
  YYSYMBOL_GT = 48,                        /* GT  */
  YYSYMBOL_ID = 49,                        /* ID  */
  YYSYMBOL_INT_CONST = 50,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 51,               /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 52,                /* CHAR_CONST  */
  YYSYMBOL_FUNC_NAME = 53,                 /* FUNC_NAME  */
  YYSYMBOL_STRING_CONST = 54,              /* STRING_CONST  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_S = 56,                         /* S  */
  YYSYMBOL_BEGIN = 57,                     /* BEGIN  */
  YYSYMBOL_Type = 58,                      /* Type  */
  YYSYMBOL_FUNC_DECL = 59,                 /* FUNC_DECL  */
  YYSYMBOL_Para_List = 60,                 /* Para_List  */
  YYSYMBOL_Stmt_Lis = 61,                  /* Stmt_Lis  */
  YYSYMBOL_Stmt = 62,                      /* Stmt  */
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_FOR_STMT = 66,                  /* FOR_STMT  */
  YYSYMBOL_67_4 = 67,                      /* $@4  */
  YYSYMBOL_68_5 = 68,                      /* $@5  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_SWITCH_STMT = 70,               /* SWITCH_STMT  */
  YYSYMBOL_CASE_STMT = 71,                 /* CASE_STMT  */
  YYSYMBOL_BRK = 72,                       /* BRK  */
  YYSYMBOL_WHILE_STMT = 73,                /* WHILE_STMT  */
  YYSYMBOL_74_7 = 74,                      /* $@7  */
  YYSYMBOL_Assgn = 75,                     /* Assgn  */
  YYSYMBOL_ASSGN_TAIL = 76,                /* ASSGN_TAIL  */
  YYSYMBOL_IF_STMT = 77,                   /* IF_STMT  */
  YYSYMBOL_MAT = 78,                       /* MAT  */
  YYSYMBOL_UNMAT = 79,                     /* UNMAT  */
  YYSYMBOL_PRINT = 80,                     /* PRINT  */
  YYSYMBOL_FUNC_CALL = 81,                 /* FUNC_CALL  */
  YYSYMBOL_VAR_LIST = 82,                  /* VAR_LIST  */
  YYSYMBOL_RTRN_STMT = 83,                 /* RTRN_STMT  */
  YYSYMBOL_ARR_DECL = 84,                  /* ARR_DECL  */
  YYSYMBOL_MIXED_LIST = 85,                /* MIXED_LIST  */
  YYSYMBOL_DECL = 86,                      /* DECL  */
  YYSYMBOL_DECL_TAIL = 87,                 /* DECL_TAIL  */
  YYSYMBOL_EXPR = 88,                      /* EXPR  */
  YYSYMBOL_COMP_OP = 89,                   /* COMP_OP  */
  YYSYMBOL_TERM = 90,                      /* TERM  */
  YYSYMBOL_FACTOR = 91,                    /* FACTOR  */
  YYSYMBOL_CONST = 92                      /* CONST  */
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
#define YYLAST   340

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    47,    48,    51,    52,    53,    54,    57,
      58,    60,    61,    63,    64,    65,    66,    68,    69,    70,
      71,    72,    73,    73,    74,    74,    75,    75,    76,    77,
      78,    79,    80,    82,    82,    83,    83,    84,    84,    87,
      89,    90,    92,    93,    95,    95,    98,    99,   100,   103,
     103,   105,   107,   109,   110,   112,   113,   114,   115,   116,
     117,   119,   120,   122,   123,   124,   126,   127,   131,   132,
     133,   134,   145,   146,   149,   150,   151,   154,   160,   163,
     164,   165,   166,   167,   168,   169,   170,   173,   179,   185,
     191,   197,   203,   206,   207,   208,   211,   212,   213,   214
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
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "ARR", "ARR2D", "SIGNED_CONST", "HASH",
  "DQ", "TYPE_SPEC", "ARR_E", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "COLON", "IF", "ELSE",
  "WHILE", "FOR", "SWITCH", "CONTINUE", "BREAK", "RETURN", "PRINTF",
  "DEFAULT", "CASE", "INT", "FLOAT", "CHAR", "VOID", "GE", "LE", "NE",
  "LAND", "LOR", "NOT", "EQ", "LT", "GT", "ID", "INT_CONST", "FLOAT_CONST",
  "CHAR_CONST", "FUNC_NAME", "STRING_CONST", "$accept", "S", "BEGIN",
  "Type", "FUNC_DECL", "Para_List", "Stmt_Lis", "Stmt", "$@1", "$@2",
  "$@3", "FOR_STMT", "$@4", "$@5", "$@6", "SWITCH_STMT", "CASE_STMT",
  "BRK", "WHILE_STMT", "$@7", "Assgn", "ASSGN_TAIL", "IF_STMT", "MAT",
  "UNMAT", "PRINT", "FUNC_CALL", "VAR_LIST", "RTRN_STMT", "ARR_DECL",
  "MIXED_LIST", "DECL", "DECL_TAIL", "EXPR", "COMP_OP", "TERM", "FACTOR",
  "CONST", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-27)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,  -129,  -129,  -129,  -129,    13,  -129,   -39,    31,  -129,
      20,  -129,   128,    25,    14,    -6,   152,  -129,    44,    31,
      71,   152,  -129,    41,    42,    57,   -17,    64,    79,  -129,
    -129,  -129,    65,  -129,    -3,    66,    22,    58,    69,    80,
    -129,  -129,    83,  -129,  -129,  -129,  -129,    84,   184,    21,
    -129,  -129,   152,    60,  -129,   109,    98,    75,  -129,  -129,
    -129,   111,   112,    81,    49,    39,   115,   117,     7,  -129,
    -129,   130,  -129,   131,  -129,  -129,  -129,   132,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,    71,
      71,    71,    71,    71,    71,   139,  -129,  -129,    22,   154,
    -129,  -129,     1,   153,   247,   150,   157,   156,   163,  -129,
    -129,    62,   127,  -129,   207,    71,    71,    21,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,   179,   171,   149,    78,   151,
    -129,  -129,   261,   177,   261,   197,   260,    16,    71,   217,
     165,   227,   228,   175,   194,   -14,  -129,   216,   231,   239,
     245,   271,  -129,  -129,  -129,   158,  -129,    71,  -129,   211,
      71,    19,    71,    71,   246,   257,   252,   213,   258,   149,
     270,  -129,   274,    71,   275,   281,   260,   250,    71,   225,
     238,   152,   152,   152,   285,  -129,  -129,  -129,  -129,   247,
    -129,   283,  -129,   297,   250,   250,   302,  -129,  -129,   152,
    -129,  -129,   304,   306,   307,   299,   308,   -14,   152,   310,
     311,   312,  -129,  -129,  -129,   152,   152,   152,   313,  -129,
    -129,   314,  -129,   315,   316,  -129,  -129,  -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     6,     7,     8,     0,     2,     0,     4,     1,
       0,     3,     0,     0,     0,     0,    22,    12,     0,     0,
       0,    22,    32,     0,     0,     0,     0,     0,    94,    96,
      97,    98,     0,    99,     0,     0,    14,     0,     0,     0,
      29,    20,     0,    17,    19,    18,    21,     0,    28,    78,
      92,    95,    22,     0,    94,     0,     0,     0,    42,    43,
      65,     0,     0,     0,     0,     0,     0,     0,    76,    10,
      13,     0,    23,     0,    25,    49,    50,     0,    27,    30,
      31,    82,    80,    85,    84,    83,    86,    79,    81,     0,
       0,     0,     0,     0,     0,     0,    11,    93,    15,     0,
      63,    64,     0,     0,    48,     0,    70,     0,    71,    66,
      67,     0,     0,    73,     0,     0,     0,    77,    87,    88,
      89,    90,    91,     9,    16,     0,     0,     0,     0,     0,
      46,    57,     0,     0,     0,     0,    76,    76,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    61,     0,     0,
       0,     0,    68,    58,    69,     0,    72,     0,    74,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,     0,     0,     0,     0,    76,     0,     0,     0,
       0,    22,    22,    22,     0,    39,    62,    54,    60,    48,
      56,     0,    75,     0,     0,     0,     0,    44,    41,    22,
      47,    55,     0,     0,     0,    51,     0,     0,    22,     0,
       0,     0,    45,    40,    37,    22,    22,    22,     0,    35,
      33,     0,    38,     0,     0,    52,    36,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   318,     4,  -129,  -129,   -21,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,   124,  -129,  -129,  -129,
    -111,   147,  -129,  -129,  -129,  -129,  -129,   168,  -129,  -129,
       8,   224,  -128,   -19,  -129,   251,   226,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    34,     8,    15,    35,    36,    37,    38,
      39,    72,   224,   223,   218,    40,   168,    41,    78,   206,
      42,   130,    74,    75,    76,    43,    44,   148,    45,    46,
     107,    47,   113,    48,    89,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    55,    62,   141,     7,    60,    66,    67,   156,   158,
     111,    18,     7,     9,    10,    70,    14,    19,   126,   157,
     166,   167,   178,    53,   127,    90,    91,    92,    93,    94,
     112,    95,    61,    29,    30,    31,    12,    33,    20,   112,
      21,   108,   112,    16,    22,   104,    68,   -24,   192,   -26,
     -22,    23,    24,    25,    26,    27,   105,    57,     1,     2,
       3,     4,    52,    17,    58,    20,   193,     1,     2,     3,
       4,    28,    29,    30,    31,    32,    33,   124,    20,    59,
      63,    65,    64,   203,   204,    69,    71,    20,   106,    29,
      30,    31,   136,    33,    73,   149,   143,   144,    54,    29,
      30,    31,   103,    33,   108,    79,    80,    77,   108,    96,
     108,    54,    29,    30,    31,   135,    33,    98,   140,   159,
      54,    29,    30,    31,    99,    33,    97,   106,    29,    30,
      31,   108,    33,   100,   101,   102,   150,   109,   176,   110,
     152,   104,   154,   179,   180,    13,   114,   115,   116,    81,
      82,    83,    84,    85,   189,    86,    87,    88,   123,   136,
     196,   197,   198,   175,     1,     2,     3,     4,    20,   128,
      21,   125,   131,   133,    22,   174,   137,   -24,   207,   -26,
     132,    23,    24,    25,    26,    27,   134,   214,     1,     2,
       3,     4,   164,   146,   219,   220,   221,   145,   147,   153,
     151,    28,    29,    30,    31,    32,    33,   106,    29,    30,
      31,   165,    33,   155,   161,    81,    82,    83,    84,    85,
     160,    86,    87,    88,    81,    82,    83,    84,    85,   138,
      86,    87,    88,   177,    81,    82,    83,    84,    85,   169,
      86,    87,    88,     1,     2,     3,     4,   194,   170,   162,
     163,    81,    82,    83,    84,    85,   139,    86,    87,    88,
     195,   171,   172,   184,   181,    81,    82,    83,    84,    85,
     129,    86,    87,    88,   173,   182,   183,   185,    81,    82,
      83,    84,    85,   112,    86,    87,    88,    81,    82,    83,
      84,    85,   187,    86,    87,    88,   188,   190,   191,   139,
      81,    82,    83,    84,    85,   201,    86,    87,    88,   199,
     106,    29,    30,    31,   202,    33,   118,   119,   120,   121,
     122,   205,   208,   209,   210,   211,    11,   212,   215,   216,
     217,   213,   222,   225,   226,   227,   200,   186,   142,     0,
     117
};

static const yytype_int16 yycheck[] =
{
      21,    20,    26,   114,     0,    22,     9,    10,   136,   137,
       3,    17,     8,     0,    53,    36,    12,    23,    17,     3,
      34,    35,     3,    19,    23,     4,     5,     6,     7,     8,
      23,    52,    49,    50,    51,    52,    16,    54,    16,    23,
      18,    65,    23,    18,    22,    64,    49,    25,   176,    27,
      28,    29,    30,    31,    32,    33,    17,    16,    36,    37,
      38,    39,    18,    49,    22,    16,   177,    36,    37,    38,
      39,    49,    50,    51,    52,    53,    54,    98,    16,    22,
      16,    16,     3,   194,   195,    19,    28,    16,    49,    50,
      51,    52,   111,    54,    25,    17,   115,   116,    49,    50,
      51,    52,    53,    54,   128,    22,    22,    27,   132,    49,
     134,    49,    50,    51,    52,    53,    54,    19,   114,   138,
      49,    50,    51,    52,    49,    54,    17,    49,    50,    51,
      52,   155,    54,    22,    22,    54,   128,    22,   157,    22,
     132,   160,   134,   162,   163,    17,    16,    16,    16,    40,
      41,    42,    43,    44,   173,    46,    47,    48,    19,   178,
     181,   182,   183,   155,    36,    37,    38,    39,    16,    16,
      18,    17,    22,    17,    22,    17,    49,    25,   199,    27,
      23,    29,    30,    31,    32,    33,    23,   208,    36,    37,
      38,    39,    17,    22,   215,   216,   217,    18,    49,    22,
      49,    49,    50,    51,    52,    53,    54,    49,    50,    51,
      52,    17,    54,    16,    49,    40,    41,    42,    43,    44,
       3,    46,    47,    48,    40,    41,    42,    43,    44,    22,
      46,    47,    48,    22,    40,    41,    42,    43,    44,    23,
      46,    47,    48,    36,    37,    38,    39,    22,    17,    22,
      22,    40,    41,    42,    43,    44,    49,    46,    47,    48,
      22,    22,    17,    50,    18,    40,    41,    42,    43,    44,
      23,    46,    47,    48,     3,    18,    24,    19,    40,    41,
      42,    43,    44,    23,    46,    47,    48,    40,    41,    42,
      43,    44,    22,    46,    47,    48,    22,    22,    17,    49,
      40,    41,    42,    43,    44,    22,    46,    47,    48,    24,
      49,    50,    51,    52,    17,    54,    90,    91,    92,    93,
      94,    19,    18,    17,    17,    26,     8,    19,    18,    18,
      18,   207,    19,    19,    19,    19,   189,   169,   114,    -1,
      89
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,    38,    39,    56,    57,    58,    59,     0,
      53,    57,    16,    17,    58,    60,    18,    49,    17,    23,
      16,    18,    22,    29,    30,    31,    32,    33,    49,    50,
      51,    52,    53,    54,    58,    61,    62,    63,    64,    65,
      70,    72,    75,    80,    81,    83,    84,    86,    88,    90,
      91,    92,    18,    58,    49,    88,    61,    16,    22,    22,
      22,    49,    92,    16,     3,    16,     9,    10,    49,    19,
      61,    28,    66,    25,    77,    78,    79,    27,    73,    22,
      22,    40,    41,    42,    43,    44,    46,    47,    48,    89,
       4,     5,     6,     7,     8,    61,    49,    17,    19,    49,
      22,    22,    54,    53,    88,    17,    49,    85,    92,    22,
      22,     3,    23,    87,    16,    16,    16,    90,    91,    91,
      91,    91,    91,    19,    61,    17,    17,    23,    16,    23,
      76,    22,    23,    17,    23,    53,    88,    49,    22,    49,
      58,    75,    86,    88,    88,    18,    22,    49,    82,    17,
      85,    49,    85,    22,    85,    16,    87,     3,    87,    88,
       3,    49,    22,    22,    17,    17,    34,    35,    71,    23,
      17,    22,    17,     3,    17,    85,    88,    22,     3,    88,
      88,    18,    18,    24,    50,    19,    82,    22,    22,    88,
      22,    17,    87,    75,    22,    22,    61,    61,    61,    24,
      76,    22,    17,    75,    75,    19,    74,    61,    18,    17,
      17,    26,    19,    71,    61,    18,    18,    18,    69,    61,
      61,    61,    19,    68,    67,    19,    19,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    63,    62,    64,    62,    65,    62,    62,    62,
      62,    62,    62,    67,    66,    68,    66,    69,    66,    70,
      71,    71,    72,    72,    74,    73,    75,    76,    76,    77,
      77,    78,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    82,    82,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    86,    87,    87,    87,    88,    88,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    92,    92,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     8,
       7,     4,     2,     2,     1,     3,     4,     1,     1,     1,
       1,     1,     0,     2,     0,     2,     0,     2,     1,     1,
       2,     2,     1,     0,    12,     0,    12,     0,    11,     7,
       5,     3,     2,     2,     0,     8,     4,     5,     0,     1,
       1,     7,    11,     5,     7,     8,     7,     4,     5,     6,
       7,     1,     3,     3,     3,     2,     3,     3,     3,     3,
       1,     1,     5,     3,     3,     5,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1
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
  case 5: /* Type: INT  */
#line 51 "three.y"
           {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1507 "y.tab.c"
    break;

  case 6: /* Type: FLOAT  */
#line 52 "three.y"
            {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1513 "y.tab.c"
    break;

  case 7: /* Type: CHAR  */
#line 53 "three.y"
           {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1519 "y.tab.c"
    break;

  case 8: /* Type: VOID  */
#line 54 "three.y"
           {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1525 "y.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 73 "three.y"
      {printf("\nL%d: \n", ++label);}
#line 1531 "y.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 74 "three.y"
      {printf("\nL%d: \n", ++label);}
#line 1537 "y.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 75 "three.y"
      {printf("\nL%d: \n", ++label);}
#line 1543 "y.tab.c"
    break;

  case 33: /* $@4: %empty  */
#line 82 "three.y"
                                                                                {printf("\niftrue %s goto L%d\n", (yyvsp[-5].lexeme), label);}
#line 1549 "y.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 83 "three.y"
                                                                                 {printf("\niftrue %s goto L%d\n", (yyvsp[-5].lexeme), label);}
#line 1555 "y.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 84 "three.y"
                                                                           {printf("\niftrue %s goto L%d\n", (yyvsp[-5].lexeme), label);}
#line 1561 "y.tab.c"
    break;

  case 44: /* $@7: %empty  */
#line 95 "three.y"
                                                      {printf("\niftrue %s goto L%d\n", (yyvsp[-3].lexeme), label);}
#line 1567 "y.tab.c"
    break;

  case 46: /* Assgn: ID ASSIGN EXPR ASSGN_TAIL  */
#line 98 "three.y"
                                 {assignment((yyvsp[-3].lexeme), (yyvsp[-1].lexeme));}
#line 1573 "y.tab.c"
    break;

  case 47: /* ASSGN_TAIL: COMMA ID ASSIGN EXPR ASSGN_TAIL  */
#line 99 "three.y"
                                             {assignment((yyvsp[-3].lexeme), (yyvsp[-1].lexeme));}
#line 1579 "y.tab.c"
    break;

  case 72: /* DECL: Type ID ASSIGN EXPR DECL_TAIL  */
#line 145 "three.y"
                                     {assignment((yyvsp[-3].lexeme), (yyvsp[-1].lexeme));}
#line 1585 "y.tab.c"
    break;

  case 75: /* DECL_TAIL: COMMA ID ASSIGN EXPR DECL_TAIL  */
#line 150 "three.y"
                                            {assignment((yyvsp[-3].lexeme), (yyvsp[-1].lexeme));}
#line 1591 "y.tab.c"
    break;

  case 77: /* EXPR: EXPR COMP_OP TERM  */
#line 154 "three.y"
                        {
        int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme) , (yyvsp[0].lexeme));
        char* tempVar = genTempVariable(a);
        (yyval.lexeme) = tempVar;
        tempVariable++;
    }
#line 1602 "y.tab.c"
    break;

  case 79: /* COMP_OP: LT  */
#line 163 "three.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1608 "y.tab.c"
    break;

  case 80: /* COMP_OP: LE  */
#line 164 "three.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1614 "y.tab.c"
    break;

  case 81: /* COMP_OP: GT  */
#line 165 "three.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1620 "y.tab.c"
    break;

  case 82: /* COMP_OP: GE  */
#line 166 "three.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1626 "y.tab.c"
    break;

  case 83: /* COMP_OP: LOR  */
#line 167 "three.y"
               {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1632 "y.tab.c"
    break;

  case 84: /* COMP_OP: LAND  */
#line 168 "three.y"
                {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1638 "y.tab.c"
    break;

  case 85: /* COMP_OP: NE  */
#line 169 "three.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1644 "y.tab.c"
    break;

  case 86: /* COMP_OP: EQ  */
#line 170 "three.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1650 "y.tab.c"
    break;

  case 87: /* TERM: TERM PLUS FACTOR  */
#line 173 "three.y"
                        {
        int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme) , (yyvsp[0].lexeme));
        char* tempVar = genTempVariable(a);
        (yyval.lexeme) = tempVar;
        tempVariable++;
    }
#line 1661 "y.tab.c"
    break;

  case 88: /* TERM: TERM MINUS FACTOR  */
#line 179 "three.y"
                         {
        int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme) , (yyvsp[0].lexeme));
        char* tempVar = genTempVariable(a);
        (yyval.lexeme) = tempVar;
        tempVariable++;
      }
#line 1672 "y.tab.c"
    break;

  case 89: /* TERM: TERM MUL FACTOR  */
#line 185 "three.y"
                       {
        int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme) , (yyvsp[0].lexeme));
        char* tempVar = genTempVariable(a);
        (yyval.lexeme) = tempVar;
        tempVariable++;
      }
#line 1683 "y.tab.c"
    break;

  case 90: /* TERM: TERM DIV FACTOR  */
#line 191 "three.y"
                      {
        int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme) , (yyvsp[0].lexeme));
        char* tempVar = genTempVariable(a);
        (yyval.lexeme) = tempVar;
        tempVariable++;
      }
#line 1694 "y.tab.c"
    break;

  case 91: /* TERM: TERM MOD FACTOR  */
#line 197 "three.y"
                      {
        int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme) , (yyvsp[0].lexeme));
        char* tempVar = genTempVariable(a);
        (yyval.lexeme) = tempVar;
        tempVariable++;
      }
#line 1705 "y.tab.c"
    break;

  case 92: /* TERM: FACTOR  */
#line 203 "three.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1711 "y.tab.c"
    break;

  case 93: /* FACTOR: LPAREN EXPR RPAREN  */
#line 206 "three.y"
                            {(yyval.lexeme) = (yyvsp[-1].lexeme);}
#line 1717 "y.tab.c"
    break;

  case 94: /* FACTOR: ID  */
#line 207 "three.y"
            {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1723 "y.tab.c"
    break;

  case 95: /* FACTOR: CONST  */
#line 208 "three.y"
               {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1729 "y.tab.c"
    break;

  case 96: /* CONST: INT_CONST  */
#line 211 "three.y"
                  {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1735 "y.tab.c"
    break;

  case 97: /* CONST: FLOAT_CONST  */
#line 212 "three.y"
                   {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1741 "y.tab.c"
    break;

  case 98: /* CONST: CHAR_CONST  */
#line 213 "three.y"
                  {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1747 "y.tab.c"
    break;

  case 99: /* CONST: STRING_CONST  */
#line 214 "three.y"
                    {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1753 "y.tab.c"
    break;


#line 1757 "y.tab.c"

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

#line 217 "three.y"


int yyerror(char *s){
    printf("Error: %s\n", s);
    return 0;
}
int main(int argc , char *argv[]){
    //printf("hello");
    yyin = fopen(argv[1], "r");
    if(yyparse()==0){
        printf("success\n");
    }
}
