#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    int n, count = 9;
    long long dp[1023] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    scanf("%d", &n);

    if (n > 1022) printf("-1\n");
    else {
        int i = 0;
        while(count < n) {
            for (int j = 0; j < dp[i] % 10; j++) dp[++count] = dp[i] * 10 + j;
            i++;
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
