#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<queue>
using namespace std;

char s[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, m, ans = 0;

void f(int tx, int ty) {
    queue<pair<int, int>> q;
    q.push({ tx ,ty });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || s[cx][cy] == '.') continue;
            q.push({ cx, cy });
            s[cx][cy] = '.';
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                f(i, j);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}