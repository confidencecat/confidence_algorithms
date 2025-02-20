#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int main() {
    
    int n, l;
    int a[1001];
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(a[0]), com);

    for (int i = 0; i < n; i++) {
        if (a[i] <= l) {
            l++;
        }
    }
    printf("%d\n", l);

    return 0;
}
