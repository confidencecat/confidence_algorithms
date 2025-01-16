#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
    
    int n;
    scanf("%d", &n);

    int ans = 0, l = 0, a = 1;

    while (1) {
        if (n < 10) break;
        l = 0; a = 1;
        while (n) {
            a *= (n % 10);
            n /= 10;
        }
        ans++;
        n = a;
    }
    printf("%d\n", ans);

    return 0;
}
