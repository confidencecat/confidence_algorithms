#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, dp[13] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600 };
	scanf("%d", &n);
	printf("%d", dp[n]);
	return 0;
}