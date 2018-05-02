%{
    int i=1;
%}
%%
[a-z A-Z]+ {printf("%d:%s",i,yytext);i++;}
%%

int main()
{
extern FILE *yyin;
yyin=fopen("myfile.txt","r");
yylex();
}
