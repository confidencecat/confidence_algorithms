#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#define mx(a, b) ((a) < (b) ? (b) : (a))
using namespace std;

typedef struct ST {
    int t;
    vector<vector<int>> m;
}ST;

int n, ans = 0;
vector<vector<int>> mp;
queue<ST> q;


int main() {


    scanf("%d", &n);
    mp.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    q.push({ 0, mp });

    while (!q.empty()) {
        int t = q.front().t, l, ln;
        vector<vector<int>> m;

        //오른쪽 ->
        m = q.front().m;
        for (int i = 0; i < n; i++) {
            l = -1;  ln = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (m[i][j] == 0) continue;
                if (m[i][j] != l) {
                    m[i][ln--] = m[i][j];
                    ans = mx(m[i][j], ans);
                    l = m[i][j];
                }
                else {
                    m[i][ln + 1] = l * 2;
                    ans = mx(l * 2, ans);
                    l = -1;
                }
            }
            for (int j = 0; j <= ln; j++) m[i][j] = 0;
        }
        if (t < 4) q.push({ t + 1, m });
        
        //왼쪽
        m = q.front().m;
        for (int i = 0; i < n; i++) {
            l = -1;  ln = 0;
            for (int j = 0; j < n; j++) {
                if (m[i][j] == 0) continue;
                if (m[i][j] != l) {
                    m[i][ln++] = m[i][j];
                    ans = mx(m[i][j], ans);
                    l = m[i][j];
                }
                else {
                    m[i][ln - 1] = l * 2;
                    ans = mx(l * 2, ans);
                    l = -1;
                }
            }
            for (int j = ln; j < n; j++) m[i][j] = 0;
        }
        if (t < 4) q.push({ t + 1, m });


        //위쪽
        m = q.front().m;
        for (int i = 0; i < n; i++) {
            l = -1;  ln = 0;
            for (int j = 0; j < n; j++) {
                if (m[j][i] == 0) continue;
                if (m[j][i] != l) {
                    m[ln++][i] = m[j][i];
                    ans = mx(m[j][i], ans);
                    l = m[j][i];
                }
                else {
                    m[ln - 1][i] = l * 2;
                    ans = mx(l * 2, ans);
                    l = -1;
                }
            }
            for (int j = ln; j < n; j++) m[j][i] = 0;
        }
        if (t < 4) q.push({ t + 1, m });

        //아래쪽
        m = q.front().m;
        for (int i = 0; i < n; i++) {
            l = -1;  ln = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (m[j][i] == 0) continue;
                if (m[j][i] != l) {
                    m[ln--][i] = m[j][i];
                    ans = mx(m[j][i], ans);
                    l = m[j][i];
                }
                else {
                    m[ln + 1][i] = l * 2;
                    ans = mx(l * 2, ans);
                    l = -1;
                }
            }
            for (int j = 0; j <= ln; j++) m[j][i] = 0;
        }
        if (t < 4) q.push({ t + 1, m });

        q.pop();
    }

    printf("%d\n", ans);

    return 0;
}
