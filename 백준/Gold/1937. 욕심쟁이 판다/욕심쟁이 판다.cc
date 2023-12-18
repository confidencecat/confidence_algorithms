#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define max(a, b) a > b ? a : b

int n, a[501][501], dp[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


int f(int i, int j) {
    if (dp[i][j] != 0) return dp[i][j];
    dp[i][j] = 1;

    for (int d = 0; d < 4; d++) {
        int ci = i + dy[d];
        int cj = j + dx[d];
        if (ci < 0 || ci >= n || cj < 0 || cj >= n) continue;
        if (a[i][j] >= a[ci][cj]) continue;
       

        dp[i][j] = max(dp[i][j], f(ci, cj) + 1);
    }
    return dp[i][j];
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, f(i, j));
        }
    }
    printf("%d\n", ans);
    return 0;
}