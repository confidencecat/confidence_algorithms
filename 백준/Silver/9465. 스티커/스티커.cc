#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define max(a, b) a > b ? a : b

int n, a[2][100001];
int c[100001][3];

int main() {
	int m;
	scanf("%d", &m);
	for (int j = 0; j < m; j++) {
		scanf("%d", &n);
		for (int i = 0; i < 2 * n; i++) {
			scanf("%d", &a[i < n ? 0 : 1][i < n ? i : i - n]);
		}

		c[0][0] = 0;//x
		c[0][1] = a[0][0];//위
		c[0][2] = a[1][0];//아래
		for (int i = 1; i < n; i++) {
			c[i][0] = max(c[i - 1][2], c[i - 1][1]);
			c[i][1] = max(a[0][i] + c[i - 1][2], a[0][i] + c[i - 1][0]);
			c[i][2] = max(a[1][i] + c[i - 1][1], a[1][i] + c[i - 1][0]);
		}
		int b = max(c[n - 1][1], c[n - 1][2]);
		printf("%d\n", max(c[n - 1][0], b));
	}
	return 0;
}