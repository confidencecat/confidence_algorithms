#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<queue>
using namespace std;

int a[1002][1002];
int c[1002][1002];
int dx[4] = { 0 ,0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

queue<pair<int, int>> q;

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            
            if (a[i][j] == 2) {
                q.push({ i, j });
                a[i][j] = 0;
                c[i][j] = 1;
            }
            else if(a[i][j] == 1 ){
                a[i][j] = -1;
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
            if (cx < 0 || cx > n || cy < 0 || cy > m || c[cx][cy] == 1 || a[cx][cy] == 0) continue;
            c[cx][cy] = 1;
            a[cx][cy] = a[x][y] + 1;
            q.push({ cx, cy });
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}