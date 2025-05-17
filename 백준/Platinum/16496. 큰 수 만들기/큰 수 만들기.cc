#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))


typedef struct ST {
    int n;
    char s[12];
}ST;

ST st(char c[]) {
    ST s;

    s.n = strlen(c);
    for (int i = 0; i < s.n; i++) {
        s.s[i] = c[i];
    }
    s.s[s.n] = '\0';
    
    return s;
}

int n;
char a[12];
ST l[1001];

int com(const void* AA, const void* BB) {
    char ab[25], ba[25];
    ST* A = (ST*)AA, * B = (ST*)BB;
    strcpy(ab, A->s);
    strcat(ab, B->s);
    strcpy(ba, B->s);
    strcat(ba, A->s);
    return strcmp(ba, ab);
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        l[i] = st(a);
    }

    qsort(l, n, sizeof(l[0]), com);
    if (l[0].s[0] == '0') {
        printf("0");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%s", l[i].s);
    }

    
    return 0;
}
