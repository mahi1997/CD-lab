#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

bool isFinal(char c, char* fin,int N){
    bool found=false;
    for(int i=0;i<N;i++){
        if(fin[i]==c){
            found= true;
            break;
        }
    }
    return found;
}

int main(){

    int m=0,n=0;
    // m states and n input symbols
    cout<<"Enter #states  and #symbol..\n";
    cin>>m>>n;
    char states[m];
    cout<<"Enter states..\n";
    for (int i=0;i<m;i++)
        cin>>states[i];
    
    char sym[n];
    cout<<"Enter symbols..\n";
    for (int i=0;i<n;i++)
        cin>>sym[i];

    cout<<"Enter table entry..\n";
    char st[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>st[i][j];

    //char cst=states[0];
    cout<<"Enter Number of final states..\n";
    int f;
    cin>>f;
    char fst[f];
    cout<<"Enter final states..\n";
    for(int i=0;i<f;i++)
    cin>>fst[i];

    cout<<"print table..\n";
    for(int i=0;i<m;i++)
        {for(int j=0;j<n;j++)
            cout<<st[i][j]<<"       ";
        cout<<endl;
        }


    

    cout<<"---------------------------------"<<endl;
    while(true){
        char cst=states[0];
        
        string str="A";
        
       
    //string str=states[0].toString();
    // symbol input
    cout<<"Enter input string..\n";
    // here $ means blank

    string S;
    cin>>S;
    int l=S.length();
    char instring[l];
    strcpy(instring, S.c_str());
    int k=0;
    bool accept= false;

    while(k<l){

        //int nst;
        //cin>>nst;

        cst=st[(int)((int)cst-(int)(states[0]))][(int)(instring[k])-(int)(sym[0])];
        if(cst!='$'){

        str=str+" -> " +cst;
        cout<<str;
        if(isFinal(cst,fst,f)==true){accept=true;cout<<" final state";}
        else
            accept=false;
        cout<<endl;
        k++;
         }
        else {
            accept=false;
        cout<<"reached dead state..\n";
        k=l;
        //break;

        }

        



    }
    if(accept==true)
        cout<<"\n Finally accepted..! \n";
    else
        cout<<"\n Finally rejected..! \n";
}
    return 0;



}


