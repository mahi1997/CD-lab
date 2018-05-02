%{
#include<stdio.h>
%}
%token ID
%left '+'
%left '.'
%left '*'
%%

E:  {printf("E==> $E+T \n");} E '+' {printf("E==> E+$T \n");} T  
    |{printf("E==> $E+T \n");} E '-' {printf("E==> E-$T \n");} T 
    |{printf("E==> $T \n");} T     
    ;

T:  T '*' F   {printf("*");}
    | T '/' F {printf("/");}
    | F
    ;     

F:  '(' E ')'
    | ID {printf("%d",yylval);}
    ;   

%%

int main(){
    yyparse();
    printf("\n");
}

int yyerror (char *msg) {
    return printf ("error YACC: %s\n", msg);
}