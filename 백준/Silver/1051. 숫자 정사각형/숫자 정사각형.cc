#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, ans = 0, max;
    char a[51][51];
    scanf("%d %d", &n, &m);
    max = n > m ? m : n;

    if (max == 1) {
        printf("1\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < max; k++) {
                if (i + k >= n || j + k >= m) continue;
                if (a[i][j] == a[i + k][j] && a[i][j] == a[i][j + k] && a[i][j] == a[i + k][j + k]) {
                    ans = ans > (k + 1) * (k + 1) ? ans : (k + 1) * (k + 1);
                    //printf("%c %c %c %c\n", a[i][j], a[i][j + k], a[i + k][j], a[i + k][j + k]);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
