#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

char Input[1 << 17];

static inline char input()
{
    static int index = 1 << 17;
    if (index == 1 << 17) {
        Input[fread(Input, 1, 1 << 17, stdin)] = 0;
        index = 0;
    }
    return Input[index++];
}

int read()
{
    char now = input();
    register int val = 0;
    while (now >= '0' && now <= '9') {
        val = (val << 3) + (val << 1) + (now - '0');
        now = input();
    }
    return val;
}

int n, s, a[100002], min_len;

int main() {
    //freopen("input.txt", "rt", stdin);
    n = read();
    s = read();
    min_len = n + 1;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        a[i] += a[i - 1];
    }
    int r = 1, l = 1;

    while (l <= n && r <= n) {
        int sum = a[r] - a[l - 1];
        if (sum < s) r++;
        else {
            if (min_len >= r - l + 1) min_len = r - l + 1;
            l++;
        }
    }
    printf("%d\n", min_len == n + 1 ? 0 : min_len);
    return 0;
}
