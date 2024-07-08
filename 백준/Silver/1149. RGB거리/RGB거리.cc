#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) a > b ? b : a

int dp[3][1001], n;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);

    scanf("%d %d %d", &dp[0][0], &dp[1][0], &dp[2][0]);

    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &dp[0][i], &dp[1][i], &dp[2][i]);
        dp[0][i] += min(dp[1][i - 1], dp[2][i - 1]);
        dp[1][i] += min(dp[0][i - 1], dp[2][i - 1]);
        dp[2][i] += min(dp[0][i - 1], dp[1][i - 1]);
    }

    printf("%d", min((min(dp[0][n - 1], dp[1][n - 1])), dp[2][n - 1]));
    return 0;
}
