#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, a[6] = {500, 100, 50, 10, 5, 1}, ans = 0;
    scanf("%d", &n);
    for (int i = 0, m = 1000 - n; i < 6; i++) {
        ans += m / a[i];
        m %= a[i];
    }
    printf("%d\n", ans);

    return 0;
}
