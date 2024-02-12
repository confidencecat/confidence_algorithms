#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;


#include <string.h>

#define SZ (1 << 20)

typedef struct {
    char* read_buf;
    int read_idx, next_idx;
    int __END_FLAG__, __GETLINE_FLAG__;
} INPUT;

typedef struct {
    char* write_buf;
    int write_idx;
} OUTPUT;

void init_input(INPUT* input) {
    input->read_buf = (char*)malloc(SZ * sizeof(char));
    if (input->read_buf == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    input->read_idx = 0;
    input->next_idx = 0;
    input->__END_FLAG__ = 0;
    input->__GETLINE_FLAG__ = 0;
}

char readChar(INPUT* input) {
    if (input->read_idx == input->next_idx) {
        input->next_idx = fread(input->read_buf, 1, SZ, stdin);
        if (input->next_idx == 0) return '\0'; // EOF or error
        input->read_idx = 0;
    }
    return input->read_buf[input->read_idx++];
}

int is_blank(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

int readInt(INPUT* input) {
    int result = 0, sign = 1;
    char c = readChar(input);

    // Skip blank characters
    while (is_blank(c)) c = readChar(input);

    // Check for negative numbers
    if (c == '-') {
        sign = -1;
        c = readChar(input);
    }

    // Read number
    while (c >= '0' && c <= '9') {
        result = result * 10 + (c - '0');
        c = readChar(input);
    }

    return result * sign;
}

void cleanup_input(INPUT* input) {
    free(input->read_buf);
}

void init_output(OUTPUT* output) {
    output->write_buf = (char*)malloc(SZ * sizeof(char));
    if (output->write_buf == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    output->write_idx = 0;
}

void bflush(OUTPUT* output) {
    if (output->write_idx > 0) {
        fwrite(output->write_buf, sizeof(char), output->write_idx, stdout);
        output->write_idx = 0;
    }
}

void writeChar(OUTPUT* output, char c) {
    if (output->write_idx == SZ) bflush(output);
    output->write_buf[output->write_idx++] = c;
}

void writeInt(OUTPUT* output, int n) {
    if (n == 0) {
        writeChar(output, '0');
        return;
    }

    int sign = n < 0 ? -1 : 1;
    if (sign < 0) {
        writeChar(output, '-');
        n = -n;
    }

    char temp[12]; // Enough for an int
    int temp_idx = 0;

    while (n > 0) {
        temp[temp_idx++] = '0' + (n % 10);
        n /= 10;
    }

    for (int i = temp_idx - 1; i >= 0; --i) {
        writeChar(output, temp[i]);
    }
}

void cleanup_output(OUTPUT* output) {
    bflush(output); // Make sure to flush before cleanup
    free(output->write_buf);
}

int d[1000001];

int find(int a) {
	if (d[a] == a) return a;
	return d[a] = find(d[a]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);
	if (a != b) {
		d[b] = a;
	}
}

int main() {
    INPUT input;
    OUTPUT output;
    init_input(&input);
    init_output(&output);
	//freopen("input.txt", "rt", stdin);
	int n, m, count = 0, j = 0, ans = 0;
	priority_queue<pair<int, pair<int, int>>> q;
	//scanf("%d %d", &n, &m);
    n = readInt(&input);
    m = readInt(&input);
	for (int i = 1; i <= m; i++) {
		d[i] = i;
		int ss, ee, vv;
        ss = readInt(&input);
        ee = readInt(&input);
        vv = readInt(&input);
		//scanf("%d %d %d", &ss, &ee, &vv);
		q.push({ -vv, {ss, ee} });
	}

	while (!q.empty() && count < n - 2) {
		int v = -q.top().first;
		int s = q.top().second.first;
		int e = q.top().second.second;
		q.pop();

		if (find(s) != find(e)) {
			uni(s, e);
			ans += v;
			count++;
		}
	}
    writeInt(&output, ans);
	//printf("%d\n", ans);
    cleanup_input(&input);
    cleanup_output(&output);
	return 0;
}