#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef long long int ll;

int com(const void* A, const void* B) {
    return *(int*)B - *(int*)A;
}

int n, a[1000001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(a[0]), com);
    bool t = false;
    for (int i = 0; i < n - 2; i++) {
        if (a[i] >= a[i + 1] + a[i + 2]) continue;
        printf("%d\n", a[i] + a[i + 1] + a[i + 2]);
        t = true;
        break;
    }
    if (!t) printf("-1");
    return 0;
}
