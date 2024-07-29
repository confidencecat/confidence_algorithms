#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int a, b, g;

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d %d", &a, &b);
    g = gcd(a, b);
    printf("%d\n%d", g, a * b / g);

    return 0;
}
