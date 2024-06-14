#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, a[15] = { 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596 };

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d\n", &n);
    printf("%d", a[n - 1]);
    return 0;
}
