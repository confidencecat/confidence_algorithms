#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, c[10001];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int i = n - 1;
    while (i > 0 && c[i - 1] <= c[i]) {
        i--;
    }
    if (i <= 0) {
        printf("-1");
        return 0;
    }

    int j = n - 1;
    while (c[j] >= c[i - 1]) {
        j--;
    }

    int temp = c[i - 1];
    c[i - 1] = c[j];
    c[j] = temp;

    int start = i, end = n - 1;
    while (start < end) {
        temp = c[start];
        c[start] = c[end];
        c[end] = temp;
        start++;
        end--;
    }

    for (int k = 0; k < n; k++) {
        printf("%d ", c[k]);
    }

    return 0;
}
