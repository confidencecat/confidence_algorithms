#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[52];

int find(int a) {
    if (arr[a] == a) return a;
    return arr[a] = find(arr[a]);
}

void make_union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        arr[b] = a;
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, p[51][51], ans = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) arr[i] = i;

    int know_n, know[51];
    scanf("%d", &know_n);
    for (int i = 0; i < know_n; i++) {
        scanf("%d", &know[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &p[i][0], &p[i][1]);
        for (int j = 2; j <= p[i][0]; j++) {
            scanf("%d", &p[i][j]);
            make_union(p[i][1], p[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        bool tf = true;
        for (int j = 0; j < know_n; j++) {
            if (find(p[i][1]) == find(know[j])) tf = false;
        }
        if (tf) ans++;
    }
    printf("%d\n", ans);
    return 0;
}