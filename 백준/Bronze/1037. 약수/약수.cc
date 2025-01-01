#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a, mx = -1, mi = 1000001;


int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        mx = mx < a ? a : mx;
        mi = mi > a ? a : mi;
    }
    printf("%d\n", mx * mi);
    return 0;
}
