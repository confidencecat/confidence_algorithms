#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int s, sum = 0, a;
    scanf("%d", &s);
    for (int i = 0; i < 9; i++) {
        scanf("%d", &a);
        sum += a;
    }
    printf("%d", s - sum);
    return 0;
}
