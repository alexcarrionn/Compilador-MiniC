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
#line 1 "sintactico.y"
 //parte de las declaraciones, parte en C con includes
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    //parte de los simbolos
    #include "listaSimbolos.h"
    #include "listaCodigo.h"
    Lista l; 
    Tipo t; 
    void insertarID(char *id , Tipo t, int v); 
    void imprimeLs();
    void buscarId(char *id, int variable); 
    //tabla de registros libres 
    char registrosLibres[10]; 
    //metodo inicializar registros
    void inicializaReg(); 
    //Te va a devolver el $tX
    char *obtenerReg(); 
    void liberarReg(char *reg); 

    char *concatena(char *s1,char *s2);
    bool analisis_ok(); 
     void imprimirLC(ListaC codigo); 
    //aqui la parte de los strings
    void insertarSTR(char *id); 
    int val_str;
    //Generador de etiquetas de salto
    int contador_etiq = 1; 
    char *nuevaEtiqueta(); 


    extern int yylex(); 
    extern int yylineno; 
    void yyerror(const char* msg); //es obligatorio hacerlo o implementarlo nosotros 
    
    int errores = 0;  

#line 111 "sintactico.tab.c"

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

#include "sintactico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* "id"  */
  YYSYMBOL_VAR = 4,                        /* "var"  */
  YYSYMBOL_CONST = 5,                      /* "const"  */
  YYSYMBOL_PRIN = 6,                       /* "print"  */
  YYSYMBOL_IF = 7,                         /* "if"  */
  YYSYMBOL_ELSE = 8,                       /* "else"  */
  YYSYMBOL_READ = 9,                       /* "read"  */
  YYSYMBOL_WHILE = 10,                     /* "while"  */
  YYSYMBOL_SUMA = 11,                      /* "+"  */
  YYSYMBOL_REST = 12,                      /* "-"  */
  YYSYMBOL_COMA = 13,                      /* ","  */
  YYSYMBOL_MUL = 14,                       /* "*"  */
  YYSYMBOL_DIVI = 15,                      /* "/"  */
  YYSYMBOL_PARI = 16,                      /* "("  */
  YYSYMBOL_PARD = 17,                      /* ")"  */
  YYSYMBOL_LLAI = 18,                      /* "{"  */
  YYSYMBOL_LLAD = 19,                      /* "}"  */
  YYSYMBOL_NUME = 20,                      /* "numero"  */
  YYSYMBOL_PC = 21,                        /* ";"  */
  YYSYMBOL_STR = 22,                       /* "string"  */
  YYSYMBOL_IGUAL = 23,                     /* "="  */
  YYSYMBOL_FOR = 24,                       /* "for"  */
  YYSYMBOL_DO = 25,                        /* "do"  */
  YYSYMBOL_MENOR = 26,                     /* "<"  */
  YYSYMBOL_MAYOR = 27,                     /* ">"  */
  YYSYMBOL_MENORIGUAL = 28,                /* "<="  */
  YYSYMBOL_MAYORIGUAL = 29,                /* ">="  */
  YYSYMBOL_IGUALIGUAL = 30,                /* "=="  */
  YYSYMBOL_DISTINTO = 31,                  /* "!="  */
  YYSYMBOL_UMINUS = 32,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_35_1 = 35,                      /* $@1  */
  YYSYMBOL_declarations = 36,              /* declarations  */
  YYSYMBOL_37_2 = 37,                      /* $@2  */
  YYSYMBOL_38_3 = 38,                      /* $@3  */
  YYSYMBOL_identifier_list = 39,           /* identifier_list  */
  YYSYMBOL_identifier = 40,                /* identifier  */
  YYSYMBOL_statement_list = 41,            /* statement_list  */
  YYSYMBOL_assignment = 42,                /* assignment  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_print_list = 44,                /* print_list  */
  YYSYMBOL_expr_rel = 45,                  /* expr_rel  */
  YYSYMBOL_print_item = 46,                /* print_item  */
  YYSYMBOL_read_list = 47,                 /* read_list  */
  YYSYMBOL_expression = 48                 /* expression  */
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
typedef yytype_int8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   110,   121,   121,   127,   127,   133,   136,
     138,   144,   148,   160,   165,   169,   182,   185,   186,   222,
     243,   271,   272,   273,   306,   345,   348,   349,   356,   367,
     377,   387,   397,   407,   417,   423,   446,   468,   488,   509,
     519,   528,   537,   546,   557,   558,   569
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"id\"", "\"var\"",
  "\"const\"", "\"print\"", "\"if\"", "\"else\"", "\"read\"", "\"while\"",
  "\"+\"", "\"-\"", "\",\"", "\"*\"", "\"/\"", "\"(\"", "\")\"", "\"{\"",
  "\"}\"", "\"numero\"", "\";\"", "\"string\"", "\"=\"", "\"for\"",
  "\"do\"", "\"<\"", "\">\"", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"",
  "UMINUS", "$accept", "program", "$@1", "declarations", "$@2", "$@3",
  "identifier_list", "identifier", "statement_list", "assignment",
  "statement", "print_list", "expr_rel", "print_item", "read_list",
  "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -69,    31,    17,   -69,    30,    23,    37,   -69,     0,   -69,
     -69,    53,    55,    55,    45,    46,    51,    57,    59,    65,
     -69,   -69,    68,    67,    66,   -69,    63,    -4,   -69,    11,
     -69,     3,   132,     3,    85,     3,    73,    86,   -69,   -69,
       3,    55,   -69,   -69,   -69,     3,     3,   -69,    24,   -69,
      20,   -69,    24,    76,    -1,   -69,    44,    78,   -69,    80,
      93,    24,   -69,   -69,   148,     3,     3,     3,     3,   132,
      83,   133,     3,     3,     3,     3,     3,     3,   102,    87,
     133,     3,    96,   -69,    50,    50,   -69,   -69,   -69,   -69,
      99,    24,    24,    24,    24,    24,    24,   -69,   -69,   -69,
      88,    94,   133,    86,     3,   -69,    98,   104,    95,   103,
     -69,   -69,   113,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     8,    14,     4,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     3,     0,     0,     0,    13,    11,     0,     9,     0,
      25,     0,     0,     0,     0,     0,     0,     0,    14,    16,
       0,     0,     5,     7,    45,     0,     0,    46,    15,    36,
       0,    26,    35,     0,    34,    37,     0,     0,    17,     0,
       0,    12,    10,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    39,    40,    41,    42,    27,    21,
      19,    28,    29,    32,    33,    30,    31,    38,    22,    20,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
      14,    23,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,   -69,   -69,   -69,   112,    89,   -20,   -35,
     -68,   -69,   -34,    58,   -69,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     8,    12,    13,    27,    28,    11,    24,
      25,    50,    53,    51,    56,    54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    57,    59,    90,     9,    10,    44,    48,    52,    41,
      65,    66,    99,    67,    68,    45,    61,    42,    60,    46,
       4,    63,    64,    47,    41,    72,    73,    74,    75,    76,
      77,     3,    43,    69,   105,    65,    66,    70,    67,    68,
       6,    84,    85,    86,    87,    52,     5,   100,    91,    92,
      93,    94,    95,    96,    14,     7,    15,    78,    26,    16,
      17,    79,    18,    19,    67,    68,    30,    32,   106,    31,
     107,    20,    21,    33,    14,    34,    15,    22,    23,    16,
      17,    35,    18,    19,    37,    38,    40,    39,    55,    15,
     112,    20,    58,    71,    14,    80,    15,    22,    23,    16,
      17,    81,    18,    19,    89,    97,   101,   102,    98,   103,
     104,    20,    82,   110,    14,   108,    15,    22,    23,    16,
      17,   109,    18,    19,   111,    29,     0,    88,     0,     0,
      62,    20,   113,     0,    14,    44,    15,    22,    23,    16,
      17,     0,    18,    19,    45,     0,     0,     0,    46,     0,
       0,    20,    47,     0,    49,     0,     0,    22,    23,    65,
      66,     0,    67,    68,     0,    83
};

