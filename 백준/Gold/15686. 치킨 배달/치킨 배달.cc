#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n, m;
int map[50][50];
int houses[50][2], houses_n = 0;
int chicken[50][2], chicken_n = 0;
int selected[50];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int fsum() {
    int sum = 0;
    for (int i = 0; i < houses_n; i++) {
        int msum = INT_MAX;
        for (int j = 0; j < chicken_n; j++) {
            if (selected[j]) {
                int d = abs(houses[i][0] - chicken[j][0]) + abs(houses[i][1] - chicken[j][1]);
                msum = min(msum, d);
            }
        }
        sum += msum;
    }
    return sum;
}

int f(int x, int fn) {
    if (fn == m) {
        return fsum();
    }
    if (x == chicken_n) {
        return INT_MAX;
    }

    int ans = INT_MAX;

    selected[x] = 1;
    ans = min(ans, f(x + 1, fn + 1));

    selected[x] = 0;
    ans = min(ans, f(x + 1, fn));

    return ans;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                houses[houses_n][0] = i;
                houses[houses_n++][1] = j;
            }
            else if (map[i][j] == 2) {
                chicken[chicken_n][0] = i;
                chicken[chicken_n++][1] = j;
            }
        }
    }

    printf("%d\n", f(0, 0));

    return 0;
}
