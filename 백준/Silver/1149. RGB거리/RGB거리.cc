#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define min(a, b) ((a) > (b) ? (b) : (a))
int n, a[1001][3], dp[1001][3], ans;

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for (int i = 1; i < n; i++) {
        dp[i][0] = a[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = a[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = a[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    printf("%d\n", ans);

    return 0;
}
