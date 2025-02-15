#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
	return *(int*)A - *(int*)B;
}

int n, k, a[10001], sub[10001], ans = 0;

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	qsort(a, n, sizeof(a[0]), com);
	for (int i = 1; i < n; i++) sub[i - 1] = -1 * (a[i] - a[i - 1]);
	qsort(sub, n - 1, sizeof(sub[0]), com);
	ans = a[n - 1] - a[0];
	for (int i = 0; i < k - 1; i++) ans += sub[i];
	printf("%d\n", ans);


	return 0;
}