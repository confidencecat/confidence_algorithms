#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int a, ans = 0, n;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a);
        ans += a * a;
    }
    printf("%d", ans % 10);
    return 0;
}