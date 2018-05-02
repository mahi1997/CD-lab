#include <bits/stdc++.h>
using namespace std;

int i;
int N;
bool cov=false;

string inp;
bool term(char s ){
	if(inp[i++]==s){
		if(i==N) cov=true;

		cout<<"match found at: "<<i-1<<endl;
		return true;
	}
	else
		return false;
}

pair<bool,vector<string> > S(vector<string> tr){
   int save=i;
   vector<string> trr=tr;
   pair<bool,vector<string> > A;
   pair<bool,vector<string> >  t1;
   
   if((i=save, term('a') &&(t1=S(trr) ,t1.first )&&term('a'))){
   	// vector<string> t11=t1.second;
   	//t1.second.push_back("->aSa");
    A.first=true;
    A.second=t1.second;
    return A;
   }
   else{
   	if((i=save, term('a') &&term('a'))){
     trr.push_back("->aa");
    A.first=true;
    A.second=trr;
    return A;
   	}
   	else{
    A.first=false;
    A.second=trr;
    return A;
   	}
   }
   

  

}

int main(){
	//string inp;
	while(1){
	cout<<"Enter input"<<endl;
	cin>>inp;
	i=0;
    N=inp.length();
	vector<string> tr;
	pair<bool,vector<string> > B =S(tr);
	if(B.first && cov ){
		cout<<"accepted "<<i<<" tree is "<<endl;
		cout<<"S";
		vector<string> tr1 =B.second;
		for(int m=0;m<tr1.size();m++){
			cout<<tr1[m];
		}
	}
	else{
		cout<<"rejected  "<<i<<endl;
	}
}
return 0;

}