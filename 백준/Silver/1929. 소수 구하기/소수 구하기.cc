#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool era[1000001];

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 2; i <= m; i++) {
        if (!era[i]) {
            for (int j = i + i; j <= m; j += i) {
                era[j] = 1;
            }
        }
    }

    for (int i = n; i <= m; i++) {
        if (!era[i] && i > 1) printf("%d\n", i);
    }
    return 0;
}
