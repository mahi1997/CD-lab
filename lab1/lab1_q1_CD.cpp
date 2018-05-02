#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string S;
	cin>>S;
	int n=S.length();
	cout<<"string length:"<< n<<endl;
	cout<<"SYMBOL  --- next state -- Accept/reject"<<endl;
	char instring[n];
	strcpy(instring, S.c_str());
	
	char currstate='A';
	char finstate='E';
	for(int i=0;i<n;i++){
	    switch(currstate){
	        case 'A':
	        switch(instring[i]){
	            case '0' :
	            currstate='B';
	            cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            case  '1':
	            currstate='A';
	             cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            case  '2':
	            currstate='B';
	             cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            default:
	            cout<<"Wrong input \n";
	            i=n;
	            break;
	            
	        }
	        break;
	        case 'B':
	        switch(instring[i]){
	            case '0' :
	            currstate='E';
	            cout<<instring[i] <<"  --  "<<currstate<<"  acepted\n";
	            break;
	            case  '1':
	            currstate='A';
	             cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            case  '2':
	            currstate='C';
	             cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            default:
	            cout<<"Wrong input \n";
	            i=n;
	            break;
	        }
	        break;
	        case 'C':
	        switch(instring[i]){
	            case '0' :
	            currstate='A';
	            cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            case  '1':
	            currstate='E';
	             cout<<instring[i] <<"  --  "<<currstate<<"  accepted\n";
	            break;
	            case  '2':
	            currstate='D';
	             cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            default:
	            cout<<"Wrong input \n";
	            i=n;
	            break;
	            
	        }
	        break;
	        case 'D':
	        switch(instring[i]){
	           case '0' :
	            currstate='C';
	            cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            case  '1':
	            currstate='D';
	             cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            case  '2':
	            currstate='E';
	             cout<<instring[i] <<"  --  "<<currstate<<"  accepted\n";
	            break;
	            default:
	            cout<<"Wrong input \n";
	            i=n;
	            break;
	            
	        }
	        break;
	        case 'E':
	        switch(instring[i]){
	           case '0' :
	            currstate='E';
	            cout<<instring[i] <<"  --  "<<currstate<<"  accepted\n";
	            break;
	            case  '1':
	            currstate='D';
	             cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            case  '2':
	            currstate='A';
	             cout<<instring[i] <<"  --  "<<currstate<<"  rejected\n";
	            break;
	            default:
	            cout<<"Wrong input \n";
	            i=n;
	            break;
	            
	        }
	        break;
	        default:
	        cout<<"wrong happened\n";
	        i=n;
	        break;
	        
	    }
	}
	if(currstate=='E')
	cout<<"Finally accepted...";
	else
	cout<<"Finally rejected ...";
	
	
	return 0;
}
