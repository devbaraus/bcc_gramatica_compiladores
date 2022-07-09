%{
#include <stdio.h>
#include <ctype.h>
#include "sym.h"
#include <string.h>

extern int yylineno;
extern int global_scope;
extern VAR *SymTab;

FILE * output;

#define AddVAR(n) SymTab=MakeVAR(n,SymTab)
#define ASSERT(x,y) if((x)) printf("%s on line %d\n",(y),yylineno)
%}

%define parse.error verbose //aparecer mais detalhes dos erros
//docker run  -it  -v "%cd%":/usr/src  phdcoder/flexbison
%union {
	char* ystr; //4
}

%start goal
%token DLET DCONST DVAR DFUNC
%token <ystr> VSTR VINT VBOOL VFLOAT IDENTIFIER
%token <ystr> CIF CELSE
%token ASSGNOP EXPGT EXPLT EXPEQ EXPDF NULLCOALESCING LOGOR LOGAND
%left '?' ':' LOGOR LOGAND NULLCOALESCING
%left '>' '<' '=' EXPGT EXPLT EXPEQ EXPDF
%left '-' '+'
%left '*' '/'
%left '^'

%type <ystr>  program
%type <ystr> conditional
%type <ystr> expression statement declarations assigns value 
%type <ystr> anonymFunction funcArgsNull funcArgs
// %type <ystr> flowcontrol
%%

goal: program {}


program : program statement
| statement
;

statement: assigns
| declarations
| conditional
;

declarations: DLET IDENTIFIER {
	VAR *p = FindVAR($2);
	// ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2);
	fprintf(output, "%s = None\n", $2);
	char t[1000]; sprintf(t, "%s = None\n", $2); $$= t;
} 
| DVAR IDENTIFIER {
	VAR *p = FindVAR($2);
	// ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2);
	fprintf(output, "%s = None\n", $2);
	char t[1000]; sprintf(t, "%s = None\n", $2); $$=t;
}
| DLET IDENTIFIER ASSGNOP assigns {
	VAR *p = FindVAR($2);
	// ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2);
	fprintf(output, "%s = %s\n", $2, $4);
	char t[1000]; sprintf(t, "%s = %s\n", $2, $4); $$=t;
} 
| DVAR IDENTIFIER ASSGNOP assigns {
	VAR *p = FindVAR($2);
	// ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2);
	fprintf(output, "%s = %s\n", $2, $4);
	char t[1000]; sprintf(t, "%s = %s\n", $2, $4); $$=t;
}
| DCONST IDENTIFIER ASSGNOP assigns {
	VAR *p = FindVAR($2);
	// ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2);
	fprintf(output, "%s = %s\n", $2, $4);
	char t[1000]; sprintf(t, "%s = %s\n", $2, $4); $$=t;
}
// | DLET IDENTIFIER ASSGNOP anonymFunction {
// 	VAR *p = FindVAR($2);
// 	// ASSERT((p!=NULL), "Identificador já declarado");
// 	AddVAR($2);
// 	char t[1000]; sprintf(t, "def %s %s\n", $2, $4); $$=t;
// 	fprintf(output, "%s", t);
// } 
| DVAR IDENTIFIER ASSGNOP anonymFunction {
	VAR *p = FindVAR($2);
	// ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2);
	char t[1000]; sprintf(t, "def %s %s\n", $2, $4); $$=t;
	fprintf(output, "def %s %s\n", $2, $4);

}
| DCONST IDENTIFIER ASSGNOP anonymFunction {
	VAR *p = FindVAR($2);
	// ASSERT((p!=NULL), "Identificador já declarado");
	AddVAR($2);
	char t[1000]; sprintf(t, "def %s %s\n", $2, $4); $$=t;
	fprintf(output, "def %s %s\n", $2, $4);

}
;

conditional: CIF '(' assigns ')' '{' { 
	fprintf(output, "if %s :\n\t",$3);
} statement '}' conditionalElse

conditionalElse: 
| CELSE '{' { 
	fprintf(output, "else:\n\t");
} statement '}'
| CELSE CIF '(' assigns ')' '{' { 
	fprintf(output, "elif %s :\n\t",$4);
} statement '}' conditionalElse
;

anonymFunction: DFUNC '(' funcArgsNull ')' '{' statement '}' { 
	char t[1000]; 
	sprintf(t, "( %s ): \n\t%s", $3, $6); 
	$$= t; 
	fprintf(output, "( %s ): \n\t%s", $3, $6); } 
; 

funcArgsNull: { $$ = ""; }
| funcArgs { $$ = $1; }
| IDENTIFIER ',' funcArgs { char t[1000]; sprintf(t, "%s ,", $1); $$=t; } 
;

funcArgs: IDENTIFIER { $$ = $1; }
| IDENTIFIER ',' funcArgs { char t[1000]; sprintf(t, "%s ,", $1); $$=t; } 
;

assigns: value NULLCOALESCING value { char t[1000]; sprintf(t, "%s or %s", $1, $3); $$=t; }
| value '?' value ':' value { char t[1000]; sprintf(t, "%s if %s else %s", $3, $1, $5); $$=t; }
| value { $$ = $1; }
;

value: VSTR { $$ = $1; }
| VBOOL { $$ = $1 == "true" ? "True" : "False"; }
// | "["  "]" { $$=ARR; fprintf(output, "[ %s ]", $2);}
| expression
;


expression: VINT { $$= $1;  }
| VFLOAT { $$= $1; }
| IDENTIFIER  {	VAR *p=FindVAR($1);	ASSERT(p==NULL,"Identificador Não declarado"); $$= $1; }
| expression LOGAND expression { char t[1000]; sprintf(t, "%s and %s", $1, $3); $$=t; }
| expression LOGOR expression { char t[1000]; sprintf(t, "%s or %s", $1, $3); $$=t; }
| expression EXPGT expression { char t[1000]; sprintf(t, "%s >= %s", $1, $3); $$=t; }
| expression EXPLT expression { char t[1000]; sprintf(t, "%s <= %s", $1, $3); $$=t; }
| expression EXPEQ expression { char t[1000]; sprintf(t, "%s == %s", $1, $3); $$=t; }
| expression EXPDF expression { char t[1000]; sprintf(t, "%s != %s", $1, $3); $$=t; }
| expression '<' expression { char t[1000]; sprintf(t, "%s < %s", $1, $3); $$=t; }
| expression '>' expression { char t[1000]; sprintf(t, "%s > %s", $1, $3); $$=t; }
| expression '+' expression { char t[1000]; sprintf(t, "%s + %s", $1, $3); $$=t; }
| expression '-' expression { char t[1000]; sprintf(t, "%s - %s", $1, $3); $$=t; }
| expression '*' expression { char t[1000]; sprintf(t, "%s * %s", $1, $3); $$=t; }
| expression '/' expression { char t[1000]; sprintf(t, "%s / %s", $1, $3); $$=t; }
| expression '^' expression { char t[1000]; sprintf(t, "%s ^ %s", $1, $3); $$=t; }
;


%%

main( int argc, char *argv[] ) {
	output = fopen("output.py","w");
	init_stringpool(10000); //memória que vai guardar as strings
	if ( yyparse () == 0) printf("\n\n ----- Code without errors ----- \n\n");
}

yyerror(char *s) { /* Called by yyparse on error */
	printf ("\n%s on line %d\n", s, yylineno );
}