#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int a[102];

void change(int s, int e) {
    //printf("%d\n", s - e);
    for (int i = 0; i < (e - s + 1) / 2; i++) {
        //printf("%d ", i);
        int c = a[s + i];
        a[s + i] = a[e - i];
        a[e - i] = c;
    }
    //printf("\n");
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) a[i] = i;

    for (int i = 0; i < m; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        change(s, e);
    }

    for (int i = 1; i <= n; i++) printf("%d ", a[i]);

    return 0;
}
