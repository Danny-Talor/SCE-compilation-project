%{
#include <stdio.h>
#include <stdlib.h>
%}
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
null 		{ yylval.string = strdup(yytext); return NONE; };
void        return VOID;
do 			{ yylval.string = strdup(yytext); return DO; };


/* Operator Lexemes */
"&&" 		{ yylval.string = strdup("AND"); return OP_AND; };
"/" 		{ yylval.string = strdup(yytext); return DIV; };
"="	        { yylval.string = strdup(yytext); return ASSIGN; };
"==" 		{ yylval.string = strdup(yytext); return OP_EQ; };
">"			{ yylval.string = strdup(yytext); return OP_GT; };
">=" 		{ yylval.string = strdup(yytext); return OP_GE; };
"<"			{ yylval.string = strdup(yytext); return OP_LT; };
"<=" 		{ yylval.string = strdup(yytext); return OP_LE; };
"-" 		{ yylval.string = strdup(yytext); return MINUS; };
"!"			{ yylval.string = strdup(yytext); return NOT; }
"!="		{ yylval.string = strdup(yytext); return OP_NOT_EQ; };
"||" 		{ yylval.string = strdup("OR"); return OP_OR; };
"+" 		{ yylval.string = strdup(yytext); return PLUS; };
"*"			{ yylval.string = strdup(yytext); return MULT; };
"&" 		{ yylval.string = strdup(yytext); return ADDRESS; }

/* Literal Lexemes */
true				        { yylval.string = strdup(yytext); return TRUE_VAL; };
false 	     		        { yylval.string = strdup(yytext); return FALSE_VAL; };
[a-zA-Z][a-zA-Z0-9_]*	    { yylval.string = strdup(yytext); return ID; };
0|[1-9][0-9]*               { yylval.string = strdup(yytext); return DECIMAL_INT_NUMBER; };
0[xX][A-F0-9]+ 		        { yylval.string = strdup(yytext); return HEX_INT_NUMBER; };
\'[^\']\'			        { yylval.string = strdup(yytext); return CHAR_VAL; };
\"[^\"]*\"			        { yylval.string = strdup(yytext); return STRING_VAL; };
[0-9]*[\.]?[0-9]+|[-+]?[0-9]*[\.]?[0-9]?+[eE][-+]?[0-9]+	{ yylval.string = strdup(yytext); return REAL_NUMBER; };
" " ;
"*"[a-zA-Z][a-zA-Z0-9_]*    { yylval.string = strdup(yytext); return DER_ID; };

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
"/""%".*"%""/"              return COMMENT;

[\n] yylineno++;
[ \t] ;
. 		return yytext[0]; 
%%
