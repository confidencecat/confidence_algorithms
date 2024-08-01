#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int n, m;
char map[502][502];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool ch(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (cx < 0 || cx >= m || cy < 0 || cy >= n) continue;
        //printf("%d %d\n", cx, cy);
        if (map[cy][cx] == 'S') continue;
        if (map[cy][cx] == 'W') return false;
        map[cy][cx] = 'D';
    }
    return true;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //printf("%c\n", map[i][j]);
            if (map[i][j] == 'S') {
                //printf("1\n");
                if (ch(i, j) == false) {
                    printf("0\n");
                    return 0;
                }
            }
        }
    }
    printf("1\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", map[i]);
    }
    return 0;
}
