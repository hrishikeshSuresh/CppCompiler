/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "icg_grammar.y" /* yacc.c:339  */

	#include<stdio.h>
	#include<string.h>
	#include<bits/stdc++.h>
	using namespace std;
	void yyerror(const char *s);
	extern int yylineno;
	extern char* yytext;
	int yylex();
	//int yywrap();
	
	extern int lineno;
	int list_declr_flag = 0;
	int type;
	int iset=0,fset=0,sset=0,cset=0;
	void reset_globals();
	void check_exists(char* str, int a);

	char* temp_func();
	int temp=0;
	char* ret;
	int label = 0;
	int global_next=0;
	int args_count=0;
	char* label_func();
	char* global_func();
	vector < map<string,string> > v;

#line 95 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INCLUDE = 258,
    T_IDH = 259,
    T_TYPE = 260,
    T_RETURN = 261,
    T_COUT = 262,
    T_CIN = 263,
    T_IDENTIFIER = 264,
    T_ADDEQ = 265,
    T_MINEQ = 266,
    T_MULEQ = 267,
    T_DIVEQ = 268,
    T_FOR = 269,
    T_IF = 270,
    T_ELSE = 271,
    T_LTEQ = 272,
    T_GTEQ = 273,
    T_NEQEQ = 274,
    T_EQEQ = 275,
    T_OROR = 276,
    T_ANDAND = 277,
    T_OR = 278,
    T_AND = 279,
    T_XOR = 280,
    T_LRSHIFT = 281,
    T_LLSHIFT = 282,
    T_WHILE = 283,
    T_MAIN = 284,
    T_STRING = 285,
    T_STRUCT = 286,
    T_CLASS = 287,
    T_PRIVATE = 288,
    T_PUBLIC = 289,
    T_PROTECTED = 290,
    T_ADDADD = 291,
    T_MINMIN = 292,
    T_STRING_VAL = 293,
    T_CHAR_VAL = 294,
    T_INTEGER_VAL = 295,
    T_FLOAT_VAL = 296
  };
#endif
/* Tokens.  */
#define T_INCLUDE 258
#define T_IDH 259
#define T_TYPE 260
#define T_RETURN 261
#define T_COUT 262
#define T_CIN 263
#define T_IDENTIFIER 264
#define T_ADDEQ 265
#define T_MINEQ 266
#define T_MULEQ 267
#define T_DIVEQ 268
#define T_FOR 269
#define T_IF 270
#define T_ELSE 271
#define T_LTEQ 272
#define T_GTEQ 273
#define T_NEQEQ 274
#define T_EQEQ 275
#define T_OROR 276
#define T_ANDAND 277
#define T_OR 278
#define T_AND 279
#define T_XOR 280
#define T_LRSHIFT 281
#define T_LLSHIFT 282
#define T_WHILE 283
#define T_MAIN 284
#define T_STRING 285
#define T_STRUCT 286
#define T_CLASS 287
#define T_PRIVATE 288
#define T_PUBLIC 289
#define T_PROTECTED 290
#define T_ADDADD 291
#define T_MINMIN 292
#define T_STRING_VAL 293
#define T_CHAR_VAL 294
#define T_INTEGER_VAL 295
#define T_FLOAT_VAL 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "icg_grammar.y" /* yacc.c:355  */

    	char cval;
		int ival;
		float fval;
		char *sval;
		//valtypes *allval;
		struct{
			char* next;
			char code[1500];
			char addr[50]; 
			char* true_label;
			char* false_label;
		}node;		

