#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

#define MOD 1000000007

typedef long long ll;
typedef struct {
    ll a[2][2];
} matrix;

matrix mul(matrix x, matrix y) {
    matrix res;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res.a[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
            }
        }
    }
    return res;
}

matrix pow(matrix x, ll n) {
    if (n == 1) return x;
    if (n % 2) {
        return mul(x, pow(x, n - 1));
    }
    matrix half = pow(x, n / 2);
    return mul(half, half);
}

int main() {
    ll n;
    scanf("%lld", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }
    else if (n == 1) {
        printf("1\n");
        return 0;
    }

    matrix m;
    m.a[0][0] = 1; m.a[0][1] = 1;
    m.a[1][0] = 1; m.a[1][1] = 0;

    matrix res = pow(m, n - 1);

    printf("%lld\n", res.a[0][0]);
    return 0;
}

