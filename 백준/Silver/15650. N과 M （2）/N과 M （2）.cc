#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int ch[10];
bool c[10];

void f(int fn, int x) {
    if (fn == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", ch[i]);
        }
        printf("\n");
    }
    else if(fn < n) {
        for (int i = x + 1; i <= n; i++) {
            if (c[i]) continue;
            ch[fn] = i;
            c[i] = true;
            f(fn + 1, i);
            c[i] = false;
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d %d", &n, &m);

    f(0, 0);

    return 0;
}
