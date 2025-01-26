#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int n;

int main() {
    //freopen("input.txt", "r", stdin);

    scanf("%lld", &n);

    for (long long int i = 1, s = 0; i <= 2147483648; i++) {
        if (s + i > n) {
            printf("%lld\n", i - 1);
            break;
        }
        s += i;
        //printf("%lld : %lld\n", i, s);
    }

    return 0;
}
