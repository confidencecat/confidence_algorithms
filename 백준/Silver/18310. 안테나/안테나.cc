#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, mx = 0, mi = 100001;
int a[200001], ans = 0;

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(a[0]), com);
    printf("%d\n", a[(n - 1) / 2]);


    return 0;
}

