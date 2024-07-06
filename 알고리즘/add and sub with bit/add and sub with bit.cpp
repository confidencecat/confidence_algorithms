#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int sub(int a, int b) {
    return add(a, add(~b, 1));
}

int main() {
    
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", add(a, b));
    printf("%d\n", sub(a, b));

    return 0;
}
