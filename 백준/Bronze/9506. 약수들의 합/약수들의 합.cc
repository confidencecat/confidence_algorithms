#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;


int n, c, sum = 0;
queue<int> q;

int main() {
    
    while (1) {
        scanf("%d", &n);
        if (n == -1) break;

        for (c = 1; c < n; c++) {
            if (n % c == 0) {
                q.push(c);
                sum += c;
            }
        }

        if (sum == n) {
            printf("%d =", n);
            while(!q.empty()){
                printf(" %d", q.front());
                q.pop();
                if (!q.empty()) printf(" +");
            }
            printf("\n");
        }
        else {
            printf("%d is NOT perfect.\n", n);
            while (!q.empty()) q.pop();
        }
        sum = 0;
    }


    return 0;
}
