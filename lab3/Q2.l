%option noyywrap

%%
[A-Za-z][A-Za-z0-9]*[^A-Za-z0-9 \t\n] {printf("%s : accepted \n",yytext);}
.* {printf("%s : not accepted \n",yytext);}
%%

main()
{
extern FILE *yyin;
yyin=fopen("xyz.txt","r");
yylex();
}
