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

int mul(int a, int b) {
    int result = 0;
    while (b != 0) {
        if (b & 1) {
            result = result + a;
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

int divi(int a, int b) {
    int result = 0;
    while (a >= b) {
        int shift = 0;
        while ((b << (shift + 1)) <= a) {
            shift++;
        }
        result += 1 << shift;
        a -= b << shift;
    }
    return result;
}


int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    printf("add : %d\nsub : %d\nmul : %d\ndivi : %d\n", add(a, b), sub(a, b), mul(a, b), divi(a, b));

    return 0;
}
