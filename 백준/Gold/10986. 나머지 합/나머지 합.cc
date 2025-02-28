#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
long long int ans = 0, c[1001], a[1000001], s[1000001];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s[i] = (s[i - 1] + a[i])%m;
        c[s[i]]++;
    }
    c[0]++;
    for (int i = 0; i < m; i++) {
        if (c[i] > 1) ans += c[i] * (c[i] - 1) / 2;
    }
    printf("%lld\n", ans);


    return 0;
}
