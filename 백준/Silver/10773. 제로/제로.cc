#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, b, ans = 0;
	stack<int> a;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &b);
		if (b == 0 && !a.empty()) {
			ans -= a.top();
			a.pop();
		}
		else {
			ans += b;
			a.push(b);
		}
	}
	printf("%d\n", ans);

	return 0;
}
