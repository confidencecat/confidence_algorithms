#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int a[15], n, ans = 0;

bool ch(int x) {
    for (int i = 0; i < x; i++) {
        if (a[x] == a[i] || x - i == abs(a[x] - a[i])) return false;
    }
    return true;
}

void nq(int x) {
    if (x == n) {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        a[x] = i;
        if (ch(x)) {
            nq(x + 1);
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);
    nq(0);
    printf("%d\n", ans);
    return 0;
}
