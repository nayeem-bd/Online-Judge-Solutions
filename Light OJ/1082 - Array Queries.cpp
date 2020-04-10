#include<bits/stdc++.h>
using namespace std;
#define mx 100000+1
int tree[3*mx];
int ara[mx];
int query(int node,int i,int j,int p,int q)
{
    if(q<i||p>j){
        return INT_MAX;
    }
    if(i>=p && j<=q){
        return tree[node];
    }
    int left = node *2;
    int right = node *2+1;
    int mid = (i + j)/2;
    return min(query(left,i,mid,p,q),query(right,mid+1,j,p,q));
}
void build(int node,int i,int j)
{
    if(i==j){
        tree[node]=ara[j];
        return;
    }
    int left = node *2;
    int right = node*2+1;
    int mid = (i+j)/2;
    build(left,i,mid);
    build(right,mid+1,j);
    tree[node] = min(tree[left],tree[right]);
}
int main()
{
    int t,i,j,k,n,p,q,l,r;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d",&n,&q);
 
        for(j=1;j<=n;j++){
            scanf("%d",&ara[j]);
        }
        build(1,1,n);
        printf("Case %d:\n",i);
        while(q--){
            scanf("%d %d",&l,&r);
            printf("%d\n",query(1,1,n,l,r));
        }
    }
    return 0;
}
 
