#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define max(a, b) a > b ? a : b

int a[10001], b[10001];

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    b[1] = a[1];
    b[2] = a[1] + a[2];
    for (int i = 3; i <= n; i++) {
        b[i] = max(b[i - 2] + a[i], b[i - 3] + a[i - 1] + a[i]);
    }
    printf("%d\n", b[n]);
    return 0;
}