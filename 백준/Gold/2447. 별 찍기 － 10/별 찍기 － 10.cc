#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool c[6563][6563];

void f(int x, int y, int n) {
    if (n == 3) {
        for (int i = 0; i < 3; i++) {
            c[y][x - i] = true;
            c[y - 2][x - i] = true;

            c[y - i][x - 2] = true;
            c[y - i][x] = true;
        }
    }
    else {
        f(x, y, n / 3);
        f(x - n / 3, y, n / 3);
        f(x - n / 3 * 2, y, n / 3);

        f(x, y - n / 3, n / 3);
        f(x - n / 3 * 2, y - n / 3, n / 3);

        f(x, y - n/3*2, n / 3);
        f(x - n / 3, y - n / 3 * 2, n / 3);
        f(x - n / 3 * 2, y - n / 3 * 2, n / 3);

    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int n;
    scanf("%d", &n);

    f(n, n, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}