#line 232 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 249 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  85
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    48,     2,     2,     2,     2,
      42,    43,    45,    44,    52,    46,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    51,
      49,    55,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    79,    80,    89,    90,    95,   102,   103,
     106,   110,   114,   118,   124,   135,   142,   146,   151,   156,
     163,   169,   177,   182,   189,   193,   199,   208,   214,   218,
     224,   225,   226,   227,   230,   231,   234,   252,   253,   256,
     259,   260,   263,   265,   267,   272,   279,   283,   291,   295,
     301,   306,   308,   309,   312,   313,   316,   317,   320,   321,
     324,   325,   328,   329,   330,   333,   334,   337,   338,   339,
     342,   346,   350,   354,   360,   364,   371,   372,   378,   394,
     410,   415,   422,   440,   449,   463,   478,   482,   488,   496,
     508,   521,   528,   532,   538,   542,   549,   557,   563,   569,
     575,   579,   585,   592,   600,   604,   608,   612,   618,   623,
     640,   657,   676,   680,   684,   688,   692,   698,   702,   706,
     710,   714,   718,   724,   728,   734,   739,   755,   771,   772,
     775,   780,   797,   816,   821,   826,   830,   835,   840,   845,
     852,   856,   863,   868,   875,   876
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INCLUDE", "T_IDH", "T_TYPE",
  "T_RETURN", "T_COUT", "T_CIN", "T_IDENTIFIER", "T_ADDEQ", "T_MINEQ",
  "T_MULEQ", "T_DIVEQ", "T_FOR", "T_IF", "T_ELSE", "T_LTEQ", "T_GTEQ",
  "T_NEQEQ", "T_EQEQ", "T_OROR", "T_ANDAND", "T_OR", "T_AND", "T_XOR",
  "T_LRSHIFT", "T_LLSHIFT", "T_WHILE", "T_MAIN", "T_STRING", "T_STRUCT",
  "T_CLASS", "T_PRIVATE", "T_PUBLIC", "T_PROTECTED", "T_ADDADD",
  "T_MINMIN", "T_STRING_VAL", "T_CHAR_VAL", "T_INTEGER_VAL", "T_FLOAT_VAL",
  "'('", "')'", "'+'", "'*'", "'-'", "'/'", "'#'", "'<'", "'>'", "';'",
  "','", "'['", "']'", "'='", "'{'", "'}'", "':'", "$accept", "P",
  "program", "external_declaration", "header_stmt", "global_stmt",
  "main_fun", "declaration_statement", "list_identifier", "variable",
  "array", "init", "var_init", "array_init", "values", "constant",
  "declarator", "fun_declr", "params_list", "params", "compound_stmt",
  "start_paren", "end_paren", "block_item_list", "block_item",
  "user_defined_ds", "class", "structure", "class_body_stmt",
  "struct_body_stmt", "struct_mems", "class_mems", "struct_mem",
  "class_mem", "class_var_declaration", "access_specifier", "statement",
  "expression_stmt", "if_stack", "if_else_stack", "selection_statement",
  "iterative_statement", "for_stack", "for_loop", "for_assgn_stmt",
  "for_decl_stmt", "while_stack", "while_loop", "return_stmt",
  "expression", "assignment_expression", "unary_exprn",
  "postfix_expression", "uop_shorthd", "simple_expression", "bitop",
  "relop", "logop", "additive_expression", "term", "factor", "call",
  "args", "input_output_statements", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    40,    41,    43,    42,    45,    47,    35,    60,
      62,    59,    44,    91,    93,    61,   123,   125,    58
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     116,     2,   156,     3,   -10,    16,   -18,    24,    46,    31,
      87,    98,   104,  -126,  -126,  -126,  -126,   210,    97,    97,
     123,  -126,  -126,   127,   116,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,    36,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,    78,  -126,  -126,  -126,  -126,   240,   -28,
    -126,  -126,  -126,   -33,    90,    39,  -126,  -126,  -126,  -126,
    -126,    89,   210,   133,  -126,  -126,  -126,  -126,  -126,  -126,
     197,   210,   210,   109,  -126,  -126,    93,    93,  -126,  -126,
     108,   117,  -126,  -126,     6,  -126,  -126,   152,  -126,  -126,
    -126,    36,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,    -3,    -3,  -126,  -126,
      97,    97,    97,    -3,    -3,    54,   130,   210,    -7,    93,
     120,  -126,   152,  -126,   122,   125,  -126,   119,   134,  -126,
    -126,   169,    73,   128,  -126,   210,   210,     0,   129,    -1,
     135,  -126,  -126,   177,    26,  -126,  -126,   -28,   -28,   -21,
     -21,   -21,  -126,  -126,   178,  -126,   136,   146,   149,  -126,
     165,   153,  -126,    93,  -126,  -126,  -126,  -126,   210,  -126,
     166,   171,  -126,   181,   182,   199,  -126,  -126,  -126,     0,
    -126,  -126,   217,  -126,  -126,  -126,  -126,  -126,    -1,  -126,
     170,  -126,   179,  -126,   226,  -126,  -126,   188,    64,  -126,
    -126,   210,   235,   210,   176,   176,  -126,  -126,   203,    60,
    -126,  -126,  -126,  -126,   244,  -126,  -126,  -126,  -126,  -126,
     -39,  -126,  -126,   200,   221,   257,  -126,  -126,   265,  -126,
      64,  -126,   210,    58,  -126,  -126,  -126,  -126,   258,   232,
     176,   176,  -126,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,   138,   139,   136,   137,     0,     0,     0,
       0,    76,    42,     0,     2,     3,     5,     6,     7,    10,
      11,    71,     0,    12,    48,    49,    13,    70,    73,    72,
      82,    83,    75,     0,    94,    97,   100,    95,   108,   125,
     130,   135,    74,    20,     0,     0,    19,    18,    24,    25,
      92,     0,     0,     0,   104,   105,   106,   107,   102,   103,
       0,     0,     0,     0,    78,    90,     0,     0,    98,    99,
       0,   134,   128,   129,     0,     1,     4,     0,    43,    46,
      40,     0,    44,    47,    77,   119,   120,   121,   122,   123,
     124,   112,   113,   114,   115,   116,     0,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,    15,     0,    93,     0,     0,   140,   142,     0,    96,
     101,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,   133,     9,     0,    20,    41,    45,   126,   127,   111,
     109,   110,   131,   132,     0,    34,    39,     0,     0,    26,
       0,     0,    36,     0,    16,    17,   144,   145,     0,   141,
       0,    86,    84,     0,     0,     0,    60,    61,    54,     0,
      56,    51,     0,    67,    68,    69,    63,    52,     0,    58,
       0,    50,     0,    37,     0,    35,    23,     0,     0,    14,
     143,     0,     0,     0,     0,     0,    55,    57,    65,     0,
      53,    59,    64,     8,     0,    22,    31,    32,    30,    33,
       0,    29,    88,     0,     0,    80,    91,    62,     0,    38,
       0,    27,     0,     0,    79,    66,    28,    89,     0,     0,
       0,     0,    81,    85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,   252,  -126,  -126,  -126,   -29,  -126,   155,
    -126,   157,  -126,  -126,  -126,    48,  -126,  -125,  -126,  -126,
     -98,    40,   -90,  -126,   189,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,   102,    94,  -126,  -126,   -30,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,    -2,
     212,    50,  -126,  -126,  -126,  -126,  -126,  -126,   -11,    13,
      55,  -126,   124,  -126
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    26,    27,    28,    29,    55,    56,
     118,    57,    58,    59,   220,   221,   119,    30,   156,   157,
      31,    32,    90,    91,    92,    33,    34,    35,   140,   138,
     179,   188,   180,   189,   209,   190,    36,    37,   135,   240,
      38,    39,   203,    40,   133,   171,   136,    41,    42,    43,
      44,    45,    46,    72,    47,   110,   111,   112,    48,    49,
      50,    51,   128,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,   145,    93,    89,   182,   175,    81,    82,    83,   115,
     142,    53,   177,   230,   186,    80,    63,   113,   231,   114,
     116,   162,   117,   106,    73,   107,    64,    65,    66,    67,
      62,    54,   183,   184,   185,    13,    14,    15,    16,    17,
      76,    87,     2,     3,     4,     5,   160,   178,   161,   187,
       6,     7,    68,    69,   177,   143,    88,    88,    70,   154,
     124,    93,    89,   186,     8,   199,    74,   238,   127,   129,
     130,    71,    11,    12,    13,    14,    15,    16,    17,   116,
      18,   117,    19,    64,    65,    66,    67,    21,    75,   206,
     121,   122,    22,    88,    11,    12,    77,   155,   210,   149,
     150,   151,   216,   217,   218,   219,    81,    78,   176,    68,
      69,   227,   228,    79,   131,   159,   137,   139,   132,   147,
     148,     1,     2,     3,     4,     5,    84,    85,    71,    94,
       6,     7,   120,   173,   174,    13,    14,    15,    16,    17,
     123,    18,   125,    19,     8,    11,    12,     9,    10,    22,
     176,   141,    11,    12,    13,    14,    15,    16,    17,    70,
      18,   144,    19,   163,    20,     5,   127,    21,   152,   153,
     158,   168,    22,   166,   225,   226,   167,   169,   170,   172,
     181,   192,     2,     3,     4,     5,   191,   193,   194,   195,
       6,     7,    11,    12,    13,    14,    15,    16,    17,   222,
      18,   224,    19,   196,     8,   197,     5,    60,    53,   198,
     242,   243,    11,    12,    13,    14,    15,    16,    17,     5,
      18,   201,    19,   202,   204,   205,   208,    21,   212,   213,
     237,   214,    22,    11,    12,    13,    14,    15,    16,    17,
     126,    18,   215,    19,   223,   115,    11,    12,    13,    14,
      15,    16,    17,   229,    18,   232,    19,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    64,    65,
      66,    67,   233,   234,   235,   241,    86,   164,   236,   165,
     146,   207,   211,   239,   106,   134,   107,     0,     0,   108,
     109,     0,   200,     0,    68,    69
};

