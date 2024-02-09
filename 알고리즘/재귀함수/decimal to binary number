#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void f(int a) {
	if (a == 0) return;
	f(a / 2);
	printf("%d", a % 2);
}

int main() {
	int n;
	scanf("%d", &n);

	f(n);
	return 0;
}
