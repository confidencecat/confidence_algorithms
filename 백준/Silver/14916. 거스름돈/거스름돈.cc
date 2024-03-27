#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 100000000

int dp[100001], n;

int min(int a, int b) {
    if (a > b) return b;
    return a;
}

int null(int a) {
    if (a == 0) return INF;
    return a;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    dp[1] = dp[3] = INF;
    dp[2] = dp[5] = 1;
    dp[4] = 2;

    if (n <= 5) printf("%d\n", dp[n] == INF ? -1 : dp[n]);
    else {
        for (int i = 6; i <= n; i++) {
            dp[i] = min(null(dp[i - 2]), null(dp[i - 5])) + 1;
        }
        printf("%d\n", dp[n] == INF ? -1 : dp[n]);
    }
    return 0;
}

