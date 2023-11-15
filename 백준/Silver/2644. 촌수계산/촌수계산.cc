#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> a[101];
int e, ans = -1;
bool v[101];

void d(int ds, int n) {
    if (ds == e) {
        ans = n;
        return;
    }
    int dn = a[ds].size();
    for (int i = 0; i < dn; i++) {
        if (v[a[ds][i]] == false) {
            v[a[ds][i]] = true;

            d(a[ds][i], n + 1);

            v[a[ds][i]] = false;
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, s, m;
    
    scanf("%d %d %d %d", &n, &s, &e, &m);
    
    for (int i = 0; i < m; i++) {
        int q, w;
        scanf("%d %d", &q, &w);
        a[q].push_back(w);
        a[w].push_back(q);
    }
    v[s] = true;
    d(s, 0);
    printf("%d\n", ans);
    return 0;
}
