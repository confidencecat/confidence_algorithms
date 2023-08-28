#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[31] = { 1, 0, 3 };

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2) {
            dp[i] += dp[i - j] * 2;
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}