#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}


int n, c, mi, mx, d, ans = 0;
int a[200001];


int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(a[0]), com);

    int l = 1, r = a[n - 1] - a[0], mid;

    while (l <= r) {
        mid = (l + r) / 2;

        int st = 0;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[st] >= mid) {
                st = i;
                count++;
            }
        }

        if (count >= c) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    printf("%d\n", ans);

    return 0;
}
