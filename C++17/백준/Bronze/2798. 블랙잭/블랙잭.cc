#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, a[101], max_sum = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int l = j + 1; l < n; l++) {
                int sum = a[i] + a[j] + a[l];
                if (sum <= m && sum > max_sum) {
                    max_sum = sum;
                }
            }
        }
    }
    printf("%d", max_sum);
    return 0;
}
