#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n;
float f[100001], ans = 0;

int com(const void* A, const void* B) {
    return *(float*)A - *(float*)B;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%f", &f[i]);
    qsort(f, n, sizeof(f[0]), com);
    for (int i = 0; i < n - 1; i++) {
        ans += f[i] / 2;
    }
    printf("%f\n", ans + f[n - 1]);

    return 0;
}
