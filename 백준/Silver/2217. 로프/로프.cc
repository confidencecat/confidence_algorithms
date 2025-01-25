#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, a[100001], mx = 0;

int com(const void* A, const void* B) {
    return *(int*)B - *(int*)A;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), com);
    //for (int i = 0; i < n; i++) printf("%d ", a[i]);
    
    for (int i = 0; i < n; i++) {
        mx = a[i] * (i + 1) > mx ? a[i] * (i + 1) : mx;
    }

    printf("%d\n", mx);

    return 0;
}
