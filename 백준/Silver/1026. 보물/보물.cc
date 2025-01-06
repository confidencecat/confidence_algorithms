#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int coma(const void* a, const void* b) { return *(int*)a < *(int*)b; }
int comb(const void* a, const void* b) { return *(int*)a > *(int*)b; }

int main() {
    //freopen("input.txt", "rt", stdin);

    int n, sum = 0, a[51], b[51];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    qsort(a, n, sizeof(int), coma);
    qsort(b, n, sizeof(int), comb);

    for (int i = 0; i < n; i++) sum += a[i] * b[i];
    printf("%d\n", sum);
    return 0;
}
