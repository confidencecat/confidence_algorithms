#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[52];
int n, c[28], odd = 0, oc = 27;

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; i++) {
        c[s[i] - 65]++;
    }
    for (int i = 0; i < 26; i++) {
        if (c[i] % 2 == 1) {
            odd++;
            oc = i;
        }
        
    }
    if (odd > 1) {
        printf("I'm Sorry Hansoo\n");
        return 0;
    }
    c[oc]--;
    for (int i = 0; i < 26; i++) {
        if (c[i] != 0) {
            for (int j = 0; j < c[i] / 2; j++) {
                printf("%c", i+65);
            }
        }
    }
    if (odd == 1) printf("%c", oc+65);
    for (int i = 26; i >= 0; i--) {
        if (c[i] != 0) {
            for (int j = 0; j < c[i] / 2; j++) {
                printf("%c", i + 65);
            }
        }
    }
    



    return 0;
}
