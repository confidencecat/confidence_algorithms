#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include <queue>
using namespace std;

int n, m, ans = 0, v[600][600];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char s[601][601];

int main() {
    //freopen("input.txt", "rt", stdin);
    queue<pair<int, int>> q;
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'I') {
                q.push({ i, j });
                v[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || s[cx][cy] == 'X' || v[cx][cy] == 1) {
                continue;
            }
            v[cx][cy] = 1;
            if (s[cx][cy] == 'P') ans++;
            q.push({ cx, cy });
        }
    }
    if (ans == 0) {
        printf("TT\n");
    }
    else {
        printf("%d\n", ans);
    }
    return 0;
}