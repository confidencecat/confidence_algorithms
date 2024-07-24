#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
char map[101][101];
int ch[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	queue<pair<int, int>> q;

	ch[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == m - 1 && y == n - 1) {
			
			break;
		}
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx < 0 || cx >= m || cy < 0 || cy >= n) continue;
			if (ch[cy][cx] != 0 || map[cy][cx] == '0') continue;
			ch[cy][cx] = ch[y][x] + 1;
			q.push({ cx, cy });
		}
	}


	printf("%d\n", ch[n - 1][m - 1]);

	return 0;
}
