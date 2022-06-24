%{
#include <stdio.h>
#include <ctype.h>
#include "sym.h"
//#include <time.h>
//#include <stdlib.h>

#include <string.h>
extern int yylineno;
extern int global_scope;
extern VAR *SymTab;
FILE * output;
#define UNDECL  0
#define INT     1
#define BOOL    2
#define FLT     3
#define STR     4
#define ARR		5
#define AddVAR(n,t) SymTab=MakeVAR(n,t,SymTab)
#define ASSERT(x,y) if((x)) printf("%s on line %d\n",(y),yylineno)
%}

//%define parse.error verbose //aparecer mais detalhes dos erros
//docker run  -it  -v "%cd%":/usr/src  phdcoder/flexbison
%union {
	int   yint;// 1
	int ybool; //2
	float yfloat; //3
	char* ystr; //4
}

%start program
%token DLET DCONST DVAR VSTR VBOOL
%token <yint> VINT
%token <yfloat> VFLOAT
%token <ystr> IDENTIFIER
%token ASSGNOP MAIORIGUAL
%left '>' '<' '=' MAIORIGUAL
%left '-' '+'
%left '*' '/'
%left '^'

%type  <yint>  exp
%type  <yint>  value
%%

program : {} commands
;

commands : command ';' commands | /* ε */ ;

command : declarations 
;

declarations:  /* ε */
| DLET IDENTIFIER comma_not {
	VAR *p = FindVAR($2);
	ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2,UNDECL);
	fprintf(output, "%s = None\n", $2);
} declarations 
| DVAR IDENTIFIER comma_not {
	VAR *p = FindVAR($2);
	ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2,UNDECL);
	fprintf(output, "%s = None\n", $2);
} declarations
| DLET IDENTIFIER ASSGNOP {
	fprintf(output, "%s = ", $2);
} value comma_not {
	VAR *p = FindVAR($2);
	ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2, $5);
	fprintf(output, "\n");
} declarations 
| DVAR IDENTIFIER ASSGNOP {
	fprintf(output, "%s = ", $2);
} value comma_not {
	VAR *p = FindVAR($2);
	ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2, $5);
	fprintf(output, "\n");
} declarations
| DCONST IDENTIFIER ASSGNOP {
	fprintf(output, "%s = ", $2);
} value comma_not {
	VAR *p = FindVAR($2);
	ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2, $5);
	fprintf(output, "\n");
} declarations
;

comma_not: 
| ";"
;

value: VSTR { $$= STR; }
| VBOOL { $$= BOOL;  /* fprintf(output, "%s", $1 == "true" ? "True" : "False"); */ }
| exp
;

exp: VINT { $$= INT; fprintf(output, "%d", $1); }
| VFLOAT { $$= FLT; fprintf(output, "%f", $1); }
| IDENTIFIER  {  
	VAR *p=FindVAR($1);
	ASSERT(p==NULL,"Identificador Não declarado");
	$$= (p!=NULL) ? p->type : UNDECL;  
}
| exp MAIORIGUAL exp {  
	ASSERT(($1== INT || $1== FLT) && ($3== INT || $3== FLT), "Operadores devem ser INT ou FLT");
    $$= BOOL;  
}
| exp '<' exp  { 
	ASSERT(  ($1== INT || $1== FLT) && ($3== INT || $3== FLT) , "Operadores devem ser INT ou FLT");
    $$= BOOL;
}
| exp '=' exp  {  
	ASSERT(  ($1== INT || $1== FLT) && ($3== INT || $3== FLT)  , "Operadores devem ser INT ou FLT");
    $$= BOOL; 
}
| exp '>' exp  { 
	ASSERT(  ($1== INT || $1== FLT) && ($3== INT || $3== FLT)  , "Operadores devem ser INT ou FLT");
    $$= BOOL;  
}
| exp '+' exp  {   
	ASSERT(  ($1== INT || $1== FLT) && ($3== INT || $3== FLT)  , "Operadores devem ser INT ou FLT");
	if ($1==FLT || $3==FLT){
		$$= FLT;
	} else {
		$$= INT;
	}
}
| exp '-' exp  { 
	ASSERT(  ($1== INT || $1== FLT) && ($3== INT || $3== FLT)  , "Operadores devem ser INT ou FLT");
	if ($1==FLT || $3==FLT){
		$$= FLT;
	} else {
		$$= INT;
	}
}
| exp '*' exp  { 
	ASSERT(  ($1== INT || $1== FLT) && ($3== INT || $3== FLT)  , "Operadores devem ser INT ou FLT");
	if ($1==FLT || $3==FLT){
		$$= FLT;
	} else {
		$$= INT;
	}
}
| exp '/' exp  { 
	ASSERT(  ($1== INT || $1== FLT) && ($3== INT || $3== FLT)  , "Operadores devem ser INT ou FLT");
	if ($1==FLT || $3==FLT){
		$$= FLT;
	} else {
		$$= INT;
	}
}
| exp '^' exp  { 
	ASSERT(  ($1== INT || $1== FLT) && ($3== INT || $3== FLT)  , "Operadores devem ser INT ou FLT");
	if ($1==FLT || $3==FLT){
		$$= FLT;
	} else {
		$$= INT;
	}
}
;


%%

main( int argc, char *argv[] ) {
	output = fopen("output.py","w");
	init_stringpool(10000); //memória que vai guardar as strings
	if ( yyparse () == 0) printf("\ncodigo sem erros");
}

yyerror(char *s) { /* Called by yyparse on error */
	printf ("\n%s on line %d\n", s, yylineno );
}