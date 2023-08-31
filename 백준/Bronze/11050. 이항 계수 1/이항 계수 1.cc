#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int f(int n, int r) {
	if (r == 0 || n == r) return 1;
	return f(n - 1, r) + f(n - 1, r - 1);
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d", f(n, r));
	return 0;
}