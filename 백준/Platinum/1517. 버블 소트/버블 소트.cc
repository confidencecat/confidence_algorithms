#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n;
int a[500001], b[500001];
long long int ans = 0;

void merge(int s, int e) {
    int mid = (s + e) / 2;
    int i = s, j = mid + 1, k = s, cnt = 0;

    while (i <= mid && j <= e) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
            ans += cnt;
        }
        else {
            b[k++] = a[j++];
            cnt++;
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
        ans += cnt;
    }
    while (j <= e) {
        b[k++] = a[j++];
        cnt++;
    }

    for (int i = s; i <= e; i++) a[i] = b[i];
}

void merge_sort(int s, int e) {
    if (s < e) {
        int mid = (s + e) / 2;
        merge_sort(s, mid);
        merge_sort(mid + 1, e);
        merge(s, e);
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    merge_sort(0, n - 1);


    printf("%lld\n", ans);


    return 0;
}
