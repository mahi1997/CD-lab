#include <bits/stdc++.h>
using namespace std;

int i;
string inp;
bool term(char s ){
	return (inp[i++]==s);
}

pair<bool,vector<string> > S(vector<string> tr){
   int save=i;
   vector<string> trr=tr;
   pair<bool,vector<string> > A;
   pair<bool,vector<string> >  t1;
   pair<bool,vector<string> >  t2;

   if((i=save, term('a') &&(t1=S(trr) ,t1.first)&&term('b')&&(t2=S(trr) ,t2.first))){

    for(int v=0;v<t1.second.size();v++){
      t2.second.push_back(t1.second[v]);
    }
    t2.second.push_back("->aSbS");

    A.first=true;
    A.second=t2.second;

    return A;
   }
   

   if((i=save, term('b') &&(t1=S(trr) ,t1.first)&&term('a')&&(t2=S(trr) ,t2.first))){
   
   for(int v=0;v<t1.second.size();v++){
      t2.second.push_back(t1.second[v]);
    }
    t2.second.push_back("->bSaS");

    A.first=true;
    A.second=t2.second;

    return A;

   }

   if((i=save, term('a') &&(t1=S(trr) ,t1.first)&&term('b'))){
   t1.second.push_back("->aSb");

    A.first=true;
    A.second=t1.second;

    return A;
   }
   if((i=save, term('a') &&term('b')&&(t1=S(trr) ,t1.first))){
   t1.second.push_back("->abS");


    A.first=true;
    A.second=t1.second;

    return A;
   }
   if((i=save, term('a') &&term('b'))){
    trr.push_back("->ab");


    A.first=true;
    A.second=trr;

    return A;
   }

   if((i=save, term('b') &&term('a')&&(t1=S(trr) ,t1.first))){
   t1.second.push_back("->baS");


    A.first=true;
    A.second=t1.second;


    return A;

   }

   if((i=save, term('b') &&(t1=S(trr) ,t1.first)&&term('a'))){
   t1.second.push_back("->bSa");

    A.first=true;
    A.second=t1.second;

    return A;
   }

   if((i=save, term('b') &&term('a'))){
    trr.push_back("->ba");


    A.first=true;
    A.second=trr;

    return A;
   }
   else{
    A.first=false;
    A.second=trr;

    return A;
   }



   





   //return A;

  

}

int main(){
	//string inp;
	while(1){
	cout<<"Enter input"<<endl;
	cin>>inp;
	i=0;

	vector<string> tr;
	pair<bool,vector<string> > B =S(tr);
	if(B.first && (i==inp.length()) ){
		cout<<"accepted "<<i<<" tree is "<<endl;
		cout<<"S";
		vector<string> tr1 =B.second;
		for(int m=tr1.size()-1;m>=0;m--){
			cout<<tr1[m];
		}
	}
	else{
		cout<<"rejected  "<<i<<endl;
	}
}
return 0;

}