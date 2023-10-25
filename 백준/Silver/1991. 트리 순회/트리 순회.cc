#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int n, s[27][3];

void f1(int x) {
    printf("%c", x + 65);
    if (s[x][1] != 0) f1(s[x][1]);
    if (s[x][2] != 0) f1(s[x][2]);
}
void f2(int x) {
    if (s[x][1] != 0) f2(s[x][1]);
    printf("%c", x + 65);
    if (s[x][2] != 0) f2(s[x][2]);
}
void f3(int x) {
    if (s[x][1] != 0) f3(s[x][1]);
    if (s[x][2] != 0) f3(s[x][2]);
    printf("%c", x + 65);
}

int main() {
    //freopen("input.txt", "rt", stdin);
    char a, b, c;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf(" %c %c %c", &a, &b, &c);
        if (b != '.') s[a - 65][1] = b - 65;
        if (c != '.') s[a - 65][2] = c - 65;
    }


    f1(0);
    printf("\n");
    f2(0);
    printf("\n");
    f3(0);
    printf("\n");
    return 0;
}
