#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int t, m, s, d;
    scanf("%d %d %d", &t, &m, &s);
    scanf("%d", &d);
    printf("%d %d %d\n", (t + (m + ((s + d) / 60)) / 60) % 24, (m + ((s + d) / 60)) % 60, (s + d) % 60);
    return 0;
}

