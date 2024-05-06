#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int n, ans = 0;

int s(int m) {
    int sum = 0;
    while (m) {
        if (m % 10 == 3 || m % 10 == 6 || m % 10 == 9) sum++;
        m /= 10;
    }
    return sum;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        ans += s(i);
    }
    printf("%d\n", ans);
    return 0;
}