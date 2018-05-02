%{
extern int yylval;
#include "y.tab.h"
%}

%%

[0-9]+  {yylval = atoi(yytext);return INTEGER;}
\n { return(0); }
[ \t\n]     /* skip whitespace */
.   {return *yytext;}
%%

int yywrap(void) {
return 1;
}