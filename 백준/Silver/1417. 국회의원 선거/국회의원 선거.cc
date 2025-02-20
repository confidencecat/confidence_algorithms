#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int n, d, a, ans;

int main() {
    priority_queue<int> q;
    scanf("%d %d", &n, &d);
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a);
        q.push(a);
    }
    
    while (1) {
        int t = q.top();
        q.pop();
        if (t < d) break;
        d++;
        ans++;
        q.push(t - 1);
    }

    printf("%d\n", ans);
    return 0;
}
