#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max(a, b) a > b ? a : b

int ans[1001];
int main() {
    //freopen("input.txt", "rt", stdin);
    int n, a[1001];

    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans[j] = max(ans[j], ans[j - i] + a[i]);
        }
    }
    printf("%d\n", ans[n]);

    return 0;
}
