#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f(int n) {
    int ans = n;
    //printf("%d : ", n);
    while (n > 0) {
        ans += n % 10;
        //printf("%d ", n % 10);
        n /= 10;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "rt", stdin);

    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (n == f(i)) {
            printf("%d\n", i);
            return 0;
        }
        //printf("\n");
    }
    printf("0");

    return 0;
}
