%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}
%x COMMENT
%%

    /* Keywords Lexemes */
bool        return BOOL;
char        return CHAR;
int         return INT;
real        return REAL;
string      return STRING;
"int*"      return INTP;
"char*"     return CHARP;
"real*"     return REALP;
if 			{ yylval.string = strdup(yytext); return IF; };
else 		{ yylval.string = strdup(yytext); return ELSE; };
while 		{ yylval.string = strdup(yytext); return WHILE; };
for 		{ yylval.string = strdup(yytext); return FOR;};
var         return VAR;
"arg->"     return FUNCARGS;
function    return FUNC;
return 		{ yylval.string = strdup(yytext); return RETURN; };
null 		{ yylval.string = strdup(yytext); return NULLP; };
void        return VOID;
do 			{ yylval.string = strdup(yytext); return DO; };
main        return MAIN;

    /* Operator Lexemes */
"&&" 		{ yylval.string = strdup("AND"); return AND; };
"/" 		{ yylval.string = strdup(yytext); return DIV; };
"="	        { yylval.string = strdup(yytext); return ASSIGN; };
"==" 		{ yylval.string = strdup(yytext); return EQ; };
">"			{ yylval.string = strdup(yytext); return GT; };
">=" 		{ yylval.string = strdup(yytext); return GTE; };
"<"			{ yylval.string = strdup(yytext); return LT; };
"<=" 		{ yylval.string = strdup(yytext); return LTE; };
"-" 		{ yylval.string = strdup(yytext); return SUB; };
"!"			{ yylval.string = strdup(yytext); return NOT; }
"!="		{ yylval.string = strdup(yytext); return NEQ; };
"||" 		{ yylval.string = strdup("OR"); return OR; };
"+" 		{ yylval.string = strdup(yytext); return ADD; };
"*"			{ yylval.string = strdup(yytext); return MUL; };
"&" 		{ yylval.string = strdup(yytext); return ADDRESS; }

    /* Literal Lexemes */
[a-zA-Z][a-zA-Z0-9_]*	    { yylval.string = strdup(yytext); return ID; };
"*"[a-zA-Z][a-zA-Z0-9_]*    { yylval.string = strdup(yytext); return DER_ID; };
true				        { yylval.string = strdup(yytext); return TRUE_VAL; };
false 	     		        { yylval.string = strdup(yytext); return FALSE_VAL; };
0|[1-9][0-9]*               { yylval.string = strdup(yytext); return DEC_INT; };
0[xX][A-F0-9]+ 		        { yylval.string = strdup(yytext); return HEX_INT; };
\'[^\']\'			        { yylval.string = strdup(yytext); return CHAR_VAL; };
\"[^\"]*\"			        { yylval.string = strdup(yytext); return STRING_VAL; };
[0-9]*[\.]?[0-9]+|[-+]?[0-9]*[\.]?[0-9]?+[eE][-+]?[0-9]+	{ yylval.string = strdup(yytext); return REAL_VAL; };

    /* Other Lexemes */
";"         return ';'; 
","         {yylval.string = strdup(","); return ','; };
"|"         return '|'; 
"{"         return '{'; 
"}"         return '}'; 
"("         return '('; 
")"         return ')'; 
"["         return '['; 
"]"         return ']'; 
":"         {yylval.string = strdup(":"); return ':'; };

    /* Comments */
"/*"([^*]|(\*+[^*/]))*"*/"   /* Ignore multiline comments */
"//".*                      /* Ignore single-line comments */

    /* Misc */
" " ;
[\n] yylineno++;
[ \t] ;
. 		return yytext[0]; 
%%
