#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) ((a) > (b)? (a) : (b))

int n, a[201];
int dp[201], ans = 0;


int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    printf("%d", n - ans);

    return 0;
}