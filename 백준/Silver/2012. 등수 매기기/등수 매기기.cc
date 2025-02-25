#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int n;
long long ans = 0;
int a[500001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(a[0]), com);

    for (int i = 1; i <= n; i++) {
        ans += (long long)abs((a[i - 1] - i));
    }
    printf("%lld\n", ans);

    return 0;
}

