#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, a[10], num[10];

void f(int x, int fn) {
    if (fn == m) {
        for (int i = 0; i < m; i++)
            printf("%d ", a[i]);
        printf("\n");
        return;
    }

    int l = 0;

    for (int i = x; i < n; i++) {
        if (num[i] != l) {
            a[fn] = num[i];
            l = a[fn];
            f(i, fn + 1);
        }
    }

    return;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    sort(num, num + n);

    f(0, 0);

    return 0;
}
