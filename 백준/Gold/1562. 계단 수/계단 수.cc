#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define mod 1000000000

int dp[101][10][1025];

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, ans = 0;
	scanf("%d", &n);

	for (int i = 1; i < 10; i++) {
		dp[1][i][1 << i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				if (j == 0) {
					dp[i][j][k | 1] = (dp[i][0][k | 1] + dp[i - 1][1][k]) % mod;
				}
				else if (j == 9) {
					dp[i][j][k | (1 << 9)] = (dp[i][9][k | 512] + dp[i - 1][8][k]) % mod;
				}
				else {
					dp[i][j][k | 1 << j] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[n][i][1023]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}