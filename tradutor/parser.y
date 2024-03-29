%{
#include <stdio.h>
#include <ctype.h>
#include "sym.h"

extern int yylineno;
extern int global_scope;
extern VAR *SymTab;

FILE * output;

void ScopeTab(){
	int i;
	for(i = 0; i < global_scope; i++){ 
		fprintf(output, "\t");
	}
}

#define AddVAR(n) SymTab=MakeVAR(n,SymTab)
#define ASSERT(x,y) if((x)) printf("%s on line %d\n",(y),yylineno)
%}

%define parse.error verbose //aparecer mais detalhes dos erros
//docker run  -it  -v "%cd%":/usr/src  phdcoder/flexbison
%union {
	char* ystr;
}

%start goal
%token DLET DCONST DVAR DFUNC DAFUNC
%token <ystr> VSTR VINT VBOOL VFLOAT IDENTIFIER
%token <ystr> CIF CELSE
%token ASSGNOP EXPGT EXPLT EXPEQ EXPDF NULLCOALESCING LOGOR LOGAND
%token FRETURN FBREAK FCONTINUE SEMICOLON
%token LFOR LOF LIN LWHILE
%token CBLOCK CINLINE 
%left '?' ':' LOGOR LOGAND NULLCOALESCING
%left '>' '<' '=' EXPGT EXPLT EXPEQ EXPDF
%left '-' '+'
%left '*' '/'
%left '[' ']'

%type <ystr> program
%type <ystr> assigns
%type <ystr> expression
%type <ystr> statement
%type <ystr> declarations
// %type <ystr> value
%type <ystr> anonymFunction flow
%type <ystr> funcParamsNull funcParams funcArgsNull
%type <ystr> arr_expression arr_values arr_index
// %type <ystr> flowcontrol
%%

goal: program { global_scope = 0; } 
| 
;


program : statement semicolon_not
| statement semicolon_not program
;

semicolon_not: 
| SEMICOLON
;

statement: expression { if($1 != ""){ ScopeTab(); fprintf(output, "%s\n", $1);} }
| declarations { if($1 != ""){ ScopeTab(); fprintf(output, "%s\n", $1);}}
| assigns {if($1 != ""){ ScopeTab(); fprintf(output, "%s\n", $1);}}
| conditional { $$=""; }
| loop {$$="";}
| flow {if($1 != ""){ ScopeTab(); fprintf(output, "%s\n", $1);}}
;

flow: FRETURN { $$="return"; }
| FRETURN expression {
	char t[1000]; 
	sprintf(t, "return %s", $2); 
	$$=stringpool(t);
}
| FBREAK {$$="break";}
| FCONTINUE {$$="continue";}
;

loop: LFOR '(' declarations SEMICOLON expression SEMICOLON assigns ')' '{' {
	ScopeTab();
	fprintf(output, "%s\n", $3);
	ScopeTab();
	fprintf(output, "while %s:\n", $5); 
	global_scope += 1;
} program '}' {
	ScopeTab();
	fprintf(output, "%s\n", $7); 
	global_scope -= 1;
}
| LFOR '(' DLET IDENTIFIER LOF IDENTIFIER ')' '{' {
	fprintf(output, "for %s in %s:\n", $4, $6); 
	global_scope += 1;
} program '}' {
	global_scope -= 1;
}
| LFOR '(' DLET IDENTIFIER LOF arr_expression ')' '{' {
	fprintf(output, "for %s in %s:\n", $4, $6); 
	global_scope += 1;
} program '}' {
	global_scope -= 1;
}
| LWHILE '(' expression ')' '{' {
	fprintf(output, "while %s:\n", $3); 
	global_scope += 1;
} program '}' {
	ScopeTab();
	global_scope -= 1;
}
;

