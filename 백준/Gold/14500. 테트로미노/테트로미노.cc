#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
int n, m, ans;
int paper[555][555];
int visited[555][555];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
void dfs(int y, int x, int cnt, int val) {
    if (cnt == 4) ans = ans < val ? val : ans;
    else {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i]; int nx = x + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx]++;
            dfs(ny, nx, cnt + 1, val + paper[ny][nx]);
            visited[ny][nx]--;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> paper[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            visited[i][j]++;
            dfs(i, j, 1, paper[i][j]);
            visited[i][j]--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int t = paper[i][j]; 
            int mini = 1001;
            for (int k = 0; k < 4; k++) {
                mini = mini < paper[i + dy[k]][j + dx[k]] ? mini : paper[i + dy[k]][j + dx[k]]; 
                t += paper[i + dy[k]][j + dx[k]]; 
            }
            ans = ans < t - mini ? t - mini : ans; 
        }
    }
    cout << ans;
    return 0;
}