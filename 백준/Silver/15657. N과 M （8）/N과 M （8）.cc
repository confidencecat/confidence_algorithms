#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>

int n, m, c[9], a[9];

int com(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

void f(int x, int xn) {
    if (xn == m) {
        xn = 0;
        for (int i = 0; i < m; i++) {
            printf("%d ", c[i]);
        }
        printf("\n");
    }
    else {
        for (int i = x; i < n; i++){
            c[xn] = a[i];
            f(i, xn + 1);
            c[xn] = 0;
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), com);
    f(0, 0);
    return 0;
}