#include<bits/stdc++.h>

#include<string.h>
using namespace std;
char *input;
int i=0;
char lasthandle[5],stack1[50];
vector<string> handles;
handles.push_back("E");
handles.push_back("E+T");
handles.push_back("T");
handles.push_back("i");
//(E) becomes )E( when pushed to stack1

int top=0,l;



int shift(int si)
{
stack1[++top]=*(input+i++);
stack1[top+1]='\0';
}


int reduce(int ri )
{
int len,found,t;

    len=strlen(handles[ri]);
    if(stack1[top]==handles[ri][0]&&top+1>=len)
        {
        found=1;
        for(t=0;t<len;t++)
            {
            if(stack1[top-t]!=handles[ri][t])
                {
                found=0;
                break;
                }
            }
        if(found==1)
            {
            stack1[top-t+1]='S';  //E
            top=top-t+1;
            strcpy(lasthandle,handles[ri]);
            stack1[top+1]='\0';
            return 1;//successful reduction
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