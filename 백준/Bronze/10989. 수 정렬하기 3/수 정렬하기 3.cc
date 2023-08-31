#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, arr[10001], a;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        arr[a] += 1;
    }
    int m = 0;
    for (int i = 0; i <= 10000; i++) {
        if (arr[i] != 0) {
            for (int j = 0; j < arr[i]; j++) {
                printf("%d\n", i);
                m++;
            }
            if (m == n) break;
        }
    }
    return 0;
}
