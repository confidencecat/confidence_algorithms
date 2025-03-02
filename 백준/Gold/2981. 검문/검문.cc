#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ll long long int

int com(const void* A, const void* B) {
    return *(ll*)A - *(ll*)B;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll a[101],b[101];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    qsort(a, n, sizeof(a[0]), com);


    ll gc = a[1] - a[0];
    for (int i = 1; i < n; i++) {
        gc = gcd(gc, a[i] - a[i - 1]);
    }
    ll ans[1001];
    int an = 0;
    for (ll m = 2; m * m <= gc; m++) {
        if (gc % m == 0) {
            ans[an++] = m;
            if (m * m != gc) ans[an++] = gc / m;
        }
    }
    if (gc > 1) ans[an++] = gc;
    qsort(ans, an, sizeof(ans[0]), com);

    for (int i = 0; i < an; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}
