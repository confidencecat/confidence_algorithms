#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max(a, b) a > b ? a : b

int ans[16];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int n, a[16][3];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    for (int i = 0; i < n; i++) {
        ans[i + a[i][0]] = max(ans[i + a[i][0]], ans[i] + a[i][1]);
        for (int j = i + a[i][0]; j <= n; j++) {
            ans[j] = max(ans[j - 1], ans[j]);
        }
    }
    printf("%d\n", ans[n]);
    return 0;
}
