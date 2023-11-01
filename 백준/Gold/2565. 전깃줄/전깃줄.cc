#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#define max(a, b) a > b ? a : b

typedef struct {
    int a, b;
}r;

int com(const void* first, const void* second) {
    return ((r*)first)->a - ((r*)second)->a;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, dp[101], mx = 0;
    r a[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].a, &a[i].b);
    }
    qsort(a, n, sizeof(r), com);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i].b > a[j].b) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (mx < dp[i]) mx = dp[i];
    }
    printf("%d", n - mx);
    return 0;
}
