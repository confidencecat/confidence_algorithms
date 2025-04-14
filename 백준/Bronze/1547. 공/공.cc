#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, s, e, d = 1;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &e);
        if (s == d) d = e;
        else if (e == d) d = s;
    }
    printf("%d\n", d);


    return 0;
}
