#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <utility>
using namespace std;

int n, k, dp[100001];
pair<int, int> a[101];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }

    for (int i = 0; i < n; i++) {
        for (int j = k; j > 0; j--) {
            if (j >= a[i].first) {
                if (dp[j] < dp[j - a[i].first] + a[i].second) dp[j] = dp[j - a[i].first] + a[i].second;
            }
        }
    }

    printf("%d", dp[k]);
    return 0;
}