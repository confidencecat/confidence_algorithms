#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <string.h>
#define OBUF_SIZE (1 << 20)

static char outbuf[OBUF_SIZE];
static int out_pos;


void bflush() {
	if (out_pos) {
		fwrite(outbuf, 1, out_pos, stdout);
		out_pos = 0;
	}
}

void printfc(char c) {
	if (out_pos == OBUF_SIZE) bflush();
	outbuf[out_pos++] = c;
}


int n;
char s[1026][2048];

int ww, hh, i, w, h;

int main() {
    out_pos = 0;
    scanf("%d", &n);
    for (i = 0, w = 1; i < (n + 1); i++, w *= 2); w -= 3;
    for (i = 0, h = 1; i < (n); i++, h *= 2); h--;
    bool d = n%2==1;
    int sh = d ? 0 : h - 1;


    for (int m = n; m > 0; m--) {
        for (i = 0, ww = 1; i < (m + 1); i++, ww *= 2); ww -= 3;
        for (i = 0, hh = 1; i < (m); i++, hh *= 2); hh--;
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
        
        for (int j = 0; j < (n%2==1 ? w/2+i + 1 : w - i); j++){
            char cc = s[i][j] == NULL ? ' ' : s[i][j];
            printfc(cc);
        } 
        printfc('\n');
    }
    bflush();
    
    return 0;
}
