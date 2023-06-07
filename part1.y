%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define false 0
#define true 1

typedef struct node {
	char *token; 
	struct node *left;
	struct node *right;
} node;

typedef struct Arguments
	{
		char * name;
		char * type;
		char * len;
	}Arguments;
    typedef struct Function 
	{
        char * name;
		struct Arguments * args;
        char *returnType; 
		int countArgs;
		int findreturn;
    } Function;
	
	typedef struct Varaiables
	{	int isArg;
		char *name;
		char *value;
		char *type;
		char * len;
	}Varaiable;
		typedef struct code
	{	
		int place;
		char *name;
		Varaiable * var;
		int countvar;
		int countfunc;
		Function ** func;
		struct code * nextLVL;
		struct code * beforeLVL;
	}code;
	char * exprtype(node *,code*);
	Arguments * mkArgs(node *,int *);
	void addFunc(char * name,Arguments * args,node *returnType,int countArgs,code*);
	void addvar(Arguments * args,int,int,code * CODEscope);
	code* mkcode(char *);
node *makeNode(char *token, node *left, node *right);
void printTree(node *tree, int tab);
void printTabs(int numOfTabs);
int yyerror(char *err);
int yylex();
void push(code* from,char*);
	int printlevel=-1;
	code* mycode=NULL;
	code* lestcode(code * codey);
	static int scope=0;
	void syntaxMKscope(node *tree,code * scope);
	char* findfunc(node * tree,code * CODEscope);
	char *findvar(node * tree,code * CODEscope);
	Arguments * callfuncargs(code *,node *tree,int * count);
	int flagMain=false;
%}

%union
{
    char *string;
    struct node *node;
}

%token <string> BOOL
%token <string> CHAR
%token <string> INT
%token <string> REAL
%token <string> STRING
%token <string> INTP
%token <string> CHARP
%token <string> REALP
%token <string> IF
%token <string> ELSE
%token <string> WHILE
%token <string> FOR
%token <string> VAR
%token <string> FUNCARGS
%token <string> FUNC
%token <string> RETURN
%token <string> NULLP
%token <string> VOID
%token <string> DO
%token <string> MAIN
%token <string> AND
%token <string> DIV
%token <string> ASSIGN
%token <string> EQ
%token <string> GT
%token <string> GTE
%token <string> LT
%token <string> LTE
%token <string> SUB
%token <string> NOT
%token <string> NEQ
%token <string> OR
%token <string> ADD
%token <string> MUL
%token <string> ADDRESS
%token <string> ID
%token <string> DER_ID
%token <string> TRUE_VAL
%token <string> FALSE_VAL
%token <string> DEC_INT
%token <string> HEX_INT
%token <string> CHAR_VAL
%token <string> STRING_VAL
%token <string> REAL_VAL

%type <string> type
%type <string> primitive_value
%type <string> unary_op

%type <node> start
%type <node> initial
%type <node> code
%type <node> main
%type <node> function
%type <node> procedure
%type <node> args_Id
%type <node> args
%type <node> body
%type <node> update
%type <node> declaration
%type <node> statement
%type <node> string_type
%type <node> string_Id
%type <node> address_of
%type <node> body_proc
%type <node> expression
%type <node> element_of_expression
%type <node> assignment
%type <node> multi_assign
%type <node> func_arguments
%type <node> if_statement
%type <node> block
%type <node> nested_statement
%type <node> for_statement
%type <node> while_statement
%type <node> return_statement
%type <node> do_statement
%type <node> long_declaration
%type <node> proc_statement
%type <node> proc_if_statement
%type <node> proc_while_statement
%type <node> func_statement
%type <node> proc_do_statement
%type <node> proc_for_statement
%type <node> block_proc
%type <node> proc_nested_statement
%type <node> call_func

%right UNARY
%left OR
%left AND
%left EQ
%left GT
%left GTE
%left LTE
%left LT
%left ADD
%left SUB
%left MUL
%left DIV
%left NEQ
%left FUNCARGS
%%

start: initial { syntaxMKscope($1,mycode); };

initial: code { $$ = makeNode("CODE", $1, NULL);};

code: function code { $$ = makeNode("FUNCTION ",$1, $2); } 
    | function { $$ = makeNode("FUNCTION ",$1, NULL); } 
    | procedure code{ $$ = makeNode("PROC ",$1, $2); } 
    | procedure { $$ = makeNode("PROC ",$1, NULL); };
	| main { $$ = makeNode("Main ",$1, NULL); };
	| {$$=NULL;};

main: FUNC MAIN '(' ')' ':' VOID '{'body_proc '}'  {$$ = makeNode("ARGS NONE",NULL, makeNode("TYPE VOID", NULL,$8)); };

