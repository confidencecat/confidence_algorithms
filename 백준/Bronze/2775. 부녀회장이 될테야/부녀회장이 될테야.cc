#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t, n, k, dp[15][15];

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &t);
	for (int j = 0; j <= 14; j++) {
		dp[0][j] = j;
	}
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

			}
		}
		printf("%d\n", dp[n][k]);
	}
	return 0;
}