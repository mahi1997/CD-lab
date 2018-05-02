#include <bits/stdc++.h>
using namespace std;

int i;
string inp;
bool term(char s ){
	return (inp[i++]==s);
}

bool S(){
   int save=i;
   
   return ((i=save, term('a') &&S()&&term('b')&&S())
          ||(i=save, term('b') &&S()&&term('a')&&S())
          ||(i=save, term('a') &&S()&&term('b'))
          ||(i=save, term('a') &&term('b')&&S())
          ||(i=save, term('a') &&term('b'))
          ||(i=save, term('b') &&term('a')&&S())
          ||(i=save, term('b') &&S()&&term('a'))
          ||(i=save, term('b') &&term('a'))


          );

}



int main(){
	//string inp;
	while(1){
	cout<<"Enter input"<<endl;
	cin>>inp;
	i=0;
	
	if(S() &&(i==inp.length())){
		cout<<"accepted"<<endl;
	}
	else{
		cout<<"rejected"<<endl;
	}
}
return 0;

}