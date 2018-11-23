%{
#include <stdio.h>
#include <stdlib.h>

// To avoid warning, we include below definitions:
int yylex(void);
void yyerror(const char *s);

%}

%token ID 
%token OPBR 
%token CLBR 
%token INC 
%token MULT

 
%%
// RULES SECTION: 

EXPR : TERM EXPRPRIMA { printf("\nOk\n"); exit(0); }

EXPRPRIMA : INC TERM 
| 

TERM : FACTOR TERMPRIMA

TERMPRIMA : MULT EXPR 
| 

FACTOR : ID 
| OPBR EXPR CLBR 

;

%%

#include"lex.yy.c"  	
int main(void) {   
	yyparse();    
}  

void yyerror(const char *s){ printf("\nERROR\n"); }
int yywrap(){ return 1; }
