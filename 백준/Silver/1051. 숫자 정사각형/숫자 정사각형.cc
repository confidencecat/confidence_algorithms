#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);
    char a[51][51];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    for (int k = (n > m ? m : n) - 1; k >= 0; k--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + k >= n || j + k >= m) continue;
                if (a[i][j] == a[i + k][j] && a[i][j] == a[i][j + k] && a[i][j] == a[i + k][j + k]) {
                    printf("%d\n", (k + 1) * (k + 1));
                    return 0;
                }
            }
        }
    }
    return 0;
}
