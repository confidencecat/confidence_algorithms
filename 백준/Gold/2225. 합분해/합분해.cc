#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[201][201];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i <= n; i++) {
        dp[i][1] = 1;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 0; l <= i; l++) {
                dp[i][j] += dp[l][j - 1];
                dp[i][j] %= 1000000000;
            }
        }
    }

    printf("%d\n", dp[n][k]);
    return 0;
}
