#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long long sumOnes(unsigned long long n) {
    unsigned long long total = 0;
    for (int k = 0; (1ULL << k) <= n; ++k) {
        unsigned long long bitVal = 1ULL << k;
        unsigned long long period = bitVal << 1;
        unsigned long long fullCycles = (n + 1) / period;
        unsigned long long remainder = (n + 1) % period;
        unsigned long long contrib = fullCycles * bitVal;
        if (remainder > bitVal) {
            contrib += remainder - bitVal;
        }
        total += contrib;
    }
    return total;
}

int main(void) {
    unsigned long long A, B;
    unsigned long long ans;

    if (scanf("%llu %llu", &A, &B) != 2) {
        return 1;
    }

    ans = sumOnes(B) - sumOnes(A - 1);

    printf("%llu\n", ans);
    return 0;
}
