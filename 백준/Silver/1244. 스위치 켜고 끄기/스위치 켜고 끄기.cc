#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int n, m;
int a, b; //1 2 남 여
bool s[101];


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (a == 1) {//남
            for (int j = b; j <= n; j += b) s[j-1] = !s[j-1];
        }
        else {

            b -= 1;
            int l = (n - 1 - b) < b ? (n - 1 - b) : b;
            for (int j = 0; j <= l; j++) {
                if (s[b + j] != s[b - j]) break;
                if(j != 0) s[b + j] = !s[b + j];
                s[b - j] = !s[b - j];
            }
        }
        
    }
    for (int j = 0; j < n; j++) {
        printf("%d ", s[j]);
        if ((j + 1) % 20 == 0) printf("\n");
        
    }
    if (n % 20) printf("\n");
    return 0;
}
