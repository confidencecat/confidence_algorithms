#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int n;

vector<vector<int>> multiplication(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    vector<vector<int>> ans(n, vector<int>(n));
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

int main() {
    //freopen("input.txt", "rt", stdin);
    long long int t;
    
    scanf("%d %lld", &n, &t);
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int element;
            scanf("%d ", &element);
            matrix[i][j] = (element % 1000);
        }
    }

    vector<vector<int>> ans(n, vector<int>(n));
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}