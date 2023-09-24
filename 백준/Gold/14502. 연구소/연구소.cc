#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int n, m, a[9][9], a1[9][9], mx = -100;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


int bfs() {
    queue<pair<int, int>> q;
    int zn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a1[i][j] == 2) q.push({ i, j });
            if (a1[i][j] == 0) zn++;
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || a1[cx][cy] != 0) continue;
            q.push({ cx, cy });
            a1[cx][cy] = 2;
            zn--;
        }
    }
    return zn;
}

void mw(int wn) {
    if (wn == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a1[i][j] = a[i][j];
            }
        }
        
        int b = bfs();
        if (b > mx) {
            mx = b;
        }
        wn = 0;
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    a[i][j] = 1;
                    mw(wn + 1);
                    a[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    mw(0);
    printf("%d\n", mx);
    return 0;
}