static const yytype_int8 yycheck[] =
{
      20,    35,    37,    71,     4,     5,     3,    31,    32,    13,
      11,    12,    80,    14,    15,    12,    40,    21,    38,    16,
       3,    45,    46,    20,    13,    26,    27,    28,    29,    30,
      31,     0,    21,    13,   102,    11,    12,    17,    14,    15,
      17,    65,    66,    67,    68,    69,    16,    81,    72,    73,
      74,    75,    76,    77,     1,    18,     3,    13,     3,     6,
       7,    17,     9,    10,    14,    15,    21,    16,   103,    23,
     104,    18,    19,    16,     1,    16,     3,    24,    25,     6,
       7,    16,     9,    10,    16,    18,    23,    21,     3,     3,
     110,    18,    19,    17,     1,    17,     3,    24,    25,     6,
       7,    21,     9,    10,    21,     3,    10,     8,    21,    21,
      16,    18,    19,    18,     1,    17,     3,    24,    25,     6,
       7,    17,     9,    10,    21,    13,    -1,    69,    -1,    -1,
      41,    18,    19,    -1,     1,     3,     3,    24,    25,     6,
       7,    -1,     9,    10,    12,    -1,    -1,    -1,    16,    -1,
      -1,    18,    20,    -1,    22,    -1,    -1,    24,    25,    11,
      12,    -1,    14,    15,    -1,    17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    35,     0,     3,    16,    17,    18,    36,     4,
       5,    41,    37,    38,     1,     3,     6,     7,     9,    10,
      18,    19,    24,    25,    42,    43,     3,    39,    40,    39,
      21,    23,    16,    16,    16,    16,    41,    16,    18,    21,
      23,    13,    21,    21,     3,    12,    16,    20,    48,    22,
      44,    46,    48,    45,    48,     3,    47,    45,    19,    42,
      41,    48,    40,    48,    48,    11,    12,    14,    15,    13,
      17,    17,    26,    27,    28,    29,    30,    31,    13,    17,
      17,    21,    19,    17,    48,    48,    48,    48,    46,    21,
      43,    48,    48,    48,    48,    48,    48,     3,    21,    43,
      45,    10,     8,    21,    16,    43,    42,    45,    17,    17,
      18,    21,    41,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    35,    34,    37,    36,    38,    36,    36,    39,
      39,    40,    40,    41,    41,    42,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    44,    44,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     0,     5,     0,     5,     0,     1,
       3,     1,     3,     2,     0,     3,     2,     3,     7,     5,
       5,     5,     5,     9,    11,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* $@1: %empty  */
#line 110 "sintactico.y"
                                                             {  l = creaLS(); 
                                                                inicializaReg();
                                                             }
#line 1493 "sintactico.tab.c"
    break;

  case 3: /* program: $@1 "id" "(" ")" "{" declarations statement_list "}"  */
#line 113 "sintactico.y"
                                                             {  if (analisis_ok()){
                                                                imprimeLs();
                                                                concatenaLC((yyvsp[-2].codigo), (yyvsp[-1].codigo)); 
                                                                imprimirLC((yyvsp[-2].codigo));
                                                                liberaLC((yyvsp[-1].codigo));
                                                                liberaLC((yyvsp[-2].codigo));  } 
                                                                liberaLS(l);
                                                             }
#line 1506 "sintactico.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 121 "sintactico.y"
                                {t = VARIABLE; }
#line 1512 "sintactico.tab.c"
    break;

  case 5: /* declarations: declarations "var" $@2 identifier_list ";"  */
#line 121 "sintactico.y"
                                                                            {if(analisis_ok()){
                                                                                (yyval.codigo) = (yyvsp[-4].codigo); 
                                                                                concatenaLC((yyval.codigo), (yyvsp[-1].codigo)); 
                                                                                liberaLC((yyvsp[-1].codigo));            
                                                                            }
                                                                            }
#line 1523 "sintactico.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 127 "sintactico.y"
                                  {t = CONSTANTE; }
#line 1529 "sintactico.tab.c"
    break;

  case 7: /* declarations: declarations "const" $@3 identifier_list ";"  */
#line 127 "sintactico.y"
                                                                             {if(analisis_ok()){
                                                                                (yyval.codigo) = (yyvsp[-4].codigo); 
                                                                                concatenaLC((yyval.codigo), (yyvsp[-1].codigo)); 
                                                                                liberaLC((yyvsp[-1].codigo));            
                                                                            }
                                                                            }
#line 1540 "sintactico.tab.c"
    break;

  case 8: /* declarations: %empty  */
#line 133 "sintactico.y"
                      {if(analisis_ok())
                            (yyval.codigo) = creaLC(); }
#line 1547 "sintactico.tab.c"
    break;

  case 9: /* identifier_list: identifier  */
#line 136 "sintactico.y"
                                                           {if(analisis_ok())
                                                                (yyval.codigo) = (yyvsp[0].codigo);}
#line 1554 "sintactico.tab.c"
    break;

  case 10: /* identifier_list: identifier_list "," identifier  */
#line 138 "sintactico.y"
                                                           {if(analisis_ok()){
                                                                (yyval.codigo)=(yyvsp[-2].codigo); 
                                                                concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                                liberaLC((yyvsp[0].codigo)); 
                                                            }}
#line 1564 "sintactico.tab.c"
    break;

  case 11: /* identifier: "id"  */
#line 144 "sintactico.y"
                                                           {insertarID((yyvsp[0].cadena),t,0);
                                                            if(analisis_ok()){
                                                                (yyval.codigo) = creaLC();
                                                            }}
#line 1573 "sintactico.tab.c"
    break;

  case 12: /* identifier: "id" "=" expression  */
#line 148 "sintactico.y"
                                                           {insertarID((yyvsp[-2].cadena),t,0);
                                                                if(analisis_ok()){
                                                                    (yyval.codigo) = (yyvsp[0].codigo); 
                                                                    Operacion oper; 
                                                                    oper.op = "sw"; 
                                                                    oper.res = recuperaResLC((yyvsp[0].codigo)); 
                                                                    oper.arg1 = concatena("_", (yyvsp[-2].cadena));
                                                                    oper.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                    liberarReg(oper.res); 
                                                                }}
#line 1589 "sintactico.tab.c"
    break;

  case 13: /* statement_list: statement_list statement  */
#line 160 "sintactico.y"
                                                           { if(analisis_ok()){
                                                                (yyval.codigo) = (yyvsp[-1].codigo); 
                                                                concatenaLC((yyval.codigo), (yyvsp[0].codigo)); 
                                                            }
                                                            }
#line 1599 "sintactico.tab.c"
    break;

  case 14: /* statement_list: %empty  */
#line 165 "sintactico.y"
                                                           {if(analisis_ok())
                                                                (yyval.codigo) = creaLC(); }
#line 1606 "sintactico.tab.c"
    break;

  case 15: /* assignment: "id" "=" expression  */
#line 169 "sintactico.y"
                                                     {buscarId((yyvsp[-2].cadena), 1);
                                                    //pruebas
                                                    if(analisis_ok()){
                                                        (yyval.codigo) = (yyvsp[0].codigo);
                                                        Operacion oper;
                                                        oper.op = "sw";
                                                        oper.res = recuperaResLC((yyvsp[0].codigo));
                                                        oper.arg1 = concatena("_", (yyvsp[-2].cadena));
                                                        oper.arg2 = NULL;
                                                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                        liberarReg(oper.res);
                                                    }}
#line 1623 "sintactico.tab.c"
    break;

  case 16: /* statement: assignment ";"  */
#line 182 "sintactico.y"
                                                     { if(analisis_ok())
                                                          (yyval.codigo) = (yyvsp[-1].codigo);
                                                     }
#line 1631 "sintactico.tab.c"
    break;

  case 17: /* statement: "{" statement_list "}"  */
#line 185 "sintactico.y"
                                                             {(yyval.codigo)= (yyvsp[-1].codigo);}
#line 1637 "sintactico.tab.c"
    break;

  case 18: /* statement: "if" "(" expr_rel ")" statement "else" statement  */
#line 186 "sintactico.y"
                                                           { 
                                                            if(analisis_ok()){
                                                               char *etiqueta  = nuevaEtiqueta();
                                                               char *etiqueta2 = nuevaEtiqueta(); 
                                                               (yyval.codigo) = (yyvsp[-4].codigo); 
                                                               Operacion oper; 
                                                               oper.op = "beqz"; 
                                                               oper.res = recuperaResLC((yyvsp[-4].codigo)); 
                                                               oper.arg1 = etiqueta; 
                                                               oper.arg2 = NULL;
                                                               insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper); 
                                                               liberarReg(oper.res);
                                                               //sentecia del if 
                                                               concatenaLC((yyval.codigo), (yyvsp[-2].codigo)); 
                                                               liberaLC((yyvsp[-2].codigo));
                                                                oper.op = "j";
                                                                oper.res = etiqueta2;
                                                                oper.arg1 = oper.arg2 = NULL;
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);  
                                                                //sentencia del else
                                                                oper.op = "etiq";
                                                                oper.res = etiqueta;
                                                                oper.arg1 = NULL;
                                                                oper.arg2 = NULL;
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                                                liberaLC((yyvsp[0].codigo));
                                                                oper.op = "etiq";
                                                                oper.res = etiqueta2;
                                                                oper.arg1 = NULL;
                                                                oper.arg2 = NULL;
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                
                                                               }
                                                                }
