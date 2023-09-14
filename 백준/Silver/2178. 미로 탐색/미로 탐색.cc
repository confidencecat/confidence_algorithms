#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<queue>
#define min(a, b) a > b ? b : a
using namespace std;

int v[101][101], ans[101][101];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    queue<pair<int, int>> q;
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };
    int n, m;
    char a[101][101];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    q.push({ 0, 0 });
    v[0][0] = 1;
    ans[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || v[cx][cy] == 1 || a[cx][cy] == '0')
                continue;
            
            v[cx][cy] = 1;
            q.push({ cx, cy });
            if (ans[cx][cy] == 0) ans[cx][cy] = ans[x][y] + 1;
            else ans[cx][cy] = min(ans[cx][cy], ans[x][y] + 1);
        }
    }
    printf("%d\n", ans[n - 1][m - 1]);
    return 0;
}