#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sum[301][301];

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d ", &sum[i][j]);
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    scanf("%d", &t);

    while (t--) {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);
    }
    return 0;
}
