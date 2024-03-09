#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;
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
}void cleanup_input() { free(input.read_buf); }

void init_output() {
	output.write_buf = (char*)malloc(SZ);
	output.write_idx = 0;
}

void bflush() {
	if (output.write_idx) {
		fwrite(output.write_buf, 1, output.write_idx, stdout);
		output.write_idx = 0;
	}
}void printfc(char c) {
	if (output.write_idx == SZ) bflush();
	output.write_buf[output.write_idx++] = c;
}void printfi(int n) {
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
int n, ln = 0, ch[1000001];
long long int a[1000001], l[1000001];
vector<long long int> v;

int lower_bound( int key) {
	int start = 0, end = ln - 1;
	int ans = ln - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (l[mid] > key) {
			end = mid - 1;
			ans = mid;
		}
		else if (l[mid] < key) {
			start = mid + 1;
		}
		else {
			ans = mid;
			break;
		}
	}
	return ans;
}

int main() {
	init_input();
	init_output();
	//freopen("input.txt", "rt", stdin);
	n = scanfi();
	for (int i = 0; i < n; i++) {
		a[i] = scanfl();

		if (ln == 0) {
			l[ln++] = a[i];
			ch[0] = 0;
		}
		else if (l[ln - 1] < a[i]) {
			ch[i] = ln;
			l[ln++] = a[i];
			
		}
		else {
			int pos = lower_bound(a[i]);
			l[pos] = a[i];
			ch[i] = pos;
		}
	}
	printfi(ln);
	printfc('\n');
	int cnt = ln - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (ch[i] == cnt) {
			cnt--;
			v.push_back(a[i]);
		}
	}
	while (!v.empty()) {
		printfl(v.back());
		printfc(' ');
		v.pop_back();
	}
	cleanup_input();
	cleanup_output();
	return 0;
}