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
#define scl(x) scanf("%lld",&x)
#define scll(x,y) scanf("%lld %lld",&x,&y)
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
int n,k,i,j,l;
int ara[505];
int dp[505][505];
int solve(int st,int r_s)
{
    if(dp[st][r_s]!=-1)return dp[st][r_s];
    int ret1=0,ret2=INT_MAX,black=0,white=0;
    for(int i=st;i<=n-r_s;i++){
        if(ara[i]==0){
            white++;
        }
        else{
            black++;
        }
        if(r_s>1){
            ret1=solve(i+1,r_s-1);
            ret2 = min(ret2,(black*white) + ret1);
        }
    }
    if(r_s==1){
        return dp[st][r_s]=black*white;
    }
    return dp[st][r_s]=ret2;
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
    scii(n,k);
    ms(dp,-1);
    for(i=0;i<n;i++){
        sci(ara[i]);
    }
    cout<<solve(0,k)<<endl;

    return 0;
}