function: FUNC ID '(' args ')' ':' type '{' body '}' {$$ = makeNode($2, NULL, makeNode("ARGS", $4, makeNode($7, NULL, $9))); };

procedure: FUNC ID '(' args ')' ':' VOID '{' body_proc '}' {$$ = makeNode($2,NULL, makeNode("ARGS", $4,makeNode("TYPE VOID", NULL,$9))); };

args: args_Id ':' type { $$ = makeNode($3, $1, NULL); }
    | args ',' args_Id type { $$ = makeNode($4, $3, $1); }
    | FUNCARGS args_Id type { $$ = makeNode($3, $2, NULL); $$->left = makeNode("", NULL, $2); }
    | FUNCARGS args_Id type ';' args { $$ = makeNode($3, $2, $5); $$->left = makeNode("", NULL, $2); }
    | { $$ = NULL; };

args_Id: ID { $$ = makeNode($1, NULL, NULL); } 
       | ID ':' { $$ = makeNode($1, NULL,NULL); }
       | ID ',' args_Id { $$ = makeNode($1, NULL, $3); }
       | FUNCARGS ID { $$ = makeNode($2, NULL, NULL); }
       | FUNCARGS ID ',' args_Id { $$ = makeNode($2, NULL, $4); }
       | FUNCARGS ID ':' { $$ = makeNode($2, NULL, NULL); $$->left = makeNode($2, NULL, NULL); }
       | { $$ = NULL; };

string_Id: ID '[' expression ']' { $$ = makeNode($1, makeNode("[]", NULL,$3), NULL); }
         | assignment ':'{ $$ = $1; }
         | assignment ',' string_Id { $1->right = $3;  $$ = $1; }
         | FUNCARGS ID '[' expression ']'  ',' string_Id { $$ = makeNode($2, makeNode("[]", NULL,$4), $7); }
         | FUNCARGS ID '[' expression ']' ':' {$$ = makeNode($2, makeNode("[]", NULL,$4), NULL); };
  
type: BOOL { $$ = "BOOL"; } 
    | CHAR { $$ = "CHAR"; } 
    | INT { $$ = "INT"; } 
    | REAL { $$ = "REAL"; } 
    | INTP { $$ = "INT_PTR"; } 
    | CHARP { $$ = "CHAR_PTR"; } 
    | REALP { $$ = "REAL_PTR"; };

string_type: STRING string_Id { $$ =$2; };

body: declaration nested_statement return_statement { $$ = makeNode("BODY", makeNode("", $1, $2),$3); }
    | declaration return_statement {$$ = makeNode("BODY",$1, $2); }
    | nested_statement return_statement { $$ = makeNode("BODY", $1 ,$2); }
    | nested_statement { $$ = makeNode("BODY", $1 ,NULL); };

body_proc: declaration proc_nested_statement { $$ = makeNode("BODY", makeNode("", $1, $2),NULL); }
         | declaration {$$ = makeNode("BODY",$1, NULL); }
         | proc_nested_statement { $$ = makeNode("BODY", $1 ,NULL); };

declaration: function declaration { $$ = makeNode("FUNCTION  ", $1, $2); }
           | string_type declaration {$$ = makeNode("STRING",$1,$2);}
           | VAR long_declaration ':' type ';' declaration { $$ = makeNode($4,$2,$6);}
           | { $$ = NULL; };

long_declaration: assignment ',' long_declaration {$1->right=$3;$$=$1;}
                | ID ',' long_declaration {$$ = makeNode($1,NULL,$3);}
                | assignment  {$$=$1;}
                | ID  { $$ = makeNode($1, NULL, NULL); } 
                | { $$ = NULL; };             

nested_statement: statement { $$ = $1; }
                | statement nested_statement { $1->right = $2; $$ = $1; };

proc_nested_statement: proc_statement { $$ = $1; }
                     | proc_statement proc_nested_statement { $1->right = $2; $$ = $1; };

proc_statement: assignment ';' {$$ = $1;}
              | func_statement {$$=$1;}
              | proc_if_statement {$$=$1;}
              | proc_while_statement { $$ = $1;}
              | proc_do_statement { $$ = $1;}
              | block_proc {$$ = $1;}
              | proc_for_statement {$$ = $1;};

statement: assignment ';' {$$ = $1;}
         | func_statement {$$=$1;}
         | if_statement {$$=$1;}
         | while_statement { $$ = $1;}
         | do_statement { $$ = $1;}
         | block {$$ = $1;}
         | for_statement {$$ = $1;}
         | return_statement {$$ = $1;};

