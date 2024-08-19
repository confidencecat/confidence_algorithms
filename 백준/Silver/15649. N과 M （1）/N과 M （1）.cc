#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, a[10];
bool c[10];

void f(int fn) {
    if (fn == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else if(fn < m){
        for (int i = 1; i <= n; i++) {
            if (c[i] == false) {
                c[i] = true;
                a[fn] = i;
                f(fn + 1);
                a[fn] = 0;
                c[i] = false;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    f(0);
    return 0;
}
