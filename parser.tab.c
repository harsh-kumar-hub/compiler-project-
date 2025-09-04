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

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int line_number;
void yyerror(const char *s);

ASTNode* root = NULL;

#line 83 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_DO = 10,                        /* DO  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_SWITCH = 13,                    /* SWITCH  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_PRINT = 16,                     /* PRINT  */
  YYSYMBOL_READ = 17,                      /* READ  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_STRING = 19,                    /* STRING  */
  YYSYMBOL_VOID = 20,                      /* VOID  */
  YYSYMBOL_BOOL = 21,                      /* BOOL  */
  YYSYMBOL_TRUE = 22,                      /* TRUE  */
  YYSYMBOL_FALSE = 23,                     /* FALSE  */
  YYSYMBOL_MAIN = 24,                      /* MAIN  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 28,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 29,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 30,                    /* MODULO  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_NEQ = 33,                       /* NEQ  */
  YYSYMBOL_LT = 34,                        /* LT  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_LTE = 36,                       /* LTE  */
  YYSYMBOL_GTE = 37,                       /* GTE  */
  YYSYMBOL_INCREMENT = 38,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 39,                 /* DECREMENT  */
  YYSYMBOL_PLUS_ASSIGN = 40,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 41,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 42,               /* MULT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 43,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 44,                /* MOD_ASSIGN  */
  YYSYMBOL_AND = 45,                       /* AND  */
  YYSYMBOL_OR = 46,                        /* OR  */
  YYSYMBOL_NOT = 47,                       /* NOT  */
  YYSYMBOL_LPAREN = 48,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 49,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 50,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 51,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 52,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 53,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 54,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 55,                     /* COMMA  */
  YYSYMBOL_COLON = 56,                     /* COLON  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_function_declaration = 59,      /* function_declaration  */
  YYSYMBOL_param_list = 60,                /* param_list  */
  YYSYMBOL_param = 61,                     /* param  */
  YYSYMBOL_type = 62,                      /* type  */
  YYSYMBOL_statement_list = 63,            /* statement_list  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_declaration = 65,               /* declaration  */
  YYSYMBOL_assignment = 66,                /* assignment  */
  YYSYMBOL_compound_assign = 67,           /* compound_assign  */
  YYSYMBOL_expression = 68,                /* expression  */
  YYSYMBOL_bool_literal = 69,              /* bool_literal  */
  YYSYMBOL_function_call = 70,             /* function_call  */
  YYSYMBOL_arg_list = 71,                  /* arg_list  */
  YYSYMBOL_switch_statement = 72,          /* switch_statement  */
  YYSYMBOL_case_list = 73,                 /* case_list  */
  YYSYMBOL_case_statement = 74,            /* case_statement  */
  YYSYMBOL_default_statement = 75,         /* default_statement  */
  YYSYMBOL_if_statement = 76,              /* if_statement  */
  YYSYMBOL_while_statement = 77,           /* while_statement  */
  YYSYMBOL_for_statement = 78,             /* for_statement  */
  YYSYMBOL_do_while_statement = 79,        /* do_while_statement  */
  YYSYMBOL_break_statement = 80,           /* break_statement  */
  YYSYMBOL_continue_statement = 81,        /* continue_statement  */
  YYSYMBOL_print_statement = 82,           /* print_statement  */
  YYSYMBOL_read_statement = 83,            /* read_statement  */
  YYSYMBOL_return_statement = 84           /* return_statement  */
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

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
       0,    54,    54,    55,    59,    61,    63,    68,    69,    73,
      77,    78,    79,    80,    84,    85,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     106,   107,   111,   112,   114,   118,   119,   120,   121,   122,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   152,   153,   157,   158,   162,   163,   167,
     172,   173,   174,   175,   179,   184,   189,   191,   196,   201,
     206,   211,   215,   219,   223,   227,   228
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIFIER",
  "STRING_LITERAL", "IF", "ELSE", "WHILE", "FOR", "DO", "BREAK",
  "CONTINUE", "SWITCH", "CASE", "DEFAULT", "PRINT", "READ", "INT",
  "STRING", "VOID", "BOOL", "TRUE", "FALSE", "MAIN", "RETURN", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "MODULO", "ASSIGN", "EQ", "NEQ", "LT",
  "GT", "LTE", "GTE", "INCREMENT", "DECREMENT", "PLUS_ASSIGN",
  "MINUS_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND", "OR",
  "NOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "SEMICOLON", "COMMA", "COLON", "$accept", "program",
  "function_declaration", "param_list", "param", "type", "statement_list",
  "statement", "declaration", "assignment", "compound_assign",
  "expression", "bool_literal", "function_call", "arg_list",
  "switch_statement", "case_list", "case_statement", "default_statement",
  "if_statement", "while_statement", "for_statement", "do_while_statement",
  "break_statement", "continue_statement", "print_statement",
  "read_statement", "return_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,   -64,   -64,   -64,   -64,     5,   -64,    16,   -64,   -64,
     -41,   -33,    -8,   -31,   -29,     0,   -25,    54,    15,    51,
      27,    66,   -64,    51,     4,    18,    60,    63,    51,   -64,
     -64,    64,   128,   109,   128,    51,   117,    77,    51,    76,
      80,    81,   -64,   -64,   -64,   -64,   -64,    82,    86,    87,
      88,    89,    51,   -64,    93,   128,   -64,   -64,   -64,   -64,
     -64,   100,   128,   128,   128,   128,   142,   144,   128,   -64,
     -20,   -64,   -64,   -64,   150,   152,   128,   128,   369,   -64,
     -64,   -64,   369,   107,   111,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   108,   -64,   369,   -64,   151,
     115,   198,   369,   242,   266,   348,   114,   121,   290,   128,
     -64,   -64,   -64,   314,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   -64,   162,   -64,
     128,   -64,   139,    51,    51,   128,   128,   122,   220,   -64,
      45,    45,   -64,   -64,   -64,    90,    90,    52,    52,    52,
      52,   404,   390,   118,   -64,   128,   166,   -64,   175,   338,
      39,   -64,   -64,   369,    51,   142,   120,   179,   133,   140,
      39,   -64,   -64,   141,   -64,   136,    51,   -64,   -64,   -64,
      51,    51,   -64,   -64,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,    11,    12,    13,     0,     2,     0,     1,     3,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,    81,
      82,     0,     0,     0,    86,     0,     0,     0,    14,     0,
       0,     0,    24,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     8,     0,     0,    35,    36,    37,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,    40,
      43,    41,    63,    64,     0,     0,     0,     0,    83,    42,
      62,    84,    85,     0,    30,     6,    15,    16,    17,    28,
      22,    23,    25,    26,    27,     0,     4,    32,    66,    67,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     5,
       0,    65,     0,     0,     0,     0,     0,     0,     0,    59,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,    68,     0,    76,    78,     0,     0,
       0,    44,    31,    33,     0,     0,     0,     0,     0,     0,
      70,    72,    77,     0,    80,     0,     0,    69,    71,    72,
       0,     0,    75,    79,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   188,   173,   -64,    22,   -21,   -27,   -64,   -63,
     -64,   -26,   -64,   -19,    65,   -64,    28,   -64,    29,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    15,    16,    36,    37,    38,    39,    40,
      63,    99,    79,    80,   100,    42,   169,   170,   171,    43,
      44,    45,    46,    47,    48,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    67,    54,   106,    41,     8,    78,    12,    82,    41,
       1,     2,     3,     4,    83,    13,    41,    86,    18,    41,
      10,    19,     7,     1,     2,     3,     4,     7,    61,    97,
      21,    95,   109,    41,    17,    55,   101,   102,   103,   104,
      11,    14,   108,    17,    56,    57,    58,    59,    60,    20,
     112,   113,    61,   167,   168,    24,    62,    25,    22,    26,
      27,    28,    29,    30,    31,    23,    64,    32,    33,     1,
       2,     3,     4,   116,   117,   118,    34,    52,   114,   115,
     116,   117,   118,   138,     1,     2,     3,     4,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    35,   173,    69,    70,    71,   156,   157,    65,   158,
     159,    66,    68,    81,    41,    41,   114,   115,   116,   117,
     118,    84,    72,    73,   121,   122,   123,   124,    85,   163,
      87,    69,    70,    71,    88,    89,    90,   172,    74,    75,
      91,    92,    93,    94,    96,    41,   105,    76,    77,    98,
      72,    73,   107,   183,   110,   182,   111,    41,   127,   129,
     184,    41,    41,   128,   131,   153,    74,    75,   135,   136,
     155,   162,   160,   164,   174,    76,    77,   114,   115,   116,
     117,   118,   175,   119,   120,   121,   122,   123,   124,   176,
     180,   177,   181,     9,    53,   154,   125,   126,   178,   179,
       0,   114,   115,   116,   117,   118,   130,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
     125,   126,     0,     0,   114,   115,   116,   117,   118,   165,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,   125,   126,     0,   114,   115,   116,   117,
     118,   132,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,     0,     0,     0,   125,   126,     0,   114,   115,
     116,   117,   118,   161,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,   125,   126,     0,
       0,   133,   114,   115,   116,   117,   118,     0,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,   125,   126,     0,     0,   134,   114,   115,   116,   117,
     118,     0,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,     0,     0,     0,   125,   126,     0,     0,   137,
     114,   115,   116,   117,   118,     0,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,   125,
     126,     0,     0,   139,   114,   115,   116,   117,   118,     0,
     119,   120,   121,   122,   123,   124,     0,     0,     0,    55,
       0,     0,     0,   125,   126,     0,     0,   166,    56,    57,
      58,    59,    60,     0,     0,   114,   115,   116,   117,   118,
      62,   119,   120,   121,   122,   123,   124,     0,     0,     0,
       0,     0,     0,     0,   125,   126,   114,   115,   116,   117,
     118,     0,   119,   120,   121,   122,   123,   124,     0,     0,
     114,   115,   116,   117,   118,   125,   119,   120,   121,   122,
     123,   124
};

