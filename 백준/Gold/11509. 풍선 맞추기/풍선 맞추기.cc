#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, ans = 1;
int a;
int dp[1000001];

int main() {

    scanf("%d", &n);

    scanf("%d", &a);
    dp[a - 1] = 1;
    
    for (int i = 1; i < n; i++) {
        scanf("%d", &a);
        if (dp[a] >= 1) {
            dp[a]--;
            if(a != 1) dp[a - 1]++;
        }
        else {
            ans++;
            dp[a - 1]++;
        }
        /*for (int j = 1; j <= 6; j++) {
            printf("%d ", dp[j]);
        }
        printf("\n");*/
    }
    printf("%d\n", ans);

    return 0;
}
