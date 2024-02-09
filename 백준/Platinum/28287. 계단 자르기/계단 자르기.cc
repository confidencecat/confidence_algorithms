#include<stdio.h>
#define ll long long int
#define fr(A, S, E) for(int A = S; A <= E; A++)
ll com[103], dp[103];
int main() {
    int n;
    ll mod;
    scanf("%d %lld", &n, &mod);
    com[0] = 1;
    fr(i, 1, n + 2) fr(j, 0, i - 1) {
        com[i] = (com[i] + (com[j] * com[i - j - 1] % mod)) % mod;
    }
    dp[1] = 0;
    fr(i, 1, n){
        dp[i] = (2 * com[i + 1] + com[i] - com[i + 2] + mod) % mod;
        fr(j, 1, i - 1) dp[i] = (dp[i] + ((2 * (i - j) + 1) * com[j] % mod * com[i - j] % mod)) % mod;
        fr(j, 1, i)dp[i] = (dp[i] + (((com[j - 1] * dp[i - j]) + (dp[j - 1] * com[i - j])) % mod)) % mod;
    }
    fr(i, 1, n) printf("%lld ", dp[i]);
    return 0;
}
