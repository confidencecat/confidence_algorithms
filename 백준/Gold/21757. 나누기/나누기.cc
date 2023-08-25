#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long d[4][100001];
int a, b, n, s[1000001];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (i == 0) s[i] = a;
		else s[i] = s[i - 1] + a;
	}
	if (s[n - 1] % 4 != 0) {
		printf("0");
		return 0;
	}
	if (s[0] == s[n - 1] / 4) d[1][0] = 1;

	for (int i = 1; i < n; i++) {
		if (s[i] == s[n - 1] / 4) d[1][i] = d[1][i - 1] + 1;
		else d[1][i] = d[1][i - 1];
	}
	for (int i = 2; i <= 3; i++) {
		b = s[n - 1] / 4 * i;
		for (int j = i - 1; j < n; j++) {
			if (s[j] == b) d[i][j] = d[i][j - 1] + d[i - 1][j - 1];
			else d[i][j] = d[i][j - 1];
		}
	}
	printf("%lld", d[3][n - 2]);
	return 0;
}