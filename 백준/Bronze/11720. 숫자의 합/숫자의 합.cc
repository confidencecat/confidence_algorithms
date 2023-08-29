#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int n, ans = 0;
    char s[101];
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        ans += s[i] - 48;
    }
    printf("%d", ans);
    return 0;
}