#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<queue>
using namespace std;

int n, ans = 0, ans1 = 0;
char s[101][101];
int c[101][101], c1[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void f(char tc, int tx, int ty, int tf) {
    queue<pair<int, int>> q;
    q.push({ tx, ty });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];

            if (cx < 0 || cx >= n || cy < 0 || cy >= n) continue;

            if (tf) {//적록색약
                if (c1[cx][cy] == 1) continue;
                if (tc == 'B' && s[cx][cy] == 'B') {
                    q.push({ cx, cy });
                    c1[cx][cy] = 1;
                }
                if ((tc == 'R' || tc == 'G') && (s[cx][cy] == 'R' || s[cx][cy] == 'G')) {
                    q.push({ cx, cy });
                    c1[cx][cy] = 1;
                }
            }
            else {//일반
                if (s[cx][cy] != tc || c[cx][cy] == 1) continue;
                q.push({ cx,cy });
                c[cx][cy] = 1;

            }
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
   
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] == 0) {
                c[i][j] = 1;
                f(s[i][j], i, j, 0);
                ans++;
            }
            if (c1[i][j] == 0) {
                c1[i][j] = 1;
                f(s[i][j], i, j, 1);
                ans1++;
            }
        }
    }
    printf("%d %d\n", ans, ans1);
    return 0;
}