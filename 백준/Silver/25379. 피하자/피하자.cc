#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int n, a;
    long int m = 0, j = 0, l = 0, r = 0;
	scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a % 2 == 0) {
            m += j++;
            l += i;
            r += n - 1 - i;
        }
    }
    printf("%ld", (l > r ? r : l) - m);
	return 0;
}