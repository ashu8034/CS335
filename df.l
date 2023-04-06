%option header-file="lex.yy.h"
%option noyywrap
%option yylineno

%top{
 #include "ast.tab.hpp"
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <sstream>
using namespace std;
int comment;
}

identifier [a-zA-Z][a-zA-Z0-9_]*
ws [ ]
LT [\t]

%%

"/*" {comment=1;}
"*/" {if(comment)comment=0; else{cout << "Error: unexpected */ in line-" << yylineno;}}
"//".* 

"abstract"        {if(!comment)yylval.str=strdup(yytext); return(abstract);}
"assert"          {if(!comment)yylval.str=strdup(yytext); return(assert);}
"boolean"         {if(!comment)yylval.str=strdup(yytext); return(boolean);}
"break"           {if(!comment)yylval.str=strdup(yytext); return(break1);}
"byte"            {if(!comment)yylval.str=strdup(yytext); return(byte1);}
"case"            {if(!comment)yylval.str=strdup(yytext); return(case1);}
"catch"           {if(!comment)yylval.str=strdup(yytext); return(catch1);}
"char"            {if(!comment)yylval.str=strdup(yytext); return(char1);}
"class"           {if(!comment)yylval.str=strdup(yytext); return(class1);}
"const"           {if(!comment)yylval.str=strdup(yytext); return(const1);}
"_"               {if(!comment)yylval.str=strdup(yytext); return(underscore);}
"continue"        {if(!comment)yylval.str=strdup(yytext); return(continue1);}
"default"         {if(!comment)yylval.str=strdup(yytext); return(default1);}
"do"             {if(!comment)yylval.str=strdup(yytext); return(do1);}
"double"         {if(!comment)yylval.str=strdup(yytext); return(double1);}
"else"           {if(!comment)yylval.str=strdup(yytext); return(else1);}
"enum"           {if(!comment)yylval.str=strdup(yytext); return(enum1);}
"extends"        {if(!comment)yylval.str=strdup(yytext); return(extends);}
"final"          {if(!comment)yylval.str=strdup(yytext); return(final);}
"finally"        {if(!comment)yylval.str=strdup(yytext); return(finally);}
"float"         {if(!comment)yylval.str=strdup(yytext); return(float1);}
"for"           {if(!comment)yylval.str=strdup(yytext); return(for1);}
"if"             {if(!comment)yylval.str=strdup(yytext); return(if1);}
"goto"           {if(!comment)yylval.str=strdup(yytext); return(goto1);}
"implements"     {if(!comment)yylval.str=strdup(yytext); return(implements);}
"import"         {if(!comment)yylval.str=strdup(yytext); return(import);}
"instanceof"     {if(!comment)yylval.str=strdup(yytext); return(instanceof);}
"int"            {if(!comment)yylval.str=strdup(yytext); return(int1);}
"interface"       {if(!comment)yylval.str=strdup(yytext); return(interface);}
"long"           {if(!comment)yylval.str=strdup(yytext); return(long1);}
"native"         {if(!comment)yylval.str=strdup(yytext); return(native);}
"new"           {if(!comment)yylval.str=strdup(yytext); return(new1);}
"package"        {if(!comment)yylval.str=strdup(yytext); return(package);}
"private"       {if(!comment)yylval.str=strdup(yytext); return(private1);}
"protected"     {if(!comment)yylval.str=strdup(yytext); return(protected1);}
"public"        {if(!comment)yylval.str=strdup(yytext); return(public1);}
"return"        {if(!comment)yylval.str=strdup(yytext); return(return1);}
"static"        {if(!comment)yylval.str=strdup(yytext); return(static1);}
"strictfp"      {if(!comment)yylval.str=strdup(yytext); return(strictfp);}
"short"         {if(!comment)yylval.str=strdup(yytext); return(short1);}
"super"         {if(!comment)yylval.str=strdup(yytext); return(super);}
"switch"        {if(!comment)yylval.str=strdup(yytext); return(switch1);}
"synchronised"  {if(!comment)yylval.str=strdup(yytext); return(synchronised);}
"this"         {if(!comment)yylval.str=strdup(yytext); return(this1);}
"throw"        {if(!comment)yylval.str=strdup(yytext); return(throw1);}
"throws"      {if(!comment)yylval.str=strdup(yytext); return(throws);}
"transient"  {if(!comment)yylval.str=strdup(yytext); return(transient);}
"try"       {if(!comment)yylval.str=strdup(yytext); return(try1);}
"void"     {if(!comment)yylval.str=strdup(yytext); return(void1);}
"volatile" {if(!comment)yylval.str=strdup(yytext); return(volatile1);}
"while" {if(!comment)yylval.str=strdup(yytext); return(while1);}

