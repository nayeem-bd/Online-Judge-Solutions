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

int n,m;
struct node
{
    int a,b,c;
}edge[205];

bool cmp(node a,node b)
{
    return a.c<b.c;
}
int parent[105],edg;
vector<int>va;

void makeset()
{
    for(int i=0;i<105;i++)parent[i]=i;
}

int find_ref(int r)
{
    if(parent[r]==r)return r;
    return parent[r]=find_ref(parent[r]);
}

int kruskal()
{
	makeset();
    int ans=0;
    for(int i=0;i<m;i++){
        int u,v;
        u = find_ref(edge[i].a);
        v = find_ref(edge[i].b);
        if(u!=v){
            edg++;
            parent[u]=v;
            ans += edge[i].c;
            va.pb(i);
            if(edg==n-1)break;
        }
        
    }
    return ans;
}

int kruskal2(int i,int sum)
{
    int u,v;
    u = find_ref(edge[i].a);
    v = find_ref(edge[i].b);
    if(u!=v){
        parent[u]=v;
        sum += edge[i].c;
        edg++;
    }
    return sum;
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

    int t,cs=1;
    cin>>t;
    while(t--){
    	va.clear();
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>edge[i].a>>edge[i].b>>edge[i].c;
        }
        sort(edge,edge+m,cmp);
        edg = 0;
        int mst = kruskal();
        if(edg != n-1){
            printf("Case #%d : No way\n",cs++);
        }
        else{
            int i,j,k,smst,ans = INT_MAX,flag=0;
            for(i=0;i<va.size();i++){
                k = va[i];
                edg = 0;
                smst = 0;
                makeset();
                for(j=0;j<m;j++){
                    if(k!=j){
                        smst = kruskal2(j,smst);
                        if(edg == n-1)break;
                    }
                }
                if(edg == n-1){
                    ans = min(ans,smst);
                    flag = 1;
                }
            }
            if(flag == 0){
                printf("Case #%d : No second way\n",cs++);
            }
            else{
                printf("Case #%d : %d\n",cs++,ans);
            }
        }

    }




    return 0;
}









