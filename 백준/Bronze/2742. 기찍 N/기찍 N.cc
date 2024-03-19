#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);

    while (n) {
        printf("%d\n", n--);
    }
    return 0;
}
