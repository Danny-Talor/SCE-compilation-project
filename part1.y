%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	char *token; 
	struct node *left;
	struct node *right;
} node;
node *makeNode(char *token, node *left, node *right);
void printTree(node *tree, int tab);
void printTabs(int numOfTabs);
int yyerror(char *err);
int yylex();
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
%type <string> ret_type
%type <string> primitive_value
%type <string> unary_op

%type <node> start
%type <node> initial
%type <node> code
%type <node> function
%type <node> procedure
%type <node> args_Id
%type <node> args
%type <node> body
%type <node> update
%type <node> declaration
%type <node> statement
%type <node> string_type
%type <node> math_expression
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

start: initial { printTree($1,0); };

initial: code { $$ = makeNode("CODE", $1, NULL); };

code: function code { $$ = makeNode("FUNCTION",$1, $2); } 
    | function { $$ = makeNode("FUNCTION",$1, NULL); } 
    | procedure code{ $$ = makeNode("FUNCTION",$1, $2); } 
    | procedure { $$ = makeNode("FUNCTION",$1, NULL); };

function: FUNC ID '(' args ')' ':' type '{' body '}' {$$ = makeNode($2, NULL, makeNode("ARGS", $4, makeNode($7, NULL, $9))); };

procedure: FUNC ID '(' args ')' ':' VOID '{' body_proc '}' {$$ = makeNode($2,NULL, makeNode("ARGS", $4,makeNode("TYPE VOID", NULL,$9))); };

args: args_Id type { $$ = makeNode($2, $1, NULL); }
    | args ',' args_Id type { $$ = makeNode($4, $3, $1); }
    | FUNCARGS args_Id type { $$ = makeNode($3, $2, NULL); $$->left = makeNode("", NULL, $2); }
    | FUNCARGS args_Id type ';' args { $$ = makeNode($3, $2, $5); $$->left = makeNode("", NULL, $2); }
    | { $$ = NULL; };

args_Id: ID { $$ = makeNode($1, NULL, NULL); } 
       | ID ':' { $$ = makeNode($1, NULL,NULL); }
       | ID ',' args_Id { $$ = makeNode($1, NULL, $3); }
       | FUNCARGS ID ',' args_Id { $$ = makeNode($2, NULL, $4); }
       | FUNCARGS ID ':' { $$ = makeNode($2, NULL, NULL); $$->left = makeNode($2, NULL, NULL); }
       | { $$ = NULL; };

string_Id: ID '[' math_expression ']' { $$ = makeNode($1, makeNode("[]", NULL,$3), NULL); }
         | assignment ':'{ $$ = $1; }
         | assignment ',' string_Id { $1->right = $3;  $$ = $1; }
         | FUNCARGS ID '[' math_expression ']'  ',' string_Id { $$ = makeNode($2, makeNode("[]", NULL,$4), $7); }
         | FUNCARGS ID '[' math_expression ']' ':' {$$ = makeNode($2, makeNode("[]", NULL,$4), NULL); };
  
type: BOOL { $$ = "BOOL"; } 
    | CHAR { $$ = "CHAR"; } 
    | INT { $$ = "INT"; } 
    | REAL { $$ = "REAL"; } 
    | INTP { $$ = "INT_PTR"; } 
    | CHARP { $$ = "CHAR_PTR"; } 
    | REALP { $$ = "REAL_PTR"; };

ret_type: BOOL { $$ = "TYPE BOOL"; }
        | CHAR { $$ = "TYPE CHAR"; } 
		| INT { $$ = "TYPE INT"; }
	    | REAL { $$ = "TYPE REAL"; }
        | INTP { $$ = "TYPE INT_PTR"; }
        | CHARP { $$ = "TYPE CHAR_PTR"; }
        | REALP { $$ = "TYPE REAL_PTR"; }
        | STRING {$$ = "TYPE STRING";};

string_type: STRING string_Id { $$ =$2; };

body: declaration nested_statement return_statement { $$ = makeNode("BODY", makeNode("", $1, $2),$3); }
    | declaration return_statement {$$ = makeNode("BODY",$1, $2); }
    | nested_statement return_statement { $$ = makeNode("BODY", $1 ,$2); };

