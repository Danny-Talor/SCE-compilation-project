%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;
	node* mknode(char* token, node *left, node *right);
	void print_tree(node *tree);
	void print_tabs(int n);
	int yylex();
	int yyerror(char *e);
	
	int printlevel=0;
%}
%union
{
    struct node *node;
    char *string;
}



%token <string> COMMENT WHILE IF ELSE FOR 
%token <string> RETURN
%token <string> BOOL_TYPE STRING_TYPE CHARPTR_TYPE CHAR_TYPE INT_TYPE INTPTR_TYPE PROCEDURE
%token <string> AND ADDRESS EQ ASSIGN OR LENGTH GREATEREQ GREATER LESSEQ LESS NOTEQ NOT
%token <string> DIV ADD SUB MUL VAR
%token <string> STRING REAL CHAR NULL_T
%token <string> MAIN IDENTIFIER SEMICOLON COMMA OPAREN CPAREN OBRACK CBRACK OBRACE CBRACE
%token <string> DECIMAL HEX BOOLTRUE BOOLFALSE  REAL_TYPE REALPTR_TYPE FUNCTION COLON DEREFRENCE 

%left ADD SUB RETURN
%left MUL DIV
%left EQ NOTEQ LESS LESSEQ GREATEREQ GREATER OR AND
%left SEMICOLON 
%right NOT CBRACE

%nonassoc IDENTIFIER 
%nonassoc OPAREN
%nonassoc IF
%nonassoc ELSE 


%type <node> address_expr address_exprs stmnts stmnt_block derefrence_expr  expr_list call_func 
%type <node> expr lhs assmnt_stmnt new_block 
%type <node> stmnt type_pro type_id var_id declear paren_expr
%type <node> pro_body para_list para_pro procedure procedures
%type <node> main program project declears RET
%%
 //Main project
project: cmmnt program { Printtree($2); printf("syntax valid\n");};

program: procedures main {$$=mknode("CODE",$1,$2);}

 //comments
cmmnt: COMMENT cmmnt| ;

 //this is the main
main: PROCEDURE MAIN OPAREN CPAREN OBRACE pro_body CBRACE
{
$$=mknode("proc",
mknode("Main",mknode("\n",NULL,NULL),NULL),
mknode("ARGS",NULL,$6));
}	| {$$=NULL;};

//functions
procedures: procedures  procedure {$$=mknode("",$1,$2);}
	| {$$=NULL;};

//function
procedure: FUNCTION IDENTIFIER OPAREN para_pro CPAREN cmmnt RETURN type_pro  OBRACE  pro_body RET CBRACE
{ 
		$$=mknode("func",mknode($2,mknode("\n",NULL,NULL),mknode("ARGS",$4,mknode("return",$8,NULL))),mknode("",$10,$11));	
}
| PROCEDURE IDENTIFIER OPAREN para_pro CPAREN  OBRACE  pro_body CBRACE
{
	$$=mknode("proc",mknode($2,mknode("\n",NULL,NULL),NULL),mknode("ARGS",$4,$7));
};


//list of parameter for function or not
para_pro: para_list {$$=$1;}
| {$$=NULL;};

//list of parameter

para_list: var_id COLON type_id {$$=mknode("(",$3,mknode("",$1,mknode(")",NULL,NULL)));}
	|  para_list SEMICOLON cmmnt  para_list 
	{$$=mknode("",$1,mknode("",$4,NULL));}	;

 //Procedure body
pro_body: cmmnt  procedures declears stmnts 
{
	$$=mknode("(BODY\n    ", mknode("",$2,NULL),mknode("",$3,mknode("",$4,mknode("}",NULL,NULL))));
};


//list of declears
declears: declears declear  {$$=mknode("",$1,$2);} | {$$=NULL;}  ;

//declaration of varibals/ 
declear: VAR var_id COLON type_id cmmnt SEMICOLON cmmnt
{
	$$=mknode("var", $4,$2);
};

