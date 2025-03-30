#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <stdlib.h>
using namespace std;

int n, sum = 0;
int a[200001][2];

int com(const void* A, const void* B) {
    int* AA = (int*)A;
    int* BB = (int*)B;
    return AA[0] - BB[0];
}

priority_queue<int> q;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    qsort(a, n, sizeof(a[0]), com);
    for (int i = 0; i < n; i++) {
        q.push(-a[i][1]);
        if (q.size() > a[i][0]) q.pop();
    }
    while (!q.empty()) {
        sum -= q.top();
        q.pop();
    }

    printf("%d\n", sum);
    return 0;
}
