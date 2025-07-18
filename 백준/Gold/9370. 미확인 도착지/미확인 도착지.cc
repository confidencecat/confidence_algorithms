#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <functional>
#include <queue>
#define INF 50000001
using namespace std;

typedef struct ST {
    int e, w;

    ST(int a, int b) {
        e = a;
        w = b;
    }

    bool operator<(const ST& ss)const {
        return ss.w < w;
    }
}ST;

int T;
int n, m, t;//노드 수, 간선 수, 후보 수(목적지 후보)
int s, g, h, ghd, ghx, can_x;//시작, g h 사이 간선 필수, 후보 명단
int A, B, C, d[2001], dg[2001], dh[2001];

int main() {
    //freopen("input.txt", "rt", stdin);

    for (scanf("%d", &T); T--;) {
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);
        vector<ST> v[2001];

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &A, &B, &C);
            if ((A == g && B == h) || (A == h && B == g)) ghd = C;
            v[A].push_back({ B, C });
            v[B].push_back({ A, C });
        }
        priority_queue<int, vector<int>, greater<int>> can;
        for (int i = 0; i < t; i++) {
            scanf("%d", &can_x);
            can.push(can_x);
        }

        for (int i = 1; i <= n; i++) d[i] = INF;
        d[s] = 0;
        priority_queue<ST> q;
        q.push({ s, 0 });

        while (!q.empty()) {
            int x = q.top().e;
            int w = q.top().w;
            q.pop();

            if (d[x] < w) continue;

            for (ST c : v[x]) {
                if (d[c.e] > d[x] + c.w) {
                    q.push({ c.e, d[x] + c.w });
                    d[c.e] = d[x] + c.w;
                }
            }
        }


        for (int i = 1; i <= n; i++) dg[i] = INF;
        q.push({ g, 0 });
        dg[g] = 0;
        //dg[h] = 0;

        while (!q.empty()) {
            int x = q.top().e;
            int w = q.top().w;
            q.pop();

            if (dg[x] < w) continue;

            for (ST c : v[x]) {
                if (dg[c.e] > dg[x] + c.w) {
                    q.push({ c.e, dg[x] + c.w });
                    dg[c.e] = dg[x] + c.w;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) dh[i] = INF;
        q.push({ h, 0 });
        //dh[g] = 0;
        dh[h] = 0;

        while (!q.empty()) {
            int x = q.top().e;
            int w = q.top().w;
            q.pop();

            if (dh[x] < w) continue;

            for (ST c : v[x]) {
                if (dh[c.e] > dh[x] + c.w) {
                    q.push({ c.e, dh[x] + c.w });
                    dh[c.e] = dh[x] + c.w;
                }
            }
        }

        /*for (int i = 1; i <= n; i++) printf("%2d ", d[i] == INF ? -1 : d[i]);
        printf("\n");
        for (int i = 1; i <= n; i++) printf("%2d ", dg[i] == INF ? -1 : dg[i]);
        printf("\n");
        for (int i = 1; i <= n; i++) printf("%2d ", dh[i] == INF ? -1 : dh[i]);
        printf("\n");*/

        while(!can.empty()){
            int can_x = can.top();
            can.pop();
            int sghx = d[g] + ghd + dh[can_x];
            int shgx = d[h] + ghd + dg[can_x];
            
            if (d[can_x] == min(d[g] + ghd + dh[can_x], d[h] + ghd + dg[can_x])) {
                //printf("sghx : %2d | shgx : %2d | sx : %2d |  %d\n", sghx, shgx, d[can_x], can_x);
                printf("%d", can_x);
                if (!can.empty()) printf(" ");
            }
        }

        if(T != 0) printf("\n");
        // g 또는 h로 먼저 가기
        // g 또는 h에서 목적지 후보로 가기(이때 s 지점 통과 x)
        // 최단 경로 구하고 gh통과한 길이보다 최단 경로가 긴 후보는 제외, 이후 가장 짧은 후보 선택
        // "이 도로는 목적지 후보들 중 적어도 1개로 향하는 최단 경로의 일부"


    }

    return 0;
}
