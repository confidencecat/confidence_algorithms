#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n, d[501], z = 0, o = 0;
char s[501];

int main() {

    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; i++) if (s[i] == '0') z++;
    o = n - z;

    z /= 2;
    o /= 2;

    for (int i = 0; i < n && o > 0; i++) {
        if (s[i] == '1') {
            o--;
            d[i] = 1;
        }
    }
    for (int i = n - 1; i >=0 && z > 0; i--) {
        if (s[i] == '0') {
            z--;
            d[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!d[i]) {
            printf("%c", s[i]);
        }
    }

    return 0;
}
