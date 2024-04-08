#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define mod 1000000009

long long int n, t, dp[1000001];

int main() {
    //freopen("input.txt", "rt", stdin);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 1000001; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}

