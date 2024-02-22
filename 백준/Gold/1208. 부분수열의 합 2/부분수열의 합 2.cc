#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, S;
int arr[41];
long long subsum[8000001];
long long cnt = 0;

void r(int index, int sum) {
    if (index == n) {
        subsum[sum + 4000000]++;
        return;
    }
    r(index + 1, sum + arr[index]);
    r(index + 1, sum);
}

void l(int index, int sum) {
    if (index == n / 2) {
        cnt += subsum[S - sum + 4000000];
        return;
    }
    l(index + 1, sum + arr[index]);
    l(index + 1, sum);
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &S);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    r(n / 2, 0);
    l(0, 0);

    if (S == 0) cnt--;

    printf("%lld\n", cnt);

    return 0;
}
