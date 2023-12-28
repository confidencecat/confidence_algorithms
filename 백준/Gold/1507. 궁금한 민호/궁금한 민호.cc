#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define min(a, b) a < b ? a : b 
bool c[21][21];
int main() {
    //freopen("input.txt", "rt", stdin);
    int n, a[21][21], ans = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d ", &a[i][j]);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!(i == j || j == k || i == k)) {
                    if (a[i][j] - a[i][k] - a[k][j] > 0) {
                        printf("-1");
                        return 0;
                    }
                    if (a[i][j] - a[i][k] - a[k][j] == 0) {
                        c[i][j] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (!c[i][j]) ans += a[i][j];
        }
    }
    printf("%d\n", ans);
    return 0;
}
