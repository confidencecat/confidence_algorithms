#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n;
char s[1000002];
int o = 0, z = 0;

int main() {
    scanf("%s", s);
    n = strlen(s);

    if (s[0] == '1') o = 1;
    else z = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '1') o++;
            else z++;
        }
    }

    printf("%d\n", o < z ? o : z);
    return 0;
}
