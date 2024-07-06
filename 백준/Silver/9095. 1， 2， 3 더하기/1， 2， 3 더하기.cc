#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    

    int t, dp[12] = {0, 1, 2, 4, }, a;

    scanf("%d", &t);
    
    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    
    while (t--) {
        scanf("%d", &a);
        printf("%d\n", dp[a]);
    }
    return 0;
}
