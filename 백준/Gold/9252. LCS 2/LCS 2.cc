#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b

int dp[1001][1001], an, bn, ans[1001], ans_n;

int main() {
    //freopen("input.txt", "rt", stdin);
    char a[1001], b[1001];
    scanf("%s %s", a, b);
    an = strlen(a);
    bn = strlen(b);

    for (int i = 0; i <= an; i++) {
        for (int j = 0; j <= bn; j++) {
            if (i == 0 || j == 0) dp[0][0] = 0;
            else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("%d\n", dp[an][bn]);
    int i = an, j = bn, c = 1;
    while (i != 0 && j != 0) {
        if (dp[i][j] == dp[i - 1][j]) i--;
        else if (dp[i][j] == dp[i][j - 1]) j--;
        else {
            ans[ans_n++] = a[--i];
            j--;
        }
    }
    for (int i = ans_n - 1; i >= 0; i--) printf("%c", ans[i]);
    return 0;
}