declarations: DLET IDENTIFIER {
	// VAR *p = FindVAR($2);
	// ASSERT((p!=NULL), "Identificador já declarado");
	// AddVAR($2);
	char t[1000]; 
	sprintf(t, "%s = None", $2); 
	$$=stringpool(t);
} 
| DVAR IDENTIFIER {
	char t[1000]; 
	sprintf(t, "%s = None", $2); 
	$$=stringpool(t);
}
| DLET IDENTIFIER ASSGNOP expression {	
	char t[1000];
	char w[1000];  
	sprintf(t, "%s =", $2); 
	sprintf(w, "%s", $4); 
	sprintf(t, "%s %s", t, w);
	$$=stringpool(t);
} 
| DVAR IDENTIFIER ASSGNOP expression {
	char t[1000];
	char w[1000];  
	sprintf(t, "%s =", $2); 
	sprintf(w, "%s", $4); 
	sprintf(t, "%s %s", t, w);
	$$=stringpool(t);
}
| DCONST IDENTIFIER ASSGNOP expression {
	char t[1000];
	char w[1000];  
	sprintf(t, "%s =", $2); 
	sprintf(w, "%s", $4); 
	sprintf(t, "%s %s", t, w);
	$$=stringpool(t);
}
| DCONST IDENTIFIER ASSGNOP {
	fprintf(output, "def %s", $2);
} anonymFunction { $$ = ""; }
| DFUNC IDENTIFIER '(' { 
	fprintf(output, "def %s(", $2);
} funcParamsNull ')' '{'  { 
	fprintf(output, "):\n");
	global_scope += 1;
} program '}' { 
	$$ = "";
	global_scope -= 1;
}
;

assigns: IDENTIFIER ASSGNOP expression {	
	char t[1000];
	char w[1000];  
	sprintf(t, "%s =", $1); 
	sprintf(w, "%s", $3); 
	sprintf(t, "%s %s", t, w);
	$$=stringpool(t);
}
| IDENTIFIER '[' arr_values ']' ASSGNOP expression {
	char t[1000];
	char w[1000];  
	sprintf(t, "%s[%s] =", $1, $3); 
	sprintf(w, "%s", $6); 
	sprintf(t, "%s %s", t, w);
	$$=stringpool(t);
}
;

anonymFunction: DFUNC '(' { 
	fprintf(output, "(");
} funcParamsNull ')' '{' { 
	fprintf(output, "):\n");
	global_scope += 1; 
} program '}' { 
	global_scope -= 1; 
	$$ = "";
}
| '(' funcParamsNull ')' DAFUNC '{'  { 
	fprintf(output, "(%s):\n", $2);
	global_scope += 1; 
} program '}' { 
	$$ = "";
	global_scope -= 1; 
}
; 

funcParamsNull: { $$ = ""; }
| funcParams { char t[1000]; sprintf(t, "%s", $1); $$=stringpool(t); } 
;

funcParams: IDENTIFIER { $$ = $1; fprintf(output, "%s", $1);}
| assigns { $$ = $1; fprintf(output, "%s", $1); }
| IDENTIFIER  {	
	fprintf(output, "%s", $1);
} ','  {	
	fprintf(output, ", ");
} funcParams
| assigns  {	
	fprintf(output, "%s", $1);
} ','  {	
	fprintf(output, ", ");
} funcParams
;

funcArgsNull: { $$ = ""; }
| expression { char t[1000]; sprintf(t, "%s", $1); $$=stringpool(t);}
| expression ',' funcArgsNull  { char t[1000]; sprintf(t, "%s, %s", $1, $3); $$=stringpool(t); } 
| ',' funcArgsNull  { char t[1000]; sprintf(t, ", %s", $2); $$=stringpool(t); } 
;

conditional: CIF '(' expression ')' '{' { 
	ScopeTab();
	fprintf(output, "if %s:\n", $3); 
	global_scope += 1;
} program {
	global_scope -= 1;
} '}' conditionalElse

