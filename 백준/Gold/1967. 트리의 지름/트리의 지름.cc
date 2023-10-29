#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;

int n, mx = 0;
vector<pair<int, int>> a[10001];

bool v[10001] = { false, };

void f(int s, int fv) {
    int fn = a[s].size();
    if (fv > mx) mx = fv;
    //printf("%d %d %d\n", s, fv, mx);
    for (int i = 0; i < fn; i++) {
        if (v[a[s][i].first] == true) continue;

        v[a[s][i].first] = true;
        v[s] = true;
        f(a[s][i].first, fv + a[s][i].second);
        v[s] = false;
        v[a[s][i].first] = false;
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int s, e, v;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &s, &e, &v);
        a[s].push_back({ e, v });
        a[e].push_back({ s, v });
    }

    for (int i = 1; i <= n; i++) {
        //printf("%d\n", i);
        f(i, 0);
    }
    printf("%d\n", mx);
    return 0;
}
