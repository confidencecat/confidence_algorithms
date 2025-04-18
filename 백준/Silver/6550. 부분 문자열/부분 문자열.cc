#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int t, si, sj, s1n, s2n;
char s1[100001], s2[100001];

int main() {
    while(scanf("%s %s", s1, s2) != EOF){
        s1n = strlen(s1);
        s2n = strlen(s2);
        if (s2n < s1n) {
            printf("No\n");
            continue;
        }
        si = 0; sj = 0;
        while (si < s1n && sj < s2n) {
            if (s1[si] == s2[sj]) {
                si++;
                sj++;
            }
            else {
                sj++;
            }
        }
        if (si == s1n) printf("Yes\n");
        else printf("No\n");

    }

    
    return 0;
}
