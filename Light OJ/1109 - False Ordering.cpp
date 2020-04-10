#include<stdio.h>
int dp[1005];
int countDivisor(int n) {
  int divisor = 0;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      divisor += 1;
    } else if (n % i == 0) {
      divisor += 2;
    }
  }
  return divisor;
}
int main()
{
    int t,n,i,j,l=2,m=2;
    int ara[1005];
    scanf("%d",&t);
    for(i=1;i<=1000;i++){
       dp[i]=countDivisor(i);
    }
    while(1){
        for(i=1000;i>=1;i--){
            if(dp[i]==m){
                ara[l++]=i;
            }
        }
        m++;
        if(l==1001) break;
    }
    ara[1]=1;
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        printf("Case %d: %d\n",i,ara[n]);
    }
    return 0;
}
