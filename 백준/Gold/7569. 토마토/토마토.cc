#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<queue>
using namespace std;

int a[101][101][101];

typedef struct {
    int h, x, y, d;
}dhxy;

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, l, cnt = 0, ans = 0;

    int dh[6] = { 0, 0, 0, 0, -1, 1 };
    int dx[6] = { 0, 0, -1, 1 , 0, 0 };
    int dy[6] = { -1, 1, 0, 0 , 0, 0 };

    queue<dhxy> q;

    scanf("%d %d %d", &m, &n, &l);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &a[i][j][k]);
                if (a[i][j][k] == 0) cnt++;
                if (a[i][j][k] == 1) q.push({ i, j, k, 0});
            }
        }
    }

    while (!q.empty() && cnt > 0) {
        int h = q.front().h;
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d + 1;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int ch = h + dh[i];
            int cx = x + dx[i];
            int cy = y + dy[i];

            if (ch < 0 || ch >= l || cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
            if (a[ch][cx][cy] != 0) continue;

            q.push({ ch, cx, cy, d });
            a[ch][cx][cy] = 1;
            cnt--;
            ans = d;

        }
    }
    if (cnt == 0) {
        printf("%d\n", ans);
    }
    else {
        printf("-1\n");
    }
    return 0;
}