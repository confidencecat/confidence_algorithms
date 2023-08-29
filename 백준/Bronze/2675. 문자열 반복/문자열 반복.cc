#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int n, m, k;
    char s[21];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &m, s);
        k = strlen(s);
        for (int j = 0; j < k; j++) {
            for (int k = 0; k < m; k++) {
                printf("%c", s[j]);
            }
        }
        printf("\n");
    }
    return 0;
}