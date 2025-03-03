#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, a[100001], c = 0, mi = 1<<31, mx = 0;

int com(const void* A, const void* B) {
    return *(int*)B - *(int*)A;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(a[0]), com);

    for (int i = 0; i < n; i++) {
        a[i] = a[i] - (n - i - 1);
        mx = mx < a[i] ? a[i] : mx;
    }
    printf("%d\n", mx + n + 1);
    return 0;
}
