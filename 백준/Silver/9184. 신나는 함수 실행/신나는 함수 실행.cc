#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int dp[21][21][21];

int f(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return dp[0][0][0] = 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        if (dp[20][20][20] != 0) return dp[20][20][20];
        return dp[20][20][20] = f(20, 20, 20);
    }

    if (dp[a][b][c] != 0) return dp[a][b][c];

    if (a < b && b < c) {
        return dp[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
    }
    return dp[a][b][c] = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
}

int main() {
    //freopen("input.txt", "rt", stdin);
    while (1) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) {
            return 0;
        }

        printf("w(%d, %d, %d) = %d\n", a, b, c, f(a, b, c));
    }
    return 0;
}
