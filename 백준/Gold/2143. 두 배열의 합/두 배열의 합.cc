#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[1002], b[1002];
vector<int> A, B;

int main() {
    //freopen("input.txt", "rt", stdin);
    int t, n, m;
    long long int ans = 0;
    
    scanf("%d", &t);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            A.push_back(a[j] - a[i - 1]);
        }
    }

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            B.push_back(b[j] - b[i - 1]);
        }
    }

    //sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++) {
        //if (A[i] >= t) break;
        int x = t - A[i];
        
        int first = lower_bound(B.begin(), B.end(), x) - B.begin();
        int second = upper_bound(B.begin(), B.end(), x) - B.begin();
        ans += second - first;

    }
    printf("%lld\n", ans);
    return 0;
}