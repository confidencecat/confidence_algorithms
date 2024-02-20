#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ (1 << 20)

typedef struct {
    char* read_buf;
    int read_idx, next_idx;
} INPUT;

typedef struct {
    char* write_buf;
    int write_idx;
} OUTPUT;

INPUT input;
OUTPUT output;

void init_input() {
    input.read_buf = (char*)malloc(SZ);
    input.read_idx = input.next_idx = 0;
}

char scanfc() {
    if (input.read_idx == input.next_idx) {
        input.next_idx = fread(input.read_buf, 1, SZ, stdin);
        if (!input.next_idx) return 0;
        input.read_idx = 0;
    }
    return input.read_buf[input.read_idx++];
}

int is_blank(char c) { return c == ' ' || c == '\n' || c == '\r' || c == '\t'; }

int scanfi() {
    int result = 0, sign = 1;
    char c = scanfc();
    while (is_blank(c)) c = scanfc();
    if (c == '-') { sign = -1; c = scanfc(); }
    while (c >= '0' && c <= '9') { result = result * 10 + (c - '0'); c = scanfc(); }
    return result * sign;
}

long long scanfl() {
    long long result = 0;
    int sign = 1;
    char c = scanfc();
    while (is_blank(c)) c = scanfc();
    if (c == '-') { sign = -1; c = scanfc(); }
    while (c >= '0' && c <= '9') { result = result * 10 + (c - '0'); c = scanfc(); }
    return result * sign;
}

char* scanfs() {
    char* str = (char*)malloc(SZ);
    int i = 0;
    char c = scanfc();
    while (is_blank(c)) c = scanfc();
    while (!is_blank(c) && c) {
        str[i++] = c;
        c = scanfc();
    }
    str[i] = '\0';
    return str; // Caller must free this memory
}

void cleanup_input() { free(input.read_buf); }

void init_output() {
    output.write_buf = (char*)malloc(SZ);
    output.write_idx = 0;
}

void bflush() {
    if (output.write_idx) {
        fwrite(output.write_buf, 1, output.write_idx, stdout);
        output.write_idx = 0;
    }
}

void printfc(char c) {
    if (output.write_idx == SZ) bflush();
    output.write_buf[output.write_idx++] = c;
}

void printfi(int n) {
    if (!n) { printfc('0'); return; }
    if (n < 0) { printfc('-'); n = -n; }
    char temp[12];
    int i = 0;
    while (n) { temp[i++] = n % 10 + '0'; n /= 10; }
    while (i--) printfc(temp[i]);
}

void printfl(long long n) {
    if (!n) { printfc('0'); return; }
    if (n < 0) { printfc('-'); n = -n; }
    char temp[20];
    int i = 0;
    while (n) { temp[i++] = n % 10 + '0'; n /= 10; }
    while (i--) printfc(temp[i]);
}

void printfs(const char* str) {
    while (*str) {
        printfc(*str++);
    }
}

void cleanup_output() {
    bflush();
    free(output.write_buf);
}

int n, m, mod = 1e9;
int d[100001], sv[100001], ev[100001];
long long int sum, ans, cnt[100001];

int find(int a) {
	if (a == d[a]) return a;
	return d[a] = find(d[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) d[b] = a;
}

int main() {
    init_input();
    init_output();
	//freopen("input.txt", "rt", stdin);
	//scanf("%d %d", &n, &m);
    n = scanfi();
    m = scanfi();

	for (int i = 1; i <= n; i++) {
		d[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int ss, ee, vv;
        ss = scanfi();
        ee = scanfi();
        vv = scanfi();
		sv[vv] = ss;
		ev[vv] = ee;
		sum += vv;
	}

	sum %= mod;

	for (int i = 100000; i > 0; i--) {
		if (sv[i] != 0) {
			int sf = find(sv[i]), ef = find(ev[i]);
			if (sf != ef) {
				ans = (ans + sum * cnt[sf] * cnt[ef]) % mod;
				d[ef] = sf;
				cnt[sf] += cnt[ef];
			}
			sum = (sum - i + mod) % mod;
		}
	}
    printfl(ans);
    cleanup_input();
    cleanup_output();
	return 0;
}