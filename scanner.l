%{
#include "parser.tab.h"
char *stringpool(char *);
%}
%option yylineno

DIGIT    [0-9]
ID       [_a-zA-Z][_A-Za-z0-9]*

%%

"="                  { printf("assignment "); return(ASSGNOP); }
">="                 { printf(">= "); return(MAIORIGUAL); }
"\"".*"\""           { printf("string "); yylval.ystr = stringpool(yytext);  return(VSTR); }
"true"|"false"       { printf("boolean ");  yylval.ybool = yytext == "true"; return(VBOOL); }
{DIGIT}+             { printf("integer "); yylval.yint = atoi(yytext);  return(VINT); }
{DIGIT}*"."{DIGIT}+  { printf("float "); yylval.yfloat = atof(yytext);  return(VFLOAT); }
let                  { printf("let "); return(DLET); }
const                { printf("const "); return(DCONST); }
var                  { printf("var "); return(DVAR); }
{ID}                 { printf("identifier "); yylval.ystr = stringpool(yytext);  return(IDENTIFIER); }
"\n"                 { printf("\n");}
"//"[A-Za-z0-9_ ]* {printf("inline comment "); }
"/*"[A-Za-z0-9_ \n\r]*"*/" {printf("block comment "); }
[ \t]+ /* blank, tab, new line: eat up whitespace */
.                    { printf("%c",yytext[0]); return(yytext[0]); }

%%
