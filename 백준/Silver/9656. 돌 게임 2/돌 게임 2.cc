#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, d[5] = {1, 0, 1, 0};

int main() {
    scanf("%d", &n);
    printf("%s", d[(n - 1) % 4] == 0 ? "SK" : "CY");
    
    return 0;
}
