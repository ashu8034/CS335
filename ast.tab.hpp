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

#ifndef YY_YY_AST_TAB_HPP_INCLUDED
# define YY_YY_AST_TAB_HPP_INCLUDED
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
    identifier = 258,              /* identifier  */
    NewLine = 259,                 /* NewLine  */
    abstract = 260,                /* abstract  */
    assert = 261,                  /* assert  */
    boolean = 262,                 /* boolean  */
    break1 = 263,                  /* break1  */
    byte1 = 264,                   /* byte1  */
    case1 = 265,                   /* case1  */
    catch1 = 266,                  /* catch1  */
    char1 = 267,                   /* char1  */
    class1 = 268,                  /* class1  */
    const1 = 269,                  /* const1  */
    underscore = 270,              /* underscore  */
    continue1 = 271,               /* continue1  */
    default1 = 272,                /* default1  */
    do1 = 273,                     /* do1  */
    double1 = 274,                 /* double1  */
    else1 = 275,                   /* else1  */
    enum1 = 276,                   /* enum1  */
    extends = 277,                 /* extends  */
    final = 278,                   /* final  */
    finally = 279,                 /* finally  */
    float1 = 280,                  /* float1  */
    for1 = 281,                    /* for1  */
    if1 = 282,                     /* if1  */
    goto1 = 283,                   /* goto1  */
    implements = 284,              /* implements  */
    import = 285,                  /* import  */
    instanceof = 286,              /* instanceof  */
    int1 = 287,                    /* int1  */
    interface = 288,               /* interface  */
    long1 = 289,                   /* long1  */
    native = 290,                  /* native  */
    new1 = 291,                    /* new1  */
    package = 292,                 /* package  */
    private1 = 293,                /* private1  */
    protected1 = 294,              /* protected1  */
    public1 = 295,                 /* public1  */
    return1 = 296,                 /* return1  */
    static1 = 297,                 /* static1  */
    strictfp = 298,                /* strictfp  */
    short1 = 299,                  /* short1  */
    super = 300,                   /* super  */
    switch1 = 301,                 /* switch1  */
    synchronised = 302,            /* synchronised  */
    this1 = 303,                   /* this1  */
    throw1 = 304,                  /* throw1  */
    throws = 305,                  /* throws  */
    transient = 306,               /* transient  */
    try1 = 307,                    /* try1  */
    void1 = 308,                   /* void1  */
    volatile1 = 309,               /* volatile1  */
    while1 = 310,                  /* while1  */
    exports = 311,                 /* exports  */
    module1 = 312,                 /* module1  */
    NonSealed = 313,               /* NonSealed  */
    open = 314,                    /* open  */
    opens = 315,                   /* opens  */
    permits = 316,                 /* permits  */
    provides = 317,                /* provides  */
    record = 318,                  /* record  */
    requires1 = 319,               /* requires1  */
    sealed = 320,                  /* sealed  */
    to = 321,                      /* to  */
    transitive = 322,              /* transitive  */
    uses = 323,                    /* uses  */
    var = 324,                     /* var  */
    with = 325,                    /* with  */
    yield = 326,                   /* yield  */
    decint = 327,                  /* decint  */
    octint = 328,                  /* octint  */
    hexint = 329,                  /* hexint  */
    binint = 330,                  /* binint  */
    hexfloat1 = 331,               /* hexfloat1  */
    decfloat = 332,                /* decfloat  */
    BooleanLiteral = 333,          /* BooleanLiteral  */
    charlit = 334,                 /* charlit  */
    string1 = 335,                 /* string1  */
    textblock = 336,               /* textblock  */
    NullLiteral = 337,             /* NullLiteral  */
    comma = 338,                   /* comma  */
    semicolon = 339,               /* semicolon  */
    period = 340,                  /* period  */
    open_bracket = 341,            /* open_bracket  */
    closed_bracket = 342,          /* closed_bracket  */
    open_square_bracket = 343,     /* open_square_bracket  */
    closed_square_bracket = 344,   /* closed_square_bracket  */
    dots_three = 345,              /* dots_three  */
    at = 346,                      /* at  */
    colon_colon = 347,             /* colon_colon  */
    open_flower_bracket = 348,     /* open_flower_bracket  */
    closed_flower_bracket = 349,   /* closed_flower_bracket  */
    equal1 = 350,                  /* equal1  */
    diamond = 351,                 /* diamond  */
    gthan = 352,                   /* gthan  */
    lthan = 353,                   /* lthan  */
    exclamatory = 354,             /* exclamatory  */
    notk = 355,                    /* notk  */
    qmark = 356,                   /* qmark  */
    colon = 357,                   /* colon  */
    implies = 358,                 /* implies  */
    equal_equal = 359,             /* equal_equal  */
    g_equal = 360,                 /* g_equal  */
    l_equal = 361,                 /* l_equal  */
    exclamatory_equal = 362,       /* exclamatory_equal  */
    and_and = 363,                 /* and_and  */
    or1 = 364,                     /* or1  */
    increment = 365,               /* increment  */
    decrement = 366,               /* decrement  */
    plus_1 = 367,                  /* plus_1  */
    minus_1 = 368,                 /* minus_1  */
    multiply = 369,                /* multiply  */
    divide = 370,                  /* divide  */
    band = 371,                    /* band  */
    bor = 372,                     /* bor  */
    power = 373,                   /* power  */
    percentage = 374,              /* percentage  */
    llthan = 375,                  /* llthan  */
    ggthan = 376,                  /* ggthan  */
    gggthan = 377,                 /* gggthan  */
    plus_equal = 378,              /* plus_equal  */
    minus_equal = 379,             /* minus_equal  */
    multiply_equal = 380,          /* multiply_equal  */
    divide_equal = 381,            /* divide_equal  */
    bitor_equal = 382,             /* bitor_equal  */
    bitand_equal = 383,            /* bitand_equal  */
    power_equal = 384,             /* power_equal  */
    percentage_equal = 385,        /* percentage_equal  */
    ll_equal = 386,                /* ll_equal  */
    gg_equal = 387,                /* gg_equal  */
    ggg_equal = 388                /* ggg_equal  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 156 "ast.ypp"

  struct Node* node;
  char* str;
  int ival;
  float fval; 

#line 204 "ast.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_AST_TAB_HPP_INCLUDED  */
