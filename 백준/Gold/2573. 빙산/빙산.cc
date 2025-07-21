#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int map[301][301];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool ch[301][301];

int count_comp() {
    memset(ch, 0, sizeof(ch));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > 0 && !ch[i][j]) {
                cnt++;
                queue<pair<int,int>> q;
                q.push({ i, j });
                ch[i][j] = true;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    int y = cur.first;
                    int x = cur.second;
                    for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d], nx = x + dx[d];
                        if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] > 0 && !ch[ny][nx]) {
                            ch[ny][nx] = true;
                            q.push({ ny, nx });
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

void melt() {
    int sub[301][301] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > 0) {
                int water = 0;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dy[d], nj = j + dx[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && map[ni][nj] == 0) water++;
                }
                sub[i][j] = water;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > 0) {
                map[i][j] = max(0, map[i][j] - sub[i][j]);
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
    int year = 0;
    while (1) {
        int parts = count_comp();
        if (parts >= 2) {
            printf("%d\n", year);
            return 0;
        }
        if (parts == 0) {
            printf("0\n");
            return 0;
        }
        melt();
        year++;
    }
    return 0;
}
