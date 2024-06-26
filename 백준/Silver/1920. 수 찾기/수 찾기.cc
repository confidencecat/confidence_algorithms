#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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


int arr[100000], n, m, ma;

int f(int a) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == a) return 1;
        else if (a < arr[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return 0;
}

int cmp(const void* a, const void* b) {
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main() {
    INPUT input;
    OUTPUT output;
    init_input(&input);
    init_output(&output);
    //freopen("input.txt", "rt", stdin);
    n = readInt(&input);
    for (int i = 0; i < n; i++) {
        arr[i] = readInt(&input);
    }

    qsort(arr, n, sizeof(int), cmp);

    m = readInt(&input);
    for (int i = 0; i < m; i++) {
        ma = readInt(&input);
        writeInt(&output, f(ma));
        writeChar(&output, '\n');
    }

    cleanup_input(&input);
    cleanup_output(&output);
    return 0;
}