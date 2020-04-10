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
#define zero(arr,a) memset(arr,a,sizeof arr)
#define md 100000007
 
int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};
 
ll n,ara[55],make,val[55],dp[55][22][1005];
 
ll coin_count(int i,int amount,int taken_i)
{
    if(i==n){
        if(amount==make){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][taken_i][amount]!=-1)return dp[i][taken_i][amount];
    ll ret1=0,ret2=0;
    if(amount+ara[i]<=make && taken_i<val[i]){
        ret1 = coin_count(i,amount+ara[i],taken_i+1);  
    }
    ret2 = coin_count(i+1,amount,0);
    dp[i][taken_i][amount]=(ret1+ret2)%md;
    return dp[i][taken_i][amount];
}
 
int main()
{
    //IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    int t,cs=1;
    sci(t);
    while(t--){
        int i,j,k;
        memset(dp,-1,sizeof(dp));
        scl( n);scl(make);
        for(i=0;i<n;i++){
            scl(ara[i]);
        }
        for(i=0;i<n;i++){
            scl(val[i]);
        }
        pfc(cs++);
        pfl(coin_count(0,0,0));
        pn;
    }
    return 0;
}
