#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) a > b ? a : b

int n, a[100001], dp[100001], ans = -10000;

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i] =  a[i] + dp[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