body_proc: declaration proc_nested_statement { $$ = makeNode("BODY", makeNode("", $1, $2),NULL); }
         | declaration {$$ = makeNode("BODY",$1, NULL); }
         | proc_nested_statement { $$ = makeNode("BODY", $1 ,NULL); };

declaration: function declaration { $$ = makeNode("FUNCTION", $1, $2); }
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
         | for_statement {$$ = $1;};

func_statement: ID ASSIGN ID '(' func_arguments ')' ';' { $$ = makeNode($2,makeNode($1,NULL,makeNode($3,$5,NULL)),NULL); }
              | ID '(' func_arguments ')' ';' {$$ = makeNode($1,$3,NULL);};

func_arguments: { $$ = NULL; }
              | math_expression ',' func_arguments {$1->right=$3;$$=$1;}
              | math_expression{ $$ = $1; } ;

assignment: ID ASSIGN math_expression { $$ = makeNode($2,makeNode($1,NULL, $3), NULL);}
          | ID ASSIGN expression { $$ = makeNode($2,makeNode($1,NULL, $3), NULL);}
          | ADDRESS ID ASSIGN expression { $$ = makeNode($1,makeNode($3,makeNode($2,NULL, $4), NULL), NULL);}
          | ID ASSIGN STRING_VAL {$$ = makeNode($2, makeNode($1, makeNode($3,NULL, NULL), NULL), NULL);}
          | ID '[' math_expression ']' ASSIGN STRING_VAL {$$ = makeNode($5, makeNode($1, makeNode("[]",NULL,$3),NULL),makeNode($6,NULL,NULL));}
          | ID ASSIGN ID '[' math_expression ']' {$$ = makeNode($2, makeNode($1,NULL,makeNode($3,makeNode("[]",NULL,$5),NULL)),NULL);}
          | ID '[' math_expression ']' ASSIGN CHAR_VAL {$$ = makeNode($5, makeNode($1, makeNode("[]",NULL,$3),NULL),makeNode($6,NULL,NULL));}
          | ID '[' math_expression ']' ASSIGN ID {$$ = makeNode($5, makeNode($1, makeNode("[]",NULL,$3),NULL),makeNode($6,NULL,NULL));};

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

math_expression: element_of_expression { $$ = $1;}  
               | math_expression ADD math_expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);}
               | math_expression SUB math_expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
               | math_expression MUL math_expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);} 
               | math_expression DIV math_expression {$1->right = $3; $$ = makeNode($2, $1 ,NULL);};

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

element_of_expression:   primitive_value {$$ = makeNode($1,NULL, NULL); }
                     |   '|' ID '|' { $$ = makeNode("STR_LEN", makeNode($2, NULL, NULL), NULL); };

primitive_value: CHAR_VAL { $$ = $1; }
               | HEX_INT  { $$ = $1; }
               | DEC_INT  {$$ = $1; }
               | REAL_VAL { $$ = $1; }
               | ID { $$ = $1; }
               | TRUE_VAL { $$ = $1;}
               | NULLP { $$ = $1; }
               | DER_ID { $$ = $1; }
               | FALSE_VAL { $$ = $1;};

address_of: ADDRESS ID { $$ = makeNode($1, makeNode($2, NULL, NULL), NULL); }
          | ADDRESS ID '[' expression ']' { $$ = makeNode($1, makeNode($2, makeNode("[]", $4, NULL), NULL), NULL); };

return_statement: RETURN math_expression ';' { $$ = makeNode("RET", $2, NULL); } ;

update: ID ADD ADD { $$ = makeNode("++", makeNode($1, NULL, NULL), NULL); }
      | ID SUB SUB { $$ = makeNode("--", makeNode($1, NULL, NULL), NULL); }
      | multi_assign { $$ = $1; };

unary_op: ADD { $$ = $1; }
        | SUB { $$ = $1; }
        | NOT {$$ = $1;};

%%
#include "lex.yy.c"
int main()
{
    return yyparse();
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

int yyerror(char *err) {
  int yydebug = 1;
  fflush(stdout);
  fprintf(stderr, "%s at line %d\n", err, yylineno);
  fprintf(stderr, "does not accept '%s'\n", yytext);
  return 0;
}