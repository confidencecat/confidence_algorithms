#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int t, m, n;
	scanf("%d %d %d", &t, &m, &n);
	printf("%d %d", (t + (n + m) / 60) % 24, (n + m) % 60);
	return 0;
}