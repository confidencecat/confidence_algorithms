#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

bool t[1001];
int n, m;

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        if (t[i] == false) {
            m--;
            if (m == 0) {
                printf("%d", i);
                return 0;
            }
            for (int j = i; j <= n; j += i) {
                if (i == j) continue;
                if (t[j] == false) {
                    t[j] = true;
                    m--;
                    if (m == 0) {
                        printf("%d", j);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
