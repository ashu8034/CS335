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
#line 1 "ast.ypp"

  /* This is the prologue section. This code goes
  on the top of the parser implementation file. */
  #include <iostream>
  #include <vector>
  #include <cstring>
  #include <sstream>
  #include <typeinfo>
  #include <fstream>
  using namespace std;
 long long int curr_id = 0;

  struct Node{
    string s;
	int flag=0;
	int i;
	float f;
    vector <Node* > child;
	long long int id = 0;
  };

  struct Node* root=NULL;
  
  struct Node* fterminal_child(string pstr,string cstr){
    struct Node* c= new Node;
	curr_id++;
	c->id = curr_id;
	c->flag=1;
    c->s=cstr;
    struct Node* p=new Node;
	curr_id++;
	p->id = curr_id;
    p->s= pstr;
    p->child.push_back(c);
	return p;
}

void print_dot_of_node(Node*p, string filename)
  {
    std::ofstream output;
    output.open(filename, std::ios_base::app);
    output << p->id << "[label=\"" << p->s << "\"];" << endl;
    int i;
    for(i=0; i<p->child.size(); i++)
    {
      struct Node* f=p->child[i];
      while(f->child.size()==1){
        f=f->child[0];
      }
      output << p->id << " -> " << f->id <<";" << endl;
      print_dot_of_node(f, filename);
    }
  } 

void print_graph_in_dot(Node*p, string filename)
  {
    std::ofstream output;
    output.open(filename, std::ios_base::app);
    output << "Digraph G{" <<endl;
    print_dot_of_node(p, filename);
    output<<"}";
  }

void terminal_child(Node* p,string pstr,string cstr){
    struct Node* c= new Node;
	curr_id++;
	c->id = curr_id;
	c->flag=1;
    c->s=cstr;
    p->child.push_back(c);
}

  struct Node* fterminal_child_int(string pstr,int cstr){
    struct Node* c= new Node;
	curr_id++;
	c->id = curr_id;
    c->i=cstr;
	c->flag=2;
    struct Node* p=new Node;
	curr_id++;
	p->id = curr_id;
    p->s= pstr;
	p->child.push_back(c);
	return p;
  }

   void terminal_child_int(Node* p,string pstr,int cstr){
    struct Node* c= new Node;
	curr_id++;
	c->id = curr_id;
    c->i=cstr;
	c->flag=2;
    p->child.push_back(c);
  }

  struct Node* fterminal_child_float(string pstr,float cstr){
    struct Node* c= new Node;
	curr_id++;
	c->id = curr_id;
    c->f=cstr;
	c->flag=3;
	struct Node* p=new Node;
	curr_id++;
	p->id = curr_id;
    p->s= pstr;
	p->child.push_back(c);
	return p;
  }

  void terminal_child_float(Node* p,string pstr,float cstr){
    struct Node* c= new Node;
	curr_id++;
	c->id = curr_id;
    c->f=cstr;
	c->flag=3;
	p->child.push_back(c);
  }
  
  struct Node* fnon_terminalchild(string pstr, Node*c){
    struct Node* p=new Node;
	curr_id++;
	p->id = curr_id;
    p->s= pstr;
	p->flag=1;
    p->child.push_back(c);
	return p;
  }

  void non_terminalchild(Node*p,string pstr, Node*c){
	p->flag=1;
	p->child.push_back(c);
  }

  struct Node* nonopnon(string pstr,string op, Node* fir, Node* sec){
    struct Node* p=new Node;
	curr_id++;
	p->id = curr_id;
    p->s=pstr;
    struct Node* o=new Node;
    o->s=op;
	curr_id++;
	o->id = curr_id;
    p->child.push_back(o);
    o->child.push_back(fir);
    o->child.push_back(sec);
	return p;
	}

  extern void yyerror(char const * message);
  extern int yyparse(void);
  extern int yylex(void);
  extern int yylineno;

#line 225 "ast.tab.cpp"

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

