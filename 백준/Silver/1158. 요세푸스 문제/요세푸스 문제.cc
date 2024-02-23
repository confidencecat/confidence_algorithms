#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	//freopen("input.txt", "rt", stdin);
	int arr[5000], m, n, k;

	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		arr[i] = i + 1;
	}
	k = n - 1;
	printf("<%d", arr[k]);
	for (m = m; m > 1; m--) {
		for (int i = k--; i < m - 1; i++) arr[i] = arr[i + 1];
		k = (k + n) % (m - 1);
		printf(", %d", arr[k]);
	}
	printf(">");
	return 0;
}