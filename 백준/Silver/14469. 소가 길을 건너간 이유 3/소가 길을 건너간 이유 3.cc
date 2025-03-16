#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, a[101][2], ans = 0;

int com(const void* A, const void* B) {
    int* AA = (int*)A;
    int* BB = (int*)B;
    return AA[0] - BB[0];
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    qsort(a, n, sizeof(a[0]), com);

    for (int i = 0; i < n; i++) {
        if (a[i][0] >= ans) ans = a[i][0] + a[i][1];
        else ans += a[i][1];
    }
    printf("%d\n", ans);
    return 0;
}
