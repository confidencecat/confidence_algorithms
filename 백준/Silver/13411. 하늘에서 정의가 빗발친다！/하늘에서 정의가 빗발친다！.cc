#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

struct Q {
	double t;
	int n;

	Q(double a, int b) {
		t = a;
		n = b;
	}

	bool operator<(const Q& qq)const {
		if (t == qq.t) return n > qq.n;
		else return t > qq.t;
	}

};

int main() {
	//freopen("input.txt", "rt", stdin);

	int n;
	scanf("%d", &n);
	priority_queue<Q> q;


	for (int i = 0; i < n; i++) {
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		double d = sqrt(pow(x, 2) + pow(y, 2));
		//printf("%f\n", d);
		q.push({d / (double)v, i + 1});
	}

	while (!q.empty()) {
		printf("%d\n", q.top().n);
		q.pop();
	}
	return 0;
}