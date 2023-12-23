#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>

int com(const void *first, const void *second) {
    return *(int*)first - *(int*)second;
}

int n, m, a[500000], b[500000];

bool find(int x) {
    int find_n = b[x];
    int l = 0, r = n - 1, mid;
    bool find_tf = false;
    while (l <= r && !find_tf) {
        mid = (l + r) / 2;
        //printf("%d %d %d\n", l, r, mid);
        if (a[mid] == find_n) {
            find_tf = true;
        }
        else if (find_n > a[mid]) {
            l = mid + 1;
        }
        else if (find_n < a[mid]) {
            r = mid - 1;
        }
        
    }
    return find_tf;
}

int main() {
    //freopen("input.txt", "rt", stdin); 
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    qsort(a, n, sizeof(int), com);

    for (int i = 0; i < m; i++) {
        printf("%d ", find(i) ? 1 : 0);
    }

    return 0;
}
