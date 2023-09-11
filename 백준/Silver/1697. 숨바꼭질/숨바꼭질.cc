#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<queue>
#define min(a, b) a > b ? b : a
using namespace std;

queue<pair<int, int>> q;
bool c[100001] ;

int main() {
    int s, e, ans = 0;

    scanf("%d %d", &s, &e);
    
    q.push({ s, 0 });
    c[s] = true;
    while (!q.empty()) {
        int x = q.front().first;
        ans = q.front().second;
        q.pop();

        if (x == e) {
            break;
        }
        if (c[x - 1] == false && x - 1 >= 0 && x - 1 <= 100000) {
            c[x - 1] = true;
            q.push({ x - 1, ans + 1 });
        }
        if (c[x + 1] == false && x + 1 >= 0 && x + 1 <= 100000) {
            c[x + 1] = true;
            q.push({ x + 1, ans + 1 });
        }
        if (c[x * 2] == false && x * 2 >= 0 && x * 2 <= 100000) {
            c[x * 2] = true;
            q.push({ x * 2, ans + 1 });
        }
    }
    printf("%d\n", ans);
    return 0;
}