func_statement: ID ASSIGN ID '(' func_arguments ')' ';' { $$ = makeNode($2,makeNode($1,NULL,makeNode($3,$5,NULL)),NULL); }
              | ID '(' func_arguments ')' {$$ = makeNode($1,$3,NULL);}
              | ID '(' func_arguments ')' ';' {$$ = makeNode($1,$3,NULL);}
              | ID '(' func_arguments ')' ADD func_statement {$$ = makeNode($1,$3,$6);};

func_arguments: { $$ = NULL; }
              | expression ',' func_arguments {$1->right=$3;$$=$1;}
              | expression{ $$ = $1; } ;

assignment: ID ASSIGN expression { $$ = makeNode($2,makeNode($1,NULL, $3), NULL);}
          | ADDRESS ID ASSIGN expression { $$ = makeNode($1,makeNode($3,makeNode($2,NULL, $4), NULL), NULL);}
          | ID ASSIGN STRING_VAL {$$ = makeNode($2, makeNode($1, makeNode($3,NULL, NULL), NULL), NULL);}
          | ID '[' expression ']' ASSIGN STRING_VAL {$$ = makeNode($5, makeNode($1, makeNode("[]",NULL,$3),NULL),makeNode($6,NULL,NULL));}
          | ID ASSIGN ID '[' expression ']' {$$ = makeNode($2, makeNode($1,NULL,makeNode($3,makeNode("[]",NULL,$5),NULL)),NULL);}
          | ID '[' expression ']' ASSIGN CHAR_VAL {$$ = makeNode($5, makeNode($1, makeNode("[]",NULL,$3),NULL),makeNode($6,NULL,NULL));}
          | ID '[' expression ']' ASSIGN ID {$$ = makeNode($5, makeNode($1, makeNode("[]",NULL,$3),NULL),makeNode($6,NULL,NULL));};

multi_assign: assignment { $$ = $1; }
            | assignment ',' multi_assign { $$ = makeNode("", $1, $3); }
            | { $$ = NULL; };

if_statement: IF '(' expression ')' statement { $$ = makeNode("IF",$3,$5);}
            | IF '(' expression ')' statement ELSE statement { $$ = makeNode("IF-ELSE", makeNode("", $3, makeNode("", $5,$7)), NULL); };

proc_if_statement: IF '(' expression ')' proc_statement { $$ = makeNode("IF",$3,$5);}
                 | IF '(' expression ')' proc_statement ELSE proc_statement { $$ = makeNode("IF-ELSE", makeNode("", $3, makeNode("", $5,$7)), NULL); };

while_statement: WHILE '(' expression ')' statement { $$ = makeNode($1, $3, $5); };

proc_while_statement: WHILE '(' expression ')' proc_statement { $$ = makeNode($1, $3, $5); };

do_statement: DO block WHILE '(' expression ')' ';' { $$ = makeNode($1, makeNode("", $2,NULL), makeNode($3, $5, NULL)); };

proc_do_statement: DO block_proc WHILE '(' expression ')' ';' { $$ = makeNode($1, makeNode("", $2,NULL), makeNode($3, $5, NULL)); };

for_statement: FOR '(' assignment ';' expression ';' update ')' statement { $$ = makeNode($1, makeNode("INITS", $3, makeNode("EXPR", $5, makeNode("UPDATE", $7, $9))), NULL); };

proc_for_statement: FOR '(' assignment ';' expression ';' update ')' proc_statement { $$ = makeNode($1, makeNode("INITS", $3, makeNode("EXPR", $5, makeNode("UPDATE", $7, $9))), NULL); };

block: '{' '}' {$$ = makeNode("BLOCK",NULL, NULL);}
     | '{' declaration nested_statement return_statement '}' { $$ = makeNode("BLOCK", makeNode("", $2, $3),$4); };
     | '{' declaration return_statement '}' { $$ = makeNode("BLOCK", $2, $3); };
     | '{' nested_statement return_statement '}' { $$ = makeNode("BLOCK", $2, $3); };
     | '{' declaration proc_nested_statement '}' { $$ = makeNode("BLOCK", makeNode("", $2, $3),NULL);}
     | '{' declaration '}' {$$ = makeNode("BLOCK",$2, NULL); }
     | '{' proc_nested_statement '}' { $$ = makeNode("BLOCK", $2 ,NULL); };

block_proc: '{' '}' {$$ = makeNode("BLOCK",NULL, NULL);}
          | '{' declaration proc_nested_statement '}' { $$ = makeNode("BLOCK", makeNode("", $2, $3),NULL);}
          | '{' declaration '}' {$$ = makeNode("BLOCK",$2, NULL); }
          | '{' proc_nested_statement '}' { $$ = makeNode("BLOCK", $2 ,NULL); };

