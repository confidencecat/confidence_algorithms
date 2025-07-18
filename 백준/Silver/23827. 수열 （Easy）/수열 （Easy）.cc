#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int n;
long long sum = 0, ans = 0;
int a[500001];

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        sum -= a[i];
        ans = (ans + (a[i] * sum)) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}
