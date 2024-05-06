#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int n, a[100001], m = 0, ans = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > m) {
            m = a[i];
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}