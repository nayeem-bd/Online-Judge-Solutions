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

int n,i,j,k,l;
string pl1,pl2;
bool possible;
int dp[1005][1005][2];
vector<int>ans;

int func(int pos_1,int pos_2,int now,int prv)
{
    if(possible)return 0;
    if(pos_1==n && pos_2==n){
        if(pos_1==n && pos_2==n){
                possible=true;
                return 1;
        }
    }
    if(dp[pos_1][pos_2][now]!=-1)return dp[pos_1][pos_2][now];
    int ret1=0,ret2=0,ni=-1;
    if(now==0){
        if(pl1[pos_1]=='0'){
            ret1 = func(pos_1+1,pos_2,now^1,0);
        }
        else{
            ret1 = func(pos_1+1,pos_2,now^1,1);
        }
        if(possible)ans.pb(1);
        if(pl2[pos_2]=='0'){
            ret2 = func(pos_1,pos_2+1,now^1,0);
        }
        else{
            ret2 = func(pos_1,pos_2+1,now^1,1);
        }
        if(possible && !ret1)ans.pb(2);
    }
    else{
        if(prv==0){
            if(pl1[pos_1]-'0'==1){
                ret1 = func(pos_1+1,pos_2,now^1,1);
            }
            if(possible)ans.pb(1);
            if(pl2[pos_2]-'0'==1){
                ret2 = func(pos_1,pos_2+1,now^1,1);
            }
            if(possible && !ret1)ans.pb(2);
        }
        else{
            if(pl1[pos_1]-'0'==0){
                ret1 = func(pos_1+1,pos_2,now^1,0);
            }
            if(possible)ans.pb(1);
            if(pl2[pos_2]-'0'==0){
                ret2 = func(pos_1,pos_2+1,now^1,0);
            }
            if(possible && !ret1)ans.pb(2);
        }
    }
    return dp[pos_1][pos_2][now]=ret1|ret2;
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
    cin>>n>>pl1>>pl2;
    ms(dp,-1);
    if(func(0,0,0,0)==1){
       for(i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
       }
    }

    else{
        cout<<"Impossible"<<endl;
    }

    return 0;
}
