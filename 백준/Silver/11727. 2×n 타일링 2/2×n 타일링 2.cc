#include <stdio.h>

int dp[1005]={1,1};

int main(){
    int n;

    scanf("%d",&n);

    for(int i=2;i<=n;i++)
        dp[i] = (dp[i-1] + 2*dp[i-2])%10007;

    printf("%d\n",dp[n]);

    return 0;
}