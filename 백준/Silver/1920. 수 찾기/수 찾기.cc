#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[100000], n, m, ma;

int f(int a) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == a) return 1;
        else if (a < arr[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return 0;
}

int cmp(const void* a, const void* b) {
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &ma);
        printf("%d\n", f(ma));
    }

    return 0;
}
