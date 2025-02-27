#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a[501], dp[502][502], b;

int main() {
    scanf("%d", &n);
    scanf("%d %d", &a[0], &a[1]);
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &b, &a[i]);
        dp[i - 1][i - 1] = 0;
    }
    dp[n][n] = 0;
    for (int l= 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = 2147483647;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    printf("%d\n", dp[1][n]);

    return 0;
}
