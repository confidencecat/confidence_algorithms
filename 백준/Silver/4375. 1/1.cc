#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int n;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    while (scanf("%lld", &n) != EOF) {
        long long int a = 0, j = 0;
        while (1) {
            j++;
            a = 10 * a + 1;
            if (a % n == 0) {
                printf("%d\n", j);
                break;
            }
            a = a % n;
        }

    }

    return 0;
}
