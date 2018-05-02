%{
#include<stdio.h>
int lines=0, words=0,n_char=0;
%}
%%


 
\n { lines++; words++;}
[\t ' '] {words++;}
[A-Z | a-z | 0-9] {n_char++;}
. n_char++;


%%





main(void)
{
yyin= fopen("abc.txt","r");
yylex();

printf(" This File contains ...");
printf("\n\t%d lines", lines);
printf("\n\t%d words",words);
printf("\n\t%d characters", n_char);

}
 
int yywrap()
{
return(1);
}