#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ST {
    int c = 0;
    long long m = 0;
} st;

int n, m, dp[10001], sum = 0;
st a[101];

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i].m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].c);
        sum += a[i].c;
    }
    for (int i = 1; i <= sum; i++)
        dp[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= a[i].c; j--) {
            if (dp[j - a[i].c] >= 0) {
                if (dp[j - a[i].c] + a[i].m > dp[j])
                    dp[j] = dp[j - a[i].c] + a[i].m;
            }
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (dp[i] >= m) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
