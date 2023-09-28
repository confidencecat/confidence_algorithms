#include <stdio.h>
#include <queue>
using namespace std;

int n, m, c[1001][1001][2];
char a[1001][1001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

struct State {
    int x, y, wall;
};

int main() {
    queue<State> q;
    
    scanf("%d %d", &n, &m);
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

            if (a[nx][ny] == '0' && c[nx][ny][wall] == 0) {
                c[nx][ny][wall] = c[x][y][wall] + 1;
                q.push({ nx, ny, wall });
            }
            
            if (wall == 0 && a[nx][ny] == '1' && c[nx][ny][1] == 0) {
                c[nx][ny][1] = c[x][y][0] + 1;
                q.push({ nx, ny, 1 });
            }
        }
    }

    if (c[n-1][m-1][0] != 0 && c[n-1][m-1][1] != 0)
        printf("%d\n", min(c[n-1][m-1][0], c[n-1][m-1][1]));
    else if (c[n-1][m-1][0] != 0)
        printf("%d\n", c[n-1][m-1][0]);
    else if (c[n-1][m-1][1] != 0)
        printf("%d\n", c[n-1][m-1][1]);
    else
        printf("-1\n");

    return 0;
}
