#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <queue>
#include <climits> // INT_MAX를 사용하기 위해
using namespace std;

int answer[20001];

int main() {
    //freopen("input.txt", "rt", stdin);
    int v, e, s, nu, nv, nw, b;
    scanf("%d %d", &v, &e);
    vector<pair<int, int>> a[20001];

    for (int i = 1; i <= v; i++) {
        answer[i] = INT_MAX;
    }

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &nu, &nv, &nw);
        a[nu].push_back(make_pair(nv, nw));
    }
    scanf("%d %d", &s, &b);
    answer[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        int d = -q.top().first;
        int c = q.top().second;
        q.pop();
        if (answer[c] < d) continue;
        for (auto& p : a[c]) {
            int next = p.first;
            int nextd = d + p.second;

            if (nextd < answer[next]) {
                answer[next] = nextd;
                q.push(make_pair(-nextd, next));
            }
        }
    }

    printf("%d", answer[b]);
    return 0;
}