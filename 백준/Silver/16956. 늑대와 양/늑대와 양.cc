#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int r, c;
char map[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] != 'W') continue;
            for (int k = 0; k < 4; k++) {
                int cx = j + dx[k];
                int cy = i + dy[k];
                if (cx < 0 || cx >= c || cy < 0 || cy >= r) continue;
                if (map[cy][cx] == 'S') {
                    printf("0");
                    return 0;
                }
                else if(map[cy][cx] == '.') {
                    map[cy][cx] = 'D';
                }
            }
        }
    }
    printf("1\n");
    for (int i = 0; i < r; i++) {
        printf("%s\n", map[i]);
    }


    return 0;
}
