#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll dp[2][105][105];

int main() {
    freopen("input.txt", "rt", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    ll* c = (ll*)malloc((n + 2) * sizeof(ll));
    c[0] = c[1] = 1;
    for (int i = 2; i <= n; i++) {
        c[i] = 0;
        for (int j = 0; j <= i - 1; j++) {
            c[i] = (c[i] + c[j] * c[i - j - 1]) % m;
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i][1] = c[i - 1];
        dp[1][i][2] = (i - 1) * c[i - 1] % m;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k + i <= n; k++) {
                for (int l = 0; l < 2 && (l == 0 || j > 1); l++) {
                    dp[l][i + k][j + 1] = (dp[l][i + k][j + 1] + dp[0][i][j] * c[k - (0 == l)]) % m;
                }
                for (int l = 1; l < 2 && (l == 0 || j > 1); l++) {
                    dp[l][i + k][j + 1] = (dp[l][i + k][j + 1] + dp[1][i][j] * c[k - (1 == l)]) % m;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= j + 1; k++) {
                dp[1][i + 1][k] = (dp[1][i + 1][k] + dp[1][i][j]) % m;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld ", dp[1][i + 1][1]);
    }

    free(c);
    return 0;
}
