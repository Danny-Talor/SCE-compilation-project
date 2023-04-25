%{
#include <stdio.h>
#include "parser.tab.h" // include the Bison/Yacc generated header file
%}
%%

  /*Literal Lexemes*/
true {return BOOLTRUE;}
false {return BOOLFALSE;}
[a-zA-Z][a-zA-Z0-9_]* { yylval.string= strdup(yytext);return IDENTIFIER;}
"\""[^"]*"\"" {yylval.string= strdup(yytext);return STRING_LTL;}
\'.\' {yylval.string= strdup(yytext);return CHAR_LTL;}
[+-]?[1-9][0-9]*|[0-9] {yylval.string= strdup(yytext);return DECIMAL_LTL;}
0(x|X)[0-9A-F]+ {yylval.string= strdup(yytext);return HEX_LTL;}
[-+]?[0-9]*\.?[0-9]*[eE]?[-+]?[0-9]+ {yylval.string= strdup(yytext);return REAL_LTL;}
[ \n\t]   { /* skip whitespace */}
. return yytext[0];

    /*Keywords Lexemes*/
bool {return BOOL_TYPE;}
char {return CHAR_TYPE;}
int {return INT_TYPE;}
real {return REAL_TYPE;}
string {return STRING_TYPE;}
int\* {return INTPTR_TYPE;}
char\* {return CHARPTR_TYPE;}
real\* {return REALPTR_TYPE;}
if {return IF;}
else {return ELSE;}
while {return WHILE;}
for {return FOR;}
var {return VAR;}
arg-> {return FUNC_ARGS;}
function {return FUNCTION;}
return {return RETURN;}
null {return NULL_T;}
void {return VOID;}
do {return DO;}
main {return MAIN;}
 
  /*Operator Lexemes*/
"&&" {return AND;}
"/" {return DIV;}
"=" {return ASSIGN;}
"==" {return EQ;}
">" {return GREATER;}
">=" {return GREATEREQ;}
"<" {return LESS;}
"<=" {return LESSEQ;}
"-" {return SUB;}
"!" {return NOT;}
"!=" {return NEQ;}
"||" {return OR;}
"+" {return ADD;}
"*" {return MUL;}
"&" {return ADDRESS;}

  /*Other Lexemes*/
";" {return SEMICOLON;}
"," {return COMMA;}
"|" {return LENGTH;}
"{" {return OBRACK;}
"}" {return CBRACK;}
"(" {return OPAREN;}
")" {return CPAREN;}
"[" {return OCROT;}
"]" {return CCROT;}

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]  { return COMMENT;}

%%