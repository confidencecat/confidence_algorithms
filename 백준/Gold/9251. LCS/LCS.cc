#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b

int dp[1001][1001], an, bn;

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
    return 0;
}
