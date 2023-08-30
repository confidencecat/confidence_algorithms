#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int n, t, a, b;
int main() {
	scanf("%d", &n);
	a = 1;
	b = 3;
	for (int i = 0; i < n - 1; i++) {
		t = a;
		a = b;
		b = (t + 2 * b) % 9901;
	}
	printf("%d\n", b);

	return 0;
}