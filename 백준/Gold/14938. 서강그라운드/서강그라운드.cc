#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<vector>
#include<queue>
#define INF 2100000000
using namespace std;

//item 비교 없이 value를 통해서 갈 수 있는 곳에 표시를 하고 후에 더하는 방식
//혹은 거리 대신 item을 기준으로 하는 다익스트라 구현 X

struct Q {
    int x, value;
    Q(int qx, int qv) {
        x = qx;
        value = qv;
    }

    bool operator < (const Q& w) const {
        return value < w.value;
    }
};

int n, m, r;//지역 수, 수색 범위, 도로 수
int item[101];
int dist[101];
vector<pair<int, int>> atobvalue[101];

int f(int s) {
    priority_queue<Q> q;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    q.push({ s, 0 });
    dist[s] = 0;

    while (!q.empty()) {
        int q_x = q.top().x;
        int q_value = q.top().value;
        q.pop();

        int xn = atobvalue[q_x].size();

        for (int i = 0; i < xn; i++) {
            int ex = atobvalue[q_x][i].first;
            int evalue = atobvalue[q_x][i].second + q_value;

            if (evalue < dist[ex]) {
                dist[ex] = evalue;
                q.push({ex, evalue });
            }//조건 추가 evalue > m
        }
    }
    for (int i = 1; i <= n; i++) {
        max += dist[i] <= m ? item[i] : 0;
    }
    return max;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int answer = 0;

    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++) scanf("%d", &item[i]);
    for (int i = 0; i < r; i++) {
        int vs, ve, vv;
        scanf("%d %d %d", &vs, &ve, &vv);
        atobvalue[vs].push_back({ ve, vv });
        atobvalue[ve].push_back({ vs, vv });
    }

    for (int i = 1; i <= n; i++) {
        int f_ans = f(i);
        if (f_ans > answer) answer = f_ans;
    }

    printf("%d\n", answer);
    return 0;
}