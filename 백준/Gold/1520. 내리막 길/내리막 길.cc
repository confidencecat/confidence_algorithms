#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a[501][501], ans = 0, n, m;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int v[501][501];

int f(int x, int y) {
    if (x == m - 1 && y == n - 1) {
        return 1;
    }
    if (v[y][x] != -1) return v[y][x];
    int w = 0;
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (a[cy][cx] >= a[y][x] || cx >= m || cx < 0 || cy >= n || cy < 0) continue;
        w += f(cx, cy);
    }
    v[y][x] = w;
    return v[y][x];
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            v[i][j] = -1;
        }
    }

    printf("%d\n", f(0, 0));
    return 0;
}
