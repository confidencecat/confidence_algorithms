#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, m;
    int arr[51], a[51];
    int ans = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    int size = n;
    for (int i = 0; i < m; i++) {
        int pos = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == a[i]) {
                pos = j;
                break;
            }
        }
        if (pos <= size - pos - 1) {
            ans += pos;
            while (pos--) {
                int temp = arr[0];
                for (int k = 0; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                arr[size - 1] = temp;
            }
        }
        else {
            ans += (size - pos);
            for (int j = 0; j < size - pos; j++) {
                int temp = arr[size - 1];
                for (int k = size - 1; k > 0; k--) {
                    arr[k] = arr[k - 1];
                }
                arr[0] = temp;
            }
        }
        for (int j = 0; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--;
    }

    printf("%d\n", ans);
    return 0;
}
