#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
#include <queue>
#define max(a, b) (a) > (b) ? (a) : (b)
using namespace std;

int main() {
    //freopen("input.txt", "rt", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, time[1001], cnt[1001] = { 0 }, target;
        int dp[1001] = { 0 };
        queue<int> q;
        vector<int> v[1001];
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &time[i]);
        }
        for (int i = 0; i < k; i++) {
            int s, e;
            scanf("%d %d", &s, &e);
            v[s - 1].push_back(e - 1);
            cnt[e - 1]++;
        }
        scanf("%d", &target);
        target--;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int& next : v[x]) {
                dp[next] = max(dp[next], dp[x] + time[x]);
                if (--cnt[next] == 0) q.push(next);
            }
        }
        printf("%d\n", dp[target] + time[target]);
    }
    return 0;
}
