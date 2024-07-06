#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
    //freopen("input.txt", "rt", stdin);
    
    long long int dp[44] = { 0, 1, 1 };

    for (int i = 3; i <= 41; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int t, a;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &a);
        printf("%lld %lld\n", dp[(a == 0) ? (a + 1) : (a - 1)], dp[a]);
    }
    return 0;
}
