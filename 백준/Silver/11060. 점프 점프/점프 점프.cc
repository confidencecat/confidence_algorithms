#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<queue>
using namespace std;

int a[1001], ans_arr[1001];

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, ans = -1;
    queue<int> q;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        int d = a[x];
        q.pop();
        
        if (x == n - 1) {
            ans = ans_arr[x];
            break;
        }

        for (int i = 1; i <= d; i++) {
            if ((ans_arr[x + i] != 0 && ans_arr[x + i] <= ans_arr[x] + 1) || x + i >= n || a[x + i] == 0) continue;
            q.push(x + i);
            ans_arr[x + i] = ans_arr[x] + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