expression: element_of_expression {$$ = $1;}
          | '(' expression ')' {$$ = makeNode("",$2, NULL);}
	      | expression EQ expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
          | MUL '(' expression ')' {$$ = makeNode("*",$3, NULL);}
	      | expression AND expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
	      | expression OR expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
	      | expression GT expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
	      | expression GTE expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
	      | expression LTE expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
	      | expression LT expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
          | expression NEQ expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
          | expression ADD expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);}
          | expression SUB expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
          | expression MUL expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
          | unary_op expression %prec UNARY { $$ = makeNode($1, $2, NULL); }
          | expression DIV expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);}
          | address_of { $$ = $1; };

element_of_expression: primitive_value {$$ = makeNode($1,NULL, NULL); }
                     |   '|' ID '|' { $$ = makeNode("STR_LEN", makeNode($2, NULL, NULL), NULL); }
                     | func_statement { $$ = $1; }
                     | ID { $$ = makeNode($1,NULL, NULL); };

primitive_value: CHAR_VAL { $$ = $1; }
               | HEX_INT  { $$ = $1; }
               | DEC_INT  {$$ = $1; }
               | REAL_VAL { $$ = $1; }
               | TRUE_VAL { $$ = $1;}
               | NULLP { $$ = $1; }
               | DER_ID { $$ = $1; }
               | FALSE_VAL { $$ = $1;};

address_of: ADDRESS ID { $$ = makeNode($1, makeNode($2, NULL, NULL), NULL); }
          | ADDRESS ID '[' expression ']' { $$ = makeNode($1, makeNode($2, makeNode("[]", $4, NULL), NULL), NULL); };

return_statement: RETURN expression ';'{ $$ = makeNode("RET", $2, NULL); }
                | RETURN func_statement { $$ = makeNode("RET", $2, NULL); };

update: ID ADD ADD { $$ = makeNode("++", makeNode($1, NULL, NULL), NULL); }
      | ID SUB SUB { $$ = makeNode("--", makeNode($1, NULL, NULL), NULL); }
      | multi_assign { $$ = $1; };

unary_op: ADD { $$ = $1; }
        | SUB { $$ = $1; }
        | NOT {$$ = $1;};

call_func: ID '(' func_arguments ')' ';' {$$=makeNode("Call func",makeNode($1,NULL,NULL),makeNode("ARGS",$3,NULL));} ;

%%
#include "lex.yy.c"
int main()
{
    int x= yyparse();
	if(x==0)
	{
	printf("syntax valid\n"); 
	printf("Semantics valid\n");
	}
	return x;
}

