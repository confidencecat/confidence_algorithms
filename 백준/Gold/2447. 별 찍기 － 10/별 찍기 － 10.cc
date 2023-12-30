#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int n, a[6562][6561];

void make(int x, int y) {
    for (int i = x - 2; i <= x; i++) {
        a[y - 2][i] = 1;
        a[y][i] = 1;
        if (i != x - 1) a[y - 1][i] = 1;
    }
}

void f(int m, int x, int y) {
    if (m == 3) {
        make(x, y);
    }
    else {
        for (int i = 3; i >= 1; i--) {
            for (int j = 3; j >= 1; j--) {
                if (i == 2 && j == 2) continue;
                f(m / 3, x - (m / 3 * i) + (m / 3), y - (m / 3 * j) + (m / 3));
            }
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    f(n, n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", a[i][j] == 1 ? '*' : ' ');
        }
        printf("\n");
    }
    return 0;
}
