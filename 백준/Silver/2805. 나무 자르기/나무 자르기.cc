#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
long long M, trees[1000001];

int isPossible(unsigned int height) {
    long long taken = 0;
    for (int i = 0; i < N; i++) {
        if (trees[i] >= height)
            taken += (trees[i] - height);
        if (taken >= M) return 1;
    }
    return 0;
}

int solve() {
    unsigned int left = 0, right = 1000000000;
    unsigned int mid, ret;
    while (left <= right) {
        mid = (left + right) / 2;
        if (isPossible(mid)) {
            ret = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ret;
}

int main() {
    // freopen("input.txt", "rt", stdin);
    scanf("%d %lld", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &trees[i]);
    }
    printf("%d\n", solve());
    return 0;
}