conditionalElse:
| CELSE '{' { 
	ScopeTab();
	fprintf(output, "else:\n");
	global_scope += 1;
} program {
	global_scope -= 1;
} '}' 
| CELSE CIF '(' expression ')' '{' { 
	ScopeTab();
	fprintf(output, "elif %s:\n",$4);
	global_scope += 1;
} program {
	global_scope -= 1;
} '}' conditionalElse
;


// value: VSTR { $$ = $1; }
// | VBOOL { $$ = $1 == stringpool("true") ? "True" : "False"; }
// | expression { $$ = $1; }
// ;

arr_expression: '[' ']' {$$="[ ]";}
| '[' arr_values ']' { char t[1000]; sprintf(t, "[ %s ]", $2); $$=stringpool(t); } 
;

arr_values: expression { $$ = $1; }
| expression ',' arr_values { char t[1000]; sprintf(t, "%s, %s", $1, $3); $$=stringpool(t); }
;

arr_index: IDENTIFIER '[' arr_values ']' {
	char t[1000]; sprintf(t, "%s[%s]", $1, $3); $$=stringpool(t);
}
| arr_expression '[' arr_values ']' {
	char t[1000]; sprintf(t, "%s[%s]", $1, $3); $$=stringpool(t);
}
;

expression: VSTR { $$ = $1; }
| VBOOL { $$ = $1 == stringpool("true") ? "True" : "False"; }
| VINT { $$= $1;  }
| VFLOAT { $$= $1; }
| IDENTIFIER  {	
	$$= $1; 
}
| IDENTIFIER '(' funcArgsNull ')' {
 char t[1000]; sprintf(t, "%s( %s )", $1, $3); $$=stringpool(t);}
| arr_index { $$ = $1; }
| arr_expression { $$ = $1; }
// | '(' expression ')' { char t[1000]; sprintf(t, "( %s )", $2); $$=stringpool(t); }
| expression NULLCOALESCING expression { char t[1000]; sprintf(t, "%s or %s", $1, $3); $$=stringpool(t); }
| expression '?' expression ':' expression { char t[1000]; sprintf(t, "%s if %s else %s", $3, $1, $5); $$=stringpool(t); }
| expression LOGAND expression { char t[1000]; sprintf(t, "%s and %s", $1, $3); $$=stringpool(t); }
| expression LOGOR expression { char t[1000]; sprintf(t, "%s or %s", $1, $3); $$=stringpool(t);}
| expression EXPGT expression { char t[1000]; sprintf(t, "%s >= %s", $1, $3); $$=stringpool(t); }
| expression EXPLT expression { char t[1000]; sprintf(t, "%s <= %s", $1, $3); $$=stringpool(t); }
| expression EXPEQ expression { char t[1000]; sprintf(t, "%s == %s", $1, $3); $$=stringpool(t); }
| expression EXPDF expression { char t[1000]; sprintf(t, "%s != %s", $1, $3); $$=stringpool(t); }
| expression '<' expression { char t[1000]; sprintf(t, "%s < %s", $1, $3); $$=stringpool(t); }
| expression '>' expression { char t[1000]; sprintf(t, "%s > %s", $1, $3); $$=stringpool(t); }
| expression '+' expression { char t[1000]; sprintf(t, "%s + %s", $1, $3); $$=stringpool(t); }
| expression '-' expression { char t[1000]; sprintf(t, "%s - %s", $1, $3); $$=stringpool(t); }
| expression '*' expression { char t[1000]; sprintf(t, "%s * %s", $1, $3); $$=stringpool(t); }
| expression '/' expression { char t[1000]; sprintf(t, "%s / %s", $1, $3); $$=stringpool(t); }
;


%%

int main( int argc, char *argv[] ) {
	output = fopen("output.py","w");
	init_stringpool(10000); //memória que vai guardar as strings
	if ( yyparse () == 0) printf("\n\n ----- Code without errors ----- \n\n");
}

int yyerror(char *s) { /* Called by yyparse on error */
	printf ("\n%s on line %d\n", s, yylineno );
}