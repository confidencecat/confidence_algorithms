#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int dp[1001][1001];

int c(int n, int k) {
    if (dp[k][n] != 0) return dp[k][n];
    int ans = 0;
    if (k == n || k == 0) ans = 1;
    else if (k == 1) ans = n;
    else ans = c(n - 1, k - 1) + c(n - 1, k);
    ans %= 10007;
    dp[k][n] = ans;
    dp[n - k][n] = ans;
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", c(n, k));
    return 0;
}