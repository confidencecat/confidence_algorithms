#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[32], n;

int main() {
    for (int i = 0; i < 30; i++) {
        scanf("%d", &n);
        a[n] = 1;
    }
    for (int i = 1; i <= 30; i++) {
        if (a[i] == 0) printf("%d\n", i);
    }
    return 0;
}