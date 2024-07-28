#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool era[4000001];
int prime[283148], pn = 0;
long long int sum[283148];

int main() {
    //freopen("input.txt", "rt", stdin);

    int n;
    scanf("%d", &n);

    for (int i = 2; i * i <= n; i++) {
        if (!era[i]) {
            for (int j = i * i; j <= n; j += i) {
                era[j] = true;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!era[i]) {
            prime[pn] = i;
            sum[pn] = (pn == 0) ? i : sum[pn - 1] + i;
            pn++;
        }
    }

    int s = 0, e = 0;
    int ans = 0;

    while (e < pn) {
        long long int sx = (s > 0) ? sum[e] - sum[s - 1] : sum[e];
        if (sx > n) {
            s++;
        }
        else if (sx < n) {
            e++;
        }
        else {
            ans++;
            e++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
