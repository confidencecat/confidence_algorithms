#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int fib(int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return (fib(n - 1) + fib(n - 2));
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	printf("%d %d", fib(n), n - 2);
	return 0;
}