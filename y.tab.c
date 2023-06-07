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
#line 1 "part1.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define false 0
#define true 1

typedef struct node {
	char *token; 
	struct node *left;
	struct node *right;
} node;

typedef struct Arguments {
	char * name;
	char * type;
	char * len;
}Arguments;

typedef struct Function {
    char * name;
	struct Arguments * args;
    char *returnType; 
	int countArgs;
	int findreturn;
} Function;
	
typedef struct Varaiables {	
	int isArg;
	char *name;
	char *value;
	char *type;
	char * len;
} Varaiable;

typedef struct code {	
	int place;
	char *name;
	Varaiable * var;
	int countvar;
	int countfunc;
	Function ** func;
	struct code * nextLVL;
	struct code * beforeLVL;
} code;

char* exprtype(node*, code*);
Arguments* mkArgs(node*, int *);
void addFunc(char* name, Arguments* args,node *returnType,int countArgs, code* CODEscope);
void addvar(Arguments* args,int,int,code * CODEscope);
code* mkcode(char *);
node *makeNode(char *token, node *left, node *right);
void printTree(node *tree, int tab);
void printTabs(int numOfTabs);
int yyerror(char *err);
int yylex();
void push(code* from,char*);
code* mycode=NULL;
code* lestcode(code * codey);
static int scope=0;
void syntaxMKscope(node *tree,code * scope);
char* findfunc(node * tree,code * CODEscope);
char *findvar(node * tree,code * CODEscope);
Arguments * callfuncargs(code *,node *tree,int * count);

int printlevel=-1;
int flagMain=false;

#line 141 "y.tab.c"

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
#line 72 "part1.y"

    char *string;
    struct node *node;

