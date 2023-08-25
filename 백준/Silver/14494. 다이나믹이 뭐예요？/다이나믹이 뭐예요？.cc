#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, m;
long long int dp[1002][1002];

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] < dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1])
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007;
		}
	}
	printf("%lld\n", dp[n][m]);
	return 0;
}