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
#define TestCase int t,cs=1;sci(t);while(t--)
 
int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};
 
ll cal(ll n)
{
    ll cnt=0,k=5;
    while(k<=n){
        cnt += n/k;
        k *= 5;
    }
    return cnt;
}
ll bisection(ll q)
{
    ll l,m,h,v;
    l = 1; h = 1000000000000000000;
    while(l<=h){
        m = (l+h)/2;
        v = cal(m);
//        if(v==q){
//            //return m;
//            h = m;
//        }
     //   cout<<l<<" "<<h<<endl;
        if(v>=q){
            h = m;
        }
        else {
            l = m;
        }
        if(l==h){
            if(cal(l)==q)return l;
            else{
                return -1;
            }
        }
        if(l+1==h){
            if(cal(l)==q)return l;
            else if(cal(h)==q)return h;
            else return -1;
        }
    }
    return -1;
}
 
 
 
int main()
{
    //IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    /*
        Check Contains Limit && Declear Counter in Long Long
    */
    TestCase
    {
        ll q,i,j,k;
        scl(q);
        pfc(cs++);
        k = bisection(q);
        if(k==-1)printf("impossible");
        else pfl(k);
        pn;
 
    }
 
 
 
    return 0;
}
 
 
