#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t, l, p, v;

int main() {
    //freopen("input.txt", "rt", stdin);

    while (1) {
        scanf("%d %d %d", &l, &p, &v);
        if (l == 0 && p == 0 && v == 0) break;

        printf("Case %d: %d\n", ++t, (v/p)*l + (v%p < l ? v%p : l));
    }

    return 0;
}
