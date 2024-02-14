#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

struct info {
	double v;
	int x, y;

	info(double a, int b, int c) {
		v = a;
		x = b;
		y = c;
	}
	bool operator<(const info& Info)const {
		return v > Info.v;
	}
};

int n, d[101], cnt = 0;
double pos[2][101], ans = 0;

double f(int i, int j) {
	return pow(pos[0][i] - pos[0][j], 2) + pow(pos[1][i] - pos[1][j], 2);
}

int find(int a) {
	if (a == d[a]) return a;
	return d[a] = find(d[a]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) d[b] = a;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	
	priority_queue<info> q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		d[i + 1] = i + 1;
		scanf("%lf %lf", &pos[0][i], &pos[1][i]);
		//printf("%lf %lf\n", pos[0][i], pos[1][i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			//printf("%lf\n", f(i, j));
			q.push({ sqrt(f(i, j)), i, j });
		}
	}
	while (!q.empty() && cnt < n - 1) {
		double v = q.top().v;
		int x = q.top().x;
		int y = q.top().y;
		q.pop();
		//printf("%lf\n", v);
		if (find(x) != find(y)) {
			uni(x, y);
			ans += v;
			cnt++;
		}
	}

	printf("%0.2lf\n", ans);
	return 0;
}