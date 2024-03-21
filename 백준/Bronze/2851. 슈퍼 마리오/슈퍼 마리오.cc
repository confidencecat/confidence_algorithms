#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int a[11], sum = 0;

int main() {
    //freopen("input.txt", "rt", stdin);
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (abs(100 - (sum + a[i])) <= abs(sum - 100))
            sum += a[i];
        else break;
    }
    printf("%d\n", sum);
    return 0;
}