static const yytype_int16 yycheck[] =
{
       2,    91,    32,    32,     5,     5,     9,    18,    19,    42,
       4,     9,   137,    52,   139,    17,    26,    45,    57,    47,
      53,   119,    55,    44,    42,    46,    10,    11,    12,    13,
      27,    29,    33,    34,    35,    38,    39,    40,    41,    42,
       9,     5,     6,     7,     8,     9,    53,   137,    55,   139,
      14,    15,    36,    37,   179,    49,    57,    57,    42,     5,
      62,    91,    91,   188,    28,   163,    42,     9,    70,    71,
      72,    55,    36,    37,    38,    39,    40,    41,    42,    53,
      44,    55,    46,    10,    11,    12,    13,    51,    42,   179,
      51,    52,    56,    57,    36,    37,     9,    43,   188,   110,
     111,   112,    38,    39,    40,    41,     9,     9,   137,    36,
      37,    51,    52,     9,     5,   117,    76,    77,     9,   106,
     107,     5,     6,     7,     8,     9,     3,     0,    55,    51,
      14,    15,    42,   135,   136,    38,    39,    40,    41,    42,
      51,    44,     9,    46,    28,    36,    37,    31,    32,    56,
     179,    43,    36,    37,    38,    39,    40,    41,    42,    42,
      44,     9,    46,    43,    48,     9,   168,    51,   113,   114,
      40,    52,    56,    51,   204,   205,    51,    43,     9,    51,
      51,     4,     6,     7,     8,     9,    51,     9,    52,    43,
      14,    15,    36,    37,    38,    39,    40,    41,    42,   201,
      44,   203,    46,    54,    28,    40,     9,    51,     9,    56,
     240,   241,    36,    37,    38,    39,    40,    41,    42,     9,
      44,    55,    46,    52,    43,    43,     9,    51,    58,    50,
     232,     5,    56,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    54,    46,     9,    42,    36,    37,    38,    39,
      40,    41,    42,     9,    44,    55,    46,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    10,    11,
      12,    13,    51,    16,     9,    43,    24,   122,   230,   122,
      91,   179,   188,   233,    44,    73,    46,    -1,    -1,    49,
      50,    -1,   168,    -1,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    14,    15,    28,    31,
      32,    36,    37,    38,    39,    40,    41,    42,    44,    46,
      48,    51,    56,    60,    61,    62,    63,    64,    65,    66,
      76,    79,    80,    84,    85,    86,    95,    96,    99,   100,
     102,   106,   107,   108,   109,   110,   111,   113,   117,   118,
     119,   120,   122,     9,    29,    67,    68,    70,    71,    72,
      51,   108,    27,    26,    10,    11,    12,    13,    36,    37,
      42,    55,   112,    42,    42,    42,     9,     9,     9,     9,
     108,     9,   117,   117,     3,     0,    62,     5,    57,    66,
      81,    82,    83,    95,    51,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    44,    46,    49,    50,
     114,   115,   116,    45,    47,    42,    53,    55,    69,    75,
      42,    51,    52,    51,   108,     9,    43,   108,   121,   108,
     108,     5,     9,   103,   109,    97,   105,    80,    88,    80,
      87,    43,     4,    49,     9,    81,    83,   118,   118,   117,
     117,   117,   119,   119,     5,    43,    77,    78,    40,   108,
      53,    55,    79,    43,    68,    70,    51,    51,    52,    43,
       9,   104,    51,   108,   108,     5,    66,    76,    81,    89,
      91,    51,     5,    33,    34,    35,    76,    81,    90,    92,
      94,    51,     4,     9,    52,    43,    54,    40,    56,    79,
     121,    55,    52,   101,    43,    43,    81,    91,     9,    93,
      81,    92,    58,    50,     5,    54,    38,    39,    40,    41,
      73,    74,   108,     9,   108,    95,    95,    51,    52,     9,
      52,    57,    55,    51,    16,     9,    74,   108,     9,   110,
      98,    43,    95,    95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    65,    66,    67,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    72,    73,    73,
      74,    74,    74,    74,    75,    75,    76,    77,    77,    78,
      79,    79,    80,    81,    82,    82,    83,    83,    84,    84,
      85,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    96,    96,    97,    98,
      99,    99,   100,   100,   101,   102,   103,   103,   104,   104,
     105,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   111,   111,   112,   112,   112,   112,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   115,   115,   115,
     115,   115,   115,   116,   116,   117,   117,   117,   117,   117,
     118,   118,   118,   119,   119,   119,   119,   119,   119,   119,
     120,   120,   121,   121,   122,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     5,     3,
       1,     1,     1,     1,     5,     3,     3,     3,     1,     1,
       1,     2,     4,     3,     1,     1,     3,     6,     3,     1,
       1,     1,     1,     1,     2,     3,     4,     2,     4,     1,
       2,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       4,     4,     2,     3,     2,     3,     1,     2,     1,     2,
       1,     1,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     0,
       6,     9,     1,     1,     0,    10,     2,     1,     3,     5,
       0,     6,     2,     3,     1,     1,     3,     1,     2,     2,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     2,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     1,     3,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 72 "icg_grammar.y" /* yacc.c:1646  */
    { 
		FILE *fptr = fopen("test/icg_output.txt", "w");
		fprintf(fptr,"%s\n",(yyvsp[0].node).code); 
		fclose(fptr);
	}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "icg_grammar.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "icg_grammar.y" /* yacc.c:1646  */
    {
				//ICG
				strcpy((yyval.node).code,(yyvsp[-1].node).code);
				strcat((yyval.node).code,"\n");
				strcat((yyval.node).code,(yyvsp[0].node).code);
			}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 89 "icg_grammar.y" /* yacc.c:1646  */
    {}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "icg_grammar.y" /* yacc.c:1646  */
    {
					 		//ICG
					 		(yyval.node) = (yyvsp[0].node);
					 	}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 96 "icg_grammar.y" /* yacc.c:1646  */
    {
					 		//ICG
					 		strcpy((yyval.node).code,(yyvsp[0].node).code);
					 	}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,(yyvsp[0].node).code);
			}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 111 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,(yyvsp[0].node).code);
			}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 115 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,(yyvsp[0].node).code);
			}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,(yyvsp[0].node).code);
			}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "icg_grammar.y" /* yacc.c:1646  */
    {
		 	//ICG
		 	strcpy((yyval.node).code,"main:\n");
		 	strcat((yyval.node).code,(yyvsp[0].node).code);
		 	strcat((yyval.node).code,"\n");
		 	//printf("in main_func\n %s",$$.code);
		 }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "icg_grammar.y" /* yacc.c:1646  */
    {
				   		//ICG
				   		sprintf((yyval.node).code,"%s %s",(yyvsp[-2].sval),(yyvsp[-1].node).code);
				   }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 143 "icg_grammar.y" /* yacc.c:1646  */
    {	//ICG
				 	sprintf((yyval.node).code,"%s,%s",(yyvsp[-2].node).code,(yyvsp[0].node).code);
				 }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 147 "icg_grammar.y" /* yacc.c:1646  */
    {
					//ICG
					sprintf((yyval.node).code,"%s,%s",(yyvsp[-2].node).code,(yyvsp[0].node).code);
				}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 152 "icg_grammar.y" /* yacc.c:1646  */
    {
					//ICG
					sprintf((yyval.node).code,"%s",(yyvsp[0].node).code);
				}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 157 "icg_grammar.y" /* yacc.c:1646  */
    {
					//ICG
					sprintf((yyval.node).code,"%s",(yyvsp[0].node).code);
				}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 164 "icg_grammar.y" /* yacc.c:1646  */
    {
					    	//ICG
					    	//strcpy($$.addr,$1);
	   						strcpy((yyval.node).code,(yyvsp[0].sval));
					    }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 170 "icg_grammar.y" /* yacc.c:1646  */
    {
				          	//ICG
				              //strcpy($$.addr,$1);
							  sprintf((yyval.node).code,"%s %s",(yyvsp[-1].sval),(yyvsp[0].node).code);
				          }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "icg_grammar.y" /* yacc.c:1646  */
    {
	  	//ICG
	  	sprintf((yyval.node).code,"%s [ %s ]",(yyvsp[-3].node).code,(yyvsp[-1].sval));
	  }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "icg_grammar.y" /* yacc.c:1646  */
    {
	  	  //ICG
	      sprintf((yyval.node).code,"[ %s ]",(yyvsp[-1].sval));
	  }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 190 "icg_grammar.y" /* yacc.c:1646  */
    { 
	 	strcpy((yyval.node).code,(yyvsp[0].node).code); 
	 }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 194 "icg_grammar.y" /* yacc.c:1646  */
    {
     	strcpy((yyval.node).code,(yyvsp[0].node).code);	
     }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 200 "icg_grammar.y" /* yacc.c:1646  */
    {
		 	strcat((yyval.node).code,(yyvsp[0].node).code); 
		   	strcat((yyval.node).code,(yyvsp[-2].sval));
		   	strcat((yyval.node).code," = ");
		   	strcat((yyval.node).code,(yyvsp[0].node).addr);
		   	//strcat($$.code,"\n");
		}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 209 "icg_grammar.y" /* yacc.c:1646  */
    {
				sprintf((yyval.node).code,"%s %s = { %s }",(yyvsp[-5].sval),(yyvsp[-4].node).code,(yyvsp[-1].node).code);
			}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 215 "icg_grammar.y" /* yacc.c:1646  */
    {
			sprintf((yyval.node).code,"%s , %s",(yyvsp[-2].node).code,(yyvsp[0].node).code);
		}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 219 "icg_grammar.y" /* yacc.c:1646  */
    {
       		strcpy((yyval.node).code,(yyvsp[0].node).code);
       	}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 224 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,(yyvsp[0].sval));}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 225 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,(yyvsp[0].sval));}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 226 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,(yyvsp[0].sval));}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 227 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,(yyvsp[0].sval));}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 230 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,"");}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 231 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,"");}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 235 "icg_grammar.y" /* yacc.c:1646  */
    {
			sprintf((yyval.node).code,"%s:\n%s",(yyvsp[-2].sval),(yyvsp[0].node).code);
		}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 252 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,"");}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 253 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,"");}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 256 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,"");}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 259 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,"");}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 260 "icg_grammar.y" /* yacc.c:1646  */
    {strcpy((yyval.node).code,(yyvsp[-1].node).code);}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 268 "icg_grammar.y" /* yacc.c:1646  */
    {
					strcpy((yyval.node).code,(yyvsp[0].node).code);
					//printf("block item %s",$$.code);
				}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 273 "icg_grammar.y" /* yacc.c:1646  */
    {
					sprintf((yyval.node).code,"%s\n %s",(yyvsp[-1].node).code,(yyvsp[0].node).code);
					//printf("blocks %s",$$.code);
				}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 280 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,(yyvsp[0].node).code);
			}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 284 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,(yyvsp[0].node).code);
		    }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 292 "icg_grammar.y" /* yacc.c:1646  */
    {
					strcpy((yyval.node).code,"");
				}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 296 "icg_grammar.y" /* yacc.c:1646  */
    {
					strcpy((yyval.node).code,"");
				}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 302 "icg_grammar.y" /* yacc.c:1646  */
    {
					strcpy((yyval.node).code,"");
		}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 343 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,(yyvsp[0].node).code);
			}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 347 "icg_grammar.y" /* yacc.c:1646  */
    {
		  	strcpy((yyval.node).code,(yyvsp[0].node).code);
		  }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 351 "icg_grammar.y" /* yacc.c:1646  */
    {
  		  	strcpy((yyval.node).code,(yyvsp[0].node).code);
  		  }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 355 "icg_grammar.y" /* yacc.c:1646  */
    {
  		  	map <string,string> m = v.back();
			v.pop_back();
			sprintf((yyval.node).code,"%s\n%s:\n",(yyvsp[0].node).code,m["next"].c_str());
  		  }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 361 "icg_grammar.y" /* yacc.c:1646  */
    {

		  }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 365 "icg_grammar.y" /* yacc.c:1646  */
    {
          	strcpy((yyval.node).code,(yyvsp[0].node).code);
          }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 371 "icg_grammar.y" /* yacc.c:1646  */
    {}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 373 "icg_grammar.y" /* yacc.c:1646  */
    {
    	strcpy((yyval.node).code,(yyvsp[-1].node).code);
    }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 378 "icg_grammar.y" /* yacc.c:1646  */
    {
			map <string,string> m;
			char *begin = label_func();
			m["true"] = string(begin);
			free(begin);
			m["type"] = "if";
			m["false"] = string(global_func());
			m["next"] = m["false"];
			v.push_back(m);
			//printf("if");
			//printf("true %s  false  %s  next  %s",m["true"].c_str(),m["false"].c_str(),m["next"].c_str());

		}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 394 "icg_grammar.y" /* yacc.c:1646  */
    {
				map <string,string> m = v.back();
				v.pop_back();

				//m["next"] = m["false"];
				
				char *begin = label_func();
				m["false"] = string(begin);
				m["type"] = "if_else";
				free(begin);
				v.push_back(m);
				//printf("if else");
				//printf("true %s  false  %s  next  %s",m["true"].c_str(),m["false"].c_str(),m["next"].c_str());
			}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 411 "icg_grammar.y" /* yacc.c:1646  */
    {
						map <string,string> m = v.back();
					sprintf((yyval.node).code,"%s\nif %s goto %s\n goto %s\n%s:\n%s",(yyvsp[-2].node).code,(yyvsp[-2].node).addr,m["true"].c_str(),m["false"].c_str(),m["true"].c_str(),(yyvsp[0].node).code);		
					}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 416 "icg_grammar.y" /* yacc.c:1646  */
    {
                    	map <string,string> m = v.back();
                    	sprintf((yyval.node).code,"%s\nif %s goto %s\ngoto %s\n%s:\n%s\n%s:\n%s",(yyvsp[-5].node).code,(yyvsp[-5].node).addr,m["true"].c_str(),m["false"].c_str(),m["true"].c_str(),(yyvsp[-3].node).code,m["false"].c_str(),(yyvsp[0].node).code);
                    }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 423 "icg_grammar.y" /* yacc.c:1646  */
    {
						map <string,string> m = v.back();
						v.pop_back();
						sprintf((yyval.node).code,"%s\n%s:\n",(yyvsp[0].node).code,m["false"].c_str());
						if(!v.empty())
						{
							map <string,string> m = v.back();
							if(m["type"]=="if")
							{
								strcat((yyval.node).code,"\n");
								strcat((yyval.node).code,"goto ");
								strcat((yyval.node).code,m["false"].c_str());
								strcat((yyval.node).code,"\n");
							}
						}

					}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 441 "icg_grammar.y" /* yacc.c:1646  */
    {
						map <string,string> m = v.back();
						v.pop_back();
						sprintf((yyval.node).code,"%s\n%s:\n",(yyvsp[0].node).code,m["false"].c_str());
					}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 449 "icg_grammar.y" /* yacc.c:1646  */
    {
			map <string,string> m;
			char *begin = label_func();
			m["begin"] = string(begin);
			m["type"] = "for";
			free(begin);
			m["true"] = string(label_func());
			m["false"] = string(global_func());
			m["next"] = m["begin"];
			v.push_back(m);
			//printf("for loop");
			//printf("true %s  false  %s  next  %s",m["true"].c_str(),m["false"].c_str(),m["next"].c_str());
		}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 464 "icg_grammar.y" /* yacc.c:1646  */
    {
				map <string,string> m = v.back();
				/*init 
				  begin: cond.code

				  cond.true: stat.code
				  			 incr
							 goto begin
				  cond.false:
				*/
				sprintf((yyval.node).code,"%s\n%s:\n%sif %s goto %s\ngoto %s\n%s:\n%s\n%s\ngoto %s",(yyvsp[-7].node).code,m["begin"].c_str(),(yyvsp[-4].node).code,(yyvsp[-4].node).addr,m["true"].c_str(),m["false"].c_str(),m["true"].c_str(),(yyvsp[0].node).code,(yyvsp[-2].node).code,m["begin"].c_str());
			}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 479 "icg_grammar.y" /* yacc.c:1646  */
    {
					sprintf((yyval.node).code,"%s %s",(yyvsp[-1].sval),(yyvsp[0].node).code);
				}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 483 "icg_grammar.y" /* yacc.c:1646  */
    {
			   	strcpy((yyval.node).code,(yyvsp[0].node).code);
			   }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 489 "icg_grammar.y" /* yacc.c:1646  */
    {
					strcat((yyval.node).code,(yyvsp[0].node).code); 
				   	strcat((yyval.node).code,(yyvsp[-2].sval));
				   	strcat((yyval.node).code," = ");
				   	strcat((yyval.node).code,(yyvsp[0].node).addr);
				   	//strcat($$.code,"\n");
				}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 497 "icg_grammar.y" /* yacc.c:1646  */
    {
			  	sprintf((yyval.node).code,"%s , ",(yyvsp[-4].node).code);
			  	strcat((yyval.node).code,(yyvsp[0].node).code); 
				strcat((yyval.node).code,(yyvsp[-2].sval));
			   	strcat((yyval.node).code," = ");
			   	strcat((yyval.node).code,(yyvsp[0].node).addr);
			   	//strcat($$.code,"\n");
			  }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 508 "icg_grammar.y" /* yacc.c:1646  */
    {
				map <string,string> m;
				char *begin = label_func();
				m["begin"] = string(begin);
				m["type"] = "while";
				free(begin);
				m["true"] = string(label_func());
				m["false"] = string(global_func());
				m["next"] = m["begin"];
				v.push_back(m);
			}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 522 "icg_grammar.y" /* yacc.c:1646  */
    {
				map <string,string> m = v.back();
				sprintf((yyval.node).code,"%s:\n%sif %s goto %s\ngoto %s\n \n%s:\n%s\ngoto %s",  m["begin"].c_str(), (yyvsp[-2].node).code,  (yyvsp[-2].node).addr,m["true"].c_str(),m["false"].c_str(),  m["true"].c_str(),     (yyvsp[0].node).code,m["begin"].c_str());
			}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 529 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,"return ");
			}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 533 "icg_grammar.y" /* yacc.c:1646  */
    {
		    	sprintf((yyval.node).code,"return %s",(yyvsp[-1].node).code);
		    }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 539 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,(yyvsp[0].node).code);
			}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 543 "icg_grammar.y" /* yacc.c:1646  */
    { 
		   		strcpy((yyval.node).code,(yyvsp[0].node).code); 
	  		 	strcpy((yyval.node).addr,(yyvsp[0].node).addr); 
	  	   }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 550 "icg_grammar.y" /* yacc.c:1646  */
    {
							strcat((yyval.node).code,(yyvsp[0].node).code); 
						   	strcat((yyval.node).code,(yyvsp[-2].sval));
						   	strcat((yyval.node).code," = ");
						   	strcat((yyval.node).code,(yyvsp[0].node).addr);
						   	strcat((yyval.node).code,"\n");
						}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 558 "icg_grammar.y" /* yacc.c:1646  */
    {
	          		  	strcpy((yyval.node).code,(yyvsp[0].node).code);
	          		  }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 564 "icg_grammar.y" /* yacc.c:1646  */
    {
				ret = temp_func();
				sprintf((yyval.node).code,"%s = %s + 1\n%s = %s",ret,(yyvsp[0].sval),(yyvsp[0].sval),ret);
				free(ret);
			}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 570 "icg_grammar.y" /* yacc.c:1646  */
    {
				ret = temp_func();
				sprintf((yyval.node).code,"%s = %s - 1\n%s = %s",ret,(yyvsp[0].sval),(yyvsp[0].sval),ret);
				free(ret);
			}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 576 "icg_grammar.y" /* yacc.c:1646  */
    {
            	strcpy((yyval.node).code,(yyvsp[0].node).code);
            }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 580 "icg_grammar.y" /* yacc.c:1646  */
    {
            	sprintf((yyval.node).code,"%s %s %s",(yyvsp[-2].sval),(yyvsp[-1].node).code,(yyvsp[0].node).code);
            }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 586 "icg_grammar.y" /* yacc.c:1646  */
    {
					ret = temp_func();
					sprintf((yyval.node).code,"%s = %s + 1\n%s = %s",ret,(yyvsp[0].sval),(yyvsp[0].sval),ret);
					free(ret);

				}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 593 "icg_grammar.y" /* yacc.c:1646  */
    {
					ret = temp_func();					
					sprintf((yyval.node).code,"%s = %s - 1\n%s = %s",ret,(yyvsp[0].sval),(yyvsp[0].sval),ret);
					free(ret);
				 }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 601 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,"+=");
			}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 605 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,"-=");
			 }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 609 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,"*=");
			 }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 613 "icg_grammar.y" /* yacc.c:1646  */
    {
				strcpy((yyval.node).code,"/=");
			 }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 619 "icg_grammar.y" /* yacc.c:1646  */
    {
						strcpy((yyval.node).code,(yyvsp[0].node).code); 
	  					strcpy((yyval.node).addr,(yyvsp[0].node).addr);
					}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 624 "icg_grammar.y" /* yacc.c:1646  */
    {
				  	ret = temp_func();
					strcpy((yyval.node).addr,ret);
					free(ret);
					strcat((yyval.node).code,(yyvsp[-2].node).code);
					strcat((yyval.node).code,(yyvsp[0].node).code);

					strcat((yyval.node).code,"\n");
					strcat((yyval.node).code,(yyval.node).addr); 
					strcat((yyval.node).code," = ");
					strcat((yyval.node).code,(yyvsp[-2].node).addr);
					strcat((yyval.node).code,(yyvsp[-1].node).addr);
					strcat((yyval.node).code,(yyvsp[0].node).addr);
					strcat((yyval.node).code,"\n"); 
				  	//sprintf($$.code,"%s %s %s",$1.addr,$2.addr,$3.addr);
				  }
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 641 "icg_grammar.y" /* yacc.c:1646  */
    {
				  	ret = temp_func();
					strcpy((yyval.node).addr,ret);
					free(ret);
					strcat((yyval.node).code,(yyvsp[-2].node).code);
					strcat((yyval.node).code,(yyvsp[0].node).code);

					strcat((yyval.node).code,"\n");
					strcat((yyval.node).code,(yyval.node).addr); 
					strcat((yyval.node).code," = ");
					strcat((yyval.node).code,(yyvsp[-2].node).addr);
					strcat((yyval.node).code,(yyvsp[-1].node).addr);
					strcat((yyval.node).code,(yyvsp[0].node).addr);
					strcat((yyval.node).code,"\n"); 
				  	//sprintf($$.code,"%s %s %s",$1.addr,$2.addr,$3.addr);
				  }
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 658 "icg_grammar.y" /* yacc.c:1646  */
    {
				  	ret = temp_func();
					strcpy((yyval.node).addr,ret);
					free(ret);
					strcat((yyval.node).code,(yyvsp[-2].node).code);
					strcat((yyval.node).code,(yyvsp[0].node).code);

					strcat((yyval.node).code,"\n");
					strcat((yyval.node).code,(yyval.node).addr); 
					strcat((yyval.node).code," = ");
					strcat((yyval.node).code,(yyvsp[-2].node).addr);
					strcat((yyval.node).code,(yyvsp[-1].node).addr);
					strcat((yyval.node).code,(yyvsp[0].node).addr);
					strcat((yyval.node).code,"\n"); 
				  	//sprintf($$.code,"%s %s %s",$1.addr,$2.addr,$3.addr);
				  }
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 677 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,"||");
		}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 681 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,"&&");
		}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 685 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,"^");
		}
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 689 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,"<<");
		}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 693 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,">>");
		}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 699 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,"<");
		}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 703 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,">");
	   }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 707 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,"<=");
	  }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 711 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,">=");
	  }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 715 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,"!=");
	  }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 719 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,"==");
	  }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 725 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).addr,"||");
		}
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 729 "icg_grammar.y" /* yacc.c:1646  */
    {
	  	strcpy((yyval.node).addr,"&&");
	  }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 735 "icg_grammar.y" /* yacc.c:1646  */
    {
						strcpy((yyval.node).code,(yyvsp[0].node).code); 
	  					strcpy((yyval.node).addr,(yyvsp[0].node).addr);
					}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 740 "icg_grammar.y" /* yacc.c:1646  */
    {
						ret = temp_func();
					  	strcpy((yyval.node).addr,ret);
					  	free(ret);
					  	strcat((yyval.node).code,(yyvsp[-2].node).code);
					  	strcat((yyval.node).code,(yyvsp[0].node).code);

					  	strcat((yyval.node).code,"\n");
					  	strcat((yyval.node).code,(yyval.node).addr); 
					  	strcat((yyval.node).code," = ");
					  	strcat((yyval.node).code,(yyvsp[-2].node).addr);
					  	strcat((yyval.node).code," + ");
					  	strcat((yyval.node).code,(yyvsp[0].node).addr);
					  	strcat((yyval.node).code,"\n"); 
					}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 756 "icg_grammar.y" /* yacc.c:1646  */
    {
						ret = temp_func();
					  	strcpy((yyval.node).addr,ret);
					  	free(ret);
					  	strcat((yyval.node).code,(yyvsp[-2].node).code);
					  	strcat((yyval.node).code,(yyvsp[0].node).code);

					  	strcat((yyval.node).code,"\n");
					  	strcat((yyval.node).code,(yyval.node).addr); 
					  	strcat((yyval.node).code," = ");
					  	strcat((yyval.node).code,(yyvsp[-2].node).addr);
					  	strcat((yyval.node).code," - ");
					  	strcat((yyval.node).code,(yyvsp[0].node).addr);
					  	strcat((yyval.node).code,"\n"); 
					}
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 771 "icg_grammar.y" /* yacc.c:1646  */
    {}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 772 "icg_grammar.y" /* yacc.c:1646  */
    {}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 776 "icg_grammar.y" /* yacc.c:1646  */
    {
	 	strcpy((yyval.node).code,(yyvsp[0].node).code); 
	  	strcpy((yyval.node).addr,(yyvsp[0].node).addr);
	 }
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 781 "icg_grammar.y" /* yacc.c:1646  */
    {
	 	ret = temp_func();
	  	strcpy((yyval.node).addr,ret);
	  	free(ret);

	  	strcat((yyval.node).code,(yyvsp[-2].node).code);
	  	strcat((yyval.node).code,(yyvsp[0].node).code);

	  	strcat((yyval.node).code,"\n");
	  	strcat((yyval.node).code,(yyval.node).addr); 
	  	strcat((yyval.node).code," = ");
	  	strcat((yyval.node).code,(yyvsp[-2].node).addr);
	  	strcat((yyval.node).code," * ");
	  	strcat((yyval.node).code,(yyvsp[0].node).addr);
	  	strcat((yyval.node).code,"\n"); 
	 }
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 798 "icg_grammar.y" /* yacc.c:1646  */
    {
	 	ret = temp_func();
	  	strcpy((yyval.node).addr,ret);
	  	free(ret);

	  	strcat((yyval.node).code,(yyvsp[-2].node).code);
	  	strcat((yyval.node).code,(yyvsp[0].node).code);

	  	strcat((yyval.node).code,"\n");
	  	strcat((yyval.node).code,(yyval.node).addr); 
	  	strcat((yyval.node).code," = ");
	  	strcat((yyval.node).code,(yyvsp[-2].node).addr);
	  	strcat((yyval.node).code," / ");
	  	strcat((yyval.node).code,(yyvsp[0].node).addr);
	  	strcat((yyval.node).code,"\n"); 
	 }
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 817 "icg_grammar.y" /* yacc.c:1646  */
    {
			strcpy((yyval.node).code,(yyvsp[-1].node).code); 
			strcpy((yyval.node).addr,(yyvsp[-1].node).addr);
		}
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 822 "icg_grammar.y" /* yacc.c:1646  */
    {
	   	strcpy((yyval.node).addr,(yyvsp[0].sval));
	   	strcpy((yyval.node).code,"");
	   }
