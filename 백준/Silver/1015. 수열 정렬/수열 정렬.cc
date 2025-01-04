#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}


int main() {
    //freopen("input.txt", "rt", stdin);

    int n, a[51], b[51], c[51];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = 0;
    }
    qsort(a, n, sizeof(int), com);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //printf("%d %d %d\n", b[i], a[j], c[j]);
            if (c[j] == 1) continue;
            if (b[i] == a[j]) {
                printf("%d ", j);
                c[j] = 1;
                break;
            }
        }
        //printf("\n\n");
    }

    return 0;
}
