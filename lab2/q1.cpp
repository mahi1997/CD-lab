#include<bits/stdc++.h>
using namespace std;
int vis[100],adj[10002][102],v[100];
string s1[10003];
vector<int>a[100][100];
int n,m;
void dfs(int mask,int i)
{
    if(adj[mask][i]!=-1)return ;
    for(int j=0;j<n;j++)vis[j]=0;
    for(int j=0;j<n;j++)
    {
        if(mask&(1<<j))
        {
            for(int k=0;k<a[j][i].size();k++)vis[a[j][i][k]]=1;
        }
    }
    int nxt=0;
    for(int j=0;j<n;j++)
    {
        if(vis[j]==1)nxt+=(1<<j);
    }
    adj[mask][i]=nxt;
    for(int j=0;j<m;j++)dfs(nxt,j);

}
int main()
{
    cout<<"Enter the number of state"<<endl; 
    cin>>n;
    cout<<"Enter the number of symbol"<<endl; 
    cin>>m;
    cout<<"Enter Transitions"<<endl; 
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<m;j++)adj[i][j]=-1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            while(x!=-1)
            {
                a[i][j].push_back(x);
                cin>>x;
            }
        }
    }
    cout<<"Enter no of final states"<<endl;
    int noe;
    cin>>noe;
    for(int i=1;i<=noe;i++)
    {
        int x;
        cin>>x;
        v[x]=1;
    }
    for(int i=0;i<m;i++)dfs(1,i);
    vector<string>v1;
    int cnt=0;
    for(int i=0;i<(1<<n);i++)
    {
        if(adj[i][0]!=-1)
        {
            cnt++;
            bool bl=false;
            string str="{";
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j)){str+=(char)('0'+j);str+=',';if(v[j])bl=true;}
            }
            str+="}";
            s1[i]=str;
            if(bl)v1.push_back(s1[i]);
        }
    }
    int no_end=v1.size();
    cout<<"NO of state "<<cnt<<endl;
    cout<<"Start state {0}"<<endl;
    cout<<"NO of final states "<<no_end<<endl;
    for(int i=0;i<no_end;i++)cout<<v1[i]<<" "<<endl;
    for(int i=0;i<(1<<n);i++)
    {
        if(adj[i][0]!=-1)
        {
            cout<<s1[i]<<" -> ";
            for(int j=0;j<m;j++)cout<<s1[adj[i][j]]<<" ";
            cout<<endl;
        }
    }

}