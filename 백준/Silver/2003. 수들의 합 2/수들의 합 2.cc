#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, ans = 0, a[10001];
long long m, sum[10001];

int main() {
    scanf("%d %lld", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }

    int s = 1, e = 1;
    while (s <= n && e <= n) {
        long long su = sum[e] - sum[s - 1];
        if (su >= m) {
            if (su == m)
                ans++;
            s++;
        }
        else {
            e++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
