#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[300001];

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    double num = n * 0.15;
    if ((int)(num * 10) % 10 >= 5) {
        num = ceil(num);
    } else {
        num = floor(num);
    }

    double sum = 0;
    for (int i = (int)num; i < n - (int)num; i++) {
        sum += arr[i];
    }
    sum /= (n - 2 * (int)num);

    if ((int)(sum * 10) % 10 >= 5) {
        sum = ceil(sum);
    } else {
        sum = floor(sum);
    }

    printf("%.0f\n", sum);

    return 0;
}
