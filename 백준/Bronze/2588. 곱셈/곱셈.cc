#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b, ans = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    ans += a * (b % 10);
    printf("%d\n", a * (b % 10));
    ans += a * ((b / 10) % 10) * 10;
    printf("%d\n", a * ((b / 10) % 10));
    ans += a * ((b / 100) % 10) * 100;
    printf("%d\n%d", a * ((b / 100) % 10), ans);

    return 0;
}
