#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int ch[10], l[10];

void f(int x) {
    if (x == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", l[i]);
        }
        printf("\n");
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (ch[i] == 1) continue;

            ch[i] = 1;
            l[x] = i;
            f(x + 1);
            l[x] = 0;
            ch[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);

    f(0);


    return 0;
}
