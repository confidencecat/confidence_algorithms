#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t, n;
char s[1001], r[2005];

int main() {

    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf(" %c", &s[i]);
        int h = 1000, e = 1000;
        r[h] = s[0];
        for (int i = 1; i < n; i++) {
            char c = s[i];
            if (c <= r[h]) r[--h] = c;
            else r[++e] = c;
        }
        for (int i = h; i <= e; i++) putchar(r[i]);
        putchar('\n');
    }

    return 0;
}
