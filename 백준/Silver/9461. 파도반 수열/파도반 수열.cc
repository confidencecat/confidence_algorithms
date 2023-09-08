#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int a[102] = { 1, 1, 1, };

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        if (a[m] != 0) {
            printf("%lld\n", a[m - 1]);
        }
        else {
            for (int j = 3; j <= m; j++) {
                a[j] = a[j - 3] + a[j - 2];
            }
            printf("%lld\n", a[m - 1]);
        }
    }

    return 0;
}