"exports"     {if(!comment)yylval.str=strdup(yytext); return(exports);} 
"module"      {if(!comment)yylval.str=strdup(yytext); return(module1);} 
"non-sealed"  {if(!comment)yylval.str=strdup(yytext); return(NonSealed);} 
"open"        {if(!comment)yylval.str=strdup(yytext); return(open);} 
"opens"       {if(!comment)yylval.str=strdup(yytext); return(opens);} 
"permits"     {if(!comment)yylval.str=strdup(yytext); return(permits);} 
"provides"     {if(!comment)yylval.str=strdup(yytext); return(provides);} 
"record"       {if(!comment)yylval.str=strdup(yytext); return(record);} 
"requires"     {if(!comment)yylval.str=strdup(yytext); return(requires1);} 
"sealed"       {if(!comment)yylval.str=strdup(yytext); return(sealed);} 
"to"           {if(!comment)yylval.str=strdup(yytext); return(to);} 
"transitive"  {if(!comment)yylval.str=strdup(yytext); return(transitive);} 
"uses"    {if(!comment)yylval.str=strdup(yytext); return(uses);} 
"var"    {if(!comment)yylval.str=strdup(yytext); return(var);} 
"with"   {if(!comment)yylval.str=strdup(yytext); return(with);} 
"yield" {if(!comment)yylval.str=strdup(yytext); return(yield);} 

","   {if(!comment)yylval.str=strdup(yytext);return(comma);}
";"   {if(!comment)yylval.str=strdup(yytext);return(semicolon);}
"."   {if(!comment)yylval.str=strdup(yytext);return(period);}
"("   {if(!comment)yylval.str=strdup(yytext);return(open_bracket);}
")"   {if(!comment)yylval.str=strdup(yytext);return(closed_bracket);}
"["   {if(!comment)yylval.str=strdup(yytext);return(open_square_bracket);}
"]"   {if(!comment)yylval.str=strdup(yytext);return(closed_square_bracket);}
"..." {if(!comment)yylval.str=strdup(yytext);return(dots_three);}
"@"   {if(!comment)yylval.str=strdup(yytext);return(at);}
"::"  {if(!comment)yylval.str=strdup(yytext);return(colon_colon);}
"{"  {if(!comment)yylval.str=strdup(yytext);return(open_flower_bracket);}
"}" {if(!comment)yylval.str=strdup(yytext);return(closed_flower_bracket);} 

