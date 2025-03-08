#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, a, ans = 0;
    scanf("%d", &n);
    if (n == 0) { printf("1"); return 0; }
    a = n;
    while (1) {
        a = ((a%10)*10)+((a/10)+(a%10))%10;
        //printf("%d\n", a);
        ans++;
        if (a == n) break;
    }
    printf("%d\n", ans);
    return 0;
}
