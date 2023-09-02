#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int n1 = *(int*)a, n2 = *(int*)b;
    if (n1 < n2)
        return -1;
    else if (n1 > n2)
        return 1;
    return 0;
}

int f(int* arr, int val, int n) {
    int first = 0, last = n, mid;
    while (last > first) {
        mid = (first + last) / 2;
        arr[mid] > val ? last = mid : (first = mid + 1);
    }
    int temp = last;
    first = 0, last = n;
    while (last > first) {
        mid = (first + last) / 2;
        arr[mid] >= val ? last = mid : (first = mid + 1);
    }
    return temp - last;
}

int main() {
    int n, m, val;
    scanf("%d", &n);
    int card[500000];
    for (int i = 0; i < n; i++)
        scanf("%d", &card[i]);
    qsort(card, n, sizeof(int), cmp);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        printf("%d ", f(card, val, n));
    }
}
