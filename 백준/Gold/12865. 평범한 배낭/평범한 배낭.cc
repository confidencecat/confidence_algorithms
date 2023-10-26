#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define max(a, b) a > b ? a : b

typedef struct {
    int w, v;
}S;

int dp[100001];
S a[100000];
int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].w, &a[i].v);
    }

    for (int i = 0; i < n; i++) {
        for (int j = m; j > 0; j--) {
            if (a[i].w <= j) {
                if (dp[j] < dp[j - a[i].w] + a[i].v) dp[j] = dp[j - a[i].w] + a[i].v;
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
