#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int n, w, l;
int a[1001];
int ans = 0, sum = 0;
queue<int> q;


int main() {
    scanf("%d %d %d", &n, &w, &l);

    for (int i = 0; i < w; i++) q.push(0);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; ans++) {
        sum -= q.front();
        q.pop();

        q.push((sum + a[i] <= l ? a[i] : 0));
        sum += (sum + a[i] <= l ? a[i++] : 0);
    }
    printf("%d\n", ans + w);
    return 0;
}
