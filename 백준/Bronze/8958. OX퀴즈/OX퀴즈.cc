#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int main() {
    int n, m, p, ans;
    char s[81];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p = 0;
        ans = 0;
        scanf("%s", s);
        m = strlen(s);
        for (int j = 0; j < m; j++) {
            if (s[j] == 'O') p += 1;
            else p = 0;
            ans += p;
        }
        printf("%d\n", ans);
    }
    return 0;
}