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
#line 1 "part2.y"

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
Arguments* makeArgs(node*, int *);
void addFunc(char* name, Arguments* args,node *returnType,int countArgs, code* CODEscope);
void addvar(Arguments* args,int,int,code * CODEscope);
code* makecode(char *);
node *makeNode(char *token, node *left, node *right);
void printTree(node *tree, int tab);
void printTabs(int numOfTabs);
int yyerror(char *err);
int yylex();
int typeFinder(char* token);
void push(code* from,char*);
code* mycode=NULL;
code* lestcode(code * codey);
static int scope=0;
void syntaxMKscope(node *tree,code * scope);
char* findfunc(node * tree,code * CODEscope);
char *findvar(node * tree,code * CODEscope);
Arguments * callfuncargs(code *,node *tree,int * count);

int printlevel=0;
int flagMain=false;

#line 140 "y.tab.c"

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
#line 71 "part2.y"

    char *string;
    struct node *node;

#line 292 "y.tab.c"

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
  YYSYMBOL_nested_statement = 73,          /* nested_statement  */
  YYSYMBOL_proc_nested_statement = 74,     /* proc_nested_statement  */
  YYSYMBOL_proc_statement = 75,            /* proc_statement  */
  YYSYMBOL_statement = 76,                 /* statement  */
  YYSYMBOL_func_statement = 77,            /* func_statement  */
  YYSYMBOL_func_arguments = 78,            /* func_arguments  */
  YYSYMBOL_assignment = 79,                /* assignment  */
  YYSYMBOL_multi_assign = 80,              /* multi_assign  */
  YYSYMBOL_if_statement = 81,              /* if_statement  */
  YYSYMBOL_proc_if_statement = 82,         /* proc_if_statement  */
  YYSYMBOL_while_statement = 83,           /* while_statement  */
  YYSYMBOL_proc_while_statement = 84,      /* proc_while_statement  */
  YYSYMBOL_do_statement = 85,              /* do_statement  */
  YYSYMBOL_proc_do_statement = 86,         /* proc_do_statement  */
  YYSYMBOL_for_statement = 87,             /* for_statement  */
  YYSYMBOL_proc_for_statement = 88,        /* proc_for_statement  */
  YYSYMBOL_block = 89,                     /* block  */
  YYSYMBOL_block_proc = 90,                /* block_proc  */
  YYSYMBOL_expression = 91,                /* expression  */
  YYSYMBOL_element_of_expression = 92,     /* element_of_expression  */
  YYSYMBOL_primitive_value = 93,           /* primitive_value  */
  YYSYMBOL_address_of = 94,                /* address_of  */
  YYSYMBOL_return_statement = 95,          /* return_statement  */
  YYSYMBOL_update = 96,                    /* update  */
  YYSYMBOL_unary_op = 97                   /* unary_op  */
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
#define YYLAST   1440

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  368

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
       0,   178,   178,   180,   182,   183,   184,   185,   186,   187,
     189,   191,   193,   195,   196,   197,   198,   199,   201,   202,
     203,   204,   205,   206,   207,   209,   210,   211,   212,   213,
     215,   216,   217,   218,   219,   220,   221,   223,   225,   226,
     227,   228,   230,   231,   232,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   244,   245,   246,   248,   249,   251,
     252,   253,   254,   255,   256,   257,   258,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   271,   272,   273,
     274,   276,   277,   278,   280,   281,   282,   283,   284,   285,
     286,   288,   289,   290,   292,   293,   295,   296,   298,   300,
     302,   304,   306,   308,   310,   311,   312,   313,   314,   315,
     316,   318,   319,   320,   321,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   341,   342,   343,   344,   346,   347,   348,   349,
     350,   351,   352,   353,   355,   356,   358,   359,   361,   362,
     363,   365,   366,   367
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
  "body", "body_proc", "declaration", "nested_statement",
  "proc_nested_statement", "proc_statement", "statement", "func_statement",
  "func_arguments", "assignment", "multi_assign", "if_statement",
  "proc_if_statement", "while_statement", "proc_while_statement",
  "do_statement", "proc_do_statement", "for_statement",
  "proc_for_statement", "block", "block_proc", "expression",
  "element_of_expression", "primitive_value", "address_of",
  "return_statement", "update", "unary_op", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-278)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-136)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,     6,    29,  -278,  -278,    28,    28,    28,   -13,    38,
    -278,  -278,  -278,  -278,    44,    18,    67,   115,   140,    98,
      90,   125,   116,   158,   454,  -278,   117,   106,   117,   454,
     122,   162,   127,   117,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,   121,  -278,   154,   454,  -278,   811,  -278,   117,   129,
      18,   141,   202,  -278,   111,   155,   207,   213,    59,   212,
    -278,   221,  -278,  -278,  -278,   232,   254,  1056,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,   976,   674,   255,    59,    59,
     243,   892,  -278,   892,   215,    26,  -278,  -278,  -278,  -278,
    -278,  1089,  -278,  -278,  -278,   976,  -278,   231,   811,   721,
     261,   264,    -6,  -278,   178,   976,   976,   131,    17,   253,
     269,   258,   310,   976,     2,   920,   976,    59,   976,   287,
      88,  -278,  1234,  -278,   850,   281,   277,  -278,  -278,  -278,
      50,  -278,   293,  -278,    59,  -278,   976,   976,   976,   976,
     976,   976,   976,   976,   976,   976,   976,   976,  -278,  1404,
     296,   301,   302,   304,   976,   300,   469,   306,   721,   336,
     721,   215,   180,  -278,  -278,  -278,  -278,  -278,  1103,  -278,
     311,   339,   948,   976,  -278,   111,  1251,  1268,    48,   316,
     454,    18,   325,  1285,   976,   976,    60,  -278,  1118,   326,
    1219,  -278,   171,   319,   338,  -278,  -278,   329,  -278,  -278,
    -278,   391,   345,   405,   332,   152,   223,   246,   110,  -278,
     190,   240,     7,  -278,   976,   976,   131,  1132,  1147,   369,
     346,   351,   358,   342,   533,  -278,   580,   336,   335,   362,
     183,  1161,  -278,    -1,   336,   359,  -278,  -278,  -278,  -278,
     976,    84,   374,  -278,   892,   892,   976,   377,   118,   976,
    -278,  1404,  1008,   976,   976,  -278,    46,   976,   387,   380,
    -278,  1302,  1319,   383,  -278,   394,   976,   976,   131,   392,
     627,   395,  -278,   336,   397,   398,   399,  -278,   309,   313,
    -278,  1022,    53,   431,  -278,  1176,    59,   396,  1336,  -278,
     406,  1039,   416,  -278,  -278,   245,   976,   721,   721,   976,
     976,  1353,  1370,   407,   415,   418,   419,   420,  -278,  -278,
    -278,   179,  -278,   892,   250,  -278,   454,   414,    87,  -278,
      88,  -278,  -278,  -278,  -278,   424,  -278,   462,  -278,  1190,
    1387,   766,   766,   976,   423,  -278,  -278,   111,  -278,    12,
     425,  -278,   428,  -278,  -278,   427,   721,   250,   435,  1205,
    -278,   448,   450,   131,   892,  -278,  -278,   442,  -278,   250,
    -278,  -278,  -278,  -278,   721,   443,  -278,   766
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     8,     5,     7,     0,     0,
       1,     9,     4,     6,     0,    17,     0,    24,    18,     0,
       0,     0,     0,    18,     0,    19,    24,     0,    24,     0,
       0,    21,    19,    24,    30,    31,    32,    33,    34,    35,
      36,    15,    20,     0,     0,    13,    53,    23,    24,    20,
      17,     0,     0,    14,     0,     0,     0,     0,    53,     0,
     141,     0,   152,   153,   151,     0,     0,    52,   142,   140,
     143,   138,   137,   136,   139,     0,     0,     0,    53,    53,
       0,    43,    44,    57,    61,    51,    62,    63,    64,    66,
      65,     0,   115,   132,   131,     0,    22,    16,    53,    53,
       0,     0,     0,    37,     0,     0,     0,     0,    52,     0,
      51,     0,     0,     0,   144,     0,    81,    53,     0,     0,
     135,   134,     0,   111,     0,     0,     0,    45,    46,    10,
     135,    42,     0,    58,    53,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,   129,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    41,
      53,    70,    51,    71,    72,    73,    75,    74,     0,    76,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,   135,    86,     0,     0,
      83,    50,     0,   144,     0,   116,   113,     0,   114,   133,
      49,   119,   130,   117,   121,   122,   124,   123,   127,   125,
     120,   126,   128,    12,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,     0,    61,
      51,     0,    11,    68,     0,    76,    40,    56,    67,    69,
       0,   135,     0,    27,     0,     0,     0,     0,     0,     0,
     118,    85,     0,    81,     0,    84,    78,    81,     0,     0,
     112,     0,     0,     0,   146,     0,     0,     0,     0,   104,
       0,     0,   109,     0,     0,    76,     0,   110,    59,    60,
      38,     0,     0,    96,    99,     0,    47,     0,     0,   145,
       0,     0,     0,    79,    82,     0,    81,    53,    53,     0,
       0,     0,     0,     0,   109,     0,   110,     0,   108,   106,
     107,     0,    25,     0,    93,    48,     0,     0,    78,    88,
       0,    80,    90,    89,    87,     0,    68,    94,    98,     0,
       0,    53,    53,     0,   108,   105,    29,     0,    97,     0,
      91,   150,     0,   101,    77,     0,    53,    93,     0,     0,
      28,     0,     0,    93,     0,    77,    95,     0,   100,    93,
     149,   148,    92,   103,    53,     0,   102,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,  -278,   303,  -278,   260,  -278,   -37,    78,  -172,
     -19,  -278,  -278,   404,   -40,   -98,   -74,  -230,  -277,   -35,
    -231,   -46,   150,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -139,   -57,   199,  -278,  -278,  -278,  -135,  -217,  -278
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,     5,    78,     7,    19,    20,   103,
      52,    79,   157,    80,   326,   227,    82,    83,   160,   121,
     189,   132,   341,   163,    86,   164,    87,   165,    88,   166,
      89,   167,    90,    91,    92,    93,    94,   169,   342,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   159,   125,   243,   112,    41,    81,   131,   104,   133,
      45,    84,   110,    97,   283,   284,   219,   -55,   109,   172,
     327,   328,   290,   235,   236,    53,   294,   184,     8,    10,
      85,   137,   110,   110,    17,    14,   124,   172,   127,   128,
     144,    84,   172,   351,     9,     1,    84,   352,    84,   173,
     197,   -55,    85,   162,   327,   328,    18,   185,    81,   158,
     234,   179,   237,    84,   161,   325,    54,   118,   -24,   356,
     117,   110,   118,   172,    58,   115,    59,   191,   295,   134,
     135,   292,   228,   338,   219,   194,    15,   366,   110,    84,
     366,   275,   276,    16,   200,    24,   101,   108,   116,   280,
     293,   283,   284,   118,    42,   118,    44,   312,   253,   194,
     230,    49,   162,   194,   162,   254,   226,    21,   233,   217,
     233,   229,   292,   161,   363,   161,    96,   100,   273,   104,
     357,    22,   116,    22,   137,   275,   116,   363,   307,   254,
      29,   344,   365,   144,   248,    30,   147,    27,   101,   102,
     271,    28,   274,    23,    31,    18,    43,    34,    35,    36,
      37,   247,    38,    39,    40,   350,   112,   287,   101,   178,
     263,    28,   273,    46,    51,    50,   137,   -23,   230,   -22,
     230,   141,   142,   143,   270,   144,   233,   146,   147,   229,
      25,   229,    98,    26,   136,   137,   305,   138,   139,   140,
     141,   142,   143,   105,   144,   145,   146,   147,    32,    84,
      84,    33,    47,   136,   137,    48,   138,   139,   140,   141,
     142,   143,   303,   144,   230,   146,   147,   258,   174,   336,
     233,   175,   337,   134,   238,   229,   134,   278,  -134,  -134,
     110,  -134,  -134,  -134,  -134,  -134,   315,   137,  -134,  -134,
     111,   162,   162,    99,   143,   106,   144,   321,   146,   147,
       6,   107,   161,   161,   137,     6,     6,     6,   340,  -134,
     137,   143,    76,   144,   122,   141,   147,   143,    84,   144,
     113,   146,   147,   322,    28,   230,   230,   101,   339,   323,
     324,   104,   114,   126,   149,   129,   229,   229,   168,   170,
     162,   340,   171,   180,   176,   177,   181,   340,    11,    12,
      13,   161,   183,   340,   188,   190,   -67,   192,   162,    84,
     -69,   230,   134,   182,   -67,   193,   -67,   -67,   -69,   161,
     -69,   -69,   229,   198,   199,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   135,   213,   214,
     215,   156,   216,   218,   154,   231,   137,   168,   232,   168,
     140,   141,   142,   143,   184,   144,   240,   146,   147,   -70,
     246,   188,   242,   249,   185,   256,   259,   -70,   144,   -70,
     -70,   260,   265,   251,   252,  -134,  -134,   277,  -134,  -134,
    -134,  -134,  -134,   224,   266,  -134,  -134,   136,   137,   267,
     138,   139,   140,   141,   142,   143,   268,   144,   145,   146,
     147,   -39,   295,   261,   262,   137,  -134,   138,   139,   140,
     141,   142,   143,   231,   144,   231,   146,   147,   296,   137,
     282,   286,   139,   140,   141,   142,   143,   299,   144,   281,
     146,   147,   300,   313,  -111,   285,   316,   306,   288,   308,
     309,   310,   190,   291,   320,   318,   190,    34,    35,    36,
      37,   333,    38,    39,    40,   301,   302,  -113,   343,   231,
     334,  -114,   335,   345,   346,  -112,    54,   354,   353,   360,
     220,   355,   221,   222,    58,   361,    59,   154,    60,   358,
     223,   364,   367,     0,     0,   190,   168,   168,   329,   330,
      62,    63,   150,   362,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,    74,     0,    75,     0,     0,
     224,   225,     0,     0,     0,     0,    77,     0,     0,     0,
     231,   231,   349,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,   220,   168,   221,   222,    58,     0,
      59,   154,    60,     0,   223,     0,     0,     0,     0,     0,
       0,     0,     0,   168,    62,    63,   231,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    74,
       0,    75,     0,     0,   224,   269,     0,    54,     0,     0,
      77,   220,     0,   221,   222,    58,     0,    59,   154,    60,
       0,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,     0,    75,     0,
       0,   224,   272,     0,    54,     0,     0,    77,   220,     0,
     221,   222,    58,     0,    59,   154,    60,     0,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
       0,     0,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,    74,     0,    75,     0,     0,   224,   304,
       0,    54,     0,     0,    77,    55,     0,    56,    57,    58,
       0,    59,     0,    60,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,     0,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,     0,    75,     0,     0,    76,   123,     0,    54,     0,
       0,    77,   151,     0,   152,   153,    58,     0,    59,   154,
      60,     0,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    63,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,    74,     0,    75,
       0,     0,   156,    54,     0,     0,     0,   220,    77,   221,
     222,    58,     0,    59,   154,    60,     0,   223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,     0,    75,     0,     0,   224,    54,     0,
       0,     0,    55,    77,    56,    57,    58,     0,    59,     0,
      60,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    63,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,    74,     0,    75,
       0,    55,    76,    56,    57,     0,     0,     0,    77,    60,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,     0,     0,    64,    65,    66,   130,    68,
      69,    70,    71,    72,    73,     0,    74,     0,    75,     0,
       0,    76,   196,    55,     0,    56,    57,    77,     0,     0,
       0,    60,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,    63,     0,     0,    64,    65,    66,
     130,    68,    69,    70,    71,    72,    73,     0,    74,    60,
      75,     0,     0,    76,     0,     0,     0,     0,     0,    77,
       0,    62,    63,     0,     0,    64,    65,   119,   186,    68,
      69,    70,    71,    72,    73,   187,    74,    60,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,    62,
      63,     0,     0,    64,    65,   119,   241,    68,    69,    70,
      71,    72,    73,   187,    74,    60,    75,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,    62,    63,     0,
       0,    64,    65,   119,   120,    68,    69,    70,    71,    72,
      73,     0,    74,     0,    75,     0,     0,     0,     0,     0,
       0,   136,   137,    77,   138,   139,   140,   141,   142,   143,
       0,   144,   145,   146,   147,   136,   137,     0,   138,   139,
     140,   141,   142,   143,     0,   144,   145,   146,   147,     0,
       0,     0,   136,   137,   289,   138,   139,   140,   141,   142,
     143,     0,   144,   145,   146,   147,     0,     0,   311,  -135,
    -135,   115,  -135,  -135,  -135,  -135,  -135,     0,     0,  -135,
    -135,     0,     0,     0,     0,   319,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,     0,   117,
    -135,   118,   136,   137,     0,   138,   139,   140,   141,   142,
     143,     0,   144,   145,   146,   147,   136,   137,     0,   138,
     139,   140,   141,   142,   143,     0,   144,   145,   146,   147,
       0,   136,   137,   148,   138,   139,   140,   141,   142,   143,
       0,   144,   145,   146,   147,  -134,  -134,   239,  -134,  -134,
    -134,  -134,  -134,  -134,     0,  -134,  -134,  -134,  -134,     0,
     136,   137,   255,   138,   139,   140,   141,   142,   143,     0,
     144,   145,   146,   147,   136,   137,  -134,   138,   139,   140,
     141,   142,   143,     0,   144,   145,   146,   147,     0,   136,
     137,   264,   138,   139,   140,   141,   142,   143,     0,   144,
     145,   146,   147,   136,   137,   279,   138,   139,   140,   141,
     142,   143,     0,   144,   145,   146,   147,     0,   136,   137,
     314,   138,   139,   140,   141,   142,   143,     0,   144,   145,
     146,   147,   136,   137,   347,   138,   139,   140,   141,   142,
     143,     0,   144,   145,   146,   147,     0,   136,   137,   359,
     138,   139,   140,   141,   142,   143,     0,   144,   145,   146,
     147,     0,   257,     0,   136,   137,     0,   138,   139,   140,
     141,   142,   143,   195,   144,   145,   146,   147,     0,     0,
       0,   136,   137,     0,   138,   139,   140,   141,   142,   143,
     244,   144,   145,   146,   147,     0,     0,     0,   136,   137,
       0,   138,   139,   140,   141,   142,   143,   245,   144,   145,
     146,   147,     0,     0,     0,   136,   137,     0,   138,   139,
     140,   141,   142,   143,   250,   144,   145,   146,   147,     0,
       0,     0,   136,   137,     0,   138,   139,   140,   141,   142,
     143,   297,   144,   145,   146,   147,     0,     0,     0,   136,
     137,     0,   138,   139,   140,   141,   142,   143,   298,   144,
     145,   146,   147,     0,     0,     0,   136,   137,     0,   138,
     139,   140,   141,   142,   143,   317,   144,   145,   146,   147,
       0,     0,     0,   136,   137,     0,   138,   139,   140,   141,
     142,   143,   331,   144,   145,   146,   147,     0,     0,     0,
     136,   137,     0,   138,   139,   140,   141,   142,   143,   332,
     144,   145,   146,   147,     0,     0,     0,   136,   137,     0,
     138,   139,   140,   141,   142,   143,   348,   144,   145,   146,
     147
};

