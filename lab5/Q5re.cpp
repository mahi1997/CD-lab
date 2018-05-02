#include<bits/stdc++.h>
#include <vector>
#include<string.h>
using namespace std;
char *input;
int i=0;
int act=-1;
int curr_state=0;
char stack1[50];
string lasthandle;
vector< string > handles;
handles.push_back("E");
handles.push_back("E+T");
handles.push_back("T");
handles.push_back("i");

//(E) becomes )E( when pushed to stack1

char terminal[3]={'i','+','$'}
char nonterminal[2]={'E','T'}
/*
ACTION TABLE
accept  0
S3      1
S4      2

R1      3
R2      4
R3      5
else -1
*/
void shift();
int reduce(int);
void takeaction(int);
void gotoaction(int );

int ACTION[6][3]={
   1 , -1 ,-1,
   -1, -1 , 0,
   -1 ,2 ,  4 ,
   -1 , 5 , 5,
   1 , -1 ,-1,
   -1 ,-1 ,3 
}

// GOTO table
int goto1[6][2]={
	1, 2,
	-1 , -1,
	-1 , -1,
	-1 , -1,
	5 , 2 ,
	-1 , -1
}

int top=0,l;


void takeaction(int z){
	switch(z){
		case -1:
		cout<<"Not accepting input\n";
		break;
		case 0 :
		cout<<"accepted\n";
		break;
		case 1 :
		shift();
		curr_state=3;
		break;
		case 2 :
		shift();
		curr_state=4;
		break;
		case 3 :
		reduce(1);
		curr_state=0;
		top=0;
		break;
		case 4 :
		reduce(2);
		curr_state=0;
		top=0;
		break;
		case 5 :
		reduce(3);
		curr_state=0;
		top=0;
		break;
	}
}
void gotoaction(int z){
	switch(z){
		case -1:
		cout<<"Not accepting input\n";
		break;
		
		case 1 :
		shift();
		curr_state=1;
		break;
		case 2 :
		shift();
		curr_state=2;
		break;
		
		case 5 :
		shift();
		curr_state=5;
		
		break;
	}
}
void shift()
{
stack1[++top]=*(input+i++);
stack1[top+1]='\0';
}


int reduce(int ri )
{
int len,found,t;

    len=(handles[ri].length());
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
            lasthandle= handles[ri];
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



int main(){
	input=(char*)malloc(50*sizeof(char));
printf("\nEnter the string\n");
scanf("%s",input);
input=strcat(input,"$");
l=strlen(input);
strcpy(stack1,"$");
shift();

if(stack1[i]=='i' || stack1[i]=='+' ||stack1[i]=='$' ){
  takeaction(ACTION[curr_state][stack1[i]]);
}
if(stack1[i]=='E' || stack1[i]=='T' ){
  gotoaction(goto1[curr_state][stack1[i]]);
}



return 0;
}