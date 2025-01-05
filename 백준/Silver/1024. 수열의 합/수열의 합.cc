#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, l;

    scanf("%d %d", &n, &l);

    for (int i = l; i <= 100; i++) {
        int temp = n - (i * (i - 1)) / 2;
        if (temp % i == 0) {
            int a1 = temp / i;
            if (a1 >= 0) {
                for (int j = 0; j < i; j++) {
                    printf("%d ", a1 + j);
                }
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}
