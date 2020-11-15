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
#define md 1000000007
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

ll cost[100005],n,m,vis[100005],visited[100005];
vector<ll>adj[100005],revadj[100005],components[100005];
stack<ll>stk;
void dfs(ll u)
{
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if(vis[adj[u][i]]==0){
            dfs(adj[u][i]);
        }
    }
    stk.push(u);
    return;
}

void dfs2(ll u,int pos)
{
    components[pos].pb(cost[u]);
    visited[u]=1;
    for(int i=0;i<revadj[u].size();i++){
        if(visited[revadj[u][i]]==0){
            dfs2(revadj[u][i],pos);
        }
    }
    return;
}

pll findSCC()
{
    ms(vis,0);
    ms(visited,0);
    int pos = 0;

    for(ll i = 1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }

    while(!stk.empty()){
        ll u = stk.top();
        stk.pop();
        if(visited[u]==0){
            dfs2(u,pos);
            pos++;
        }
    }
    ll ans = 0,comb = 1;
    for(int i=0;i<pos;i++){
        ll mn = INT_MAX,cnt = 0;
        for(int j = 0;j<components[i].size();j++){
            mn = min(mn,components[i][j]);
        }
        for(int j = 0;j<components[i].size();j++){
            if(mn==components[i][j])cnt++;
        }
        //ans = ((ans%md)+(mn%md))%md;
        ans++;
        comb = ((comb%md)*(cnt%md))%md;
    }
    return pll(ans,comb);
}

int main()
{
    //IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    /*
        Check Contains Limit && Declear Counter in Long Long
        Check Array Size
    */

    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>cost[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        revadj[v].pb(u);
    }

    pll ans = findSCC();
    cout<<ans.uu<<" "<<ans.vv<<endl;
    return 0;
}









