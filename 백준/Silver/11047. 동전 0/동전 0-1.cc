#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, m, a[1000001], i = 1, ans = 0;

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);
	scanf("%d", &a[0]);
	while (a[i - 1] <= m) {
		scanf("%d", &a[i++]);
	}
	while (m > 0) {
		ans += m / a[i - 1];
		m = m % a[i - 1];
		i--;
	}
	printf("%d\n", ans);
	return 0;
}
