#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int n, m;
    int a[102];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) a[i] = i;

    for (int i = 0; i < m; i++) {
        int c, s, e;
        scanf("%d %d", &s, &e);
        c = a[s];
        a[s] = a[e];
        a[e] = c;
    }

    for (int i = 1; i <= n; i++) printf("%d ", a[i]);

    return 0;
}
