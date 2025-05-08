#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[50] = {1, }, b[50];
int k;

int main() {

    scanf("%d", &k);

    for (int i = 1; i <= k; i++) {
        a[i] = b[i - 1];
        b[i] = a[i - 1] + b[i - 1];
    }
    printf("%d %d\n", a[k], b[k]);

    return 0;
}
