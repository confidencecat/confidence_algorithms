#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define min(a, b) ((a) > (b) ? (b) : (a))

int a, b, n;
long long int ans = 0;
vector<vector<int>> arr(100001);

int main() {
    // freopen("input.txt", "rt", stdin);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        arr[b].push_back(a);
    }
    for (int i = 1; i <= 100000; i++) {
        if (arr[i].size() > 1) {
            sort(arr[i].begin(), arr[i].end());
            ans += arr[i][1] - arr[i][0];
            for (int j = 1; j < arr[i].size() - 1; j++) {
                int f = arr[i][j] - arr[i][j - 1];
                int s = arr[i][j + 1] - arr[i][j];
                ans += min(f, s);
            }
            ans += arr[i][arr[i].size() - 1] - arr[i][arr[i].size() - 2];
        }
    }
    printf("%lld\n", ans);
    return 0;
}

