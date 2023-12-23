#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

//아래의 코드는 hijkl2e님의 코드를 참고하여 작성하였으며, 공부하는 용도로 사용하였음

long long int com[103], dp[103];

int main() {
    //freopen("input.txt", "rt", stdin); 
    int n;
    long long int mod;
    scanf("%d %lld", &n, &mod);
    com[0] = 1;
    for (int i = 1; i <= n + 2; i++) {
        for (int j = 0; j <= i - 1; j++) {
            com[i] += com[j] * com[i - j - 1] % mod;
            com[i] %= mod;
        }
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 2 * com[i + 1] + com[i] + mod - com[i + 2];
        dp[i] %= mod;
        for (int j = 1; j <= i - 1; j++) {
            dp[i] += (2 * (i - j) + 1) * com[j] % mod * com[i - j] % mod;
            dp[i] %= mod;
        }
        for (int j = 1; j <= i; j++) {
            dp[i] += ((com[j - 1] * dp[i - j]) + (dp[j - 1] * com[i - j])) % mod;
            dp[i] %= mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", dp[i]);
    }
    return 0;
}