#line 293 "y.tab.c"

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
  YYSYMBOL_BOOL = 3,                       /* BOOL  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_INTP = 8,                       /* INTP  */
  YYSYMBOL_CHARP = 9,                      /* CHARP  */
  YYSYMBOL_REALP = 10,                     /* REALP  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_VAR = 15,                       /* VAR  */
  YYSYMBOL_FUNCARGS = 16,                  /* FUNCARGS  */
  YYSYMBOL_FUNC = 17,                      /* FUNC  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_NULLP = 19,                     /* NULLP  */
  YYSYMBOL_VOID = 20,                      /* VOID  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_MAIN = 22,                      /* MAIN  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_GTE = 28,                       /* GTE  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_LTE = 30,                       /* LTE  */
  YYSYMBOL_SUB = 31,                       /* SUB  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_NEQ = 33,                       /* NEQ  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_ADD = 35,                       /* ADD  */
  YYSYMBOL_MUL = 36,                       /* MUL  */
  YYSYMBOL_ADDRESS = 37,                   /* ADDRESS  */
  YYSYMBOL_ID = 38,                        /* ID  */
  YYSYMBOL_DER_ID = 39,                    /* DER_ID  */
  YYSYMBOL_TRUE_VAL = 40,                  /* TRUE_VAL  */
  YYSYMBOL_FALSE_VAL = 41,                 /* FALSE_VAL  */
  YYSYMBOL_DEC_INT = 42,                   /* DEC_INT  */
  YYSYMBOL_HEX_INT = 43,                   /* HEX_INT  */
  YYSYMBOL_CHAR_VAL = 44,                  /* CHAR_VAL  */
  YYSYMBOL_STRING_VAL = 45,                /* STRING_VAL  */
  YYSYMBOL_REAL_VAL = 46,                  /* REAL_VAL  */
  YYSYMBOL_UNARY = 47,                     /* UNARY  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* ':'  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_start = 59,                     /* start  */
  YYSYMBOL_initial = 60,                   /* initial  */
  YYSYMBOL_code = 61,                      /* code  */
  YYSYMBOL_main = 62,                      /* main  */
  YYSYMBOL_function = 63,                  /* function  */
  YYSYMBOL_procedure = 64,                 /* procedure  */
  YYSYMBOL_args = 65,                      /* args  */
  YYSYMBOL_args_Id = 66,                   /* args_Id  */
  YYSYMBOL_string_Id = 67,                 /* string_Id  */
  YYSYMBOL_type = 68,                      /* type  */
  YYSYMBOL_string_type = 69,               /* string_type  */
  YYSYMBOL_body = 70,                      /* body  */
  YYSYMBOL_body_proc = 71,                 /* body_proc  */
  YYSYMBOL_declaration = 72,               /* declaration  */
  YYSYMBOL_long_declaration = 73,          /* long_declaration  */
  YYSYMBOL_nested_statement = 74,          /* nested_statement  */
  YYSYMBOL_proc_nested_statement = 75,     /* proc_nested_statement  */
  YYSYMBOL_proc_statement = 76,            /* proc_statement  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_func_statement = 78,            /* func_statement  */
  YYSYMBOL_func_arguments = 79,            /* func_arguments  */
  YYSYMBOL_assignment = 80,                /* assignment  */
  YYSYMBOL_multi_assign = 81,              /* multi_assign  */
  YYSYMBOL_if_statement = 82,              /* if_statement  */
  YYSYMBOL_proc_if_statement = 83,         /* proc_if_statement  */
  YYSYMBOL_while_statement = 84,           /* while_statement  */
  YYSYMBOL_proc_while_statement = 85,      /* proc_while_statement  */
  YYSYMBOL_do_statement = 86,              /* do_statement  */
  YYSYMBOL_proc_do_statement = 87,         /* proc_do_statement  */
  YYSYMBOL_for_statement = 88,             /* for_statement  */
  YYSYMBOL_proc_for_statement = 89,        /* proc_for_statement  */
  YYSYMBOL_block = 90,                     /* block  */
  YYSYMBOL_block_proc = 91,                /* block_proc  */
  YYSYMBOL_expression = 92,                /* expression  */
  YYSYMBOL_element_of_expression = 93,     /* element_of_expression  */
  YYSYMBOL_primitive_value = 94,           /* primitive_value  */
  YYSYMBOL_address_of = 95,                /* address_of  */
  YYSYMBOL_return_statement = 96,          /* return_statement  */
  YYSYMBOL_update = 97,                    /* update  */
  YYSYMBOL_unary_op = 98                   /* unary_op  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   955

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  355

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      48,    49,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    57,    52,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   180,   180,   182,   184,   185,   186,   187,   188,   189,
     190,   192,   194,   196,   198,   199,   200,   201,   202,   204,
     205,   206,   207,   208,   209,   210,   212,   213,   214,   215,
     216,   218,   219,   220,   221,   222,   223,   224,   226,   228,
     229,   230,   231,   233,   234,   235,   237,   238,   239,   240,
     242,   243,   244,   245,   246,   248,   249,   251,   252,   254,
     255,   256,   257,   258,   259,   260,   262,   263,   264,   265,
     266,   267,   268,   269,   271,   272,   273,   274,   276,   277,
     278,   280,   281,   282,   283,   284,   285,   286,   288,   289,
     290,   292,   293,   295,   296,   298,   300,   302,   304,   306,
     308,   310,   311,   312,   313,   314,   315,   316,   318,   319,
     320,   321,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   341,
     342,   343,   344,   346,   347,   348,   349,   350,   351,   352,
     353,   355,   356,   358,   359,   361,   362,   363,   365,   366,
     367
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
  "\"end of file\"", "error", "\"invalid token\"", "BOOL", "CHAR", "INT",
  "REAL", "STRING", "INTP", "CHARP", "REALP", "IF", "ELSE", "WHILE", "FOR",
  "VAR", "FUNCARGS", "FUNC", "RETURN", "NULLP", "VOID", "DO", "MAIN",
  "AND", "DIV", "ASSIGN", "EQ", "GT", "GTE", "LT", "LTE", "SUB", "NOT",
  "NEQ", "OR", "ADD", "MUL", "ADDRESS", "ID", "DER_ID", "TRUE_VAL",
  "FALSE_VAL", "DEC_INT", "HEX_INT", "CHAR_VAL", "STRING_VAL", "REAL_VAL",
  "UNARY", "'('", "')'", "':'", "'{'", "'}'", "','", "';'", "'['", "']'",
  "'|'", "$accept", "start", "initial", "code", "main", "function",
  "procedure", "args", "args_Id", "string_Id", "type", "string_type",
  "body", "body_proc", "declaration", "long_declaration",
  "nested_statement", "proc_nested_statement", "proc_statement",
  "statement", "func_statement", "func_arguments", "assignment",
  "multi_assign", "if_statement", "proc_if_statement", "while_statement",
  "proc_while_statement", "do_statement", "proc_do_statement",
  "for_statement", "proc_for_statement", "block", "block_proc",
  "expression", "element_of_expression", "primitive_value", "address_of",
  "return_statement", "update", "unary_op", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-241)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-145)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,    76,    30,  -241,  -241,    -5,    -5,    -5,    56,    85,
    -241,  -241,  -241,  -241,    82,    31,    86,    11,   -13,   115,
      88,   131,   121,    96,   458,  -241,    83,   138,    83,   458,
     153,   136,   158,    83,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,   162,  -241,   869,   458,  -241,   325,  -241,    83,   170,
      31,   173,   177,  -241,   110,   186,   192,   197,    74,   210,
     195,   218,    28,   314,   240,   240,   214,   437,  -241,   437,
    -241,   228,  -241,  -241,  -241,  -241,  -241,  -241,   239,   325,
     200,   258,     3,  -241,   140,   499,   499,   251,    32,   250,
     244,   254,   291,   293,   441,   499,   499,  -241,   390,   264,
    -241,  -241,  -241,  -241,  -241,  -241,   268,   271,   275,   276,
     499,   279,   212,   270,   408,   308,   408,  -241,   283,  -241,
    -241,  -241,  -241,  -241,  -241,   286,   471,   499,  -241,   110,
    -241,  -241,  -241,  -241,   295,   306,    46,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,   499,   307,  -241,   682,  -241,  -241,
    -241,   499,   699,    47,   299,    74,   458,    74,    31,   301,
     499,    55,  -241,   864,   309,   668,   531,  -241,   298,  -241,
    -241,   499,   499,   251,   247,   607,   346,   312,   319,   320,
     318,   296,  -241,   361,   308,   321,   352,   317,  -241,   308,
     326,  -241,  -241,  -241,   499,    67,   545,  -241,   499,   322,
     349,   716,   327,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   437,   864,   437,   499,  -241,
     334,  -241,   117,   499,   864,   499,   499,   -15,   499,   364,
    -241,   733,   750,   337,  -241,   344,   499,   499,   251,   345,
     372,   348,  -241,   308,   350,   353,   354,  -241,   378,  -241,
     562,   -11,   767,   499,   359,  -241,  -241,   891,   375,   901,
     911,   919,   119,   167,   129,  -241,   878,   208,    12,   402,
    -241,   624,   240,   365,   784,   367,   576,   379,  -241,  -241,
     231,   408,   408,   499,   499,   801,   818,   366,   373,   382,
     383,   384,  -241,  -241,  -241,   159,  -241,  -241,   593,   499,
     437,   253,  -241,   458,   377,    43,  -241,    46,  -241,  -241,
    -241,  -241,   406,  -241,   639,   835,   419,   419,   499,   386,
    -241,  -241,   110,  -241,   394,  -241,    -9,   391,  -241,   398,
    -241,   343,   408,   253,   385,   653,  -241,   395,   421,   418,
     251,   437,  -241,   405,  -241,   253,  -241,  -241,  -241,  -241,
    -241,   408,   416,  -241,   419
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      10,     0,     0,     2,     3,     8,     5,     7,     0,     0,
       1,     9,     4,     6,     0,    18,     0,    25,    19,     0,
       0,     0,     0,    19,     0,    20,    25,     0,    25,     0,
       0,    22,    20,    25,    31,    32,    33,    34,    35,    36,
      37,    16,    21,     0,     0,    14,    49,    24,    25,    21,
      18,     0,     0,    15,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,    49,    49,     0,    44,    45,    57,
      60,     0,    61,    62,    63,    65,    64,    23,    17,    49,
       0,     0,     0,    38,     0,     0,     0,     0,    53,     0,
      52,     0,     0,     0,     0,    78,     0,   108,     0,     0,
      46,    47,    11,    43,    58,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    55,    67,     0,    68,
      69,    70,    72,    71,    73,     0,     0,     0,    27,     0,
     138,   149,   150,   148,     0,     0,   132,   139,   137,   140,
     135,   134,   133,   136,     0,     0,   131,     0,   112,   129,
     128,     0,     0,     0,     0,    54,     0,    54,    18,     0,
       0,   132,    83,    81,     0,    80,     0,   110,     0,   111,
      13,     0,     0,     0,   131,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,     0,    60,     0,    12,     0,
      73,    41,    56,    66,     0,   132,     0,    28,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,     0,    51,
       0,    50,     0,     0,    82,    78,     0,    75,    78,     0,
     109,     0,     0,     0,   143,     0,     0,     0,     0,   101,
       0,     0,   106,     0,     0,    73,     0,   107,    59,    39,
       0,     0,     0,     0,     0,   113,   130,   116,   127,   114,
     118,   119,   121,   120,   124,   122,   117,   123,   125,    93,
      96,     0,    49,     0,     0,     0,     0,     0,    76,    79,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
     107,     0,   105,   103,   104,     0,    26,   115,     0,    78,
       0,    90,    48,     0,     0,    75,    85,     0,    77,    87,
      86,    84,    91,    95,     0,     0,     0,     0,     0,   105,
     102,    30,     0,   142,     0,    94,     0,    88,   147,     0,
      98,    76,     0,    90,     0,     0,    29,     0,     0,     0,
      90,     0,    92,     0,    97,    90,    74,   146,   145,    89,
     100,     0,     0,    99,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -241,  -241,  -241,   274,  -241,   267,  -241,   -41,    34,  -125,
       0,  -241,  -241,   376,   -62,   -71,   -55,   -56,  -209,  -193,
     -46,  -190,   -39,   151,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -106,   -50,   -31,  -241,  -241,  -241,   -83,  -240,
    -241
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,     5,    64,     7,    19,    20,    83,
      52,    65,   113,    66,    67,    89,   184,    68,    69,   116,
     146,   164,    71,   328,   119,    72,   120,    73,   121,    74,
     122,    75,   123,    76,   165,   148,   149,   150,   124,   329,
     151
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    98,   100,   101,   197,   176,   269,    99,   270,    78,
      92,   103,     1,   104,   280,    84,   126,    70,   114,    90,
     277,    70,   338,    70,    41,   115,   339,    22,   126,    45,
      10,   190,   191,    70,   117,   275,   204,    25,   279,   278,
      26,   118,   168,   296,    53,   211,    96,    17,   154,    23,
     183,    24,    70,    94,   147,   152,   185,   126,   127,   189,
      42,   192,    44,   163,   174,   166,   186,    49,   117,    18,
     117,   200,   126,   187,   176,   118,    95,   118,   277,   175,
     200,   -25,    77,    96,   219,   155,   221,    96,   312,   313,
      84,   325,   200,   343,    95,   163,   196,   331,     8,    22,
     245,   246,    96,   225,    14,   352,   249,   269,   270,   324,
     226,    61,    88,   201,     9,    95,    90,   222,    90,   240,
     216,    18,   226,   312,   313,   241,    81,   244,   243,   224,
      92,    16,   350,    15,   233,   186,    21,   186,    29,   342,
     231,   232,   187,   204,   187,   350,    32,    61,    82,    33,
     210,    30,   211,   204,   213,   214,   220,   245,   353,    31,
     291,   353,   211,   250,    27,   214,   273,   252,    28,    70,
      28,    70,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   289,   243,    47,   271,    43,    48,
     128,   204,   274,   129,   186,   276,   208,   336,   210,   287,
     211,   187,   213,   214,    46,   285,   286,    54,   -24,   321,
     302,   107,   322,   108,   109,    58,    50,    59,   110,    54,
     -23,   111,   298,   177,    79,   178,   179,    58,    80,    59,
     110,   308,   204,   180,    85,   117,   117,    61,    62,   210,
      86,   211,   118,   118,   214,    87,    63,    54,    91,    61,
      62,   112,   314,   315,    70,    58,    93,    59,  -144,  -144,
    -144,  -144,   327,   181,   182,  -144,   102,     6,  -144,   309,
     186,   186,     6,     6,     6,   310,   311,   187,   187,    11,
      12,    13,   105,    84,  -144,  -144,   117,   335,    61,   153,
      61,   326,    28,   118,   327,    70,   125,   157,  -144,  -144,
     156,   327,   158,    54,   159,   117,   327,   177,   186,   178,
     179,    58,   118,    59,   110,   187,   169,   180,   160,   171,
     170,    54,   188,   172,   173,    55,   110,    56,    57,    58,
     112,    59,    54,    61,    62,    60,    55,   193,    56,    57,
      58,   194,    59,   198,   199,   202,    60,   181,   239,   223,
     230,    61,    62,   218,   -74,   -74,   -74,   -74,   227,   235,
     236,   -74,    61,    62,   -74,    63,    97,   237,   238,   181,
     -67,   248,   177,   247,   178,   179,    63,   253,   -40,   110,
     -74,   -74,   180,   177,   256,   178,   179,   254,   272,   280,
     110,   283,   284,   180,   -74,   -74,   -66,  -108,    61,    62,
     290,    55,   292,    56,    57,   293,   294,   299,   211,    61,
      62,    60,   181,   242,   300,   303,   305,   307,   332,   107,
     318,   108,   109,   181,   288,  -110,   110,    61,    62,   111,
     177,   330,   178,   179,   319,  -111,   320,   110,  -109,   344,
     180,    63,   167,   337,   340,    61,    62,   341,    55,   346,
      56,    57,   347,   348,   351,   106,    61,    62,    60,   112,
     130,    34,    35,    36,    37,   354,    38,    39,    40,     0,
     181,     0,   131,   132,    61,    62,   133,   134,   135,   161,
     137,   138,   139,   140,   141,   142,   162,   143,    63,   144,
     130,   349,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   131,   132,     0,     0,   133,   134,   135,   195,
     137,   138,   139,   140,   141,   142,   162,   143,   130,   144,
       0,     0,     0,     0,     0,     0,     0,     0,   145,     0,
     131,   132,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,     0,   144,     0,     0,
       0,     0,     0,     0,   203,   204,   145,   205,   206,   207,
     208,   209,   210,     0,   211,   212,   213,   214,   203,   204,
       0,   205,   206,   207,   208,   209,   210,     0,   211,   212,
     213,   214,     0,     0,     0,   203,   204,   229,   205,   206,
     207,   208,   209,   210,     0,   211,   212,   213,   214,   203,
     204,   251,   205,   206,   207,   208,   209,   210,     0,   211,
     212,   213,   214,     0,     0,     0,   203,   204,   295,   205,
     206,   207,   208,   209,   210,     0,   211,   212,   213,   214,
     203,   204,   306,   205,   206,   207,   208,   209,   210,     0,
     211,   212,   213,   214,     0,     0,     0,   203,   204,   323,
     205,   206,   207,   208,   209,   210,     0,   211,   212,   213,
     214,   234,   203,   204,     0,   205,   206,   207,   208,   209,
     210,     0,   211,   212,   213,   214,   203,   204,   301,   205,
     206,   207,   208,   209,   210,     0,   211,   212,   213,   214,
       0,   203,   204,   333,   205,   206,   207,   208,   209,   210,
       0,   211,   212,   213,   214,   203,   204,   345,   205,   206,
     207,   208,   209,   210,     0,   211,   212,   213,   214,     0,
       0,   228,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   215,   211,   212,   213,   214,     0,     0,     0,   203,
     204,     0,   205,   206,   207,   208,   209,   210,   217,   211,
     212,   213,   214,     0,     0,     0,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   255,   211,   212,   213,   214,
       0,     0,     0,   203,   204,     0,   205,   206,   207,   208,
     209,   210,   281,   211,   212,   213,   214,     0,     0,     0,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   282,
     211,   212,   213,   214,     0,     0,     0,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   297,   211,   212,   213,
     214,     0,     0,     0,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   304,   211,   212,   213,   214,     0,     0,
       0,   203,   204,     0,   205,   206,   207,   208,   209,   210,
     316,   211,   212,   213,   214,     0,     0,     0,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   317,   211,   212,
     213,   214,    34,    35,    36,    37,     0,    38,    39,    40,
       0,     0,     0,     0,   334,     0,     0,   203,   204,    51,
     205,   206,   207,   208,   209,   210,     0,   211,   212,   213,
     214,   203,   204,     0,   205,   206,   207,   208,   209,   210,
       0,   211,     0,   213,   214,   204,     0,   205,   206,   207,
     208,   209,   210,     0,   211,   204,   213,   214,   206,   207,
     208,   209,   210,     0,   211,   204,   213,   214,     0,   207,
     208,   209,   210,   204,   211,     0,   213,   214,   208,   209,
     210,     0,   211,     0,   213,   214
};

static const yytype_int16 yycheck[] =
{
      46,    63,    64,    65,   129,   111,   215,    63,   217,    50,
      60,    67,    17,    69,    25,    54,    25,    63,    80,    58,
      35,    67,    31,    69,    24,    80,    35,    16,    25,    29,
       0,   114,   115,    79,    80,   225,    24,    50,   228,    54,
      53,    80,    98,    54,    44,    33,    55,    16,    87,    38,
     112,    17,    98,    25,    85,    86,   112,    25,    55,   114,
      26,   116,    28,    94,   110,    96,   112,    33,   114,    38,
     116,    25,    25,   112,   180,   114,    48,   116,    35,   110,
      25,    50,    48,    55,   155,    53,   157,    55,   281,   282,
     129,   300,    25,   333,    48,   126,   127,    54,    22,    16,
     183,   184,    55,    48,    48,   345,   189,   316,   317,   299,
      55,    37,    38,   144,    38,    48,   155,   158,   157,   181,
     151,    38,    55,   316,   317,   181,    16,   183,   183,   160,
     180,    49,   341,    48,   173,   181,    50,   183,    50,   332,
     171,   172,   181,    24,   183,   354,    50,    37,    38,    53,
      31,    20,    33,    24,    35,    36,   156,   240,   351,    38,
     243,   354,    33,   194,    49,    36,    49,   198,    53,   215,
      53,   217,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   240,   240,    50,   218,    50,    53,
      50,    24,   223,    53,   240,   226,    29,   322,    31,   238,
      33,   240,    35,    36,    51,   236,   237,     7,    50,    50,
     272,    11,    53,    13,    14,    15,    54,    17,    18,     7,
      50,    21,   253,    11,    51,    13,    14,    15,    51,    17,
      18,   277,    24,    21,    48,   281,   282,    37,    38,    31,
      48,    33,   281,   282,    36,    48,    51,     7,    38,    37,
      38,    51,   283,   284,   300,    15,    38,    17,    11,    12,
      13,    14,   301,    51,    52,    18,    52,     0,    21,    38,
     316,   317,     5,     6,     7,    44,    45,   316,   317,     5,
       6,     7,    54,   322,    37,    38,   332,   318,    37,    38,
      37,    38,    53,   332,   333,   341,    38,    53,    51,    52,
      50,   340,    48,     7,    13,   351,   345,    11,   354,    13,
      14,    15,   351,    17,    18,   354,    52,    21,    25,    48,
      52,     7,    52,    48,    48,    11,    18,    13,    14,    15,
      51,    17,     7,    37,    38,    21,    11,    54,    13,    14,
      15,    55,    17,    48,    38,    38,    21,    51,    52,    48,
      52,    37,    38,    54,    11,    12,    13,    14,    49,    13,
      48,    18,    37,    38,    21,    51,    52,    48,    48,    51,
      18,    54,    11,    52,    13,    14,    51,    55,    52,    18,
      37,    38,    21,    11,    57,    13,    14,    38,    54,    25,
      18,    54,    48,    21,    51,    52,    18,    52,    37,    38,
      52,    11,    52,    13,    14,    52,    52,    48,    33,    37,
      38,    21,    51,    52,    12,    50,    49,    38,    12,    11,
      54,    13,    14,    51,    52,    52,    18,    37,    38,    21,
      11,    54,    13,    14,    52,    52,    52,    18,    52,    54,
      21,    51,    52,    49,    53,    37,    38,    49,    11,    54,
      13,    14,    31,    35,    49,    79,    37,    38,    21,    51,
      19,     3,     4,     5,     6,    49,     8,     9,    10,    -1,
      51,    -1,    31,    32,    37,    38,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    51,    48,
      19,   340,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    19,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    46,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    57,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    23,    24,    56,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    23,
      24,    56,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    23,    24,    56,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      23,    24,    56,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    -1,    -1,    -1,    23,    24,    56,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    54,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    23,    24,    54,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      -1,    23,    24,    54,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    23,    24,    54,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    -1,
      -1,    53,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    49,    33,    34,    35,    36,    -1,    -1,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    49,    33,
      34,    35,    36,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    49,    33,    34,    35,    36,
      -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    49,    33,    34,    35,    36,    -1,    -1,    -1,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    49,
      33,    34,    35,    36,    -1,    -1,    -1,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    49,    33,    34,    35,
      36,    -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    49,    33,    34,    35,    36,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      49,    33,    34,    35,    36,    -1,    -1,    -1,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    49,    33,    34,
      35,    36,     3,     4,     5,     6,    -1,     8,     9,    10,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    23,    24,    20,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      -1,    33,    -1,    35,    36,    24,    -1,    26,    27,    28,
      29,    30,    31,    -1,    33,    24,    35,    36,    27,    28,
      29,    30,    31,    -1,    33,    24,    35,    36,    -1,    28,
      29,    30,    31,    24,    33,    -1,    35,    36,    29,    30,
      31,    -1,    33,    -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    59,    60,    61,    62,    63,    64,    22,    38,
       0,    61,    61,    61,    48,    48,    49,    16,    38,    65,
      66,    50,    16,    38,    66,    50,    53,    49,    53,    50,
      20,    38,    50,    53,     3,     4,     5,     6,     8,     9,
      10,    68,    66,    50,    66,    68,    51,    50,    53,    66,
      54,    20,    68,    68,     7,    11,    13,    14,    15,    17,
      21,    37,    38,    51,    63,    69,    71,    72,    75,    76,
      78,    80,    83,    85,    87,    89,    91,    66,    65,    51,
      51,    16,    38,    67,    80,    48,    48,    48,    38,    73,
      80,    38,    91,    38,    25,    48,    55,    52,    72,    75,
      72,    72,    52,    75,    75,    54,    71,    11,    13,    14,
      18,    21,    51,    70,    72,    74,    77,    78,    80,    82,
      84,    86,    88,    90,    96,    38,    25,    55,    50,    53,
      19,    31,    32,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    46,    48,    57,    78,    92,    93,    94,
      95,    98,    92,    38,    80,    53,    50,    53,    48,    13,
      25,    38,    45,    92,    79,    92,    92,    52,    75,    52,
      52,    48,    48,    48,    78,    92,    90,    11,    13,    14,
      21,    51,    52,    72,    74,    75,    78,    80,    52,    74,
      96,    96,    74,    54,    55,    38,    92,    67,    48,    38,
      25,    92,    38,    23,    24,    26,    27,    28,    29,    30,
      31,    33,    34,    35,    36,    49,    92,    49,    54,    73,
      68,    73,    65,    48,    92,    48,    55,    49,    53,    56,
      52,    92,    92,    80,    54,    13,    48,    48,    48,    52,
      72,    75,    52,    74,    75,    96,    96,    52,    54,    96,
      92,    56,    92,    55,    38,    49,    57,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    76,
      76,    92,    54,    49,    92,    79,    92,    35,    54,    79,
      25,    49,    49,    54,    48,    92,    92,    80,    52,    75,
      52,    96,    52,    52,    52,    56,    54,    49,    92,    48,
      12,    54,    72,    50,    49,    49,    56,    38,    78,    38,
      44,    45,    77,    77,    92,    92,    49,    49,    54,    52,
      52,    50,    53,    56,    79,    76,    38,    80,    81,    97,
      54,    54,    12,    54,    49,    92,    67,    49,    31,    35,
      53,    49,    77,    97,    54,    54,    54,    31,    35,    81,
      76,    49,    97,    77,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    61,    61,    61,    61,    61,    61,
      61,    62,    63,    64,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    69,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    82,    82,    83,    83,    84,    85,    86,    87,    88,
      89,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    96,    96,    97,    97,    97,    98,    98,
      98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     1,     2,
       0,     9,    10,    10,     3,     4,     3,     5,     0,     1,
       2,     3,     2,     4,     3,     0,     5,     2,     3,     7,
       6,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     2,     1,     2,     1,     1,     2,     2,     6,     0,
       3,     3,     1,     1,     0,     1,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     7,     4,     5,     6,     0,     3,
       1,     3,     4,     3,     6,     6,     6,     6,     1,     3,
       0,     5,     7,     5,     7,     5,     5,     7,     7,     9,
       9,     2,     5,     4,     4,     4,     3,     3,     2,     4,
       3,     3,     1,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     3,     2,     3,     3,     1,     1,     1,
       1
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
  case 2: /* start: initial  */
