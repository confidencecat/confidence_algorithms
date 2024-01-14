#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int n, m, sx, sy, ans = 0;
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };
bool visit[1501][1501], meet = false;
char map[1501][1501];

struct Q {
    int x, y;
};

queue<Q> wt, nwt;
queue<Q> s, ns;

void sbfs() {
    while (!s.empty()) {
        int x = s.front().x;
        int y = s.front().y;
        s.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= m || cy < 0 || cy >= n || visit[cy][cx] == true) continue;
            visit[cy][cx] = true;
            if (map[cy][cx] == 'X') {
                ns.push({ cx, cy });
            }
            if (map[cy][cx] == '.') {
                s.push({ cx, cy });
            }
            if (map[cy][cx] == 'L') {
                meet = true;
                return;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                sx = j;
                sy = i;
            }
            if(map[i][j] != 'X') {
                wt.push({ j, i });
            }
        }
    }

    s.push({ sx, sy });
    visit[sy][sx] = true;

    while (1) {
        sbfs();
        if (meet) break;
        ans++;
        while (!wt.empty()) {
            int x = wt.front().x;
            int y = wt.front().y;
            wt.pop();

            for (int i = 0; i < 4; i++) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (cx < 0 || cx >= m || cy < 0 || cy >= n) continue;
                if (map[cy][cx] == 'X') {
                    map[cy][cx] = '.';
                    nwt.push({ cx, cy });
                }
            }
        }
        wt = nwt;
        s = ns;
        while (!ns.empty()) ns.pop();
        while (!nwt.empty()) nwt.pop();
    }
    printf("%d\n", ans);
    return 0;
}
