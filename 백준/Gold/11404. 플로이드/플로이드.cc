#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define min(a, b) a < b ? a : b
#define INF 1000000000

int a[101][101];

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, s, e, v;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) a[i][j] = 0;
            else a[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &s, &e, &v);
        if (a[s][e] > v) a[s][e] = v;
    }

    for (int d = 1; d <= n; d++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && a[i][d] != INF && a[d][j] != INF) {
                    a[i][j] = min(a[i][d] + a[d][j], a[i][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == INF) printf("0 ");
            else printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
