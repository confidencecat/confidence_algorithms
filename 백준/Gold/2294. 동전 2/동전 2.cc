#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define INF 21000000
#define min(a, b) a < b ? a : b
int dp[101][10001], a[101];
int n, m;

int f(int fn, int fp) {
    
    if (fp == 0) return 0;
    else if (fn == 0) return INF;

    if (dp[fn][fp] != 0) return dp[fn][fp];
    int s = f(fn - 1, fp);
    
    if (fp >= a[fn]) {
        int d = f(fn, fp - a[fn]) + 1;
        s = min(s, d);
    }
    if (s == INF) return dp[fn][fp] = INF;
    else return dp[fn][fp] = s;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = f(n, m);
    printf("%d", ans == INF ? -1 : ans);
    return 0;
}