//list of id like a,b,c/
var_id: IDENTIFIER COMMA var_id {$$=mknode($1, mknode(" ", $3, NULL),NULL);}
	| IDENTIFIER {$$=mknode($1, NULL, NULL);} ;


//types without string/
type_id: BOOL_TYPE {$$=mknode("boolean", NULL, NULL);}
	| STRING_TYPE OBRACK DECIMAL CBRACK {$$=mknode("string", NULL, NULL);}
	| CHAR_TYPE {$$=mknode("char", NULL, NULL);}
	| INT_TYPE {$$=mknode("int", NULL, NULL);}
	| REAL_TYPE {$$=mknode("real", NULL, NULL);}
	| INTPTR_TYPE {$$=mknode("int*", NULL, NULL);}
	| CHARPTR_TYPE {$$=mknode("char*", NULL, NULL);}
	| REALPTR_TYPE {$$=mknode("real*", NULL, NULL);};



//type for returning from a function
type_pro: BOOL_TYPE {$$=mknode("boolean", NULL, NULL);}
 	| STRING_TYPE {$$=mknode("string", NULL, NULL);}
	| CHAR_TYPE {$$=mknode("char", NULL, NULL);}
	| INT_TYPE {$$=mknode("int", NULL, NULL);}
	| REAL_TYPE {$$=mknode("real", NULL, NULL);}
	| INTPTR_TYPE {$$=mknode("int*", NULL, NULL);}
	| CHARPTR_TYPE {$$=mknode("char*", NULL, NULL);}
	| REALPTR_TYPE {$$=mknode("real*", NULL, NULL);};
	

//Statments
stmnts: stmnts stmnt {$$=mknode("",$1,$2);} | {$$=NULL;};

//stmnt_block
stmnt_block: stmnt {$$=$1;}|RETURN expr SEMICOLON {$$=mknode("return",$2,NULL);};

//new block in stmnts
new_block: OBRACE cmmnt declears stmnts RET CBRACE cmmnt
{
	$$=mknode("{",$3,mknode("", $4, mknode("",$5,mknode("}",NULL,NULL))));
};


RET: RETURN expr SEMICOLON cmmnt {$$=mknode("return",$2,NULL);}| {$$=NULL;};

//Statment
stmnt: IF OPAREN expr CPAREN  stmnt_block 
{
	$$=mknode("if",
	mknode("(", $3, 
	mknode(")",NULL,NULL)),$5);
}%prec IF
| IF OPAREN expr CPAREN   stmnt_block    ELSE  stmnt_block  
{
	$$=mknode("if-else",
	mknode("(", $3, 
	mknode(")",NULL,NULL)),
	mknode("",$5,
	mknode("",$7,NULL)));
}
| WHILE cmmnt OPAREN expr CPAREN  stmnt_block  
{
	$$=mknode("while",
	mknode("(", $4, 
	mknode(")",NULL,NULL)),$6);
}
| FOR cmmnt OPAREN assmnt_stmnt SEMICOLON expr SEMICOLON assmnt_stmnt CPAREN stmnt_block 
{
		$$= mknode("for",
			mknode("(",
			mknode("",$4,$6),
			mknode("",$8,
			mknode(")",NULL,NULL))),$10);		
}
| assmnt_stmnt SEMICOLON cmmnt {$$=mknode("",$1,NULL);}
| expr SEMICOLON cmmnt {$$=$1;}
| new_block {$$=$1;};




//assiment statment
assmnt_stmnt: lhs ASSINGMENT expr 
{
	$$=mknode("=",$1,$3);
};


