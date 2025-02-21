#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, t = 0;
char s[51];

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) { if (s[i] == 'L') t++; }
    if (!t) printf("%d", n);
    else printf("%d", n - t / 2 + 1);
    return 0;
}

