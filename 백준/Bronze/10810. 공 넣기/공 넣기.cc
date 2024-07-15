#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n, m, s, e, k, a[101];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &s, &e, &k);

        for (int j = s; j <= e; j++) {
            a[j] = k;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
