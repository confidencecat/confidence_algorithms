#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) a > b ? a : b

int n, a[16][2];
int dp[22];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    for (int i = 0; i < n; i++) {
        
        dp[i + a[i][0]] = max(dp[i + a[i][0]], dp[i] + a[i][1]);
        
        for (int j = i + a[i][0]; j <= n; j++) {
            dp[j] = max(dp[j - 1], dp[j]);
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}
