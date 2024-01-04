#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	long long int a[100] = {0, 1, 1};
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	printf("%lld", a[n]);
	return 0;
}