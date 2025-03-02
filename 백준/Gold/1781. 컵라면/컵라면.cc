#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long

struct Problem {
    ll deadline;
    ll ramen;
};

int main() {
    int n;
    scanf("%d", &n);
    vector<Problem> problems(n);

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &problems[i].deadline, &problems[i].ramen);
    }

    sort(problems.begin(), problems.end(), [](const Problem& a, const Problem& b) {
        return a.deadline < b.deadline;
        });


    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(problems[i].ramen);
        if (pq.size() > problems[i].deadline) {
            pq.pop();
        }
    }

    ll ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    printf("%lld\n", ans);
    return 0;
}
