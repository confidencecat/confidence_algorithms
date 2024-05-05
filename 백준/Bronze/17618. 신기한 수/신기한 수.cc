#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

int n, ans = 0;

int s(int m) {
    int sum = 0;
    while (m) {
        sum += m % 10;
        m /= 10;
    }
    return sum;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % s(i) == 0) ans++;
    }
    printf("%d\n", ans);
    return 0;
}