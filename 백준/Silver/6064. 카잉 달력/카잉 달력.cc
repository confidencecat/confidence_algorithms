#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, x, y, t, ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &m, &n, &x, &y);
        ans = x;
        y %= n;
        while ((ans <= n * m) && ans % n != y) {
            ans += m;
        }
        if (ans > n * m) {
            printf("-1\n");
        }
        else{
            printf("%d\n", ans);
        }
    }
    return 0;
}
