#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a, min = 101, sum = 0;


int main() {
    for (int i = 0; i < 7; i++) {
        scanf("%d", &a);
        if (a % 2 == 1) { sum += a; min = min > a ? a : min; }
    }
    if (min == 101) printf("-1");
    else printf("%d\n%d", sum, min);

    return 0;
}
