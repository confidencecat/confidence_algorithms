#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        if (n == 1) printf("0\n");
        else {
            printf("1");
            for (int i = 0; i < n - 2; i++) {
                printf("2");
            }
            printf("1\n");
        }
    }
    return 0;
}
