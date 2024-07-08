#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a < b ? b : a;
}

int a[501][501], dp[501][501];

int main() {
    //freopen("input.txt", "rt", stdin);

    int n, ans = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    ans = dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
            //printf("%d(%d) ", dp[i][j], max(dp[i - 1][j - 1], dp[i - 1][j]));
            if (dp[i][j] > ans) ans = dp[i][j];
        }
        //printf("\n");
    }

    printf("%d\n", ans);

    return 0;
}
