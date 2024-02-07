#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#define min(a, b) a > b ? b : a
using namespace std;

int map[101][101], define_ch[101][101], n, ans = 100000, cnt = 0;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<pair<int, int>> v[5001];

bool isside(int x, int y) {
	if (x - 1 >= 0 && map[y][x - 1] == 0) return true;
	if (x + 1 < n && map[y][x + 1] == 0) return true;
	if (y - 1 >= 0 && map[y - 1][x] == 0) return true;
	if (y + 1 >= 0 && map[y + 1][x] == 0) return true;
	return false;
}

void define(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	v[num].push_back({ x, y });
	define_ch[y][x] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			
			if (x + dx[i] < 0 || x + dx[i] >= n) continue;
			if (y + dy[i] < 0 || y + dy[i] >= n) continue;
			if (define_ch[y + dy[i]][x + dx[i]] != 0 || map[y + dy[i]][x + dx[i]] == 0) continue;

			define_ch[y + dy[i]][x + dx[i]] = 1;
			if (isside(x + dx[i], y + dy[i])) v[num].push_back({ x + dx[i], y + dy[i] });
			q.push({ x + dx[i], y + dy[i] });
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && define_ch[i][j] == 0) {
				define(j, i, cnt++);
			}
		}
	}
	/*for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			printf("[%d, %d]  ", v[i][j].first, v[i][j].second);
		}
		printf("\n");
	}*/

	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			int vi = v[i].size();
			for (int ii = 0; ii < vi; ii++) {
				int vj = v[j].size();
				for (int jj = 0; jj < vj; jj++) {
					int len = abs(v[j][jj].first - v[i][ii].first) + abs(v[j][jj].second - v[i][ii].second);
					ans = min(len - 1, ans);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}