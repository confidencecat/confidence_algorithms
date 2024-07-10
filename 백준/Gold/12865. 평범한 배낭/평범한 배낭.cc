#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) a > b ? a : b

int n, k, dp[100001];

typedef struct {
    int w, v;
}S;

S a[100001];

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].w, &a[i].v);
    }

    for (int i = 0; i < n; i++) {
        for (int j = k; j > 0; j--) {
            if (j >= a[i].w) {
                if (dp[j] < dp[j - a[i].w] + a[i].v) dp[j] = dp[j - a[i].w] + a[i].v;
            }
        }
    }

    printf("%d", dp[k]);
    return 0;
}
