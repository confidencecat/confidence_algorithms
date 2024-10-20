#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	long long int n, t = 2;
	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		t = t * 2 - 1;
	}
	printf("%lld", t * t);
	return 0;
}