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

//ll modPower(ll x, ll y, ll p){ll res = 1;x = x % p;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
//ll power(ll a,ll b){if(b==0)return 1;ll x=power(a,b/2);x=(x*x);if(b&1)x=(x*a);return x;}

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

int dp[105],n,ans,vis[105];




int solve(vector<int>v[],int cur)
{
    if(v[cur].size()==0){
        return 0;
    }
    if(dp[cur]!=-1)return dp[cur];
    int ret1=0,i,j,cnt=0;
    for(j=0;j<v[cur].size();j++){
        if(vis[v[cur][j]]==0){
        	ret1 += solve(v,v[cur][j]);
        	 vis[v[cur][j]]=1;
        	 cnt++;
        }

    }
    ret1 +=cnt;
    return dp[cur]=ret1;
}
void solution(vector<int>v[])
{
    int ret1=0,ret2=0,i;
    for(i=1;i<=n;i++){
        ms(vis,0);
         ms(dp,-1);
        ret2 = solve(v,i);
        if(ret1<ret2){
            ans=i;
            ret1 = ret2;
        }
        //cout<<i<<"    "<<ret1<<endl;
    }
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
    int i,j,l,m,t;
    while(sci(n)&&n>0){
        ans=0;

        vector<int>v[n+1];
        for(i=1;i<=n;i++){
            sci(t);
            for(j=0;j<t;j++){
                sci(m);
                v[i].pb(m);
            }
        }
        solution(v);
        cout<<ans<<endl;
    }



    return 0;
}

