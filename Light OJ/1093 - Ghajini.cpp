#include<bits/stdc++.h>
using namespace std;
#define ms 100000
 
int ara[ms+1];
int tree_max[4*ms];
int tree_min[4*ms];
 
void init(int node,int l, int r)
{
    if(l==r){
        tree_max[node]=ara[l];
        tree_min[node]=ara[l];
        return ;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (l+r)/2;
    init(left,l,mid);
    init(right,mid+1,r);
    tree_max[node] = max(tree_max[left],tree_max[right]);
    tree_min[node] = min(tree_min[left],tree_min[right]);
}
 
int query_max(int node,int i,int j,int p,int q)
{
    if(q<i||p>j){
        return INT_MIN;
    }
    if(i>=p && j<=q){
        return tree_max[node];
    }
    int left = node *2;
    int right = node *2+1;
    int mid = (i + j)/2;
    return max(query_max(left,i,mid,p,q),query_max(right,mid+1,j,p,q));
}
int query_min(int node,int i,int j,int p,int q)
{
    if(q<i||p>j){
        return INT_MAX;
    }
    if(i>=p && j<=q){
        return tree_min[node];
    }
    int left = node *2;
    int right = node *2+1;
    int mid = (i + j)/2;
    return min(query_min(left,i,mid,p,q),query_min(right,mid+1,j,p,q));
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int n,d,j,k,l,dif=0,p;
        scanf("%d %d",&n,&d);
        for(j=1;j<=n;j++){
            scanf("%d",&ara[j]);
        }
        init(1,1,n);
        int mx,mn;
        for(j=1;j<n-d;j++){
            mx = query_max(1,1,n,j,j+d-1);
            mn = query_min(1,1,n,j,j+d-1);
            dif = max(dif,mx-mn);
        }
        printf("Case %d: %d\n",i,dif);
 
    }
    return 0;
}
 
