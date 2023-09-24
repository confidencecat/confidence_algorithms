#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;
int n, m, a[51][51];
int dx[8] = { 0, 0, -1, -1, -1, 1, 1, 1};
int dy[8] = { -1, 1, -1, 0, 1, -1, 0, 1 };

void f(int ti, int tj) {
    queue<pair<int, int>> q;
    q.push({ ti, tj });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || a[cx][cy] == 0) continue;
            a[cx][cy] = 0;
            q.push({ cx, cy });
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    while (1) {
        int ans = 0;
        scanf("%d %d", &m, &n);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    f(i, j);
                    ans++;
                }
            }

        }
        printf("%d\n", ans);
    }
    return 0;
}
