#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

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

void cleanup_input() { free(input.read_buf); }
void cleanup_output() {
	bflush();
	free(output.write_buf);
}

int n, mx = -1, mx_node = 0;
vector<pair<int, int>> v[100001];
bool ch[100001];

int bfs(int sx) {
	memset(ch, false, sizeof(bool) * (n + 1));

	int mx = 0;
	queue<pair<int, int>> q;

	q.push({ sx, 0 });
	ch[sx] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop();

		if (d > mx) {
			mx = d;
			mx_node = x;
		}

		for (auto c : v[x]) {
			int cx = c.first;
			int cd = c.second;

			if (ch[cx] == true) continue;

			ch[cx] = true;
			q.push({ cx, d + cd });
		}
	}

	return mx;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	init_input();
	init_output();

	n = scanfi();

	for (int i = 1; i <= n; i++) {
		int ss = scanfi();
		while (1) {
			int aa = scanfi();
			if (aa == -1) break;
			int bb = scanfi();
			v[ss].push_back({ aa, bb });
		}
	}

	bfs(1);
	int ans = bfs(mx_node);
	printfi(ans);

	cleanup_input();
	cleanup_output();

	return 0;
}
