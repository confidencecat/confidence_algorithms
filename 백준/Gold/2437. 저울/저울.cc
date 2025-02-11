#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef long long int ll;

int n, a[1001];
ll s = 1;

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(a[0]), com);

    for (int i = 0; i < n; i++) {
        if (a[i] > s) break;
        s += a[i];
    }
    printf("%lld\n", s);
    return 0;
}
