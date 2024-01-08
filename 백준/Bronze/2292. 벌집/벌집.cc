#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, c = 1;
	scanf("%d", &n);
	for (int m = 1; m < n; m += c++ * 6);
	printf("%d\n", c);
	return 0;
}