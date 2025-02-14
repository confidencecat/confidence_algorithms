#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//============================

#include <stdlib.h>
#include <string.h>

#define IBUF_SIZE (1 << 20)
#define OBUF_SIZE (1 << 20)

static char inbuf[IBUF_SIZE];
static char* in_ptr, * in_end;
static char outbuf[OBUF_SIZE];
static int out_pos;

void init() {
	in_ptr = in_end = inbuf;
	out_pos = 0;
}

static inline char scanfc() {
	if (in_ptr == in_end) {
		int bytes = (int)fread(inbuf, 1, IBUF_SIZE, stdin);
		if (!bytes) return 0;
		in_ptr = inbuf;
		in_end = inbuf + bytes;
	}
	return *in_ptr++;
}

int scanfi() {
	int c = scanfc();
	while (c == ' ' || c == '\n' || c == '\r' || c == '\t') c = scanfc();
	int sign = 1;
	if (c == '-') { sign = -1; c = scanfc(); }
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = scanfc();
	}
	return sign * x;
}

long long scanfl() {
	int c = scanfc();
	while (c == ' ' || c == '\n' || c == '\r' || c == '\t') c = scanfc();
	int sign = 1;
	if (c == '-') { sign = -1; c = scanfc(); }
	long long x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10LL + (c - '0');
		c = scanfc();
	}
	return sign * x;
}

char* scanfs() {
	int cap = 128, len = 0;
	char* s = (char*)malloc(cap);
	int c = scanfc();
	while (c == ' ' || c == '\n' || c == '\r' || c == '\t') c = scanfc();
	while (c && c != ' ' && c != '\n' && c != '\r' && c != '\t') {
		if (len + 1 >= cap) {
			cap <<= 1;
			s = (char*)realloc(s, cap);
		}
		s[len++] = c;
		c = scanfc();
	}
	s[len] = '\0';
	return s;
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
	char buf[12];
	int idx = 0;
	while (n) {
		buf[idx++] = (n % 10) + '0';
		n /= 10;
	}
	while (idx--) printfc(buf[idx]);
}

void printfl(long long n) {
	if (n == 0) { printfc('0'); return; }
	if (n < 0) { printfc('-'); n = -n; }
	char buf[21];
	int idx = 0;
	while (n) {
		buf[idx++] = (n % 10) + '0';
		n /= 10;
	}
	while (idx--) printfc(buf[idx]);
}

void printfs(const char* s) {
	while (*s) printfc(*s++);
}

//============================

int main() {
	init();

	int n = scanfi();
	long long int ans = 0;
	printfi(n); printfc('\n');
	while (n--) {
		ans += scanfi();
	}

	printfl(ans);

	bflush();

	return 0;
}