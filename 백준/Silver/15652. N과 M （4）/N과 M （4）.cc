#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int n, m, c[9];

void f(int x, int xn) {
    if (xn == m) {
        xn = 0;
        for (int i = 0; i < m; i++) {
            printf("%d ", c[i]);
        }
        printf("\n");
    }
    else {
        for (int i = x; i <= n; i++) {
            c[xn] = i;
            f(i, xn + 1);
            c[xn] = 0;
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);
    f(1, 0);
    return 0;
}