static const yytype_int16 yycheck[] =
{
      19,    28,    23,    66,    23,     0,    32,    48,    34,    28,
      18,    19,    20,    21,    35,    48,    35,    38,    49,    38,
       4,    50,     0,    18,    19,    20,    21,     5,    48,    55,
      55,    52,    52,    52,    12,    31,    62,    63,    64,    65,
      24,    49,    68,    21,    40,    41,    42,    43,    44,    49,
      76,    77,    48,    14,    15,     4,    52,     6,     4,     8,
       9,    10,    11,    12,    13,    50,    48,    16,    17,    18,
      19,    20,    21,    28,    29,    30,    25,    50,    26,    27,
      28,    29,    30,   109,    18,    19,    20,    21,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    50,   165,     3,     4,     5,   133,   134,    48,   135,
     136,    48,    48,     4,   133,   134,    26,    27,    28,    29,
      30,     4,    22,    23,    34,    35,    36,    37,    51,   155,
      54,     3,     4,     5,    54,    54,    54,   164,    38,    39,
      54,    54,    54,    54,    51,   164,     4,    47,    48,    49,
      22,    23,     8,   180,     4,   176,     4,   176,    51,    51,
     181,   180,   181,    52,    49,     3,    38,    39,    54,    48,
      31,    53,    50,     7,    54,    47,    48,    26,    27,    28,
      29,    30,     3,    32,    33,    34,    35,    36,    37,    56,
      49,    51,    56,     5,    21,   130,    45,    46,   170,   170,
      -1,    26,    27,    28,    29,    30,    55,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    26,    27,    28,    29,    30,    54,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    26,    27,    28,    29,
      30,    53,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    26,    27,
      28,    29,    30,    53,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    49,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    49,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    49,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    45,    46,    -1,    -1,    49,    40,    41,
      42,    43,    44,    -1,    -1,    26,    27,    28,    29,    30,
      52,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
      26,    27,    28,    29,    30,    45,    32,    33,    34,    35,
      36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    19,    20,    21,    58,    59,    62,     0,    59,
       4,    24,    48,    48,    49,    60,    61,    62,    49,    50,
      49,    55,     4,    50,     4,     6,     8,     9,    10,    11,
      12,    13,    16,    17,    25,    50,    62,    63,    64,    65,
      66,    70,    72,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    50,    60,    63,    31,    40,    41,    42,    43,
      44,    48,    52,    67,    48,    48,    48,    64,    48,     3,
       4,     5,    22,    23,    38,    39,    47,    48,    68,    69,
      70,     4,    68,    63,     4,    51,    63,    54,    54,    54,
      54,    54,    54,    54,    54,    63,    51,    68,    49,    68,
      71,    68,    68,    68,    68,     4,    66,     8,    68,    52,
       4,     4,    68,    68,    26,    27,    28,    29,    30,    32,
      33,    34,    35,    36,    37,    45,    46,    51,    52,    51,
      55,    49,    53,    49,    49,    54,    48,    49,    68,    49,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,     3,    71,    31,    64,    64,    68,    68,
      50,    53,    53,    68,     7,    54,    49,    14,    15,    73,
      74,    75,    64,    66,    54,     3,    56,    51,    73,    75,
      49,    56,    63,    64,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    60,    60,    61,
      62,    62,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      73,    73,    73,    73,    74,    75,    76,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     7,     8,     7,     1,     3,     2,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     2,     2,     3,
       2,     5,     3,     6,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       2,     2,     1,     1,     1,     4,     3,     1,     3,     7,
       1,     2,     1,     2,     4,     3,     5,     7,     5,     9,
       7,     1,     1,     2,     2,     2,     1
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
  case 2: /* program: function_declaration  */
#line 54 "parser.y"
                                                  { root = (yyvsp[0].ast); }
#line 1330 "parser.tab.c"
    break;

  case 3: /* program: program function_declaration  */
#line 55 "parser.y"
                                                  { root = create_statement_list_node((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1336 "parser.tab.c"
    break;

  case 4: /* function_declaration: type MAIN LPAREN RPAREN LBRACE statement_list RBRACE  */
#line 60 "parser.y"
        { (yyval.ast) = create_function_node((yyvsp[-6].ast), "main", NULL, (yyvsp[-1].ast)); }
#line 1342 "parser.tab.c"
    break;

  case 5: /* function_declaration: type IDENTIFIER LPAREN param_list RPAREN LBRACE statement_list RBRACE  */
#line 62 "parser.y"
        { (yyval.ast) = create_function_node((yyvsp[-7].ast), (yyvsp[-6].sval), (yyvsp[-4].ast), (yyvsp[-1].ast)); }
#line 1348 "parser.tab.c"
    break;

  case 6: /* function_declaration: type IDENTIFIER LPAREN RPAREN LBRACE statement_list RBRACE  */
#line 64 "parser.y"
        { (yyval.ast) = create_function_node((yyvsp[-6].ast), (yyvsp[-5].sval), NULL, (yyvsp[-1].ast)); }
#line 1354 "parser.tab.c"
    break;

  case 7: /* param_list: param  */
#line 68 "parser.y"
                                { (yyval.ast) = create_param_list((yyvsp[0].ast), NULL); }
#line 1360 "parser.tab.c"
    break;

  case 8: /* param_list: param COMMA param_list  */
#line 69 "parser.y"
                                { (yyval.ast) = create_param_list((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1366 "parser.tab.c"
    break;

  case 9: /* param: type IDENTIFIER  */
#line 73 "parser.y"
                               { (yyval.ast) = create_param_node((yyvsp[-1].ast), (yyvsp[0].sval)); }
#line 1372 "parser.tab.c"
    break;

  case 10: /* type: INT  */
#line 77 "parser.y"
                { (yyval.ast) = create_type_node("int"); }
#line 1378 "parser.tab.c"
    break;

  case 11: /* type: STRING  */
#line 78 "parser.y"
                { (yyval.ast) = create_type_node("string"); }
#line 1384 "parser.tab.c"
    break;

  case 12: /* type: VOID  */
#line 79 "parser.y"
                { (yyval.ast) = create_type_node("void"); }
#line 1390 "parser.tab.c"
    break;

  case 13: /* type: BOOL  */
#line 80 "parser.y"
                { (yyval.ast) = create_type_node("bool"); }
#line 1396 "parser.tab.c"
    break;

  case 14: /* statement_list: statement  */
#line 84 "parser.y"
                                   { (yyval.ast) = create_statement_list_node((yyvsp[0].ast), NULL); }
#line 1402 "parser.tab.c"
    break;

  case 15: /* statement_list: statement statement_list  */
#line 85 "parser.y"
                                   { (yyval.ast) = create_statement_list_node((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1408 "parser.tab.c"
    break;

  case 16: /* statement: declaration SEMICOLON  */
#line 89 "parser.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1414 "parser.tab.c"
    break;

  case 17: /* statement: assignment SEMICOLON  */
#line 90 "parser.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1420 "parser.tab.c"
    break;

  case 18: /* statement: if_statement  */
#line 91 "parser.y"
                                   { (yyval.ast) = (yyvsp[0].ast); }
#line 1426 "parser.tab.c"
    break;

  case 19: /* statement: while_statement  */
#line 92 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1432 "parser.tab.c"
    break;

  case 20: /* statement: for_statement  */
#line 93 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1438 "parser.tab.c"
    break;

  case 21: /* statement: do_while_statement  */
#line 94 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1444 "parser.tab.c"
    break;

  case 22: /* statement: break_statement SEMICOLON  */
#line 95 "parser.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1450 "parser.tab.c"
    break;

  case 23: /* statement: continue_statement SEMICOLON  */
#line 96 "parser.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1456 "parser.tab.c"
    break;

  case 24: /* statement: switch_statement  */
#line 97 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1462 "parser.tab.c"
    break;

  case 25: /* statement: print_statement SEMICOLON  */
#line 98 "parser.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1468 "parser.tab.c"
    break;

  case 26: /* statement: read_statement SEMICOLON  */
#line 99 "parser.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1474 "parser.tab.c"
    break;

  case 27: /* statement: return_statement SEMICOLON  */
#line 100 "parser.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1480 "parser.tab.c"
    break;

  case 28: /* statement: function_call SEMICOLON  */
#line 101 "parser.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1486 "parser.tab.c"
    break;

  case 29: /* statement: LBRACE statement_list RBRACE  */
#line 102 "parser.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1492 "parser.tab.c"
    break;

  case 30: /* declaration: type IDENTIFIER  */
#line 106 "parser.y"
                                                     { (yyval.ast) = create_declaration_node((yyvsp[-1].ast), (yyvsp[0].sval)); }
#line 1498 "parser.tab.c"
    break;

  case 31: /* declaration: type IDENTIFIER LBRACKET NUMBER RBRACKET  */
#line 107 "parser.y"
                                                     { (yyval.ast) = create_array_declaration_node((yyvsp[-4].ast), (yyvsp[-3].sval), create_number_node((yyvsp[-1].ival))); }
#line 1504 "parser.tab.c"
    break;

  case 32: /* assignment: IDENTIFIER ASSIGN expression  */
#line 111 "parser.y"
                                                     { (yyval.ast) = create_assignment_node((yyvsp[-2].sval), (yyvsp[0].ast)); }
#line 1510 "parser.tab.c"
    break;

  case 33: /* assignment: IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression  */
#line 113 "parser.y"
        { (yyval.ast) = create_array_assignment_node(create_array_access_node((yyvsp[-5].sval), (yyvsp[-3].ast)), (yyvsp[0].ast)); }
#line 1516 "parser.tab.c"
    break;

  case 34: /* assignment: IDENTIFIER compound_assign expression  */
#line 114 "parser.y"
                                                     { (yyval.ast) = create_compound_assignment_node((yyvsp[-2].sval), (yyvsp[-1].sval), (yyvsp[0].ast)); }
#line 1522 "parser.tab.c"
    break;

  case 35: /* compound_assign: PLUS_ASSIGN  */
#line 118 "parser.y"
                     { (yyval.sval) = "+="; }
#line 1528 "parser.tab.c"
    break;

  case 36: /* compound_assign: MINUS_ASSIGN  */
#line 119 "parser.y"
                     { (yyval.sval) = "-="; }
#line 1534 "parser.tab.c"
    break;

  case 37: /* compound_assign: MULT_ASSIGN  */
#line 120 "parser.y"
                     { (yyval.sval) = "*="; }
#line 1540 "parser.tab.c"
    break;

  case 38: /* compound_assign: DIV_ASSIGN  */
#line 121 "parser.y"
                     { (yyval.sval) = "/="; }
#line 1546 "parser.tab.c"
    break;

  case 39: /* compound_assign: MOD_ASSIGN  */
#line 122 "parser.y"
                     { (yyval.sval) = "%="; }
#line 1552 "parser.tab.c"
    break;

  case 40: /* expression: NUMBER  */
#line 126 "parser.y"
                                { (yyval.ast) = create_number_node((yyvsp[0].ival)); }
#line 1558 "parser.tab.c"
    break;

  case 41: /* expression: STRING_LITERAL  */
#line 127 "parser.y"
                               { (yyval.ast) = create_string_node((yyvsp[0].sval)); }
#line 1564 "parser.tab.c"
    break;

  case 42: /* expression: bool_literal  */
#line 128 "parser.y"
                               { (yyval.ast) = (yyvsp[0].ast); }
#line 1570 "parser.tab.c"
    break;

  case 43: /* expression: IDENTIFIER  */
#line 129 "parser.y"
                               { (yyval.ast) = create_identifier_node((yyvsp[0].sval)); }
#line 1576 "parser.tab.c"
    break;

  case 44: /* expression: IDENTIFIER LBRACKET expression RBRACKET  */
#line 130 "parser.y"
                                              { (yyval.ast) = create_array_access_node((yyvsp[-3].sval), (yyvsp[-1].ast)); }
#line 1582 "parser.tab.c"
    break;

  case 45: /* expression: expression PLUS expression  */
#line 131 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("+", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1588 "parser.tab.c"
    break;

  case 46: /* expression: expression MINUS expression  */
#line 132 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("-", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1594 "parser.tab.c"
    break;

  case 47: /* expression: expression MULTIPLY expression  */
#line 133 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("*", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1600 "parser.tab.c"
    break;

  case 48: /* expression: expression DIVIDE expression  */
#line 134 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("/", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1606 "parser.tab.c"
    break;

  case 49: /* expression: expression MODULO expression  */
#line 135 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("%", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1612 "parser.tab.c"
    break;

  case 50: /* expression: expression EQ expression  */
#line 136 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("==", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1618 "parser.tab.c"
    break;

  case 51: /* expression: expression NEQ expression  */
#line 137 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("!=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1624 "parser.tab.c"
    break;

  case 52: /* expression: expression LT expression  */
#line 138 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("<", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1630 "parser.tab.c"
    break;

  case 53: /* expression: expression GT expression  */
#line 139 "parser.y"
                                      { (yyval.ast) = create_binary_op_node(">", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1636 "parser.tab.c"
    break;

  case 54: /* expression: expression LTE expression  */
#line 140 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("<=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1642 "parser.tab.c"
    break;

  case 55: /* expression: expression GTE expression  */
#line 141 "parser.y"
                                      { (yyval.ast) = create_binary_op_node(">=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1648 "parser.tab.c"
    break;

  case 56: /* expression: expression AND expression  */
#line 142 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("&&", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1654 "parser.tab.c"
    break;

  case 57: /* expression: expression OR expression  */
#line 143 "parser.y"
                                      { (yyval.ast) = create_binary_op_node("||", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1660 "parser.tab.c"
    break;

  case 58: /* expression: NOT expression  */
#line 144 "parser.y"
                                      { (yyval.ast) = create_unary_op_node("!", (yyvsp[0].ast)); }
#line 1666 "parser.tab.c"
    break;

  case 59: /* expression: LPAREN expression RPAREN  */
#line 145 "parser.y"
                                      { (yyval.ast) = (yyvsp[-1].ast); }
#line 1672 "parser.tab.c"
    break;

  case 60: /* expression: INCREMENT IDENTIFIER  */
#line 146 "parser.y"
                                      { (yyval.ast) = create_unary_op_node("++", create_identifier_node((yyvsp[0].sval))); }
#line 1678 "parser.tab.c"
    break;

  case 61: /* expression: DECREMENT IDENTIFIER  */
#line 147 "parser.y"
                                      { (yyval.ast) = create_unary_op_node("--", create_identifier_node((yyvsp[0].sval))); }
#line 1684 "parser.tab.c"
    break;

  case 62: /* expression: function_call  */
#line 148 "parser.y"
                                      { (yyval.ast) = (yyvsp[0].ast); }
#line 1690 "parser.tab.c"
    break;

  case 63: /* bool_literal: TRUE  */
#line 152 "parser.y"
                               { (yyval.ast) = create_bool_node(1); }
#line 1696 "parser.tab.c"
    break;

  case 64: /* bool_literal: FALSE  */
#line 153 "parser.y"
                               { (yyval.ast) = create_bool_node(0); }
#line 1702 "parser.tab.c"
    break;

  case 65: /* function_call: IDENTIFIER LPAREN arg_list RPAREN  */
#line 157 "parser.y"
                                           { (yyval.ast) = create_function_call_node((yyvsp[-3].sval), (yyvsp[-1].ast)); }
#line 1708 "parser.tab.c"
    break;

  case 66: /* function_call: IDENTIFIER LPAREN RPAREN  */
#line 158 "parser.y"
                                           { (yyval.ast) = create_function_call_node((yyvsp[-2].sval), NULL); }
#line 1714 "parser.tab.c"
    break;

  case 67: /* arg_list: expression  */
#line 162 "parser.y"
                                  { (yyval.ast) = create_arg_list((yyvsp[0].ast), NULL); }
#line 1720 "parser.tab.c"
    break;

  case 68: /* arg_list: expression COMMA arg_list  */
#line 163 "parser.y"
                                  { (yyval.ast) = create_arg_list((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1726 "parser.tab.c"
    break;

  case 69: /* switch_statement: SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE  */
#line 168 "parser.y"
        { (yyval.ast) = create_switch_node((yyvsp[-4].ast), (yyvsp[-1].ast)); }
#line 1732 "parser.tab.c"
    break;

  case 70: /* case_list: case_statement  */
#line 172 "parser.y"
                                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1738 "parser.tab.c"
    break;

  case 71: /* case_list: case_statement case_list  */
#line 173 "parser.y"
                                    { (yyval.ast) = create_case_list((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1744 "parser.tab.c"
    break;

  case 72: /* case_list: default_statement  */
#line 174 "parser.y"
                                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1750 "parser.tab.c"
    break;

  case 73: /* case_list: case_statement default_statement  */
#line 175 "parser.y"
                                       { (yyval.ast) = create_case_list((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1756 "parser.tab.c"
    break;

  case 74: /* case_statement: CASE NUMBER COLON statement_list  */
#line 180 "parser.y"
        { (yyval.ast) = create_case_node(create_number_node((yyvsp[-2].ival)), (yyvsp[0].ast)); }
#line 1762 "parser.tab.c"
    break;

  case 75: /* default_statement: DEFAULT COLON statement_list  */
#line 185 "parser.y"
        { (yyval.ast) = create_default_node((yyvsp[0].ast)); }
#line 1768 "parser.tab.c"
    break;

  case 76: /* if_statement: IF LPAREN expression RPAREN statement  */
#line 190 "parser.y"
        { (yyval.ast) = create_if_node((yyvsp[-2].ast), (yyvsp[0].ast), NULL); }
#line 1774 "parser.tab.c"
    break;

  case 77: /* if_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 192 "parser.y"
        { (yyval.ast) = create_if_node((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1780 "parser.tab.c"
    break;

  case 78: /* while_statement: WHILE LPAREN expression RPAREN statement  */
#line 197 "parser.y"
        { (yyval.ast) = create_while_node((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1786 "parser.tab.c"
    break;

  case 79: /* for_statement: FOR LPAREN assignment SEMICOLON expression SEMICOLON assignment RPAREN statement  */
#line 202 "parser.y"
        { (yyval.ast) = create_for_node((yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1792 "parser.tab.c"
    break;

  case 80: /* do_while_statement: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 207 "parser.y"
        { (yyval.ast) = create_do_while_node((yyvsp[-5].ast), (yyvsp[-2].ast)); }
#line 1798 "parser.tab.c"
    break;

  case 81: /* break_statement: BREAK  */
#line 211 "parser.y"
                               { (yyval.ast) = create_break_node(); }
#line 1804 "parser.tab.c"
    break;

  case 82: /* continue_statement: CONTINUE  */
#line 215 "parser.y"
                               { (yyval.ast) = create_continue_node(); }
#line 1810 "parser.tab.c"
    break;

  case 83: /* print_statement: PRINT expression  */
#line 219 "parser.y"
                               { (yyval.ast) = create_print_node((yyvsp[0].ast)); }
#line 1816 "parser.tab.c"
    break;

  case 84: /* read_statement: READ IDENTIFIER  */
#line 223 "parser.y"
                               { (yyval.ast) = create_read_node((yyvsp[0].sval)); }
#line 1822 "parser.tab.c"
    break;

  case 85: /* return_statement: RETURN expression  */
#line 227 "parser.y"
                               { (yyval.ast) = create_return_node((yyvsp[0].ast)); }
#line 1828 "parser.tab.c"
    break;

  case 86: /* return_statement: RETURN  */
#line 228 "parser.y"
                               { (yyval.ast) = create_return_node(NULL); }
#line 1834 "parser.tab.c"
    break;


#line 1838 "parser.tab.c"

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

#line 231 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_number, s);
}
