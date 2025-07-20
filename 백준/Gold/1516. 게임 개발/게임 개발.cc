#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int n, t[501], a;
int d[501];
int ans[501], ans_n;
int time[501];

queue<int> q;
vector<int> v[501];

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        while (1) {
            scanf("%d", &a);
            if (a == -1) break;
            d[i]++;
            v[a].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q.push(i);
            ans[ans_n++] = i;
        }
    }
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int c : v[x]) {
            time[c] = max(time[c], time[x] + t[x]);
            if (--d[c] == 0) {
                q.push(c);
                ans[ans_n++] = c;
            }
        }
    }

    //for (int i = 0; i < ans_n; i++) printf("%d\n", ans[i]);
    for (int i = 1; i <= n; i++) printf("%d\n", time[i]+t[i]);

    return 0;
}