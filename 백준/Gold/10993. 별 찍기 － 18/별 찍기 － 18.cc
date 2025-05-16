#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int n;
char s[1026][2048];

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d", &n);
    int w = (int)pow(2, (n + 1)) - 3;
    int h = (int)pow(2, n) - 1;
    bool d = n%2==1;
    int sh = d ? 0 : h - 1;


    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) s[i][j] = ' ';
    }


    int ww, hh;
    for (int m = n; m > 0; m--) {
        ww = (int)pow(2, (m + 1)) - 3;
        hh = (int)pow(2, m) - 1;
        sh = (!d ? sh - hh + 1 : sh);
        for (int i = 0; i <= ww / 2; i++) {
            s[i + sh][w / 2 + i + (d ? 0 : -ww / 2)] = '*';
            s[i + sh][w / 2 - i + (d ? 0 : ww / 2)] = '*';
            s[sh + (d ? hh - 1 : 0)][w / 2 + i + (d ? 0 : -ww / 2)] = '*';
            s[sh + (d ? hh - 1 : 0)][w / 2 - i + (d ? 0 : ww / 2)] = '*';
        }
        sh = (d ? (sh + hh - 2) : sh + 1);
        d = !d;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (n%2==1 ? w/2+i + 1 : w - i); j++) printf("%c", s[i][j]);
        printf("\n");
    }
    
    
    return 0;
}
