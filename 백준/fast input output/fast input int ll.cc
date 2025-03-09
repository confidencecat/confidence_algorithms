
char rbuf[1 << 20];
int idx, nidx;
inline char read() {
    if (idx == nidx) {
        nidx = fread(rbuf, 1, 1 << 20, stdin);
        if (!nidx) return 0;
        idx = 0;
    }
    return rbuf[idx++];
}
inline long long rll() {
    long long sum = 0;
    char now = read();
    while (now <= 32) now = read();
    while (now >= 48) {
        sum = sum * 10LL + (now - '0');
        now = read();
    }
    return sum;
}

inline int ri() {
    int sum = 0;
    char now = read();

    while (now <= 32) now = read();
    while (now >= 48) sum = sum * 10 + now - '0', now = read();

    return sum;
}