#include "ast.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_identifier = 3,                 /* identifier  */
  YYSYMBOL_NewLine = 4,                    /* NewLine  */
  YYSYMBOL_abstract = 5,                   /* abstract  */
  YYSYMBOL_assert = 6,                     /* assert  */
  YYSYMBOL_boolean = 7,                    /* boolean  */
  YYSYMBOL_break1 = 8,                     /* break1  */
  YYSYMBOL_byte1 = 9,                      /* byte1  */
  YYSYMBOL_case1 = 10,                     /* case1  */
  YYSYMBOL_catch1 = 11,                    /* catch1  */
  YYSYMBOL_char1 = 12,                     /* char1  */
  YYSYMBOL_class1 = 13,                    /* class1  */
  YYSYMBOL_const1 = 14,                    /* const1  */
  YYSYMBOL_underscore = 15,                /* underscore  */
  YYSYMBOL_continue1 = 16,                 /* continue1  */
  YYSYMBOL_default1 = 17,                  /* default1  */
  YYSYMBOL_do1 = 18,                       /* do1  */
  YYSYMBOL_double1 = 19,                   /* double1  */
  YYSYMBOL_else1 = 20,                     /* else1  */
  YYSYMBOL_enum1 = 21,                     /* enum1  */
  YYSYMBOL_extends = 22,                   /* extends  */
  YYSYMBOL_final = 23,                     /* final  */
  YYSYMBOL_finally = 24,                   /* finally  */
  YYSYMBOL_float1 = 25,                    /* float1  */
  YYSYMBOL_for1 = 26,                      /* for1  */
  YYSYMBOL_if1 = 27,                       /* if1  */
  YYSYMBOL_goto1 = 28,                     /* goto1  */
  YYSYMBOL_implements = 29,                /* implements  */
  YYSYMBOL_import = 30,                    /* import  */
  YYSYMBOL_instanceof = 31,                /* instanceof  */
  YYSYMBOL_int1 = 32,                      /* int1  */
  YYSYMBOL_interface = 33,                 /* interface  */
  YYSYMBOL_long1 = 34,                     /* long1  */
  YYSYMBOL_native = 35,                    /* native  */
  YYSYMBOL_new1 = 36,                      /* new1  */
  YYSYMBOL_package = 37,                   /* package  */
  YYSYMBOL_private1 = 38,                  /* private1  */
  YYSYMBOL_protected1 = 39,                /* protected1  */
  YYSYMBOL_public1 = 40,                   /* public1  */
  YYSYMBOL_return1 = 41,                   /* return1  */
  YYSYMBOL_static1 = 42,                   /* static1  */
  YYSYMBOL_strictfp = 43,                  /* strictfp  */
  YYSYMBOL_short1 = 44,                    /* short1  */
  YYSYMBOL_super = 45,                     /* super  */
  YYSYMBOL_switch1 = 46,                   /* switch1  */
  YYSYMBOL_synchronised = 47,              /* synchronised  */
  YYSYMBOL_this1 = 48,                     /* this1  */
  YYSYMBOL_throw1 = 49,                    /* throw1  */
  YYSYMBOL_throws = 50,                    /* throws  */
  YYSYMBOL_transient = 51,                 /* transient  */
  YYSYMBOL_try1 = 52,                      /* try1  */
  YYSYMBOL_void1 = 53,                     /* void1  */
  YYSYMBOL_volatile1 = 54,                 /* volatile1  */
  YYSYMBOL_while1 = 55,                    /* while1  */
  YYSYMBOL_exports = 56,                   /* exports  */
  YYSYMBOL_module1 = 57,                   /* module1  */
  YYSYMBOL_NonSealed = 58,                 /* NonSealed  */
  YYSYMBOL_open = 59,                      /* open  */
  YYSYMBOL_opens = 60,                     /* opens  */
  YYSYMBOL_permits = 61,                   /* permits  */
  YYSYMBOL_provides = 62,                  /* provides  */
  YYSYMBOL_record = 63,                    /* record  */
  YYSYMBOL_requires1 = 64,                 /* requires1  */
  YYSYMBOL_sealed = 65,                    /* sealed  */
  YYSYMBOL_to = 66,                        /* to  */
  YYSYMBOL_transitive = 67,                /* transitive  */
  YYSYMBOL_uses = 68,                      /* uses  */
  YYSYMBOL_var = 69,                       /* var  */
  YYSYMBOL_with = 70,                      /* with  */
  YYSYMBOL_yield = 71,                     /* yield  */
  YYSYMBOL_decint = 72,                    /* decint  */
  YYSYMBOL_octint = 73,                    /* octint  */
  YYSYMBOL_hexint = 74,                    /* hexint  */
  YYSYMBOL_binint = 75,                    /* binint  */
  YYSYMBOL_hexfloat1 = 76,                 /* hexfloat1  */
  YYSYMBOL_decfloat = 77,                  /* decfloat  */
  YYSYMBOL_BooleanLiteral = 78,            /* BooleanLiteral  */
  YYSYMBOL_charlit = 79,                   /* charlit  */
  YYSYMBOL_string1 = 80,                   /* string1  */
  YYSYMBOL_textblock = 81,                 /* textblock  */
  YYSYMBOL_NullLiteral = 82,               /* NullLiteral  */
  YYSYMBOL_comma = 83,                     /* comma  */
  YYSYMBOL_semicolon = 84,                 /* semicolon  */
  YYSYMBOL_period = 85,                    /* period  */
  YYSYMBOL_open_bracket = 86,              /* open_bracket  */
  YYSYMBOL_closed_bracket = 87,            /* closed_bracket  */
  YYSYMBOL_open_square_bracket = 88,       /* open_square_bracket  */
  YYSYMBOL_closed_square_bracket = 89,     /* closed_square_bracket  */
  YYSYMBOL_dots_three = 90,                /* dots_three  */
  YYSYMBOL_at = 91,                        /* at  */
  YYSYMBOL_colon_colon = 92,               /* colon_colon  */
  YYSYMBOL_open_flower_bracket = 93,       /* open_flower_bracket  */
  YYSYMBOL_closed_flower_bracket = 94,     /* closed_flower_bracket  */
  YYSYMBOL_equal1 = 95,                    /* equal1  */
  YYSYMBOL_diamond = 96,                   /* diamond  */
  YYSYMBOL_gthan = 97,                     /* gthan  */
  YYSYMBOL_lthan = 98,                     /* lthan  */
  YYSYMBOL_exclamatory = 99,               /* exclamatory  */
  YYSYMBOL_notk = 100,                     /* notk  */
  YYSYMBOL_qmark = 101,                    /* qmark  */
  YYSYMBOL_colon = 102,                    /* colon  */
  YYSYMBOL_implies = 103,                  /* implies  */
  YYSYMBOL_equal_equal = 104,              /* equal_equal  */
  YYSYMBOL_g_equal = 105,                  /* g_equal  */
  YYSYMBOL_l_equal = 106,                  /* l_equal  */
  YYSYMBOL_exclamatory_equal = 107,        /* exclamatory_equal  */
  YYSYMBOL_and_and = 108,                  /* and_and  */
  YYSYMBOL_or1 = 109,                      /* or1  */
  YYSYMBOL_increment = 110,                /* increment  */
  YYSYMBOL_decrement = 111,                /* decrement  */
  YYSYMBOL_plus_1 = 112,                   /* plus_1  */
  YYSYMBOL_minus_1 = 113,                  /* minus_1  */
  YYSYMBOL_multiply = 114,                 /* multiply  */
  YYSYMBOL_divide = 115,                   /* divide  */
  YYSYMBOL_band = 116,                     /* band  */
  YYSYMBOL_bor = 117,                      /* bor  */
  YYSYMBOL_power = 118,                    /* power  */
  YYSYMBOL_percentage = 119,               /* percentage  */
  YYSYMBOL_llthan = 120,                   /* llthan  */
  YYSYMBOL_ggthan = 121,                   /* ggthan  */
  YYSYMBOL_gggthan = 122,                  /* gggthan  */
  YYSYMBOL_plus_equal = 123,               /* plus_equal  */
  YYSYMBOL_minus_equal = 124,              /* minus_equal  */
  YYSYMBOL_multiply_equal = 125,           /* multiply_equal  */
  YYSYMBOL_divide_equal = 126,             /* divide_equal  */
  YYSYMBOL_bitor_equal = 127,              /* bitor_equal  */
  YYSYMBOL_bitand_equal = 128,             /* bitand_equal  */
  YYSYMBOL_power_equal = 129,              /* power_equal  */
  YYSYMBOL_percentage_equal = 130,         /* percentage_equal  */
  YYSYMBOL_ll_equal = 131,                 /* ll_equal  */
  YYSYMBOL_gg_equal = 132,                 /* gg_equal  */
  YYSYMBOL_ggg_equal = 133,                /* ggg_equal  */
  YYSYMBOL_YYACCEPT = 134,                 /* $accept  */
  YYSYMBOL_Identifier = 135,               /* Identifier  */
  YYSYMBOL_Literal = 136,                  /* Literal  */
  YYSYMBOL_Type = 137,                     /* Type  */
  YYSYMBOL_PrimitiveType = 138,            /* PrimitiveType  */
  YYSYMBOL_NumericType = 139,              /* NumericType  */
  YYSYMBOL_IntegralType = 140,             /* IntegralType  */
  YYSYMBOL_FloatingPointType = 141,        /* FloatingPointType  */
  YYSYMBOL_ReferenceType = 142,            /* ReferenceType  */
  YYSYMBOL_ArrayType = 143,                /* ArrayType  */
  YYSYMBOL_Name = 144,                     /* Name  */
  YYSYMBOL_QualifiedName = 145,            /* QualifiedName  */
  YYSYMBOL_CompilationUnit = 146,          /* CompilationUnit  */
  YYSYMBOL_PackageDeclarationopt = 147,    /* PackageDeclarationopt  */
  YYSYMBOL_ImportDeclarationsopt = 148,    /* ImportDeclarationsopt  */
  YYSYMBOL_TypeDeclarationsopt = 149,      /* TypeDeclarationsopt  */
  YYSYMBOL_ImportDeclarations = 150,       /* ImportDeclarations  */
  YYSYMBOL_TypeDeclarations = 151,         /* TypeDeclarations  */
  YYSYMBOL_PackageDeclaration = 152,       /* PackageDeclaration  */
  YYSYMBOL_ImportDeclaration = 153,        /* ImportDeclaration  */
  YYSYMBOL_SingleTypeImportDeclaration = 154, /* SingleTypeImportDeclaration  */
  YYSYMBOL_TypeImportOnDemandDeclaration = 155, /* TypeImportOnDemandDeclaration  */
  YYSYMBOL_TypeDeclaration = 156,          /* TypeDeclaration  */
  YYSYMBOL_Modifiers = 157,                /* Modifiers  */
  YYSYMBOL_Modifier = 158,                 /* Modifier  */
  YYSYMBOL_ClassDeclaration = 159,         /* ClassDeclaration  */
  YYSYMBOL_Modifiersopt = 160,             /* Modifiersopt  */
  YYSYMBOL_Superopt = 161,                 /* Superopt  */
  YYSYMBOL_Interfacesopt = 162,            /* Interfacesopt  */
  YYSYMBOL_Super = 163,                    /* Super  */
  YYSYMBOL_Interfaces = 164,               /* Interfaces  */
  YYSYMBOL_InterfaceTypeList = 165,        /* InterfaceTypeList  */
  YYSYMBOL_ClassBody = 166,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarationsopt = 167, /* ClassBodyDeclarationsopt  */
  YYSYMBOL_ClassBodyDeclarations = 168,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 169,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 170,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 171,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclarators = 172,      /* VariableDeclarators  */
  YYSYMBOL_VariableDeclarator = 173,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 174,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 175,      /* VariableInitializer  */
  YYSYMBOL_MethodDeclaration = 176,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 177,             /* MethodHeader  */
  YYSYMBOL_Throwsopt = 178,                /* Throwsopt  */
  YYSYMBOL_MethodDeclarator = 179,         /* MethodDeclarator  */
  YYSYMBOL_FormalParameterListopt = 180,   /* FormalParameterListopt  */
  YYSYMBOL_FormalParameterList = 181,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 182,          /* FormalParameter  */
  YYSYMBOL_Throws = 183,                   /* Throws  */
  YYSYMBOL_ClassTypeList = 184,            /* ClassTypeList  */
  YYSYMBOL_MethodBody = 185,               /* MethodBody  */
  YYSYMBOL_StaticInitializer = 186,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 187,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorDeclarator = 188,    /* ConstructorDeclarator  */
  YYSYMBOL_ConstructorBody = 189,          /* ConstructorBody  */
  YYSYMBOL_BlockStatementsopt = 190,       /* BlockStatementsopt  */
  YYSYMBOL_ExplicitConstructorInvocationopt = 191, /* ExplicitConstructorInvocationopt  */
  YYSYMBOL_ExplicitConstructorInvocation = 192, /* ExplicitConstructorInvocation  */
  YYSYMBOL_ArgumentListopt = 193,          /* ArgumentListopt  */
  YYSYMBOL_InterfaceDeclaration = 194,     /* InterfaceDeclaration  */
  YYSYMBOL_ExtendsInterfacesopt = 195,     /* ExtendsInterfacesopt  */
  YYSYMBOL_ExtendsInterfaces = 196,        /* ExtendsInterfaces  */
  YYSYMBOL_InterfaceBody = 197,            /* InterfaceBody  */
  YYSYMBOL_InterfaceMemberDeclarationsopt = 198, /* InterfaceMemberDeclarationsopt  */
  YYSYMBOL_InterfaceMemberDeclarations = 199, /* InterfaceMemberDeclarations  */
  YYSYMBOL_InterfaceMemberDeclaration = 200, /* InterfaceMemberDeclaration  */
  YYSYMBOL_AbstractMethodDeclaration = 201, /* AbstractMethodDeclaration  */
  YYSYMBOL_ArrayInitializer = 202,         /* ArrayInitializer  */
  YYSYMBOL_commaopt = 203,                 /* commaopt  */
  YYSYMBOL_VariableInitializersopt = 204,  /* VariableInitializersopt  */
  YYSYMBOL_VariableInitializers = 205,     /* VariableInitializers  */
  YYSYMBOL_Block = 206,                    /* Block  */
  YYSYMBOL_BlockStatements = 207,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 208,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclarationStatement = 209, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 210, /* LocalVariableDeclaration  */
  YYSYMBOL_Statement = 211,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 212,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 213, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_EmptyStatement = 214,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 215,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 216, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 217,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 218,      /* StatementExpression  */
  YYSYMBOL_IfThenStatement = 219,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 220,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 221, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_SwitchStatement = 222,          /* SwitchStatement  */
  YYSYMBOL_SwitchBlock = 223,              /* SwitchBlock  */
  YYSYMBOL_SwitchBlockStatementGroupsopt = 224, /* SwitchBlockStatementGroupsopt  */
  YYSYMBOL_SwitchLabelsopt = 225,          /* SwitchLabelsopt  */
  YYSYMBOL_SwitchBlockStatementGroups = 226, /* SwitchBlockStatementGroups  */
  YYSYMBOL_SwitchBlockStatementGroup = 227, /* SwitchBlockStatementGroup  */
  YYSYMBOL_SwitchLabels = 228,             /* SwitchLabels  */
  YYSYMBOL_SwitchLabel = 229,              /* SwitchLabel  */
  YYSYMBOL_WhileStatement = 230,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 231,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DoStatement = 232,              /* DoStatement  */
  YYSYMBOL_ForStatement = 233,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 234,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInitopt = 235,               /* ForInitopt  */
  YYSYMBOL_Expressionopt = 236,            /* Expressionopt  */
  YYSYMBOL_ForUpdateopt = 237,             /* ForUpdateopt  */
  YYSYMBOL_ForInit = 238,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 239,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 240,  /* StatementExpressionList  */
  YYSYMBOL_BreakStatement = 241,           /* BreakStatement  */
  YYSYMBOL_ContinueStatement = 242,        /* ContinueStatement  */
  YYSYMBOL_Identifieropt = 243,            /* Identifieropt  */
  YYSYMBOL_ReturnStatement = 244,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 245,           /* ThrowStatement  */
  YYSYMBOL_SynchronizedStatement = 246,    /* SynchronizedStatement  */
  YYSYMBOL_TryStatement = 247,             /* TryStatement  */
  YYSYMBOL_Catchesopt = 248,               /* Catchesopt  */
  YYSYMBOL_Catches = 249,                  /* Catches  */
  YYSYMBOL_CatchClause = 250,              /* CatchClause  */
  YYSYMBOL_Finally = 251,                  /* Finally  */
  YYSYMBOL_Primary = 252,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 253,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassInstanceCreationExpression = 254, /* ClassInstanceCreationExpression  */
  YYSYMBOL_ArgumentList = 255,             /* ArgumentList  */
  YYSYMBOL_ArrayCreationExpression = 256,  /* ArrayCreationExpression  */
  YYSYMBOL_Dimsopt = 257,                  /* Dimsopt  */
  YYSYMBOL_DimExprs = 258,                 /* DimExprs  */
  YYSYMBOL_DimExpr = 259,                  /* DimExpr  */
  YYSYMBOL_Dims = 260,                     /* Dims  */
  YYSYMBOL_FieldAccess = 261,              /* FieldAccess  */
  YYSYMBOL_MethodInvocation = 262,         /* MethodInvocation  */
  YYSYMBOL_ArrayAccess = 263,              /* ArrayAccess  */
  YYSYMBOL_PostfixExpression = 264,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 265,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 266,  /* PostDecrementExpression  */
  YYSYMBOL_UnaryExpression = 267,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 268,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 269,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 270, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_CastExpression = 271,           /* CastExpression  */
  YYSYMBOL_MultiplicativeExpression = 272, /* MultiplicativeExpression  */
  YYSYMBOL_AdditiveExpression = 273,       /* AdditiveExpression  */
  YYSYMBOL_ShiftExpression = 274,          /* ShiftExpression  */
  YYSYMBOL_RelationalExpression = 275,     /* RelationalExpression  */
  YYSYMBOL_EqualityExpression = 276,       /* EqualityExpression  */
  YYSYMBOL_AndExpression = 277,            /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 278,    /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 279,    /* InclusiveOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 280, /* ConditionalAndExpression  */
  YYSYMBOL_ConditionalOrExpression = 281,  /* ConditionalOrExpression  */
  YYSYMBOL_AssignmentExpression = 282,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 283,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 284,             /* LeftHandSide  */
  YYSYMBOL_AssignmentOperator = 285        /* AssignmentOperator  */
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
#define YYLAST   1720

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  134
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  152
/* YYNRULES -- Number of rules.  */
#define YYNRULES  328
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  531

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   388


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   184,   184,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   198,   200,   204,   206,   210,   212,
     216,   217,   218,   219,   220,   224,   224,   228,   230,   234,
     236,   238,   242,   244,   248,   252,   254,   254,   255,   255,
     256,   256,   260,   262,   266,   268,   272,   276,   278,   282,
     286,   290,   292,   294,   298,   300,   304,   304,   304,   306,
     308,   308,   308,   308,   308,   308,   312,   314,   314,   315,
     315,   316,   316,   320,   324,   328,   330,   334,   336,   336,
     340,   342,   346,   348,   350,   354,   356,   360,   364,   366,
     370,   372,   376,   378,   382,   384,   388,   392,   394,   396,
     396,   400,   402,   404,   404,   408,   410,   414,   418,   422,
     424,   428,   430,   434,   438,   442,   446,   448,   448,   449,
     449,   453,   455,   457,   457,   461,   463,   463,   467,   469,
     473,   475,   475,   479,   481,   485,   487,   491,   495,   497,
     497,   498,   498,   502,   504,   508,   512,   514,   518,   520,
     524,   528,   529,   533,   535,   537,   539,   541,   543,   547,
     549,   551,   553,   555,   559,   561,   563,   565,   567,   569,
     571,   573,   575,   577,   579,   583,   587,   591,   595,   599,
     601,   603,   605,   607,   609,   611,   615,   619,   623,   627,
     631,   633,   633,   634,   634,   638,   640,   644,   648,   650,
     654,   656,   660,   664,   668,   672,   676,   678,   678,   679,
     679,   680,   680,   684,   686,   690,   694,   696,   700,   704,
     706,   706,   710,   714,   718,   722,   724,   726,   726,   730,
     732,   736,   740,   744,   746,   750,   752,   754,   756,   758,
     760,   762,   766,   770,   772,   776,   778,   780,   780,   784,
     786,   790,   794,   796,   800,   802,   806,   808,   810,   814,
     816,   820,   822,   824,   826,   830,   834,   838,   840,   842,
     844,   846,   850,   854,   858,   860,   862,   864,   868,   870,
     872,   876,   878,   880,   882,   886,   888,   890,   894,   896,
     898,   900,   904,   906,   908,   910,   912,   914,   918,   920,
     922,   926,   928,   932,   934,   938,   940,   944,   946,   950,
     952,   956,   958,   962,   966,   968,   970,   974,   975,   976,
     977,   978,   979,   980,   981,   982,   983,   983,   983
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
  "\"end of file\"", "error", "\"invalid token\"", "identifier",
  "NewLine", "abstract", "assert", "boolean", "break1", "byte1", "case1",
  "catch1", "char1", "class1", "const1", "underscore", "continue1",
  "default1", "do1", "double1", "else1", "enum1", "extends", "final",
  "finally", "float1", "for1", "if1", "goto1", "implements", "import",
  "instanceof", "int1", "interface", "long1", "native", "new1", "package",
  "private1", "protected1", "public1", "return1", "static1", "strictfp",
  "short1", "super", "switch1", "synchronised", "this1", "throw1",
  "throws", "transient", "try1", "void1", "volatile1", "while1", "exports",
  "module1", "NonSealed", "open", "opens", "permits", "provides", "record",
  "requires1", "sealed", "to", "transitive", "uses", "var", "with",
  "yield", "decint", "octint", "hexint", "binint", "hexfloat1", "decfloat",
  "BooleanLiteral", "charlit", "string1", "textblock", "NullLiteral",
  "comma", "semicolon", "period", "open_bracket", "closed_bracket",
  "open_square_bracket", "closed_square_bracket", "dots_three", "at",
  "colon_colon", "open_flower_bracket", "closed_flower_bracket", "equal1",
  "diamond", "gthan", "lthan", "exclamatory", "notk", "qmark", "colon",
  "implies", "equal_equal", "g_equal", "l_equal", "exclamatory_equal",
  "and_and", "or1", "increment", "decrement", "plus_1", "minus_1",
  "multiply", "divide", "band", "bor", "power", "percentage", "llthan",
  "ggthan", "gggthan", "plus_equal", "minus_equal", "multiply_equal",
  "divide_equal", "bitor_equal", "bitand_equal", "power_equal",
  "percentage_equal", "ll_equal", "gg_equal", "ggg_equal", "$accept",
  "Identifier", "Literal", "Type", "PrimitiveType", "NumericType",
  "IntegralType", "FloatingPointType", "ReferenceType", "ArrayType",
  "Name", "QualifiedName", "CompilationUnit", "PackageDeclarationopt",
  "ImportDeclarationsopt", "TypeDeclarationsopt", "ImportDeclarations",
  "TypeDeclarations", "PackageDeclaration", "ImportDeclaration",
  "SingleTypeImportDeclaration", "TypeImportOnDemandDeclaration",
  "TypeDeclaration", "Modifiers", "Modifier", "ClassDeclaration",
  "Modifiersopt", "Superopt", "Interfacesopt", "Super", "Interfaces",
  "InterfaceTypeList", "ClassBody", "ClassBodyDeclarationsopt",
  "ClassBodyDeclarations", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "VariableDeclarators",
  "VariableDeclarator", "VariableDeclaratorId", "VariableInitializer",
  "MethodDeclaration", "MethodHeader", "Throwsopt", "MethodDeclarator",
  "FormalParameterListopt", "FormalParameterList", "FormalParameter",
  "Throws", "ClassTypeList", "MethodBody", "StaticInitializer",
  "ConstructorDeclaration", "ConstructorDeclarator", "ConstructorBody",
  "BlockStatementsopt", "ExplicitConstructorInvocationopt",
  "ExplicitConstructorInvocation", "ArgumentListopt",
  "InterfaceDeclaration", "ExtendsInterfacesopt", "ExtendsInterfaces",
  "InterfaceBody", "InterfaceMemberDeclarationsopt",
  "InterfaceMemberDeclarations", "InterfaceMemberDeclaration",
  "AbstractMethodDeclaration", "ArrayInitializer", "commaopt",
  "VariableInitializersopt", "VariableInitializers", "Block",
  "BlockStatements", "BlockStatement", "LocalVariableDeclarationStatement",
  "LocalVariableDeclaration", "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "IfThenStatement", "IfThenElseStatement",
  "IfThenElseStatementNoShortIf", "SwitchStatement", "SwitchBlock",
  "SwitchBlockStatementGroupsopt", "SwitchLabelsopt",
  "SwitchBlockStatementGroups", "SwitchBlockStatementGroup",
  "SwitchLabels", "SwitchLabel", "WhileStatement",
  "WhileStatementNoShortIf", "DoStatement", "ForStatement",
  "ForStatementNoShortIf", "ForInitopt", "Expressionopt", "ForUpdateopt",
  "ForInit", "ForUpdate", "StatementExpressionList", "BreakStatement",
  "ContinueStatement", "Identifieropt", "ReturnStatement",
  "ThrowStatement", "SynchronizedStatement", "TryStatement", "Catchesopt",
  "Catches", "CatchClause", "Finally", "Primary", "PrimaryNoNewArray",
  "ClassInstanceCreationExpression", "ArgumentList",
  "ArrayCreationExpression", "Dimsopt", "DimExprs", "DimExpr", "Dims",
  "FieldAccess", "MethodInvocation", "ArrayAccess", "PostfixExpression",
  "PostIncrementExpression", "PostDecrementExpression", "UnaryExpression",
  "PreIncrementExpression", "PreDecrementExpression",
  "UnaryExpressionNotPlusMinus", "CastExpression",
  "MultiplicativeExpression", "AdditiveExpression", "ShiftExpression",
  "RelationalExpression", "EqualityExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression",
  "ConditionalAndExpression", "ConditionalOrExpression",
  "AssignmentExpression", "Assignment", "LeftHandSide",
  "AssignmentOperator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-469)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-317)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      30,    74,    94,    75,  -469,  -469,  -469,    29,  -469,  -469,
      74,   548,    75,  -469,  -469,  -469,    74,    38,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    1624,  -469,   750,  -469,  -469,    12,  -469,  -469,  -469,  -469,
      10,  -469,  -469,    74,    74,    34,   109,   121,  -469,    74,
      99,  -469,    74,    60,    72,    29,    74,    70,  -469,    29,
       9,  -469,    74,    29,    87,   174,  -469,   517,  -469,    88,
      82,   238,  -469,  -469,    29,    74,    92,   517,    86,   629,
    -469,  -469,  -469,  -469,   -43,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,    74,    74,   104,  -469,  -469,
    -469,  -469,   108,   -52,  -469,  -469,  -469,    29,  1369,  -469,
     112,   182,  -469,  -469,  -469,  -469,  -469,   154,   -29,   154,
     119,  -469,   -58,   -29,   152,   153,   155,    74,    74,  1449,
     159,   161,   938,  1178,   164,   165,   166,  -469,  1178,    92,
     167,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  1178,  1178,  1178,    71,  -469,    74,    13,
     172,   156,  -469,  1369,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,   175,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,   171,   178,    -2,  -469,   611,
      78,   777,    95,    97,   107,  -469,  -469,  -469,   961,   938,
      74,   169,  -469,   938,   180,  -469,    74,  -469,   181,  1031,
    -469,  -469,  -469,  -469,  -469,   187,   188,   173,   -10,   212,
    1609,  1178,   191,    89,   917,  1178,  1178,  1178,  1178,   200,
    -469,  -469,    95,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
     -19,   111,    67,    11,     3,   177,   179,   170,   190,   186,
    -469,  -469,    74,  1178,  1178,   206,   285,  1178,   213,    98,
    -469,  -469,  -469,  -469,  1449,  -469,   172,  1178,  1080,   205,
    -469,  -469,  -469,    74,  1178,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  1178,
      74,   214,   221,  -469,    29,   223,   106,  -469,   227,  -469,
    -469,  -469,  1031,  -469,  -469,  -469,  -469,  -469,  1178,   229,
     -49,  -469,  -469,   232,  -469,   234,   231,  1178,   233,  -469,
    1178,   233,   235,    41,   237,  -469,  -469,  -469,  -469,  -469,
    1178,  1178,  1178,  1178,  1178,  1178,  1178,  1178,   938,  1178,
    1178,  1178,  1178,  1178,  1178,  1178,  1178,  1178,  1178,  1178,
     239,   240,   242,  -469,   244,   295,    15,  -469,   247,  -469,
    -469,   249,   243,  -469,   248,  -469,   245,   250,  -469,   252,
    -469,   938,    74,   257,   262,  1369,  -469,  -469,  -469,   255,
     269,  1178,  1178,  1433,  1529,   264,  1129,  -469,  -469,   266,
     270,  -469,   267,   271,  1129,   132,   299,  -469,  -469,  -469,
     -19,   -19,   111,   111,   111,   104,  -469,    67,    67,    67,
      67,    11,    11,     3,   177,   179,   170,   190,  1178,   268,
      92,   938,    92,  -469,  -469,  1449,  -469,  1178,  -469,  1178,
    -469,  -469,    29,  1178,  1178,   288,  -469,   290,  1031,   273,
     278,  -469,   277,   279,   300,   226,  -469,   344,   367,  -469,
    -469,  -469,  -469,  -469,  -469,   301,  -469,  1178,   299,  -469,
     304,    47,  -469,  -469,   305,  -469,  -469,  -469,   306,   307,
     309,  -469,  -469,  -469,   313,  1433,  1609,  1178,  1178,  1529,
    1449,  -469,  -469,  -469,  -469,  1178,   286,    47,    47,  -469,
    1289,  -469,    92,  -469,   316,   318,  -469,   319,  -469,   234,
     321,   320,   323,  -469,  -469,   310,  -469,   314,    47,  -469,
    1369,  -469,  -469,  -469,  -469,  1449,  1178,  1529,  1529,  -469,
    -469,  -469,   352,   391,  -469,  1433,  1529,   353,  -469,  1529,
    -469
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      36,     0,     0,    38,    37,     2,    32,    46,    33,     1,
       0,    67,    39,    42,    47,    48,     0,     0,    60,    61,
      62,    58,    57,    56,    59,    63,    64,    65,    53,    35,
      67,    44,    68,    54,    51,     0,    52,    43,    34,    49,
       0,    45,    55,     0,     0,     0,    69,   126,    50,     0,
      71,    70,     0,     0,   127,    73,     0,     0,    72,   128,
      67,   125,     0,    75,    74,    67,    66,     0,   135,     0,
       0,    67,   133,   136,   129,     0,    59,     0,     0,    67,
      80,    82,    85,    86,     0,    83,    84,    17,    20,    24,
      26,    25,    22,    23,    21,     0,     0,    14,    16,    18,
      19,    15,    28,    27,   137,   130,   134,    76,   117,   113,
      32,    99,    77,    81,   112,    96,   111,     0,    99,    92,
       0,    88,    90,    99,     0,     0,     0,   220,   220,     0,
       0,     0,     0,   209,     0,     0,     0,   236,     0,     0,
       0,     3,     4,     6,     5,     7,     8,     9,    10,    11,
      12,    13,   175,     0,     0,     0,    92,   235,     0,   262,
     152,     0,   164,   118,   146,   148,   150,   149,   153,   165,
     154,   166,     0,   155,   156,   167,   157,   168,   158,   169,
     170,   171,   173,   172,   174,   261,   233,   238,   234,   239,
     240,   241,     0,   182,   183,   180,   181,   179,     0,   103,
       0,     0,   100,   103,     0,    98,     0,    87,     0,     0,
      97,    29,    31,    30,   221,     0,     0,    32,   262,     0,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,   240,   274,   263,   264,   281,   267,   268,   271,   277,
     285,   288,   292,   298,   301,   303,   305,   307,   309,   311,
     210,   312,     0,     0,     0,     0,   227,     0,     0,   262,
     239,   241,   272,   273,     0,    92,   151,   123,     0,     0,
     145,   147,   178,     0,     0,   265,   266,   317,   321,   322,
     318,   319,   328,   327,   326,   320,   323,   324,   325,     0,
       0,     0,   104,   105,   109,   108,   119,   114,     0,   102,
      89,    93,   141,    91,    95,    94,   218,   219,     0,     0,
      32,   214,   216,     0,   208,   213,     0,     0,   247,   249,
     123,   247,   247,   262,     0,   276,   275,   269,   270,   222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,     0,   223,     0,     0,   225,   229,     0,   237,
     176,     0,   124,   243,     0,   314,   254,     0,   313,   107,
     115,     0,     0,     0,     0,   117,   120,   101,   143,   139,
     142,     0,   209,     0,     0,     0,     0,   245,   250,   248,
       0,   246,     0,     0,     0,     0,   237,   282,   283,   284,
     286,   287,   289,   290,   291,     0,   297,   294,   293,   296,
     295,   299,   300,   302,   304,   306,   308,   310,   123,     0,
       0,     0,     0,   226,   230,     0,   256,     0,   259,   123,
     260,   106,   110,   123,   123,     0,   140,     0,     0,     0,
       0,   217,     0,     0,     0,    32,   186,     0,   153,   160,
     161,   162,   163,   251,   252,     0,   242,     0,     0,   279,
       0,   191,   189,   224,     0,   232,   202,   244,     0,     0,
       0,   116,   138,   144,     0,   211,   207,     0,     0,     0,
       0,   253,   278,   280,   258,     0,     0,   193,   192,   195,
       0,   198,     0,   257,     0,     0,   204,     0,   212,   215,
       0,     0,     0,   177,   187,     0,   201,     0,   194,   196,
     197,   199,   231,   122,   121,     0,   209,     0,     0,   200,
     190,   205,     0,     0,   203,   211,     0,     0,   188,     0,
     206
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -469,   -16,  -469,   -66,  -127,  -469,  -469,  -469,   103,  -469,
      83,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,   431,
    -469,  -469,   414,  -469,   413,  -469,    65,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,   370,  -469,   -36,   -87,   246,
     160,  -290,  -469,   -27,   -50,   350,   256,  -469,  -352,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,    76,  -469,  -469,  -314,
    -469,  -469,  -469,  -469,  -469,  -469,   382,  -469,  -469,  -469,
    -469,  -469,   -53,   -28,  -160,  -469,  -218,    17,  -464,  -377,
    -469,  -469,  -469,  -469,  -212,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,   -23,   -21,  -468,  -469,  -469,  -469,  -469,
    -469,    -9,  -378,   -56,  -469,  -469,  -455,  -469,  -469,   342,
    -469,  -469,  -469,  -469,  -469,  -469,   115,  -469,  -469,  -469,
     -42,  -469,  -469,   -95,   258,  -263,   149,   550,   102,   706,
     125,   131,   183,  -137,   241,   327,  -386,  -469,  -104,  -136,
    -173,  -109,   135,   136,   141,   143,   140,  -469,   541,   349,
    -469,  -469
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   157,   158,    97,    98,    99,   100,   101,   102,
     218,     8,     2,     3,    11,    29,    12,    30,     4,    13,
      14,    15,    31,    32,    33,    34,    35,    50,    57,    51,
      58,    64,    66,    78,    79,    80,    81,    68,   160,   121,
     122,   303,    83,    69,   201,   118,   291,   292,   293,   202,
     295,   115,    85,    86,   111,   297,   161,   375,   376,   361,
      36,    53,    54,    61,    70,    71,    72,    73,   304,   437,
     379,   380,   162,   163,   164,   165,   166,   167,   447,   168,
     169,   170,   449,   171,   172,   173,   174,   450,   175,   462,
     487,   507,   488,   489,   490,   491,   176,   451,   177,   178,
     452,   313,   229,   497,   314,   498,   315,   179,   180,   215,
     181,   182,   183,   184,   355,   356,   357,   423,   185,   186,
     230,   362,   188,   387,   318,   319,   389,   189,   231,   191,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   363,   251,
     198,   289
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    96,   311,   271,   440,   222,   390,   448,   312,   120,
     459,    96,   378,     5,    18,   503,   -27,   262,   263,   431,
     499,   200,   511,   109,    38,    43,   354,    46,    47,    82,
     208,   116,    19,    16,   -92,   -92,   126,   209,    84,  -228,
     511,   114,   338,    82,    20,    44,   -92,    21,    22,    23,
     108,    24,    84,   523,   524,   388,    25,   485,   388,   204,
      26,   110,   528,    27,   486,   530,   187,     1,   205,   464,
     499,   266,   483,   210,   -32,    16,   267,     5,   308,   117,
     119,  -185,  -185,   269,     7,  -185,   256,   187,   325,   326,
     327,   328,   156,    17,     9,   330,   331,   322,    16,   267,
     332,   268,   448,  -131,   460,    10,   269,   343,   339,   340,
     344,   214,   214,   217,    16,   468,   341,   342,    48,   469,
     470,   187,    39,    40,    45,    67,    16,   267,    56,   394,
      77,    49,    55,   290,   269,    59,    67,   290,   522,    63,
     448,   448,   265,    52,    77,    74,   219,   156,   473,   448,
     103,   373,   448,    60,   374,    62,   -32,   -32,   107,   -32,
     103,  -184,  -184,    65,   -32,  -184,   407,   408,   409,   410,
      75,   441,   104,   264,    16,   320,   105,   317,   187,    18,
     112,   -32,   -32,    16,   267,   108,   308,   335,   336,   337,
     265,   159,   124,   397,   398,   399,   125,    19,   199,   402,
     403,   404,   206,   207,   310,   275,   276,  -263,  -263,    20,
     190,   405,    21,    22,    23,   223,    76,  -264,  -264,   458,
     455,    25,   187,   333,   334,    26,   391,   393,    27,   400,
     401,   190,   200,   192,   411,   412,   350,   259,   259,   193,
     203,   211,   212,    18,   213,   220,   159,   221,   217,   252,
     270,   253,   254,   257,   192,   206,   273,   366,   311,   272,
     193,    19,   296,   312,   312,   190,   274,   309,   -78,   299,
     301,   306,   307,    20,   265,   264,    21,    22,    23,   317,
      24,   360,   103,   294,   329,    25,   103,   347,   192,    26,
     353,   194,    27,   345,   193,   349,   354,   346,   348,   365,
     359,   370,     5,   159,   371,   290,   372,   323,   259,   259,
     259,   259,   194,   312,   377,   381,   382,   383,   384,   422,
     482,   386,   190,   392,   396,   418,   427,   419,   479,   420,
     421,   429,  -132,   187,   425,   132,   426,   428,   436,   430,
     208,   187,   187,   433,   134,   192,   194,   137,   434,   195,
     271,   193,   438,   453,   455,   290,   454,   456,   457,   156,
     474,   461,   475,   476,   480,   477,   190,   463,   445,   465,
     195,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   471,   187,   472,   224,   478,  -159,   506,   192,
     481,   484,   492,   493,   494,   193,   495,   496,   225,   226,
     513,   446,   514,   194,   195,   516,   515,   517,   520,   217,
     518,   526,   519,   259,   259,   259,   259,   259,   259,   259,
     259,   103,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   187,   187,   196,   525,   187,   187,   512,
     529,   406,   466,    37,    41,    42,   123,   194,   187,   113,
     369,   435,   300,   106,   103,   432,   196,   197,   159,   298,
     310,   195,   510,   445,   217,   509,   508,   500,   187,   527,
     216,   424,   395,   187,   156,   187,   187,   190,   197,   259,
     413,   321,   414,   187,   187,   190,   190,   187,   415,   417,
     196,   416,     0,     0,   156,     0,   360,   504,     0,   217,
     192,   445,   445,     0,   103,   195,   193,     0,   192,   192,
     445,     0,   197,   445,   193,   193,     0,     0,     0,     0,
       5,     0,     0,     0,    87,     0,    88,   190,     0,    89,
       0,     0,   521,     0,   446,   466,    90,     0,     0,     0,
     259,   259,    91,   504,     0,     0,   521,   196,   -40,    92,
     192,    93,     0,    18,     0,     0,   193,     0,   194,   159,
       0,    94,     0,     0,     0,     0,   194,   194,     0,   197,
      95,    19,     0,   159,     0,     0,     0,   190,   190,     0,
       0,   190,   190,    20,     0,     0,    21,    22,    23,     0,
      24,   196,   190,   159,     0,    25,     0,     0,     0,    26,
     192,   192,    27,     0,   192,   192,   193,   193,   194,     0,
     193,   193,   190,   197,     0,   192,   195,   190,     0,   190,
     190,   193,     0,     0,   195,   195,     0,   190,   190,     0,
       0,   190,    28,     0,    18,   192,     0,     0,     0,     0,
     192,   193,   192,   192,     0,     0,   193,     0,   193,   193,
     192,   192,    19,     0,   192,     0,   193,   193,   194,   194,
     193,     0,   194,   194,    20,     0,   195,    21,    22,    23,
       0,    76,     0,   194,   250,     0,    25,     0,     0,   255,
      26,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   258,     0,     0,     0,   194,     0,
     194,   194,   196,     0,   260,   260,  -315,     0,   194,   194,
     196,   196,   194,     0,     0,     0,   195,   195,     0,     0,
     195,   195,     0,   -79,   197,     0,     0,     0,     0,     0,
       0,   195,   197,   197,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,     0,     0,     0,     0,     0,
     305,   195,   196,     0,     0,    18,   195,     0,   195,   195,
       0,     0,   316,     0,     0,   324,   195,   195,     0,     0,
     195,     0,     0,    19,   197,   260,   260,   260,   260,     0,
       0,     0,     0,     0,     0,    20,     0,     0,    21,    22,
      23,     0,    24,     0,   351,   352,     0,    25,   358,     0,
       0,    26,   196,   196,    27,     0,   196,   196,     0,   364,
       0,     0,     0,     0,     0,   367,     0,   196,     0,     0,
       0,     0,     0,     0,   197,   197,     0,     0,   197,   197,
     368,     0,     0,     0,     0,     0,     0,   196,     0,   197,
       0,     0,   196,   305,   196,   196,     0,     0,     0,   364,
       0,     0,   196,   196,     0,     0,   196,     0,   385,   197,
     261,   261,     0,     0,   197,     0,   197,   197,     0,     0,
       0,     0,  -316,     0,   197,   197,     0,     0,   197,     0,
     260,   260,   260,   260,   260,   260,   260,   260,     0,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
    -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  -316,
    -316,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,   439,   250,    87,     0,    88,   385,     0,    89,
       0,   261,   261,   261,   261,   364,    90,     0,     0,     0,
       0,     5,    91,     0,     0,    87,   260,    88,     0,    92,
      89,    93,     0,   132,     0,     0,     0,    90,     0,     0,
       0,    94,   134,    91,     0,   137,     0,     0,   467,     0,
      92,     0,    93,     0,     0,     0,     0,     0,     0,   305,
       0,     0,    94,     0,     0,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,     0,     0,   224,     0,     0,     0,   260,   260,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   501,   502,
       0,     0,     0,     0,     0,     0,   505,   154,   155,   227,
     228,     0,     0,     0,     5,     0,   261,   261,   261,   261,
     261,   261,   261,   261,     0,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   277,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,     0,   137,
       0,     0,     0,     5,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,     0,     0,     0,     0,     0,
       0,     0,   261,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,   132,   224,     0,     0,
       0,     0,     0,     0,   302,   134,     0,     0,   137,     0,
     225,   226,     5,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   155,   227,   228,     0,     0,     0,     0,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   261,   261,   132,   224,     0,     0,   213,
       0,     0,     0,     0,   134,     0,     0,   137,     0,   225,
     226,     5,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,   227,   228,     0,     0,     0,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,   132,   224,     0,     0,   454,     0,
       0,     0,     0,   134,     0,     0,   137,     0,   225,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
     155,   227,   228,     0,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   155,
     227,   228,     5,     0,     0,     0,    87,   127,    88,   485,
       0,    89,     0,     0,     0,   128,   486,   129,    90,     0,
       0,     0,     0,     0,    91,   130,   131,     0,     0,     0,
       0,    92,     0,    93,     0,   132,     0,     0,     0,     0,
     133,     0,     0,    94,   134,   135,   136,   137,   138,     0,
       0,   139,     0,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     5,   152,     0,   153,    87,   127,    88,     0,
       0,    89,   108,     0,     0,   128,     0,   129,    90,     0,
       0,     0,     0,     0,    91,   130,   131,     0,     0,   154,
     155,    92,     0,    93,     0,   132,     0,     0,     0,     0,
     133,     0,     0,    94,   134,   135,   136,   137,   138,     0,
       0,   139,     0,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     5,   152,     0,   153,     0,   127,     0,     0,
       0,     0,   108,     0,     0,   128,     0,   129,     0,   132,
       0,     0,     0,     0,     0,   130,   131,     0,   134,   154,
     155,   137,     0,     0,     0,   132,     0,     0,     0,     0,
     133,     0,     0,     0,   134,   135,   136,   137,   138,     0,
       0,   139,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,     0,     0,   153,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     5,   152,     0,   153,     0,   127,     0,     0,
       0,     0,   108,   154,   155,   128,     0,   129,     0,     0,
       0,     0,     0,     0,     0,   442,   443,     0,     0,   154,
     155,     0,     0,     0,     0,   132,     0,     0,     0,     0,
     133,     0,     0,     0,   134,   135,   136,   137,   138,     0,
       0,   139,     0,     0,   444,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     5,   152,     0,   153,    87,     0,    88,     0,
       0,    89,   108,     0,   -41,     0,     0,     0,    90,    18,
       0,     0,     0,     0,    91,     0,     0,     0,     0,   154,
     155,    92,     0,    93,     0,   132,     0,    19,     0,     0,
       0,     0,     0,    94,   134,     0,     0,   137,     0,    20,
       0,     0,    21,    22,    23,     0,    24,     0,     0,     0,
       0,    25,     0,     0,     0,    26,     0,     0,    27,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,     0,   153,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
     155
};

