#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int dp[31][31];

int main() {
    int t, n, m;
    for (int i = 0; i < 30; i++) dp[0][i] = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        if (n == 0 || m < n) {
            printf("0\n");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
//mCn