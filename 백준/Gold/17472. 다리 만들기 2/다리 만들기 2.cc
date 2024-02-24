#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num = 0, ans = 987654321;
int map[10][10];
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
bool visit[10][10] = { false }, island[7] = { false };
vector<pair<int, int>> pos[7];

void islandNumbering(int x, int y, int c) {
    visit[x][y] = true;
    map[x][y] = c;
    pos[c].push_back({ x, y });
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0 || visit[nx][ny]) continue;
        islandNumbering(nx, ny, c);
    }
}

void bridge(int x, int y, int idx, int c, int sum) {
    if (c == num - 1) {
        ans = min(ans, sum);
        return;
    }
    island[map[x][y]] = true;
    for (int i = 0; i < pos[map[x][y]].size(); i++) {
        if ((int)i == idx) continue;
        int cx = pos[map[x][y]][i].first, cy = pos[map[x][y]][i].second;
        for (int j = 0; j < 4; j++) {
            int nx = cx + dx[j], ny = cy + dy[j];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] != 0) continue;
            int cnt = 1, f = 0, nnx = nx, nny = ny;
            while (true) {
                nnx += dx[j], nny += dy[j];
                if (nnx < 0 || nny < 0 || nnx >= n || nny >= m) break;
                if (map[nnx][nny] == map[x][y]) break;
                if (map[nnx][nny] != 0) {
                    f = 1;
                    break;
                }
                cnt++;
            }
            if (f == 1 && cnt >= 2 && !island[map[nnx][nny]]) {
                bridge(nnx, nny, -1, c + 1, sum + cnt);
                bridge(x, y, i, c + 1, sum + cnt);
                island[map[nnx][nny]] = false;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && map[i][j] != 0) {
                islandNumbering(i, j, ++num);
            }
        }
    }

    for (int i = 1; i <= num; i++) {
        fill_n(island, 7, false);
        bridge(pos[i][0].first, pos[i][0].second, -1, 0, 0);
    }

    printf("%d", ans != 987654321 ? ans : -1);
    return 0;
}
