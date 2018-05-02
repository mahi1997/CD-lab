#include<bits/stdc++.h>

#include<string.h>
using namespace std;
char *input;
int i=0;
char lasthandle[9],stack1[50],handles[][8]={")E(","E*E","E+E","E-E","E/E","E-","i","E^E"};
//(E) becomes )E( when pushed to stack1

int top=0,l;
char prec[9][9]={

                            /*input*/

            /*stack1    +    -   *   /   ^   i   (   )   $  */

            /*  + */  '>', '>','<','<','<','<','<','>','>',

            /*  - */  '>', '>','<','<','<','<','<','>','>',

            /*  * */  '>', '>','>','>','<','<','<','>','>',

            /*  / */  '>', '>','>','>','<','<','<','>','>',

            /*  ^ */  '>', '>','>','>','<','<','<','>','>',

            /*  i */  '>', '>','>','>','>','e','e','>','>',

            /*  ( */  '<', '<','<','<','<','<','<','>','e',

            /*  ) */  '>', '>','>','>','>','e','e','>','>',

            /*  $ */  '<', '<','<','<','<','<','<','<','>',

                };

int getindex(char c)
{
switch(c)
    {
    case '+':return 0;
    case '-':return 1;
    case '*':return 2;
    case '/':return 3;
    case '^':return 4;
    case 'i':return 5;
    case '(':return 6;
    case ')':return 7;
    case '$':return 8;
    }
}


int shift()
{
stack1[++top]=*(input+i++);
stack1[top+1]='\0';
}


int reduce()
{
int i,len,found,t;
for(i=0;i<8;i++)//selecting handles
    {
    len=strlen(handles[i]);
    if(stack1[top]==handles[i][0]&&top+1>=len)
        {
        found=1;
        for(t=0;t<len;t++)
            {
            if(stack1[top-t]!=handles[i][t])
                {
                found=0;
                break;
                }
            }
        if(found==1)
            {
            stack1[top-t+1]='E';
            top=top-t+1;
            strcpy(lasthandle,handles[i]);
            stack1[top+1]='\0';
            return 1;//successful reduction
            }
        }
   }
return 0;
}



void dispstack1()
{
int j;
for(j=0;j<=top;j++)
    printf("%c",stack1[j]);
}



void dispinput()
{
int j;
for(j=i;j<l;j++)
    printf("%c",*(input+j));
}



int main()
{
int j;

input=(char*)malloc(50*sizeof(char));
printf("\nEnter the string\n");
scanf("%s",input);
input=strcat(input,"$");
l=strlen(input);
strcpy(stack1,"$");
printf("\nstack1\tINPUT\tACTION");
while(i<=l)
  {
  shift();
  printf("\n");
  dispstack1();
  printf("\t");
  dispinput();
  printf("\tShift");
  if(prec[getindex(stack1[top])][getindex(input[i])]=='>')
    {
    while(reduce())
      {
      printf("\n");
      dispstack1();
      printf("\t");
      dispinput();
      printf("\tReduced: E->%s",lasthandle);
      }
    }
  }

if(strcmp(stack1,"$E$")==0)
    printf("\nAccepted\n");
else
    printf("\nNot Accepted\n");
  return 0;
}