#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct { int x, y; } Point;
const long long INF = 4000000000000000000LL;
int n;
Point a[20];
long long total_x, total_y;

long long dfs(int idx, int cnt, long long sum_x, long long sum_y) {
    if (idx == n) {
        if (cnt == n/2) {
            long long dx = 2*sum_x - total_x;
            long long dy = 2*sum_y - total_y;
            return dx*dx + dy*dy;
        }
        return INF;
    }
    if (cnt > n/2 || cnt + (n - idx) < n/2) return INF;
    long long inc = dfs(idx+1, cnt+1, sum_x + a[idx].x, sum_y + a[idx].y);
    long long exc = dfs(idx+1, cnt, sum_x, sum_y);
    return inc < exc ? inc : exc;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        total_x = total_y = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a[i].x, &a[i].y);
            total_x += a[i].x;
            total_y += a[i].y;
        }
        long long best = dfs(0, 0, 0, 0);
        printf("%.12f\n", sqrt((double)best));
    }
    return 0;
}
