#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int x, y;
    char d;
} Q;

int a[16][16];

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, ans;
    scanf("%d", &n);

    queue<Q> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    q.push({ 2, 1, 'h' });
    ans = 0;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        char d = q.front().d;
        q.pop();

        if (x == n && y == n) {
            ans++;
            continue;
        }

        if ((d == 'h' || d == 'd') && x + 1 <= n && a[y][x + 1] != 1) {
            q.push({ x + 1, y, 'h' });
        }

        if ((d == 'v' || d == 'd') && y + 1 <= n && a[y + 1][x] != 1) {
            q.push({ x, y + 1, 'v' });
        }

        if (x + 1 <= n && y + 1 <= n && a[y][x + 1] != 1 && a[y + 1][x] != 1 && a[y + 1][x + 1] != 1) {
            q.push({ x + 1, y + 1, 'd' });
        }
    }

    printf("%d\n", ans);
    return 0;
}
