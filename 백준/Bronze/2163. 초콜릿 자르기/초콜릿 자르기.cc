#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", n * m - 1);
    return 0;
}

