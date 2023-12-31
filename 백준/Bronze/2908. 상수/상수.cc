#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    char a[4], b[4];
    scanf("%s %s", a, b);

    for (int i = 2; i >= 0; i--) {
        if (a[i] > b[i]) {
            for (int j = 2; j >= 0; j--) printf("%c", a[j]);
            return 0;
        }
        else if (a[i] < b[i]) {
            for (int j = 2; j >= 0; j--) printf("%c", b[j]);
            return 0;
        }
    }
    for (int j = 2; j >= 0; j--) printf("%c", a[j]);
    return 0;
}
