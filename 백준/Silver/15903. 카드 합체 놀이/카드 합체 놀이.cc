#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;
typedef long long int ll;

int n, m;
ll a, sum = 0;

int main() {
	//freopen("input.txt", "rt", stdin);
	priority_queue<ll> q;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &a);
		q.push(-a);
		sum += a;
	}
	

	for (int i = 0; i < m; i++) {
		ll x = -q.top(); q.pop();
		ll y = -q.top(); q.pop();;
		sum -= x + y;

		q.push(-(x + y)); q.push(-(x + y));
		sum += (x + y)*2;
	}

	printf("%lld\n", sum);

	return 0;
}