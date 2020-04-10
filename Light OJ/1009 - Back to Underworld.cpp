#include<bits/stdc++.h>
using namespace std;
#define mx 20005
int visited[mx+1];
vector<int>adj[mx+1];
 
int color[mx+1];
int cnt1,cnt2;
void dfs(int n,int p)
{
    if(visited[n]==1){
        return ;
    }
    visited[n]=1;
    color[n]=p;
    if(p==1)cnt1++;
    else cnt2++;
 
    for(int i=0;i<adj[n].size();i++){
        int u = adj[n][i];
        if(p==1)dfs(u,2);
        else dfs(u,1);
    }
}
int main()
{
    int t,k;
    scanf("%d",&t);
    for(k=1;k<=t;k++){
        cnt1 = 0,cnt2=0;
        for(int i=0;i<=mx;i++){
            adj[i].clear();
            visited[i]=0;
            color[i]=0;
        }
        int n,u,v,i;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ms=0;
        for(i=1;i<=mx;i++){
            if(adj[i].size()>0){
                if(visited[i]!=1){
                        dfs(i,1);
                        ms += max(cnt1,cnt2);
                        cnt1 = 0;
                        cnt2 =0;
                }
            }
        }
        printf("Case %d: %d\n",k,ms);
    }
    return 0;
}
 
