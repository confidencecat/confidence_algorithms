#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct info {
	int s, e, v;
};

bool operator<(info A, info B) {
	return A.v > B.v;
}

int d[10001];

int find(int a) {
	if (d[a] == a) return a;
	return d[a] = find(d[a]);
}

void uni(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A != B) d[B] = A;
}

int main() {
	int n, m, ans = 0, count = 0;
	priority_queue<info> q;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) d[i] = i;
	for (int i = 0; i < m; i++) {
		int ss, ee, vv;
		scanf("%d %d %d", &ss, &ee, &vv);
		q.push({ ss, ee, vv });
	}
	while (!q.empty() && count < n) {
		int s = q.top().s;
		int e = q.top().e;
		int v = q.top().v;
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
