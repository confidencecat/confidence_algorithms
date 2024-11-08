#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int arr[1000001];
int ans = 0;

int lower_bound(int key) {
    int start = 0, end = ans - 1;
    int ret = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] >= key) {
            end = mid - 1;
            ret = mid;
        }
        else {
            start = mid + 1;
        }
    }
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (ans == 0 || arr[ans - 1] < a) {
            arr[ans++] = a;
        }
        else {
            int pos = lower_bound(a);
            arr[pos] = a;
        }
    }

    printf("%d\n", ans);
    return 0;
}
