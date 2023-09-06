#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char str[3000000];
int main() {

    int M, x;
    int S = 0;

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%s", str);

        if (strcmp(str, "add") == 0) {
            scanf("%d", &x);
            S |= (1 << x);
        }

        else if (strcmp(str, "remove") == 0) {
            scanf("%d", &x);
            S &= ~(1 << x);
        }

        else if (strcmp(str, "check") == 0) {
            scanf("%d", &x);
            if (S & (1 << x)) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }

        else if (strcmp(str, "toggle") == 0) {
            scanf("%d", &x);
            if (S & (1 << x)) {
                S &= ~(1 << x);
            }
            else {
                S |= (1 << x);
            }
        }

        else if (strcmp(str, "all") == 0) {
            S = (1 << 21) - 1;
        }

        else if (strcmp(str, "empty") == 0) {
            S = 0;
        }
    }

    return 0;
}