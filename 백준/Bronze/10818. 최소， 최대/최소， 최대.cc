#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, n, mx = -1000001, mi = 1000001;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a > mx) {
            mx = a;
        }
        if (a < mi) {
            mi = a;
        }
    }
    printf("%d %d", mi, mx);
    return 0;
}