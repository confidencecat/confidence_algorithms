#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MOD 1000000007

int n;
int a[5000], nondec[5000], noninc[5000];
long long dp[5001];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    nondec[n - 1] = n - 1;
    noninc[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        nondec[i] = a[i] <= a[i + 1] ? nondec[i + 1] : i;
        noninc[i] = a[i] >= a[i + 1] ? noninc[i + 1] : i;
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int r = (nondec[i] > noninc[i]) ? nondec[i] : noninc[i];
        for (int j = i; j <= r; j++) {
            dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
        }
    }

    printf("%lld\n", dp[n]);
    return 0;
}

