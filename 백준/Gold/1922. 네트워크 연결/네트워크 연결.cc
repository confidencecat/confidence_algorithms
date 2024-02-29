#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<queue>
using namespace std;

struct qinfo {
	int s, e, v;

	qinfo(int a, int b, int c) {
		s = a;
		e = b;
		v = c;
	}

	bool operator<(const qinfo& QI)const {
		return QI.v < v;
	}
};

int d[1001];

int find(int a) {
	if (d[a] == a) return a;
	return d[a] = find(d[a]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) d[b] = a;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, cnt = 0, ans = 0;
	scanf("%d %d", &n, &m);

	priority_queue<qinfo> q;
	for (int i = 1; i <= n; i++) d[i] = i;
	for (int i = 0; i < m; i++) {
		int ss, ee, vv;
		scanf("%d %d %d", &ss, &ee, &vv);
		q.push({ ss, ee, vv });
	}

	while (!q.empty() || cnt < n - 1) {
		int s = q.top().s;
		int e = q.top().e;
		int v = q.top().v;
		q.pop();
		if (find(s) != find(e)) {
			ans += v;
			uni(s, e);
			cnt++;
		}
	}
	printf("%d\n", ans);
	return 0;
}