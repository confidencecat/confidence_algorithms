#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int min(int a, int b) {
    return a > b ? b : a;
}

int a, dp[1000001];

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &a);

    
    for (int i = 2; i <= a; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    printf("%d\n", dp[a]);
    return 0;
}
