#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, ans = 0;
int d[10001], a[10001][2];

int com(const void* A, const void* B) {
    int* aa = (int*)A;
    int* bb = (int*)B;
    return bb[0] - aa[0];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    qsort(a, n, sizeof(a[0]), com);

    for (int i = 0; i < n; i++) {
        for (int j = a[i][1]; j >= 1; j--) { 
            if (d[j] == 0) {
                d[j] = 1;
                ans += a[i][0];
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