"="  {if(!comment)yylval.str=strdup(yytext);return(equal1);}
">"  {if(!comment)yylval.str=strdup(yytext);return(gthan);}
"<>" {if(!comment)yylval.str=strdup(yytext);return(diamond);}
"<"  {if(!comment)yylval.str=strdup(yytext);return(lthan);}
"!"  {if(!comment)yylval.str=strdup(yytext);return(exclamatory);}
"~"  {if(!comment)yylval.str=strdup(yytext);return(notk);}
"?"  {if(!comment)yylval.str=strdup(yytext);return(qmark);}
":"  {if(!comment)yylval.str=strdup(yytext);return(colon);}
"->"  {if(!comment)yylval.str=strdup(yytext);return(implies);}
"=="  {if(!comment)yylval.str=strdup(yytext);return(equal_equal);}
">="  {if(!comment)yylval.str=strdup(yytext);return(g_equal);}
"<="   {if(!comment)yylval.str=strdup(yytext);return(l_equal);}
"!="   {if(!comment)yylval.str=strdup(yytext);return(exclamatory_equal);}
"&&"   {if(!comment)yylval.str=strdup(yytext);return(and_and);}
"||"  {if(!comment)yylval.str=strdup(yytext);return(or1);}
"++"  {if(!comment)yylval.str=strdup(yytext);return(increment);}
"--"  {if(!comment)yylval.str=strdup(yytext);return(decrement);}
"+"   {if(!comment)yylval.str=strdup(yytext);return(plus_1);}
"-"   {if(!comment)yylval.str=strdup(yytext);return(minus_1);}
"*"   {if(!comment)yylval.str=strdup(yytext);return(multiply);}
"/"   {if(!comment)yylval.str=strdup(yytext);return(divide);}
"&"   {if(!comment)yylval.str=strdup(yytext);return(band);}
"|"   {if(!comment)yylval.str=strdup(yytext);return(bor);}
"^"   {if(!comment)yylval.str=strdup(yytext);return(power);}
"%"   {if(!comment)yylval.str=strdup(yytext);return(percentage);}
"<<"  {if(!comment)yylval.str=strdup(yytext);return(llthan);}
">>"  {if(!comment)yylval.str=strdup(yytext);return(ggthan);}
">>>"  {if(!comment)yylval.str=strdup(yytext);return(gggthan);}
"+="   {if(!comment)yylval.str=strdup(yytext);return(plus_equal);}
"-="   {if(!comment)yylval.str=strdup(yytext);return(minus_equal);}
"*="   {if(!comment)yylval.str=strdup(yytext);return(multiply_equal);}
"/="   {if(!comment)yylval.str=strdup(yytext);return(divide_equal);}
"&="   {if(!comment)yylval.str=strdup(yytext);return(bitand_equal);}
"|="   {if(!comment)yylval.str=strdup(yytext);return(bitor_equal);}
"^="  {if(!comment)yylval.str=strdup(yytext);return(power_equal);}
"%="  {if(!comment)yylval.str=strdup(yytext);return(percentage_equal);}
"<<="  {if(!comment)yylval.str=strdup(yytext);return(ll_equal);}
">>="  {if(!comment)yylval.str=strdup(yytext);return(gg_equal);}
">>>=" {if(!comment)yylval.str=strdup(yytext);return(ggg_equal);}

"true"|"false" {if(!comment)yylval.str=strdup(yytext);return(BooleanLiteral);}

"null" {if(!comment)yylval.str=strdup(yytext);return(NullLiteral);}

{identifier} {if(!comment)yylval.str=strdup(yytext);return(identifier);}

(([0-9]*\.[0-9]+[fFdD]?)|([0-9]+\.[0-9]*[fFdD]?))(((e|E)[\-\+]?[0-9]+[fFdD]?)|[0-9]*) {if(!comment)yylval.fval=atof(strdup(yytext));return(decfloat);}

(([0][fFdDlL]?)|([1-9]+[0-9]*[lLfFdD]?)) {if(!comment)yylval.ival=atoi(strdup(yytext));return(decint);}

[0][bB](([01]+[lL]?)) {if(!comment)yylval.ival=atoi(strdup(yytext));return(binint);}

([0](([0-7]+)[lL]?)) {if(!comment)yylval.ival=atoi(strdup(yytext));return(octint);}

[0][xX](([0-9a-fA-f]*\.[0-9a-fA-f]+[fFdD]?)|([0-9a-fA-f]+\.[0-9a-fA-f]*[fFdD]?))(((p|P)[\-\+]?[0-9]+[fFdD]?)) {if(!comment)yylval.fval=atof(strdup(yytext));return(hexfloat1);}

[0][xX]([0-9a-fA-f]+[fFdDlL]?) {if(!comment)yylval.ival=atoi(strdup(yytext));return(hexint);}

["\" \" \""]{ws}*{LT}([^\"]|(\"[^\"])|(\"\"[^\"]))*["\" \" \""]  {if(!comment)yylval.str=strdup(yytext);return(textblock);}

["]([^"\\\n]|\\(.|\n))*["] {if(!comment)yylval.str=strdup(yytext);return(string1);}

['][^']['] {if(!comment)yylval.str=strdup(yytext);return(charlit);}

\n    

[ \t]+

. {if(!comment)cout << "Error in line:" << yylineno << ",uncognized token:" << yytext << "\n";}
%%