Arguments * callfuncargs(code * CODEscope,node *tree,int * count)
{
	Arguments  *arr=NULL,ar[50];
	char* type,*len;
	while(tree!=NULL)
	{
		ar[(*count)++].type=exprtype(tree->left,CODEscope);
		//printf("%d %s, ",*count,tree->left->token);
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;

	}
	arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
	for(int i=0;i<*count;i++)
		arr[i].type=ar[i].type;
	return arr;
}
char* findfunc(node * tree,code * CODEscope)
{
	code*temp=CODEscope;
	Arguments* args;
	int find=false,flag=true;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->countfunc;i++)
		if(strcmp(tree->left->token,temp->func[i]->name)==0)
		{
			find=true;
			flag=true;
			int count=0;
			args=callfuncargs(CODEscope,tree->right->left,&count);
			//printf("%d %d ",count,temp->func[i]->countArgs);
			if(count==temp->func[i]->countArgs)
			{
				for(int j=0;j<count;j++)
				{
					//printf("%s %s",args[j].type,temp->func[i]->args->type);
					if(strcmp(args[j].type,temp->func[i]->args->type)!=0)
						flag=false;
				}
				if(flag==true)
					return temp->func[i]->returnType;
			}
		}
		temp=temp->beforeLVL;
	}
	printf("ERORR,func %s not find call in scope %s in func/proc %s\n",tree->left->token,CODEscope->name,mycode->func[mycode->countfunc-1]->name);
	if(find==true)
		printf("but find func with some name but other args\n");
		exit(1);
}
char *findvar(node * tree,code * CODEscope)
{
	code*temp=CODEscope;
	if(strcmp(tree->token,"solovar")==0)
		tree=tree->left;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->countvar;i++)
		if(strcmp(tree->token,temp->var[i].name)==0)
		{
			
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(temp->var[i].type,"string")==0)
					if(strcmp(exprtype(tree->left->left,CODEscope),"int")==0)
					{
						return "char";
					}
					else
					{
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in func/proc %s\n",CODEscope->name,mycode->func[mycode->countfunc-1]->name);
						exit(1);
					}
				else
				{
					printf("ERORR,you can use index only on string type (<string>[<int>]) in scope %s in func/proc %s\n",CODEscope->name,mycode->func[mycode->countfunc-1]->name);
					exit(1);
				}

			}
			else
			return temp->var[i].type;

		}
		temp=temp->beforeLVL;
	}
	printf("ERORR,var %s not find in scope %s in func/proc %s\n ",tree->token,CODEscope->name,mycode->func[mycode->countfunc-1]->name);
	exit(1);
	
}
char * exprtype(node * tree,code* CODEscope){
	char* msg=(char*)malloc(sizeof(char)*7);
	msg="";
	if(strcmp(tree->token,"null")==0)
		msg="NULL";
	else
	if(tree->left!=NULL){
		if(strcmp(tree->left->token,"INT")==0)
			msg= "int";
		if(strcmp(tree->left->token,"HEX")==0)
			msg= "hex";
		if(strcmp(tree->left->token,"CHAR")==0)
			msg= "char";
		if(strcmp(tree->left->token,"REAL")==0)
			msg= "real";
		if(strcmp(tree->left->token,"STRING")==0)
			msg= "string";
		if(strcmp(tree->left->token,"BOOLEAN")==0)
			msg= "boolean";
		if(strcmp(tree->token,"!")==0)
		if(strcmp(exprtype(tree->left,CODEscope),"boolean")==0)
			msg="boolean";
		else{
			printf("Erorr op ! you can use only on boolean type");
			exit(1);
		}
		if(strcmp(tree->token,"|")==0)
		if(strcmp(exprtype(tree->left,CODEscope),"string")==0)
		msg="int";
		else{
			printf("Erorr op | you can use only on string type in func/proc %s",mycode->func[mycode->countfunc-1]->name);
			exit(1);
		}
		if(strcmp(tree->token,"==")==0||strcmp(tree->token,"!=")==0)
		{
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->right,CODEscope),"string")!=0)
			msg="boolean";
			else{
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}

		if(strcmp(tree->token,">=")==0||strcmp(tree->token,">")==0||strcmp(tree->token,"<=")==0||strcmp(tree->token,"<")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
			msg="boolean";
			else{
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}

		if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0)
		{

			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->right,CODEscope),"boolean")==0)
			msg="boolean";
			else{
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
			

		}
		if(strcmp(tree->token,"-")==0||strcmp(tree->token,"+")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
			{
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->left,CODEscope),"int")==0)
			msg="int";
			else
			msg="real";
			}

			if(strcmp(exprtype(tree->right,CODEscope),"int")==0&&(strcmp(exprtype(tree->left,CODEscope),"char*")==0||strcmp(exprtype(tree->right,CODEscope),"int*")==0||strcmp(exprtype(tree->right,CODEscope),"real*")==0)){
				msg=exprtype(tree->left,CODEscope);
			}
			else if(strcmp(msg,"")==0)
			{
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}

		}
		if(strcmp(tree->token,"*")==0||strcmp(tree->token,"/")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
			{
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->left,CODEscope),"int")==0)
			msg="int";
			else
			msg="real";
			}
			else
			{
				printf("ERORR, you cant do %s between %s and %s\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope));
				exit(1);
			}
		}
		if(strcmp(tree->token,"&")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=exprtype(tree->left->left,CODEscope);
			else{
				msg=exprtype(tree->left,CODEscope);
				
				}
			if(strcmp(msg,"char")==0)
			msg="char*";
			else
			if(strcmp(msg,"int")==0)
			msg="int*";
			else
			if(strcmp(msg,"real")==0)
			msg="real*";
			else
			{
				printf("ERORR, you cant do %s on %s \n",tree->token,msg);
				exit(1);
			}
		}
		if(strcmp(tree->token,"^")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=exprtype(tree->left->left,CODEscope);
			else
				msg=exprtype(tree->left,CODEscope);
			
			if(strcmp(msg,"char*")==0)
			msg="char";
			else
			if(strcmp(msg,"int*")==0)
			msg="int";
			else
			if(strcmp(msg,"real*")==0)
			msg="real";
			else
			{
				printf("ERORR, you cant do %s on %s \n",tree->token,msg);
				exit(1);
			}

		}
		if(strcmp(tree->token,"(")==0)
			msg=exprtype(tree->left,CODEscope);
		if(strcmp(tree->token,"Call func")==0)
			msg=findfunc(tree,CODEscope);
		
	}
	if(strcmp(msg,"")==0)
		msg=findvar(tree,CODEscope);

	
	

	return msg;
}
void push(code* from,char* name)
{
	code * point;
	if(mycode==NULL)
		mycode=mkcode(name);
	else{
	point=mycode;
	while(point->nextLVL!=NULL)
		point=point->nextLVL;
	point->nextLVL=mkcode(name);
	point->nextLVL->beforeLVL=from;
	}
}
code* mkcode(char* name)
{	
	code *newlvl = (code*)malloc(sizeof(code));
	newlvl->place=++scope;
	newlvl->name=name;
	newlvl->var=NULL;
	newlvl->countvar=0;
	newlvl->func=NULL;
	newlvl->countfunc=0;
	newlvl->nextLVL=NULL;
	newlvl->beforeLVL=NULL;
	return newlvl;
}

