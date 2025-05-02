#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, map[1001][1001];
int sum[1001][1001], s, mx = 0;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
            sum[i][j] = map[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= (i < j ? i : j); k++) {
                s = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
                if (s == k * k && s > mx) mx = s;
            }
        }
    }
    printf("%d\n", mx);



    return 0;
}
