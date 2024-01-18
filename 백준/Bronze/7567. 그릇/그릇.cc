#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int l = -1, r, n, ans = 0;
    char str[51];
    scanf("%s", str);
    n = strlen(str);

    for (int i = 0; i < n; i++) {
        if (str[i] == '(') r = 1;
        if (str[i] == ')') r = 2;
        if (l == -1 || (l == 1 && r == 2) || (l == 2 && r == 1)) ans += 10;
        else ans += 5;
        l = r;
    }
    printf("%d\n", ans);
    return 0;
}
