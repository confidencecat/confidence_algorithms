#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

char a[26][26];
int n, ans = 0;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

int com(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

void bfs(int i, int j, int* ans_arr) {
    int m = 0;
    q.push({ i, j });
    a[i][j] = '0';

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        m++;

        for (int k = 0; k < 4; k++) {
            int cx = x + dx[k];
            int cy = y + dy[k];

            if (cx < 0 || cx >= n || cy < 0 || cy >= n || a[cx][cy] == '0') continue;
            a[cx][cy] = '0';
            q.push({ cx, cy });
        }
    }
    ans_arr[ans] = m;
}

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    int ans_arr[625] = { 0 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '1') {
                bfs(i, j, ans_arr);
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    qsort(ans_arr, ans, sizeof(int), com);
    for (int i = 0; i < ans; i++) {
        printf("%d\n", ans_arr[i]);
    }

    return 0;
}
