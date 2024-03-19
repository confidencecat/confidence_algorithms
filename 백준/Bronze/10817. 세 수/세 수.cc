#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int max = (a > b ? (a > c ? a : c) : (b > c ? b : c));
    int min = (a < b ? (a < c ? a : c) : (b < c ? b : c));
    printf("%d\n", a + b + c - max - min);
    return 0;
}
