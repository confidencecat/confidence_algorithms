#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

char a[65][65];

void f(int x, int y, int n) {

    if (n == 1) {
        printf("%c", a[y][x]);
        return;
    }
    bool z = true;
    bool o = true;

    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (a[i][j] == '1') {
                z = false;
            }
            else {
                o = false;
            }

            if (!z && !o) {
                break;
            }
        }
        if (!z && !o) {
            break;
        }
    }

    if (z) {
        printf("0");
    }
    else if (o) {
        printf("1");
    }
    else {
        printf("(");
        f(x, y, n / 2);
        f(x + n / 2, y, n / 2);
        f(x, y + n / 2, n / 2);
        f(x + n / 2, y + n / 2, n / 2);
        printf(")");
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    f(0, 0, n);

    return 0;
}
