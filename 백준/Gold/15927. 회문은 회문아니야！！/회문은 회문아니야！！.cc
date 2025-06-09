#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[500002], c;
int n;
bool tf = true, isall = true;

int main() {
    
    scanf("%s", s);
    n = strlen(s);
    c = s[0];


    for (int i = 0; i < n / 2 + 1; i++) {
        if (s[i] != s[n - i - 1]) {
            tf = false;
            break;
        }
        if (s[i] != c || s[n - i - 1] != c) isall = false;
    }
    if (tf) {
        if (isall) printf("-1");
        else printf("%d", n - 1);
    }
    else printf("%d", n);

    return 0;
}