#line 1677 "sintactico.tab.c"
    break;

  case 19: /* statement: "if" "(" expr_rel ")" statement  */
#line 222 "sintactico.y"
                                                           { if(analisis_ok()){
                                                               char *etiqueta  = nuevaEtiqueta();
                                                               (yyval.codigo) = (yyvsp[-2].codigo); 
                                                               Operacion oper; 
                                                               oper.op = "beqz"; 
                                                               oper.res = recuperaResLC((yyvsp[-2].codigo)); 
                                                               oper.arg1 = etiqueta; 
                                                               oper.arg2 = NULL;
                                                               insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper); 
                                                               liberarReg(oper.res);
                                                               //sentecia del if 
                                                               concatenaLC((yyval.codigo), (yyvsp[0].codigo)); 
                                                               liberaLC((yyvsp[0].codigo));
                                                               oper.op = "etiq"; //para poner que es una etiqueta
                                                               oper.res = etiqueta; 
                                                               oper.arg1 = NULL; 
                                                               oper.arg2 = NULL;
                                                               insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);  
                                                               }
                                                                }
#line 1702 "sintactico.tab.c"
    break;

  case 20: /* statement: "while" "(" expr_rel ")" statement  */
#line 243 "sintactico.y"
                                                           {if(analisis_ok()){
                                                                char *etiqueta = nuevaEtiqueta(); 
                                                                char *etiqueta2 = nuevaEtiqueta(); 
                                                                Operacion oper; 
                                                                oper.op = "etiq"; 
                                                                oper.res = etiqueta; 
                                                                oper.arg1 = NULL; 
                                                                oper.arg2 = NULL;
                                                                (yyval.codigo) = (yyvsp[-2].codigo); 
                                                                insertaLC((yyval.codigo), inicioLC((yyval.codigo)), oper); 
                                                                oper.op = "beqz"; 
                                                                oper.res = recuperaResLC((yyvsp[-2].codigo)); 
                                                                oper.arg1 = etiqueta2; 
                                                                oper.arg2 = NULL; 
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper); 
                                                                liberarReg(oper.res); 
                                                                concatenaLC((yyval.codigo), (yyvsp[0].codigo)); 
                                                                liberaLC((yyvsp[0].codigo)); 
                                                                oper.op = "j"; 
                                                                oper.res = etiqueta; 
                                                                oper.arg1 = oper.arg2 = NULL; 
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper); 
                                                                oper.op = "etiq"; 
                                                                oper.res = etiqueta2; 
                                                                oper.arg1 = oper.arg2 = NULL; 
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper); 
                                                            }    
                                                            }
