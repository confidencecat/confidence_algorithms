#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c) printf("%d", 10000 + a * 1000);
    
    if (a == b && b != c) printf("%d", 1000 + a * 100);
    if (a == c && b != c) printf("%d", 1000 + a * 100);
    if (b == c && a != b) printf("%d", 1000 + b * 100);
    
    if (a != b && b != c && a != c) {
        int max = a > b ? a > c ? a : c : b > c ? b : c;
        printf("%d", max * 100);
    }
    return 0;
}
