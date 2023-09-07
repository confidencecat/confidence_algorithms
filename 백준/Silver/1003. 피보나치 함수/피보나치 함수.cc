#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
long long int dp[42] = {1, 0, 1};

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        if (m < 2) printf("%d %d\n", dp[m], dp[m + 1]);
        else if (dp[m + 1] != 0) printf("%d %d\n", dp[m], dp[m + 1]);
        else {
            for (int i = 2; i <= m + 1; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            printf("%d %d\n", dp[m], dp[m + 1]);
        }
    }
    return 0;
}