#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int n, m, a[101][101];
char map[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 , 0 };

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    queue<pair<int, int>> q;

    q.push({ 0, 0 });
    a[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //printf("%d %d\n", x, y);

        if (x == m && y == n) break;

        for (int i = 0; i < 4; i++) {
            int cx = dx[i] + x;
            int cy = dy[i] + y;

            //printf("%d %d\n", cx, cy);
            if (cx < 0 || cx >= m || cy < 0 || cy >= n || map[cy][cx] == '0' || a[cy][cx] != 0) continue;

            a[cy][cx] = a[y][x] + 1;
            q.push({ cx, cy });
        }

    }


    printf("%d\n", a[n - 1][m - 1]);
    return 0;
}
