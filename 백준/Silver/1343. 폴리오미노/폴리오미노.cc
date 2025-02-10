#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

char a[52], ans[52];
int an, count = 0, as = 0;

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%s", a);
    an = strlen(a);

    for (int i = 0; i < an; i++) {
        if (a[i] == 'X') count++;
        if (a[i] == '.') {
            if (count == 0) {
                ans[as++] = '.';
                continue;
            }
            if (count % 2 == 1) {
                printf("-1");
                return 0;
            }
            for (int j = 0; j < (count / 4) * 4; j++) ans[as++] = 'A';
            for (int j = 0; j < ((count % 4) / 2) * 2; j++) ans[as++] = 'B';
            count = 0;
            ans[as++] = '.';
        }
    }
    if(count != 0) {
        if (count % 2 == 1) {
            printf("-1");
            return 0;
        }
        for (int j = 0; j < (count / 4) * 4; j++) ans[as++] = 'A';
        for (int j = 0; j < ((count % 4) / 2) * 2; j++) ans[as++] = 'B';
    }
    for (int i = 0; i < as; i++) {
        printf("%c", ans[i]);
    }
    return 0;
}
