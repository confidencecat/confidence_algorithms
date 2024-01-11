#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long int mod = 1000000007;

long long int gcd(long long int a, long long int b) {
    if (b == 0)return a;
    else return gcd(b, a % b);
}

long long power(long long a, long long b) {
    long long c = 1;
    while (b) {
        if (b & 1) c = c * a % mod;
        b = b / 2;
        a = a * a % mod;
    }
    return c;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int t;
    long long int ans = 0;
    scanf("%d", &t);
    while (t--) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        long long int gcd_int = gcd(a, b);
        a /= gcd_int;
        b /= gcd_int;
        ans = (ans + b * power(a, mod - 2)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}