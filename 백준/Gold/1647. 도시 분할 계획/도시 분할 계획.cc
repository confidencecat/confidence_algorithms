#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int d[1000001];

int find(int a) {
	if (d[a] == a) return a;
	return d[a] = find(d[a]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);
	if (a != b) {
		d[b] = a;
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, count = 0, j = 0, ans = 0;
	priority_queue<pair<int, pair<int, int>>> q;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		d[i] = i;
		int ss, ee, vv;
		scanf("%d %d %d", &ss, &ee, &vv);
		q.push({ -vv, {ss, ee} });
	}

	while (!q.empty() && count < n - 2) {
		int v = -q.top().first;
		int s = q.top().second.first;
		int e = q.top().second.second;
		q.pop();

		if (find(s) != find(e)) {
			uni(s, e);
			ans += v;
			count++;
		}
	}

	printf("%d\n", ans);
	return 0;
}