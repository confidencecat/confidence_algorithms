#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define min(a, b) (a > b) ? b : a

int dp[203][203];
int arr[203];

int solve(int a, int b) {
    if (a == b) return 0;

    int ret = dp[a][b];
    if (ret != -1) return ret;

    ret = 1000000007;

    for (int i = a; i < b; i++) {
        int temp = (arr[a] == arr[i + 1]) ? 0 : 1;
        ret = min(ret, solve(a, i) + solve(i + 1, b) + temp);
    }
    dp[a][b] = ret;
    return ret;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    memset(dp, -1, sizeof(dp));

    printf("%d", solve(0, n - 1));

    return 0;
}