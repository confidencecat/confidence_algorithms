#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int n;
char a[3073][6145];

void f(int m, int x, int y) {
    if (m == 3) {
        for (int i = x + 1; i <= x + 5; i++) {
            a[y][i] = '*';
            if (i == x + 2 || i == x + 4) a[y - 1][i] = '*';
            if (i == x + 3) a[y - 2][i] = '*';
        }
    }
    else {
        f(m / 2, x + (m / 2 * 0), y);
        f(m / 2, x + (m / 2 * 1), y - m / 2);
        f(m / 2, x + (m / 2 * 2), y);
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    
    f(n, 0, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n * 2; j++) {
            printf("%c", a[i][j] ? a[i][j] : ' ');
        }
        printf("\n");
    }
    return 0;
}
