#include <stdio.h>
int main() {
    int a, b, c, n, m;
    scanf("%d %d %d\n", &a, &b, &c);
    n = a > b ? a > c ? a : c : b > c ? b : c;
    m = a < b ? a < c ? a : c : b < c ? b : c;
    printf("%d %d %d", m, a + b + c - n - m, n);
    return 0;
}
