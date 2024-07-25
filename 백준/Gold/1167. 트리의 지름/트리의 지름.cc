#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, mx = -1, mx_node = 0;
vector<pair<int, int>> v[100001];
bool ch[100001];

int bfs(int sx) {
	memset(ch, false, sizeof(bool) * (n + 1));

	int mx = 0;
	queue<pair<int, int>> q;

	q.push({ sx, 0 });
	ch[sx] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop();

		if (d > mx) {
			mx = d;
			mx_node = x;
		}

		for (auto c : v[x]) {
			int cx = c.first;
			int cd = c.second;

			if (ch[cx] == true) continue;

			ch[cx] = true;
			q.push({ cx, d + cd });
		}
	}

	return mx;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int ss;
		scanf("%d", &ss);
		while (1) {
			int aa, bb;
			scanf("%d", &aa);
			if (aa == -1) break;
			scanf("%d", &bb);
			v[ss].push_back({ aa, bb });
		}
	}

	bfs(1);
	printf("%d\n", bfs(mx_node));

	return 0;
}
