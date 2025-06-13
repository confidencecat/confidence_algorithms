#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int m[6] = { 0, 7, 14, 21, 28, 35 };
int n, ans = 0;

int main() {
    
    scanf("%d", &n);
    ans = m[5];
    for (int i = 2; i <= n; i++) {
        ans += 2 * (i - 2) * (m[1]); //1
        ans += (i > 1) * m[2];
        ans += (i - 2) * m[3];
        ans += 2 * (i > 1) * m[4];
    }
    printf("%d\n", ans);


    return 0;
}
