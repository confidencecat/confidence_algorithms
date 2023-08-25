#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n;
	long long int a[1001] = { 0, }, b[11] = { 0, 1, };

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			b[j] += b[j - 1];
			b[j] %= 10007;
			a[i] += b[j];
			a[i] %= 10007;
		}
	}
	printf("%lld", a[n]);
	return 0;
}