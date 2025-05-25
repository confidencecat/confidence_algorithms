#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}


int main() {
    int n = 5, a[6], sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    qsort(a, n, sizeof(a[0]), com);
    printf("%d\n%d", sum / 5, a[2]);

    return 0;
}



