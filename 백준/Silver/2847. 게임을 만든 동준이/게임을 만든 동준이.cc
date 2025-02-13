#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a[101], ans = 0;


int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = n - 1; i >= 1; i--) {
        if (a[i] <= a[i - 1]) {
            ans += a[i - 1] - a[i] + 1;
            a[i - 1] = a[i] - 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}
