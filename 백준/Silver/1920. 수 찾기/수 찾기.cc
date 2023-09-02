#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int narr[100000];
int marr[100000];

int f(int arr[], int key, int size) {
    int f, r, p;
    f = 0;
    r = size - 1;

    while (1) {
        p = (f + r) / 2;
        if (arr[p] == key) return 1;
        if (arr[f] == key) return 1;
        if (arr[r] == key) return 1;

        if (arr[p] < key)
            f = p + 1;
        else
            r = p - 1;

        if (f >= r)
            return 0;
    }
}

int cmp(const void* a, const void* b) {
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main() {
    int n, m;
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &narr[i]);
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &marr[i]);
    }

    qsort(narr, n, sizeof(int), cmp);

    for (i = 0; i < m; i++) {
        printf("%d\n", f(narr, marr[i], n));
    }

    return 0;
}
