#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n;
char s1[100001], s2[100001], e[100001];
int ans1 = 0, ans2 = 1;

int main() {
    scanf("%d", &n);
    scanf("%s\n%s", s1, e);
    for (int i = 0; i < n; i++) s2[i] = s1[i];

    for (int i = 1; i < n; i++) {
        if (s1[i - 1] != e[i - 1]) {
            ans1++;
            s1[i - 1] = 97 - s1[i - 1];
            s1[i] = 97 - s1[i];
            if(i != n - 1)s1[i + 1] = 97 - s1[i + 1];
        }
    }
    if (strcmp(s1, e) == 0) {
        printf("%d\n", ans1);
        return 0;
    }
    s2[0] = 97 - s2[0];
    s2[1] = 97 - s2[1];
    for (int i = 1; i < n; i++) {
        if (s2[i - 1] != e[i - 1]) {
            ans2++;
            s2[i - 1] = 97 - s2[i - 1];
            s2[i] = 97 - s2[i];
            if(i != n - 1) s2[i + 1] = 97 - s2[i + 1];
        }
    }
    if (strcmp(s2, e) == 0) {
        printf("%d\n", ans2);
        return 0;
    }
    printf("-1");
    return 0;
}
