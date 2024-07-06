#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min(int a, int b) {
    return (a > b ? b : a);
}

int dp[5001], n;

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d", &n);

    
    for (int i = 1; i <= n; i++) dp[i] = 5000;
    dp[3] = dp[5] = 1;
    for (int i = 6; i <= n; i++) {
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
    }

    printf("%d\n", dp[n] >= 5000 ? -1 : dp[n]);
    return 0;
}
