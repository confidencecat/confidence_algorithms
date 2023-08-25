#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define max(a, b) a > b ? a : b

int n, a[102][102];
long long int dp[102][102];

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	dp[n - 1][n - 1] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] != 0) {
				dp[i][j] = dp[i + a[i][j]][j] + dp[i][j + a[i][j]];
			}
		}
	}


	printf("%lld\n", dp[0][0]);
	return 0;
}