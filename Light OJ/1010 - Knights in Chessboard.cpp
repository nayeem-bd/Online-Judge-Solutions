#include<stdio.h>
int main()
{
    int i,t,m,n,cnt,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d",&n,&m);
        if(n==1 || m==1)    cnt = m*n;
        else if(n==2 || m==2)
        {
            if(n==2) k = m;
            else     k = n;
            if(k%4 == 0) cnt = k;
            else if(k%4 == 1 ||k%4 ==3) cnt = k+1;
            else if(k%4 == 2) cnt = k+2;
        }
        else cnt = (n*m)/2+(n*m)%2;
        printf("Case %d: %d\n",i,cnt);
    }
    return 0;
}
