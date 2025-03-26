#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int n, m, a[1001];
int ans = 0, p = 0;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    qsort(a, m, sizeof(a[0]), com);

    for (int i = (m - n < 0 ? 0 : m - n); i < m; i++) {
        if (a[i] * (m - i) > ans) {
            p = a[i];
            ans = a[i] * (m - i);
        }
    }

    printf("%d %d", p, ans);
    return 0;
}
