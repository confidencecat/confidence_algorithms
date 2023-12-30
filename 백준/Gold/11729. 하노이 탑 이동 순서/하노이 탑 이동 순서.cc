#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void f(int m, int a, int b, int c) {
    if (m == 1) printf("%d %d\n", a, c);
    else {
        f(m - 1, a, c, b);
        printf("%d %d\n", a, c);
        f(m - 1, b, a, c);
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, ans = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) ans *= 2;
    printf("%d\n", ans - 1);
    f(n, 1, 2, 3);
    return 0;
}
