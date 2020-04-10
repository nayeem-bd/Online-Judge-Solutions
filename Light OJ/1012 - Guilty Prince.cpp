#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mx 25
#define uu first
#define vv second
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int cell[mx][mx];
int vis[mx][mx],d[mx][mx];
int row,col;
int cnt;
void bfs(int sx,int sy)
{
    memset(vis,0,sizeof (vis));
   // memset(d,0,sizeof (d));
    vis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        //cnt++;
        for(int k=0;k<4;k++)
        {
            int tx=top.uu+fx[k];
            int ty=top.vv+fy[k];
            if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                cnt++;
                d[tx][ty]=d[top.uu][top.vv]+1;
                q.push(pii(tx,ty));
            }
        }
    }
 
}
 
int main()
{
    int t,k;
    scanf("%d",&t);
    for(k=1;k<=t;k++){
        cnt = 0;
        memset(cell,0,sizeof(cell));
        int r,c,i,j,x,y;
        scanf("%d %d",&c,&r);
        char ch[r+1][c+1];
        for(i=0;i<r;i++){
            scanf("%s",ch[i]);
        }
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
               if(ch[i][j]=='#')cell[i][j]=-1;
               if(ch[i][j]=='@'){
                x = j;
                y = i;
               }
            }
        }
        row = r;
        col = c;
        bfs(y,x);
        printf("Case %d: %d\n",k,cnt+1);
 
    }
    return 0;
}
