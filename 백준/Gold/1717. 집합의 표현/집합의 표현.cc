#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int n, m;
int d[1000003];
int c, a, b;

int find(int x) {
    if (d[x] == x) return x;
    else return d[x] = find(d[x]);
}
void uni(int a, int b) {
    a = find(a); b = find(b);
    if (a != b) d[b] = a;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) d[i] = i;
    

    for(int j = 0; j < m; j++) {
        scanf("%d %d %d", &c, &a, &b);
        if (c == 0) {
            uni(a, b);
        }
        else {
            if (find(a) == find(b)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
