#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int answer[1001], answer1[1001];

int main() {
    //freopen("input.txt", "rt", stdin);
    int v, e, s, nu, nv, nw, mx = 0;
    scanf("%d %d %d", &v, &e, &s);
    vector<pair<int, int>> a[1001], a1[1001];

    for (int i = 1; i <= v; i++) {
        answer1[i] = answer[i] = INT_MAX;
    }

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &nu, &nv, &nw);
        a[nu].push_back(make_pair(nv, nw));
        a1[nv].push_back(make_pair(nu, nw));
    }

    answer[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, s));

    answer1[s] = 0;
    priority_queue<pair<int, int>> q1;
    q1.push(make_pair(0, s));

    while (!q.empty() || !q1.empty()) {
        if (!q.empty()) {
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
        if (!q1.empty()) {
            int d = -q1.top().first;
            int c = q1.top().second;
            q1.pop();
            if (answer1[c] < d) continue;

            for (auto& p : a1[c]) {
                int next = p.first;
                int nextd = d + p.second;
                if (nextd < answer1[next]) {
                    answer1[next] = nextd;
                    q1.push(make_pair(-nextd, next));
                }
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (answer[i] + answer1[i] > mx) mx = answer[i] + answer1[i];
    }
    printf("%d\n", mx);
    return 0;
}
