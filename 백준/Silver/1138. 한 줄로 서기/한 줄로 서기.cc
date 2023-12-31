#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, a[11];
    vector<int> ans;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    for (int i = n; i >= 1; i--) {
        ans.insert(ans.begin() + a[i], i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
