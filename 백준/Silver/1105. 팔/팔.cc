#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char l[11], r[11];
    int ans = 0;

    scanf("%s %s", l, r);
    int ln = strlen(l), rn = strlen(r);

    if (ln != rn) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < ln; i++) {
        if (l[i] != r[i]) break;
        if (l[i] == '8') ans++;
    }

    printf("%d\n", ans);
    return 0;
}
