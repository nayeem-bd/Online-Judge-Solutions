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
 
int cal(int n, int x)
{
    int cnt=0;
    while(n%x==0){
        cnt++;
        n/=x;
    }
    return cnt;
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
        int n,r,p,q,i,j,two=0,five=0,k,l;
        sci(n);sci(r);sci(p);sci(q);
        k=2;
        while(k<=n){
            two += n/k;
            k*=2;
        }
        k=2;
        while(k<=r){
            two -= r/k;
            k*=2;
        }
        k=2;
        while(k<=(n-r)){
            two -= (n-r)/k;
            k*=2;
        }
        k=5;
        while(k<=n){
            five += n/k;
            k*=5;
        }
        k=5;
        while(k<=r){
            five -= r/k;
            k*=5;
        }
        k=5;
        while(k<=(n-r)){
            five -= (n-r)/k;
            k *= 5;
        }
        two += q*cal(p,2);
        five += q*cal(p,5);
        //cout<<two<<five<<endl;
        pfc(cs++);pfi(min(two,five));pn;
 
    }
 
    return 0;
}
 
 
