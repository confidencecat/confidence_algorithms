#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;

long long int a[1000005] , tree[4000005];
//vector<long long int> tree;

long long int segment_tree(int s, int e, int node) {
    if (s == e) return tree[node] = a[s];
    int mid = (s + e) / 2;
    return tree[node] = segment_tree(s, mid, node * 2) + segment_tree(mid + 1, e, node * 2 + 1);
}

long long int sum(int s, int e, int node, int l, int r) {
    if (l > e || r < s) return 0;

    if (l <= s && e <= r) return tree[node];

    int mid = (s + e) / 2;

    return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

void update(int s, int e, int node, int index, long long int dif) {
    if (index < s || index > e) return;
    tree[node] += dif;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(s, mid, node * 2, index, dif);
    update(mid + 1, e, node * 2 + 1, index, dif);
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    //tree.resize(n * 4 + 5);
    segment_tree(0, n - 1, 1);

    for (int i = 0; i < m + k; i++) {
        int tf, ct;
        long long cn;
        scanf("%d %d %lld", &tf, &ct, &cn);
        if (tf == 1) {
            long long diff = cn - a[ct - 1];
            update(0, n - 1, 1, ct - 1, diff);
            a[ct - 1] = cn;
        }
        else if (tf == 2) {
            printf("%lld\n", sum(0, n - 1, 1, ct - 1, cn - 1));
        }
    }
    
    return 0;
}
