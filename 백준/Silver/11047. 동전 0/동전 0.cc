#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, m, a[1000001], i = 1, ans = 0;

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	while (m > 0) {
		ans += m / a[n - 1];
		m = m % a[n - 1];
		n--;
	}
	printf("%d\n", ans);
	return 0;
}