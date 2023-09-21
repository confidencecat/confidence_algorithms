#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

long long int arr[1508][1508], ld[808][808], rd[808][808], lu[808][808], ru[808][808];

int main() {
    long long int i, j, k, l, m, n;
    scanf("%lld %lld", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%1lld", &arr[i][j]);

    for (i = n; i >= 1; i--)
        for (j = 1; j <= m; j++)
            if (arr[i][j] == 1) {
                ld[i][j] = ld[i + 1][j - 1] + 1;
                rd[i][j] = rd[i + 1][j + 1] + 1;
            }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (arr[i][j] == 1) {
                lu[i][j] = lu[i - 1][j - 1] + 1;
                ru[i][j] = ru[i - 1][j + 1] + 1;
            }

    long long int ans = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            for (k = 1; k <= (ld[i][j] < rd[i][j] ? ld[i][j] : rd[i][j]); k++)
                if (arr[i + 2 * (k - 1)][j] && lu[i + 2 * (k - 1)][j] >= k && ru[i + 2 * (k - 1)][j] >= k)
                    ans = (ans > k ? ans : k);
            for (k = 1; k <= (ru[i][j] < rd[i][j] ? ru[i][j] : rd[i][j]); k++)
                if (arr[i][j + 2 * (k - 1)] && lu[i][j + 2 * (k - 1)] >= k && ld[i][j + 2 * (k - 1)] >= k)
                    ans = (ans > k ? ans : k);
        }
    printf("%lld", ans);

    return 0;
}
