#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int t, m;

    scanf("%d %d", &t, &m);

    printf("%d %d\n", (t + 24 - ((m - 45) >> 31 & 1)) % 24, (m + 60 - 45) % 60);

    return 0;
}
