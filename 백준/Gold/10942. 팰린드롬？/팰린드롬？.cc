#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int dp[2001][2001];
int a[2001], n, t;

int dfs(int s, int e) { // 0 : null 1 : false 2 : true
    if (dp[s][e] != 0) return dp[s][e];

    if (a[s] != a[e]) return dp[s][e] = 1;

    if (s == e) return dp[s][e] = 2;
    else if (s + 1 == e) return dp[s][e] = 2;

    if (dfs(s + 1, e - 1) == 2) return dp[s][e] = 2;
    else return dp[s][e] = 1;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &t);
    while (t--) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", dfs(s, e) - 1);
    }
    return 0;
}