#line 180 "part1.y"
               { syntaxMKscope((yyvsp[0].node),mycode); }
#line 1724 "y.tab.c"
    break;

  case 3: /* initial: code  */
#line 182 "part1.y"
              { (yyval.node) = makeNode("CODE", (yyvsp[0].node), NULL);}
#line 1730 "y.tab.c"
    break;

  case 4: /* code: function code  */
#line 184 "part1.y"
                    { (yyval.node) = makeNode("FUNCTION",(yyvsp[-1].node), (yyvsp[0].node)); }
#line 1736 "y.tab.c"
    break;

  case 5: /* code: function  */
#line 185 "part1.y"
               { (yyval.node) = makeNode("FUNCTION",(yyvsp[0].node), NULL); }
#line 1742 "y.tab.c"
    break;

  case 6: /* code: procedure code  */
#line 186 "part1.y"
                    { (yyval.node) = makeNode("PROC",(yyvsp[-1].node), (yyvsp[0].node)); }
#line 1748 "y.tab.c"
    break;

  case 7: /* code: procedure  */
#line 187 "part1.y"
                { (yyval.node) = makeNode("PROC",(yyvsp[0].node), NULL); }
#line 1754 "y.tab.c"
    break;

  case 8: /* code: main  */
#line 188 "part1.y"
               { (yyval.node) = makeNode("Main",(yyvsp[0].node), NULL); }
#line 1760 "y.tab.c"
    break;

  case 9: /* code: main code  */
#line 189 "part1.y"
                    { (yyval.node) = makeNode("Main",(yyvsp[-1].node), (yyvsp[0].node)); }
#line 1766 "y.tab.c"
    break;

  case 10: /* code: %empty  */
#line 190 "part1.y"
          {(yyval.node)=NULL;}
#line 1772 "y.tab.c"
    break;

  case 11: /* main: FUNC MAIN '(' ')' ':' VOID '{' body_proc '}'  */
#line 192 "part1.y"
                                                   {(yyval.node) = makeNode("ARGS NONE",NULL, makeNode("RET VOID", NULL,(yyvsp[-1].node))); }
#line 1778 "y.tab.c"
    break;

  case 12: /* function: FUNC ID '(' args ')' ':' type '{' body '}'  */
#line 194 "part1.y"
                                                     {(yyval.node) = makeNode((yyvsp[-8].string), NULL, makeNode("ARGS", makeNode("VAR", (yyvsp[-6].node), NULL) , makeNode((yyvsp[-3].string), NULL, (yyvsp[-1].node)))); }
#line 1784 "y.tab.c"
    break;

  case 13: /* procedure: FUNC ID '(' args ')' ':' VOID '{' body_proc '}'  */
#line 196 "part1.y"
                                                           {(yyval.node) = makeNode((yyvsp[-8].string),NULL, makeNode("ARGS", (yyvsp[-6].node),makeNode("RET VOID", NULL,(yyvsp[-1].node)))); }
#line 1790 "y.tab.c"
    break;

  case 14: /* args: args_Id ':' type  */
#line 198 "part1.y"
                       { (yyval.node) = makeNode((yyvsp[0].string), (yyvsp[-2].node), NULL); }
#line 1796 "y.tab.c"
    break;

  case 15: /* args: args ',' args_Id type  */
#line 199 "part1.y"
                            { (yyval.node) = makeNode((yyvsp[0].string), (yyvsp[-1].node), (yyvsp[-3].node)); }
#line 1802 "y.tab.c"
    break;

  case 16: /* args: FUNCARGS args_Id type  */
#line 200 "part1.y"
                            { (yyval.node) = makeNode((yyvsp[0].string), (yyvsp[-1].node), NULL); }
#line 1808 "y.tab.c"
    break;

  case 17: /* args: FUNCARGS args_Id type ';' args  */
#line 201 "part1.y"
                                     { (yyval.node) = makeNode((yyvsp[-2].string), (yyvsp[-3].node), (yyvsp[0].node)); }
#line 1814 "y.tab.c"
    break;

  case 18: /* args: %empty  */
#line 202 "part1.y"
      { (yyval.node) = NULL; }
#line 1820 "y.tab.c"
    break;

  case 19: /* args_Id: ID  */
#line 204 "part1.y"
            { (yyval.node) = makeNode((yyvsp[0].string), NULL, NULL); }
#line 1826 "y.tab.c"
    break;

  case 20: /* args_Id: ID ':'  */
#line 205 "part1.y"
                { (yyval.node) = makeNode((yyvsp[-1].string), NULL,NULL); }
#line 1832 "y.tab.c"
    break;

  case 21: /* args_Id: ID ',' args_Id  */
#line 206 "part1.y"
                        { (yyval.node) = makeNode((yyvsp[-2].string), NULL, (yyvsp[0].node)); }
#line 1838 "y.tab.c"
    break;

  case 22: /* args_Id: FUNCARGS ID  */
