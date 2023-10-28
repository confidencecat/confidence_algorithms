#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

int cnt = 0, n, c[16];

void f(int col) {
    if (col == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        bool ch = true;
        for (int j = 0; j < col; j++) {
            c[col] = i;
            if (c[j] == c[col] || ((j - col) == (c[j] - c[col]) || ((j - col) == c[col] - c[j]))) {
                ch = false;
                break;
            }
        }
        if (ch) {
            f(col + 1);
        }
    }

}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        c[0] = i;
        f(1);
    }
    printf("%d\n", cnt);

    return 0;
}

