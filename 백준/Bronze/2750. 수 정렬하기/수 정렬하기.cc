#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int com(const void* A, const void* B) {
	return *(int*)A - *(int*)B;
}

int main() {
	int n, a[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), com);
	for (int i = 0; i < n; i++) printf("%d\n", a[i]);
	return 0;
}