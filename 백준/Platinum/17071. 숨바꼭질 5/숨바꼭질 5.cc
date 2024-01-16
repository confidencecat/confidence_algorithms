#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

bool visit[2][5000001];
int s, e, ep = 1;
queue<int> q;

int f() {
    while (!q.empty()) {
        e += ep;
        if (e > 500000) return -1;

        if (visit[ep % 2][e]) return ep;
        
        int n = q.size();
        for (int i = 0; i < n; i++) {
            int x = q.front();
            q.pop();

            for (int nx : {x - 1, x + 1, x * 2}) {
                if (nx == e) return ep;
                if (nx < 0 || nx > 500000 || visit[ep % 2][nx]) continue;
                visit[ep % 2][nx] = true;
                q.push(nx);
            }
        }
        ep++;
    }
    return -1;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &s, &e);
    if (s == e) printf("0");
    else {
        q.push(s);
        printf("%d\n", f());
    }
    return 0;
}