#line 2584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 827 "icg_grammar.y" /* yacc.c:1646  */
    {
	   	strcpy((yyval.node).code,(yyvsp[0].node).code);
	   }
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 831 "icg_grammar.y" /* yacc.c:1646  */
    {
	   	strcpy((yyval.node).addr,(yyvsp[0].sval));
	   	strcpy((yyval.node).code,"");
	   }
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 836 "icg_grammar.y" /* yacc.c:1646  */
    {
	   strcpy((yyval.node).addr,(yyvsp[0].sval));
	   	strcpy((yyval.node).code,"");
	   }
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 841 "icg_grammar.y" /* yacc.c:1646  */
    {
	   	strcpy((yyval.node).addr,(yyvsp[0].sval));
	   	strcpy((yyval.node).code,"");
	   }
#line 2619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 846 "icg_grammar.y" /* yacc.c:1646  */
    {
	   	strcpy((yyval.node).addr,(yyvsp[0].sval));
	   	strcpy((yyval.node).code,"");
	   }
#line 2628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 853 "icg_grammar.y" /* yacc.c:1646  */
    {
		sprintf((yyval.node).code,"call(%s,0)",(yyvsp[-2].sval));
	}
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 857 "icg_grammar.y" /* yacc.c:1646  */
    {
	 	sprintf((yyval.node).code,"%s\ncall(%s,%d)",(yyvsp[-1].node).code,(yyvsp[-3].sval),args_count);
	 	args_count=0;	
	 }
