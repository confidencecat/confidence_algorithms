#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b


int main() {
    //freopen("input.txt", "rt", stdin);
    int t;
    scanf("%d", &t);

    while (t--) {
        int l, n;
        scanf("%d %d", &l, &n);

        int a, it = 0, xt = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            int mi = min(a, l - a);
            int mx = max(a, l - a);

            it = max(it, mi);
            xt = max(xt, mx);
        }
        printf("%d %d\n", it, xt);
    }

    return 0;
}
