#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int n, a, b, ans = 0;
    scanf("%d %d %d", &n, &a, &b);

    while (a++ != b++) {
        a /= 2;
        b /= 2;
        ans++;
    }
    printf("%d\n", ans);

    return 0;
}
