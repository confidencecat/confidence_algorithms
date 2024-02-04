#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);

    if (n < 10) {
        printf("%d\n", n);
        return 0;
    }

    queue<long long int> q;
    for (int i = 0; i <= 9; i++) {
        q.push(i);
    }
    int count = 9;
    long long int number = 0;


    while (!q.empty() && count < n) {
        number = q.front();
        q.pop();
        int l = number % 10;
        for (int i = 0; i < l; i++) {
            q.push(number * 10 + i);
            count++;
            if (count == n) {
                printf("%lld\n", number * 10 + i);
                return 0;
            }
        }
    }

    printf("-1\n");
    return 0;
}