//lefd hand side id
lhs: IDENTIFIER OBRACK expr CBRACK 
{
	$$=mknode($1, mknode("[",$3,mknode("]",NULL,NULL)), NULL);
} 
| IDENTIFIER {$$=mknode($1,NULL,NULL);}
| derefrence_expr{$$=$1;} ;


	
//Expresion
expr:  OPAREN expr CPAREN {$$=mknode("(",$2,mknode(")",NULL,NULL));}|
//bool oper
    expr EQ expr {$$=mknode("==",$1,$3);}
	| expr NOTEQ expr {$$=mknode("!=",$1,$3);}
	| expr GREATEREQ expr {$$=mknode(">=",$1,$3);}
	| expr GREATER expr {$$=mknode(">",$1,$3);}
	| expr LESSEQ expr {$$=mknode("<=",$1,$3);}
	| expr LESS expr {$$=mknode("<",$1,$3);}
	| expr AND expr {$$=mknode("&&",$1,$3);}
	| expr OR expr {$$=mknode("||",$1,$3);}
//aritmetical operator
	| expr ADD expr {$$=mknode("+",$1,$3);}
	| expr SUB expr {$$=mknode("-",$1,$3);}
	| expr MUL expr {$$=mknode("*",$1,$3);}
	| expr DIV expr {$$=mknode("/",$1,$3);}
//not operator
	| NOT expr {$$=mknode("!",$2,NULL);}
	| address_exprs {$$=$1;}
	| derefrence_expr {$$=$1;}
	| call_func cmmnt {$$=$1;}
	| DECIMAL {$$=mknode($1,NULL,NULL);}
	| HEX {$$=mknode($1,NULL,NULL);}
	| CHAR {$$=mknode($1,NULL,NULL);}
	| REAL {$$=mknode($1,NULL,NULL);}
	| STRING {$$=mknode($1,NULL,NULL);}
	| BOOLFALSE {$$=mknode($1,NULL,NULL);}
	| BOOLTRUE {$$=mknode($1,NULL,NULL);}
	| LENGTH IDENTIFIER LENGTH 
	{
		$$=mknode("|",
		mknode($2,NULL,NULL),
		mknode("|",NULL,NULL));
	}
	| IDENTIFIER OBRACK expr CBRACK 
	{$$=mknode($1,mknode("[",$3,mknode("]",NULL,NULL)),NULL);}
	| IDENTIFIER {$$=mknode($1,NULL,NULL);}
	| NULL_T {$$=mknode("null",NULL,NULL);};

//address expression like &id

address_exprs:ADDRESS address_exprs {$$=mknode($1,$2,NULL);} | address_expr {$$=$1;};

address_expr: ADDRESS IDENTIFIER {$$=mknode("&",mknode($2,NULL,NULL),NULL);}
	| ADDRESS OPAREN IDENTIFIER CPAREN {$$=mknode("&",mknode("(",mknode($3,NULL,NULL),NULL),mknode(")",NULL,NULL));}
	| ADDRESS IDENTIFIER OBRACK expr CBRACK 
	{$$=mknode("&", mknode($2,NULL,NULL), mknode("[",$4,mknode("]",NULL,NULL)));}
	| ADDRESS OPAREN IDENTIFIER OBRACK expr CBRACK CPAREN 
	{
		$$=mknode("&",
		mknode("(", 
		mknode($3,NULL,NULL),
		mknode("[",$5,NULL)), 
		mknode("]",NULL,mknode(")",NULL,NULL)));
	};
//value expression like ^id


	derefrence_expr: DEREFRENCE IDENTIFIER {$$=mknode("^",mknode($2,NULL,NULL),NULL);}
	| DEREFRENCE OPAREN expr CPAREN {$$=mknode("^",mknode("(",$3,NULL),mknode(")",NULL,NULL));}
	| DEREFRENCE IDENTIFIER OBRACK expr CBRACK 
	{$$=mknode($1, mknode($2,NULL,NULL), mknode("[",$4,mknode("]",NULL,NULL)));};

	//list of expreession
expr_list: expr COMMA expr_list {$$=mknode("",$1,mknode(",",$3,NULL));} 
	| expr {$$=mknode("",$1,NULL);}
	| {$$=NULL;};

paren_expr:OPAREN expr_list CPAREN {$$=$2;};
//call func rul 
call_func: IDENTIFIER paren_expr {$$=mknode("Call func",mknode($1,NULL,NULL),mknode("ARGS",$2,NULL));} ;
%%



