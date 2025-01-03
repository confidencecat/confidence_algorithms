#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* a, const void* b) {
    return *(int*)a < *(int*)b;
}
int ccom(const void* a, const void* b) {
    return *(int*)a > *(int*)b;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int n, a[51], b[51], ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    qsort(a, n, sizeof(int), ccom);
    qsort(b, n, sizeof(int), com);

    for (int i = 0; i < n; i++) ans += a[i] * b[i];

    printf("%d\n", ans);
    return 0;
}
