#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
    //freopen("input.txt", "rt", stdin);
    
    long long int dp[1002] = { 0, 1, 2, };

    int n;
    scanf("%d", &n);

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
        dp[i] %= 10007;
    }
    printf("%lld\n", dp[n]);

    return 0;
}
