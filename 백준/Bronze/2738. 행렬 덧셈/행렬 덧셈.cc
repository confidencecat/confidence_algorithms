#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, a[101][101], b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &b);
			a[i][j] += b;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}