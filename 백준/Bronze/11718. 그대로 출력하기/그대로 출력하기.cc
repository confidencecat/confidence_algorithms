#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    char s[102];
    
    while (fgets(s, sizeof(s), stdin) != NULL) {
        printf("%s", s);
    }
    return 0;
}
