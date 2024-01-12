#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, a[2001], ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d ", &a[i]);
    qsort(a, n, sizeof(int), com);

    for (int i = 0; i < n; i++) {
        int s = 0, e = n - 1;

        while (s < e) {
            if (a[s] + a[e] == a[i]) {
                if (s != i && e != i) {
                    ans++;
                    break;
                }
                else if (s == i) s++;
                else if (e == i) e--;
            }
            else if (a[s] + a[e] > a[i]) e--;
            else if (a[s] + a[e] < a[i]) s++;
        }
    }
    printf("%d\n", ans);
    return 0;
}