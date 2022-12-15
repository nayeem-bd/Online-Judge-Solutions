/*
                    NAYEEM
    Information and Communication Engineering ,
            University of Rajshahi
            Updated: 16-12-2022
*/
#include<bits/stdc++.h>
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
#define TestCase_IOS int t,cs=1;cin>>t;while(t--)
#define PI 2*acos(0.0)

/*------------------------Policy-Based-Data-Structure------------------------*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T, typename K, typename Comp = less<T>>
using ordered_map = tree<T,K,Comp,rb_tree_tag,tree_order_statistics_node_update>;

template <typename T> using ordered_set = ordered_map<T,null_type, less<T>>;

// Functions
// order_of_key(k): Returns the number of elements strictly smaller than k.
// find_by_order(k): Returns the address of the element at kth index (0-based)

// AS MULTISET
// ordered_set <pair<int,int>> os;
// os.insert({value,id++});
// os.erase(os.lower_bound({value,0}));
// os.order_of_key({value, 0});

/*---------------------------------------------------------------------------*/


/*------------------------Declarations------------------------*/

//priority_queue<int,vector<int>, greater<int>>  //priority queue sorted in increasing order

/*------------------------------------------------------------*/

template <typename T> T power(T a, T b){ T x=1;while(b){ if(b&1)x*=a;a*=a;b>>=1; }return x; }
template <typename T> T modPower(T a, T b, T M){ T x=1;while(b){ if(b&1) x=(x*a)%M;a=(a*a)%M;b>>=1; }return x; }
template <typename T> T Sqrt(T a) { T x=(T)sqrt(a); if((x+1)*(x+1)==a) x++; return x; }

/*------------------------------------------------------------*/

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



int main()
{
    //IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    /*
        Check Contains Limit && Declear Counter in Long Long
        Check Array Size
    */




    return 0;
}








