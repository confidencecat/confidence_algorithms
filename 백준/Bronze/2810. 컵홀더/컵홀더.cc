#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, ans = 0;
char s[51];

int main() {
    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < n; i++) {
        ans++;
        if (s[i] == 'L') i++;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i + 1] == 'S' && s[i] == 'L') { ans++; break; }
    }
    printf("%d\n", ans);

    return 0;
}

