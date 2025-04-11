#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int n, l, r;
int map[51][51];
bool ch[51][51];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool bfs(int fx, int fy) {
    int sum = map[fy][fx], c = 1;
    bool tf = false;

    queue<pair<int, int>> m;
    queue<pair<int, int>> q;

    ch[fy][fx] = true;
    q.push({ fx, fy });
    m.push({ fx, fy });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= n) continue;
            if (ch[cy][cx]) continue;
            
            if (l <= abs(map[y][x] - map[cy][cx]) && abs(map[y][x] - map[cy][cx]) <= r) {
                sum += map[cy][cx];
                c++;
                m.push({ cx, cy });
                tf = true;

                q.push({ cx, cy });
                ch[cy][cx] = true;
            }
        }
    }
    while (!m.empty()) {
        int x = m.front().first;
        int y = m.front().second;
        m.pop();
        map[y][x] = (sum / c);
    }

    return tf;
}

int main() {

    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int ans = 0;
    while (1) {
        bool tf = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ch[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!ch[i][j]) {
                    ch[i][j] = true;
                    if (bfs(j, i)) tf = false;
                }
            }
        }
        if (tf) break;
        ans++;
    }
    printf("%d\n", ans);

    return 0;
}
