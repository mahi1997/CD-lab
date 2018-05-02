%{
extern int yylval;
#include "y.tab.h"
%}

%%

[a-zA-Z]  {yylval = yytext;return ID;}
\n { return(0); }
[ \t\n]     /* skip whitespace */
.   {return *yytext;}
%%

int yywrap(void) {
return 1;
}