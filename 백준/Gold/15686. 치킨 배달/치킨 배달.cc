#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n, m;
int city[50][50];
int hs[50 * 2][2], hs_cnt = 0;
int ck[50 * 2][2], ck_cnt = 0;
int sel[50 * 2];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int f() {
    int ans = 0;
    for (int i = 0; i < hs_cnt; i++) {
        int dist = INT_MAX;
        for (int j = 0; j < ck_cnt; j++) {
            if (sel[j]) {
                int d = abs(hs[i][0] - ck[j][0]) + abs(hs[i][1] - ck[j][1]);
                dist = min(dist, d);
            }
        }
        ans += dist;
    }
    return ans;
}

int solve(int idx, int cnt) {
    if (cnt == m) {
        return f();
    }
    if (idx == ck_cnt) {
        return INT_MAX;
    }

    int min_dist = INT_MAX;
    sel[idx] = 1;
    min_dist = min(min_dist, solve(idx + 1, cnt + 1));
    sel[idx] = 0;
    min_dist = min(min_dist, solve(idx + 1, cnt));

    return min_dist;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            scanf("%d", &city[r][c]);
            if (city[r][c] == 1) {
                hs[hs_cnt][0] = r;
                hs[hs_cnt][1] = c;
                hs_cnt++;
            }
            else if (city[r][c] == 2) {
                ck[ck_cnt][0] = r;
                ck[ck_cnt][1] = c;
                ck_cnt++;
            }
        }
    }

    printf("%d\n", solve(0, 0));

    return 0;
}
