#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;

char rbuf[1 << 17];
char wbuf[1 << 17];
int idx, ridx, widx;

inline char read() {
    if (idx == ridx) {
        ridx = fread(rbuf, 1, 1 << 17, stdin);
        if (!ridx) return 0;
        idx = 0;
    }
    return rbuf[idx++];
}

inline int readInt() {
    int sum = 0;
    char now = read();

    while (now <= 32) now = read();
    while (now >= 48) sum = sum * 10 + now - '0', now = read();

    return sum;
}

inline int unitSize(int n) {
    int ret = 1;
    while (n >= 10) {
        ret++;
        n /= 10;
    }
    return ret;
}

void bflush() {
    fwrite(wbuf, 1, widx, stdout);
    widx = 0;
}

inline void writeInt(int n) {
    int isz = unitSize(n);
    if (isz + widx >= (1 << 17)) bflush();

    int next = widx + isz;
    while (isz--) {
        wbuf[widx + isz] = n % 10 + '0';
        n /= 10;
    }
    widx = next;
}

inline void write(char c) {
    if (widx == (1 << 17)) bflush();
    wbuf[widx++] = c;
}


int era[1000001], n = 0;

int main() {
	//freopen("input.txt", "rt", stdin);
	vector<int> prime;
	
	for (int i = 2; i * i <= 1000000; i++) {
		if (era[i] == 0) {
			prime.push_back(i);
			for (int j = i * i; j <= 1000000; j += i) {
				era[j] = 1;
			}
		}
	}

	while (1) {
        n = readInt();
		if (n == 0) {
			break;
		}

		for (int i = 0; i < prime.size(); i++) {
			if (prime[i] % 2 == 0 || (n - prime[i]) % 2 == 0) continue;
			if (era[n - prime[i]] == 0) {
                writeInt(n); write(' ');
                write('='); write(' ');
                writeInt(prime[i]);
                write(' '); write('+');
                write(' '); writeInt(n - prime[i]);
                write('\n');
				break;
			}
		}
	}
    bflush();
	return 0;
}