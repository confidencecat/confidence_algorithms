#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

int n, a[101][101], a1[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void f(int h, int tx, int ty) {
    queue<pair<int, int>> q;
    q.push({ tx, ty });
    a1[tx][ty] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= n || a1[cx][cy] <= h) continue;
            q.push({ cx, cy });
            a1[cx][cy] = 0;
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int mn = 101, mx = -101, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] < mn) mn = a[i][j];
            if (a[i][j] > mx) mx = a[i][j];
        }
    }
    for (int h = mn - 1; h <= mx; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a1[i][j] = a[i][j];
            }
        }

        int hans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a1[i][j] > h) {
                    f(h, i, j);
                    hans++;
                }
            }
        }
        if (hans > ans) ans = hans;
    }
    printf("%d\n", ans);

    return 0;
}
