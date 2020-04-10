#include<stdio.h>
#include<math.h>
double ara[1000005];
int main()
{
     int n,i,j,a,b,x;
     scanf("%d",&n);
    for(i=1;i<=1000000;i++) ara[i]=ara[i-1]+log(i);
     for(j=1;j<=n;j++){
        scanf("%d %d",&a,&b);
        x = ara[a]/log(b)+1;
        printf("Case %d: %d\n",j,x);
     }
 
    return 0;
}
 