static const yytype_int16 yycheck[] =
{
      16,    67,   220,   163,   382,   132,   320,   384,   220,    96,
     396,    77,   302,     3,     5,   479,     3,   154,   155,   371,
     475,    50,   490,    76,    40,    13,    11,    43,    44,    65,
      88,    84,    23,    85,    83,    84,    88,    95,    65,    24,
     508,    84,    31,    79,    35,    33,    95,    38,    39,    40,
      93,    42,    79,   517,   518,   318,    47,    10,   321,    88,
      51,    77,   526,    54,    17,   529,   108,    37,   118,   421,
     525,   158,   458,   123,     3,    85,    86,     3,    88,    95,
      96,    83,    84,    93,     1,    87,   139,   129,   225,   226,
     227,   228,   108,    10,     0,   114,   115,   224,    85,    86,
     119,    88,   479,    94,   418,    30,    93,   104,    97,    98,
     107,   127,   128,   129,    85,   429,   105,   106,    84,   433,
     434,   163,    84,    85,   114,    60,    85,    86,    29,    88,
      65,    22,    49,   199,    93,    52,    71,   203,   516,    56,
     517,   518,   158,    22,    79,    62,   129,   163,   438,   526,
      67,    45,   529,    93,    48,    83,    85,    86,    75,    88,
      77,    83,    84,    93,    93,    87,   339,   340,   341,   342,
      83,   383,    84,   102,    85,    86,    94,    88,   220,     5,
      94,   110,   111,    85,    86,    93,    88,   120,   121,   122,
     206,   108,    88,   330,   331,   332,    88,    23,    86,   335,
     336,   337,    83,    84,   220,   110,   111,   110,   111,    35,
     108,   338,    38,    39,    40,   132,    42,   110,   111,    87,
      88,    47,   264,   112,   113,    51,   321,   322,    54,   333,
     334,   129,    50,   108,   343,   344,   252,   154,   155,   108,
      86,    89,    89,     5,    89,    86,   163,    86,   264,    85,
      94,    86,    86,    86,   129,    83,    85,   273,   476,    84,
     129,    23,    93,   475,   476,   163,    88,    55,    94,    89,
      89,    84,    84,    35,   290,   102,    38,    39,    40,    88,
      42,   264,   199,   200,    84,    47,   203,   117,   163,    51,
      84,   108,    54,   116,   163,   109,    11,   118,   108,    94,
      87,    87,     3,   220,    83,   371,    83,   224,   225,   226,
     227,   228,   129,   525,    87,    86,    84,    83,    87,    24,
     457,    88,   220,    88,    87,    86,    83,    87,   102,    87,
      86,    86,    94,   375,    87,    36,    87,    89,    83,    89,
      88,   383,   384,    86,    45,   220,   163,    48,    86,   108,
     510,   220,    83,    89,    88,   421,    89,    87,    87,   375,
      87,    93,    84,    86,    20,    86,   264,   420,   384,   422,
     129,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    94,   425,    94,    86,    86,    20,   102,   264,
      89,    87,    87,    87,    87,   264,    87,    84,    99,   100,
      84,   384,    84,   220,   163,    84,    87,    87,    94,   425,
      87,    20,   102,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   475,   476,   108,    84,   479,   480,   492,
      87,   338,   425,    12,    30,    32,    96,   264,   490,    79,
     290,   375,   206,    71,   371,   372,   129,   108,   375,   203,
     476,   220,   490,   479,   480,   488,   487,   476,   510,   525,
     128,   356,   323,   515,   490,   517,   518,   375,   129,   396,
     345,   223,   346,   525,   526,   383,   384,   529,   347,   349,
     163,   348,    -1,    -1,   510,    -1,   479,   480,    -1,   515,
     375,   517,   518,    -1,   421,   264,   375,    -1,   383,   384,
     526,    -1,   163,   529,   383,   384,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,     7,    -1,     9,   425,    -1,    12,
      -1,    -1,   515,    -1,   517,   518,    19,    -1,    -1,    -1,
     457,   458,    25,   526,    -1,    -1,   529,   220,     0,    32,
     425,    34,    -1,     5,    -1,    -1,   425,    -1,   375,   476,
      -1,    44,    -1,    -1,    -1,    -1,   383,   384,    -1,   220,
      53,    23,    -1,   490,    -1,    -1,    -1,   475,   476,    -1,
      -1,   479,   480,    35,    -1,    -1,    38,    39,    40,    -1,
      42,   264,   490,   510,    -1,    47,    -1,    -1,    -1,    51,
     475,   476,    54,    -1,   479,   480,   475,   476,   425,    -1,
     479,   480,   510,   264,    -1,   490,   375,   515,    -1,   517,
     518,   490,    -1,    -1,   383,   384,    -1,   525,   526,    -1,
      -1,   529,    84,    -1,     5,   510,    -1,    -1,    -1,    -1,
     515,   510,   517,   518,    -1,    -1,   515,    -1,   517,   518,
     525,   526,    23,    -1,   529,    -1,   525,   526,   475,   476,
     529,    -1,   479,   480,    35,    -1,   425,    38,    39,    40,
      -1,    42,    -1,   490,   133,    -1,    47,    -1,    -1,   138,
      51,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   510,   153,    -1,    -1,    -1,   515,    -1,
     517,   518,   375,    -1,   154,   155,    95,    -1,   525,   526,
     383,   384,   529,    -1,    -1,    -1,   475,   476,    -1,    -1,
     479,   480,    -1,    94,   375,    -1,    -1,    -1,    -1,    -1,
      -1,   490,   383,   384,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
     209,   510,   425,    -1,    -1,     5,   515,    -1,   517,   518,
      -1,    -1,   221,    -1,    -1,   224,   525,   526,    -1,    -1,
     529,    -1,    -1,    23,   425,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    39,
      40,    -1,    42,    -1,   253,   254,    -1,    47,   257,    -1,
      -1,    51,   475,   476,    54,    -1,   479,   480,    -1,   268,
      -1,    -1,    -1,    -1,    -1,   274,    -1,   490,    -1,    -1,
      -1,    -1,    -1,    -1,   475,   476,    -1,    -1,   479,   480,
     289,    -1,    -1,    -1,    -1,    -1,    -1,   510,    -1,   490,
      -1,    -1,   515,   302,   517,   518,    -1,    -1,    -1,   308,
      -1,    -1,   525,   526,    -1,    -1,   529,    -1,   317,   510,
     154,   155,    -1,    -1,   515,    -1,   517,   518,    -1,    -1,
      -1,    -1,    95,    -1,   525,   526,    -1,    -1,   529,    -1,
     330,   331,   332,   333,   334,   335,   336,   337,    -1,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,   381,   382,     7,    -1,     9,   386,    -1,    12,
      -1,   225,   226,   227,   228,   394,    19,    -1,    -1,    -1,
      -1,     3,    25,    -1,    -1,     7,   396,     9,    -1,    32,
      12,    34,    -1,    36,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    44,    45,    25,    -1,    48,    -1,    -1,   427,    -1,
      32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,   438,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    86,    -1,    -1,    -1,   457,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   477,   478,
      -1,    -1,    -1,    -1,    -1,    -1,   485,   110,   111,   112,
     113,    -1,    -1,    -1,     3,    -1,   330,   331,   332,   333,
     334,   335,   336,   337,    -1,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,    95,   516,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,
      -1,    -1,    -1,     3,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   396,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    36,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    45,    -1,    -1,    48,    -1,
      99,   100,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,   457,   458,    36,    86,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    -1,    99,
     100,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    36,    86,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    48,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,     3,    -1,    -1,    -1,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    44,    45,    46,    47,    48,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     3,    84,    -1,    86,     7,     8,     9,    -1,
      -1,    12,    93,    -1,    -1,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,   110,
     111,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    44,    45,    46,    47,    48,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     3,    84,    -1,    86,    -1,     8,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    16,    -1,    18,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    45,   110,
     111,    48,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    47,    48,    49,    -1,
      -1,    52,    -1,    -1,    55,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    -1,    86,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     3,    84,    -1,    86,    -1,     8,    -1,    -1,
      -1,    -1,    93,   110,   111,    16,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    47,    48,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     3,    84,    -1,    86,     7,    -1,     9,    -1,
      -1,    12,    93,    -1,     0,    -1,    -1,    -1,    19,     5,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,   110,
     111,    32,    -1,    34,    -1,    36,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    48,    -1,    35,
      -1,    -1,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    37,   146,   147,   152,     3,   135,   144,   145,     0,
      30,   148,   150,   153,   154,   155,    85,   144,     5,    23,
      35,    38,    39,    40,    42,    47,    51,    54,    84,   149,
     151,   156,   157,   158,   159,   160,   194,   153,   135,    84,
      85,   156,   158,    13,    33,   114,   135,   135,    84,    22,
     161,   163,    22,   195,   196,   144,    29,   162,   164,   144,
      93,   197,    83,   144,   165,    93,   166,   160,   171,   177,
     198,   199,   200,   201,   144,    83,    42,   160,   167,   168,
     169,   170,   171,   176,   177,   186,   187,     7,     9,    12,
      19,    25,    32,    34,    44,    53,   137,   138,   139,   140,
     141,   142,   143,   144,    84,    94,   200,   144,    93,   206,
     135,   188,    94,   169,    84,   185,   206,   135,   179,   135,
     172,   173,   174,   179,    88,    88,    88,     8,    16,    18,
      26,    27,    36,    41,    45,    46,    47,    48,    49,    52,
      55,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    84,    86,   110,   111,   135,   136,   137,   144,
     172,   190,   206,   207,   208,   209,   210,   211,   213,   214,
     215,   217,   218,   219,   220,   222,   230,   232,   233,   241,
     242,   244,   245,   246,   247,   252,   253,   254,   256,   261,
     262,   263,   264,   265,   266,   268,   269,   283,   284,    86,
      50,   178,   183,    86,    88,   178,    83,    84,    88,    95,
     178,    89,    89,    89,   135,   243,   243,   135,   144,   211,
      86,    86,   138,   144,    86,    99,   100,   112,   113,   236,
     254,   262,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,    85,    86,    86,   282,   206,    86,   282,   144,
     261,   263,   267,   267,   102,   135,   172,    86,    88,    93,
      94,   208,    84,    85,    88,   110,   111,    95,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   285,
     137,   180,   181,   182,   144,   184,    93,   189,   180,    89,
     173,    89,    93,   175,   202,   282,    84,    84,    88,    55,
     135,   210,   218,   235,   238,   240,   282,    88,   258,   259,
      86,   258,   138,   144,   282,   267,   267,   267,   267,    84,
     114,   115,   119,   112,   113,   120,   121,   122,    31,    97,
      98,   105,   106,   104,   107,   116,   118,   117,   108,   109,
     135,   282,   282,    84,    11,   248,   249,   250,   282,    87,
     211,   193,   255,   282,   282,    94,   135,   282,   282,   174,
      87,    83,    83,    45,    48,   191,   192,    87,   175,   204,
     205,    86,    84,    83,    87,   282,    88,   257,   259,   260,
     193,   257,    88,   257,    88,   260,    87,   267,   267,   267,
     272,   272,   273,   273,   273,   138,   142,   274,   274,   274,
     274,   275,   275,   276,   277,   278,   279,   280,    86,    87,
      87,    86,    24,   251,   250,    87,    87,    83,    89,    86,
      89,   182,   144,    86,    86,   190,    83,   203,    83,   282,
     236,   218,    26,    27,    55,   135,   211,   212,   213,   216,
     221,   231,   234,    89,    89,    88,    87,    87,    87,   270,
     193,    93,   223,   206,   182,   206,   211,   282,   193,   193,
     193,    94,    94,   175,    87,    84,    86,    86,    86,   102,
      20,    89,   267,   270,    87,    10,    17,   224,   226,   227,
     228,   229,    87,    87,    87,    87,    84,   237,   239,   240,
     235,   282,   282,   212,   211,   282,   102,   225,   228,   227,
     207,   229,   206,    84,    84,    87,    84,    87,    87,   102,
      94,   211,   236,   212,   212,    84,    20,   237,   212,    87,
     212
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   134,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   140,   140,   140,   141,   141,   142,   142,   143,
     143,   143,   144,   144,   145,   146,   147,   147,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   153,   153,   154,
     155,   156,   156,   156,   157,   157,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   159,   160,   160,   161,
     161,   162,   162,   163,   164,   165,   165,   166,   167,   167,
     168,   168,   169,   169,   169,   170,   170,   171,   172,   172,
     173,   173,   174,   174,   175,   175,   176,   177,   177,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   183,   184,
     184,   185,   185,   186,   187,   188,   189,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   195,   195,   196,   196,
     197,   198,   198,   199,   199,   200,   200,   201,   202,   203,
     203,   204,   204,   205,   205,   206,   207,   207,   208,   208,
     209,   210,   210,   211,   211,   211,   211,   211,   211,   212,
     212,   212,   212,   212,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   214,   215,   216,   217,   218,
     218,   218,   218,   218,   218,   218,   219,   220,   221,   222,
     223,   224,   224,   225,   225,   226,   226,   227,   228,   228,
     229,   229,   230,   231,   232,   233,   234,   235,   235,   236,
     236,   237,   237,   238,   238,   239,   240,   240,   241,   242,
     243,   243,   244,   245,   246,   247,   247,   248,   248,   249,
     249,   250,   251,   252,   252,   253,   253,   253,   253,   253,
     253,   253,   254,   255,   255,   256,   256,   257,   257,   258,
     258,   259,   260,   260,   261,   261,   262,   262,   262,   263,
     263,   264,   264,   264,   264,   265,   266,   267,   267,   267,
     267,   267,   268,   269,   270,   270,   270,   270,   271,   271,
     271,   272,   272,   272,   272,   273,   273,   273,   274,   274,
     274,   274,   275,   275,   275,   275,   275,   275,   276,   276,
     276,   277,   277,   278,   278,   279,   279,   280,   280,   281,
     281,   282,   282,   283,   284,   284,   284,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     3,     3,     0,     1,     0,     1,
       0,     1,     1,     2,     1,     2,     2,     1,     1,     3,
       5,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     0,     1,     0,
       1,     0,     1,     2,     2,     1,     3,     3,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     1,     2,     4,     4,     0,
       1,     4,     3,     0,     1,     1,     3,     2,     2,     1,
       3,     1,     1,     2,     4,     4,     4,     0,     1,     0,
       1,     5,     5,     0,     1,     5,     0,     1,     2,     3,
       3,     0,     1,     1,     2,     1,     1,     2,     4,     0,
       1,     0,     1,     1,     3,     3,     1,     2,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     5,     7,     7,     5,
       4,     0,     1,     0,     1,     1,     2,     2,     1,     2,
       3,     2,     5,     5,     7,     9,     9,     0,     1,     0,
       1,     0,     1,     1,     1,     1,     1,     3,     3,     3,
       0,     1,     3,     3,     5,     3,     4,     0,     1,     1,
       2,     5,     2,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     5,     1,     3,     4,     4,     0,     1,     1,
       2,     3,     2,     3,     3,     3,     4,     6,     6,     4,
       4,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     1,     2,     2,     1,     2,     2,     1,     5,     4,
       5,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* Identifier: identifier  */
#line 184 "ast.ypp"
                      {(yyval.node)=fterminal_child("Identifier",(yyvsp[0].str));}
#line 2196 "ast.tab.cpp"
    break;

  case 3: /* Literal: decint  */
#line 186 "ast.ypp"
                {(yyval.node)=fterminal_child_int("Literal",(yyvsp[0].ival));}
#line 2202 "ast.tab.cpp"
    break;

  case 4: /* Literal: octint  */
#line 187 "ast.ypp"
        {(yyval.node)=fterminal_child_int("Literal",(yyvsp[0].ival));}
#line 2208 "ast.tab.cpp"
    break;

  case 5: /* Literal: binint  */
#line 188 "ast.ypp"
         {(yyval.node)=fterminal_child_int("Literal",(yyvsp[0].ival));}
#line 2214 "ast.tab.cpp"
    break;

  case 6: /* Literal: hexint  */
#line 189 "ast.ypp"
         {(yyval.node)=fterminal_child_int("Literal",(yyvsp[0].ival));}
#line 2220 "ast.tab.cpp"
    break;

  case 7: /* Literal: hexfloat1  */
#line 190 "ast.ypp"
            {(yyval.node)=fterminal_child_float("Literal",(yyvsp[0].fval));}
#line 2226 "ast.tab.cpp"
    break;

  case 8: /* Literal: decfloat  */
#line 191 "ast.ypp"
           {(yyval.node)=fterminal_child_float("Literal",(yyvsp[0].fval));}
#line 2232 "ast.tab.cpp"
    break;

  case 9: /* Literal: BooleanLiteral  */
#line 192 "ast.ypp"
                 {(yyval.node)=fterminal_child("Literal",(yyvsp[0].str));}
#line 2238 "ast.tab.cpp"
    break;

  case 10: /* Literal: charlit  */
#line 193 "ast.ypp"
          {(yyval.node)=fterminal_child("Literal",(yyvsp[0].str));}
#line 2244 "ast.tab.cpp"
    break;

  case 11: /* Literal: string1  */
#line 194 "ast.ypp"
          {string p=(yyvsp[0].str);p.erase(0,1);p.erase(p.size()-1,1);(yyval.node)=fterminal_child("Literal",p);}
#line 2250 "ast.tab.cpp"
    break;

  case 12: /* Literal: textblock  */
#line 195 "ast.ypp"
            {(yyval.node)=fterminal_child("Literal",(yyvsp[0].str));}
#line 2256 "ast.tab.cpp"
    break;

  case 13: /* Literal: NullLiteral  */
#line 196 "ast.ypp"
              {(yyval.node)=fterminal_child("Literal",(yyvsp[0].str));}
#line 2262 "ast.tab.cpp"
    break;

  case 14: /* Type: PrimitiveType  */
#line 198 "ast.ypp"
                  {(yyval.node)=fnon_terminalchild("Type",(yyvsp[0].node));}
#line 2268 "ast.tab.cpp"
    break;

  case 15: /* Type: ReferenceType  */
#line 200 "ast.ypp"
                 {(yyval.node)=fnon_terminalchild("Type",(yyvsp[0].node));}
#line 2274 "ast.tab.cpp"
    break;

  case 16: /* PrimitiveType: NumericType  */
#line 204 "ast.ypp"
                   {(yyval.node)=fnon_terminalchild("PrimitiveType",(yyvsp[0].node));}
#line 2280 "ast.tab.cpp"
    break;

  case 17: /* PrimitiveType: boolean  */
#line 206 "ast.ypp"
               {(yyval.node)=fterminal_child("PrimitiveType",(yyvsp[0].str));}
#line 2286 "ast.tab.cpp"
    break;

  case 18: /* NumericType: IntegralType  */
#line 210 "ast.ypp"
                    {(yyval.node)=fnon_terminalchild("NumericType",(yyvsp[0].node));}
#line 2292 "ast.tab.cpp"
    break;

  case 19: /* NumericType: FloatingPointType  */
#line 212 "ast.ypp"
                         {(yyval.node)=fnon_terminalchild("NumericType",(yyvsp[0].node));}
#line 2298 "ast.tab.cpp"
    break;

  case 20: /* IntegralType: byte1  */
#line 216 "ast.ypp"
             {(yyval.node)=fterminal_child("IntegralType",(yyvsp[0].str));}
#line 2304 "ast.tab.cpp"
    break;

  case 21: /* IntegralType: short1  */
#line 217 "ast.ypp"
              {(yyval.node)=fterminal_child("IntegralType",(yyvsp[0].str));}
#line 2310 "ast.tab.cpp"
    break;

  case 22: /* IntegralType: int1  */
#line 218 "ast.ypp"
            {(yyval.node)=fterminal_child("IntegralType",(yyvsp[0].str));}
#line 2316 "ast.tab.cpp"
    break;

  case 23: /* IntegralType: long1  */
#line 219 "ast.ypp"
             {(yyval.node)=fterminal_child("IntegralType",(yyvsp[0].str));}
#line 2322 "ast.tab.cpp"
    break;

  case 24: /* IntegralType: char1  */
#line 220 "ast.ypp"
           {(yyval.node)=fterminal_child("IntegralType",(yyvsp[0].str));}
#line 2328 "ast.tab.cpp"
    break;

  case 25: /* FloatingPointType: float1  */
#line 224 "ast.ypp"
               {(yyval.node)=fterminal_child("FloatingPointType",(yyvsp[0].str));}
#line 2334 "ast.tab.cpp"
    break;

  case 26: /* FloatingPointType: double1  */
#line 224 "ast.ypp"
                                                                    {(yyval.node)=fterminal_child("FloatingPointType",(yyvsp[0].str));}
#line 2340 "ast.tab.cpp"
    break;

  case 27: /* ReferenceType: Name  */
#line 228 "ast.ypp"
             {(yyval.node)=fnon_terminalchild("ReferenceType",(yyvsp[0].node));}
#line 2346 "ast.tab.cpp"
    break;

  case 28: /* ReferenceType: ArrayType  */
#line 230 "ast.ypp"
                 {(yyval.node)=fnon_terminalchild("ReferenceType",(yyvsp[0].node));}
#line 2352 "ast.tab.cpp"
    break;

  case 29: /* ArrayType: PrimitiveType open_square_bracket closed_square_bracket  */
#line 234 "ast.ypp"
                                                               {(yyval.node)=fnon_terminalchild("ArrayType",(yyvsp[-2].node));terminal_child((yyval.node),"ArrayType",(yyvsp[-1].str));terminal_child((yyval.node),"ArrayType",(yyvsp[0].str));}
#line 2358 "ast.tab.cpp"
    break;

  case 30: /* ArrayType: Name open_square_bracket closed_square_bracket  */
#line 236 "ast.ypp"
                                                      {(yyval.node)=fnon_terminalchild("ArrayType",(yyvsp[-2].node));terminal_child((yyval.node),"ArrayType",(yyvsp[-1].str));terminal_child((yyval.node),"ArrayType",(yyvsp[0].str));}
#line 2364 "ast.tab.cpp"
    break;

  case 31: /* ArrayType: ArrayType open_square_bracket closed_square_bracket  */
#line 238 "ast.ypp"
                                                           {(yyval.node)=fnon_terminalchild("ArrayType",(yyvsp[-2].node));terminal_child((yyval.node),"ArrayType",(yyvsp[-1].str));terminal_child((yyval.node),"ArrayType",(yyvsp[0].str));}
#line 2370 "ast.tab.cpp"
    break;

  case 32: /* Name: Identifier  */
#line 242 "ast.ypp"
                  {(yyval.node)=fnon_terminalchild("Name",(yyvsp[0].node));}
#line 2376 "ast.tab.cpp"
    break;

  case 33: /* Name: QualifiedName  */
#line 244 "ast.ypp"
                     {(yyval.node)=fnon_terminalchild("Name",(yyvsp[0].node));}
#line 2382 "ast.tab.cpp"
    break;

  case 34: /* QualifiedName: Name period Identifier  */
#line 248 "ast.ypp"
                              {(yyval.node)=nonopnon("QualifiedName",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2388 "ast.tab.cpp"
    break;

  case 35: /* CompilationUnit: PackageDeclarationopt ImportDeclarationsopt TypeDeclarationsopt  */
#line 252 "ast.ypp"
                                                                       {(yyval.node)=fnon_terminalchild("CompilationUnit",(yyvsp[-2].node));non_terminalchild((yyval.node),"CompilationUnit",(yyvsp[-1].node));non_terminalchild((yyval.node),"CompilationUnit",(yyvsp[0].node));root=(yyval.node);}
#line 2394 "ast.tab.cpp"
    break;

  case 36: /* PackageDeclarationopt: %empty  */
#line 254 "ast.ypp"
                       {(yyval.node)=fterminal_child("PackageDeclarationopt","");}
#line 2400 "ast.tab.cpp"
    break;

  case 37: /* PackageDeclarationopt: PackageDeclaration  */
#line 254 "ast.ypp"
                                                                                            {(yyval.node)=fnon_terminalchild("PackageDeclarationopt",(yyvsp[0].node));root=(yyval.node);}
#line 2406 "ast.tab.cpp"
    break;

  case 38: /* ImportDeclarationsopt: %empty  */
#line 255 "ast.ypp"
                       {(yyval.node)=fterminal_child("ImportDeclarationopt","");}
#line 2412 "ast.tab.cpp"
    break;

  case 39: /* ImportDeclarationsopt: ImportDeclarations  */
#line 255 "ast.ypp"
                                                                                           {(yyval.node)=fnon_terminalchild("ImportDeclarationopt",(yyvsp[0].node));}
#line 2418 "ast.tab.cpp"
    break;

  case 40: /* TypeDeclarationsopt: %empty  */
#line 256 "ast.ypp"
                     {(yyval.node)=fterminal_child("TypeDeclarationopt","");}
#line 2424 "ast.tab.cpp"
    break;

  case 41: /* TypeDeclarationsopt: TypeDeclarations  */
#line 256 "ast.ypp"
                                                                                     {(yyval.node)=fnon_terminalchild("TypeDeclarationopt",(yyvsp[0].node));}
#line 2430 "ast.tab.cpp"
    break;

  case 42: /* ImportDeclarations: ImportDeclaration  */
#line 260 "ast.ypp"
                         {(yyval.node)=fnon_terminalchild("ImportDeclarations",(yyvsp[0].node));}
#line 2436 "ast.tab.cpp"
    break;

  case 43: /* ImportDeclarations: ImportDeclarations ImportDeclaration  */
#line 262 "ast.ypp"
                                            {(yyval.node)=fnon_terminalchild("ImportDeclarations",(yyvsp[-1].node));non_terminalchild((yyval.node),"ImportDeclarations",(yyvsp[0].node));}
#line 2442 "ast.tab.cpp"
    break;

  case 44: /* TypeDeclarations: TypeDeclaration  */
#line 266 "ast.ypp"
                       {(yyval.node)=fnon_terminalchild("TypeDeclarations",(yyvsp[0].node));}
#line 2448 "ast.tab.cpp"
    break;

  case 45: /* TypeDeclarations: TypeDeclarations TypeDeclaration  */
#line 268 "ast.ypp"
                                        {(yyval.node)=fnon_terminalchild("TypeDeclarations",(yyvsp[-1].node));non_terminalchild((yyval.node),"TypeDeclarations",(yyvsp[0].node));}
#line 2454 "ast.tab.cpp"
    break;

  case 46: /* PackageDeclaration: package Name  */
#line 272 "ast.ypp"
                    {(yyval.node)=fterminal_child("PackageDeclaration",(yyvsp[-1].str));non_terminalchild((yyval.node),"PackageDeclaration",(yyvsp[0].node));}
#line 2460 "ast.tab.cpp"
    break;

  case 47: /* ImportDeclaration: SingleTypeImportDeclaration  */
#line 276 "ast.ypp"
                                   {(yyval.node)=fnon_terminalchild("ImportDeclaration",(yyvsp[0].node));}
#line 2466 "ast.tab.cpp"
    break;

  case 48: /* ImportDeclaration: TypeImportOnDemandDeclaration  */
#line 278 "ast.ypp"
                                     {(yyval.node)=fnon_terminalchild("ImportDeclaration",(yyvsp[0].node));}
#line 2472 "ast.tab.cpp"
    break;

  case 49: /* SingleTypeImportDeclaration: import Name semicolon  */
#line 282 "ast.ypp"
                             {(yyval.node)=fterminal_child("SingleTypeImportDeclaration",(yyvsp[-2].str));non_terminalchild((yyval.node),"SingleTypeImportDeclaration",(yyvsp[-1].node));terminal_child((yyval.node),"SingleTypeImportDeclaration",(yyvsp[0].str));}
#line 2478 "ast.tab.cpp"
    break;

  case 50: /* TypeImportOnDemandDeclaration: import Name period multiply semicolon  */
#line 286 "ast.ypp"
                                             {(yyval.node)=fterminal_child("TypeImportOnDemandDeclaration",(yyvsp[-4].str));non_terminalchild((yyval.node),"TypeImportOnDemandDeclaration",(yyvsp[-3].node));terminal_child((yyval.node),"TypeImportOnDemandDeclaration",(yyvsp[-2].str));terminal_child((yyval.node),"TypeImportOnDemandDeclaration",(yyvsp[-1].str));terminal_child((yyval.node),"TypeImportOnDemandDeclaration",(yyvsp[0].str));}
#line 2484 "ast.tab.cpp"
    break;

  case 51: /* TypeDeclaration: ClassDeclaration  */
#line 290 "ast.ypp"
                        {(yyval.node)=fnon_terminalchild("TypeDeclaration",(yyvsp[0].node));}
#line 2490 "ast.tab.cpp"
    break;

  case 52: /* TypeDeclaration: InterfaceDeclaration  */
#line 292 "ast.ypp"
                            {(yyval.node)=fnon_terminalchild("TypeDeclaration",(yyvsp[0].node));}
#line 2496 "ast.tab.cpp"
    break;

  case 53: /* TypeDeclaration: semicolon  */
#line 294 "ast.ypp"
                 {(yyval.node)=fterminal_child("TypeDeclaration",(yyvsp[0].str));}
#line 2502 "ast.tab.cpp"
    break;

  case 54: /* Modifiers: Modifier  */
#line 298 "ast.ypp"
                {(yyval.node)=fnon_terminalchild("Modifiers",(yyvsp[0].node));}
#line 2508 "ast.tab.cpp"
    break;

  case 55: /* Modifiers: Modifiers Modifier  */
#line 300 "ast.ypp"
                          {(yyval.node)=fnon_terminalchild("Modifiers",(yyvsp[-1].node));non_terminalchild((yyval.node),"Modifiers",(yyvsp[0].node));}
#line 2514 "ast.tab.cpp"
    break;

  case 56: /* Modifier: public1  */
#line 304 "ast.ypp"
               {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2520 "ast.tab.cpp"
    break;

  case 57: /* Modifier: protected1  */
#line 304 "ast.ypp"
                                                               {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2526 "ast.tab.cpp"
    break;

  case 58: /* Modifier: private1  */
#line 304 "ast.ypp"
                                                                                                             {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2532 "ast.tab.cpp"
    break;

  case 59: /* Modifier: static1  */
#line 306 "ast.ypp"
               {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2538 "ast.tab.cpp"
    break;

  case 60: /* Modifier: abstract  */
#line 308 "ast.ypp"
                {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2544 "ast.tab.cpp"
    break;

  case 61: /* Modifier: final  */
#line 308 "ast.ypp"
                                                           {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2550 "ast.tab.cpp"
    break;

  case 62: /* Modifier: native  */
#line 308 "ast.ypp"
                                                                                                       {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2556 "ast.tab.cpp"
    break;

  case 63: /* Modifier: synchronised  */
#line 308 "ast.ypp"
                                                                                                                                                          {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2562 "ast.tab.cpp"
    break;

  case 64: /* Modifier: transient  */
#line 308 "ast.ypp"
                                                                                                                                                                                                         {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2568 "ast.tab.cpp"
    break;

  case 65: /* Modifier: volatile1  */
#line 308 "ast.ypp"
                                                                                                                                                                                                                                                        {(yyval.node)=fterminal_child("Modifier",(yyvsp[0].str));}
#line 2574 "ast.tab.cpp"
    break;

  case 66: /* ClassDeclaration: Modifiersopt class1 Identifier Superopt Interfacesopt ClassBody  */
#line 312 "ast.ypp"
                                                                       {(yyval.node)=fnon_terminalchild("ClassDeclaration",(yyvsp[-5].node));terminal_child((yyval.node),"ClassDeclaration",(yyvsp[-4].str));non_terminalchild((yyval.node),"ClassDeclaration",(yyvsp[-3].node));non_terminalchild((yyval.node),"ClassDeclaration",(yyvsp[-2].node));non_terminalchild((yyval.node),"ClassDeclaration",(yyvsp[-1].node));non_terminalchild((yyval.node),"ClassDeclaration",(yyvsp[0].node));}
#line 2580 "ast.tab.cpp"
    break;

  case 67: /* Modifiersopt: %empty  */
#line 314 "ast.ypp"
              {(yyval.node)=fterminal_child("Modifiersopt","");}
#line 2586 "ast.tab.cpp"
    break;

  case 68: /* Modifiersopt: Modifiers  */
#line 314 "ast.ypp"
                                                                 {(yyval.node)=fnon_terminalchild("Modifiersopt",(yyvsp[0].node));}
#line 2592 "ast.tab.cpp"
    break;

  case 69: /* Superopt: %empty  */
#line 315 "ast.ypp"
          {(yyval.node)=fterminal_child("Superopt","");}
#line 2598 "ast.tab.cpp"
    break;

  case 70: /* Superopt: Super  */
#line 315 "ast.ypp"
                                                     {(yyval.node)=fnon_terminalchild("Superopt",(yyvsp[0].node));}
#line 2604 "ast.tab.cpp"
    break;

  case 71: /* Interfacesopt: %empty  */
#line 316 "ast.ypp"
               {(yyval.node)=fterminal_child("Interfacesopt","");}
#line 2610 "ast.tab.cpp"
    break;

  case 72: /* Interfacesopt: Interfaces  */
#line 316 "ast.ypp"
                                                                    {(yyval.node)=fnon_terminalchild("Interfaceopt",(yyvsp[0].node));}
#line 2616 "ast.tab.cpp"
    break;

  case 73: /* Super: extends Name  */
#line 320 "ast.ypp"
                    {(yyval.node)=fterminal_child("Super",(yyvsp[-1].str));non_terminalchild((yyval.node),"Super",(yyvsp[0].node));}
#line 2622 "ast.tab.cpp"
    break;

  case 74: /* Interfaces: implements InterfaceTypeList  */
#line 324 "ast.ypp"
                                    {(yyval.node)=fterminal_child("Interfaces",(yyvsp[-1].str));non_terminalchild((yyval.node),"Interfaces",(yyvsp[0].node));}
#line 2628 "ast.tab.cpp"
    break;

  case 75: /* InterfaceTypeList: Name  */
#line 328 "ast.ypp"
            {(yyval.node)=fnon_terminalchild("InterfaceTypeList",(yyvsp[0].node));}
#line 2634 "ast.tab.cpp"
    break;

  case 76: /* InterfaceTypeList: InterfaceTypeList comma Name  */
#line 330 "ast.ypp"
                                    {(yyval.node)=fnon_terminalchild("InterfaceTypeList",(yyvsp[-2].node));terminal_child((yyval.node),"InterfaceTypeList",(yyvsp[-1].str));non_terminalchild((yyval.node),"InterfaceTypeList",(yyvsp[0].node));}
#line 2640 "ast.tab.cpp"
    break;

  case 77: /* ClassBody: open_flower_bracket ClassBodyDeclarationsopt closed_flower_bracket  */
#line 334 "ast.ypp"
                                                                          {(yyval.node)=fterminal_child("ClassBody",(yyvsp[-2].str));non_terminalchild((yyval.node),"ClassBody",(yyvsp[-1].node));terminal_child((yyval.node),"ClassBody",(yyvsp[0].str));}
#line 2646 "ast.tab.cpp"
    break;

  case 78: /* ClassBodyDeclarationsopt: %empty  */
#line 336 "ast.ypp"
                          {(yyval.node)=fterminal_child("ClassBodyDeclarationsopt","");}
#line 2652 "ast.tab.cpp"
    break;

  case 79: /* ClassBodyDeclarationsopt: ClassBodyDeclarations  */
#line 336 "ast.ypp"
                                                                                                      {(yyval.node)=fnon_terminalchild("ClassBodydeclarationopt",(yyvsp[0].node));}
#line 2658 "ast.tab.cpp"
    break;

  case 80: /* ClassBodyDeclarations: ClassBodyDeclaration  */
#line 340 "ast.ypp"
                            {(yyval.node)=fnon_terminalchild("ClassBodyDeclarations",(yyvsp[0].node));}
#line 2664 "ast.tab.cpp"
    break;

  case 81: /* ClassBodyDeclarations: ClassBodyDeclarations ClassBodyDeclaration  */
#line 342 "ast.ypp"
                                                  {(yyval.node)=fnon_terminalchild("ClassBodyDeclarations",(yyvsp[-1].node));non_terminalchild((yyval.node),"ClassBodyDeclarations",(yyvsp[0].node));}
#line 2670 "ast.tab.cpp"
    break;

  case 82: /* ClassBodyDeclaration: ClassMemberDeclaration  */
#line 346 "ast.ypp"
                              {(yyval.node)=fnon_terminalchild("ClassBodyDeclaration",(yyvsp[0].node));}
#line 2676 "ast.tab.cpp"
    break;

  case 83: /* ClassBodyDeclaration: StaticInitializer  */
#line 348 "ast.ypp"
                         {(yyval.node)=fnon_terminalchild("ClassBodyDeclaration",(yyvsp[0].node));}
#line 2682 "ast.tab.cpp"
    break;

  case 84: /* ClassBodyDeclaration: ConstructorDeclaration  */
#line 350 "ast.ypp"
                              {(yyval.node)=fnon_terminalchild("ClassBodyDeclaration",(yyvsp[0].node));}
#line 2688 "ast.tab.cpp"
    break;

  case 85: /* ClassMemberDeclaration: FieldDeclaration  */
#line 354 "ast.ypp"
                        {(yyval.node)=fnon_terminalchild("ClassMemberDeclaration",(yyvsp[0].node));}
#line 2694 "ast.tab.cpp"
    break;

  case 86: /* ClassMemberDeclaration: MethodDeclaration  */
#line 356 "ast.ypp"
                         {(yyval.node)=fnon_terminalchild("ClassMemberDeclaration",(yyvsp[0].node));}
#line 2700 "ast.tab.cpp"
    break;

  case 87: /* FieldDeclaration: Modifiersopt Type VariableDeclarators semicolon  */
#line 360 "ast.ypp"
                                                       {(yyval.node)=fnon_terminalchild("FieldDeclaration",(yyvsp[-3].node));non_terminalchild((yyval.node),"FieldDeclaration",(yyvsp[-2].node));non_terminalchild((yyval.node),"FieldDeclaration",(yyvsp[-1].node));terminal_child((yyval.node),"FieldDeclaration",(yyvsp[0].str));}
#line 2706 "ast.tab.cpp"
    break;

  case 88: /* VariableDeclarators: VariableDeclarator  */
#line 364 "ast.ypp"
                          {(yyval.node)=fnon_terminalchild("VariableDeclarators",(yyvsp[0].node));}
#line 2712 "ast.tab.cpp"
    break;

  case 89: /* VariableDeclarators: VariableDeclarators comma VariableDeclarator  */
#line 366 "ast.ypp"
                                                    {(yyval.node)=fnon_terminalchild("VariableDeclarators",(yyvsp[-2].node));terminal_child((yyval.node),"VariableDeclarators",(yyvsp[-1].str));non_terminalchild((yyval.node),"VariableDeclarators",(yyvsp[0].node));}
#line 2718 "ast.tab.cpp"
    break;

  case 90: /* VariableDeclarator: VariableDeclaratorId  */
#line 370 "ast.ypp"
                            {(yyval.node)=fnon_terminalchild("VariableDeclarator",(yyvsp[0].node));}
#line 2724 "ast.tab.cpp"
    break;

  case 91: /* VariableDeclarator: VariableDeclaratorId equal1 VariableInitializer  */
#line 372 "ast.ypp"
                                                       {(yyval.node)=nonopnon( "VariableDeclarator",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2730 "ast.tab.cpp"
    break;

  case 92: /* VariableDeclaratorId: Identifier  */
#line 376 "ast.ypp"
                  {(yyval.node)=fnon_terminalchild("VariableDeclaratorId",(yyvsp[0].node));}
#line 2736 "ast.tab.cpp"
    break;

  case 93: /* VariableDeclaratorId: VariableDeclaratorId open_square_bracket closed_square_bracket  */
#line 378 "ast.ypp"
                                                                      {(yyval.node)=fnon_terminalchild("VariableDeclaratorId",(yyvsp[-2].node));terminal_child((yyval.node),"VariableDeclaratorId",(yyvsp[-1].str));terminal_child((yyval.node),"VariableDeclaratorId",(yyvsp[0].str));}
#line 2742 "ast.tab.cpp"
    break;

  case 94: /* VariableInitializer: AssignmentExpression  */
#line 382 "ast.ypp"
                            {(yyval.node)=fnon_terminalchild("VariableInitializer",(yyvsp[0].node));}
#line 2748 "ast.tab.cpp"
    break;

  case 95: /* VariableInitializer: ArrayInitializer  */
#line 384 "ast.ypp"
                        {(yyval.node)=fnon_terminalchild("VariableInitializer",(yyvsp[0].node));}
#line 2754 "ast.tab.cpp"
    break;

  case 96: /* MethodDeclaration: MethodHeader MethodBody  */
#line 388 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("MethodDeclaration",(yyvsp[-1].node));non_terminalchild((yyval.node),"MethodDeclaration",(yyvsp[0].node));}
#line 2760 "ast.tab.cpp"
    break;

  case 97: /* MethodHeader: Modifiersopt Type MethodDeclarator Throwsopt  */
#line 392 "ast.ypp"
                                                    {(yyval.node)=fnon_terminalchild("MethodHeader",(yyvsp[-3].node)); non_terminalchild((yyval.node),"MethodHeader",(yyvsp[-2].node));non_terminalchild((yyval.node),"MethodHeader",(yyvsp[-1].node));non_terminalchild((yyval.node),"MethodHeader",(yyvsp[0].node));}
#line 2766 "ast.tab.cpp"
    break;

  case 98: /* MethodHeader: Modifiersopt void1 MethodDeclarator Throwsopt  */
#line 394 "ast.ypp"
                                                     {(yyval.node)=fnon_terminalchild("MethodHeader",(yyvsp[-3].node)); terminal_child((yyval.node),"MethodHeader",(yyvsp[-2].str));non_terminalchild((yyval.node),"MethodHeader",(yyvsp[-1].node));non_terminalchild((yyval.node),"MethodHeader",(yyvsp[0].node));}
#line 2772 "ast.tab.cpp"
    break;

  case 99: /* Throwsopt: %empty  */
#line 396 "ast.ypp"
           {(yyval.node)=fterminal_child("Throwsopt","");}
#line 2778 "ast.tab.cpp"
    break;

  case 100: /* Throwsopt: Throws  */
#line 396 "ast.ypp"
                                                        {(yyval.node)=fnon_terminalchild("Throwsopt",(yyvsp[0].node));}
#line 2784 "ast.tab.cpp"
    break;

  case 101: /* MethodDeclarator: Identifier open_bracket FormalParameterListopt closed_bracket  */
#line 400 "ast.ypp"
                                                                     {(yyval.node)=fnon_terminalchild("Methoddeclarator",(yyvsp[-3].node));terminal_child((yyval.node),"MethodDeclarator",(yyvsp[-2].str));non_terminalchild((yyval.node),"MethodDeclarator",(yyvsp[-1].node));terminal_child((yyval.node),"MethodDeclarator",(yyvsp[0].str));}
#line 2790 "ast.tab.cpp"
    break;

  case 102: /* MethodDeclarator: MethodDeclarator open_square_bracket closed_square_bracket  */
#line 402 "ast.ypp"
                                                                  {(yyval.node)=fnon_terminalchild("MethodDeclarator",(yyvsp[-2].node));terminal_child((yyval.node),"Methoddeclarator",(yyvsp[-1].str));terminal_child((yyval.node),"MethodDeclarator",(yyvsp[0].str));}
#line 2796 "ast.tab.cpp"
    break;

  case 103: /* FormalParameterListopt: %empty  */
#line 404 "ast.ypp"
                        {(yyval.node)=fterminal_child("FormalParameterListopt","");}
#line 2802 "ast.tab.cpp"
    break;

  case 104: /* FormalParameterListopt: FormalParameterList  */
#line 404 "ast.ypp"
                                                                                               {(yyval.node)=fnon_terminalchild("FormalParameterListopt",(yyvsp[0].node));}
#line 2808 "ast.tab.cpp"
    break;

  case 105: /* FormalParameterList: FormalParameter  */
#line 408 "ast.ypp"
                       {(yyval.node)=fnon_terminalchild("FormalParameterList",(yyvsp[0].node));}
#line 2814 "ast.tab.cpp"
    break;

  case 106: /* FormalParameterList: FormalParameterList comma FormalParameter  */
#line 410 "ast.ypp"
                                                 {(yyval.node)=fnon_terminalchild("FormalParameterList",(yyvsp[-2].node));terminal_child((yyval.node),"FormalParameterList",(yyvsp[-1].str));non_terminalchild((yyval.node),"FormalParameterList",(yyvsp[0].node));}
#line 2820 "ast.tab.cpp"
    break;

  case 107: /* FormalParameter: Type VariableDeclaratorId  */
#line 414 "ast.ypp"
                                 {(yyval.node)=fnon_terminalchild("FormalParameter",(yyvsp[-1].node));non_terminalchild((yyval.node),"FormalParameter",(yyvsp[0].node));}
#line 2826 "ast.tab.cpp"
    break;

  case 108: /* Throws: throws ClassTypeList  */
#line 418 "ast.ypp"
                            {(yyval.node)=fterminal_child("Throws",(yyvsp[-1].str));non_terminalchild((yyval.node),"Throws",(yyvsp[0].node));}
#line 2832 "ast.tab.cpp"
    break;

  case 109: /* ClassTypeList: Name  */
#line 422 "ast.ypp"
            {(yyval.node)=fnon_terminalchild("ClassTypeList",(yyvsp[0].node));}
#line 2838 "ast.tab.cpp"
    break;

  case 110: /* ClassTypeList: ClassTypeList comma Name  */
#line 424 "ast.ypp"
                                {(yyval.node)=fnon_terminalchild("ClassTypeList",(yyvsp[-2].node));terminal_child((yyval.node),"ClassTypeList",(yyvsp[-1].str));non_terminalchild((yyval.node),"ClassTypeList",(yyvsp[0].node));}
#line 2844 "ast.tab.cpp"
    break;

  case 111: /* MethodBody: Block  */
#line 428 "ast.ypp"
             {(yyval.node)=fnon_terminalchild("MethodBody",(yyvsp[0].node));}
#line 2850 "ast.tab.cpp"
    break;

  case 112: /* MethodBody: semicolon  */
#line 430 "ast.ypp"
                 {(yyval.node)=fterminal_child("MethodBody",(yyvsp[0].str));}
#line 2856 "ast.tab.cpp"
    break;

  case 113: /* StaticInitializer: static1 Block  */
#line 434 "ast.ypp"
                     {(yyval.node)=fterminal_child("StaticInitializer",(yyvsp[-1].str));non_terminalchild((yyval.node),"StaticInitializer",(yyvsp[0].node));}
#line 2862 "ast.tab.cpp"
    break;

  case 114: /* ConstructorDeclaration: Modifiersopt ConstructorDeclarator Throwsopt ConstructorBody  */
#line 438 "ast.ypp"
                                                                    {(yyval.node)=fnon_terminalchild("ConstructorDeclaration",(yyvsp[-3].node));non_terminalchild((yyval.node),"ConstructorDeclaration",(yyvsp[-2].node));non_terminalchild((yyval.node),"ConstructorDeclaration",(yyvsp[-1].node));non_terminalchild((yyval.node),"ConstructorDeclaration",(yyvsp[0].node));}
#line 2868 "ast.tab.cpp"
    break;

  case 115: /* ConstructorDeclarator: Identifier open_bracket FormalParameterListopt closed_bracket  */
#line 442 "ast.ypp"
                                                                     {(yyval.node)=fnon_terminalchild("ConstructorDeclarator",(yyvsp[-3].node));terminal_child((yyval.node),"ConstructorDeclarator",(yyvsp[-2].str));non_terminalchild((yyval.node),"ConstructorDeclarator",(yyvsp[-1].node));terminal_child((yyval.node),"ConstructorDeclarator",(yyvsp[0].str));}
#line 2874 "ast.tab.cpp"
    break;

  case 116: /* ConstructorBody: open_flower_bracket ExplicitConstructorInvocationopt BlockStatementsopt closed_flower_bracket  */
#line 446 "ast.ypp"
                                                                                                     {(yyval.node)=fterminal_child("ConstructorBody",(yyvsp[-3].str));non_terminalchild((yyval.node),"ConstructorBody",(yyvsp[-2].node));non_terminalchild((yyval.node),"ConstructorBody",(yyvsp[-1].node));terminal_child((yyval.node),"ConstructorBody",(yyvsp[0].str));}
#line 2880 "ast.tab.cpp"
    break;

  case 117: /* BlockStatementsopt: %empty  */
#line 448 "ast.ypp"
                    {(yyval.node)=fterminal_child("BlockStatementsopt","");}
#line 2886 "ast.tab.cpp"
    break;

  case 118: /* BlockStatementsopt: BlockStatements  */
#line 448 "ast.ypp"
                                                                                   {(yyval.node)=fnon_terminalchild("BlockStatementsopt",(yyvsp[0].node));}
#line 2892 "ast.tab.cpp"
    break;

  case 119: /* ExplicitConstructorInvocationopt: %empty  */
#line 449 "ast.ypp"
                                  {(yyval.node)=fterminal_child("ExplicitConstructorInvocationopt","");}
#line 2898 "ast.tab.cpp"
    break;

  case 120: /* ExplicitConstructorInvocationopt: ExplicitConstructorInvocation  */
#line 449 "ast.ypp"
                                                                                                                             {(yyval.node)=fnon_terminalchild("ExplicitConstructorInvocationopt",(yyvsp[0].node));}
#line 2904 "ast.tab.cpp"
    break;

  case 121: /* ExplicitConstructorInvocation: this1 open_bracket ArgumentListopt closed_bracket semicolon  */
#line 453 "ast.ypp"
                                                                   {(yyval.node)=fterminal_child("ExplicitConstructorInvocation",(yyvsp[-4].str));terminal_child((yyval.node),"ExplicitConstructorInvocation",(yyvsp[-3].str));non_terminalchild((yyval.node),"ExplicitConstructorInvocation",(yyvsp[-2].node));terminal_child((yyval.node),"ExplicitConstructorInvocation",(yyvsp[-1].str));terminal_child((yyval.node),"ExplicitConstructorInvocation",(yyvsp[0].str));}
#line 2910 "ast.tab.cpp"
    break;

  case 122: /* ExplicitConstructorInvocation: super open_bracket ArgumentListopt closed_bracket semicolon  */
#line 455 "ast.ypp"
                                                                   {(yyval.node)=fterminal_child("ExplicitConstructorInvocation",(yyvsp[-4].str));terminal_child((yyval.node),"ExplicitConstructorInvocation",(yyvsp[-3].str));non_terminalchild((yyval.node),"ExplicitConstructorInvocation",(yyvsp[-2].node));terminal_child((yyval.node),"ExplicitConstructorInvocation",(yyvsp[-1].str));terminal_child((yyval.node),"ExplicitConstructorInvocation",(yyvsp[0].str));}
#line 2916 "ast.tab.cpp"
    break;

  case 123: /* ArgumentListopt: %empty  */
#line 457 "ast.ypp"
                 {(yyval.node)=fterminal_child("ArgumentListopt","");}
#line 2922 "ast.tab.cpp"
    break;

  case 124: /* ArgumentListopt: ArgumentList  */
#line 457 "ast.ypp"
                                                                          {(yyval.node)=fnon_terminalchild("ArgumentListopt",(yyvsp[0].node));}
#line 2928 "ast.tab.cpp"
    break;

  case 125: /* InterfaceDeclaration: Modifiersopt interface Identifier ExtendsInterfacesopt InterfaceBody  */
#line 461 "ast.ypp"
                                                                            {(yyval.node)=fnon_terminalchild("InterfaceDeclaration",(yyvsp[-4].node));terminal_child((yyval.node),"InterfaceDeclaration",(yyvsp[-3].str));non_terminalchild((yyval.node),"InterfaceDeclaration",(yyvsp[-2].node));non_terminalchild((yyval.node),"InterfaceDeclaration",(yyvsp[-1].node));non_terminalchild((yyval.node),"InterfaceDeclaration",(yyvsp[0].node));}
#line 2934 "ast.tab.cpp"
    break;

  case 126: /* ExtendsInterfacesopt: %empty  */
#line 463 "ast.ypp"
                      {(yyval.node)=fterminal_child("ExtendsInterfacesopt","");}
#line 2940 "ast.tab.cpp"
    break;

  case 127: /* ExtendsInterfacesopt: ExtendsInterfaces  */
#line 463 "ast.ypp"
                                                                                        {(yyval.node)=fnon_terminalchild("ExtendsInterfacesopt",(yyvsp[0].node));}
#line 2946 "ast.tab.cpp"
    break;

  case 128: /* ExtendsInterfaces: extends Name  */
#line 467 "ast.ypp"
                    {(yyval.node)=fterminal_child("ExtendsInterfaces",(yyvsp[-1].str));non_terminalchild((yyval.node),"ExtendsInterfaces",(yyvsp[0].node));}
#line 2952 "ast.tab.cpp"
    break;

  case 129: /* ExtendsInterfaces: ExtendsInterfaces comma Name  */
#line 469 "ast.ypp"
                                    {(yyval.node)=fnon_terminalchild("ExtendsInterfaces",(yyvsp[-2].node));terminal_child((yyval.node),"ExtendsInterfaces",(yyvsp[-1].str));non_terminalchild((yyval.node),"ExtendsInterfaces",(yyvsp[0].node));}
#line 2958 "ast.tab.cpp"
    break;

  case 130: /* InterfaceBody: open_flower_bracket InterfaceMemberDeclarationsopt closed_flower_bracket  */
#line 473 "ast.ypp"
                                                                                {(yyval.node)=fterminal_child("InterfaceBody",(yyvsp[-2].str));non_terminalchild((yyval.node),"InterfaceBody",(yyvsp[-1].node));terminal_child((yyval.node),"InterfaceBody",(yyvsp[0].str));}
#line 2964 "ast.tab.cpp"
    break;

  case 131: /* InterfaceMemberDeclarationsopt: %empty  */
#line 475 "ast.ypp"
                                {(yyval.node)=fterminal_child("InterfaceMenberDeclarationsopt","");}
#line 2970 "ast.tab.cpp"
    break;

  case 132: /* InterfaceMemberDeclarationsopt: InterfaceMemberDeclarations  */
#line 475 "ast.ypp"
                                                                                                                       {(yyval.node)=fnon_terminalchild("InterfaceMemberDeclarationsopt",(yyvsp[0].node));}
#line 2976 "ast.tab.cpp"
    break;

  case 133: /* InterfaceMemberDeclarations: InterfaceMemberDeclaration  */
#line 479 "ast.ypp"
                                  {(yyval.node)=fnon_terminalchild("InterfaceMemberDeclarations",(yyvsp[0].node));}
#line 2982 "ast.tab.cpp"
    break;

  case 134: /* InterfaceMemberDeclarations: InterfaceMemberDeclarations InterfaceMemberDeclaration  */
#line 481 "ast.ypp"
                                                              {(yyval.node)=fnon_terminalchild("InterfaceMemberDeclarations",(yyvsp[-1].node));non_terminalchild((yyval.node),"InterfaceMemberDeclarations",(yyvsp[0].node));}
#line 2988 "ast.tab.cpp"
    break;

  case 135: /* InterfaceMemberDeclaration: FieldDeclaration  */
#line 485 "ast.ypp"
                        {(yyval.node)=fnon_terminalchild("InterfaceMemberDeclaration",(yyvsp[0].node));}
#line 2994 "ast.tab.cpp"
    break;

  case 136: /* InterfaceMemberDeclaration: AbstractMethodDeclaration  */
#line 487 "ast.ypp"
                                 {(yyval.node)=fnon_terminalchild("InterfaceMemberDeclaration",(yyvsp[0].node));}
#line 3000 "ast.tab.cpp"
    break;

  case 137: /* AbstractMethodDeclaration: MethodHeader semicolon  */
#line 491 "ast.ypp"
                              {(yyval.node)=fnon_terminalchild("AbstractMethodDeclaration",(yyvsp[-1].node));terminal_child((yyval.node),"AbstractMethodDeclaration",(yyvsp[0].str));}
#line 3006 "ast.tab.cpp"
    break;

  case 138: /* ArrayInitializer: open_flower_bracket VariableInitializersopt commaopt closed_flower_bracket  */
#line 495 "ast.ypp"
                                                                                  {(yyval.node)=fterminal_child("ArrayInitializer",(yyvsp[-3].str));non_terminalchild((yyval.node),"ArrayInitializer",(yyvsp[-2].node));non_terminalchild((yyval.node),"ArrayInitializer",(yyvsp[-1].node));terminal_child((yyval.node),"ArrayInitializer",(yyvsp[0].str));}
#line 3012 "ast.tab.cpp"
    break;

  case 139: /* commaopt: %empty  */
#line 497 "ast.ypp"
          {(yyval.node)=fterminal_child("commaopt","");}
#line 3018 "ast.tab.cpp"
    break;

  case 140: /* commaopt: comma  */
#line 497 "ast.ypp"
                                                     {(yyval.node)=fterminal_child("commaopt",(yyvsp[0].str));}
#line 3024 "ast.tab.cpp"
    break;

  case 141: /* VariableInitializersopt: %empty  */
#line 498 "ast.ypp"
                         {(yyval.node)=fterminal_child("VariableInitializersopt","");}
#line 3030 "ast.tab.cpp"
    break;

  case 142: /* VariableInitializersopt: VariableInitializers  */
#line 498 "ast.ypp"
                                                                                                  {(yyval.node)=fnon_terminalchild("VariableInitializersopt",(yyvsp[0].node));}
#line 3036 "ast.tab.cpp"
    break;

  case 143: /* VariableInitializers: VariableInitializer  */
#line 502 "ast.ypp"
                           {(yyval.node)=fnon_terminalchild("VariableInitializers",(yyvsp[0].node));}
#line 3042 "ast.tab.cpp"
    break;

  case 144: /* VariableInitializers: VariableInitializers comma VariableInitializer  */
#line 504 "ast.ypp"
                                                      {(yyval.node)=fnon_terminalchild("VariableInitializers",(yyvsp[-2].node));terminal_child((yyval.node),"VariableInitializers",(yyvsp[-1].str));non_terminalchild((yyval.node),"VariableInitializers",(yyvsp[0].node));}
#line 3048 "ast.tab.cpp"
    break;

  case 145: /* Block: open_flower_bracket BlockStatementsopt closed_flower_bracket  */
#line 508 "ast.ypp"
                                                                    {(yyval.node)=fterminal_child("Block",(yyvsp[-2].str));non_terminalchild((yyval.node),"Block",(yyvsp[-1].node));terminal_child((yyval.node),"Block",(yyvsp[0].str));}
#line 3054 "ast.tab.cpp"
    break;

  case 146: /* BlockStatements: BlockStatement  */
#line 512 "ast.ypp"
                      {(yyval.node)=fnon_terminalchild("BlockStatements",(yyvsp[0].node));}
#line 3060 "ast.tab.cpp"
    break;

  case 147: /* BlockStatements: BlockStatements BlockStatement  */
#line 514 "ast.ypp"
                                      {(yyval.node)=fnon_terminalchild("BlockStatements",(yyvsp[-1].node));non_terminalchild((yyval.node),"BlockStatements",(yyvsp[0].node));}
#line 3066 "ast.tab.cpp"
    break;

  case 148: /* BlockStatement: LocalVariableDeclarationStatement  */
#line 518 "ast.ypp"
                                         {(yyval.node)=fnon_terminalchild("BlockStatement",(yyvsp[0].node));}
#line 3072 "ast.tab.cpp"
    break;

  case 149: /* BlockStatement: Statement  */
#line 520 "ast.ypp"
                 {(yyval.node)=fnon_terminalchild("BlockStatement",(yyvsp[0].node));}
#line 3078 "ast.tab.cpp"
    break;

  case 150: /* LocalVariableDeclarationStatement: LocalVariableDeclaration  */
#line 524 "ast.ypp"
                                {(yyval.node)=fnon_terminalchild("LocalVariableDeclarationStatement",(yyvsp[0].node));}
#line 3084 "ast.tab.cpp"
    break;

  case 151: /* LocalVariableDeclaration: Type VariableDeclarators  */
#line 528 "ast.ypp"
                                {(yyval.node)=fnon_terminalchild("LocalVariableDeclaration",(yyvsp[-1].node));non_terminalchild((yyval.node),"LocalVariableDeclaration",(yyvsp[0].node));}
#line 3090 "ast.tab.cpp"
    break;

  case 152: /* LocalVariableDeclaration: VariableDeclarators  */
#line 529 "ast.ypp"
                           {(yyval.node)=fnon_terminalchild("LocalVariableDeclaration",(yyvsp[0].node));}
#line 3096 "ast.tab.cpp"
    break;

  case 153: /* Statement: StatementWithoutTrailingSubstatement  */
#line 533 "ast.ypp"
                                            {(yyval.node)=fnon_terminalchild("Statement",(yyvsp[0].node));}
#line 3102 "ast.tab.cpp"
    break;

  case 154: /* Statement: LabeledStatement  */
#line 535 "ast.ypp"
                        {(yyval.node)=fnon_terminalchild("Statement",(yyvsp[0].node));}
#line 3108 "ast.tab.cpp"
    break;

  case 155: /* Statement: IfThenStatement  */
#line 537 "ast.ypp"
                       {(yyval.node)=fnon_terminalchild("Statement",(yyvsp[0].node));}
#line 3114 "ast.tab.cpp"
    break;

  case 156: /* Statement: IfThenElseStatement  */
#line 539 "ast.ypp"
                           {(yyval.node)=fnon_terminalchild("Statement",(yyvsp[0].node));}
#line 3120 "ast.tab.cpp"
    break;

  case 157: /* Statement: WhileStatement  */
#line 541 "ast.ypp"
                      {(yyval.node)=fnon_terminalchild("Statement",(yyvsp[0].node));}
#line 3126 "ast.tab.cpp"
    break;

  case 158: /* Statement: ForStatement  */
#line 543 "ast.ypp"
                    {(yyval.node)=fnon_terminalchild("Statement",(yyvsp[0].node));}
#line 3132 "ast.tab.cpp"
    break;

  case 159: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 547 "ast.ypp"
                                            {(yyval.node)=fnon_terminalchild("StatementNoShortIf",(yyvsp[0].node));}
#line 3138 "ast.tab.cpp"
    break;

  case 160: /* StatementNoShortIf: LabeledStatementNoShortIf  */
#line 549 "ast.ypp"
                                 {(yyval.node)=fnon_terminalchild("StatementNoShortIf",(yyvsp[0].node));}
#line 3144 "ast.tab.cpp"
    break;

  case 161: /* StatementNoShortIf: IfThenElseStatementNoShortIf  */
#line 551 "ast.ypp"
                                    {(yyval.node)=fnon_terminalchild("StatementNoShortIf",(yyvsp[0].node));}
#line 3150 "ast.tab.cpp"
    break;

  case 162: /* StatementNoShortIf: WhileStatementNoShortIf  */
#line 553 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("StatementNoShortIf",(yyvsp[0].node));}
#line 3156 "ast.tab.cpp"
    break;

  case 163: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 555 "ast.ypp"
                             {(yyval.node)=fnon_terminalchild("StatementNoShortIf",(yyvsp[0].node));}
#line 3162 "ast.tab.cpp"
    break;

  case 164: /* StatementWithoutTrailingSubstatement: Block  */
#line 559 "ast.ypp"
             {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3168 "ast.tab.cpp"
    break;

  case 165: /* StatementWithoutTrailingSubstatement: EmptyStatement  */
#line 561 "ast.ypp"
                      {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3174 "ast.tab.cpp"
    break;

  case 166: /* StatementWithoutTrailingSubstatement: ExpressionStatement  */
#line 563 "ast.ypp"
                           {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3180 "ast.tab.cpp"
    break;

  case 167: /* StatementWithoutTrailingSubstatement: SwitchStatement  */
#line 565 "ast.ypp"
                       {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3186 "ast.tab.cpp"
    break;

  case 168: /* StatementWithoutTrailingSubstatement: DoStatement  */
#line 567 "ast.ypp"
                   {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3192 "ast.tab.cpp"
    break;

  case 169: /* StatementWithoutTrailingSubstatement: BreakStatement  */
#line 569 "ast.ypp"
                      {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3198 "ast.tab.cpp"
    break;

  case 170: /* StatementWithoutTrailingSubstatement: ContinueStatement  */
#line 571 "ast.ypp"
                         {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3204 "ast.tab.cpp"
    break;

  case 171: /* StatementWithoutTrailingSubstatement: ReturnStatement  */
#line 573 "ast.ypp"
                       {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3210 "ast.tab.cpp"
    break;

  case 172: /* StatementWithoutTrailingSubstatement: SynchronizedStatement  */
#line 575 "ast.ypp"
                             {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3216 "ast.tab.cpp"
    break;

  case 173: /* StatementWithoutTrailingSubstatement: ThrowStatement  */
#line 577 "ast.ypp"
                      {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3222 "ast.tab.cpp"
    break;

  case 174: /* StatementWithoutTrailingSubstatement: TryStatement  */
#line 579 "ast.ypp"
                    {(yyval.node)=fnon_terminalchild("StatementWithoutTrailingSubstatement",(yyvsp[0].node));}
#line 3228 "ast.tab.cpp"
    break;

  case 175: /* EmptyStatement: semicolon  */
#line 583 "ast.ypp"
                 {(yyval.node)=fterminal_child("EmptyStatement",(yyvsp[0].str));}
#line 3234 "ast.tab.cpp"
    break;

  case 176: /* LabeledStatement: Identifier colon Statement  */
#line 587 "ast.ypp"
                                  {(yyval.node)=fnon_terminalchild("LabeledStatement",(yyvsp[-2].node));terminal_child((yyval.node),"LabeledStatement",(yyvsp[-1].str));non_terminalchild((yyval.node),"LabeledStatement",(yyvsp[0].node));}
#line 3240 "ast.tab.cpp"
    break;

  case 177: /* LabeledStatementNoShortIf: Identifier colon StatementNoShortIf  */
#line 591 "ast.ypp"
                                           {(yyval.node)=fnon_terminalchild("LabeledStatementNoShortIf",(yyvsp[-2].node));terminal_child((yyval.node),"LabeledStatementNoShortIf",(yyvsp[-1].str));non_terminalchild((yyval.node),"LabeledStatementNoShortIf",(yyvsp[0].node));}
#line 3246 "ast.tab.cpp"
    break;

  case 178: /* ExpressionStatement: StatementExpression semicolon  */
#line 595 "ast.ypp"
                                     {(yyval.node)=fnon_terminalchild("ExpressionStatement",(yyvsp[-1].node));terminal_child((yyval.node),"ExpressionStatement",(yyvsp[0].str));}
#line 3252 "ast.tab.cpp"
    break;

  case 179: /* StatementExpression: Assignment  */
#line 599 "ast.ypp"
                  {(yyval.node)=fnon_terminalchild("StatementExpression",(yyvsp[0].node));}
#line 3258 "ast.tab.cpp"
    break;

  case 180: /* StatementExpression: PreIncrementExpression  */
#line 601 "ast.ypp"
                              {(yyval.node)=fnon_terminalchild("StatementExpression",(yyvsp[0].node));}
#line 3264 "ast.tab.cpp"
    break;

  case 181: /* StatementExpression: PreDecrementExpression  */
#line 603 "ast.ypp"
                              {(yyval.node)=fnon_terminalchild("StatementExpression",(yyvsp[0].node));}
#line 3270 "ast.tab.cpp"
    break;

  case 182: /* StatementExpression: PostIncrementExpression  */
#line 605 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("StatementExpression",(yyvsp[0].node));}
#line 3276 "ast.tab.cpp"
    break;

  case 183: /* StatementExpression: PostDecrementExpression  */
#line 607 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("StatementExpression",(yyvsp[0].node));}
#line 3282 "ast.tab.cpp"
    break;

  case 184: /* StatementExpression: MethodInvocation  */
#line 609 "ast.ypp"
                        {(yyval.node)=fnon_terminalchild("StatementExpression",(yyvsp[0].node));}
#line 3288 "ast.tab.cpp"
    break;

  case 185: /* StatementExpression: ClassInstanceCreationExpression  */
#line 611 "ast.ypp"
                                       {(yyval.node)=fnon_terminalchild("StatementExpression",(yyvsp[0].node));}
#line 3294 "ast.tab.cpp"
    break;

  case 186: /* IfThenStatement: if1 open_bracket AssignmentExpression closed_bracket Statement  */
#line 615 "ast.ypp"
                                                                      {(yyval.node)=fterminal_child("IfThenStatement",(yyvsp[-4].str));terminal_child((yyval.node),"IfThenStatement",(yyvsp[-3].str));non_terminalchild((yyval.node),"IfThenStatement",(yyvsp[-2].node));terminal_child((yyval.node),"IfThenStatement",(yyvsp[-1].str));non_terminalchild((yyval.node),"IfThenStatement",(yyvsp[0].node));}
#line 3300 "ast.tab.cpp"
    break;

  case 187: /* IfThenElseStatement: if1 open_bracket AssignmentExpression closed_bracket StatementNoShortIf else1 Statement  */
#line 619 "ast.ypp"
                                                                                               {(yyval.node)=fterminal_child("IfThenElseStatement",(yyvsp[-6].str));terminal_child((yyval.node),"IfThenElseStatement",(yyvsp[-5].str));non_terminalchild((yyval.node),"IfThenElseStatement",(yyvsp[-4].node));terminal_child((yyval.node),"IfThenElseStatement",(yyvsp[-3].str));non_terminalchild((yyval.node),"IfThenElseStatement",(yyvsp[-2].node));terminal_child((yyval.node),"IfThenElseStatement",(yyvsp[-1].str));non_terminalchild((yyval.node),"IfThenElseStatement",(yyvsp[0].node));}
#line 3306 "ast.tab.cpp"
    break;

  case 188: /* IfThenElseStatementNoShortIf: if1 open_bracket AssignmentExpression closed_bracket StatementNoShortIf else1 StatementNoShortIf  */
#line 623 "ast.ypp"
                                                                                                        {(yyval.node)=fterminal_child("IfThenElseStatementNoShortIf",(yyvsp[-6].str));terminal_child((yyval.node),"IfThenElseStatementNoShortIf",(yyvsp[-5].str));non_terminalchild((yyval.node),"IfThenElseStatementNoShortIf",(yyvsp[-4].node));terminal_child((yyval.node),"IfThenElseStatementNoShortIf",(yyvsp[-3].str));non_terminalchild((yyval.node),"IfThenElseStatementNoShortIf",(yyvsp[-2].node));terminal_child((yyval.node),"IfThenElseStatementNoShortIf",(yyvsp[-1].str));non_terminalchild((yyval.node),"IfThenElseStatementNoShortIf",(yyvsp[0].node));}
#line 3312 "ast.tab.cpp"
    break;

  case 189: /* SwitchStatement: switch1 open_bracket AssignmentExpression closed_bracket SwitchBlock  */
#line 627 "ast.ypp"
                                                                            {(yyval.node)=fterminal_child("IfThenStatement",(yyvsp[-4].str));terminal_child((yyval.node),"IfThenStatement",(yyvsp[-3].str));non_terminalchild((yyval.node),"IfThenStatement",(yyvsp[-2].node));terminal_child((yyval.node),"IfThenStatement",(yyvsp[-1].str));non_terminalchild((yyval.node),"IfThenStatement",(yyvsp[0].node));}
#line 3318 "ast.tab.cpp"
    break;

  case 190: /* SwitchBlock: open_flower_bracket SwitchBlockStatementGroupsopt SwitchLabelsopt closed_flower_bracket  */
#line 631 "ast.ypp"
                                                                                               {(yyval.node)=fterminal_child("SwitchBlock",(yyvsp[-3].str));non_terminalchild((yyval.node),"SwitchBlock",(yyvsp[-2].node));non_terminalchild((yyval.node),"SwitchBlock",(yyvsp[-1].node));terminal_child((yyval.node),"SwitchBlock",(yyvsp[0].str));}
#line 3324 "ast.tab.cpp"
    break;

  case 191: /* SwitchBlockStatementGroupsopt: %empty  */
#line 633 "ast.ypp"
                               {(yyval.node)=fterminal_child("SwitchBlockStatementGroupsopt","");}
#line 3330 "ast.tab.cpp"
    break;

  case 192: /* SwitchBlockStatementGroupsopt: SwitchBlockStatementGroups  */
#line 633 "ast.ypp"
                                                                                                                    {(yyval.node)=fnon_terminalchild("SwitchBlockStatementGroupsopt",(yyvsp[0].node));}
#line 3336 "ast.tab.cpp"
    break;

  case 193: /* SwitchLabelsopt: %empty  */
#line 634 "ast.ypp"
                 {(yyval.node)=fterminal_child("SwitchLabelsopt","");}
#line 3342 "ast.tab.cpp"
    break;

  case 194: /* SwitchLabelsopt: SwitchLabels  */
#line 634 "ast.ypp"
                                                                          {(yyval.node)=fnon_terminalchild("SwitchLabelsopt",(yyvsp[0].node));}
#line 3348 "ast.tab.cpp"
    break;

  case 195: /* SwitchBlockStatementGroups: SwitchBlockStatementGroup  */
#line 638 "ast.ypp"
                                 {(yyval.node)=fnon_terminalchild("SwitchBlockStatementGroups",(yyvsp[0].node));}
#line 3354 "ast.tab.cpp"
    break;

  case 196: /* SwitchBlockStatementGroups: SwitchBlockStatementGroups SwitchBlockStatementGroup  */
#line 640 "ast.ypp"
                                                            {(yyval.node)=fnon_terminalchild("SwitchBlockStatementGroups",(yyvsp[-1].node));non_terminalchild((yyval.node),"SwitchBlockStatementGroups",(yyvsp[0].node));}
#line 3360 "ast.tab.cpp"
    break;

  case 197: /* SwitchBlockStatementGroup: SwitchLabels BlockStatements  */
#line 644 "ast.ypp"
                                    {(yyval.node)=fnon_terminalchild("SwitchBlockStatementGroup",(yyvsp[-1].node));non_terminalchild((yyval.node),"SwitchBlockStatementGroup",(yyvsp[0].node));}
#line 3366 "ast.tab.cpp"
    break;

  case 198: /* SwitchLabels: SwitchLabel  */
#line 648 "ast.ypp"
                   {(yyval.node)=fnon_terminalchild("SwitchLabels",(yyvsp[0].node));}
#line 3372 "ast.tab.cpp"
    break;

  case 199: /* SwitchLabels: SwitchLabels SwitchLabel  */
#line 650 "ast.ypp"
                                {(yyval.node)=fnon_terminalchild("SwitchLabels",(yyvsp[-1].node));non_terminalchild((yyval.node),"SwitchLabels",(yyvsp[0].node));}
#line 3378 "ast.tab.cpp"
    break;

  case 200: /* SwitchLabel: case1 AssignmentExpression colon  */
#line 654 "ast.ypp"
                                        {(yyval.node)=fterminal_child("SwitchLabel",(yyvsp[-2].str));non_terminalchild((yyval.node),"SwitchLabel",(yyvsp[-1].node));terminal_child((yyval.node),"SwitchLabel",(yyvsp[0].str));}
#line 3384 "ast.tab.cpp"
    break;

  case 201: /* SwitchLabel: default1 colon  */
#line 656 "ast.ypp"
                      {(yyval.node)=fterminal_child("SwitchLabel",(yyvsp[-1].str));terminal_child((yyval.node),"SwitchLabel",(yyvsp[0].str));}
#line 3390 "ast.tab.cpp"
    break;

  case 202: /* WhileStatement: while1 open_bracket AssignmentExpression closed_bracket Statement  */
#line 660 "ast.ypp"
                                                                         {(yyval.node)=fterminal_child("WhileStatement",(yyvsp[-4].str));terminal_child((yyval.node),"WhileStatement",(yyvsp[-3].str));non_terminalchild((yyval.node),"WhileStatement",(yyvsp[-2].node));terminal_child((yyval.node),"WhileStatement",(yyvsp[-1].str));non_terminalchild((yyval.node),"WhileStatement",(yyvsp[0].node));}
#line 3396 "ast.tab.cpp"
    break;

  case 203: /* WhileStatementNoShortIf: while1 open_bracket AssignmentExpression closed_bracket StatementNoShortIf  */
#line 664 "ast.ypp"
                                                                                  {(yyval.node)=fterminal_child("WhileStatementNoShortIf",(yyvsp[-4].str));terminal_child((yyval.node),"WhileStatementNoShortIf",(yyvsp[-3].str));non_terminalchild((yyval.node),"WhileStatementNShortIf",(yyvsp[-2].node));terminal_child((yyval.node),"WhileStatementNoShortIf",(yyvsp[-1].str));non_terminalchild((yyval.node),"WhileStatementNoShortIf",(yyvsp[0].node));}
#line 3402 "ast.tab.cpp"
    break;

  case 204: /* DoStatement: do1 Statement while1 open_bracket AssignmentExpression closed_bracket semicolon  */
#line 668 "ast.ypp"
                                                                                       {(yyval.node)=fterminal_child("DoStatement",(yyvsp[-6].str));non_terminalchild((yyval.node),"DoStatement",(yyvsp[-5].node));terminal_child((yyval.node),"DoStatement",(yyvsp[-4].str));terminal_child((yyval.node),"DoStatement",(yyvsp[-3].str));non_terminalchild((yyval.node),"DoStatement",(yyvsp[-2].node));terminal_child((yyval.node),"DoStatement",(yyvsp[-1].str));terminal_child((yyval.node),"DoStatement",(yyvsp[0].str));}
#line 3408 "ast.tab.cpp"
    break;

  case 205: /* ForStatement: for1 open_bracket ForInitopt semicolon Expressionopt semicolon ForUpdateopt closed_bracket Statement  */
#line 672 "ast.ypp"
                                                                                                            {(yyval.node)=fterminal_child("ForStatement",(yyvsp[-8].str));terminal_child((yyval.node),"ForStatement",(yyvsp[-7].str));non_terminalchild((yyval.node),"ForStatement",(yyvsp[-6].node));terminal_child((yyval.node),"ForStatement",(yyvsp[-5].str));non_terminalchild((yyval.node),"ForStatement",(yyvsp[-4].node));terminal_child((yyval.node),"ForStatement",(yyvsp[-3].str));non_terminalchild((yyval.node),"ForStatement",(yyvsp[-2].node));terminal_child((yyval.node),"ForStatement",(yyvsp[-1].str));non_terminalchild((yyval.node),"ForStatement",(yyvsp[0].node));}
#line 3414 "ast.tab.cpp"
    break;

  case 206: /* ForStatementNoShortIf: for1 open_bracket ForInitopt semicolon Expressionopt semicolon ForUpdateopt closed_bracket StatementNoShortIf  */
#line 676 "ast.ypp"
                                                                                                                     {(yyval.node)=fterminal_child("ForStatementNoShortIf",(yyvsp[-8].str));terminal_child((yyval.node),"ForStatementNoShortIf",(yyvsp[-7].str));non_terminalchild((yyval.node),"ForStatementNoShortIf",(yyvsp[-6].node));terminal_child((yyval.node),"ForStatementNoShortIf",(yyvsp[-5].str));non_terminalchild((yyval.node),"ForStatementNoShortIf",(yyvsp[-4].node));terminal_child((yyval.node),"ForStatementNoShortIf",(yyvsp[-3].str));non_terminalchild((yyval.node),"ForStatementNoShortIf",(yyvsp[-2].node));terminal_child((yyval.node),"ForStatementNoShortIf",(yyvsp[-1].str));non_terminalchild((yyval.node),"ForStatementNoShortIf",(yyvsp[0].node));}
#line 3420 "ast.tab.cpp"
    break;

  case 207: /* ForInitopt: %empty  */
#line 678 "ast.ypp"
            {(yyval.node)=fterminal_child("ForInitopt","");}
#line 3426 "ast.tab.cpp"
    break;

  case 208: /* ForInitopt: ForInit  */
#line 678 "ast.ypp"
                                                           {(yyval.node)=fnon_terminalchild("ForInitopt",(yyvsp[0].node));}
#line 3432 "ast.tab.cpp"
    break;

  case 209: /* Expressionopt: %empty  */
#line 679 "ast.ypp"
               {(yyval.node)=fterminal_child("Expressionopt","");}
#line 3438 "ast.tab.cpp"
    break;

  case 210: /* Expressionopt: AssignmentExpression  */
#line 679 "ast.ypp"
                                                                              {(yyval.node)=fnon_terminalchild("Expressionopt",(yyvsp[0].node));}
#line 3444 "ast.tab.cpp"
    break;

  case 211: /* ForUpdateopt: %empty  */
#line 680 "ast.ypp"
              {(yyval.node)=fterminal_child("ForUpdateopt","");}
#line 3450 "ast.tab.cpp"
    break;

  case 212: /* ForUpdateopt: ForUpdate  */
#line 680 "ast.ypp"
                                                                 {(yyval.node)=fnon_terminalchild("ForUpdateopt",(yyvsp[0].node));}
#line 3456 "ast.tab.cpp"
    break;

  case 213: /* ForInit: StatementExpressionList  */
#line 684 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("ForInit",(yyvsp[0].node));}
#line 3462 "ast.tab.cpp"
    break;

  case 214: /* ForInit: LocalVariableDeclaration  */
#line 686 "ast.ypp"
                                {(yyval.node)=fnon_terminalchild("ForInit",(yyvsp[0].node));}
#line 3468 "ast.tab.cpp"
    break;

  case 215: /* ForUpdate: StatementExpressionList  */
#line 690 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("ForUpdate",(yyvsp[0].node));}
#line 3474 "ast.tab.cpp"
    break;

  case 216: /* StatementExpressionList: StatementExpression  */
#line 694 "ast.ypp"
                           {(yyval.node)=fnon_terminalchild("StatementExpressionList",(yyvsp[0].node));}
#line 3480 "ast.tab.cpp"
    break;

  case 217: /* StatementExpressionList: StatementExpressionList comma StatementExpression  */
#line 696 "ast.ypp"
                                                         {(yyval.node)=fnon_terminalchild("StatementExpressionList",(yyvsp[-2].node));terminal_child((yyval.node),"StatementExpressionList",(yyvsp[-1].str));non_terminalchild((yyval.node),"StatementExpressionList",(yyvsp[0].node));}
#line 3486 "ast.tab.cpp"
    break;

  case 218: /* BreakStatement: break1 Identifieropt semicolon  */
#line 700 "ast.ypp"
                                      {(yyval.node)=fterminal_child("BreakStatement",(yyvsp[-2].str));non_terminalchild((yyval.node),"BreakStatement",(yyvsp[-1].node));terminal_child((yyval.node),"BreakStatement",(yyvsp[0].str));}
#line 3492 "ast.tab.cpp"
    break;

  case 219: /* ContinueStatement: continue1 Identifieropt semicolon  */
#line 704 "ast.ypp"
                                         {(yyval.node)=fterminal_child("ContinueStatement",(yyvsp[-2].str));non_terminalchild((yyval.node),"ContinueStatement",(yyvsp[-1].node));terminal_child((yyval.node),"ContinueStatement",(yyvsp[0].str));}
#line 3498 "ast.tab.cpp"
    break;

  case 220: /* Identifieropt: %empty  */
#line 706 "ast.ypp"
               {(yyval.node)=fterminal_child("Identifieropt","");}
#line 3504 "ast.tab.cpp"
    break;

  case 221: /* Identifieropt: Identifier  */
#line 706 "ast.ypp"
                                                                    {(yyval.node)=fnon_terminalchild("Identifieropt",(yyvsp[0].node));}
#line 3510 "ast.tab.cpp"
    break;

  case 222: /* ReturnStatement: return1 Expressionopt semicolon  */
#line 710 "ast.ypp"
                                       {(yyval.node)=fterminal_child("ReturnStatement",(yyvsp[-2].str));non_terminalchild((yyval.node),"ReturnStatement",(yyvsp[-1].node));terminal_child((yyval.node),"ReturnStatement",(yyvsp[0].str));}
#line 3516 "ast.tab.cpp"
    break;

  case 223: /* ThrowStatement: throw1 AssignmentExpression semicolon  */
#line 714 "ast.ypp"
                                             {(yyval.node)=fterminal_child("ThrowStatement",(yyvsp[-2].str));non_terminalchild((yyval.node),"ThrowStatement",(yyvsp[-1].node));terminal_child((yyval.node),"ThrowStatement",(yyvsp[0].str));}
#line 3522 "ast.tab.cpp"
    break;

  case 224: /* SynchronizedStatement: synchronised open_bracket AssignmentExpression closed_bracket Block  */
#line 718 "ast.ypp"
                                                                           {(yyval.node)=fterminal_child("SynchronizedStatement",(yyvsp[-4].str));terminal_child((yyval.node),"SynchronizedStatement",(yyvsp[-3].str));non_terminalchild((yyval.node),"SynchronizedStatement",(yyvsp[-2].node));terminal_child((yyval.node),"SynchronizedStatement",(yyvsp[-1].str));non_terminalchild((yyval.node),"SynchronizedStatement",(yyvsp[0].node));}
#line 3528 "ast.tab.cpp"
    break;

  case 225: /* TryStatement: try1 Block Catches  */
#line 722 "ast.ypp"
                          {(yyval.node)=fterminal_child("TryStatement",(yyvsp[-2].str));non_terminalchild((yyval.node),"TryStatement",(yyvsp[-1].node));non_terminalchild((yyval.node),"TryStatement",(yyvsp[0].node));}
#line 3534 "ast.tab.cpp"
    break;

  case 226: /* TryStatement: try1 Block Catchesopt Finally  */
#line 724 "ast.ypp"
                                     {(yyval.node)=fterminal_child("TryStatement",(yyvsp[-3].str));non_terminalchild((yyval.node),"TryStatement",(yyvsp[-2].node));non_terminalchild((yyval.node),"TryStatement",(yyvsp[-1].node));non_terminalchild((yyval.node),"TryStatement",(yyvsp[0].node));}
#line 3540 "ast.tab.cpp"
    break;

  case 227: /* Catchesopt: %empty  */
#line 726 "ast.ypp"
            {(yyval.node)=fterminal_child("Catchesopt","");}
#line 3546 "ast.tab.cpp"
    break;

  case 228: /* Catchesopt: Catches  */
#line 726 "ast.ypp"
                                                           {(yyval.node)=fnon_terminalchild("Catchesopt",(yyvsp[0].node));}
#line 3552 "ast.tab.cpp"
    break;

  case 229: /* Catches: CatchClause  */
#line 730 "ast.ypp"
                   {(yyval.node)=fnon_terminalchild("Catches",(yyvsp[0].node));}
#line 3558 "ast.tab.cpp"
    break;

  case 230: /* Catches: Catches CatchClause  */
#line 732 "ast.ypp"
                           {(yyval.node)=fnon_terminalchild("Catches",(yyvsp[-1].node));non_terminalchild((yyval.node),"Catches",(yyvsp[0].node));}
#line 3564 "ast.tab.cpp"
    break;

  case 231: /* CatchClause: catch1 open_bracket FormalParameter closed_bracket Block  */
#line 736 "ast.ypp"
                                                                {(yyval.node)=fterminal_child("CatchClause",(yyvsp[-4].str));terminal_child((yyval.node),"CatchClause",(yyvsp[-3].str));non_terminalchild((yyval.node),"CatchClause",(yyvsp[-2].node));terminal_child((yyval.node),"CatchClause",(yyvsp[-1].str));}
#line 3570 "ast.tab.cpp"
    break;

  case 232: /* Finally: finally Block  */
#line 740 "ast.ypp"
                     {(yyval.node)=fterminal_child("Finally",(yyvsp[-1].str));non_terminalchild((yyval.node),"Finally",(yyvsp[0].node));}
#line 3576 "ast.tab.cpp"
    break;

  case 233: /* Primary: PrimaryNoNewArray  */
#line 744 "ast.ypp"
                         {(yyval.node)=fnon_terminalchild("Primary",(yyvsp[0].node));}
#line 3582 "ast.tab.cpp"
    break;

  case 234: /* Primary: ArrayCreationExpression  */
#line 746 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("Primary",(yyvsp[0].node));}
#line 3588 "ast.tab.cpp"
    break;

  case 235: /* PrimaryNoNewArray: Literal  */
#line 750 "ast.ypp"
               {(yyval.node)=fnon_terminalchild("PrimaryNoArray",(yyvsp[0].node));}
#line 3594 "ast.tab.cpp"
    break;

  case 236: /* PrimaryNoNewArray: this1  */
#line 752 "ast.ypp"
             {(yyval.node)=fterminal_child("PrimaryNoArray",(yyvsp[0].str));}
#line 3600 "ast.tab.cpp"
    break;

  case 237: /* PrimaryNoNewArray: open_bracket AssignmentExpression closed_bracket  */
#line 754 "ast.ypp"
                                                        {(yyval.node)=fterminal_child("PrimaryNoArray",(yyvsp[-2].str));non_terminalchild((yyval.node),"PrimaryNoArray",(yyvsp[-1].node));terminal_child((yyval.node),"PrimaryNoArray",(yyvsp[0].str));}
#line 3606 "ast.tab.cpp"
    break;

  case 238: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 756 "ast.ypp"
                                       {(yyval.node)=fnon_terminalchild("PrimaryNoArray",(yyvsp[0].node));}
#line 3612 "ast.tab.cpp"
    break;

  case 239: /* PrimaryNoNewArray: FieldAccess  */
#line 758 "ast.ypp"
                   {(yyval.node)=fnon_terminalchild("PrimaryNoArray",(yyvsp[0].node));}
#line 3618 "ast.tab.cpp"
    break;

  case 240: /* PrimaryNoNewArray: MethodInvocation  */
#line 760 "ast.ypp"
                        {(yyval.node)=fnon_terminalchild("PrimaryNoArray",(yyvsp[0].node));}
#line 3624 "ast.tab.cpp"
    break;

  case 241: /* PrimaryNoNewArray: ArrayAccess  */
#line 762 "ast.ypp"
                   {(yyval.node)=fnon_terminalchild("PrimaryNoArray",(yyvsp[0].node));}
#line 3630 "ast.tab.cpp"
    break;

  case 242: /* ClassInstanceCreationExpression: new1 Name open_bracket ArgumentListopt closed_bracket  */
#line 766 "ast.ypp"
                                                             {(yyval.node)=fterminal_child("ClassInstanceCreationExpression",(yyvsp[-4].str));non_terminalchild((yyval.node),"ClassInstanceCreationExpression",(yyvsp[-3].node));terminal_child((yyval.node),"ClassInstanceCreationExpression",(yyvsp[-2].str));non_terminalchild((yyval.node),"ClassInstanceCreationExpression",(yyvsp[-1].node));terminal_child((yyval.node),"ClassInstanceCreationExpression",(yyvsp[0].str));}
#line 3636 "ast.tab.cpp"
    break;

  case 243: /* ArgumentList: AssignmentExpression  */
#line 770 "ast.ypp"
                            {(yyval.node)=fnon_terminalchild("ArgumentList",(yyvsp[0].node));}
#line 3642 "ast.tab.cpp"
    break;

  case 244: /* ArgumentList: ArgumentList comma AssignmentExpression  */
#line 772 "ast.ypp"
                                               {(yyval.node)=fnon_terminalchild("ArgumentList",(yyvsp[-2].node));terminal_child((yyval.node),"ArgumentList",(yyvsp[-1].str));non_terminalchild((yyval.node),"ArgumentList",(yyvsp[0].node));}
#line 3648 "ast.tab.cpp"
    break;

  case 245: /* ArrayCreationExpression: new1 PrimitiveType DimExprs Dimsopt  */
#line 776 "ast.ypp"
                                           {(yyval.node)=fterminal_child("ArrayCreationExpression",(yyvsp[-3].str));non_terminalchild((yyval.node),"ArrayCreationExpression",(yyvsp[-2].node));non_terminalchild((yyval.node),"ArrayCreationExpression",(yyvsp[-1].node));non_terminalchild((yyval.node),"ArrayCreationExpression",(yyvsp[0].node));}
#line 3654 "ast.tab.cpp"
    break;

  case 246: /* ArrayCreationExpression: new1 Name DimExprs Dimsopt  */
#line 778 "ast.ypp"
                                  {(yyval.node)=fterminal_child("ArrayCreationExpression",(yyvsp[-3].str));non_terminalchild((yyval.node),"ArrayCreationExpression",(yyvsp[-2].node));non_terminalchild((yyval.node),"ArrayCreationExpression",(yyvsp[-1].node));non_terminalchild((yyval.node),"ArrayCreationExpression",(yyvsp[0].node));}
#line 3660 "ast.tab.cpp"
    break;

  case 247: /* Dimsopt: %empty  */
#line 780 "ast.ypp"
         {(yyval.node)=fterminal_child("Dimsopt","");}
#line 3666 "ast.tab.cpp"
    break;

  case 248: /* Dimsopt: Dims  */
#line 780 "ast.ypp"
                                                  {(yyval.node)=fnon_terminalchild("Dimsopt",(yyvsp[0].node));}
#line 3672 "ast.tab.cpp"
    break;

  case 249: /* DimExprs: DimExpr  */
#line 784 "ast.ypp"
               {(yyval.node)=fnon_terminalchild("DimExprs",(yyvsp[0].node));}
#line 3678 "ast.tab.cpp"
    break;

  case 250: /* DimExprs: DimExprs DimExpr  */
#line 786 "ast.ypp"
                        {(yyval.node)=fnon_terminalchild("DimExprs",(yyvsp[-1].node));non_terminalchild((yyval.node),"DimExprs",(yyvsp[0].node));}
#line 3684 "ast.tab.cpp"
    break;

  case 251: /* DimExpr: open_square_bracket AssignmentExpression closed_square_bracket  */
#line 790 "ast.ypp"
                                                                      {(yyval.node)=fterminal_child("DimExpr",(yyvsp[-2].str));non_terminalchild((yyval.node),"DimExpr",(yyvsp[-1].node));terminal_child((yyval.node),"DimExpr",(yyvsp[0].str));}
#line 3690 "ast.tab.cpp"
    break;

  case 252: /* Dims: open_square_bracket closed_square_bracket  */
#line 794 "ast.ypp"
                                                 {(yyval.node)=fterminal_child("Dims",(yyvsp[-1].str));terminal_child((yyval.node),"Dims",(yyvsp[0].str));}
#line 3696 "ast.tab.cpp"
    break;

  case 253: /* Dims: Dims open_square_bracket closed_square_bracket  */
#line 796 "ast.ypp"
                                                      {(yyval.node)=fnon_terminalchild("Dims",(yyvsp[-2].node));terminal_child((yyval.node),"Dims",(yyvsp[-1].str));terminal_child((yyval.node),"Dims",(yyvsp[0].str));}
#line 3702 "ast.tab.cpp"
    break;

  case 254: /* FieldAccess: Primary period Identifier  */
#line 800 "ast.ypp"
                                 {(yyval.node)=fnon_terminalchild("FieldAccess",(yyvsp[-2].node));terminal_child((yyval.node),"FieldAccess",(yyvsp[-1].str));non_terminalchild((yyval.node),"FieldAccess",(yyvsp[0].node));}
#line 3708 "ast.tab.cpp"
    break;

  case 255: /* FieldAccess: super period Identifier  */
#line 802 "ast.ypp"
                               {(yyval.node)=fterminal_child("FieldAccess",(yyvsp[-2].str));terminal_child((yyval.node),"Dims",(yyvsp[-1].str));non_terminalchild((yyval.node),"FieldAccess",(yyvsp[0].node));}
#line 3714 "ast.tab.cpp"
    break;

  case 256: /* MethodInvocation: Name open_bracket ArgumentListopt closed_bracket  */
#line 806 "ast.ypp"
                                                        {(yyval.node)=fnon_terminalchild("MethodInvocation",(yyvsp[-3].node));terminal_child((yyval.node),"MethodInvocation",(yyvsp[-2].str));non_terminalchild((yyval.node),"MethodInvocation",(yyvsp[-1].node));terminal_child((yyval.node),"MethodInvocation",(yyvsp[0].str));}
#line 3720 "ast.tab.cpp"
    break;

  case 257: /* MethodInvocation: Primary period Identifier open_bracket ArgumentListopt closed_bracket  */
#line 808 "ast.ypp"
                                                                             {(yyval.node)=fnon_terminalchild("MethodInvocation",(yyvsp[-5].node));terminal_child((yyval.node),"MethodInvocation",(yyvsp[-4].str));non_terminalchild((yyval.node),"MethodInvocation",(yyvsp[-3].node));terminal_child((yyval.node),"MethodInvocation",(yyvsp[-2].str));non_terminalchild((yyval.node),"MethodInvocation",(yyvsp[-1].node));terminal_child((yyval.node),"MethodInvocation",(yyvsp[0].str));}
#line 3726 "ast.tab.cpp"
    break;

  case 258: /* MethodInvocation: super period Identifier open_bracket ArgumentListopt closed_bracket  */
#line 810 "ast.ypp"
                                                                           {(yyval.node)=fterminal_child("MethodInvocation",(yyvsp[-5].str));terminal_child((yyval.node),"MethodInvocation",(yyvsp[-4].str));non_terminalchild((yyval.node),"MethodInvocation",(yyvsp[-3].node));terminal_child((yyval.node),"MethodInvocation",(yyvsp[-2].str));non_terminalchild((yyval.node),"MethodInvocation",(yyvsp[-1].node));terminal_child((yyval.node),"MethodInvocation",(yyvsp[0].str));}
#line 3732 "ast.tab.cpp"
    break;

  case 259: /* ArrayAccess: Name open_square_bracket AssignmentExpression closed_square_bracket  */
#line 814 "ast.ypp"
                                                                           {(yyval.node)=fnon_terminalchild("ArrayAccess",(yyvsp[-3].node));terminal_child((yyval.node),"ArrayAccess",(yyvsp[-2].str));non_terminalchild((yyval.node),"ArrayAccess",(yyvsp[-1].node));terminal_child((yyval.node),"ArrayAccess",(yyvsp[0].str));}
#line 3738 "ast.tab.cpp"
    break;

  case 260: /* ArrayAccess: PrimaryNoNewArray open_square_bracket AssignmentExpression closed_square_bracket  */
#line 816 "ast.ypp"
                                                                                        {(yyval.node)=fnon_terminalchild("ArrayAccess",(yyvsp[-3].node));terminal_child((yyval.node),"ArrayAccess",(yyvsp[-2].str));non_terminalchild((yyval.node),"ArrayAccess",(yyvsp[-1].node));terminal_child((yyval.node),"ArrayAccess",(yyvsp[0].str));}
#line 3744 "ast.tab.cpp"
    break;

  case 261: /* PostfixExpression: Primary  */
#line 820 "ast.ypp"
               {(yyval.node)=fnon_terminalchild("PostfixExpression",(yyvsp[0].node));}
#line 3750 "ast.tab.cpp"
    break;

  case 262: /* PostfixExpression: Name  */
#line 822 "ast.ypp"
            {(yyval.node)=fnon_terminalchild("PostfixExpression",(yyvsp[0].node));}
#line 3756 "ast.tab.cpp"
    break;

  case 263: /* PostfixExpression: PostIncrementExpression  */
#line 824 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("PostfixExpression",(yyvsp[0].node));}
#line 3762 "ast.tab.cpp"
    break;

  case 264: /* PostfixExpression: PostDecrementExpression  */
#line 826 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("PostfixExpression",(yyvsp[0].node));}
#line 3768 "ast.tab.cpp"
    break;

  case 265: /* PostIncrementExpression: PostfixExpression increment  */
#line 830 "ast.ypp"
                                   {(yyval.node)=fnon_terminalchild("PostIncrementExpression",(yyvsp[-1].node));terminal_child((yyval.node),"PostIncrementExpression",(yyvsp[0].str));}
#line 3774 "ast.tab.cpp"
    break;

  case 266: /* PostDecrementExpression: PostfixExpression decrement  */
#line 834 "ast.ypp"
                                   {(yyval.node)=fnon_terminalchild("PostDecrementExpression",(yyvsp[-1].node));terminal_child((yyval.node),"PostDecrementExpression",(yyvsp[0].str));}
#line 3780 "ast.tab.cpp"
    break;

  case 267: /* UnaryExpression: PreIncrementExpression  */
#line 838 "ast.ypp"
                              {(yyval.node)=fnon_terminalchild("UnaryExpression",(yyvsp[0].node));}
#line 3786 "ast.tab.cpp"
    break;

  case 268: /* UnaryExpression: PreDecrementExpression  */
#line 840 "ast.ypp"
                              {(yyval.node)=fnon_terminalchild("UnaryExpression",(yyvsp[0].node));}
#line 3792 "ast.tab.cpp"
    break;

  case 269: /* UnaryExpression: plus_1 UnaryExpression  */
#line 842 "ast.ypp"
                              {(yyval.node)=fterminal_child("UnaryExpression",(yyvsp[-1].str));non_terminalchild((yyval.node),"UnaryExpression",(yyvsp[0].node));}
#line 3798 "ast.tab.cpp"
    break;

  case 270: /* UnaryExpression: minus_1 UnaryExpression  */
#line 844 "ast.ypp"
                               {(yyval.node)=fterminal_child("UnaryExpression",(yyvsp[-1].str));non_terminalchild((yyval.node),"PostfixExpression",(yyvsp[0].node));}
#line 3804 "ast.tab.cpp"
    break;

  case 271: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 846 "ast.ypp"
                                   {(yyval.node)=fnon_terminalchild("UnaryExpression",(yyvsp[0].node));}
#line 3810 "ast.tab.cpp"
    break;

  case 272: /* PreIncrementExpression: increment UnaryExpression  */
#line 850 "ast.ypp"
                                 {(yyval.node)=fterminal_child("PreIncrementExpression",(yyvsp[-1].str));non_terminalchild((yyval.node),"PreIncrementExpression",(yyvsp[0].node));}
#line 3816 "ast.tab.cpp"
    break;

  case 273: /* PreDecrementExpression: decrement UnaryExpression  */
#line 854 "ast.ypp"
                                 {(yyval.node)=fterminal_child("PreDecrementExpression",(yyvsp[-1].str));non_terminalchild((yyval.node),"PreDecrementExpression",(yyvsp[0].node));}
#line 3822 "ast.tab.cpp"
    break;

  case 274: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 858 "ast.ypp"
                         {(yyval.node)=fnon_terminalchild("UnaryExpressionNotPlusMinus",(yyvsp[0].node));}
#line 3828 "ast.tab.cpp"
    break;

  case 275: /* UnaryExpressionNotPlusMinus: notk UnaryExpression  */
#line 860 "ast.ypp"
                            {(yyval.node)=fterminal_child("UnaryExpressionNotPlusMinus",(yyvsp[-1].str));non_terminalchild((yyval.node),"UnaryExpressionNotPlusMinus",(yyvsp[0].node));}
#line 3834 "ast.tab.cpp"
    break;

  case 276: /* UnaryExpressionNotPlusMinus: exclamatory UnaryExpression  */
#line 862 "ast.ypp"
                                   {(yyval.node)=fterminal_child("UnaryExpressionNotPlusMinus",(yyvsp[-1].str));non_terminalchild((yyval.node),"UnaryExpressionNotPlusMinus",(yyvsp[0].node));}
#line 3840 "ast.tab.cpp"
    break;

  case 277: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 864 "ast.ypp"
                      {(yyval.node)=fnon_terminalchild("UnaryExpressionNotPlusMinus",(yyvsp[0].node));}
#line 3846 "ast.tab.cpp"
    break;

  case 278: /* CastExpression: open_bracket PrimitiveType Dimsopt closed_bracket UnaryExpression  */
#line 868 "ast.ypp"
                                                                         {(yyval.node)=fterminal_child("CastExpression",(yyvsp[-4].str));non_terminalchild((yyval.node),"CastExpression",(yyvsp[-3].node));non_terminalchild((yyval.node),"CastExpression",(yyvsp[-2].node));terminal_child((yyval.node),"CastExpression",(yyvsp[-1].str));non_terminalchild((yyval.node),"CastExpression",(yyvsp[0].node));}
#line 3852 "ast.tab.cpp"
    break;

  case 279: /* CastExpression: open_bracket AssignmentExpression closed_bracket UnaryExpressionNotPlusMinus  */
#line 870 "ast.ypp"
                                                                                    {(yyval.node)=fterminal_child("CastExpression",(yyvsp[-3].str));non_terminalchild((yyval.node),"CastExpression",(yyvsp[-2].node));terminal_child((yyval.node),"CastExpression",(yyvsp[-1].str));non_terminalchild((yyval.node),"CastExpression",(yyvsp[0].node));}
#line 3858 "ast.tab.cpp"
    break;

  case 280: /* CastExpression: open_bracket Name Dims closed_bracket UnaryExpressionNotPlusMinus  */
#line 872 "ast.ypp"
                                                                         {(yyval.node)=fterminal_child("CastExpression",(yyvsp[-4].str));non_terminalchild((yyval.node),"CastExpression",(yyvsp[-3].node));non_terminalchild((yyval.node),"CastExpression",(yyvsp[-2].node));terminal_child((yyval.node),"CastExpression",(yyvsp[-1].str));non_terminalchild((yyval.node),"CastExpression",(yyvsp[0].node));}
#line 3864 "ast.tab.cpp"
    break;

  case 281: /* MultiplicativeExpression: UnaryExpression  */
#line 876 "ast.ypp"
                       {(yyval.node)=fnon_terminalchild("MultiplicativeExpression",(yyvsp[0].node));}
#line 3870 "ast.tab.cpp"
    break;

  case 282: /* MultiplicativeExpression: MultiplicativeExpression multiply UnaryExpression  */
#line 878 "ast.ypp"
                                                         {(yyval.node)=nonopnon( "MultiplicativeExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3876 "ast.tab.cpp"
    break;

  case 283: /* MultiplicativeExpression: MultiplicativeExpression divide UnaryExpression  */
#line 880 "ast.ypp"
                                                       {(yyval.node)=nonopnon( "MultiplicativeExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3882 "ast.tab.cpp"
    break;

  case 284: /* MultiplicativeExpression: MultiplicativeExpression percentage UnaryExpression  */
#line 882 "ast.ypp"
                                                           {(yyval.node)=nonopnon( "MultiplicativeExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3888 "ast.tab.cpp"
    break;

  case 285: /* AdditiveExpression: MultiplicativeExpression  */
#line 886 "ast.ypp"
                                {(yyval.node)=fnon_terminalchild("AdditiveExpression",(yyvsp[0].node));}
#line 3894 "ast.tab.cpp"
    break;

  case 286: /* AdditiveExpression: AdditiveExpression plus_1 MultiplicativeExpression  */
#line 888 "ast.ypp"
                                                          {(yyval.node)=nonopnon( "AdditiveExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3900 "ast.tab.cpp"
    break;

  case 287: /* AdditiveExpression: AdditiveExpression minus_1 MultiplicativeExpression  */
#line 890 "ast.ypp"
                                                           {(yyval.node)=nonopnon( "AdditiveExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3906 "ast.tab.cpp"
    break;

  case 288: /* ShiftExpression: AdditiveExpression  */
#line 894 "ast.ypp"
                          {(yyval.node)=fnon_terminalchild("ShiftExpression",(yyvsp[0].node));}
#line 3912 "ast.tab.cpp"
    break;

  case 289: /* ShiftExpression: ShiftExpression llthan AdditiveExpression  */
#line 896 "ast.ypp"
                                                 {(yyval.node)=nonopnon( "ShiftExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3918 "ast.tab.cpp"
    break;

  case 290: /* ShiftExpression: ShiftExpression ggthan AdditiveExpression  */
#line 898 "ast.ypp"
                                                 {(yyval.node)=nonopnon( "ShiftExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3924 "ast.tab.cpp"
    break;

  case 291: /* ShiftExpression: ShiftExpression gggthan AdditiveExpression  */
#line 900 "ast.ypp"
                                                  {(yyval.node)=nonopnon( "ShiftExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3930 "ast.tab.cpp"
    break;

  case 292: /* RelationalExpression: ShiftExpression  */
#line 904 "ast.ypp"
                       {(yyval.node)=fnon_terminalchild("RelationalExpression",(yyvsp[0].node));}
#line 3936 "ast.tab.cpp"
    break;

  case 293: /* RelationalExpression: RelationalExpression lthan ShiftExpression  */
#line 906 "ast.ypp"
                                                  {(yyval.node)=nonopnon( "RelationalExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3942 "ast.tab.cpp"
    break;

  case 294: /* RelationalExpression: RelationalExpression gthan ShiftExpression  */
#line 908 "ast.ypp"
                                                  {(yyval.node)=nonopnon( "RelationalExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3948 "ast.tab.cpp"
    break;

  case 295: /* RelationalExpression: RelationalExpression l_equal ShiftExpression  */
#line 910 "ast.ypp"
                                                    {(yyval.node)=nonopnon( "RelationalExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3954 "ast.tab.cpp"
    break;

  case 296: /* RelationalExpression: RelationalExpression g_equal ShiftExpression  */
#line 912 "ast.ypp"
                                                    {(yyval.node)=nonopnon( "RelationalExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3960 "ast.tab.cpp"
    break;

  case 297: /* RelationalExpression: RelationalExpression instanceof ReferenceType  */
#line 914 "ast.ypp"
                                                     {(yyval.node)=fnon_terminalchild("RelationalExpression",(yyvsp[-2].node));terminal_child((yyval.node),"RelationalExpression",(yyvsp[-1].str));non_terminalchild((yyval.node),"RelationalExpression",(yyvsp[0].node));}
#line 3966 "ast.tab.cpp"
    break;

  case 298: /* EqualityExpression: RelationalExpression  */
#line 918 "ast.ypp"
                            {(yyval.node)=fnon_terminalchild("EqualityExpression",(yyvsp[0].node));}
#line 3972 "ast.tab.cpp"
    break;

  case 299: /* EqualityExpression: EqualityExpression equal_equal RelationalExpression  */
#line 920 "ast.ypp"
                                                           {(yyval.node)=nonopnon( "EqualityExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3978 "ast.tab.cpp"
    break;

  case 300: /* EqualityExpression: EqualityExpression exclamatory_equal RelationalExpression  */
#line 922 "ast.ypp"
                                                                 {(yyval.node)=nonopnon( "EqualityExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3984 "ast.tab.cpp"
    break;

  case 301: /* AndExpression: EqualityExpression  */
#line 926 "ast.ypp"
                          {(yyval.node)=fnon_terminalchild("AndExpression",(yyvsp[0].node));}
#line 3990 "ast.tab.cpp"
    break;

  case 302: /* AndExpression: AndExpression band EqualityExpression  */
#line 928 "ast.ypp"
                                             {(yyval.node)=nonopnon( "AndExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 3996 "ast.tab.cpp"
    break;

  case 303: /* ExclusiveOrExpression: AndExpression  */
#line 932 "ast.ypp"
                     {(yyval.node)=fnon_terminalchild("ExclusiveOrExpression",(yyvsp[0].node));}
#line 4002 "ast.tab.cpp"
    break;

  case 304: /* ExclusiveOrExpression: ExclusiveOrExpression power AndExpression  */
#line 934 "ast.ypp"
                                                 {(yyval.node)=nonopnon( "ExclusiveOrExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 4008 "ast.tab.cpp"
    break;

  case 305: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 938 "ast.ypp"
                             {(yyval.node)=fnon_terminalchild("InclusiveOrExpression",(yyvsp[0].node));}
#line 4014 "ast.tab.cpp"
    break;

  case 306: /* InclusiveOrExpression: InclusiveOrExpression bor ExclusiveOrExpression  */
#line 940 "ast.ypp"
                                                       {(yyval.node)=nonopnon( "InclusiveOrExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 4020 "ast.tab.cpp"
    break;

  case 307: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 944 "ast.ypp"
                             {(yyval.node)=fnon_terminalchild("ConditionalAndExpression",(yyvsp[0].node));}
#line 4026 "ast.tab.cpp"
    break;

  case 308: /* ConditionalAndExpression: ConditionalAndExpression and_and InclusiveOrExpression  */
#line 946 "ast.ypp"
                                                              {(yyval.node)=nonopnon( "ConditionalAndExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 4032 "ast.tab.cpp"
    break;

  case 309: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 950 "ast.ypp"
                                {(yyval.node)=fnon_terminalchild("ConditionalOrExpression",(yyvsp[0].node));}
#line 4038 "ast.tab.cpp"
    break;

  case 310: /* ConditionalOrExpression: ConditionalOrExpression or1 ConditionalAndExpression  */
#line 952 "ast.ypp"
                                                            {(yyval.node)=nonopnon( "ConditionalOrExpression",(yyvsp[-1].str),(yyvsp[-2].node),(yyvsp[0].node));}
#line 4044 "ast.tab.cpp"
    break;

  case 311: /* AssignmentExpression: ConditionalOrExpression  */
#line 956 "ast.ypp"
                               {(yyval.node)=fnon_terminalchild("AssignmentExpression",(yyvsp[0].node));}
#line 4050 "ast.tab.cpp"
    break;

  case 312: /* AssignmentExpression: Assignment  */
#line 958 "ast.ypp"
                  {(yyval.node)=fnon_terminalchild("AssignmentExpression",(yyvsp[0].node));}
#line 4056 "ast.tab.cpp"
    break;

  case 313: /* Assignment: LeftHandSide AssignmentOperator AssignmentExpression  */
#line 962 "ast.ypp"
                                                            {(yyval.node)=fnon_terminalchild("Assignment",(yyvsp[-2].node));non_terminalchild((yyval.node),"Assignment",(yyvsp[-1].node));non_terminalchild((yyval.node),"Assignment",(yyvsp[0].node));}
#line 4062 "ast.tab.cpp"
    break;

  case 314: /* LeftHandSide: Name open_flower_bracket closed_flower_bracket  */
#line 966 "ast.ypp"
                                                      {(yyval.node)=fnon_terminalchild("LeftHandSide",(yyvsp[-2].node));terminal_child((yyval.node),"LeftHandSide",(yyvsp[-1].str));terminal_child((yyval.node),"LeftHandSide",(yyvsp[0].str));}
#line 4068 "ast.tab.cpp"
    break;

  case 315: /* LeftHandSide: FieldAccess  */
#line 968 "ast.ypp"
                   {(yyval.node)=fnon_terminalchild("LeftHandSide",(yyvsp[0].node));}
#line 4074 "ast.tab.cpp"
    break;

  case 316: /* LeftHandSide: ArrayAccess  */
#line 970 "ast.ypp"
                   {(yyval.node)=fnon_terminalchild("LeftHandSide",(yyvsp[0].node));}
#line 4080 "ast.tab.cpp"
    break;

  case 317: /* AssignmentOperator: equal1  */
#line 974 "ast.ypp"
              {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4086 "ast.tab.cpp"
    break;

  case 318: /* AssignmentOperator: multiply_equal  */
#line 975 "ast.ypp"
                  {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4092 "ast.tab.cpp"
    break;

  case 319: /* AssignmentOperator: divide_equal  */
#line 976 "ast.ypp"
                {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4098 "ast.tab.cpp"
    break;

  case 320: /* AssignmentOperator: percentage_equal  */
#line 977 "ast.ypp"
                    {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4104 "ast.tab.cpp"
    break;

  case 321: /* AssignmentOperator: plus_equal  */
#line 978 "ast.ypp"
              {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4110 "ast.tab.cpp"
    break;

  case 322: /* AssignmentOperator: minus_equal  */
#line 979 "ast.ypp"
               {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4116 "ast.tab.cpp"
    break;

  case 323: /* AssignmentOperator: ll_equal  */
#line 980 "ast.ypp"
            {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4122 "ast.tab.cpp"
    break;

  case 324: /* AssignmentOperator: gg_equal  */
#line 981 "ast.ypp"
            {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4128 "ast.tab.cpp"
    break;

  case 325: /* AssignmentOperator: ggg_equal  */
#line 982 "ast.ypp"
             {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4134 "ast.tab.cpp"
    break;

  case 326: /* AssignmentOperator: power_equal  */
#line 983 "ast.ypp"
               {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4140 "ast.tab.cpp"
    break;

  case 327: /* AssignmentOperator: bitand_equal  */
#line 983 "ast.ypp"
                                                                           {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4146 "ast.tab.cpp"
    break;

  case 328: /* AssignmentOperator: bitor_equal  */
#line 983 "ast.ypp"
                                                                                                                                      {(yyval.node)=fterminal_child("AssignmentOperator",(yyvsp[0].str));}
#line 4152 "ast.tab.cpp"
    break;


#line 4156 "ast.tab.cpp"

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

#line 986 "ast.ypp"


int main(int argc, char** argv)
{
  yyparse();
  string filename = "graph.dot";
  std::ofstream ofs;
ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
ofs.close();
  print_graph_in_dot(root, filename);

  return 0;
}
void yyerror(char const * message)
{
    cout<<endl<<" Entered code is invalid, unable to parse" << yylineno <<endl;
}
