#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int a, b, am = 10000, bm = 10000;

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        am = am > a ? a : am;
        bm = bm > b ? b : bm;
    }
    if (am > bm * 6) am = bm * 6;
    if (((n / 6) * am + (n % 6) * bm) > ((n / 6) * am + am)) printf("%d", (n / 6) * am + am);
    else printf("%d", ((n / 6) * am + (n % 6) * bm));
    return 0;
}
