#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char a[1000005];
int ans[27], max = -1, n, j = 0;

int main() {
    scanf("%s", a);
    int m = strlen(a);
    for (int i = 0; i < m; i++) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            if (++ans[a[i] - 97] > max)
                max = ans[a[i] - 97];
        }
        if (a[i] >= 'A' && a[i] <= 'Z') {
            if (++ans[a[i] - 65] > max)
                max = ans[a[i] - 65];
        }
    }
    for (int i = 0; i < 26; i++) {
        if (ans[i] == max) {
            n++;
            j = i;
        }
    }
    if (n == 1) {
        printf("%c\n", j + 65);
    }
    else
        printf("?\n");
    return 0;
}