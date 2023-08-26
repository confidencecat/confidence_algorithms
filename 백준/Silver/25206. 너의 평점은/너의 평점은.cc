#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    //freopen("input.txt", "r", stdin);
    char s[51], h[3];
    double p, ans = 0, p1 = 0;
    for (int i = 0; i < 20; i++) {
        scanf("%s %lf %s", s, &p, h);
        if (strcmp(h, "P") != 0)
            p1 += p;

        if (strcmp(h, "A+") == 0)
            ans += 4.5 * p;
        else if (strcmp(h, "A0") == 0)
            ans += 4.0 * p;
        else if (strcmp(h, "B+") == 0)
            ans += 3.5 * p;
        else if (strcmp(h, "B0") == 0)
            ans += 3.0 * p;
        else if (strcmp(h, "C+") == 0)
            ans += 2.5 * p;
        else if (strcmp(h, "C0") == 0)
            ans += 2.0 * p;
        else if (strcmp(h, "D+") == 0)
            ans += 1.5 * p;
        else if (strcmp(h, "D0") == 0)
            ans += 1.0 * p;
    }
    printf("%lf", ans / p1);
    return 0;
}
