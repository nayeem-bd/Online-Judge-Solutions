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
#define all(x) x.begin()+1,x.end()-1
#define rall(x) x.rbegin(),x.rend()
 
#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define scd(x) scanf("%lf",&x)
 
#define pfi(x) printf("%d",x)
#define pfl(x) printf("%lld",x)
#define pfd(x) printf("%lf",x)
#define pfc(x) printf("Case %d:",x)
#define ps printf(" ")
#define pn printf("\n")
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define pf(x) push_front(x)
#define ppf(x) pop_front(x)
#define in(x,y) insert({x,y})
#define sv(a) sort(a.begin(),a.end())
#define zero(arr,a) memset(arr,a,sizeof arr)
#define mx 1005
 
int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};
 
map<string,int>mp;
 
char in[200],sent[100005];
 
int main()
{
    //IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    int t,cs=1;
    sci(t);
    while(t--)
    {
        ll n,i,j,k,l,ans=1;
        scl(n);
        for(i=0;i<n;i++){
            //cin>>s;
            scanf("%s",in);
            l=strlen(in);
            string s(in,in+l);
            if(s.size()>3)
            sort(all(s));
            mp[s]++;
        }
        scl(n);
        pfc(cs++);
        pn;
        getchar();
        while(n--){
            ans=1;
            //getline(cin,sen);
            //scanf("%[^\n]s",sent);
            fgets(sent,100005,stdin);
            l=strlen(sent);
            string sen(sent,sent+l);
            stringstream ss;
            ss<<sen;
            string s;
            while(ss>>s){
                    if(s.size()>3)
                    sort(all(s));
                    ans *= mp[s];
            }
            pfl(ans);
            pn;
            //sen.clear();
        }
        //s.clear();
        mp.clear();
    }
 
    return 0;
}
