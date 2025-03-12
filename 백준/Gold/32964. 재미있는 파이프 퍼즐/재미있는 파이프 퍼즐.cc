#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
bool c[2][200001];
char a[2][200001];

int main() {
    scanf("%d", &n);
    scanf("%s\n%s", a[0], a[1]);
    c[0][0] = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[0][i] == 'X') c[1][i] = (a[1][i] == 'L');
        else {
            c[0][i] = ((a[0][i] == 'I' && c[0][i - 1]) || (c[1][i - 1] && a[1][i] == 'L'));
            c[1][i] = ((a[1][i] == 'I' && c[1][i - 1]) || (c[0][i - 1] && a[1][i] == 'L'));
        }
    }
    printf("%s", (c[0][n - 2] && a[0][n - 1] == 'L') || (c[1][n - 2] && a[1][n - 2] == 'I') ? "YES" : "NO");


    return 0;
}
