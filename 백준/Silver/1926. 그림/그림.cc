#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a[501][501], n, m, mx = 0;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void f(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx >= m || cx < 0 || cy >= n || cy < 0) continue;
        if (a[cy][cx] == 1) {
            a[cy][cx] = 0;
            mx++;
            f(cy, cx);
        }

    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int ans_count = 0, ans_mx = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                mx = 1;
                a[i][j] = 0;
                f(i, j);
                ans_count++;
                if (mx > ans_mx) ans_mx = mx;
            }
        }
    }
    printf("%d\n%d\n", ans_count, ans_mx);
    return 0;
}