#line 1735 "sintactico.tab.c"
    break;

  case 21: /* statement: "print" "(" print_list ")" ";"  */
#line 271 "sintactico.y"
                                                                { if(analisis_ok()){(yyval.codigo) = (yyvsp[-2].codigo);} }
#line 1741 "sintactico.tab.c"
    break;

  case 22: /* statement: "read" "(" read_list ")" ";"  */
#line 272 "sintactico.y"
                                                                  { if(analisis_ok()){(yyval.codigo) = (yyvsp[-2].codigo);} }
#line 1747 "sintactico.tab.c"
    break;

  case 23: /* statement: "do" "{" statement_list "}" "while" "(" expr_rel ")" ";"  */
#line 273 "sintactico.y"
                                                                { 
                                                                   if (analisis_ok()) {
                                                                    (yyval.codigo)=(yyvsp[-6].codigo); 
                                                                    char *etiquetaInicio = nuevaEtiqueta();
                                                                    char *etiquetaFin = nuevaEtiqueta();

                                                                    // Insertar etiqueta de inicio del bucle
                                                                    Operacion oper;
                                                                    oper.op = "etiq";
                                                                    oper.res = etiquetaInicio;
                                                                    oper.arg1 = NULL;
                                                                    oper.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), inicioLC((yyval.codigo)), oper);
                                                                    // Insertar condición de salida
                                                                    oper.op = "beqz";
                                                                    oper.res = recuperaResLC((yyvsp[-2].codigo)); // Condición
                                                                    oper.arg1 = etiquetaFin; // Etiqueta de fin del bucle
                                                                    oper.arg2 = NULL;
                                                                    concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                    liberarReg(oper.res);
                                                                    // Volver al inicio del bucle
                                                                    oper.op = "j";
                                                                    oper.res = etiquetaInicio; // Etiqueta de inicio del bucle
                                                                    oper.arg1 = oper.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                    // Insertar etiqueta de fin del bucle
                                                                    oper.op = "etiq";
                                                                    oper.res = etiquetaFin;
                                                                    oper.arg1 = oper.arg2 = NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                    }
                                                                    }
