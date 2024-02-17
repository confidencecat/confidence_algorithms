#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int N, i, j, k, l, count = 0;
    int sums[1001] = { 0 };

    scanf("%d", &N);

    for (i = 0; i <= N; i++) { 
        for (j = 0; j <= N - i; j++) {
            for (k = 0; k <= N - i - j; k++) {
                l = N - i - j - k;
                int sum = i * 1 + j * 5 + k * 10 + l * 50;
                if (!sums[sum]) {
                    sums[sum] = 1;
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
