#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[8];
    int ans = 0;
    scanf("%s",s);
    ans = strtol(s, NULL, 16);
    printf("%d\n", ans);
    return 0;

}
