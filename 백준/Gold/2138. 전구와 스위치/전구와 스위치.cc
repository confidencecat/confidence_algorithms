#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a,b) (a) < (b) ? (a) : (b)

int n;
char s[100001], s1[100001], e[100001];
int ans = 0;

int main() {
    scanf("%d", &n);
    scanf("%s\n%s", s, e);
    for (int i = 0; i < n; i++) s1[i] = s[i];

    for (int i = 1; i < n; i++) {
        if (s[i - 1] != e[i - 1]) {
            ans++;
            s[i - 1] = 97 - s[i - 1];
            s[i] = 97 - s[i];
            if(i != n - 1)s[i + 1] = 97 - s[i + 1];
        }
        //printf("%s %d\n", s, ans);
    }
    if (strcmp(s, e) == 0) {
        printf("%d\n", ans);
        return 0;
    }
    int ans2 = 1;
    //printf("\n\n");
    s1[0] = 97 - s1[0];
    s1[1] = 97 - s1[1];
    for (int i = 1; i < n; i++) {
        if (s1[i - 1] != e[i - 1]) {
            ans2++;
            s1[i - 1] = 97 - s1[i - 1];
            s1[i] = 97 - s1[i];
            if(i != n - 1) s1[i + 1] = 97 - s1[i + 1];
        }
        //printf("%c %c  %s %d\n", s1[i - 1], e[i - 1], s1, ans2);
    }
    if (strcmp(s1, e) == 0) {
        printf("%d\n", ans2);
        return 0;
    }
    printf("-1");
    return 0;
}
