%{
#include<stdio.h>
int state=0;
%}

%%
[a-zA-Z]([a-zA-Z]|[0-9])*([^a-zA-Z0-9]) state=1;
.* state=0;
%%


int main(void)
{
yyin= fopen("test2.txt","r");
yylex();
if(state)
printf("Accepted %d",state);
else
printf("\nNot Accepted");
fclose(yyin);
}
 
int yywrap()
{
return(1);
}
