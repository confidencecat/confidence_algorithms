#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int max = -1, j = 0, a;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &a);
        if (a > max) {
            max = a;
            j = i;
        }
    }
    printf("%d\n%d\n", max, j + 1);
    return 0;
}