%{
#include "parser.tab.h"
char *stringpool(char *);
%}
%option yylineno

DIGIT    [0-9]
ID       [_a-zA-Z][_A-Za-z0-9]*

%%

"="                  { printf("assignment "); return(ASSGNOP); }
">="                 { printf(">= "); return(EXPGT); }
"<="                 { printf("<= "); return(EXPLT); }
"=="                 { printf("== "); return(EXPEQ); }
"!="                 { printf("!= "); return(EXPDF); }
"||"                 { printf("|| "); return(LOGOR); }
"&&"                 { printf("&& "); return(LOGAND); }
"=>"                 { printf("=> "); return(DAFUNC); }
";"                  { printf(";"); return(SEMICOLON); } 
"??"                 { printf("null-coalescing "); return(NULLCOALESCING); }
"\""[_A-Za-z0-9 ]*"\""           { printf("string "); yylval.ystr = stringpool(yytext);  return(VSTR); }
"\'"[_A-Za-z0-9]*"\'"          { printf("string "); yylval.ystr = stringpool(yytext);  return(VSTR); }
"true"|"false"       { printf("boolean ");  yylval.ystr = stringpool(yytext); return(VBOOL); }
{DIGIT}+             { printf("integer "); yylval.ystr = stringpool(yytext);  return(VINT); }
{DIGIT}*"."{DIGIT}+  { printf("float "); yylval.ystr = stringpool(yytext);  return(VFLOAT); }
if                   { printf("if "); return(CIF); }
else                 { printf("else "); return(CELSE); }   
let                  { printf("let "); return(DLET); }
const                { printf("const "); return(DCONST); }
var                  { printf("var "); return(DVAR); }
of                   { printf("of "); return(LOF); }
in                   { printf("in "); return(LIN); }
for                  { printf("for "); return(LFOR);}
while                { printf("while "); return(LWHILE);}
function             { printf("function "); return(DFUNC); }
return               { printf("return "); return(FRETURN); }
continue             { printf("return "); return(FCONTINUE); }
break                { printf("return "); return(FBREAK); }
{ID}                 { printf("identifier "); yylval.ystr = stringpool(yytext);  return(IDENTIFIER); }
"\n"                 { printf("\n");}
"//"[A-Za-z0-9_ ]*   {printf("inline comment "); return(CINLINE); }
"/*"[A-Za-z0-9_ \n\r]*"*/" {printf("block comment "); return(CBLOCK); }
[ \t]+ /* blank, tab, new line: eat up whitespace */
.                    { printf("%c ",yytext[0]); return(yytext[0]); }

%%
