#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int n, sum = 0;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%lld", &n);

    for (int i = 1; i <= n; i++) {
        sum += (i * (n / i));
    }

    printf("%lld", sum);
    return 0;
}
