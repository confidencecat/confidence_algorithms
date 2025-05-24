#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000000
#define min(a, b) ((a) < (b) ? (a) : (b))

int n, map[1501][1501];
int dp[1501][1501];
int ans = MAX;

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = MAX;
        }
    }

    if (n >= 2) {
        dp[1][0] = map[0][1];
    }

    for (int i = 2; i < n; i++) {
        for (int j = 0; j <= i - 2; j++) {
            dp[i][j] = dp[i - 1][j] + map[i - 1][i];
        }
        int best = MAX;
        for (int k = 0; k <= i - 2; k++) {
            int cand = dp[i - 1][k] + map[k][i];
            if (cand < best) best = cand;
        }
        dp[i][i - 1] = best;
    }

    int answer = MAX;
    if (n == 2) {
        answer = map[0][1];
    }
    else {
        for (int j = 0; j <= n - 2; j++) {
            if (dp[n - 1][j] < answer) {
                answer = dp[n - 1][j];
            }
        }
    }

    printf("%d\n", answer);
    return 0;
}