#line 1785 "sintactico.tab.c"
    break;

  case 24: /* statement: "for" "(" assignment ";" expr_rel ";" assignment ")" "{" statement_list "}"  */
#line 306 "sintactico.y"
                                                                            {
    if (analisis_ok()) {
       (yyval.codigo) = creaLC();
        char *indice = obtenerReg();
        concatenaLC((yyval.codigo), (yyvsp[-8].codigo));  // Código de la inicialización
        // Etiqueta de inicio del bucle
        char *etiquetaInicio = nuevaEtiqueta();
        char *etiquetaFin = nuevaEtiqueta();
        Operacion oper;
        oper.op = "etiq";
        oper.res = etiquetaInicio;
        oper.arg1 = NULL;
        oper.arg2 = NULL;
        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
        // Condición de salida
        concatenaLC((yyval.codigo), (yyvsp[-6].codigo)); // Código de la condición
        oper.op = "beqz";
        oper.res = recuperaResLC((yyvsp[-6].codigo)); 
        oper.arg1 = etiquetaFin; 
        oper.arg2 = NULL;
        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
        // Cuerpo del bucle
        concatenaLC((yyval.codigo), (yyvsp[-1].codigo)); // Código del cuerpo del bucle
        // Incremento
        concatenaLC((yyval.codigo), (yyvsp[-4].codigo)); // Código del incremento
        oper.op = "j";
        oper.res = etiquetaInicio;
        oper.arg1 = oper.arg2 = NULL;
        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
        oper.op = "etiq";
        oper.res = etiquetaFin;
        oper.arg1 = oper.arg2 = NULL;
        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
        liberarReg(indice);
    }
}
#line 1826 "sintactico.tab.c"
    break;

  case 25: /* statement: error ";"  */
#line 345 "sintactico.y"
                                                                {(yyval.codigo) = creaLC();
                                                                errores++;}
#line 1833 "sintactico.tab.c"
    break;

  case 26: /* print_list: print_item  */
#line 348 "sintactico.y"
                                                             { (yyval.codigo) = (yyvsp[0].codigo);}
