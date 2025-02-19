#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int r, c, ans = 0;
char map[10001][501];
int d[3] = { -1, 0, 1 };

int f(int x, int y) {
    if (x == c - 1) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        int cy = y + d[i];
        if (cy < 0 || cy == r) continue;
        if (map[cy][x + 1] == 'x') continue;
        map[y][x] = 'x';
        if (f(x + 1, cy) == 1) return 1;
    }
    return 0;
}

int main() {
    
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", map[i]);
        map[i][0] = 'c';
    }

    for (int i = 0; i < r; i++) {
        ans += f(0, i);
    }
    printf("%d\n", ans);
    return 0;
}
