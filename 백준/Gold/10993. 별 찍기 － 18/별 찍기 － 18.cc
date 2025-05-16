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
        //printf("%d %d %d %d\n", ww, hh, sh, d);
        if (d) {
            for (int i = 0; i <= ww / 2; i++) {
                s[i+sh][w / 2 + i] = '*';
                s[i+sh][w / 2 - i] = '*';
                s[sh+hh - 1][w / 2 + i] = '*';
                s[sh+hh - 1][w / 2 - i] = '*';
            }
            sh = sh + hh - 2;
        }
        else {
            sh = sh - hh + 1;
            for (int i = 0; i <= ww / 2; i++) {
                s[sh + i][w / 2 + ww / 2 - i] = '*';
                s[sh + i][w / 2 - ww / 2 + i] = '*';
                s[sh+0][w / 2 + ww / 2 - i] = '*';
                s[sh+0][w / 2 - ww / 2 + i] = '*';
            }
            sh = sh + 1;
        }
        d = !d;
        
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (n%2==1 ? w/2+i + 1 : w - i); j++) printf("%c", s[i][j]);
        printf("\n");
    }
    
    return 0;
}
