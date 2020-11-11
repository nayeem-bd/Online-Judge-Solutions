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
#define pdd pair<double,double>
#define pdi pair<double,pii>
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

vector<pdd>vec;
vector<pdi>edge;

int parent[105];

void make_parent()
{
    for(int i=0;i<105;i++){
        parent[i]=i;
    }
}

int find_ref(int r)
{
    if(parent[r]==r)return r;
    return parent[r]=find_ref(parent[r]);
}

double kruskal()
{
    sort(all(edge));
    double ans = 0.0;
    for(int i=0;i<edge.size();i++){
        int u,v;
        u = find_ref(edge[i].vv.uu);
        v = find_ref(edge[i].vv.vv);

        if(u!=v){
            parent[u] = v;
            ans += edge[i].uu;
        }
    }
    return ans;
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

    int t;
    cin>>t;
    while(t--){
        make_parent();
        edge.clear();
        vec.clear();
        double a,b,c,w;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            vec.pb(pdd(a,b));
        }

        int i,j;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                w = sqrt((vec[i].uu-vec[j].uu)*(vec[i].uu-vec[j].uu)+(vec[i].vv-vec[j].vv)*(vec[i].vv-vec[j].vv));
                edge.pb(pdi(w,pii(i,j)));
            }
        }
        printf("%0.2f\n",kruskal());
        if(t>0)pn;
    }



    return 0;
}









