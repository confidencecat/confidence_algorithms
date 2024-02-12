#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

struct INFO {
	int s, e, v;
};

int d[1000001];
INFO a[1000001];

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

int com(const void* A, const void* B) {
	INFO AA = *(INFO*)A;
	INFO BB = *(INFO*)B;
	return AA.v - BB.v;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, count = 0, j = 0, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		d[i] = i;
		scanf("%d %d %d", &a[i - 1].s, &a[i - 1].e, &a[i - 1].v);
	}

	qsort(a, m, sizeof(INFO), com);


	while (j < m) {
		if (count == n - 2) break;
		if (find(a[j].s) != find(a[j].e)) {
			uni(a[j].s, a[j].e);
			ans += a[j].v;
			count++;
		}
		j++;
		
	}

	printf("%d\n", ans);
	return 0;
}