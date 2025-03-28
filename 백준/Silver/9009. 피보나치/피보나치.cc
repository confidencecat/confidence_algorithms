#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int fibo[44] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733 };
long long int c[44];
int cn = 0;
int t, n;

int main() {
    for (scanf("%d", &t); t; t--) {
        scanf("%d\n", &n);
        cn = 0;
        for (int i = 43; i >= 0; i--) {
            if (fibo[i] <= n && n - fibo[i] >= 0) {
                n -= fibo[i];
                c[cn++] = fibo[i];
                if (n == 0) break;
            }
        }
        for (int i = cn - 1; i >= 0; i--) printf("%lld ", c[i]);
        printf("\n");
    }

    return 0;
}
