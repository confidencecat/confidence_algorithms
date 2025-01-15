#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        for (int i = 0; i < a; i++) {
            char m[13];
            scanf("%s", m);
            for (int j = b - 1; j >= 0; j--) printf("%c", m[j]);
            printf("\n");
        }
    }

    return 0;
}
