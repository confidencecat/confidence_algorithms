#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a[101][101], n, s;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &s);
            if (s == 1) {
                a[i][j] = 1;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (k != j && a[i][j] == 0 && a[i][k] == 1 && a[k][j] == 1) {
                    a[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
