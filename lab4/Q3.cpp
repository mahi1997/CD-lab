
#include <bits/stdc++.h>
using namespace std;


int i;
vector<string> inp;

vector<string> split( string s, char delimiter)
{
   vector<string> tokens;
   int k=0;
   int N=s.length();
   string tok="";
   while(k<N){
   	if(s[k]==delimiter && tok!="")
   		{tokens.push_back(tok);
   			tok="";}
   	else
   		tok=tok+s[k];
   	k++;
   }

   if(tok!="")
   	tokens.push_back(tok);

   for( int l=0;l<tokens.size();l++){
   	cout<<tokens[l]<<endl;
   }
   return tokens;
}



bool term(string s ){
	return (inp[i++]==s);
}

bool E();
/*
bool F();
bool T1();
bool T();
bool E1();
*/
bool F(){
	int save=i;
	return ((i=save,term("not")&&F())
          ||(i=save,term("(")&& E()&& term(")"))
          ||(i=save,term("true"))
          ||(i=save,term("false"))
          
          );
}

bool T1(){
	int save=i;
	return ((i=save,term("and")&&F()&&T1())
          ||(i=save,term("and")&& F())
          
          );
}

bool T(){
	int save=i;
	return ((i=save,F()&&T1())
          ||(i=save, F())
          
          );

}

bool E1(){
	int save=i;
	return ((i=save,term("or")&&T()&&E1())
          ||(i=save, term("or")&&T())
          
          );
}



bool E(){
	int save=i;
	return ((i=save,T()&&E1())
          ||(i=save, T())
          
          );
}


int main(){
	
	while(1){
	string exp;
	cout<<"Enter input"<<endl;
	getline(cin,exp);
	
	inp=split(exp,' ');
	i=0;

	if(E() &&(i==inp.size())){
		cout<<"accepted"<<endl;
	}
	else{
		cout<<"rejected"<<endl;
	}
	
}
return 0;

}