#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int> q;

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if(x!=0){
            q.push(x);
        }else{
            if(q.empty()){
                printf("0\n");
            }else{
                printf("%d\n", q.top());
                q.pop();
            }
        }
    }
    return 0;
}