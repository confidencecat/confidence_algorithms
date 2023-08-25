#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int T, K;
int sum[501], file[501], dp[501][501];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &K);
        for (int i = 1; i <= K; i++) {
            scanf("%d", &file[i]);
            sum[i] = sum[i - 1] + file[i];
        }

        for (int i = 1; i <= K; i++) {
            for (int j = 1; j <= K - i; j++) {
                dp[j][i + j] = INF;
                for (int k = j; k < i + j; k++) {
                    if (dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1] < dp[j][i + j]) {
                        dp[j][i + j] = dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1];
                    }
                }
            }
        }

        printf("%d\n", dp[1][K]);
    }

    return 0;
}
