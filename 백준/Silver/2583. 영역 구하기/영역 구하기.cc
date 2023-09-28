#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include <queue>
using namespace std;

int n, m, k, ans = 0, ans_a[101];
char a[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


int f(int tx, int ty) {
    queue<pair<int, int>> q;
    int ans = 1;
    q.push({ tx, ty });
    a[tx][ty] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m || a[cx][cy] == 1) continue;
            ans++;
            q.push({ cx, cy });
            a[cx][cy] = 1;
        }
    }

    return ans;
}

int com(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d %d", &n, &m, &k);
    while (k--) {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                a[j][i] = 1;
            }
        }
        
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                ans_a[ans++] = f(i, j);
            }
        }
    }

    printf("%d\n", ans);
    qsort(ans_a, ans, sizeof(int), com);
    for (int i = 0; i < ans; i++) {
        printf("%d ", ans_a[i]);
    }
    return 0;
}
