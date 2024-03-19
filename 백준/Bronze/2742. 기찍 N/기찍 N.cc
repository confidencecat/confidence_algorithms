#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        printf("%d\n", i);
    }
    return 0;
}
