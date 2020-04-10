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
#define mx 1005
 
 
map<char,int>mp;
 
ll ans = LLONG_MIN;
 
struct node{
    bool endmark;
    //map<char,node *>mp;
    node * ara[5];
    int cnt;
    node()
    {
        for(int i=0;i<4;i++){
            ara[i]=NULL;
        }
        endmark = false;
        cnt = 0;
    }
 
} * root;
 
void Insert(string s,int len)
{
    node * cur = root;
    for(int i=0;i<len;i++){
        if(cur->ara[mp[s[i]]]==NULL)
        {
            cur->ara[mp[s[i]]]=new node();
        }
        cur->cnt = cur->cnt+1;
        cur = cur->ara[mp[s[i]]];
    }
    cur->cnt = cur->cnt+1;
    cur->endmark=1;
}
 
void Search(node * cur,int len)
{
    for(int i=0;i<4;i++){
        if(cur->ara[i]!=NULL){
            Search(cur->ara[i],len+1);
        }
        ans = max( (ll)len*(cur->cnt),ans);
    }
}
 
void del(node* cur)
{
    for(int i=0;i<4;i++){
        if(cur->ara[i])del(cur->ara[i]);
    }
    delete(cur);
}
 
int main()
{
    //IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    mp['A']=0;mp['C']=1;mp['G']=2;mp['T']=3;
    int t,cs=1;
    sci(t);
    int n,i,j,l;
    string s;
    while(t--){
        root = new node();
        sci(n);
        for(i=0;i<n;i++){
            cin>>s;
            Insert(s,s.size());
        }
        ans = LLONG_MIN;
        pfc(cs++);
        Search(root,0);
        pfl(max(0LL,ans));
        pn;
        del(root);
    }
    return 0;
}
 
 
