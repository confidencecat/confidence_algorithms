#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum = 0, a;

int main() {
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a);
        sum += (a < 40 ? 40 : a);
    }
    printf("%d\n", sum / 5);

    return 0;
}
