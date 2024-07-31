#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, x, y, d; //북동남서 0123
int map[52][52], ch[52][52]; //0 청소 안함 1 청소함
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = 0;

bool ch4(int x, int y) { //true : 청소할 공간이 남음
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
        if (map[cx][cy] != 1 && ch[cx][cy] == false) return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &d);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    while (1) {
        if (ch[x][y] == false) {
            ch[x][y] = true;
            ans++;
        }

        if (ch4(x, y)) {
            d = (d + 3) % 4;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0 && ch[nx][ny] == false) {
                x = nx;
                y = ny;
            }
        }
        else {
            int nx = x - dx[d];
            int ny = y - dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 1) break;
            x = nx;
            y = ny;
        }
    }

    printf("%d\n", ans);

    return 0;
}
