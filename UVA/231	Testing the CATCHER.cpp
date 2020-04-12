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

//ll modPower(ll x, ll y, ll p){ll res = 1;x = x % p;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
//ll power(ll a,ll b){if(b==0)return 1;ll x=power(a,b/2);x=(x*x);if(b&1)x=(x*a);return x;}

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

int n,m,j,l;
vector<int>ve;
int dp[2005];
int LIS(int u)
{
    if(dp[u]!=-1)return dp[u];
    int maxi=0,i;
    for(i=u+1;i<l;i++){
        if(ve[i]<=ve[u]){
            maxi = max(maxi,LIS(i));
        }
    }
    return dp[u]=1+maxi;
}

int maintain()
{
    int maxi=1;
    for(int i=0;i<l;i++){
        maxi= max(maxi,LIS(i));
    }
    return maxi;
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
    int cs=1,f=0;
    while(1){
        sci(n);
        if(n==-1)break;
        if(f==1)pn;
        f=1;
        ve.clear();
        ms(dp,-1);
        while(n!=-1){
           ve.pb(n);
           sci(n);
        }
        l=ve.size();
        int ans = maintain();
        printf("Test #%d:\n  maximum possible interceptions: %d\n",cs++,ans);
    }

    return 0;
}

