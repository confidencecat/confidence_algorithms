#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int n, dp[5005];
char s[5005];
int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%s", s);
    n = strlen(s);
    if (s[0] == '0') {
        printf("0\n");
    }
    else {
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0') dp[i] = dp[i - 1];
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (10 <= num && num < 27) dp[i] = (dp[i] + dp[i - 2]) % 1000000;
        }
        printf("%d\n", dp[n]);
    }
    
    return 0;
}