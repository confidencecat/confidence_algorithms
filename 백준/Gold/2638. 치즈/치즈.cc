#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int n, m, ans = 0;
int map[101][101];
int cnt[101][101];
int ch[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d ", &map[i][j]);
		}
	}


	while (1) {
		int cn = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 2) map[i][j] = 0;
				if (map[i][j] == 1) cn++;
				cnt[i][j] = 0;
				ch[i][j] = 0;
			}
		}
		if (cn == 0) break;
		ans++;
		queue<pair<int, int>> q;
		q.push({ 0, 0 });

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (ch[y][x] == 1) continue;
			ch[y][x] = 1;

			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (cx < 0 || cx >= m || cy < 0 || cy >= n) continue;
				if (map[cy][cx] == 1) {
					cnt[cy][cx]++;
					if (cnt[cy][cx] == 2) {
						map[cy][cx] = 2;
					}
				}
				else if(map[cy][cx] == 0) {
					q.push({ cx, cy });
				}
			}
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
	}
	printf("%d\n", ans);
	return 0;
}