#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            k--;
            if (k == 0) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    printf("0\n");
    return 0;
}
