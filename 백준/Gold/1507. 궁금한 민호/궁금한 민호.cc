#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
    //freopen("input.txt", "rt", stdin);
    int n, a[21][21], ans = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d ", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool c = false;
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) continue;
                if (a[i][j] > a[i][k] + a[k][j]) {
                    printf("-1");
                    return 0;
                }
                else if (a[i][j] == a[i][k] + a[k][j]) c = true;
            }
            if (c == false) ans += a[i][j];
        }
    }
    printf("%d", ans);
    return 0;
}
