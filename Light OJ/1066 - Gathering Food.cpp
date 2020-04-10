#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define uu first
#define vv second
 
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
char ch[15][15],ch2[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int cell[15][15],d[15][15];
int row,col,p,f,s;
int vis[15][15];
 
void bfs(int sx,int sy,int dx,int dy )
{
    memset(vis,0,sizeof vis);
    memset(d,0,sizeof d);
    vis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            int tx = top.uu + fx[k];
            int ty = top.vv + fy[k];
            if(tx>=0 and tx<col and ty>=0 and ty<row and vis[tx][ty]==0 and cell[tx][ty]!=-1)
            {
                if(ch[tx][ty]=='.'){
                    q.push(pii(tx,ty));
                    d[tx][ty] += d[top.uu][top.vv]+1;
                    vis[tx][ty]=1;
 
                }
                if(tx==dx and ty==dy){
                    d[tx][ty] += d[top.uu][top.vv]+1;
                    ch[sx][sy]='.';
                    return ;
                }
 
            }
        }
    }
}
 
int main()
{
    int t,l;
    scanf("%d",&t);
    for(l=1; l<=t; l++)
    {
        p=0,s=0,f=1;
        memset(cell,0,sizeof (cell));
        int n,i,j,m,t,dis=0;
        pii v[26];
        scanf("%d",&n);
        row=n,col=n;
        for(i=0; i<n; i++)
        {
            scanf("%s",ch[i]);
 
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(ch[i][j]=='#')
                {
                    cell[i][j]=-1;
                }
//                if(ch[i][j]=='A')
//                {
//                    m=i,t=j;
//                }
             else  if(ch[i][j]>='A' && ch[i][j]<='Z')
                {
                    p++;
                    v[ch[i][j]-'A'] = pii(i,j);
 
                }
            }
        }
       for(i=0;i<p-1;i++){
            bfs(v[i].uu,v[i].vv,v[i+1].uu,v[i+1].vv);
            if(d[v[i+1].uu][v[i+1].vv]==0){
                f=0;break;
            }
            dis += d[v[i+1].uu][v[i+1].vv];
       }
        printf("Case %d: ",l);
        if(f==0)
            printf("Impossible\n");
        else
            printf("%d\n",dis);
    }
 
    return 0;
}
