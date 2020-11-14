/*
                    NAYEEM
    Information and Communication Engineering ,
            University of Rajshahi
*/
#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

#define sci(x) scanf("%d",&x)
#define scii(x,y) scanf("%d %d",&x,&y)
#define scll(x,y) scanf("%lld %lld",&x,&y)
#define scl(x) scanf("%lld",&x)
#define scd(x) scanf("%lf",&x)

#define pfi(x) printf("%d",x)
#define pfl(x) printf("%lld",x)
#define pfd(x) printf("%lf",x)
#define pfc(x) printf("Case %d: ",x)
#define ps printf(" ")
#define pn printf("\n")
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define pf(x) push_front(x)
#define ppf(x) pop_front(x)
#define in(x,y) insert({x,y})
#define sv(a) sort(a.begin(),a.end())
#define ms(arr,a) memset(arr,a,sizeof arr)
#define mx 1005
#define TestCase int t,cs=1;sci(t);while(t--)
#define PI 2*acos(0.0)

//ll modPower(ll x,ll y,ll p){ll res=1LL;x=x%p;while(y>0{if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
//ll power(ll a,ll b){if(b==0)return 1;ll x=power(a,b/2);x=(x*x);if(b&1)x=(x*a);return x;}

/*---------------------Direction Array----------------------*/

//int fx[]={0,1,1,1,0,-1,-1,-1};    //8-side move
//int fy[]={1,1,0,-1,-1,-1,0,1};
//int fx[]={1,-1,0,0};              //4-side move
//int fy[]={0,0,1,-1};
//int fx[]={2,1,-1,-2,-2,-1,1,2};   //knight move
//int fy8]={1,2,2,1,-1,-2,-2,-1};

/*----------------------------------------------------------*/

/*--------------------------BitMask-------------------------*/

//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}

/*---------------------------------------------------------*/

set<pii>st;
set<pii>::iterator it;
int d[10005],low[10005],vis[10005],tme,parent[10005];

void find_articulation(vector<int>adj[],int u)
{
    tme++;
    d[u]=tme;
    low[u]=tme;
    vis[u]=1;

    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(v == parent[u])continue;
        if(vis[v]){
            low[u] = min(low[u],d[v]);
        }
        else{
            parent[v] = u;
            find_articulation(adj,v);
            low[u] = min(low[u],low[v]);
            if(d[u]<low[v]){
                st.insert(pii(min(u,v),max(u,v)));
            }
        }
    }

}

int main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    /*
        Check Contains Limit && Declear Counter in Long Long
        Check Array Size
    */
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m,i,j,k,l,u,v;
        scanf("%d",&n);
        vector<int>adj[n+1];
        for(i=0;i<n;i++){
            scanf("%d (%d)",&u,&m);
            for(j=0;j<m;j++){
                scanf("%d",&v);
                adj[u].pb(v);
            }
        }
        for(i=0;i<=n;i++){
            d[i]=0;
            low[i]=0;
            parent[i]=i;
            vis[i]=0;
        }
        tme = 0;
        st.clear();
        for(i=0;i<=n;i++){
            if(!vis[i]){
                find_articulation(adj,i);
            }
        }
        printf("Case %d:\n%d critical links\n",cs++,st.size());
        for(it=st.begin();it!=st.end();it++){
            pii ans = *it;
            printf("%d - %d\n",ans.uu,ans.vv);
        }

    }




    return 0;
}









