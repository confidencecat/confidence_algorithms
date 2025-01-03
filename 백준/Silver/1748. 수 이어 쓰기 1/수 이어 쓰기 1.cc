#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int n, ans = 0;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i *= 10) {
        ans += (n - i + 1);
    }
    printf("%d\n", ans);

    return 0;
}
