#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int x, y, d;
} Q;

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, rx, ry, rd, ans = 0;
    int map[52][52];
    int md[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    queue<Q> q;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &ry, &rx, &rd);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    q.push({ rx, ry, rd });

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();

        if (map[y][x] == 0) {
            map[y][x] = 2;
            ans++;
        }

        bool allCleaned = true;
        for (int i = 0; i < 4; i++) {
            int nextD = (d + 3) % 4;
            int nx = x + md[nextD][1];
            int ny = y + md[nextD][0];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] == 0) {
                q.push({ nx, ny, nextD });
                allCleaned = false;
                break;
            }
            d = nextD;
        }

        if (allCleaned) {
            int backD = (d + 2) % 4;
            int bx = x + md[backD][1];
            int by = y + md[backD][0];

            if (bx >= 0 && bx < m && by >= 0 && by < n && map[by][bx] != 1) {
                q.push({ bx, by, d });
            }
            else {
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
