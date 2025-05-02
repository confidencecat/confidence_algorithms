#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b, c) (a < b ? (a < c ? a : c) : (b < c ? b : c))

int n, m, map[1001][1001];
int f[1001], s[1001], mx;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 1) {
                s[j] = min(s[j - 1], f[j], f[j - 1]) + 1;
                mx = mx < s[j] ? s[j] : mx;
            }
            else s[j] = 0;
        }
        for(int j = 1; j <= m; j++) f[j] = s[j];
    }
    printf("%d\n", mx*mx);

    return 0;
}
