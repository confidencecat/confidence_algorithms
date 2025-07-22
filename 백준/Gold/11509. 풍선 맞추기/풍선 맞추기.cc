#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, ans = 1;
int a[1000001];
int dp[1000001];

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    dp[a[0] - 1] = 1;
    
    for (int i = 1; i < n; i++) {
        if (dp[a[i]] >= 1) {
            dp[a[i]]--;
            if(a[i] != 1) dp[a[i] - 1]++;
        }
        else {
            ans++;
            dp[a[i] - 1]++;
        }
        /*for (int j = 1; j <= 6; j++) {
            printf("%d ", dp[j]);
        }
        printf("\n");*/
    }
    printf("%d\n", ans);

    return 0;
}