#line 1839 "sintactico.tab.c"
    break;

  case 27: /* print_list: print_list "," print_item  */
#line 349 "sintactico.y"
                                                             {  if (analisis_ok()) {
                                                                (yyval.codigo) = (yyvsp[-2].codigo); 
                                                                concatenaLC((yyval.codigo), (yyvsp[0].codigo)); 
                                                                liberaLC((yyvsp[0].codigo)); }
                                                                }
#line 1849 "sintactico.tab.c"
    break;

  case 28: /* expr_rel: expression "<" expression  */
#line 356 "sintactico.y"
                                        {   if(analisis_ok()){
                                                                (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                                Operacion oper; oper.op = "slt"; 
                                                                oper.res = recuperaResLC((yyvsp[-2].codigo));
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC((yyvsp[0].codigo));
                                                              }
                                            }
#line 1865 "sintactico.tab.c"
    break;

  case 29: /* expr_rel: expression ">" expression  */
#line 367 "sintactico.y"
                                       { if(analisis_ok()){
                                                             (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                            Operacion oper; oper.op = "sgt"; 
                                                            oper.res = recuperaResLC((yyvsp[-2].codigo));
                                                            oper.arg1 = oper.res;  
                                                            oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                                            insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                                            liberarReg(oper.arg2);
                                                            liberaLC((yyvsp[0].codigo));}
                                        }
#line 1880 "sintactico.tab.c"
    break;

  case 30: /* expr_rel: expression "==" expression  */
#line 377 "sintactico.y"
                                        {if(analisis_ok()){
                                            (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                            Operacion oper; oper.op = "seq"; 
                                            oper.res = recuperaResLC((yyvsp[-2].codigo));
                                            oper.arg1 = oper.res;  
                                            oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                            insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                            liberarReg(oper.arg2);
                                            liberaLC((yyvsp[0].codigo));}
                                        }
#line 1895 "sintactico.tab.c"
    break;

  case 31: /* expr_rel: expression "!=" expression  */
#line 387 "sintactico.y"
                                        {if(analisis_ok()){
                                            (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                                Operacion oper; oper.op = "sne"; 
                                                                oper.res = recuperaResLC((yyvsp[-2].codigo));
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC((yyvsp[0].codigo));}
                                        }
#line 1910 "sintactico.tab.c"
    break;

  case 32: /* expr_rel: expression "<=" expression  */
#line 397 "sintactico.y"
                                        {if(analisis_ok()){
                                            (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                                Operacion oper; oper.op = "sle"; 
                                                                oper.res = recuperaResLC((yyvsp[-2].codigo));
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC((yyvsp[0].codigo));}
                                        }
#line 1925 "sintactico.tab.c"
    break;

  case 33: /* expr_rel: expression ">=" expression  */
#line 407 "sintactico.y"
                                         {if(analisis_ok()){
                                           (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                                Operacion oper; oper.op = "sge"; 
                                                                oper.res = recuperaResLC((yyvsp[-2].codigo));
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC((yyvsp[0].codigo));}
                                        }
#line 1940 "sintactico.tab.c"
    break;

  case 34: /* expr_rel: expression  */
#line 417 "sintactico.y"
                                                              {if(analisis_ok()){
                                                                (yyval.codigo) = (yyvsp[0].codigo); 
                                                            }}
#line 1948 "sintactico.tab.c"
    break;

  case 35: /* print_item: expression  */
#line 423 "sintactico.y"
                                                             {
                                                                if(analisis_ok()){
                                                                    (yyval.codigo)= (yyvsp[0].codigo); 
                                                                    Operacion oper; 
                                                                    oper.op = "li"; 
                                                                    oper.res = "$v0"; 
                                                                    oper.arg1 = "1"; 
                                                                    oper.arg2 = NULL; 
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper); 
                                                                    oper.op = "move"; 
                                                                    oper.res = "$a0";
                                                                    oper.arg1 = recuperaResLC((yyvsp[0].codigo)); 
                                                                    oper.arg2  =NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper); 
                                                                    
                                                                    liberarReg(oper.arg1); 

                                                                    oper.op = "syscall"; 
                                                                    oper.res = oper.arg1 = oper.arg2 = NULL; 
                                                                    insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper); 

                                                                    
                                                                }}
#line 1976 "sintactico.tab.c"
    break;

  case 36: /* print_item: "string"  */
#line 446 "sintactico.y"
                                                             {insertarSTR((yyvsp[0].cadena));
                                                                if(analisis_ok()){
                                                                    (yyval.codigo)= creaLC(); 
                                                                    Operacion oper; 
                                                                    oper.op = "li"; 
                                                                    oper.res = "$v0"; 
                                                                    oper.arg1 = "4"; 
                                                                    oper.arg2 = NULL; 
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper); 
                                                                    oper.op = "la"; 
                                                                    oper.res = "$a0";
                                                                    char *str; 
                                                                    asprintf(&str,"$str%d",val_str-1); 
                                                                    oper.arg1 = str; 
                                                                    oper.arg2  =NULL;
                                                                    insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper); 
                                                                    
                                                                    oper.op = "syscall"; 
                                                                    oper.res = oper.arg1 = oper.arg2 = NULL; 
                                                                    insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper); 
                                                                }}
