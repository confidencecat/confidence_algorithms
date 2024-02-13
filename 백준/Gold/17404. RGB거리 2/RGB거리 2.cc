#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int cost[1001][3];
int dp[1001][3];

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int answer = 10000000;

    for (int sx = 0; sx < 3; sx++) {
        for (int color = 0; color < 3; color++) {
            if (color == sx) dp[0][color] = cost[0][color];
            else dp[0][color] = 10000000;
        }

        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }

        for (int dx = 0; dx < 3; dx++) {
            if (dx != sx) {
                answer = min(answer, dp[n - 1][dx]);
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
