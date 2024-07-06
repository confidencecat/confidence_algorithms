#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m = 0;

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d", &n);

    while (n >= 0) {
        if (n % 5 == 0) {
            printf("%d", m + n / 5);
            return 0;
        }
        m++;
        n -= 3;
    }
    printf("-1");
    return 0;
}
