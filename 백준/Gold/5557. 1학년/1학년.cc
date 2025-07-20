#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  n, a;
long long int dp[101][21];

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a);
        if (i == 0) dp[i][a] = 1;
        else {
            for (int j = 0; j <= 20; j++) {
                if (dp[i - 1][j] != 0) {
                    if (j - a >= 0) dp[i][j - a]+=dp[i - 1][j];
                    if (j + a <= 20) dp[i][j + a]+= dp[i - 1][j];
                }
            }
        }
        /*printf("%2d : ", i+1);
        for (int j = 0; j <= 20; j++) printf("%d ", dp[i][j]);
        printf("\n");*/
    }
    scanf("%d", &a);
    printf("%lld", dp[n - 2][a]);

    return 0;
}