#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((i * i + j * j + m) % (i * j) == 0) {
                    k++;
                }
            }
        }
        printf("%d\n", k);
    }
    return 0;
}
