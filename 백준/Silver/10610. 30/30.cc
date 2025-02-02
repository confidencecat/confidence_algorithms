#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[100002];
int n, m[11], sum = 0;

int main() {

    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        m[s[i] - 48]++;
        sum += (s[i] - 48);
    }


    if (m[0] == 0 || sum % 3 != 0) {
        printf("-1\n");
        return 0;
    }

    m[0]--;
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < m[i]; j++) {
            printf("%d", i);
        }
    }
    printf("0");



    return 0;
}