#line 207 "part1.y"
                     { (yyval.node) = makeNode((yyvsp[0].string), NULL, NULL); }
#line 1844 "y.tab.c"
    break;

  case 23: /* args_Id: FUNCARGS ID ',' args_Id  */
#line 208 "part1.y"
                                 { (yyval.node) = makeNode((yyvsp[-2].string), NULL, (yyvsp[0].node)); }
#line 1850 "y.tab.c"
    break;

  case 24: /* args_Id: FUNCARGS ID ':'  */
#line 209 "part1.y"
                         { (yyval.node) = makeNode((yyvsp[-1].string), NULL, NULL); (yyval.node) -> left = makeNode((yyvsp[-1].string), NULL, NULL); }
#line 1856 "y.tab.c"
    break;

  case 25: /* args_Id: %empty  */
#line 210 "part1.y"
         { (yyval.node) = NULL; }
#line 1862 "y.tab.c"
    break;

  case 26: /* string_Id: ID '[' expression ']' ';'  */
#line 212 "part1.y"
                                     { (yyval.node) = makeNode((yyvsp[-4].string), makeNode("[]", NULL,(yyvsp[-2].node)), NULL); }
#line 1868 "y.tab.c"
    break;

  case 27: /* string_Id: assignment ':'  */
#line 213 "part1.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1874 "y.tab.c"
    break;

  case 28: /* string_Id: assignment ',' string_Id  */
#line 214 "part1.y"
                                    { (yyvsp[-2].node) -> right = (yyvsp[0].node);  (yyval.node) = (yyvsp[-2].node); }
#line 1880 "y.tab.c"
    break;

  case 29: /* string_Id: FUNCARGS ID '[' expression ']' ',' string_Id  */
#line 215 "part1.y"
                                                         { (yyval.node) = makeNode((yyvsp[-5].string), makeNode("[]", NULL,(yyvsp[-3].node)), (yyvsp[0].node)); }
#line 1886 "y.tab.c"
    break;

  case 30: /* string_Id: FUNCARGS ID '[' expression ']' ':'  */
#line 216 "part1.y"
                                              {(yyval.node) = makeNode((yyvsp[-4].string), makeNode("[]", NULL,(yyvsp[-2].node)), NULL); }
#line 1892 "y.tab.c"
    break;

  case 31: /* type: BOOL  */
#line 218 "part1.y"
           { (yyval.string) = "BOOL"; }
#line 1898 "y.tab.c"
    break;

  case 32: /* type: CHAR  */
#line 219 "part1.y"
           { (yyval.string) = "CHAR"; }
#line 1904 "y.tab.c"
    break;

  case 33: /* type: INT  */
#line 220 "part1.y"
          { (yyval.string) = "INT"; }
#line 1910 "y.tab.c"
    break;

  case 34: /* type: REAL  */
#line 221 "part1.y"
           { (yyval.string) = "REAL"; }
#line 1916 "y.tab.c"
    break;

  case 35: /* type: INTP  */
#line 222 "part1.y"
           { (yyval.string) = "INT_PTR"; }
#line 1922 "y.tab.c"
    break;

  case 36: /* type: CHARP  */
#line 223 "part1.y"
            { (yyval.string) = "CHAR_PTR"; }
#line 1928 "y.tab.c"
    break;

  case 37: /* type: REALP  */
#line 224 "part1.y"
            { (yyval.string) = "REAL_PTR"; }
#line 1934 "y.tab.c"
    break;

  case 38: /* string_type: STRING string_Id  */
#line 226 "part1.y"
                              { (yyval.node) =(yyvsp[0].node); }
#line 1940 "y.tab.c"
    break;

  case 39: /* body: declaration nested_statement return_statement  */
#line 228 "part1.y"
                                                    { (yyval.node) = makeNode("BODY", makeNode("", (yyvsp[-2].node), (yyvsp[-1].node)),(yyvsp[0].node)); }
#line 1946 "y.tab.c"
    break;

  case 40: /* body: declaration return_statement  */
#line 229 "part1.y"
                                   {(yyval.node) = makeNode("BODY",(yyvsp[-1].node), (yyvsp[0].node)); }
#line 1952 "y.tab.c"
    break;

  case 41: /* body: nested_statement return_statement  */
#line 230 "part1.y"
                                        { (yyval.node) = makeNode("BODY", (yyvsp[-1].node) ,(yyvsp[0].node)); }
#line 1958 "y.tab.c"
    break;

  case 42: /* body: nested_statement  */
#line 231 "part1.y"
                       { (yyval.node) = makeNode("BODY", (yyvsp[0].node) ,NULL); }
#line 1964 "y.tab.c"
    break;

  case 43: /* body_proc: declaration proc_nested_statement  */
#line 233 "part1.y"
                                             { (yyval.node) = makeNode("BODY", makeNode("", (yyvsp[-1].node), (yyvsp[0].node)),NULL); }
#line 1970 "y.tab.c"
    break;

  case 44: /* body_proc: declaration  */
#line 234 "part1.y"
                       {(yyval.node) = makeNode("BODY",(yyvsp[0].node), NULL); }
#line 1976 "y.tab.c"
    break;

  case 45: /* body_proc: proc_nested_statement  */
#line 235 "part1.y"
                                 { (yyval.node) = makeNode("BODY", (yyvsp[0].node) ,NULL); }
#line 1982 "y.tab.c"
    break;

  case 46: /* declaration: function declaration  */
