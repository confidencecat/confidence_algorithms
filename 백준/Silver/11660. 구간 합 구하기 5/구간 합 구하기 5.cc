#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, a;
long long int d[1026][1026];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a);
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a;
        }
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%2d ", d[i][j]);
        }
        printf("\n");
    }*/


    while (m--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        printf("%lld\n", d[y2][x2] - d[y1 - 1][x2] - d[y2][x1 - 1] + d[y1 - 1][x1 - 1]);
    }
    return 0;
}
