#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <cstring>

#define max 20000+1

using namespace std;

int k, v, e;
vector<int> g[max];
int vis[max];

bool tf() {
    for (int i = 1; i <= v; i++) {
        int gs = g[i].size();
        for (int j = 0; j < gs; j++) {
            int nxt = g[i][j];
            if (vis[i] == vis[nxt]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &v, &e);

        for (int i = 0; i < e; i++) {
            int f, s;
            scanf("%d %d", &f, &s);
            g[f].push_back(s);
            g[s].push_back(f);
        }

        for (int i = 1; i <= v; i++) { 
            if (!vis[i]) {
                queue<int> q;
                int col = 1;
                vis[i] = col;
                q.push(i);
                while (!q.empty()) {
                    int n = q.front();
                    q.pop();

                    if (vis[n] == 1) {
                        col = 2;
                    }
                    else if (vis[n] == 2) {
                        col = 1;
                    }

                    int gs = g[n].size();
                    for (int i = 0; i < gs; i++) {
                        int nxt = g[n][i];
                        if (!vis[nxt]) {
                            vis[nxt] = col;
                            q.push(nxt);
                        }
                    }
                }
            } 
        }

        if (tf()) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }

        for (int i = 0; i <= v; i++) {
            g[i].clear();
        }
        memset(vis, false, sizeof(vis));
    }
    return 0;
}
