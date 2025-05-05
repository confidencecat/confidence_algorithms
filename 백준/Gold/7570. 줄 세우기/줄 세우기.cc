#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) (a > b ? a : b)

int n, a[1000001];
int s[1000001], ch[1000001], dp[1000001];

int main() {

    scanf("%d", &n);

    scanf("%d", &a[0]);
    s[0] = 1;
    ch[a[0]] = 1;
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        s[i] = 1;
        if (ch[a[i] - 1] != 0) {
            s[i] = s[ch[a[i] - 1] - 1] + 1;
        }
        dp[i] = max(dp[i-1], s[i]);

        ch[a[i]] = i + 1;
        
    }
    printf("%d\n", n - dp[n - 1]);

    return 0;
}