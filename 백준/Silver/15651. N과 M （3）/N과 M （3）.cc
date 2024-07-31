#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int ch[10];

void f(int fn) {
    if (fn == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", ch[i]);
        }
        printf("\n");
    }
    else if(fn < n) {
        for (int i = 1; i <= n; i++) {
            ch[fn] = i;
            f(fn + 1);
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d %d", &n, &m);

    f(0);

    return 0;
}