#line 2002 "sintactico.tab.c"
    break;

  case 37: /* read_list: "id"  */
#line 468 "sintactico.y"
                                                             {buscarId((yyvsp[0].cadena), 1);

                                                                if(analisis_ok()){
                                                                (yyval.codigo) = creaLC(); 
                                                                Operacion oper;
                                                                oper.op = "li";
                                                                oper.res = "$v0"; 
                                                                oper.arg1 = "5"; 
                                                                oper.arg2 = NULL;
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                oper.op = "syscall"; 
                                                                oper.res = oper.arg1 = oper.arg2 = NULL; 
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper);
                                                                oper.op = "sw"; 
                                                                oper.res = "$v0";
                                                                oper.arg1 = concatena("_", (yyvsp[0].cadena));
                                                                oper.arg2 = NULL;
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                liberarReg(oper.res); 
                                                                }}
#line 2027 "sintactico.tab.c"
    break;

  case 38: /* read_list: read_list "," "id"  */
#line 488 "sintactico.y"
                                                             {buscarId((yyvsp[0].cadena), 1);
                                                            if(analisis_ok()){
                                                                (yyval.codigo) = (yyvsp[-2].codigo); 
                                                                Operacion oper;
                                                                oper.op = "li";
                                                                oper.res = "$v0"; 
                                                                oper.arg1 = "5"; 
                                                                oper.arg2 = NULL;
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                oper.op = "syscall"; 
                                                                oper.res = oper.arg1 = oper.arg2 = NULL; 
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper);
                                                                oper.op = "sw"; 
                                                                oper.res = "$v0";
                                                                oper.arg1 = concatena("_", (yyvsp[0].cadena));
                                                                oper.arg2 = NULL;
                                                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                                                                liberarReg(oper.res); 
                                                            }
                                                            }
#line 2052 "sintactico.tab.c"
    break;

  case 39: /* expression: expression "+" expression  */
