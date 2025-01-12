#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    n /= 100;
    for (int i = 0; i < 100; i++) {
        if ((n * 100 + i) % m == 0) {
            printf("%d%d\n", i/10, i%10);
            return 0;
        }
    }
    return 0;
}
