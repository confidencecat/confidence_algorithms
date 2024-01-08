#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
    //freopen("input.txt", "rt", stdin);
    int s, e;
    queue<int> q;
    pair<int, int> dp[100001];
    scanf("%d %d", &s, &e);

    if (s == e) {
        printf("0\n1");
        return 0;
    }
    else if (e == 0) {
        printf("%d\n1", s);
        return 0;
    }

    for (int i = 0; i <= 100000; i++) dp[i].first = 1e9;

    dp[s] = { 0, 1 };

    if (s == 0) {
        dp[1] = { 1, 1 };
        s = 1;
    }

    q.push(s);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x - 1 >= 0 && dp[x - 1].first >= dp[x].first + 1) {
            if (dp[x - 1].first == dp[x].first + 1) {
                dp[x - 1].second += dp[x].second;
            }
            else {
                dp[x - 1] = { dp[x].first + 1, dp[x].second };
                q.push(x - 1);
            }
        }
        if (x + 1 <= 100000 && dp[x + 1].first >= dp[x].first + 1) {
            if (dp[x + 1].first == dp[x].first + 1) {
                dp[x + 1].second += dp[x].second;
            }
            else {
                dp[x + 1] = { dp[x].first + 1, dp[x].second };
                q.push(x + 1);
            }
        }
        if (x * 2 <= 100000 && dp[x * 2].first >= dp[x].first + 1) {
            if (dp[x * 2].first == dp[x].first + 1) {
                dp[x * 2].second += dp[x].second;
            }
            else {
                dp[x * 2] = { dp[x].first + 1, dp[x].second };
                q.push(x * 2);
            }
        }
    }

    printf("%d\n%d", dp[e].first, dp[e].second);
    return 0;
}

