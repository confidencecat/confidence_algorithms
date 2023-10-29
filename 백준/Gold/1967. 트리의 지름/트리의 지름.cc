#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, mx = 0, endx;
vector<pair<int, int>> a[10002];

bool v[10002];

void f(int s, int fv) {
    v[s] = true;
    int fn = a[s].size();
    if (fv > mx) {
        mx = fv;
        endx = s;
    }
    //printf("%d %d %d\n", s, fv, mx);
    for (int i = 0; i < fn; i++) {
        if (v[a[s][i].first] == true) continue;

        f(a[s][i].first, fv + a[s][i].second);
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int s, e, w;
    scanf("%d", &n);
    if(n == 1) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &s, &e, &w);
        a[s].push_back({ e, w });
        a[e].push_back({ s, w });
    }
    f(1, 0);
    memset(v, false, sizeof(v));
    f(endx, 0);
    printf("%d\n", mx);
    return 0;
}
