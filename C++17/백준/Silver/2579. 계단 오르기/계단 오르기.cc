#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) a < b ? b : a

int n, a[302];
int dp[3][302];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[0][i] = a[i] + dp[2][i == 1 ? 0 : (i - 2)];
        dp[1][i] = a[i] + dp[0][i - 1];
        dp[2][i] = max(dp[0][i], dp[1][i]);
    }

    printf("%d\n", dp[2][n]);

    return 0;
}
