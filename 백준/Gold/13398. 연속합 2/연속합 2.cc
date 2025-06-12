#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int n, a[100001], dp[100001][2], ans = -2147483648;

int main() {
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ans = a[0];
    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = a[i];
        if (i == 0) continue;
        dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    printf("%d\n", ans);

    return 0;
}
