#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, k, an = 1, b, a[300001], m[300001], mi = 1000000000, ans = 0;

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int main() {
    scanf("%d %d", &n, &k);

    scanf("%d", &a[0]);
    for (int i = 1; i < n; i++) {
        scanf("%d", &b);
        if (a[an - 1] != b) a[an++] = b;
    }

    for (int i = 0; i < an - 1; i++) m[i] = a[i + 1] - a[i];
    qsort(m, an - 1, sizeof(m[0]), com);

    for (int i = 0; i < an - k; i++) {
        ans += m[i];
    }
    printf("%d\n", ans);

    return 0;
}
