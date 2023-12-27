#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

void update(ll* arr, ll* sqd, int sn, int i, ll z) {
    ll tmp = arr[i];
    arr[i] = z;
    sqd[i / sn] += z - tmp;
}

ll query(ll* arr, ll* sqd, int sn, int n, int l, int r) {
    ll ret = 0;
    if (l / sn == r / sn) {
        for (int i = l; i <= r; ++i) {
            ret += arr[i];
        }
    }
    else {
        int j = l / sn * sn + sn < n ? l / sn * sn + sn : n;
        for (int i = l; i < j; ++i) {
            ret += arr[i];
        }
        for (int i = r / sn * sn; i <= r; ++i) {
            ret += arr[i];
        }
        for (int i = l / sn + 1; i < r / sn; ++i) {
            ret += sqd[i];
        }
    }
    return ret;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, k, sn;
    scanf("%d %d %d", &n, &m, &k);
    sn = (int)sqrt(n) + 1;

    ll* arr = (ll*)malloc(n * sizeof(ll));
    ll* sqd = (ll*)malloc(sn * sizeof(ll));

    for (int i = 0; i < sn; ++i) {
        sqd[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
        sqd[i / sn] += arr[i];
    }

    int T = m + k;
    while (T--) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            update(arr, sqd, sn, b - 1, c);
        }
        else {
            printf("%lld\n", query(arr, sqd, sn, n, b - 1, c - 1));
        }
    }

    free(arr);
    free(sqd);

    return 0;
}