static const yytype_int16 yycheck[] =
{
      46,    99,    76,   175,    61,    24,    46,    81,    54,    83,
      29,    46,    58,    50,   244,   245,   155,    18,    58,    25,
     297,   298,   253,   158,   159,    44,   257,    25,    22,     0,
      76,    24,    78,    79,    16,    48,    76,    25,    78,    79,
      33,    76,    25,    31,    38,    17,    81,    35,    83,    55,
     124,    52,    98,    99,   331,   332,    38,    55,    98,    99,
     158,   107,   160,    98,    99,   296,     7,    55,    50,   346,
      53,   117,    55,    25,    15,    25,    17,   117,    25,    53,
      54,    35,   156,   313,   223,    25,    48,   364,   134,   124,
     367,   226,   227,    49,   134,    17,    37,    38,    48,   234,
      54,   331,   332,    55,    26,    55,    28,    54,    48,    25,
     156,    33,   158,    25,   160,    55,   156,    50,   158,   154,
     160,   156,    35,   158,   354,   160,    48,    16,   226,   175,
     347,    16,    48,    16,    24,   270,    48,   367,   273,    55,
      50,    54,   359,    33,   181,    20,    36,    49,    37,    38,
     224,    53,   226,    38,    38,    38,    50,     3,     4,     5,
       6,   180,     8,     9,    10,   337,   223,    49,    37,    38,
     216,    53,   270,    51,    20,    54,    24,    50,   224,    50,
     226,    29,    30,    31,   224,    33,   226,    35,    36,   224,
      50,   226,    51,    53,    23,    24,   270,    26,    27,    28,
      29,    30,    31,    48,    33,    34,    35,    36,    50,   244,
     245,    53,    50,    23,    24,    53,    26,    27,    28,    29,
      30,    31,   268,    33,   270,    35,    36,    56,    50,    50,
     270,    53,    53,    53,    54,   270,    53,    54,    23,    24,
     286,    26,    27,    28,    29,    30,   286,    24,    33,    34,
      38,   297,   298,    51,    31,    48,    33,   292,    35,    36,
       0,    48,   297,   298,    24,     5,     6,     7,   314,    54,
      24,    31,    51,    33,    75,    29,    36,    31,   313,    33,
      48,    35,    36,    38,    53,   331,   332,    37,    38,    44,
      45,   337,    38,    38,    95,    52,   331,   332,    99,    38,
     346,   347,    38,    50,   105,   106,    48,   353,     5,     6,
       7,   346,   113,   359,   115,   116,     7,   118,   364,   354,
       7,   367,    53,    13,    15,    38,    17,    18,    15,   364,
      17,    18,   367,    52,    57,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    54,    52,    48,
      48,    51,    48,   154,    18,   156,    24,   158,    52,   160,
      28,    29,    30,    31,    25,    33,    55,    35,    36,     7,
      54,   172,   173,    48,    55,    49,    38,    15,    33,    17,
      18,    52,    13,   184,   185,    23,    24,    52,    26,    27,
      28,    29,    30,    51,    48,    33,    34,    23,    24,    48,
      26,    27,    28,    29,    30,    31,    48,    33,    34,    35,
      36,    52,    25,   214,   215,    24,    54,    26,    27,    28,
      29,    30,    31,   224,    33,   226,    35,    36,    48,    24,
      56,    54,    27,    28,    29,    30,    31,    54,    33,   240,
      35,    36,    48,    12,    52,   246,    50,    52,   249,    52,
      52,    52,   253,   254,    38,    49,   257,     3,     4,     5,
       6,    54,     8,     9,    10,   266,   267,    52,    54,   270,
      52,    52,    52,    49,    12,    52,     7,    49,    53,    31,
      11,    54,    13,    14,    15,    35,    17,    18,    19,    54,
      21,    49,    49,    -1,    -1,   296,   297,   298,   299,   300,
      31,    32,    98,   353,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    46,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
     331,   332,   333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    -1,    -1,    11,   346,    13,    14,    15,    -1,
      17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   364,    31,    32,   367,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    46,
      -1,    48,    -1,    -1,    51,    52,    -1,     7,    -1,    -1,
      57,    11,    -1,    13,    14,    15,    -1,    17,    18,    19,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    -1,    48,    -1,
      -1,    51,    52,    -1,     7,    -1,    -1,    57,    11,    -1,
      13,    14,    15,    -1,    17,    18,    19,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    -1,    48,    -1,    -1,    51,    52,
      -1,     7,    -1,    -1,    57,    11,    -1,    13,    14,    15,
      -1,    17,    -1,    19,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    -1,    48,    -1,    -1,    51,    52,    -1,     7,    -1,
      -1,    57,    11,    -1,    13,    14,    15,    -1,    17,    18,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    46,    -1,    48,
      -1,    -1,    51,     7,    -1,    -1,    -1,    11,    57,    13,
      14,    15,    -1,    17,    18,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    -1,    48,    -1,    -1,    51,     7,    -1,
      -1,    -1,    11,    57,    13,    14,    15,    -1,    17,    -1,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    46,    -1,    48,
      -1,    11,    51,    13,    14,    -1,    -1,    -1,    57,    19,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    -1,    48,    -1,
      -1,    51,    52,    11,    -1,    13,    14,    57,    -1,    -1,
      -1,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    19,
      48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    19,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    31,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    19,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    57,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    23,    24,    56,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    -1,    -1,    56,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    53,
      54,    55,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      -1,    23,    24,    54,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    23,    24,    54,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    -1,
      23,    24,    54,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    23,    24,    54,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    -1,    23,
      24,    54,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    23,    24,    54,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    -1,    23,    24,
      54,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    23,    24,    54,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    -1,    23,    24,    54,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    -1,    53,    -1,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    49,    33,    34,    35,    36,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      49,    33,    34,    35,    36,    -1,    -1,    -1,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    49,    33,    34,
      35,    36,    -1,    -1,    -1,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    49,    33,    34,    35,    36,    -1,
      -1,    -1,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    49,    33,    34,    35,    36,    -1,    -1,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    49,    33,
      34,    35,    36,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    49,    33,    34,    35,    36,
      -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    49,    33,    34,    35,    36,    -1,    -1,    -1,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    49,
      33,    34,    35,    36,    -1,    -1,    -1,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    49,    33,    34,    35,
      36
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
      19,    21,    31,    32,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    46,    48,    51,    57,    63,    69,
      71,    72,    74,    75,    77,    79,    82,    84,    86,    88,
      90,    91,    92,    93,    94,    97,    66,    65,    51,    51,
      16,    37,    38,    67,    79,    48,    48,    48,    38,    72,
      79,    38,    90,    48,    38,    25,    48,    53,    55,    37,
      38,    77,    91,    52,    72,    74,    38,    72,    72,    52,
      38,    74,    79,    74,    53,    54,    23,    24,    26,    27,
      28,    29,    30,    31,    33,    34,    35,    36,    54,    91,
      71,    11,    13,    14,    18,    21,    51,    70,    72,    73,
      76,    77,    79,    81,    83,    85,    87,    89,    91,    95,
      38,    38,    25,    55,    50,    53,    91,    91,    38,    79,
      50,    48,    13,    91,    25,    55,    38,    45,    91,    78,
      91,    72,    91,    38,    25,    49,    52,    74,    52,    57,
      72,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    52,    48,    48,    48,    77,    91,    89,
      11,    13,    14,    21,    51,    52,    72,    73,    74,    77,
      79,    91,    52,    72,    73,    95,    95,    73,    54,    54,
      55,    38,    91,    67,    49,    49,    54,    68,    65,    48,
      49,    91,    91,    48,    55,    54,    49,    53,    56,    38,
      52,    91,    91,    79,    54,    13,    48,    48,    48,    52,
      72,    74,    52,    73,    74,    95,    95,    52,    54,    54,
      95,    91,    56,    75,    75,    91,    54,    49,    91,    56,
      78,    91,    35,    54,    78,    25,    48,    49,    49,    54,
      48,    91,    91,    79,    52,    74,    52,    95,    52,    52,
      52,    56,    54,    12,    54,    72,    50,    49,    49,    56,
      38,    77,    38,    44,    45,    78,    72,    76,    76,    91,
      91,    49,    49,    54,    52,    52,    50,    53,    75,    38,
      79,    80,    96,    54,    54,    49,    12,    54,    49,    91,
      67,    31,    35,    53,    49,    54,    76,    96,    54,    54,
      31,    35,    80,    75,    49,    96,    76,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    61,    61,    61,    61,    61,    61,
      62,    63,    64,    65,    65,    65,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    69,    70,    70,
      70,    70,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    77,
      77,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    81,    81,    82,    82,    83,    84,
      85,    86,    87,    88,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    97,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     1,     2,
       9,    10,    10,     3,     4,     3,     5,     0,     1,     2,
       3,     2,     4,     3,     0,     5,     2,     3,     7,     6,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       2,     1,     2,     1,     1,     2,     2,     5,     6,     3,
       3,     1,     1,     0,     1,     1,     2,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     7,     4,     5,
       6,     0,     3,     1,     4,     4,     3,     6,     6,     6,
       6,     1,     3,     0,     5,     7,     5,     7,     5,     5,
       7,     7,     9,     9,     2,     5,     4,     4,     4,     3,
       3,     2,     4,     3,     3,     1,     3,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     3,     2,     3,     3,
       1,     1,     1,     1
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
#line 178 "part2.y"
               { syntaxMKscope((yyvsp[0].node),mycode); }
#line 1821 "y.tab.c"
    break;

  case 3: /* initial: code  */
#line 180 "part2.y"
              { (yyval.node) = makeNode("CODE", (yyvsp[0].node), NULL);}
#line 1827 "y.tab.c"
    break;

  case 4: /* code: function code  */
#line 182 "part2.y"
                    { (yyval.node) = makeNode("FUNCTION", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1833 "y.tab.c"
    break;

  case 5: /* code: function  */
#line 183 "part2.y"
               { (yyval.node) = makeNode("FUNCTION", (yyvsp[0].node), NULL); }
#line 1839 "y.tab.c"
    break;

  case 6: /* code: procedure code  */
#line 184 "part2.y"
                    { (yyval.node) = makeNode("PROC", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1845 "y.tab.c"
    break;

  case 7: /* code: procedure  */
#line 185 "part2.y"
                { (yyval.node) = makeNode("PROC", (yyvsp[0].node), NULL); }
#line 1851 "y.tab.c"
    break;

  case 8: /* code: main  */
#line 186 "part2.y"
               { (yyval.node) = makeNode("Main", (yyvsp[0].node), NULL); }
#line 1857 "y.tab.c"
    break;

  case 9: /* code: main code  */
#line 187 "part2.y"
                    { (yyval.node) = makeNode("Main", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1863 "y.tab.c"
    break;

  case 10: /* main: FUNC MAIN '(' ')' ':' VOID '{' body_proc '}'  */
#line 189 "part2.y"
                                                   {(yyval.node) = makeNode("ARGS NONE",NULL, makeNode("RET", makeNode("VOID", NULL, NULL), (yyvsp[-1].node))); }
#line 1869 "y.tab.c"
    break;

  case 11: /* function: FUNC ID '(' args ')' ':' type '{' body '}'  */
#line 191 "part2.y"
                                                     {(yyval.node) = makeNode((yyvsp[-8].string), NULL, makeNode("ARGS", makeNode("VAR", (yyvsp[-6].node), NULL), makeNode("RET", makeNode((yyvsp[-3].string), NULL, NULL), (yyvsp[-1].node)))); }
#line 1875 "y.tab.c"
    break;

  case 12: /* procedure: FUNC ID '(' args ')' ':' VOID '{' body_proc '}'  */
#line 193 "part2.y"
                                                           {(yyval.node) = makeNode((yyvsp[-8].string),NULL, makeNode("ARGS", (yyvsp[-6].node),makeNode("RET", makeNode("VOID",NULL,NULL),(yyvsp[-1].node)))); }
#line 1881 "y.tab.c"
    break;

  case 13: /* args: args_Id ':' type  */
#line 195 "part2.y"
                       { (yyval.node) = makeNode((yyvsp[0].string), (yyvsp[-2].node), NULL); }
#line 1887 "y.tab.c"
    break;

  case 14: /* args: args ',' args_Id type  */
#line 196 "part2.y"
                            { (yyval.node) = makeNode((yyvsp[0].string), (yyvsp[-1].node), (yyvsp[-3].node)); }
#line 1893 "y.tab.c"
    break;

  case 15: /* args: FUNCARGS args_Id type  */
#line 197 "part2.y"
                            { (yyval.node) = makeNode((yyvsp[0].string), (yyvsp[-1].node), NULL); }
#line 1899 "y.tab.c"
    break;

  case 16: /* args: FUNCARGS args_Id type ';' args  */
#line 198 "part2.y"
                                     { (yyval.node) = makeNode((yyvsp[-2].string), (yyvsp[-3].node), (yyvsp[0].node)); }
#line 1905 "y.tab.c"
    break;

  case 17: /* args: %empty  */
#line 199 "part2.y"
      { (yyval.node) = NULL; }
#line 1911 "y.tab.c"
    break;

  case 18: /* args_Id: ID  */
#line 201 "part2.y"
            { (yyval.node) = makeNode((yyvsp[0].string), NULL, NULL); }
#line 1917 "y.tab.c"
    break;

  case 19: /* args_Id: ID ':'  */
#line 202 "part2.y"
                { (yyval.node) = makeNode((yyvsp[-1].string), NULL,NULL); }
#line 1923 "y.tab.c"
    break;

  case 20: /* args_Id: ID ',' args_Id  */
#line 203 "part2.y"
                        { (yyval.node) = makeNode((yyvsp[-2].string), NULL, (yyvsp[0].node)); }
#line 1929 "y.tab.c"
    break;

  case 21: /* args_Id: FUNCARGS ID  */
#line 204 "part2.y"
                     { (yyval.node) = makeNode((yyvsp[0].string), NULL, NULL); }
#line 1935 "y.tab.c"
    break;

  case 22: /* args_Id: FUNCARGS ID ',' args_Id  */
#line 205 "part2.y"
                                 { (yyval.node) = makeNode((yyvsp[-2].string), NULL, (yyvsp[0].node)); }
#line 1941 "y.tab.c"
    break;

  case 23: /* args_Id: FUNCARGS ID ':'  */
#line 206 "part2.y"
                         { (yyval.node) = makeNode((yyvsp[-1].string), NULL, NULL); (yyval.node) -> left = makeNode((yyvsp[-1].string), NULL, NULL); }
#line 1947 "y.tab.c"
    break;

  case 24: /* args_Id: %empty  */
#line 207 "part2.y"
         { (yyval.node) = NULL; }
#line 1953 "y.tab.c"
    break;

  case 25: /* string_Id: ID '[' expression ']' ';'  */
#line 209 "part2.y"
                                     { (yyval.node) = makeNode((yyvsp[-4].string), makeNode("[]", NULL,(yyvsp[-2].node)), NULL); }
#line 1959 "y.tab.c"
    break;

  case 26: /* string_Id: assignment ':'  */
#line 210 "part2.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1965 "y.tab.c"
    break;

  case 27: /* string_Id: assignment ',' string_Id  */
#line 211 "part2.y"
                                    { (yyvsp[-2].node) -> right = (yyvsp[0].node);  (yyval.node) = (yyvsp[-2].node); }
#line 1971 "y.tab.c"
    break;

  case 28: /* string_Id: FUNCARGS ID '[' expression ']' ',' string_Id  */
#line 212 "part2.y"
                                                         { (yyval.node) = makeNode((yyvsp[-5].string), makeNode("[]", NULL,(yyvsp[-3].node)), (yyvsp[0].node)); }
#line 1977 "y.tab.c"
    break;

  case 29: /* string_Id: FUNCARGS ID '[' expression ']' ':'  */
#line 213 "part2.y"
                                              {(yyval.node) = makeNode((yyvsp[-4].string), makeNode("[]", NULL,(yyvsp[-2].node)), NULL); }
#line 1983 "y.tab.c"
    break;

  case 30: /* type: BOOL  */
#line 215 "part2.y"
           { (yyval.string) = "BOOL"; }
#line 1989 "y.tab.c"
    break;

  case 31: /* type: CHAR  */
#line 216 "part2.y"
           { (yyval.string) = "CHAR"; }
#line 1995 "y.tab.c"
    break;

  case 32: /* type: INT  */
#line 217 "part2.y"
          { (yyval.string) = "INT"; }
#line 2001 "y.tab.c"
    break;

  case 33: /* type: REAL  */
#line 218 "part2.y"
           { (yyval.string) = "REAL"; }
#line 2007 "y.tab.c"
    break;

  case 34: /* type: INTP  */
#line 219 "part2.y"
           { (yyval.string) = "INT_PTR"; }
#line 2013 "y.tab.c"
    break;

  case 35: /* type: CHARP  */
#line 220 "part2.y"
            { (yyval.string) = "CHAR_PTR"; }
#line 2019 "y.tab.c"
    break;

  case 36: /* type: REALP  */
#line 221 "part2.y"
            { (yyval.string) = "REAL_PTR"; }
#line 2025 "y.tab.c"
    break;

  case 37: /* string_type: STRING string_Id  */
#line 223 "part2.y"
                              { (yyval.node) =(yyvsp[0].node); }
#line 2031 "y.tab.c"
    break;

  case 38: /* body: declaration nested_statement return_statement  */
#line 225 "part2.y"
                                                    { (yyval.node) = makeNode("BODY", makeNode("", (yyvsp[-2].node), (yyvsp[-1].node)),(yyvsp[0].node)); }
#line 2037 "y.tab.c"
    break;

  case 39: /* body: declaration return_statement  */
#line 226 "part2.y"
                                   {(yyval.node) = makeNode("BODY",(yyvsp[-1].node), (yyvsp[0].node)); }
#line 2043 "y.tab.c"
    break;

  case 40: /* body: nested_statement return_statement  */
#line 227 "part2.y"
                                        { (yyval.node) = makeNode("BODY", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2049 "y.tab.c"
    break;

  case 41: /* body: nested_statement  */
#line 228 "part2.y"
                       { (yyval.node) = makeNode("BODY", (yyvsp[0].node), NULL); }
#line 2055 "y.tab.c"
    break;

  case 42: /* body_proc: declaration proc_nested_statement  */
#line 230 "part2.y"
                                             { (yyval.node) = makeNode("BODY", makeNode("", (yyvsp[-1].node), (yyvsp[0].node)),NULL); }
#line 2061 "y.tab.c"
    break;

  case 43: /* body_proc: declaration  */
#line 231 "part2.y"
                       {(yyval.node) = makeNode("BODY", (yyvsp[0].node), NULL); }
#line 2067 "y.tab.c"
    break;

  case 44: /* body_proc: proc_nested_statement  */
#line 232 "part2.y"
                                 { (yyval.node) = makeNode("BODY", (yyvsp[0].node), NULL); }
#line 2073 "y.tab.c"
    break;

  case 45: /* declaration: function declaration  */
#line 234 "part2.y"
                                  { (yyval.node) = makeNode("FUNCTION", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2079 "y.tab.c"
    break;

  case 46: /* declaration: string_type declaration  */
#line 235 "part2.y"
                                     {(yyval.node) = makeNode("STRING",(yyvsp[-1].node), (yyvsp[0].node));}
#line 2085 "y.tab.c"
    break;

  case 47: /* declaration: VAR declaration ':' type ';'  */
#line 236 "part2.y"
                                                  { (yyval.node) = makeNode("VAR",makeNode((yyvsp[-1].string),(yyvsp[-3].node),NULL),NULL);}
#line 2091 "y.tab.c"
    break;

  case 48: /* declaration: VAR declaration ':' type ';' declaration  */
#line 237 "part2.y"
                                                      { (yyval.node) = makeNode("VAR", makeNode((yyvsp[-2].string), (yyvsp[-4].node), (yyvsp[0].node)),NULL);}
#line 2097 "y.tab.c"
    break;

  case 49: /* declaration: assignment ',' declaration  */
#line 238 "part2.y"
                                                {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = (yyvsp[-2].node);}
#line 2103 "y.tab.c"
    break;

  case 50: /* declaration: ID ',' declaration  */
#line 239 "part2.y"
                                {(yyval.node) = makeNode((yyvsp[-2].string),NULL,(yyvsp[0].node));}
#line 2109 "y.tab.c"
    break;

  case 51: /* declaration: assignment  */
#line 240 "part2.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2115 "y.tab.c"
    break;

  case 52: /* declaration: ID  */
#line 241 "part2.y"
                 { (yyval.node) = makeNode((yyvsp[0].string), NULL, NULL); }
#line 2121 "y.tab.c"
    break;

  case 53: /* declaration: %empty  */
#line 242 "part2.y"
                     { (yyval.node) = NULL; }
#line 2127 "y.tab.c"
    break;

  case 54: /* nested_statement: statement  */
#line 244 "part2.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2133 "y.tab.c"
    break;

  case 55: /* nested_statement: declaration  */
#line 245 "part2.y"
                                              { (yyval.node) = (yyvsp[0].node); }
#line 2139 "y.tab.c"
    break;

  case 56: /* nested_statement: statement nested_statement  */
#line 246 "part2.y"
                                             { (yyvsp[-1].node) -> right = (yyvsp[0].node); (yyval.node) = (yyvsp[-1].node); }
#line 2145 "y.tab.c"
    break;

  case 57: /* proc_nested_statement: proc_statement  */
#line 248 "part2.y"
                                      { (yyval.node) = (yyvsp[0].node); }
#line 2151 "y.tab.c"
    break;

  case 58: /* proc_nested_statement: proc_statement proc_nested_statement  */
#line 249 "part2.y"
                                                            { (yyvsp[-1].node) -> right = (yyvsp[0].node); (yyval.node) = (yyvsp[-1].node); }
#line 2157 "y.tab.c"
    break;

  case 59: /* proc_statement: assignment ';'  */
#line 251 "part2.y"
                               {(yyval.node) = (yyvsp[-1].node);}
#line 2163 "y.tab.c"
    break;

  case 60: /* proc_statement: expression ';'  */
#line 252 "part2.y"
                                           {(yyval.node) = (yyvsp[-1].node);}
#line 2169 "y.tab.c"
    break;

  case 61: /* proc_statement: func_statement  */
#line 253 "part2.y"
                               {(yyval.node)=(yyvsp[0].node);}
#line 2175 "y.tab.c"
    break;

  case 62: /* proc_statement: proc_if_statement  */
#line 254 "part2.y"
                                  {(yyval.node)=(yyvsp[0].node);}
#line 2181 "y.tab.c"
    break;

  case 63: /* proc_statement: proc_while_statement  */
#line 255 "part2.y"
                                     { (yyval.node) = (yyvsp[0].node);}
#line 2187 "y.tab.c"
    break;

  case 64: /* proc_statement: proc_do_statement  */
#line 256 "part2.y"
                                  { (yyval.node) = (yyvsp[0].node);}
#line 2193 "y.tab.c"
    break;

  case 65: /* proc_statement: block_proc  */
#line 257 "part2.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2199 "y.tab.c"
    break;

  case 66: /* proc_statement: proc_for_statement  */
#line 258 "part2.y"
                                   {(yyval.node) = (yyvsp[0].node);}
#line 2205 "y.tab.c"
    break;

  case 67: /* statement: assignment ';'  */
#line 260 "part2.y"
                          {(yyval.node) = (yyvsp[-1].node);}
#line 2211 "y.tab.c"
    break;

  case 68: /* statement: declaration  */
#line 261 "part2.y"
                               {(yyval.node) = (yyvsp[0].node);}
#line 2217 "y.tab.c"
    break;

  case 69: /* statement: expression ';'  */
#line 262 "part2.y"
                                  {(yyval.node) = (yyvsp[-1].node);}
#line 2223 "y.tab.c"
    break;

  case 70: /* statement: func_statement  */
#line 263 "part2.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2229 "y.tab.c"
    break;

  case 71: /* statement: if_statement  */
#line 264 "part2.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2235 "y.tab.c"
    break;

  case 72: /* statement: while_statement  */
#line 265 "part2.y"
                           { (yyval.node) = (yyvsp[0].node);}
#line 2241 "y.tab.c"
    break;

  case 73: /* statement: do_statement  */
#line 266 "part2.y"
                        { (yyval.node) = (yyvsp[0].node);}
#line 2247 "y.tab.c"
    break;

  case 74: /* statement: block  */
#line 267 "part2.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 2253 "y.tab.c"
    break;

  case 75: /* statement: for_statement  */
#line 268 "part2.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 2259 "y.tab.c"
    break;

  case 76: /* statement: return_statement  */
#line 269 "part2.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2265 "y.tab.c"
    break;

  case 77: /* func_statement: ID ASSIGN ID '(' func_arguments ')' ';'  */
#line 271 "part2.y"
                                                        {(yyval.node) = makeNode((yyvsp[-5].string),makeNode((yyvsp[-6].string),NULL, makeNode((yyvsp[-4].string), (yyvsp[-2].node), NULL)), NULL); }
#line 2271 "y.tab.c"
    break;

  case 78: /* func_statement: ID '(' func_arguments ')'  */
#line 272 "part2.y"
                                          {(yyval.node) = makeNode("call_func", makeNode((yyvsp[-3].string),NULL,NULL), makeNode("ARGS", (yyvsp[-1].node), NULL));}
#line 2277 "y.tab.c"
    break;

  case 79: /* func_statement: ID '(' func_arguments ')' ';'  */
#line 273 "part2.y"
                                              {(yyval.node) = makeNode("call_func",makeNode((yyvsp[-4].string),makeNode("ARGS", (yyvsp[-2].node), NULL),NULL), NULL);}
#line 2283 "y.tab.c"
    break;

  case 80: /* func_statement: ID '(' func_arguments ')' ADD func_statement  */
#line 274 "part2.y"
                                                             {(yyval.node) = makeNode((yyvsp[-5].string),(yyvsp[-3].node),(yyvsp[0].node));}
#line 2289 "y.tab.c"
    break;

  case 81: /* func_arguments: %empty  */
#line 276 "part2.y"
                { (yyval.node) = NULL; }
#line 2295 "y.tab.c"
    break;

  case 82: /* func_arguments: expression ',' func_arguments  */
#line 277 "part2.y"
                                              {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = (yyvsp[-2].node);}
#line 2301 "y.tab.c"
    break;

  case 83: /* func_arguments: expression  */
#line 278 "part2.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2307 "y.tab.c"
    break;

  case 84: /* assignment: ID ASSIGN expression ';'  */
#line 280 "part2.y"
                                     { (yyval.node) = makeNode((yyvsp[-2].string), makeNode((yyvsp[-3].string), NULL, (yyvsp[-1].node)), NULL);}
#line 2313 "y.tab.c"
    break;

  case 85: /* assignment: ADDRESS ID ASSIGN expression  */
#line 281 "part2.y"
                                         { (yyval.node) = makeNode((yyvsp[-3].string), makeNode((yyvsp[-1].string), makeNode((yyvsp[-2].string), NULL, (yyvsp[0].node)), NULL), NULL);}
#line 2319 "y.tab.c"
    break;

  case 86: /* assignment: ID ASSIGN STRING_VAL  */
#line 282 "part2.y"
                                 {(yyval.node) = makeNode((yyvsp[-1].string),  makeNode((yyvsp[-2].string),  makeNode((yyvsp[0].string), NULL, NULL), NULL), NULL);}
#line 2325 "y.tab.c"
    break;

  case 87: /* assignment: ID '[' expression ']' ASSIGN STRING_VAL  */
#line 283 "part2.y"
                                                    {(yyval.node) = makeNode((yyvsp[-1].string),  makeNode((yyvsp[-5].string), makeNode("[]", NULL, (yyvsp[-3].node)), NULL), makeNode((yyvsp[0].string), NULL, NULL));}
#line 2331 "y.tab.c"
    break;

  case 88: /* assignment: ID ASSIGN ID '[' expression ']'  */
#line 284 "part2.y"
                                            {(yyval.node) = makeNode((yyvsp[-4].string),  makeNode((yyvsp[-5].string), NULL, makeNode((yyvsp[-3].string), makeNode("[]", NULL, (yyvsp[-1].node)), NULL)), NULL);}
#line 2337 "y.tab.c"
    break;

  case 89: /* assignment: ID '[' expression ']' ASSIGN CHAR_VAL  */
#line 285 "part2.y"
                                                  {(yyval.node) = makeNode((yyvsp[-1].string),  makeNode((yyvsp[-5].string),  makeNode("[]", NULL, (yyvsp[-3].node)), NULL), makeNode((yyvsp[0].string), NULL, NULL));}
#line 2343 "y.tab.c"
    break;

  case 90: /* assignment: ID '[' expression ']' ASSIGN ID  */
#line 286 "part2.y"
                                            {(yyval.node) = makeNode((yyvsp[-1].string),  makeNode((yyvsp[-5].string), makeNode("[]", NULL, (yyvsp[-3].node)), NULL), makeNode((yyvsp[0].string), NULL, NULL));}
#line 2349 "y.tab.c"
    break;

  case 91: /* multi_assign: assignment  */
#line 288 "part2.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2355 "y.tab.c"
    break;

  case 92: /* multi_assign: assignment ',' multi_assign  */
#line 289 "part2.y"
                                          { (yyval.node) = makeNode("", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2361 "y.tab.c"
    break;

  case 93: /* multi_assign: %empty  */
#line 290 "part2.y"
              { (yyval.node) = NULL; }
#line 2367 "y.tab.c"
    break;

  case 94: /* if_statement: IF '(' expression ')' statement  */
#line 292 "part2.y"
                                              { (yyval.node) = makeNode("IF",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2373 "y.tab.c"
    break;

  case 95: /* if_statement: IF '(' expression ')' statement ELSE statement  */
#line 293 "part2.y"
                                                             { (yyval.node) = makeNode("IF-ELSE", makeNode("", (yyvsp[-4].node), makeNode("", (yyvsp[-2].node),(yyvsp[0].node))), NULL); }
#line 2379 "y.tab.c"
    break;

  case 96: /* proc_if_statement: IF '(' expression ')' proc_statement  */
#line 295 "part2.y"
                                                        { (yyval.node) = makeNode("IF",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2385 "y.tab.c"
    break;

  case 97: /* proc_if_statement: IF '(' expression ')' proc_statement ELSE proc_statement  */
#line 296 "part2.y"
                                                                            { (yyval.node) = makeNode("IF-ELSE", makeNode("", (yyvsp[-4].node), makeNode("", (yyvsp[-2].node),(yyvsp[0].node))), NULL); }
#line 2391 "y.tab.c"
    break;

  case 98: /* while_statement: WHILE '(' expression ')' statement  */
#line 298 "part2.y"
                                                    { (yyval.node) = makeNode((yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2397 "y.tab.c"
    break;

  case 99: /* proc_while_statement: WHILE '(' expression ')' proc_statement  */
#line 300 "part2.y"
                                                              { (yyval.node) = makeNode((yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2403 "y.tab.c"
    break;

  case 100: /* do_statement: DO block WHILE '(' expression ')' ';'  */
#line 302 "part2.y"
                                                    { (yyval.node) = makeNode((yyvsp[-6].string), makeNode("", (yyvsp[-5].node),NULL), makeNode((yyvsp[-4].string), (yyvsp[-2].node), NULL)); }
#line 2409 "y.tab.c"
    break;

  case 101: /* proc_do_statement: DO block_proc WHILE '(' expression ')' ';'  */
#line 304 "part2.y"
                                                              { (yyval.node) = makeNode((yyvsp[-6].string), makeNode("", (yyvsp[-5].node),NULL), makeNode((yyvsp[-4].string), (yyvsp[-2].node), NULL)); }
#line 2415 "y.tab.c"
    break;

  case 102: /* for_statement: FOR '(' assignment ';' expression ';' update ')' statement  */
#line 306 "part2.y"
                                                                          { (yyval.node) = makeNode((yyvsp[-8].string), makeNode("INITS", (yyvsp[-6].node), makeNode("EXPR", (yyvsp[-4].node), makeNode("UPDATE", (yyvsp[-2].node), (yyvsp[0].node)))), NULL); }
#line 2421 "y.tab.c"
    break;

  case 103: /* proc_for_statement: FOR '(' assignment ';' expression ';' update ')' proc_statement  */
#line 308 "part2.y"
                                                                                    { (yyval.node) = makeNode((yyvsp[-8].string), makeNode("INITS", (yyvsp[-6].node), makeNode("EXPR", (yyvsp[-4].node), makeNode("UPDATE", (yyvsp[-2].node), (yyvsp[0].node)))), NULL); }
#line 2427 "y.tab.c"
    break;

  case 104: /* block: '{' '}'  */
#line 310 "part2.y"
               {(yyval.node) = makeNode("BLOCK",NULL, NULL);}
#line 2433 "y.tab.c"
    break;

  case 105: /* block: '{' declaration nested_statement return_statement '}'  */
#line 311 "part2.y"
                                                             { (yyval.node) = makeNode("BLOCK", makeNode("", (yyvsp[-3].node), (yyvsp[-2].node)),(yyvsp[-1].node)); }
#line 2439 "y.tab.c"
    break;

  case 106: /* block: '{' declaration return_statement '}'  */
#line 312 "part2.y"
                                            { (yyval.node) = makeNode("BLOCK", (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2445 "y.tab.c"
    break;

  case 107: /* block: '{' nested_statement return_statement '}'  */
#line 313 "part2.y"
                                                 { (yyval.node) = makeNode("BLOCK", (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2451 "y.tab.c"
    break;

  case 108: /* block: '{' declaration proc_nested_statement '}'  */
#line 314 "part2.y"
                                                 { (yyval.node) = makeNode("BLOCK", makeNode("", (yyvsp[-2].node), (yyvsp[-1].node)),NULL);}
#line 2457 "y.tab.c"
    break;

  case 109: /* block: '{' declaration '}'  */
#line 315 "part2.y"
                           {(yyval.node) = makeNode("BLOCK",(yyvsp[-1].node), NULL); }
#line 2463 "y.tab.c"
    break;

  case 110: /* block: '{' proc_nested_statement '}'  */
#line 316 "part2.y"
                                     { (yyval.node) = makeNode("BLOCK", (yyvsp[-1].node), NULL); }
#line 2469 "y.tab.c"
    break;

  case 111: /* block_proc: '{' '}'  */
#line 318 "part2.y"
                    {(yyval.node) = makeNode("BLOCK", NULL, NULL);}
#line 2475 "y.tab.c"
    break;

  case 112: /* block_proc: '{' declaration proc_nested_statement '}'  */
#line 319 "part2.y"
                                                      { (yyval.node) = makeNode("BLOCK", makeNode("", (yyvsp[-2].node), (yyvsp[-1].node)),NULL);}
#line 2481 "y.tab.c"
    break;

  case 113: /* block_proc: '{' declaration '}'  */
#line 320 "part2.y"
                                {(yyval.node) = makeNode("BLOCK",(yyvsp[-1].node), NULL); }
#line 2487 "y.tab.c"
    break;

  case 114: /* block_proc: '{' proc_nested_statement '}'  */
#line 321 "part2.y"
                                          { (yyval.node) = makeNode("BLOCK", (yyvsp[-1].node), NULL); }
#line 2493 "y.tab.c"
    break;

  case 115: /* expression: element_of_expression  */
#line 323 "part2.y"
                                  {(yyval.node) = (yyvsp[0].node);}
#line 2499 "y.tab.c"
    break;

  case 116: /* expression: '(' expression ')'  */
#line 324 "part2.y"
                               {(yyval.node) = makeNode("", (yyvsp[-1].node), NULL);}
#line 2505 "y.tab.c"
    break;

  case 117: /* expression: expression EQ expression  */
#line 325 "part2.y"
                                         {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2511 "y.tab.c"
    break;

  case 118: /* expression: MUL '(' expression ')'  */
#line 326 "part2.y"
                                   {(yyval.node) = makeNode("*",(yyvsp[-1].node), NULL);}
#line 2517 "y.tab.c"
    break;

  case 119: /* expression: expression AND expression  */
#line 327 "part2.y"
                                          {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2523 "y.tab.c"
    break;

  case 120: /* expression: expression OR expression  */
#line 328 "part2.y"
                                         {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2529 "y.tab.c"
    break;

  case 121: /* expression: expression GT expression  */
#line 329 "part2.y"
                                         {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2535 "y.tab.c"
    break;

  case 122: /* expression: expression GTE expression  */
#line 330 "part2.y"
                                          {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2541 "y.tab.c"
    break;

  case 123: /* expression: expression LTE expression  */
#line 331 "part2.y"
                                          {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2547 "y.tab.c"
    break;

  case 124: /* expression: expression LT expression  */
#line 332 "part2.y"
                                         {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2553 "y.tab.c"
    break;

  case 125: /* expression: expression NEQ expression  */
#line 333 "part2.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2559 "y.tab.c"
    break;

  case 126: /* expression: expression ADD expression  */
#line 334 "part2.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2565 "y.tab.c"
    break;

  case 127: /* expression: expression SUB expression  */
#line 335 "part2.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2571 "y.tab.c"
    break;

  case 128: /* expression: expression MUL expression  */
#line 336 "part2.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2577 "y.tab.c"
    break;

  case 129: /* expression: unary_op expression  */
#line 337 "part2.y"
                                            { (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[0].node), NULL); }
#line 2583 "y.tab.c"
    break;

  case 130: /* expression: expression DIV expression  */
#line 338 "part2.y"
                                      {(yyvsp[-2].node) -> right = (yyvsp[0].node); (yyval.node) = makeNode((yyvsp[-1].string), (yyvsp[-2].node), NULL);}
#line 2589 "y.tab.c"
    break;

  case 131: /* expression: address_of  */
#line 339 "part2.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2595 "y.tab.c"
    break;

  case 132: /* element_of_expression: primitive_value  */
#line 341 "part2.y"
                                       {(yyval.node) = makeNode((yyvsp[0].string), NULL, NULL); }
#line 2601 "y.tab.c"
    break;

  case 133: /* element_of_expression: '|' ID '|'  */
#line 342 "part2.y"
                                    { (yyval.node) = makeNode("STR_LEN", makeNode((yyvsp[-1].string), NULL, NULL), NULL); }
#line 2607 "y.tab.c"
    break;

  case 134: /* element_of_expression: func_statement  */
#line 343 "part2.y"
                                      { (yyval.node) = (yyvsp[0].node); }
#line 2613 "y.tab.c"
    break;

  case 135: /* element_of_expression: ID  */
#line 344 "part2.y"
                          { (yyval.node) = makeNode((yyvsp[0].string),NULL, NULL); }
#line 2619 "y.tab.c"
    break;

  case 136: /* primitive_value: CHAR_VAL  */
#line 346 "part2.y"
                          { (yyval.string) = (yyvsp[0].string); }
#line 2625 "y.tab.c"
    break;

  case 137: /* primitive_value: HEX_INT  */
#line 347 "part2.y"
                          { (yyval.string) = (yyvsp[0].string); }
#line 2631 "y.tab.c"
    break;

  case 138: /* primitive_value: DEC_INT  */
#line 348 "part2.y"
                          {(yyval.string) = (yyvsp[0].string); }
#line 2637 "y.tab.c"
    break;

  case 139: /* primitive_value: REAL_VAL  */
#line 349 "part2.y"
                          { (yyval.string) = (yyvsp[0].string); }
#line 2643 "y.tab.c"
    break;

  case 140: /* primitive_value: TRUE_VAL  */
#line 350 "part2.y"
                          { (yyval.string) = (yyvsp[0].string);}
#line 2649 "y.tab.c"
    break;

  case 141: /* primitive_value: NULLP  */
#line 351 "part2.y"
                       { (yyval.string) = (yyvsp[0].string); }
#line 2655 "y.tab.c"
    break;

  case 142: /* primitive_value: DER_ID  */
#line 352 "part2.y"
                        { (yyval.string) = (yyvsp[0].string); }
#line 2661 "y.tab.c"
    break;

  case 143: /* primitive_value: FALSE_VAL  */
#line 353 "part2.y"
                           { (yyval.string) = (yyvsp[0].string);}
#line 2667 "y.tab.c"
    break;

  case 144: /* address_of: ADDRESS ID  */
#line 355 "part2.y"
                       { (yyval.node) = makeNode((yyvsp[-1].string), makeNode((yyvsp[0].string), NULL, NULL), NULL); }
#line 2673 "y.tab.c"
    break;

  case 145: /* address_of: ADDRESS ID '[' expression ']'  */
#line 356 "part2.y"
                                          { (yyval.node) = makeNode((yyvsp[-4].string), makeNode((yyvsp[-3].string), makeNode("[]", (yyvsp[-1].node), NULL), NULL), NULL); }
#line 2679 "y.tab.c"
    break;

  case 146: /* return_statement: RETURN expression ';'  */
#line 358 "part2.y"
                                       { (yyval.node) = makeNode("RET", (yyvsp[-1].node), NULL); }
#line 2685 "y.tab.c"
    break;

  case 147: /* return_statement: RETURN func_statement  */
#line 359 "part2.y"
                                        { (yyval.node) = makeNode("RET", (yyvsp[0].node), NULL); }
#line 2691 "y.tab.c"
    break;

  case 148: /* update: ID ADD ADD  */
#line 361 "part2.y"
                   { (yyval.node) = makeNode("++", makeNode((yyvsp[-2].string), NULL, NULL), NULL); }
#line 2697 "y.tab.c"
    break;

  case 149: /* update: ID SUB SUB  */
#line 362 "part2.y"
                   { (yyval.node) = makeNode("--", makeNode((yyvsp[-2].string), NULL, NULL), NULL); }
#line 2703 "y.tab.c"
    break;

  case 150: /* update: multi_assign  */
#line 363 "part2.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2709 "y.tab.c"
    break;

  case 151: /* unary_op: ADD  */
#line 365 "part2.y"
              { (yyval.string) = (yyvsp[0].string); }
#line 2715 "y.tab.c"
    break;

  case 152: /* unary_op: SUB  */
#line 366 "part2.y"
              { (yyval.string) = (yyvsp[0].string); }
#line 2721 "y.tab.c"
    break;

  case 153: /* unary_op: NOT  */
#line 367 "part2.y"
              {(yyval.string) = (yyvsp[0].string);}
#line 2727 "y.tab.c"
    break;


#line 2731 "y.tab.c"

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

#line 369 "part2.y"

#include "lex.yy.c"
int main()
{
    int x= yyparse();
	if(x == 0)
	{
	printf("syntax valid\n"); 
	printf("Semantics valid\n");
	}
	return x;
}

Arguments* callfuncargs(code* CODEscope, node* tree, int* count) {
	Arguments* arr = NULL, ar[50];
	char* type = tree -> left -> token;
	while(tree -> right != NULL) {
		ar[(*count)++].type = exprtype(tree -> left, CODEscope);
		printf("390 %d %s, ", *count, tree -> left -> token);
		if(tree -> right != NULL)
			tree = tree -> right;
		else
			tree = NULL;
	}
	arr = (Arguments*)malloc(sizeof(Arguments) * (*count));
	for(int i = 0; i < *count; i++)
		arr[i].type = ar[i].type;
	return arr;
}
char* findfunc(node* tree, code* CODEscope) {
	code* temp = CODEscope;
	Arguments* args;
	int find = false, flag = true;
	printf("L 403 We Here mate!\n");
	while(temp != NULL) {	
		printf("L 404 We Here mate!\n");
		for(int i = 0; i < temp -> countfunc; i++)
		if(strcmp(tree -> left -> token, temp -> func[i] -> name) == 0) {
			printf("L 406 We Here mate!\n");
			find = true;
			flag = true;
			int count = 0;
			args = callfuncargs(CODEscope, tree -> right -> left, &count);
			printf("L416 %d %d ",count, temp -> func[i] -> countArgs);
			if(count == temp -> func[i] -> countArgs) {
				for(int j = 0; j < count; j++) {
					printf("L421 %s %s",args[j].type, temp -> func[i] -> args -> type);
					if(strcmp(args[j].type,temp -> func[i] -> args -> type) != 0)
						flag=false;
				}
				if(flag == true)
					return temp -> func[i] -> returnType;
			}
		}
		temp = temp -> beforeLVL;
	}
	printf("ERORR,func %s not find call in scope %s in func/proc %s\n",tree -> left -> token,CODEscope -> name,mycode -> func[mycode -> countfunc-1] -> name);
	if(find == true)
		printf("but find func with some name but other args\n");
		exit(1);
}
char* findvar(node* tree, code* CODEscope){ // tree = var type
	code* temp = CODEscope;
	if(strcmp(tree -> token, "solovar") == 0)
		tree = tree -> left;
	while(temp != NULL) {
		for(int i = 0; i < temp -> countvar; i++)
		if(strcmp(tree -> token, temp -> var[i].name) == 0) {
			if(tree -> left != NULL && strcmp(tree -> left -> token,"[") == 0) {
				if(strcmp(temp -> var[i].type,"STRING") == 0)
					if(strcmp(exprtype(tree -> left -> left,CODEscope),"INT") == 0)
						return "CHAR";
					else {
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in func/proc %s\n",CODEscope -> name,mycode -> func[mycode -> countfunc-1] -> name);
						exit(1);
					}
				else {
					printf("ERORR, you can use index only on string type (<string>[<int>]) in scope %s in func/proc %s\n",CODEscope -> name,mycode -> func[mycode -> countfunc-1] -> name);
					exit(1);
				}
			} else return temp -> var[i].type;
		}
		temp = temp -> beforeLVL;
	}
	exit(1);
}

char* exprtype(node * tree, code* CODEscope){
	char* msg = (char*)malloc(sizeof(char)*7);
	msg = "";
	if(strcmp(tree -> token,"NULL") == 0)
		msg = "NULL";
	else
	if(tree -> left != NULL){
		if(strcmp(tree -> left -> token,"INT") == 0)
			msg = "INT";
		if(strcmp(tree -> left -> token,"HEX") == 0)
			msg = "HEX";
		if(strcmp(tree -> left -> token,"CHAR") == 0)
			msg = "CHAR";
		if(strcmp(tree -> left -> token,"REAL") == 0)
			msg = "REAL";
		if(strcmp(tree -> left -> token,"STRING") == 0)
			msg = "STRING";
		if(strcmp(tree -> left -> token,"BOOLEAN") == 0)
			msg = "BOOL";
		if(strcmp(tree -> token,"!") == 0)
		if(strcmp(exprtype(tree -> left,CODEscope),"BOOL") == 0)
			msg ="BOOL";
		else{
			printf("Erorr op ! you can use only on boolean type");
			exit(1);
		}
		if(strcmp(tree -> token,"|") == 0)
		if(strcmp(exprtype(tree -> left,CODEscope),"STRING") == 0)
			msg = "INT";
		else {
			printf("Erorr op | you can use only on string type in func/proc %s", mycode -> func[mycode -> countfunc-1] -> name);
			exit(1);
		}
		if(strcmp(tree -> token,"==") == 0||strcmp(tree -> token,"!=") == 0) {
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
				tree -> token, exprtype(tree -> left,CODEscope), exprtype(tree -> right, CODEscope),
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
		if (strcmp(tree -> token, "call_func") == 0)
			msg = findfunc(tree, CODEscope);
	}
	if(strcmp(msg, "") == 0)
		msg = findvar(tree, CODEscope);
	return msg;
}
void push(code* from,char* name) {
	code * point;
	if(mycode == NULL)
		mycode = makecode(name);
	else {
	point = mycode;
	while(point -> nextLVL != NULL)
		point=point -> nextLVL;
	point -> nextLVL = makecode(name);
	point -> nextLVL -> beforeLVL = from;
	}
}
code* makecode(char* name) {	
	code *newlvl = (code*)malloc(sizeof(code));
	newlvl -> place = ++scope;
	newlvl -> name = name;
	newlvl -> var = NULL;
	newlvl -> countvar = 0;
	newlvl -> func = NULL;
	newlvl -> countfunc = 0;
	newlvl -> nextLVL = NULL;
	newlvl -> beforeLVL = NULL;
	return newlvl;
}

void addvar(Arguments* args, int countvars, int isArg, code* CODEscope){
	if(countvars == 0)
		return;
	Varaiable* temp;
	code* codey = CODEscope;
	for(int i = 0; i < countvars; i++)
		for(int j = 0; j < countvars; j++)
			if(i != j && strcmp(args[j].name, args[i].name) == 0 ) {
				printf("sorry you can not have same named variables %s in one declaration\n", args[i].name);
				code* t = codey -> beforeLVL;
				while(t -> beforeLVL != NULL && t -> beforeLVL -> countfunc == 0)
					t = t -> beforeLVL;
				if(t -> func != NULL)
					printf(",in func %s\n",t -> func[t -> countfunc - 1] -> name);
				else
					printf("\n");
				exit(1);
			}
	if(codey -> var == NULL)
		codey -> var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	else {
		temp=codey -> var;
		codey -> var=(Varaiable*) malloc(sizeof(Varaiable)*(codey -> countvar + countvars));
		for(int i = 0; i < codey -> countvar; i++) {
			for(int j = 0; j < countvars; j++) {
				if(strcmp(temp[i].name,args[j].name) == 0 ) {
					printf("sorry you can not have same named variables %s in the same scope",temp[i].name);
					code* t = codey -> beforeLVL;
					while(t -> beforeLVL != NULL && t -> beforeLVL -> countfunc == 0)
						t = t -> beforeLVL;
					if(t -> func != NULL)
						printf(",in func %s\n", t -> func[t -> countfunc-1] -> name);
					else
						printf("\n");
					exit(1);
				}
			}
			codey -> var[i]=temp[i];	
		}
	}
	for(int j = 0; j < countvars; j++) {
		codey -> var[codey -> countvar].name = args[j].name;
		codey -> var[codey -> countvar].value = NULL;
		codey -> var[codey -> countvar].isArg = isArg;
		codey -> var[(codey -> countvar)++].type = args[j].type;
	}
	printf("L718 vars in scope %s \n", codey -> name);
	for(int i = 0; i < codey -> countvar; i++)
		printf("%s %s,", codey -> var[i].name, codey -> var[i].type);
	printf("\nend vars scope %d\n", codey -> place);
}
 
void addFunc(char* name, Arguments* args, node* returnType, int countArgs, code* CODEscope) {
	Function** temp;
	code* codey = CODEscope;
	for(int i = 0; i < countArgs; i++)
		for(int j = 0; j < countArgs; j++)
			if(i != j && strcmp(args[j].name, args[i].name) == 0 ) {
				printf("Sorry you can't put several arguments %s in the same function %s\n", args[i].name, name);
				exit(1);
			}
	if(codey -> func == NULL) 
		codey -> func=(Function**) malloc(sizeof(Function*));
	else {
		temp=codey -> func;
		codey -> func = (Function**)malloc(sizeof(Function*) * (codey -> countfunc + 1));
		for(int i = 0; i < codey -> countfunc; i++) {
			if(strcmp(temp[i] -> name, name) == 0 ) {
				printf("Sorry you can't put several arguments %s in the same scope \n",temp[i] -> name);
				exit(1);
			}
			codey -> func[i]=temp[i];
		}
	}
	codey -> func[codey -> countfunc] = (Function*)malloc(sizeof(Function));
	codey -> func[codey -> countfunc] -> name=name;
	codey -> func[codey -> countfunc] -> args=args;
	if(returnType == NULL)
		codey -> func[codey -> countfunc] -> returnType = NULL;
	else {
		if(strcmp(returnType -> token, "STRING") == 0) {
			printf("ERORR, return type in function %s can not be a string \n", name);
			exit(1);
		}
		codey -> func[codey -> countfunc] -> returnType = returnType -> token;
	}
	codey -> func[codey -> countfunc] -> countArgs = countArgs;
	codey -> func[codey -> countfunc] -> findreturn = false;
	++(codey -> countfunc); 

	//printf("L772 start %s in scope %d\n", name, codey -> place);
	for(int i = 0; i < countArgs; i++)
		printf("%s %s,", codey -> func[codey -> countfunc-1] -> args[i].name, codey -> func[codey -> countfunc-1] -> args[i].type);
	//printf("end %s\n", name);
}

int typeFinder(char* token){
	if(strcmp(token, "INT") == 0) return 0;
	if(strcmp(token, "REAL") == 0) return 0;
	if(strcmp(token, "BOOL") == 0) return 0;
	if(strcmp(token, "STRING") == 0) return 0;
	if(strcmp(token, "CHARP") == 0) return 0;
	if(strcmp(token, "REALP") == 0) return 0;
	if(strcmp(token, "INTP") == 0) return 0;
	return 1;
}

Arguments* makeArgs(node *tree, int *count){ //Should be recieving Var
	Arguments *arr = NULL;
	Arguments ar[50];
	char* type;
	if(tree != NULL) {
		node* VarName = tree -> left -> left;
		node* VarType = tree -> left;
		type = VarType -> token;
		if(typeFinder(VarName->token) == 0) {
            do {
                ar[*count].name = VarName -> token;
                ar[*count].type = type;
                (*count)++;
                if(VarName -> right == NULL)
                    VarName = NULL;
                else
                    VarName = VarName -> right;
            } while(VarName != NULL);
			if(VarType -> right != NULL){
				VarName = VarType -> right -> left;
				type = VarType -> token;
				do {
					ar[*count].name = VarName -> token;
					ar[*count].type = type;
					(*count)++;
					if(VarName -> right == NULL)
						VarName = NULL;
					else
						VarName = VarName -> right;
				} while(VarName != NULL);
			}
        }
        arr = (Arguments*)malloc(sizeof(Arguments) * (*count));
        for(int i = 0; i < *count; i++) {
            arr[i].name = strdup(ar[i].name); // Copy the string to prevent pointing to temporary variables
            arr[i].type = strdup(ar[i].type); // Copy the string to prevent pointing to temporary variables
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
	fprintf(stderr,"%s at line %d ", e, yylineno);
	fprintf(stderr, "- invalid character '%s'\n", yytext);
	return 0;
}

code* lestcode(code * codey){
	code * CODEscope=codey;
	if(CODEscope != NULL)
	while(CODEscope -> nextLVL != NULL)
		CODEscope = CODEscope -> nextLVL;
	return CODEscope;
}

void syntaxMKscope(node* tree,code* CODEscope){
	if(strcmp(tree -> token, "=") == 0 ) {
		if(!(strcmp(exprtype(tree -> right,CODEscope),"NULL") == 0
		&& (strcmp(exprtype(tree -> left,CODEscope),"REAL_PTR") == 0
		||strcmp(exprtype(tree -> left,CODEscope),"INT_PTR") == 0
		||strcmp(exprtype(tree -> left,CODEscope),"CHAR_PTR") == 0)))
		if(strcmp(exprtype(tree -> left,CODEscope),exprtype(tree -> right,CODEscope)) != 0) {
			printf("ERORR: %s = %s can not be evaluated in scope %s in the fuction %s\n",exprtype(tree -> left,CODEscope),exprtype(tree -> right,CODEscope),CODEscope -> name,mycode -> func[mycode -> countfunc-1] -> name);
			exit(1);
		}
	}
	else if(strcmp(tree -> token, "VAR") == 0) {
		int countvar = 0;
		Arguments* var = makeArgs(tree, &countvar);
		addvar(var, countvar, 0, CODEscope);
	}
	else if(strcmp(tree -> token, "IF") == 0) {
		if(strcmp(exprtype(tree -> left -> left,CODEscope),"BOOL") != 0) {
			printf("ERORR,If expression must be evaluated to boolean\n");
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
		if(strcmp(exprtype(tree -> left -> left, CODEscope),"BOOL") != 0) {
			printf("ERROR:For expression must evaluate to boolean\n");
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
			printf("ERROR:For expression must evaluate to boolean\n");
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
        int count = 0;
		Arguments* arg = makeArgs(tree -> left -> right -> left, &count);
		addFunc(tree -> left -> token, arg, tree -> left -> right -> right, count, CODEscope);
		push(CODEscope, tree -> token);
		addvar(arg, count, 1, lestcode(CODEscope));
		if (tree -> left) syntaxMKscope(tree -> left, lestcode( CODEscope -> nextLVL));
		if (tree -> right) syntaxMKscope(tree -> right, lestcode( CODEscope -> nextLVL));
		if(CODEscope -> func[CODEscope -> countfunc-1] -> findreturn == false) {
			printf("ERROR:At function %s - did not find return!\n", tree -> left -> token);
			exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree -> token, "PROC") == 0) {
        int count = 0;
		Arguments* arg = makeArgs(tree -> left -> right -> left, &count);
		addFunc(tree -> left -> token, arg, NULL, count, CODEscope);
		push(CODEscope,tree -> token);
		addvar(arg, count, 1, lestcode(CODEscope));
		if (tree -> left) 
			syntaxMKscope(tree -> left,lestcode( CODEscope -> nextLVL));
		if (tree -> right)
			syntaxMKscope(tree -> right,lestcode( CODEscope -> nextLVL));
			scope--;	
			return;
    }

	else if(strcmp(tree -> token, "call_func") == 0) {
		findfunc(tree, CODEscope);
		printf("%s \n",tree -> token);
	}
	else if(strcmp(tree -> token, "CODE") == 0) {
		printTree(tree,printlevel);
		push(NULL,tree -> token);
		if (tree -> left) syntaxMKscope(tree -> left,mycode);
		if (tree -> right) syntaxMKscope(tree -> right,mycode);
		scope--;
		return;
	}
    else if(strcmp(tree -> token, "BODY") == 0) {
        int count = 0;
		Arguments* arg = makeArgs(tree -> left, &count);
		addvar(arg, count, 1, lestcode(CODEscope));
		push(CODEscope,tree -> token);
		if(tree->left)
			syntaxMKscope(tree -> left, lestcode( CODEscope -> nextLVL));
		if(tree->right)
			syntaxMKscope(tree -> right, lestcode( CODEscope -> nextLVL));
	}
	else if(strcmp(tree -> token, "ARGS") == 0) { 
        int count = 0;
		Arguments* arg = makeArgs(tree -> left, &count);
		addvar(arg, count, 1, lestcode(CODEscope));
		push(CODEscope,tree -> token);
		if(tree->left)
			syntaxMKscope(tree -> left, lestcode( CODEscope -> nextLVL));
		if(tree->right)
			syntaxMKscope(tree -> right, lestcode( CODEscope -> nextLVL));
	}
    else if(strcmp(tree -> token, "Main") == 0) {
		if(flagMain == true) {
			printf("ERROR:Main can not be inside a function/procedure\n");
			exit(1);
		}
		flagMain = true;
		addFunc(tree -> token, NULL, NULL, 0, CODEscope);
		push(CODEscope,tree -> token);
		if (tree -> left) 
			syntaxMKscope(tree -> left,lestcode( CODEscope -> nextLVL));
		
		if (tree -> right)
			syntaxMKscope(tree -> right,lestcode( CODEscope -> nextLVL));
			scope--;
			return;        
    }       
	else if(strcmp(tree -> token, "IF-ELSE") == 0) {
		if(strcmp(exprtype(tree -> left -> left,CODEscope), "BOOL") != 0) {
			printf("ERROR: If statement must evaluate to boolean\n");
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
		code* temp = CODEscope;
		int flag = true;
		while(strcmp(temp -> name, "FUNCTION") != 0 && strcmp(temp -> name, "PROC") != 0 && strcmp(temp -> name, "CODE") != 0) {
			temp = temp -> beforeLVL;
			flag = false;
		}
		if(flag == false) {
			if(strcmp(exprtype(tree -> left,CODEscope),temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> returnType)) {
			printf("ERROR:At function %s - function type and return type do not match.\n",temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
			printf("%s, %s %s\n",exprtype(tree -> left,CODEscope),temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> returnType,temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
			exit(1);
			}
		}
		else{
			if(temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc - 1] -> returnType != NULL) {
				if(0 == strcmp(exprtype(tree -> left,CODEscope),temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> returnType)){
					temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc - 1] -> findreturn = true;
				}
				else {
					printf("ERROR:At procedure %s - can't have a return.\n",temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
					printf("%s, %s %s\n",exprtype(tree -> left,CODEscope),temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> returnType,temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
					exit(1);
				}
			}
			else {
				printf("ERROR:At procedure %s - can't have a return.\n", temp -> beforeLVL -> func[temp -> beforeLVL -> countfunc-1] -> name);
				exit(1);
			}  
		}  

	}
	
	if (tree -> left) syntaxMKscope(tree -> left, CODEscope);
	
	if (tree -> right) syntaxMKscope(tree -> right, CODEscope);
}