#line 2645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 864 "icg_grammar.y" /* yacc.c:1646  */
    {
	 	sprintf((yyval.node).code,"%s\nparam %s",(yyvsp[0].node).code,(yyvsp[0].node).addr);
	 	args_count+=1;
	 }
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 869 "icg_grammar.y" /* yacc.c:1646  */
    {
	 	args_count+=1;
	 	sprintf((yyval.node).code,"%s\nparam %s\n%s",(yyvsp[-2].node).code,(yyvsp[-2].node).addr,(yyvsp[0].node).code);
	 }
#line 2663 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2667 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 879 "icg_grammar.y" /* yacc.c:1906  */


void yyerror(const char *str)
{
	printf("line no :%d  %s near %s\n", yylineno, str, yytext );
}

/*int yywrap()
{
	return 1;
}*/

extern FILE *yyin;

int main(int argc, char *argv[])
{

    ++argv, --argc;  /* Skip over program name. */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }

    if(yyparse() == 0) { printf("Parsing successful!\n");}

	//LevelOrderTraversal(root);
    return 0;
}

/*void reset_globals(){

 type = 0;
 iset = 0;
 fset = 0;
 sset = 0;
 cset = 0;
 
}*/
/*
void check_exists(char *ID, int statement_type){

	if (((current_scope_node->symbolTable).find(ID) != (current_scope_node->symbolTable).end()) && (statement_type==1)) {
		std::cout<<"Identifier "<<ID<<" redefined at line "<<yylineno<<std::endl;
		exit(0);
	}
	else if (((current_scope_node->symbolTable).find(ID) == (current_scope_node->symbolTable).end()) && (statement_type==2)) {
		std::cout<<"Identifier used without declaration at line "<<yylineno<<std::endl;
		exit(0);
	}
}
*/

char* temp_func()
{
	char *ret_temp = (char*)malloc(sizeof(char)*10);
	sprintf(ret_temp,"t%d",temp);
	temp+=1;
	return ret_temp;
}

char* label_func()
{
	char *ret_temp = (char*)malloc(sizeof(char)*10);
	sprintf(ret_temp,"L%d",label);
	label+=1;
	return ret_temp;
}

char* global_func()
{
	char *ret_temp = (char*)malloc(sizeof(char)*10);
	sprintf(ret_temp,"G%d",global_next);
	global_next +=1;
	return ret_temp;
}