int main()
{
	return yyparse();	
}

/* allocation for node*/
node* mknode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	return newnode;
}

void printTabs(int n)
{
	int i;
	for(i=0;i<n/3;i++)
		printf(" ");
}
void Printtree(node* tree)
{
	int flag = 4;
	printTabs(printlevel); 
	if(strcmp(tree->token, "var") == 0)
	{
		
		printf("(DECLARE ");
		flag=2;
		
		
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		printf("(IF\n");
		flag = 1;
		
		
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		printf("(WHILE\n");
		flag = 1;
		
		
	}
			else if(strcmp(tree->token, "for") == 0)
	{
		printf("(FOR\n");
		flag = 1;
		
		
	}
		else if(strcmp(tree->token, "func") == 0 ||strcmp(tree->token, "proc") == 0 ||strcmp(tree->token, "CODE") == 0||strcmp(tree->token, "Call func") == 0)
	{
		printf("(%s \n",tree->token);
		flag= 2;
		
	}
		else if(strcmp(tree->token, "ARGS") == 0)
	{
		printf("(ARGS ");
		if(tree->left)
		{
			flag = 2;
			printf("\n");
			
		}
		else{
			printf(" NONE)\n"); 
		}
	

	}
		else if(strcmp(tree->token, "if-else") == 0)
	{
		printf("(IF-ELSE\n");
		printlevel--;
		
		flag = 1;
	}
			else if(strcmp(tree->token, "return") == 0)
	{
		printf("(RET ");
		flag = 2;
	}
	else if(strcmp(tree->token, "{") == 0)
	{
                printf("(BLOCK\n");
				
				
	}
	else if(strcmp(tree->token, "}") == 0)
	{
		printf(")\n");
	}
	else if(strcmp(tree->token, "") == 0);
	else if(strcmp(tree->token, "(") == 0)
			printf("(");
	else if(strcmp(tree->token, "\n") == 0)
			printf("\n");
	else if(strcmp(tree->token, ")") == 0)
			printf(")\n");
	else if(strcmp(tree->token, ",") == 0)
			printf(",");
	else if(strcmp(tree->token, ";") == 0)
			printf("\n");
	else if(strcmp(tree->token, "&&") == 0 ||
strcmp(tree->token, "/") == 0 || 
strcmp(tree->token, "=") == 0 || 
strcmp(tree->token, "==") == 0 || 
strcmp(tree->token, ">") == 0 || 
strcmp(tree->token, ">=") == 0 || 
strcmp(tree->token, "<") == 0 || 
strcmp(tree->token, "<=") == 0 || 
strcmp(tree->token, "-") == 0 || 
strcmp(tree->token, "!") == 0 || 
strcmp(tree->token, "!=") == 0 || 
strcmp(tree->token, "||") == 0 || 
strcmp(tree->token, "+") == 0 || 
strcmp(tree->token, "*") == 0 || 
strcmp(tree->token, "&") == 0 || 
strcmp(tree->token, "^") == 0 || 
strcmp(tree->token, "|") == 0 || 
strcmp(tree->token, ",") == 0 )
	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else
	{
		if(tree && (!tree->left && !tree->right)
		||strcmp(tree->token, "Main") == 0)
		{
			printf("%s ", tree->token);
			
		}
		else
		{
			printlevel++;
			printf("%s", tree->token);
			printlevel--;
		
		}
	}
	if (tree->left) 
	{
		printlevel++;
		Printtree(tree->left);
		printlevel--;
	}
	
	if (tree->right)
	{
		printlevel++;
		Printtree(tree->right);
		printlevel--;
		
	}
	if(flag == 2)
		printf(")\n");
	
	if(flag == 1)
		printf(")");
	if(flag == 0)
		printf("\n)");
}
int yyerror(char *e)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "does not accept '%s'\n",yytext);
	
	return 0;
}