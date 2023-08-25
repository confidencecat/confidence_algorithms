#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define max(a, b) a > b ? a : b
int n, t[1500002], p[1500002];
int dp[1500002];
int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &t[i], &p[i]);
		
	}
    for (int i = n; i >= 1; i--){
        if (i + t[i] > n + 1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
        }
    }
	printf("%d", dp[1]);
	return 0;
}