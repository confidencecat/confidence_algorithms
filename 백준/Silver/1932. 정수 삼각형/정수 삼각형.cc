#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max(a, b) a > b ? a : b

int a[501][501], answer = 0, n;

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            a[i][j] += max(a[i + 1][j + 1], a[i + 1][j]);
        }
    }
    
    printf("%d\n", a[0][0]);
    return 0;
}

