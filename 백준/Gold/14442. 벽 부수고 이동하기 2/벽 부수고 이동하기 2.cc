#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

int n, m, k, ans = 10000000, c[11][1001][1001];
char a[1001][1001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

struct State {
    int x, y, wall;
};

int main() {
    //freopen("input.txt", "rt", stdin);
    queue<State> q;

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    q.push({ 0, 0, 0 });
    c[0][0][0] = 1;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int wall = q.front().wall;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (wall < k && a[nx][ny] == '1' && c[wall + 1][nx][ny] == 0) {
                c[wall + 1][nx][ny] = c[wall][x][y] + 1;
                q.push({ nx, ny, wall + 1 });
            }

            if (a[nx][ny] == '0' && c[wall][nx][ny] == 0) {
                c[wall][nx][ny] = c[wall][x][y] + 1;
                q.push({ nx, ny, wall });
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        if (c[i][n - 1][m - 1] != 0) {
            ans = min(ans, c[i][n - 1][m - 1]);
        }
    }
    if (ans == 10000000) printf("-1");
    else printf("%d\n", ans);

    return 0;
}

