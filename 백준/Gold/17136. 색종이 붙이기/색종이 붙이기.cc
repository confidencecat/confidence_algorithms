#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n = 10, map[12][12], ans = 1e9;
int paper[6] = { 0, 5, 5, 5, 5, 5 };

bool check(int y, int x, int sz) {
    if (y + sz - 1 > 10 || x + sz - 1 > 10) return false;
    for (int i = y; i < y + sz; i++) {
        for (int j = x; j < x + sz; j++) {
            if (map[i][j] == 0) return false;
        }
    }
    return true;
}

void cover(int y, int x, int sz, int val) {
    for (int i = y; i < y + sz; i++) {
        for (int j = x; j < x + sz; j++) {
            map[i][j] = val;
        }
    }
}

void dfs(int cnt) {
    if (cnt >= ans) return;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == 1) {
                for (int sz = 5; sz >= 1; sz--) {
                    if (paper[sz] > 0 && check(i, j, sz)) {
                        cover(i, j, sz, 0);
                        paper[sz]--;
                        dfs(cnt + 1);
                        cover(i, j, sz, 1);
                        paper[sz]++;
                    }
                }
                return;
            }
        }
    }
    ans = min(ans, cnt);
}

int main() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    dfs(0);
    if (ans == 1e9) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
