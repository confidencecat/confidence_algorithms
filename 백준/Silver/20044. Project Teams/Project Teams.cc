#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define min(c, b) ((c) < (b) ? (c) : (b))
using namespace std;

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int n, a[10001], ans = 200002;

int main() {

    scanf("%d", &n);
    for (int i = 0; i < 2*n; i++) scanf("%d", &a[i]);
    qsort(a, 2*n, sizeof(a[0]), com);

    for (int i = 0; i < n; i++)
        ans = min(a[i] + a[2*n - i - 1], ans);
    printf("%d\n", ans);
    return 0;
}