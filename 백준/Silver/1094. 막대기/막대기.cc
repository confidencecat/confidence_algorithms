#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int n = 64, min = 64, x, ans = 1;
    scanf("%d", &x);

    while (n != x) {
        if (x < n) {
            min = min / 2;
            if (n - min >= x) {
                n -= min;
                ans--;
            }
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