void addvar(Arguments * args,int countvars,int isArg,code * CODEscope){
	if(countvars==0)
	return;
	Varaiable* temp;
	code * codey=CODEscope;

	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
	if(i!=j && strcmp(args[j].name,args[i].name)==0 )
	{
		printf("sorry you can't some vars %s in one declear",args[i].name);
		code * t=codey->beforeLVL;
		while(t->beforeLVL!=NULL && t->beforeLVL->countfunc==0)
			t=t->beforeLVL;
		if(t->func!=NULL)
		printf(",in func %s\n",t->func[t->countfunc-1]->name);
			else
		printf("\n");
		exit(1);
	}
	if(codey->var==NULL)
	{ 
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	}
	else
	{
		temp=codey->var;
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*(codey->countvar+countvars));
		for(int i=0;i<codey->countvar;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(temp[i].name,args[j].name)==0 )
				{
					printf("sorry you can't some var %s in some scope",temp[i].name);
					code * t=codey->beforeLVL;
					while(t->beforeLVL!=NULL && t->beforeLVL->countfunc==0)
						t=t->beforeLVL;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->countfunc-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			codey->var[i]=temp[i];	
		}
	}
	for(int j=0;j<countvars;j++)
	{

		codey->var[codey->countvar].name=args[j].name;
		codey->var[codey->countvar].value=NULL;
		codey->var[codey->countvar].isArg=isArg;
		codey->var[codey->countvar].len=args[j].len;
		codey->var[(codey->countvar)++].type=args[j].type;
	}
	/*printf("vars in scope %s \n",codey->name);
	for(int i=0;i<codey->countvar;i++)
	{
		printf("%s %s,", codey->var[i].name,codey->var[i].type);
	}printf("\nend vars scope %d\n",codey->place);*/
}

void addFunc(char * name,Arguments * args,node *returnType,int countArgs,code * CODEscope){
	Function** temp;
	code * codey=CODEscope;
	for(int i=0;i<countArgs;i++)
		for(int j=0;j<countArgs;j++)
	if(i!=j && strcmp(args[j].name,args[i].name)==0 )
	{
		printf("sorry you can't some Arguments %s in func %s\n",args[i].name,name);
		exit(1);
	}
	if(codey->func==NULL)
	{ 
		codey->func=(Function**) malloc(sizeof(Function*));
	}
	else
	{
		temp=codey->func;
		codey->func=(Function**) malloc(sizeof(Function*)*(codey->countfunc+1));
		for(int i=0;i<codey->countfunc;i++)
		{
				if(strcmp(temp[i]->name,name)==0 )
				{
					printf("sorry you can't some func %s in some scope \n",temp[i]->name);
					exit(1);
				}
				codey->func[i]=temp[i];
		}
	}
		codey->func[codey->countfunc]=(Function*) malloc(sizeof(Function));
		codey->func[codey->countfunc]->name=name;
		codey->func[codey->countfunc]->args=args;
		if(returnType==NULL)
		codey->func[codey->countfunc]->returnType=NULL;
		else{
		if(strcmp(returnType->token,"string")==0)
			{
				printf("ERORR,return type func %s cant be string\n",name);
				exit(1);
			}
		codey->func[codey->countfunc]->returnType=returnType->token;
		}
		codey->func[codey->countfunc]->countArgs=countArgs;
		codey->func[codey->countfunc]->findreturn=false;
		++(codey->countfunc); 

		
	
	/*printf("start %s in scope %d\n",name,codey->place);
	for(int i=0;i<countArgs;i++)
	{
		printf("%s %s,", codey->func[codey->countfunc-1]->args[i].name,codey->func[codey->countfunc-1]->args[i].type);
	}printf("end %s\n",name);*/
}

