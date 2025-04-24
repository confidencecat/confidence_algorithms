#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, j;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n-1; i++) {
        for (j = n - i - 1; j > 0; j--, printf(" "));
        for (printf("*"), j = 0; j < i * 2 - 1; j++, printf(" "));
        printf("%s", i==0?"\n":"*\n");
    }
    for (int i = 0; i < n * 2 - 1; i++) printf("*");

    return 0;
}
