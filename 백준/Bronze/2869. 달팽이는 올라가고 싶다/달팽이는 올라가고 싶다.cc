#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ans = 0, n, m, v;
	scanf("%d %d %d", &n, &m, &v);

	ans = (v - n) / (n - m) + ((v - n) % (n - m) == 0 ? 1 : 2);
	printf("%d\n", ans);
	return 0;
}