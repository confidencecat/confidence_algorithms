#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max(a, b) a > b ? a : b

int map[1001][1001];
int dx[3] = { 0, -1, -1};
int dy[3] = { -1, 0, -1};

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		scanf("%d", &map[i][j]);
		int mx = -1;
		for (int k = 0; k < 3; k++) {
			if (!(i + dy[k] < 0 || i + dy[k] >= n || j + dx[k] < 0 || j + dx[k] >= m)) {
				mx = max(mx, map[i + dy[k]][j + dx[k]]);
			}
		}
		map[i][j] += (mx == -1 ? 0 : mx);
	}
	printf("%d\n", map[n - 1][m - 1]);
	return 0;
}