#line 509 "sintactico.y"
                                                              { if(analisis_ok()){
                                                                 (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                                Operacion oper; oper.op = "add"; 
                                                                oper.res = recuperaResLC((yyvsp[-2].codigo));
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC((yyvsp[0].codigo));}
                                                                }
#line 2067 "sintactico.tab.c"
    break;

  case 40: /* expression: expression "-" expression  */
#line 519 "sintactico.y"
                                                             { if(analisis_ok()){
                                                                 (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                                Operacion oper; oper.op = "sub"; 
                                                                oper.res = recuperaResLC((yyvsp[-2].codigo));
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC((yyvsp[0].codigo));}}
#line 2081 "sintactico.tab.c"
    break;

  case 41: /* expression: expression "*" expression  */
#line 528 "sintactico.y"
                                                             {if(analisis_ok()){
                                                                 (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                                Operacion oper; oper.op = "mul"; 
                                                                oper.res = recuperaResLC((yyvsp[-2].codigo));
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC((yyvsp[0].codigo));}}
#line 2095 "sintactico.tab.c"
    break;

  case 42: /* expression: expression "/" expression  */
#line 537 "sintactico.y"
                                                             {if(analisis_ok()){
                                                                 (yyval.codigo) = (yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo)); 
                                                                Operacion oper; oper.op = "div"; 
                                                                oper.res = recuperaResLC((yyvsp[-2].codigo));
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC((yyvsp[0].codigo));}}
#line 2109 "sintactico.tab.c"
    break;

  case 43: /* expression: "-" expression  */
#line 546 "sintactico.y"
                                                                {
                                                                    if(analisis_ok()){
                                                                        (yyval.codigo) = (yyvsp[0].codigo);
                                                                        Operacion op; 
                                                                        op.op = "neg";
                                                                        op.res = recuperaResLC((yyvsp[0].codigo));
                                                                        op.arg1 = recuperaResLC((yyvsp[0].codigo));
                                                                        op.arg2 = NULL; 
                                                                        insertaLC((yyval.codigo), finalLC((yyval.codigo)),op);  
                                                                    }
                                                                }
#line 2125 "sintactico.tab.c"
    break;

  case 44: /* expression: "(" expression ")"  */
#line 557 "sintactico.y"
                                                             { (yyval.codigo) = (yyvsp[-1].codigo); }
#line 2131 "sintactico.tab.c"
    break;

  case 45: /* expression: "id"  */
#line 558 "sintactico.y"
                                                             {  if(analisis_ok()){
                                                                buscarId((yyvsp[0].cadena), 0);
                                                                (yyval.codigo) = creaLC();
                                                                Operacion oper;
                                                                oper.op = "lw";
                                                                oper.res = obtenerReg();
                                                                oper.arg1 = concatena("_",(yyvsp[0].cadena));
                                                                oper.arg2 = NULL;
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
                                                                guardaResLC((yyval.codigo), oper.res); }}
#line 2146 "sintactico.tab.c"
    break;

  case 46: /* expression: "numero"  */
#line 569 "sintactico.y"
                                                             {  if(analisis_ok()){
                                                                (yyval.codigo) = creaLC(); 
                                                                Operacion operacion; 
                                                                operacion.op = "li"; 
                                                                operacion.res = obtenerReg(); 
                                                                operacion.arg1 = (yyvsp[0].cadena); 
                                                                operacion.arg2 = NULL; 
                                                                insertaLC((yyval.codigo),finalLC((yyval.codigo)),operacion);
                                                                guardaResLC((yyval.codigo), operacion.res); }
                                                             }
#line 2161 "sintactico.tab.c"
    break;


#line 2165 "sintactico.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 582 "sintactico.y"


void yyerror(const char* msg){
    fprintf(stderr,"Error en línea %d: %s\n", yylineno, msg); 
}
 
void insertarID(char *id, Tipo t, int v) {
    PosicionLista p = buscaLS(l,id);
if (p == finalLS(l)) {
    //para el string se usa esto , tipo cadena, valor numero que incrementa y el nombre $1
    Simbolo aux;
    aux.nombre = id;
    aux.tipo = t;
    aux.valor=v; 
    insertaLS(l,finalLS(l),aux);}
else{
    printf("Error: %s ya esta declado en la linea %d\n", id, yylineno); 
    errores++;
}
}


void imprimeLs(){
  printf(".data\n");
  PosicionLista p = inicioLS(l);
  while (p != finalLS(l)) {
    Simbolo aux = recuperaLS(l,p);
    if(aux.tipo == VARIABLE || aux.tipo == CONSTANTE)
         printf("\t_%s : .word %d\n",aux.nombre,aux.valor);
    else 
        printf("\t$str%d : .asciiz %s\n",aux.valor,aux.nombre);   
    p = siguienteLS(l,p);
  }
}

void buscarId(char *id, int variable){
PosicionLista p = buscaLS(l,id);
if (p != finalLS(l)) {
    if (variable == 1){
        Simbolo aux = recuperaLS(l,p);  
        if(aux.tipo != VARIABLE){
            errores++; 
            printf("Error: %s es constante en la linea %d\n", id, yylineno); 
        }
    }
}else{
    errores++; 
    printf("Error: %s no declarado en la linea %d\n", id, yylineno); 
}

}

//String

void insertarSTR(char *id){
    //para el string se usa esto , tipo cadena, valor numero que incrementa y el nombre $1
    Simbolo aux;
    aux.nombre = id;
    aux.tipo = CADENA;
    aux.valor= val_str++; 
    insertaLS(l,finalLS(l),aux);
}

    void inicializaReg(){
        for (int i = 0; i<10; i++){
            registrosLibres[i]=0; 
        }
    }
    //Te va a devolver el $tX
    char *obtenerReg(){
         for (int i = 0; i<10; i++){
            if(registrosLibres[i] == 0){
                registrosLibres[i] = 1; 
                char *reg; 
                asprintf(&reg, "$t%d", i) ;//le digo la posicion de memoria del puntero, se genera en memoria dinamica
                return reg; 
            }
        }
        printf("Error: los registros ya se han llenado todos! \n");
        exit(1);  
    } 
    void liberarReg(char *reg){
        int indice = atoi(&(reg[2])); //pasa de un caracter a entero
        registrosLibres[indice]=0;  
    }

    bool analisis_ok(){
        return errores==0; 
    }

    char *concatena(char *s1,char *s2){
        char *aux; 
        asprintf(&aux, "%s%s", s1, s2); 
        return aux;  
    }

    //Imprimir la lista del codigo 
    void imprimirLC(ListaC codigo1){
        printf(".text\n.globl main\n main: \n"); 
        Operacion oper; 
        PosicionListaC p = inicioLC(codigo1);
         while (p != finalLC(codigo1)) {
            oper = recuperaLC(codigo1,p);
            if(!strcmp(oper.op, "etiq")){
                printf(" %s:",oper.res);
            }else{
            printf("\t%s",oper.op);
            if (oper.res) printf(" %s",oper.res);
                if (oper.arg1) printf(",%s",oper.arg1);
                    if (oper.arg2) printf(",%s",oper.arg2);
            }

                     printf("\n");
                    p = siguienteLC(codigo1,p);
        }
        printf("\tli $v0 , 10\n\tsyscall\n"); 
    }


    char *nuevaEtiqueta() {
        char *aux;
        asprintf(&aux,"$l%d",contador_etiq++);
        return aux;
    }
