#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#define INF 200000000
using namespace std;

struct Q {
    int e, w;

    Q(int a, int b) {
        e = a;
        w = b;
    }

    bool operator<(const Q& q)const {
        return w > q.w;
    }
};

int n, m, st;
int d[1001];
int rd[1001];


vector<pair<int, int>> vv[1001];
vector<pair<int, int>> rv[1001];

void dij(vector<pair<int, int>> v[], int arr[]) {
    priority_queue<Q> q;
    
    for (int i = 1; i <= n; i++) arr[i] = INF;

    arr[st] = 0;

    q.push({ st, 0 });

    while (!q.empty()) {
        int x = q.top().e;
        int w = q.top().w;
        q.pop();

        if (w > arr[x]) continue;

        for (auto cx : v[x]) {
            if (cx.second + w < arr[cx.first]) {
                arr[cx.first] = cx.second + w;
                q.push({ cx.first, cx.second + w });
            }
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d %d", &n, &m, &st);

    for (int i = 1; i <= n; i++) d[i] = INF;

    for (int i = 0; i < m; i++) {
        int ss, ee, W;
        scanf("%d %d %d", &ss, &ee, &W);
        vv[ss].push_back({ ee, W });
        rv[ee].push_back({ ss, W });
    }

    dij(vv, d);
    dij(rv, rd); 

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (i == st) continue;
        if (d[i] + rd[i] > ans) ans = d[i] + rd[i];
    }
    printf("%d", ans);

    return 0;
}