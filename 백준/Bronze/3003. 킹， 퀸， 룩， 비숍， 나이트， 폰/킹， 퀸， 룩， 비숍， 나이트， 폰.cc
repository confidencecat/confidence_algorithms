#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	printf("%d %d %d %d %d %d", 1 - a, 1 - b, 2 - c, 2 - d, 2 - e, 8 - f);
	return (0);
}