Arguments * mkArgs(node *tree,int *count){
	Arguments  *arr=NULL,ar[50];
	char* type,*len;
	if(tree!=NULL)
	{
		node * temp1=tree,*temp=tree;
		do{
		if(strcmp(temp1->token, "")==0)
		{
			temp=temp1->right->left;
			temp1=temp1->left;
			
			
			if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
		{
			type=temp->left->token;
			if(temp->left->left!=NULL)
			len=temp->left->left->left->token;
			node * treee;
			treee=temp->right->left;
			do{
			ar[*count].name=treee->token;
			ar[*count].type=type;
			ar[*count].len=len;
			(*count)++;
			if(treee->left==NULL)
				treee=NULL;
			else
				treee=treee->left->left;
			}while(treee!=NULL);
		}
		}
		}while(strcmp(temp1->token, "(")!=0&&strcmp(temp->token, "var")!=0);
		temp=temp1;
		if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
		{
			type=temp->left->token;
			node * treee;
			if(strcmp(temp->token, "var")==0)
			treee=temp->right;
			else
			treee=temp->right->left;
			if(temp->left->left!=NULL)
			len=temp->left->left->left->token;
			do{
			ar[*count].name=treee->token;
			ar[*count].type=type;
			ar[*count].len=len;
			(*count)++;
			if(treee->left==NULL)
				treee=NULL;
			else
				treee=treee->left->left;
			}while(treee!=NULL);
		}
		arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
		for(int i=0;i<*count;i++)
		{
			for(int j=0;j<*count;j++){
			}
			arr[i].name=ar[i].name;
			arr[i].type=ar[i].type;
			//printf("%s %s,", arr[i].name,arr[i].type);
		}
		//printf("\n");
	}
	return arr;
}

node *makeNode(char *token, node *left, node *right) {
    node *newnode = (node*)malloc(sizeof(node));
    char *newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return newnode;
}

void printTree (node *tree, int tab){
    int nextTab = tab;
    if (strlen(tree->token) > 0) {
        printTabs(tab);
        printf ("%s", tree->token);
        if (tree->left != NULL) {
            printf("\n");
        }
    }
    if (tree->left) {
        if (strlen(tree->token) == 0) {
            nextTab = tab - 1;
        }
        printTree(tree->left, nextTab + 1);
        if (strlen(tree->token) > 0) {
            printTabs(tab);
        }
    }
    if (strlen(tree->token) > 0) {
        printf ("\n");
    }
    if (tree->right) {
        printTree (tree->right, tab);
    }
}

void printTabs(int numOfTabs) {
    int i;
    for (i = 0; i < numOfTabs; i++) {
        printf ("\t");
    }
}

int yyerror(char *e) {
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "does not accept '%s'\n",yytext);
	
	return 0;
}
code* lestcode(code * codey){
	code * CODEscope=codey;
	if(CODEscope!=NULL)
	while(CODEscope->nextLVL!=NULL)
		CODEscope=CODEscope->nextLVL;
	return CODEscope;
}


