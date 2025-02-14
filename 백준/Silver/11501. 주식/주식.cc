#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t, n;
long long int a[1000001], ans = 0;

//============================
#include <stdlib.h>
#include <string.h>

#define IBUF_SIZE (1 << 20)
#define OBUF_SIZE (1 << 20)

static char inbuf[IBUF_SIZE];
static int in_pos, in_len;

static char outbuf[OBUF_SIZE];
static int out_pos;

void init_input() {
    in_pos = 0;
    in_len = 0;
}

char scanfc() {
    if (in_pos == in_len) {
        in_len = (int)fread(inbuf, 1, IBUF_SIZE, stdin);
        if (in_len == 0) return 0;
        in_pos = 0;
    }
    return inbuf[in_pos++];
}

int is_blank(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

int scanfi() {
    int c = scanfc();
    while (is_blank(c)) c = scanfc();
    int sign = 1;
    if (c == '-') { sign = -1; c = scanfc(); }
    int res = 0;
    while (c >= '0' && c <= '9') {
        res = res * 10 + (c - '0');
        c = scanfc();
    }
    return res * sign;
}

long long scanfl() {
    int c = scanfc();
    while (is_blank(c)) c = scanfc();
    int sign = 1;
    if (c == '-') { sign = -1; c = scanfc(); }
    long long res = 0;
    while (c >= '0' && c <= '9') {
        res = res * 10 + (c - '0');
        c = scanfc();
    }
    return res * sign;
}

char* scanfs() {
    int cap = 128, len = 0;
    char* s = (char*)malloc(cap);
    char c = scanfc();
    while (is_blank(c)) c = scanfc();
    while (c != 0 && !is_blank(c)) {
        if (len + 1 >= cap) {
            cap *= 2;
            s = (char*)realloc(s, cap);
        }
        s[len++] = c;
        c = scanfc();
    }
    s[len] = '\0';
    return s;
}

void cleanup_input() {
}

void init_output() {
    out_pos = 0;
}

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

void printfi(int n) {
    if (n == 0) { printfc('0'); return; }
    if (n < 0) { printfc('-'); n = -n; }
    char tmp[12];
    int idx = 0;
    while (n) {
        tmp[idx++] = (n % 10) + '0';
        n /= 10;
    }
    while (idx--) {
        printfc(tmp[idx]);
    }
}

void printfl(long long n) {
    if (n == 0) { printfc('0'); return; }
    if (n < 0) { printfc('-'); n = -n; }
    char tmp[21];
    int idx = 0;
    while (n) {
        tmp[idx++] = (n % 10) + '0';
        n /= 10;
    }
    while (idx--) {
        printfc(tmp[idx]);
    }
}

void printfs(const char* s) {
    while (*s) {
        printfc(*s++);
    }
}

void cleanup_output() {
    bflush();
}
//============================

int main() {
    init_input();
    init_output();

    t = scanfi();
    while (t--) {
        n = scanfi();
        ans = 0;

        for (int i = 0; i < n; i++) {
            a[i] = scanfl();
        }
        
        long long int mx = a[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            if (a[j] >= mx) mx = a[j];
            else ans += mx - a[j];
        }
        printfl(ans);
        printfc('\n');
    }

    cleanup_input();
    cleanup_output();

    return 0;
}
