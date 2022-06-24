/* Simple Symbol table
 * November 2001, A. Jost, Dalhousie University
 */

#include <stdio.h>
#include <stdlib.h>
#include "sym.h"
static char *strings;
static char *strp;
#define UNDECL  0
#define INT     1
#define BOOL    2
#define FLT     3
#define STR     4
#define ARR		5
static int strsize = 0;
int global_scope = 0;
//char *calloc(int,int);
int escopo1Destruido = 0;
VAR *SymTab = NULL;

const char* TypeName(int x){
	if(x == UNDECL) return "None";
	if(x == INT) return "int";
	if(x == BOOL) return "bool";
	if(x == FLT) return "float";
	if(x == STR) return "str";
	if(x == ARR) return "list";
}

VAR *MakeVAR(char *name, int type, VAR *next) {
	VAR *p;
	p = NEW(VAR);
	p->name = name;
	p->type = type;
	p->scope = global_scope;
	p->next = next;
	return p;
}

VAR *FindVAR(char *name) {
	VAR *p = SymTab;
	//printf("\nTo procurando por: %s", name);

	while( (p != NULL) && (p->name != name) ) {
		//printf("\n [nome: %s, scopo: %d] ",p->name, p->scope);
		p = p->next;
	}

	return p;
}

/* Simple string table manager for use with symbol table */
void init_stringpool(int strs) {
	if ( strs <= 0 ) return;
	strings = (char *) calloc(strs, sizeof(char));

	if ( strings == NULL ) {
		fprintf(stderr, "Cannot allocate string table of size %d\n", strs);
		exit(1);
	}
	strsize = strs;
	strp = strings;
}

/* Add a string to string table and return a pointer to it.
 * If string is already in the table, return pointer to one found.
 * Guarantees that every unique string has a unique pointer.
 */
char *stringpool(char *s) {
	register char *start=strp;
	register char *p = strings;
	register char *q, *r;
	
    /* Stick a copy of the string at the end of the table */
	while ( *s != '\0' ) {
		if ( strp >= &(strings[strsize-2]) ) {
			fprintf(stderr, "sym: string table overflow (%d chars)\n", strsize);
			exit(1);
		}
		*strp++ = *s++;
	}
	*strp++ = '\0';
	/* Make sure this is not a duplicate */
	while(p<strp) {
	    r=p; q=start;
	    while((*p==*q)&&(*p!='\0')) { p++; q++; }
	    if (*p==*q) break; /* found it */
	    /* else advance p past next null; try again */
	    while (*p++) ;
	}
	if (r != start) { /* already in table: trash new copy */
	    strp = start;
	    start = r;
	}
	return( start );
}
