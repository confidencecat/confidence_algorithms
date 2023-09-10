#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> a[1001];
bool c[1001];

void f(int x) {
    c[x] = true;
    for (int i = 0; i < a[x].size(); i++) {
        if (c[a[x][i]] == false) {
            f(a[x][i]);
        }
    }
}
int main() {
    int n, m, ans = 0, s, e;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        a[s].push_back(e);
        a[e].push_back(s);
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == false) {
            f(i);
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}