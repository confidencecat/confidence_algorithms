#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

struct Q {
    int x, y, v;
};

int main() {
    freopen("input.txt", "rt", stdin);
    int n, map[10][10], visit[10][10];
    int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };
    int sx, sy;
    queue<Q> q;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            visit[i][j] = 0;
            if (map[i][j] == 1) {
                sx = j;
                sy = i;
            }
        }
    }

    q.push({ sx, sy, 0 });
    visit[sy][sx] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int v = q.front().v;
        q.pop();

        if (map[y][x] == 2) {
            printf("%d\n", v);
            break;
        }

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= n) continue;
            if (visit[cy][cx] == 1) continue;
            if (map[cy][cx] == 9) continue;
            visit[cy][cx] = 1;
            q.push({ cx, cy, v + 1 });
        }
    }

    return 0;
}
