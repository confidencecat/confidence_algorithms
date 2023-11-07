#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a[10001];

int main() {
    int n, k;
    int c[101];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    a[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = c[i]; j <= k; j++) {
            a[j] += a[j - c[i]];
        }
    }
    printf("%d\n", a[k]);
    return 0;
}