#line 237 "part1.y"
                                  { (yyval.node) = makeNode("FUNCTION", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1988 "y.tab.c"
    break;

  case 47: /* declaration: string_type declaration  */
#line 238 "part1.y"
                                     {(yyval.node) = makeNode("STRING",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1994 "y.tab.c"
    break;

  case 48: /* declaration: VAR long_declaration ':' type ';' declaration  */
#line 239 "part1.y"
                                                           { (yyval.node) = makeNode("VAR",makeNode((yyvsp[-2].string),(yyvsp[-4].node),(yyvsp[0].node)),NULL);}
#line 2000 "y.tab.c"
    break;

  case 49: /* declaration: %empty  */
#line 240 "part1.y"
             { (yyval.node) = NULL; }
#line 2006 "y.tab.c"
    break;

  case 50: /* long_declaration: assignment ',' long_declaration  */
#line 242 "part1.y"
                                                  {(yyvsp[-2].node) -> right=(yyvsp[0].node);(yyval.node)=(yyvsp[-2].node);}
#line 2012 "y.tab.c"
    break;

  case 51: /* long_declaration: ID ',' long_declaration  */
#line 243 "part1.y"
                                          {(yyval.node) = makeNode((yyvsp[-2].string),NULL,(yyvsp[0].node));}
#line 2018 "y.tab.c"
    break;

  case 52: /* long_declaration: assignment  */
#line 244 "part1.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2024 "y.tab.c"
    break;

  case 53: /* long_declaration: ID  */
#line 245 "part1.y"
                      { (yyval.node) = makeNode((yyvsp[0].string), NULL, NULL); }
#line 2030 "y.tab.c"
    break;

  case 54: /* long_declaration: %empty  */
#line 246 "part1.y"
                  { (yyval.node) = NULL; }
#line 2036 "y.tab.c"
    break;

  case 55: /* nested_statement: statement  */
#line 248 "part1.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2042 "y.tab.c"
    break;

  case 56: /* nested_statement: statement nested_statement  */
#line 249 "part1.y"
                                             { (yyvsp[-1].node) -> right = (yyvsp[0].node); (yyval.node) = (yyvsp[-1].node); }
#line 2048 "y.tab.c"
    break;

  case 57: /* proc_nested_statement: proc_statement  */
#line 251 "part1.y"
                                      { (yyval.node) = (yyvsp[0].node); }
#line 2054 "y.tab.c"
    break;

  case 58: /* proc_nested_statement: proc_statement proc_nested_statement  */
#line 252 "part1.y"
                                                            { (yyvsp[-1].node) -> right = (yyvsp[0].node); (yyval.node) = (yyvsp[-1].node); }
#line 2060 "y.tab.c"
    break;

  case 59: /* proc_statement: assignment ';'  */
#line 254 "part1.y"
                               {(yyval.node) = (yyvsp[-1].node);}
#line 2066 "y.tab.c"
    break;

  case 60: /* proc_statement: func_statement  */
#line 255 "part1.y"
                               {(yyval.node)=(yyvsp[0].node);}
#line 2072 "y.tab.c"
    break;

  case 61: /* proc_statement: proc_if_statement  */
#line 256 "part1.y"
                                  {(yyval.node)=(yyvsp[0].node);}
#line 2078 "y.tab.c"
    break;

  case 62: /* proc_statement: proc_while_statement  */
#line 257 "part1.y"
                                     { (yyval.node) = (yyvsp[0].node);}
#line 2084 "y.tab.c"
    break;

  case 63: /* proc_statement: proc_do_statement  */
#line 258 "part1.y"
                                  { (yyval.node) = (yyvsp[0].node);}
#line 2090 "y.tab.c"
    break;

  case 64: /* proc_statement: block_proc  */
#line 259 "part1.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2096 "y.tab.c"
    break;

  case 65: /* proc_statement: proc_for_statement  */
#line 260 "part1.y"
                                   {(yyval.node) = (yyvsp[0].node);}
#line 2102 "y.tab.c"
    break;

  case 66: /* statement: assignment ';'  */
#line 262 "part1.y"
                          {(yyval.node) = (yyvsp[-1].node);}
#line 2108 "y.tab.c"
    break;

  case 67: /* statement: func_statement  */
#line 263 "part1.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2114 "y.tab.c"
    break;

  case 68: /* statement: if_statement  */
#line 264 "part1.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2120 "y.tab.c"
    break;

  case 69: /* statement: while_statement  */
#line 265 "part1.y"
                           { (yyval.node) = (yyvsp[0].node);}
#line 2126 "y.tab.c"
    break;

  case 70: /* statement: do_statement  */
#line 266 "part1.y"
                        { (yyval.node) = (yyvsp[0].node);}
#line 2132 "y.tab.c"
    break;

  case 71: /* statement: block  */
#line 267 "part1.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 2138 "y.tab.c"
    break;

  case 72: /* statement: for_statement  */
#line 268 "part1.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 2144 "y.tab.c"
    break;

  case 73: /* statement: return_statement  */
#line 269 "part1.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2150 "y.tab.c"
    break;

  case 74: /* func_statement: ID ASSIGN ID '(' func_arguments ')' ';'  */
#line 271 "part1.y"
                                                        { (yyval.node) = makeNode((yyvsp[-5].string),makeNode((yyvsp[-6].string),NULL,makeNode((yyvsp[-4].string),(yyvsp[-2].node),NULL)),NULL); }
#line 2156 "y.tab.c"
    break;

  case 75: /* func_statement: ID '(' func_arguments ')'  */
#line 272 "part1.y"
                                          {(yyval.node) = makeNode("Call func",makeNode((yyvsp[-3].string),NULL,NULL),makeNode("ARGS",(yyvsp[-1].node),NULL));}
#line 2162 "y.tab.c"
    break;

  case 76: /* func_statement: ID '(' func_arguments ')' ';'  */
#line 273 "part1.y"
                                              {(yyval.node) = makeNode("Call func",makeNode((yyvsp[-4].string),NULL,NULL),makeNode("ARGS",(yyvsp[-2].node),NULL));}
#line 2168 "y.tab.c"
    break;

  case 77: /* func_statement: ID '(' func_arguments ')' ADD func_statement  */
#line 274 "part1.y"
                                                             {(yyval.node) = makeNode((yyvsp[-5].string),(yyvsp[-3].node),(yyvsp[0].node));}
#line 2174 "y.tab.c"
    break;

  case 78: /* func_arguments: %empty  */
#line 276 "part1.y"
                { (yyval.node) = NULL; }
#line 2180 "y.tab.c"
    break;

  case 79: /* func_arguments: expression ',' func_arguments  */
#line 277 "part1.y"
                                              {(yyvsp[-2].node) -> right=(yyvsp[0].node);(yyval.node)=(yyvsp[-2].node);}
#line 2186 "y.tab.c"
    break;

  case 80: /* func_arguments: expression  */
#line 278 "part1.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2192 "y.tab.c"
    break;

  case 81: /* assignment: ID ASSIGN expression  */
#line 280 "part1.y"
                                 { (yyval.node) = makeNode((yyvsp[-1].string),makeNode((yyvsp[-2].string),NULL, (yyvsp[0].node)), NULL);}
#line 2198 "y.tab.c"
    break;

  case 82: /* assignment: ADDRESS ID ASSIGN expression  */
#line 281 "part1.y"
                                         { (yyval.node) = makeNode((yyvsp[-3].string),makeNode((yyvsp[-1].string),makeNode((yyvsp[-2].string),NULL, (yyvsp[0].node)), NULL), NULL);}
#line 2204 "y.tab.c"
    break;

  case 83: /* assignment: ID ASSIGN STRING_VAL  */
#line 282 "part1.y"
                                 {(yyval.node) = makeNode((yyvsp[-1].string), makeNode((yyvsp[-2].string), makeNode((yyvsp[0].string),NULL, NULL), NULL), NULL);}
#line 2210 "y.tab.c"
    break;

  case 84: /* assignment: ID '[' expression ']' ASSIGN STRING_VAL  */
#line 283 "part1.y"
                                                    {(yyval.node) = makeNode((yyvsp[-1].string), makeNode((yyvsp[-5].string), makeNode("[]",NULL,(yyvsp[-3].node)),NULL),makeNode((yyvsp[0].string),NULL,NULL));}
#line 2216 "y.tab.c"
    break;

  case 85: /* assignment: ID ASSIGN ID '[' expression ']'  */
#line 284 "part1.y"
                                            {(yyval.node) = makeNode((yyvsp[-4].string), makeNode((yyvsp[-5].string),NULL,makeNode((yyvsp[-3].string),makeNode("[]",NULL,(yyvsp[-1].node)),NULL)),NULL);}
#line 2222 "y.tab.c"
    break;

  case 86: /* assignment: ID '[' expression ']' ASSIGN CHAR_VAL  */
#line 285 "part1.y"
                                                  {(yyval.node) = makeNode((yyvsp[-1].string), makeNode((yyvsp[-5].string), makeNode("[]",NULL,(yyvsp[-3].node)),NULL),makeNode((yyvsp[0].string),NULL,NULL));}
#line 2228 "y.tab.c"
    break;

  case 87: /* assignment: ID '[' expression ']' ASSIGN ID  */
#line 286 "part1.y"
                                            {(yyval.node) = makeNode((yyvsp[-1].string), makeNode((yyvsp[-5].string), makeNode("[]",NULL,(yyvsp[-3].node)),NULL),makeNode((yyvsp[0].string),NULL,NULL));}
#line 2234 "y.tab.c"
    break;

  case 88: /* multi_assign: assignment  */
#line 288 "part1.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2240 "y.tab.c"
    break;

  case 89: /* multi_assign: assignment ',' multi_assign  */
#line 289 "part1.y"
                                          { (yyval.node) = makeNode("", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2246 "y.tab.c"
    break;

  case 90: /* multi_assign: %empty  */
#line 290 "part1.y"
              { (yyval.node) = NULL; }
#line 2252 "y.tab.c"
    break;

  case 91: /* if_statement: IF '(' expression ')' statement  */
#line 292 "part1.y"
                                              { (yyval.node) = makeNode("IF",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2258 "y.tab.c"
    break;

  case 92: /* if_statement: IF '(' expression ')' statement ELSE statement  */
#line 293 "part1.y"
                                                             { (yyval.node) = makeNode("IF-ELSE", makeNode("", (yyvsp[-4].node), makeNode("", (yyvsp[-2].node),(yyvsp[0].node))), NULL); }
#line 2264 "y.tab.c"
    break;

  case 93: /* proc_if_statement: IF '(' expression ')' proc_statement  */
#line 295 "part1.y"
                                                        { (yyval.node) = makeNode("IF",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2270 "y.tab.c"
    break;

  case 94: /* proc_if_statement: IF '(' expression ')' proc_statement ELSE proc_statement  */
#line 296 "part1.y"
                                                                            { (yyval.node) = makeNode("IF-ELSE", makeNode("", (yyvsp[-4].node), makeNode("", (yyvsp[-2].node),(yyvsp[0].node))), NULL); }
#line 2276 "y.tab.c"
    break;

  case 95: /* while_statement: WHILE '(' expression ')' statement  */
#line 298 "part1.y"
                                                    { (yyval.node) = makeNode((yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2282 "y.tab.c"
    break;

  case 96: /* proc_while_statement: WHILE '(' expression ')' proc_statement  */
#line 300 "part1.y"
                                                              { (yyval.node) = makeNode((yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2288 "y.tab.c"
    break;

  case 97: /* do_statement: DO block WHILE '(' expression ')' ';'  */
#line 302 "part1.y"
                                                    { (yyval.node) = makeNode((yyvsp[-6].string), makeNode("", (yyvsp[-5].node),NULL), makeNode((yyvsp[-4].string), (yyvsp[-2].node), NULL)); }
#line 2294 "y.tab.c"
    break;

  case 98: /* proc_do_statement: DO block_proc WHILE '(' expression ')' ';'  */
#line 304 "part1.y"
                                                              { (yyval.node) = makeNode((yyvsp[-6].string), makeNode("", (yyvsp[-5].node),NULL), makeNode((yyvsp[-4].string), (yyvsp[-2].node), NULL)); }
#line 2300 "y.tab.c"
    break;

  case 99: /* for_statement: FOR '(' assignment ';' expression ';' update ')' statement  */
#line 306 "part1.y"
                                                                          { (yyval.node) = makeNode((yyvsp[-8].string), makeNode("INITS", (yyvsp[-6].node), makeNode("EXPR", (yyvsp[-4].node), makeNode("UPDATE", (yyvsp[-2].node), (yyvsp[0].node)))), NULL); }
#line 2306 "y.tab.c"
    break;

  case 100: /* proc_for_statement: FOR '(' assignment ';' expression ';' update ')' proc_statement  */
#line 308 "part1.y"
                                                                                    { (yyval.node) = makeNode((yyvsp[-8].string), makeNode("INITS", (yyvsp[-6].node), makeNode("EXPR", (yyvsp[-4].node), makeNode("UPDATE", (yyvsp[-2].node), (yyvsp[0].node)))), NULL); }
#line 2312 "y.tab.c"
    break;

  case 101: /* block: '{' '}'  */
#line 310 "part1.y"
               {(yyval.node) = makeNode("BLOCK",NULL, NULL);}
#line 2318 "y.tab.c"
    break;

  case 102: /* block: '{' declaration nested_statement return_statement '}'  */
#line 311 "part1.y"
                                                             { (yyval.node) = makeNode("BLOCK", makeNode("", (yyvsp[-3].node), (yyvsp[-2].node)),(yyvsp[-1].node)); }
#line 2324 "y.tab.c"
    break;

  case 103: /* block: '{' declaration return_statement '}'  */
#line 312 "part1.y"
                                            { (yyval.node) = makeNode("BLOCK", (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2330 "y.tab.c"
    break;

  case 104: /* block: '{' nested_statement return_statement '}'  */
#line 313 "part1.y"
                                                 { (yyval.node) = makeNode("BLOCK", (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2336 "y.tab.c"
    break;

  case 105: /* block: '{' declaration proc_nested_statement '}'  */
#line 314 "part1.y"
                                                 { (yyval.node) = makeNode("BLOCK", makeNode("", (yyvsp[-2].node), (yyvsp[-1].node)),NULL);}
#line 2342 "y.tab.c"
    break;

  case 106: /* block: '{' declaration '}'  */
#line 315 "part1.y"
                           {(yyval.node) = makeNode("BLOCK",(yyvsp[-1].node), NULL); }
#line 2348 "y.tab.c"
    break;

  case 107: /* block: '{' proc_nested_statement '}'  */
#line 316 "part1.y"
                                     { (yyval.node) = makeNode("BLOCK", (yyvsp[-1].node) ,NULL); }
#line 2354 "y.tab.c"
    break;

  case 108: /* block_proc: '{' '}'  */
#line 318 "part1.y"
                    {(yyval.node) = makeNode("BLOCK",NULL, NULL);}
#line 2360 "y.tab.c"
    break;

  case 109: /* block_proc: '{' declaration proc_nested_statement '}'  */
#line 319 "part1.y"
                                                      { (yyval.node) = makeNode("BLOCK", makeNode("", (yyvsp[-2].node), (yyvsp[-1].node)),NULL);}
#line 2366 "y.tab.c"
    break;

  case 110: /* block_proc: '{' declaration '}'  */
#line 320 "part1.y"
                                {(yyval.node) = makeNode("BLOCK",(yyvsp[-1].node), NULL); }
#line 2372 "y.tab.c"
    break;

  case 111: /* block_proc: '{' proc_nested_statement '}'  */
#line 321 "part1.y"
                                          { (yyval.node) = makeNode("BLOCK", (yyvsp[-1].node) ,NULL); }
#line 2378 "y.tab.c"
    break;

  case 112: /* expression: element_of_expression  */
#line 323 "part1.y"
                                  {(yyval.node) = (yyvsp[0].node);}
#line 2384 "y.tab.c"
    break;

  case 113: /* expression: '(' expression ')'  */
#line 324 "part1.y"
                               {(yyval.node) = makeNode("",(yyvsp[-1].node), NULL);}
#line 2390 "y.tab.c"
    break;

  case 114: /* expression: expression EQ expression  */
#line 325 "part1.y"
                                         {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2396 "y.tab.c"
    break;

  case 115: /* expression: MUL '(' expression ')'  */
#line 326 "part1.y"
                                   {(yyval.node) = makeNode("*",(yyvsp[-1].node), NULL);}
#line 2402 "y.tab.c"
    break;

  case 116: /* expression: expression AND expression  */
#line 327 "part1.y"
                                          {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2408 "y.tab.c"
    break;

  case 117: /* expression: expression OR expression  */
#line 328 "part1.y"
                                         {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2414 "y.tab.c"
    break;

  case 118: /* expression: expression GT expression  */
#line 329 "part1.y"
                                         {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2420 "y.tab.c"
    break;

  case 119: /* expression: expression GTE expression  */
#line 330 "part1.y"
                                          {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2426 "y.tab.c"
    break;

  case 120: /* expression: expression LTE expression  */
#line 331 "part1.y"
                                          {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2432 "y.tab.c"
    break;

  case 121: /* expression: expression LT expression  */
#line 332 "part1.y"
                                         {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2438 "y.tab.c"
    break;

  case 122: /* expression: expression NEQ expression  */
#line 333 "part1.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2444 "y.tab.c"
    break;

  case 123: /* expression: expression ADD expression  */
#line 334 "part1.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2450 "y.tab.c"
    break;

  case 124: /* expression: expression SUB expression  */
#line 335 "part1.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2456 "y.tab.c"
    break;

  case 125: /* expression: expression MUL expression  */
#line 336 "part1.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2462 "y.tab.c"
    break;

  case 126: /* expression: unary_op expression  */
#line 337 "part1.y"
                                            { (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[0].node), NULL); }
#line 2468 "y.tab.c"
    break;

  case 127: /* expression: expression DIV expression  */
#line 338 "part1.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node) ,NULL);}
#line 2474 "y.tab.c"
    break;

  case 128: /* expression: address_of  */
#line 339 "part1.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2480 "y.tab.c"
    break;

  case 129: /* element_of_expression: primitive_value  */
#line 341 "part1.y"
                                       {(yyval.node) = makeNode((yyvsp[0].string),NULL, NULL); }
#line 2486 "y.tab.c"
    break;

  case 130: /* element_of_expression: '|' ID '|'  */
#line 342 "part1.y"
                                    { (yyval.node) = makeNode("STR_LEN", makeNode((yyvsp[-1].string), NULL, NULL), NULL); }
#line 2492 "y.tab.c"
    break;

  case 131: /* element_of_expression: func_statement  */
#line 343 "part1.y"
                                      { (yyval.node) = (yyvsp[0].node); }
#line 2498 "y.tab.c"
    break;

  case 132: /* element_of_expression: ID  */
#line 344 "part1.y"
                          { (yyval.node) = makeNode((yyvsp[0].string),NULL, NULL); }
#line 2504 "y.tab.c"
    break;

  case 133: /* primitive_value: CHAR_VAL  */
#line 346 "part1.y"
                          { (yyval.string) = (yyvsp[0].string); }
#line 2510 "y.tab.c"
    break;

  case 134: /* primitive_value: HEX_INT  */
#line 347 "part1.y"
                          { (yyval.string) = (yyvsp[0].string); }
#line 2516 "y.tab.c"
    break;

  case 135: /* primitive_value: DEC_INT  */
#line 348 "part1.y"
                          {(yyval.string) = (yyvsp[0].string); }
#line 2522 "y.tab.c"
    break;

  case 136: /* primitive_value: REAL_VAL  */
#line 349 "part1.y"
                          { (yyval.string) = (yyvsp[0].string); }
#line 2528 "y.tab.c"
    break;

  case 137: /* primitive_value: TRUE_VAL  */
#line 350 "part1.y"
                          { (yyval.string) = (yyvsp[0].string);}
#line 2534 "y.tab.c"
    break;

  case 138: /* primitive_value: NULLP  */
#line 351 "part1.y"
                       { (yyval.string) = (yyvsp[0].string); }
#line 2540 "y.tab.c"
    break;

  case 139: /* primitive_value: DER_ID  */
#line 352 "part1.y"
                        { (yyval.string) = (yyvsp[0].string); }
#line 2546 "y.tab.c"
    break;

  case 140: /* primitive_value: FALSE_VAL  */
#line 353 "part1.y"
                           { (yyval.string) = (yyvsp[0].string);}
#line 2552 "y.tab.c"
    break;

  case 141: /* address_of: ADDRESS ID  */
#line 355 "part1.y"
                       { (yyval.node) = makeNode((yyvsp[-1].string), makeNode((yyvsp[0].string), NULL, NULL), NULL); }
#line 2558 "y.tab.c"
    break;

  case 142: /* address_of: ADDRESS ID '[' expression ']'  */
#line 356 "part1.y"
                                          { (yyval.node) = makeNode((yyvsp[-4].string), makeNode((yyvsp[-3].string), makeNode("[]", (yyvsp[-1].node), NULL), NULL), NULL); }
#line 2564 "y.tab.c"
    break;

  case 143: /* return_statement: RETURN expression ';'  */
#line 358 "part1.y"
                                       { (yyval.node) = makeNode("RET", (yyvsp[-1].node), NULL); }
#line 2570 "y.tab.c"
    break;

  case 144: /* return_statement: RETURN func_statement  */
#line 359 "part1.y"
                                        { (yyval.node) = makeNode("RET", (yyvsp[0].node), NULL); }
#line 2576 "y.tab.c"
    break;

  case 145: /* update: ID ADD ADD  */
#line 361 "part1.y"
                   { (yyval.node) = makeNode("++", makeNode((yyvsp[-2].string), NULL, NULL), NULL); }
#line 2582 "y.tab.c"
    break;

  case 146: /* update: ID SUB SUB  */
#line 362 "part1.y"
                   { (yyval.node) = makeNode("--", makeNode((yyvsp[-2].string), NULL, NULL), NULL); }
#line 2588 "y.tab.c"
    break;

  case 147: /* update: multi_assign  */
#line 363 "part1.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2594 "y.tab.c"
    break;

  case 148: /* unary_op: ADD  */
#line 365 "part1.y"
              { (yyval.string) = (yyvsp[0].string); }
#line 2600 "y.tab.c"
    break;

  case 149: /* unary_op: SUB  */
#line 366 "part1.y"
              { (yyval.string) = (yyvsp[0].string); }
#line 2606 "y.tab.c"
    break;

  case 150: /* unary_op: NOT  */
#line 367 "part1.y"
              {(yyval.string) = (yyvsp[0].string);}
#line 2612 "y.tab.c"
    break;


#line 2616 "y.tab.c"

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

#line 369 "part1.y"

#include "lex.yy.c"
int main()
{
    int x= yyparse();
	if(x == 0)
	{
		printf("\033[0;32m");
	printf("syntax valid\n"); 
	printf("Semantics valid\n");
	}
	return x;
}

Arguments * callfuncargs(code * CODEscope,node *tree,int * count)
{
	Arguments* arr = NULL ,ar[50];
	char* type, *len;
	while(tree != NULL) {
		ar[(*count)++].type = exprtype(tree -> left,CODEscope);
		printf("390 %d %s, ",*count,tree -> left -> token);
		if(tree -> right != NULL)
			tree=tree -> right -> left;
		else
			tree=NULL;

	}
	arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
	for(int i=0;i<*count;i++)
		arr[i].type=ar[i].type;
	return arr;
}
char* findfunc(node * tree,code * CODEscope)
{
	code*temp=CODEscope;
	Arguments* args;
	int find=false,flag=true;
	while(temp != NULL)
	{
		for(int i=0; i < temp -> countfunc; i++)
		if(strcmp(tree -> left -> token, temp -> func[i] -> name) == 0)
		{
			find=true;
			flag=true;
			int count=0;
			args=callfuncargs(CODEscope,tree -> right -> left, &count);
			printf("416 %d %d ",count,temp -> func[i] -> countArgs);
			if(count == temp -> func[i] -> countArgs) {
				for(int j = 0; j < count; j++) {
					printf("L421 %s %s",args[j].type,temp -> func[i] -> args -> type);
					if(strcmp(args[j].type,temp -> func[i] -> args -> type) != 0)
						flag=false;
				}
				if(flag == true)
					return temp -> func[i] -> returnType;
			}
		}
		temp=temp -> beforeLVL;
	}
	printf("ERORR,func %s not find call in scope %s in func/proc %s\n",tree -> left -> token,CODEscope -> name,mycode -> func[mycode -> countfunc-1] -> name);
	if(find == true)
		printf("but find func with some name but other args\n");
		exit(1);
}
char *findvar(node * tree,code * CODEscope)
{
	code*temp=CODEscope;
	if(strcmp(tree -> token,"solovar") == 0)
		tree=tree -> left;
	while(temp != NULL)
	{
		for(int i=0;i<temp -> countvar;i++)
		if(strcmp(tree -> token,temp -> var[i].name) == 0)
		{
			
			if(tree -> left != NULL && strcmp(tree -> left -> token,"[") == 0)
			{
				if(strcmp(temp -> var[i].type,"STRING") == 0)
					if(strcmp(exprtype(tree -> left -> left,CODEscope),"INT") == 0)
					{
						return "CHAR";
					}
					else
					{
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in func/proc %s\n",CODEscope -> name,mycode -> func[mycode -> countfunc-1] -> name);
						exit(1);
					}
				else
				{
					printf("ERORR,you can use index only on string type (<string>[<int>]) in scope %s in func/proc %s\n",CODEscope -> name,mycode -> func[mycode -> countfunc-1] -> name);
					exit(1);
				}

			}
			else
			return temp -> var[i].type;

		}
		temp = temp -> beforeLVL;
	}
	printf("ERORR,var %s not find in scope %s in func/proc %s\n ",tree -> token,CODEscope -> name,mycode -> func[mycode -> countfunc-1] -> name);
	exit(1);
	
}
char * exprtype(node * tree,code* CODEscope){
	char* msg = (char*)malloc(sizeof(char)*7);
	msg = "";
	if(strcmp(tree -> token,"NULL") == 0)
		msg = "NULL";
	else
	if(tree -> left != NULL){
		if(strcmp(tree -> left -> token,"INT") == 0)
			msg= "INT";
		if(strcmp(tree -> left -> token,"HEX") == 0)
			msg= "HEX";
		if(strcmp(tree -> left -> token,"CHAR") == 0)
			msg= "CHAR";
		if(strcmp(tree -> left -> token,"REAL") == 0)
			msg= "REAL";
		if(strcmp(tree -> left -> token,"STRING") == 0)
			msg= "STRING";
		if(strcmp(tree -> left -> token,"BOOLEAN") == 0)
			msg= "BOOL";
		if(strcmp(tree -> token,"!") == 0)
		if(strcmp(exprtype(tree -> left,CODEscope),"BOOL") == 0)
			msg="BOOL";
		else{
			printf("Erorr op ! you can use only on boolean type");
			exit(1);
		}
		if(strcmp(tree -> token,"|") == 0)
		if(strcmp(exprtype(tree -> left,CODEscope),"STRING") == 0)
		msg="INT";
		else{
			printf("Erorr op | you can use only on string type in func/proc %s",mycode -> func[mycode -> countfunc-1] -> name);
			exit(1);
		}
		if(strcmp(tree -> token,"==") == 0||strcmp(tree -> token,"!=") == 0)
		{
			if(strcmp(exprtype(tree -> left,CODEscope),
			exprtype(tree -> right,CODEscope)) == 0
			&& strcmp(exprtype(tree -> right,CODEscope), "STRING") != 0)
			msg = "BOOL";
			else {
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",
				tree -> token, exprtype(tree -> left, CODEscope),
				exprtype(tree -> right, CODEscope),
				mycode -> func[mycode -> countfunc - 1] -> name);
				exit(1);
			}
		}

		if(strcmp(tree -> token, ">=") == 0 
		|| strcmp(tree -> token, ">") == 0
		|| strcmp(tree -> token, "<=") == 0
		|| strcmp(tree -> token, "<") == 0) {
			if ((strcmp(exprtype(tree -> left, CODEscope),"INT") == 0
			|| strcmp(exprtype(tree -> left,CODEscope),"REAL") == 0)
			&& (strcmp(exprtype(tree -> right,CODEscope),"INT") == 0
			|| strcmp(exprtype(tree -> right,CODEscope),"REAL") == 0))
			msg = "BOOL";
			else {
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",
				tree -> token, exprtype(tree -> left,CODEscope),exprtype(tree -> right, CODEscope),
				mycode -> func[mycode -> countfunc - 1] -> name);
				exit(1);
			}
		}

		if(strcmp(tree -> token, "&&") == 0 || strcmp(tree -> token, "||") == 0) {
			if(strcmp(exprtype(tree -> left, CODEscope), exprtype(tree -> right, CODEscope)) == 0
			&& strcmp(exprtype(tree -> right, CODEscope), "BOOL") == 0)
			msg = "BOOL";
			else {
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",tree -> token,
				exprtype(tree -> left, CODEscope), exprtype(tree -> right, CODEscope),
				mycode -> func[mycode -> countfunc-1] -> name);
				exit(1);
			}
		}
		if(strcmp(tree -> token, "-") == 0 || strcmp(tree -> token, "+") == 0) {
			if ((strcmp(exprtype(tree -> left, CODEscope),"INT") == 0
			|| strcmp(exprtype(tree -> left, CODEscope),"REAL") == 0)
			&& (strcmp(exprtype(tree -> right, CODEscope),"INT") == 0
			|| strcmp(exprtype(tree -> right, CODEscope),"REAL") == 0)) 
				if (strcmp(exprtype(tree -> left, CODEscope), exprtype(tree -> right, CODEscope)) == 0
				&& strcmp(exprtype(tree -> left, CODEscope), "INT") == 0)
					msg="INT";
				else
					msg="REAL";
			if (strcmp(exprtype(tree -> right, CODEscope), "INT") == 0
			&& (strcmp(exprtype(tree -> left, CODEscope), "CHAR_PTR") == 0
			|| strcmp(exprtype(tree -> right, CODEscope), "INT_PTR") == 0
			|| strcmp(exprtype(tree -> right, CODEscope), "REAL_PTR") == 0))
				msg=exprtype(tree -> left,CODEscope);
			else if (strcmp(msg, "") == 0) {
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",
				tree -> token,exprtype(tree -> left, CODEscope),
				exprtype(tree -> right, CODEscope), mycode -> func[mycode -> countfunc-1] -> name);
				exit(1);
			}
		}
		if(strcmp(tree -> token,"*") == 0 || strcmp(tree -> token,"/") == 0) {
			if((strcmp(exprtype(tree -> left, CODEscope),"INT") == 0
			|| strcmp(exprtype(tree -> left, CODEscope),"REAL") == 0)
			&& (strcmp(exprtype(tree -> right, CODEscope),"INT") == 0
			|| strcmp(exprtype(tree -> right, CODEscope),"REAL") == 0)) 
				if (strcmp(exprtype(tree -> left, CODEscope), exprtype(tree -> right, CODEscope)) == 0
				&& strcmp(exprtype(tree -> left, CODEscope), "INT") == 0)
					msg="INT";
				else
					msg="REAL";
			else {
				printf("ERORR, you cant put %s between %s and %s\n",
				tree -> token, exprtype(tree -> left, CODEscope),
				exprtype(tree -> right, CODEscope));
				exit(1);
			}
		}
		if(strcmp(tree -> token, "&") == 0) {
			if(strcmp(tree -> left -> token,"(") == 0)
				msg = exprtype(tree -> left -> left, CODEscope);
			else
				msg = exprtype(tree -> left, CODEscope);
			if(strcmp(msg,"CHAR") == 0)
				msg="CHAR_PTR";
			else if(strcmp(msg,"INT") == 0)
				msg="INT_PTR";
			else if(strcmp(msg,"REAL") == 0)
				msg = "REAL_PTR";
			else {
				printf("ERORR, you cant do %s on %s \n",tree -> token,msg);
				exit(1);
			}
		}
		if(strcmp(tree -> token, "^") == 0) {
			if(strcmp(tree -> left -> token, "(") == 0)
				msg = exprtype(tree -> left -> left, CODEscope);
			else
				msg = exprtype(tree -> left, CODEscope);
			if(strcmp(msg, "CHAR_PTR") == 0)
				msg = "CHAR";
			else if(strcmp(msg, "INT_PTR") == 0)
				msg = "INT";
			else if(strcmp(msg,"REAL_PTR") == 0)
				msg = "REAL";
			else {
				printf("ERORR, you cant do %s on %s \n",tree -> token, msg);
				exit(1);
			}
		}
		if (strcmp(tree -> token, "(") == 0)
			msg = exprtype(tree -> left, CODEscope);
		if (strcmp(tree -> token, "Call func") == 0)
			msg = findfunc(tree, CODEscope);
	}
	if(strcmp(msg, "") == 0)
		msg = findvar(tree, CODEscope);
	return msg;
}
void push(code* from,char* name) {
	code * point;
	if(mycode == NULL)
		mycode = mkcode(name);
	else {
	point = mycode;
	while(point -> nextLVL != NULL)
		point=point -> nextLVL;
	point -> nextLVL = mkcode(name);
	point -> nextLVL -> beforeLVL = from;
	}
}
code* mkcode(char* name) {	
	code *newlvl = (code*)malloc(sizeof(code));
	newlvl -> place=++scope;
	newlvl -> name=name;
	newlvl -> var=NULL;
	newlvl -> countvar=0;
	newlvl -> func=NULL;
	newlvl -> countfunc=0;
	newlvl -> nextLVL=NULL;
	newlvl -> beforeLVL=NULL;
	return newlvl;
}

void addvar(Arguments * args,int countvars,int isArg,code * CODEscope){
	if(countvars == 0)
	return;
	Varaiable* temp;
	code * codey=CODEscope;

	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
	if(i != j && strcmp(args[j].name,args[i].name) == 0 )
	{
		printf("sorry you can't some vars %s in one declear",args[i].name);
		code * t=codey -> beforeLVL;
		while(t -> beforeLVL != NULL && t -> beforeLVL -> countfunc == 0)
			t=t -> beforeLVL;
		if(t -> func != NULL)
		printf(",in func %s\n",t -> func[t -> countfunc-1] -> name);
			else
		printf("\n");
		exit(1);
	}
	if(codey -> var == NULL)
	{ 
		codey -> var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	}
	else
	{
		temp=codey -> var;
		codey -> var=(Varaiable*) malloc(sizeof(Varaiable)*(codey -> countvar+countvars));
		for(int i=0;i<codey -> countvar;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(temp[i].name,args[j].name) == 0 )
				{
					printf("sorry you can't some var %s in some scope",temp[i].name);
					code * t=codey -> beforeLVL;
					while(t -> beforeLVL != NULL && t -> beforeLVL -> countfunc == 0)
						t=t -> beforeLVL;
					if(t -> func != NULL)
					printf(",in func %s\n",t -> func[t -> countfunc-1] -> name);
					else
					printf("\n");
					exit(1);
				}
			}
			codey -> var[i]=temp[i];	
		}
	}
	for(int j = 0; j < countvars; j++) {
		codey -> var[codey -> countvar].name=args[j].name;
		codey -> var[codey -> countvar].value=NULL;
		codey -> var[codey -> countvar].isArg=isArg;
		codey -> var[codey -> countvar].len=args[j].len;
		codey -> var[(codey -> countvar)++].type=args[j].type;
	}
	printf("L718 vars in scope %s \n",codey -> name);
	for(int i = 0; i < codey -> countvar; i++)
		printf("%s %s,", codey -> var[i].name, codey -> var[i].type);
	printf("\nend vars scope %d\n", codey -> place);
}

void addFunc(char * name,Arguments * args,node *returnType,int countArgs,code * CODEscope) {
	Function** temp;
	code * codey=CODEscope;
	for(int i=0;i<countArgs;i++)
		for(int j=0;j<countArgs;j++)
			if(i != j && strcmp(args[j].name,args[i].name) == 0 ) {
				printf("sorry you can't some Arguments %s in func %s\n",args[i].name,name);
				exit(1);
			}
	if(codey -> func == NULL) 
		codey -> func=(Function**) malloc(sizeof(Function*));
	else {
		temp=codey -> func;
		codey -> func=(Function**) malloc(sizeof(Function*)*(codey -> countfunc+1));
		for(int i=0;i<codey -> countfunc;i++) {
			if(strcmp(temp[i] -> name,name) == 0 ) {
				printf("sorry you can't some func %s in some scope \n",temp[i] -> name);
				exit(1);
			}
			codey -> func[i]=temp[i];
		}
	}
	codey -> func[codey -> countfunc]=(Function*) malloc(sizeof(Function));
	codey -> func[codey -> countfunc] -> name=name;
	codey -> func[codey -> countfunc] -> args=args;
	if(returnType == NULL)
		codey -> func[codey -> countfunc] -> returnType=NULL;
	else {
		if(strcmp(returnType -> token,"STRING") == 0) {
			printf("ERORR,return type func %s cant be string\n",name);
			exit(1);
		}
		codey -> func[codey -> countfunc] -> returnType=returnType -> token;
	}
	codey -> func[codey -> countfunc] -> countArgs = countArgs;
	codey -> func[codey -> countfunc] -> findreturn = false;
	++(codey -> countfunc); 

	printf("L772 start %s in scope %d\n", name, codey -> place);
	for(int i=0;i<countArgs;i++)
		printf("%s %s,", codey -> func[codey -> countfunc-1] -> args[i].name,codey -> func[codey -> countfunc-1] -> args[i].type);
	printf("end %s\n", name);
}

Arguments * mkArgs(node *tree, int *count){
	Arguments  *arr = NULL;
	Arguments ar[50];
	char* type;
	char* len;
	printf("\033[0;31m"); //Set the text to the color red
	printTree(tree,printlevel);
	printf("\033[0m"); //Resets the text to default color
	if(tree != NULL) {
		node* temp = tree;
		node* temp1 = tree;
		printf("I am the token %s\n",temp1 -> token);
		printf("------------------\n");
		printf("I am the token left left %s\n",temp1 -> left -> left -> token);
		printf("I am the token left right %s\n",temp1 -> left -> right -> token); 
		printf("------------------\n");
		printf("I am the token left left right %s\n",temp1 -> left -> left -> right -> token);
		printf("I am the token left left right right %s\n",temp1 -> left -> left -> right -> right -> token);
		printf("------------------\n");
		printf("I am the token left right %s\n",temp1 -> left -> right -> token);
		printf("I am the token left right left %s\n",temp1 -> left -> right -> left -> token);
		printf("I am the token left right left right %s\n",temp1 -> left -> right -> left -> right -> token);
		int ass = strcmp(temp -> token, "VAR");
		type = temp -> left -> token;
		temp1 = temp1 -> left;
		do {
			if(strcmp(temp -> token, "VAR") == 0) {
				printf("I am the ASS: %d\n", ass);
				temp = temp1 -> left;
				temp1 = temp1 -> right;
				if(strcmp(temp -> token, "(") == 0 || strcmp(temp -> token, "VAR") == 0) {
					type = temp -> right -> token;
					if(temp -> left -> left != NULL)
						len = temp -> left -> left -> left -> token;
					node * treee;
					treee = temp -> left ;
					do {
						ar[*count].name = treee -> token;
						ar[*count].type = type;
						ar[*count].len = len;
						(*count)++;
						if(treee -> left == NULL)
							treee = NULL;
						else
							treee = treee -> left -> left;
					} while(treee != NULL);
				}
			}
		} while(strcmp(temp1 -> token, "(") != 0 && strcmp(temp -> token, type) != 0);
		temp = temp1;
		if(strcmp(temp -> token, "(") == 0 || strcmp(temp -> token, "VAR") == 0) {
			type = temp -> left -> token;
			node * treee;
			if(strcmp(temp -> token, "VAR") == 0)
				treee = temp -> right;
			else
				treee=temp -> right -> left;
			if(temp -> left -> left != NULL)
				len=temp -> left -> left -> left -> token;
			do{
				ar[*count].name = treee -> token;
				ar[*count].type = type;
				ar[*count].len = len;
				(*count)++;
				if(treee -> left == NULL)
					treee = NULL;
				else
					treee = treee -> left -> left;
			} while(treee != NULL);
		}
		arr = (Arguments*)malloc(sizeof(Arguments) * (*count));
		for(int i = 0; i < *count; i++) {
			arr[i].name = ar[i].name;
			arr[i].type = ar[i].type;
			printf("%s %s,", arr[i].name, arr[i].type);
		}
		printf("\n");
	}
	return arr;
}

node *makeNode(char *token, node *left, node *right) {
    node *newnode = (node*)malloc(sizeof(node));
    char *newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr, token);
    newnode -> left = left;
    newnode -> right = right;
    newnode -> token = newstr;
    return newnode;
}

void printTree (node *tree, int tab){
    int nextTab = tab;
    if (strlen(tree -> token) > 0) {
        printTabs(tab);
        printf ("%s", tree -> token);
        if (tree -> left != NULL) {
            printf("\n");
        }
    }
    if (tree -> left) {
        if (strlen(tree -> token) == 0) 
            nextTab = tab - 1;
        printTree(tree -> left, nextTab + 1);
        if (strlen(tree -> token) > 0) 
            printTabs(tab);
    }
    if (strlen(tree -> token) > 0) 
        printf ("\n");
    if (tree -> right) 
        printTree (tree -> right, tab);
}

void printTabs(int numOfTabs) {
    int i;
    for (i = 0; i < numOfTabs; i++) 
        printf("\t");
}

int yyerror(char *e) {
	int yydebug = 1; 
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" , e, yylineno);
	fprintf(stderr, "does not accept '%s'\n", yytext);
	return 0;
}

code* lestcode(code * codey){
	code * CODEscope=codey;
	if(CODEscope != NULL)
	while(CODEscope -> nextLVL != NULL)
		CODEscope=CODEscope -> nextLVL;
	return CODEscope;
}

void syntaxMKscope(node *tree,code * CODEscope){
	if(strcmp(tree -> token, "=") == 0 ) {
		if(!(strcmp(exprtype(tree -> right,CODEscope),"NULL") == 0
		&& (strcmp(exprtype(tree -> left,CODEscope),"REAL_PTR") == 0
		||strcmp(exprtype(tree -> left,CODEscope),"INT_PTR") == 0
		||strcmp(exprtype(tree -> left,CODEscope),"CHAR_PTR") == 0)))
		if(strcmp(exprtype(tree -> left,CODEscope),exprtype(tree -> right,CODEscope)) != 0) {
			printf("ERORR, you can't do = between %s and %s in scope %s in func/proc %s\n",exprtype(tree -> left,CODEscope),exprtype(tree -> right,CODEscope),CODEscope -> name,mycode -> func[mycode -> countfunc-1] -> name);
			exit(1);
		}
	}
	else if(strcmp(tree -> token, "VAR") == 0) {
		int countvar = 0;
		Arguments *var = mkArgs(tree, &countvar);
		addvar(var, countvar, 0, CODEscope);
	}
	else if(strcmp(tree -> token, "IF") == 0) {
		if(strcmp(exprtype(tree -> left -> left,CODEscope),"BOOL") != 0) {
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}
		if(strcmp(tree -> right -> token,"{") != 0) {
			push(CODEscope,tree -> token);
			if (tree -> left) 
				syntaxMKscope(tree -> left,lestcode( CODEscope -> nextLVL));
	
			if (tree -> right)
				syntaxMKscope(tree -> right,lestcode( CODEscope -> nextLVL));
        	scope--;
			return;
		}	
	}
	else if(strcmp(tree -> token, "while") == 0) {
		if(strcmp(exprtype(tree -> left -> left,CODEscope),"BOOL") != 0) {
			printf("ERORR, in while expr most be type boolean\n");
			exit(1);
		}
		if(strcmp(tree -> right -> token,"{") != 0) {
			push(CODEscope,tree -> token);
			if (tree -> left) 
				syntaxMKscope(tree -> left,lestcode( CODEscope -> nextLVL));
			if (tree -> right)
				syntaxMKscope(tree -> right,lestcode( CODEscope -> nextLVL));
        	scope--;
			return;
		}
	}
	else if(strcmp(tree -> token, "for") == 0) {
	    if(strcmp(exprtype(tree -> left -> left -> right,CODEscope),"BOOL") != 0) {
			printf("ERORR, in for expr most be type boolean\n");
			exit(1);
		}
		syntaxMKscope(tree -> left -> left -> left,CODEscope);
		syntaxMKscope(tree -> left -> right -> left,CODEscope);
		if(strcmp(tree -> right -> token,"{") != 0) {
			push(CODEscope,tree -> token);
			if (tree -> left) syntaxMKscope(tree -> left,lestcode( CODEscope -> nextLVL));
			if (tree -> right) syntaxMKscope(tree -> right,lestcode( CODEscope -> nextLVL));
        	scope--;
			return;
		}
	}
	else if(strcmp(tree -> token, "FUNCTION") == 0 ) {
        int count=0;
		Arguments * arg = mkArgs(tree -> left -> right->left, &count);
		addFunc(tree -> left -> token, arg, tree -> left -> right -> right -> left, count, CODEscope);
		push(CODEscope,tree -> token);
		addvar(arg,count,1,lestcode(CODEscope));
		if (tree -> left) syntaxMKscope(tree -> left,lestcode( CODEscope -> nextLVL));
		if (tree -> right) syntaxMKscope(tree -> right,lestcode( CODEscope -> nextLVL));
		if(CODEscope -> func[CODEscope -> countfunc-1] -> findreturn == false) {
			printf("ERORR,in func %s not find return\n",tree -> left -> token);
			exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree -> token, "PROC") == 0) {
        int count=0;
		Arguments * arg=mkArgs(tree -> right -> left,&count);
		addFunc(tree -> left -> token,arg,NULL,count,CODEscope);
		push(CODEscope,tree -> token);
		addvar(arg,count,1,lestcode(CODEscope));
		if (tree -> left) 
			syntaxMKscope(tree -> left,lestcode( CODEscope -> nextLVL));
		if (tree -> right)
			syntaxMKscope(tree -> right,lestcode( CODEscope -> nextLVL));
			scope--;	
			return;
    }

	else if(strcmp(tree -> token, "Call func") == 0) {
		findfunc(tree,CODEscope);
		printf("(%s \n",tree -> token);
	}
	else if(strcmp(tree -> token, "CODE") == 0) {
		printTree(tree,printlevel);
		push(NULL,tree -> token);
		if (tree -> left) syntaxMKscope(tree -> left,mycode);
		if (tree -> right) syntaxMKscope(tree -> right,mycode);
		scope--;
		return;
	}
    else if(strcmp(tree -> token, "BODY") == 0) { }
	else if(strcmp(tree -> token, "ARGS") == 0) { }
    else if(strcmp(tree -> token, "Main") == 0) {
		if(flagMain == true) {
			printf("Main needs to be one anad only and not inside a func/proc\n");
			exit(1);
		}
		flagMain=true;
		addFunc(tree -> token,NULL,NULL,0,CODEscope);
		push(CODEscope,tree -> token);
		if (tree -> left) 
			syntaxMKscope(tree -> left,lestcode( CODEscope -> nextLVL));
		
		if (tree -> right)
			syntaxMKscope(tree -> right,lestcode( CODEscope -> nextLVL));
			scope--;
			return;        
    }       
	else if(strcmp(tree -> token, "IF-ELSE") == 0) {
		if(strcmp(exprtype(tree -> left -> left,CODEscope),"BOOL") != 0) {
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}
		if(strcmp(tree -> right -> left -> token,"{") != 0) {
			push(CODEscope,tree -> token);
			syntaxMKscope(tree -> right -> left,lestcode( CODEscope -> nextLVL));
			scope--;
			push(CODEscope,tree -> token);
			syntaxMKscope(tree -> right -> right -> left,lestcode( CODEscope -> nextLVL));
        	scope--;
			return;
		}	
	}
	else if(strcmp(tree -> token, "RET") == 0) {
		code * temp= CODEscope;
		int flag=true;
		while(strcmp(temp -> name,"FUNCTION") != 0&&strcmp(temp -> name,"PROC") != 0&&strcmp(temp -> name,"CODE") != 0) {
			temp=temp -> beforeLVL;
			flag=false;
		}
		if(flag == false) {
			if(strcmp(exprtype(tree -> left,CODEscope),temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> returnType))
			{
			printf("ERORR,return no some type in func %s \n",temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
			printf("%s ,%s %s\n",exprtype(tree -> left,CODEscope),temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> returnType,temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
			exit(1);
			}
		}
		else{
			if(temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> returnType != NULL) {
				if(0 == strcmp(exprtype(tree -> left,CODEscope),temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> returnType)){
					temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> findreturn=true;
				}
				else {
					printf("ERORR,return no some type in func %s \n",temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
					printf("%s ,%s %s\n",exprtype(tree -> left,CODEscope),temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> returnType,temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
					exit(1);
				}
			}
			else {
				printf("ERORR,return cant be in proc %s\n",temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
				exit(1);
			}  
		}  

	}
	else if(strcmp(tree -> token, "{") == 0) {
		push(CODEscope,tree -> token);
		if (tree -> left) 
			syntaxMKscope(tree -> left,lestcode( CODEscope -> nextLVL));
		if (tree -> right)
			syntaxMKscope(tree -> right,lestcode( CODEscope -> nextLVL));
			scope--;
			return;		
	}
	else if(strcmp(tree -> token, "}") == 0) { }
	else if(strcmp(tree -> token, "") == 0);
	else if(strcmp(tree -> token, "(") == 0) printf("(");
	else if(strcmp(tree -> token, ")") == 0) printf(")\n");
	else if(strcmp(tree -> token, ",") == 0) printf(",");
	else if(strcmp(tree -> token, ";") == 0) printf("\n");
	else if(strcmp(tree -> token, "&&") == 0 ||
			strcmp(tree -> token, "/") == 0 || 
			strcmp(tree -> token, "==") == 0 || 
			strcmp(tree -> token, ">") == 0 || 
			strcmp(tree -> token, ">=") == 0 || 
			strcmp(tree -> token, "<") == 0 || 
			strcmp(tree -> token, "<=") == 0 || 
			strcmp(tree -> token, "-") == 0 || 
			strcmp(tree -> token, "!") == 0 || 
			strcmp(tree -> token, "!=") == 0 || 
			strcmp(tree -> token, "||") == 0 || 
			strcmp(tree -> token, "+") == 0 || 
			strcmp(tree -> token, "*") == 0 || 
			strcmp(tree -> token, "&") == 0 || 
			strcmp(tree -> token, "^") == 0 || 
			strcmp(tree -> token, "|") == 0 || 
			strcmp(tree -> token, ",") == 0 ) printf("(%s",tree -> token);		
	else if(strcmp(tree -> token, "solovar") == 0 ) findvar(tree -> left,CODEscope);
	
	if (tree -> left) syntaxMKscope(tree -> left,CODEscope);
	
	if (tree -> right) syntaxMKscope(tree -> right,CODEscope);
}
