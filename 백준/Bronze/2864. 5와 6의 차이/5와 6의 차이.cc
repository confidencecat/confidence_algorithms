#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

char a[8], b[8];
int an, bn, mi = 0, mx = 0;

int main() {

    scanf("%s %s", a, b);
    an = strlen(a);
    bn = strlen(b);

    for (int i = 0; i < an; i++) {
        mi += (a[i] == '6' ? 5 : (a[i] - 48)) * pow(10, (an - i - 1));
        mx += (a[i] == '5' ? 6 : (a[i] - 48)) * pow(10, (an - i - 1));
    }

    for (int i = 0; i < bn; i++) {
        mi += (b[i] == '6' ? 5 : (b[i] - 48)) * pow(10, (bn - i - 1));
        mx += (b[i] == '5' ? 6 : (b[i] - 48)) * pow(10, (bn - i - 1));
    }
    printf("%d %d\n", mi, mx);
    return 0;
}
