#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, ans = 0, a;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		m = i;
		a = i;
		while (m > 0) {
			a += m % 10;
			m /= 10;
		}
		if (a == n) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}