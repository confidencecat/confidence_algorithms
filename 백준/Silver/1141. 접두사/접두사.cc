#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, ans = 1;
char s[52][52];

int com(const void* A, const void* B) {
    char* str1 = (char*)A;
    char* str2 = (char*)B;

    int len1 = (int)strlen(str1);
    int len2 = (int)strlen(str2);

    if (len1 != len2) return len1 - len2;
    return strcmp(str1, str2);
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    qsort(s, n, sizeof(s[0]), com);
    for (int i = 0; i < n - 1; i++) {
        bool ch = true;
        for (int j = i + 1; j < n; j++) {
            if (strncmp(s[i], s[j], strlen(s[i])) == 0) {
                ch = false;
            }
        }
        if (ch) {
            //printf("%s\n", s[i]);
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
