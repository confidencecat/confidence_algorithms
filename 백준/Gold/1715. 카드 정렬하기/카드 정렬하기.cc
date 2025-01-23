#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);

    int n, a, ans = 0;
    priority_queue<int> q;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        q.push(a*-1);
    }

    while (q.size() > 1) {
        int x = -1*q.top();
        q.pop();
        int y = -1*q.top();
        q.pop();
        ans += x + y;
        q.push((x + y)*-1);
    }
    printf("%d\n", ans);

    return 0;
}
