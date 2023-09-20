#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<queue>
using namespace std;

char s[11][11];
int c[11][11];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

int f() {
    bool tf = true;
    while (!q.empty() && tf) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (s[cx][cy] == 'B') {
                return c[x][y] - 1;
            }
            if (cx < 0 || cx >= 10 || cy < 0 || cy >= 10 || s[cx][cy] == 'R' || c[cx][cy] != 0) continue;
            q.push({ cx, cy });
            c[cx][cy] = c[x][y] + 1;
        }
    }
    return 0;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    for (int i = 0; i < 10; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < 10; j++) {
            if (s[i][j] == 'L') {
                q.push({ i, j });
                c[i][j] = 1;
            }
        }
    }
    printf("%d\n", f());
    return 0;
}
