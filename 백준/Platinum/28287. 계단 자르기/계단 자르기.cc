#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

long long int com[103], dp[103];

int main() {
    int n;
    long long int mod;
    scanf("%d %lld", &n, &mod);
    com[0] = 1;
    for (int i = 1; i <= n + 2; i++) {
        for (int j = 0; j <= i - 1; j++) {
            com[i] = (com[i] + (com[j] * com[i - j - 1] % mod)) % mod;
        }
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * com[i + 1] + com[i] - com[i + 2] + mod) % mod;

        for (int j = 1; j <= i - 1; j++) {
            dp[i] = (dp[i] + ((2 * (i - j) + 1) * com[j] % mod * com[i - j] % mod)) % mod;
            dp[i] %= mod;
        }

        for (int j = 1; j <= i; j++) {
            dp[i] = (dp[i] + (((com[j - 1] * dp[i - j]) + (dp[j - 1] * com[i - j])) % mod)) % mod;
        }

    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", dp[i]);
    }
    return 0;
}
