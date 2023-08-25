#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define max(a, b, c) a > b ? (a > c ? a : c) : (b > c ? b : c);

int a[10001], b[10001][3];

int main() {
	//freopen("input.txt", "rt", stdin);
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	b[1][0] = a[0];
	b[1][1] = a[1];
	b[1][2] = a[0] + a[1];

	for (int i = 2; i <= n; i++) {
		b[i][0] = max(b[i - 1][0], b[i - 1][1], b[i - 1][2]);

		b[i][1] = a[i] + b[i - 1][0];
		b[i][2] = a[i - 1] + a[i] + b[i - 2][0];

	}
	printf("%d\n", b[n][0]);
	return 0;
}
