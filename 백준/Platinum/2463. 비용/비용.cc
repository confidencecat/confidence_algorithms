#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int n, m, mod = 1e9;
int d[100001], sv[100001], ev[100001];
long long int sum, ans, cnt[100001];

int find(int a) {
	if (a == d[a]) return a;
	return d[a] = find(d[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) d[b] = a;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		d[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int ss, ee, vv;
		scanf("%d %d %d", &ss, &ee, &vv);
		sv[vv] = ss;
		ev[vv] = ee;
		sum += vv;
	}
	
	sum %= mod;
	
	for (int i = 100000; i > 0; i--) {
		if (sv[i] != 0) {
			int sf = find(sv[i]), ef = find(ev[i]);
			if (sf != ef) {
				ans = (ans + sum * cnt[sf] * cnt[ef]) % mod;
				d[ef] = sf;
				cnt[sf] += cnt[ef];
			}
			sum = (sum - i + mod) % mod;
		}
	}
	printf("%lld", ans);
	return 0;
}