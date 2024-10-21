#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	long long int x1 = 10000, x2 = -10000, y1 = 10000, y2 = -10000;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		long long int a, b;
		scanf("%lld %lld", &a, &b);
		x1 = min(x1, a);
		y1 = min(y1, b);
		x2 = max(x2, a);
		y2 = max(y2, b);
	}
	printf("%lld", abs((x2 - x1)) * abs((y2 - y1)));
	return 0;
}