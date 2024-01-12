#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[10];

int find(int a) {
    if (arr[a] == a) return a;
    return arr[a] = find(arr[a]);
}

void make_union(int a, int b) {
    int a = find(a);
    int b = find(b);
    if (a != b) {
        arr[b] = a;
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) arr[i] = i;

    for (int i = 0; i < m; i++) {
        int tf;
        scanf("%d", &tf);
        if (tf == 0) {
            int a, b;
            scanf("%d %d", &a, &b);
            make_union(a, b);
        }
        else {
            int a;
            scanf("%d", &a);
            printf("%d\n", find(a));
        }
    }
    return 0;
}v
