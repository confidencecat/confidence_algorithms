#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int n, i = 1;
    scanf("%d", &n);
    if (n >= 90) printf("A\n");
    else if (n >= 80) printf("B\n");
    else if (n >= 70) printf("C\n");
    else if (n >= 60) printf("D\n");
    else printf("F\n");
    return 0;
}