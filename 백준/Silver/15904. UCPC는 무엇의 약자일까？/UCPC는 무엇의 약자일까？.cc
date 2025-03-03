#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[1002], c[5] = { 'u', 'c', 'p', 'c' };
int n, cn = 0;
bool ch[4];

int main() {
    scanf("%[^\n]s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == c[cn] - 32) ch[cn++] = true;
    }
    if (ch[3]) printf("I love UCPC");
    else printf("I hate UCPC");

    return 0;
}
