#include <stdio.h>

#define MAX 10000

void add(int result[], int a[], int b[]) {
    int carry = 0;
    for (int i = 0; i < MAX; i++) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
}

void copy(int dest[], int src[]) {
    for (int i = 0; i < MAX; i++) {
        dest[i] = src[i];
    }
}

void print(int num[]) {
    int start = MAX;
    while (start > 0 && num[start - 1] == 0) {
        start--;
    }
    if (start == 0) {
        printf("0\n");
    } else {
        for (int i = start - 1; i >= 0; i--) {
            printf("%d", num[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int fib1[MAX] = {0}, fib2[MAX] = {0}, result[MAX] = {0};

    fib1[0] = fib2[0] = 1;
    if (n == 0) printf("0\n");
    else if (n <= 2) {
        printf("1\n");
    } else {
        for (int i = 3; i <= n; i++) {
            add(result, fib1, fib2);
            copy(fib1, fib2);
            copy(fib2, result);
        }
        print(result);
    }

    return 0;
}
