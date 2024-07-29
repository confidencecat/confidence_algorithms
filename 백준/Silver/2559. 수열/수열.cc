#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int n, m, s, d[100001], mx = -1000;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &s);
        d[i] = d[i - 1] + s;
        if (i >= m) {
            if (d[i] - d[i - m] > mx) mx = d[i] - d[i - m];
        }
    }
    printf("%d\n", mx);



    return 0;
}
