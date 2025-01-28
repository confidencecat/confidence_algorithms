#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a[100001], l[100001], v = 0, d = 0, ans = 0;

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d", &n);
    for (int i = 1; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &l[i]);
    d = a[1];
    v = l[0];
    for (int i = 1; i < n - 1; i++) {
        if (l[i] < v) {
            ans += v * d;
            v = l[i];
            d = a[i + 1];
        }
        else d += a[i + 1];
    }
    ans += d * v;
    printf("%d\n", ans);

    return 0;
}
