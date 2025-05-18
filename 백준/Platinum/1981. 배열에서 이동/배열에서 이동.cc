#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, mi = 250, mx = -50, arr[100][100];
bool v[100][100];

bool bfs(int a) {
    for (int low = mi; low + a <= mx; low++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = !(low <= arr[i][j] && arr[i][j] <= low + a);
            }
        }
        if (v[0][0] || v[n - 1][n - 1]) continue;
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        v[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == n - 1 && y == n - 1) return true;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !v[nx][ny]) {
                    v[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] < mi) mi = arr[i][j];
            if (arr[i][j] > mx) mx = arr[i][j];
        }
    }
    int s = 0, e = mx - mi + 1, mid;
    while (s < e) {
        mid = (s + e) / 2;
        if (bfs(mid)) e = mid;
        else s = mid + 1;
    }
    printf("%d", s);
    return 0;
}
