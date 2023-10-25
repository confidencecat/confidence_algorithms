#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<queue>
using namespace std;

long long int a, b, answer = -1;

typedef struct {
    long long int x, n;
}Q;

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%lld %lld", &a, &b);

    queue<Q> q;

    q.push({a, 0});

    while (!q.empty()) {
        long long int x = q.front().x;
        long long int n = q.front().n;
        q.pop();

        if (x > b) {
            continue;
        }
        if (x == b) {
            answer = n + 1;
            break;
        }

        q.push({ x * 2, n + 1 });
        q.push({ x * 10 + 1, n + 1 });
    }
    printf("%lld", answer);
    return 0;
}

