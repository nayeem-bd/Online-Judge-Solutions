#include<bits/stdc++.h>
using namespace std;
 
vector<int>adj[10005];
int color[10005],p=0;
 
void dfs(int n)
{
    color[n]=1;
    for(int i=0; i<adj[n].size(); i++)
    {
        int v =adj[n][i];
        if(color[v]==0)
        {
            dfs(v);
        }
        else if(color[v]==1)
        {
            p=1;
            return ;
        }
    }
    color[n]=2;
}
int main()
{
    int n,m,i,j,u,v,t,k;
    cin>>t;
    for(k=1; k<=t; k++)
    {
        n = 1;
        p=0;
        for(i=0; i<=10005; i++)
        {
            adj[i].clear();
        }
        map<string,int>mp;
        string s1,s2;
        cin>>m;
        int f=0;
        for(i=0; i<m; i++)
        {
            cin>>s1>>s2;
            if(mp[s1]==0)
                mp[s1]=n++;
            if(mp[s2]==0)
                mp[s2]=n++;
            adj[mp[s1]].push_back(mp[s2]);
        }
        memset(color,0,sizeof color);
        for(i=1; i<n; i++)
        {
 
            dfs(i);
            if(p==1)
            {
                cout<<"Case "<<k<<": No"<<endl;
                f = 1;
                break;
            }
 
        }
        if(f==0)
            cout<<"Case "<<k<<": Yes"<<endl;
    }
    return 0;
}
 
