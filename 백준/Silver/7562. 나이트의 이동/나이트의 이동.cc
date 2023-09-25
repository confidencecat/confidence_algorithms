#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

int t, a[301][301];
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };


int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &t);
    while (t--) {
        int n, sx, sy, ex, ey, ans = 0;
        scanf("%d", &n);
        scanf("%d %d", &sx, &sy);
        scanf("%d %d", &ex, &ey);
        if (sx == ex && sy == ey) {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 0;
            }
        }

        queue<pair<int, int>> q;
        q.push({ sx, sy });
        a[sx][sy] = 1;
        bool end = true;

        while (!q.empty() && end) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                
                if (cx == ex && cy == ey) {
                    a[cx][cy] = a[x][y] + 1;
                    end = false;
                    break;
                }
                if (cx < 0 || cx >= n || cy < 0 || cy >= n || a[cx][cy] != 0) continue;
                q.push({ cx, cy });
                a[cx][cy] = a[x][y] + 1;
                //print(n);
            }
        }
        printf("%d\n", a[ex][ey] - 1);
    }
    return 0;
}
