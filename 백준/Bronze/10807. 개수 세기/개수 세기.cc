#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sum[201], n, v, a;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        sum[a < 0 ? -a + 100 : a]++;
    }
    scanf("%d", &v);
    printf("%d\n", sum[v < 0 ? -v + 100 : v]);
    return 0;
}
