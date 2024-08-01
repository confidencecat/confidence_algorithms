#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n, m, s, e;
vector<pair<int, int>> v[100001];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &e);

    for (int i = 0; i < m; i++) {
        int ss, ee, ww;
        scanf("%d %d %d", &ss, &ee, &ww);
        v[ss].push_back({ ee, ww });
        v[ee].push_back({ ss, ww });
    }

    int l = 1, r = 1000001, mid = 0, ans = 0;

    while (l <= r) {
        mid = (l + r) / 2;


        bool tf = false, ch[100001];
        for (int i = 1; i <= n; i++) {
            ch[i] = false;
        }

        queue<int> q;
        q.push(s);
        ch[s] = true;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == e) {
                ans = mid;
                tf = true;
                break;
            }

            for (auto c : v[x]) {
                int cx = c.first;
                int cd = c.second;
                
                if (mid <= cd && ch[cx] == false) {
                    q.push(cx);
                    ch[cx] = true;
                }
            }
        }


        //printf("%d -- >  %d\n", mid, tf);

        if (tf) {
            l = mid + 1;
        }
        else r = mid - 1;
    }

    printf("%d\n", ans);

    return 0;
}