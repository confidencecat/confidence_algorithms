#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) a > b ? b : a

int d[1001], a[1001], n;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            d[i] = min((d[i] == 0 ? 100000000 : d[i]), d[i - j] + a[j]);
        }
    }

    printf("%d\n", d[n]);

    return 0;
}