void syntaxMKscope(node *tree,code * CODEscope){
	if(strcmp(tree->token, "=") == 0 ) {
		if(!(strcmp(exprtype(tree->right,CODEscope),"NULL")==0
		&& (strcmp(exprtype(tree->left,CODEscope),"real*")==0
		||strcmp(exprtype(tree->left,CODEscope),"int*")==0
		||strcmp(exprtype(tree->left,CODEscope),"char*")==0)))
		if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))!=0) {
			printf("ERORR, you can't do = between %s and %s in scope %s in func/proc %s\n",exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),CODEscope->name,mycode->func[mycode->countfunc-1]->name);
			exit(1);
		}
	}
	else if(strcmp(tree->token, "var") == 0) {
		int countvar = 0;
		Arguments *var = mkArgs(tree, &countvar);
		addvar(var, countvar, 0, CODEscope);
	}
	else if(strcmp(tree->token, "if") == 0) {
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean") != 0) {
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0) {
			push(CODEscope,tree->token);
			if (tree->left) 
				syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
	
			if (tree->right)
				syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
        	scope--;
			return;
		}	
	}
	else if(strcmp(tree->token, "while") == 0) {
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean") != 0) {
			printf("ERORR, in while expr most be type boolean\n");
			exit(1);
		}
		if(strcmp(tree->right->token,"{") != 0) {
			push(CODEscope,tree->token);
			if (tree->left) 
				syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
			if (tree->right)
				syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
        	scope--;
			return;
		}
	}
	else if(strcmp(tree->token, "for") == 0) {
	    if(strcmp(exprtype(tree->left->left->right,CODEscope),"boolean") != 0) {
			printf("ERORR, in for expr most be type boolean\n");
			exit(1);
		}
		syntaxMKscope(tree->left->left->left,CODEscope);
		syntaxMKscope(tree->left->right->left,CODEscope);
		if(strcmp(tree->right->token,"{") != 0) {
			push(CODEscope,tree->token);
			if (tree->left) syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
			if (tree->right) syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
        	scope--;
			return;
		}
	}
	else if(strcmp(tree->token, "FUNC") == 0 ) {
        int count=0;
		Arguments * arg=mkArgs(tree->left->right->left,&count);
		addFunc(tree->left->token,arg,tree->left->right->right->left,count,CODEscope);
		push(CODEscope,tree->token);
		addvar(arg,count,1,lestcode(CODEscope));
		if (tree->left) syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
		if (tree->right) syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
		if(CODEscope->func[CODEscope->countfunc-1]->findreturn==false) {
			printf("ERORR,in func %s not find return\n",tree->left->token);
			exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree->token, "PROC") == 0) {
        int count=0;
		Arguments * arg=mkArgs(tree->right->left,&count);
		addFunc(tree->left->token,arg,NULL,count,CODEscope);
		push(CODEscope,tree->token);
		addvar(arg,count,1,lestcode(CODEscope));
		if (tree->left) 
			syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
		if (tree->right)
			syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
			scope--;	
			return;
    }

	else if(strcmp(tree->token, "Call func") == 0) {
		findfunc(tree,CODEscope);
		printf("(%s \n",tree->token);
	}
	else if(strcmp(tree->token, "CODE") == 0) {
		printTree(tree,printlevel);
		push(NULL,tree->token);
		if (tree->left) syntaxMKscope(tree->left,mycode);
		if (tree->right) syntaxMKscope(tree->right,mycode);
		scope--;
		return;
	}
    else if(strcmp(tree->token, "BODY") == 0) { }
	else if(strcmp(tree->token, "ARGS") == 0) { }
    else if(strcmp(tree->token, "Main") == 0) {
		if(flagMain==true && strcmp(CODEscope->name,"CODE")==0) {
			printf("Main needs to be one anad only and not inside a func/proc\n");
			exit(1);
		}
		flagMain=true;
		addFunc(tree->token,NULL,NULL,0,CODEscope);
		push(CODEscope,tree->token);
		if (tree->left) 
			syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
		
		if (tree->right)
			syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
			scope--;
			return;        
    }       
	else if(strcmp(tree->token, "if-else") == 0) {
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0) {
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}
		if(strcmp(tree->right->left->token,"{")!=0) {
			push(CODEscope,tree->token);
			syntaxMKscope(tree->right->left,lestcode( CODEscope->nextLVL));
			scope--;
			push(CODEscope,tree->token);
			syntaxMKscope(tree->right->right->left,lestcode( CODEscope->nextLVL));
        	scope--;
			return;
		}	
	}
	else if(strcmp(tree->token, "return") == 0) {
		code * temp= CODEscope;
		int flag=true;
		while(strcmp(temp->name,"FUNC")!=0&&strcmp(temp->name,"PROC")!=0&&strcmp(temp->name,"CODE")!=0) {
			temp=temp->beforeLVL;
			flag=false;
		}
		if(flag==false) {
			if(strcmp(exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType))
			{
			printf("ERORR,return no some type in func %s \n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
			printf("%s ,%s %s\n",exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType,temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
			exit(1);
			}
		}
		else{
			if(temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType!=NULL) {
				if(0==strcmp(exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType)){
					temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->findreturn=true;
				}
				else {
					printf("ERORR,return no some type in func %s \n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
					printf("%s ,%s %s\n",exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType,temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
					exit(1);
				}
			}
			else {
				printf("ERORR,return cant be in proc %s\n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
				exit(1);
			}  
		}  

	}
	else if(strcmp(tree->token, "{") == 0) {
		push(CODEscope,tree->token);
		if (tree->left) 
			syntaxMKscope(tree->left,lestcode( CODEscope->nextLVL));
		if (tree->right)
			syntaxMKscope(tree->right,lestcode( CODEscope->nextLVL));
			scope--;
			return;		
	}
	else if(strcmp(tree->token, "}") == 0) { }
	else if(strcmp(tree->token, "") == 0);
	else if(strcmp(tree->token, "(") == 0) printf("(");
	else if(strcmp(tree->token, ")") == 0) printf(")\n");
	else if(strcmp(tree->token, ",") == 0) printf(",");
	else if(strcmp(tree->token, ";") == 0) printf("\n");
	else if(strcmp(tree->token, "&&") == 0 ||
			strcmp(tree->token, "/") == 0 || 
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
			strcmp(tree->token, ",") == 0 ) printf("(%s",tree->token);		
	else if(strcmp(tree->token, "solovar") == 0 ) findvar(tree->left,CODEscope);
	
	if (tree->left) syntaxMKscope(tree->left,CODEscope);
	
	if (tree->right) syntaxMKscope(tree->right,CODEscope);
}