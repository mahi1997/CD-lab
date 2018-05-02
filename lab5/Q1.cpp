#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
	map<char, vector<string>  > cfg;
	int n;
	cout<<"Enter # of non terminal "<<endl;
    cin>>n;
    char nonT[n];
    int m;
    cout<<"Enter # of CFG rules"<<endl;
    cin>>m;
    int j=0;
    for(int i=0;i<m;i++){
    	string R;
    	cin>>R;
    	map<char,vector<string> >::iterator it;
    	it=cfg.find(R[0]);
    	if (it != cfg.end()){
        //insert new non terminal
        nonT[j]=R[0];

        j++;
        cfg.find(R[0])->second.push_back(R.substr(2,R.length()-2));

    	}
    	else{
    	
        // insert rule for existing non terminal
    		cfg.find(R[0])->second.push_back(R.substr(2,R.length()-2));
    	}
        

    }

    //////////////////////////////////////////
    //printing
    for (auto u: cfg){
    	cout<<u.first<<endl;
    }

return 0;
}
