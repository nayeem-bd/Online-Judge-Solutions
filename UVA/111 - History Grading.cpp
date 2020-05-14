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

//ll modPower(ll x,ll y,ll p){ll res=1LL;x=x%p;while(y>0{if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
//ll power(ll a,ll b){if(b==0)return 1;ll x=power(a,b/2);x=(x*x);if(b&1)x=(x*a);return x;}

/*---------------------Direction Array----------------------*/

//int fx[]={0,1,1,1,0,-1,-1,-1};    //8-side move
//int fy[]={1,1,0,-1,-1,-1,0,1};
//int fx[]={1,-1,0,0};              //4-side move
//int fy[]={0,0,1,-1};
//int fx[]={2,1,-1,-2,-2,-1,1,2};   //knight move
//int fy8]={1,2,2,1,-1,-2,-2,-1};

/*----------------------------------------------------------*/

/*--------------------------BitMask-------------------------*/

//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}

/*---------------------------------------------------------*/

int dp[25][25];

int LCS(int i,int j,int n,vector<int>a,vector<int>b)
{
    if(i==n || j==n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans;
    if(a[i]==b[j]){
        ans = 1+LCS(i+1,j+1,n,a,b);
    }
    else{
        ans = max(LCS(i+1,j,n,a,b),LCS(i,j+1,n,a,b));
    }
    return dp[i][j]=ans;
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
    string s;
    int n,i,j,p,newn;
    getline(cin,s);
    stringstream ss(s);
    ss>>newn;
    while(1)
    {
        n=newn;
        newn=-1;
        vector<int>teacher(n);
        getline(cin,s);
        stringstream ss(s);
        i=0;
        while(ss>>p){
            //teacher.pb(p);
            teacher[p-1]=i;
            i++;
        }
        while(getline(cin,s)){
            if(s.size()<=2){
                stringstream ss(s);
                ss>>newn;
                break;
            }
            else{
            	vector<int>student(n);
            	i=0;
                stringstream ss(s);
                while(ss>>p){
                    //student.pb(p);
                    student[p-1]=i;
                    i++;
                }
                ms(dp,-1);
                cout<<LCS(0,0,n,teacher,student)<<endl;;
            }
        }
        if(newn==-1){
        	break;
        }

    }



    return 0;
}









