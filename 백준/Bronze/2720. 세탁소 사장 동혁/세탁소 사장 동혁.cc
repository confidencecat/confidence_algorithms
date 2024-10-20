#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//freopen("input.txt", "r", stdin);
	int q = 25, d = 10, n = 5, p = 1;
	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		printf("%d %d %d %d\n", a / q, (a % q) / d, (a % q % d) / n, (a % q % d % n) / p);
	}
	return 0;
}