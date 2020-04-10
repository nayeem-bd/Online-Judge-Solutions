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
#define mx 105
 
int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};
 
ll dp[mx][mx];
vector<ll>v[mx];
int r;
 
ll rock_climbing(int i,int j)
{
    if(i>=0 && i<r && j>=0 && j<r){
        if(dp[i][j]!=-1)return dp[i][j];
        ll ret=LLONG_MIN;
        ret = max(ret,rock_climbing(i+1,j)+v[i][j]);
        ret = max(ret,rock_climbing(i,j+1)+v[i][j]);
        dp[i][j]=ret;
        return dp[i][j];
    }
    else return 0;
}
 
int main()
{
    //IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,cs=1;
    sci(t);
    while(t--){
        int n,i,j,l;
        zero(dp,-1);
        for(i=0;i<mx;i++){
            v[i].clear();
        }
        ll val;
        sci(n);
        r = n;
        //cout<<r<<endl;
        for(i=1;i<=n;i++){
            for(j=0;j<i;j++){
                sci(l);
                v[j].pb(l);
            }
        }
        for(i=n-1;i>=1;i--){
            for(j=i;j>=1;j--){
                sci(l);
                v[n-j].pb(l);
            }
        }
        pfc(cs++);pfl(rock_climbing(0,0));pn;
    }
    return 0;
}
 
