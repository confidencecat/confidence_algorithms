#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<queue>
using namespace std;
#define max(a, b) a > b ? a : b

int n, a[1003], dp[1003], mx = 1, mx_i = 0;

priority_queue<int> ans;

int main() {
    //freopen("input.txt", "rt", stdin); 
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                mx = max(dp[i], mx);
            }
        }
    }
    printf("%d\n", mx);
    int m = mx;
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == mx) {
            ans.push(-a[i]);
            mx--;
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d ", -ans.top());
        ans.pop();
    }
    return 0;
}
