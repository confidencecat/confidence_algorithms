#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
#include <queue>
#define INF 100
using namespace std;

int n, d[51][51];
char map[51][51];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

struct qinfo {
	int sx, sy, v;

	qinfo(int a, int b, int c) {
		sx = a;
		sy = b;
		v = c;
	}

	bool operator<(const qinfo& IN)const {
		return IN.v > v;
	}
};

struct vinfo {
	int ex, ey, v;
};


vector<vinfo> v[50][50];

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int cj = j + dx[k];
				int ci = i + dy[k];
				if (ci < 0 || cj < 0 || ci >= n || cj >= n) continue;
				v[i][j].push_back({ cj, ci, (map[cj][ci] == '0' ? 1 : 0) });
				//printf("[%d, %d] -> [%d, %d], %d\n", i, j, ci, cj, (map[cj][ci] == '0' ? 1 : 0));
			}
			d[i][j] = INF;
		}
	}
	
	priority_queue<qinfo> q;
	q.push({ 0, 0, 0 });
	d[0][0] = 0;
	
	while (!q.empty()) {
		int sx = q.top().sx;
		int sy = q.top().sy;
		int value = q.top().v;
		q.pop();

		if (d[sy][sx] < value) continue;
		for (auto& vin : v[sy][sx]) {
			int next_x = vin.ex;
			int next_y = vin.ey;
			int next_value = vin.v + value;
			if (next_value < d[next_y][next_x]) {
				d[next_y][next_x] = next_value;
				q.push({ next_x, next_y, next_value });
			}
		}
		//print();
	}

	printf("%d\n", d[n - 1][n - 1]);
	return 0;
}