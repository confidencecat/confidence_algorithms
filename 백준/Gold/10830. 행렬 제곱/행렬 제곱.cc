#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#define V vector<vector<int>>
using namespace std;

int n;

V multiplication(V a, V b) {
    V ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
            ans[i][j] %= 1000;
        }
    }
    return ans;
}

V solve(V matrix, long long int t) {
    V ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) ans[i][i] = 1;

    while (t > 0) {
        if (t % 2 == 1) {
            t -= 1;
            ans = multiplication(ans, matrix);
        }
        else {
            t /= 2;
            matrix = multiplication(matrix, matrix);
        }

        
    }
    return ans;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    long long int t;
    
    scanf("%d %lld", &n, &t);
    V matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int element;
            scanf("%d ", &element);
            matrix[i][j] = (element % 1000);
        }
    }

    
    V print = solve(matrix, t);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", print[i][j]);
        }
        printf("\n");
    }
    return 0;
}