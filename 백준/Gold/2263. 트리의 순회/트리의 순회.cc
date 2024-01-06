#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int inorder[100001], postorder[100001], x[100001];

void f(int s, int e, int ps, int pe) {
    if (s <= e && ps <= pe) {
        printf("%d ", postorder[pe]);
        f(s, x[postorder[pe]] - 1, ps, ps + x[postorder[pe]] - s - 1);
        f(x[postorder[pe]] + 1, e, ps + x[postorder[pe]] - s, pe - 1);
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d ", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d ", &postorder[i]);
    for (int i = 0; i < n; i++) x[inorder[i]] = i;
    f(0, n - 1, 0, n - 1);
    return 0;
}