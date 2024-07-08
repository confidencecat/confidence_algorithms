#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) a > b ? b : a

int a[1001], dp[1001], n, ans = 1;

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);

    scanf("%d", &a[0]);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] > max) {
                max = dp[j];
            }
        }
        dp[i] = max == 0 ? 1 : (max + 1);
        ans = ans < dp[i] ? dp[i] : ans;
    }
    printf("%d\n", ans);
    return 0;
}
