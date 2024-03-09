#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;

int n, ln = 0, ch[1000001];
long long int a[1000001], l[1000001];
vector<long long int> v;

int lower_bound( int key) {
	int start = 0, end = ln - 1;
	int ans = ln - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (l[mid] > key) {
			end = mid - 1;
			ans = mid;
		}
		else if (l[mid] < key) {
			start = mid + 1;
		}
		else {
			ans = mid;
			break;
		}
	}
	return ans;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);

		if (ln == 0) {
			l[ln++] = a[i];
			ch[0] = 0;
		}
		else if (l[ln - 1] < a[i]) {
			ch[i] = ln;
			l[ln++] = a[i];
			
		}
		else {
			int pos = lower_bound(a[i]);
			l[pos] = a[i];
			ch[i] = pos;
		}
	}
	printf("%d\n", ln);
	int cnt = ln - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (ch[i] == cnt) {
			cnt--;
			v.push_back(a[i]);
		}
	}
	while (!v.empty()) {
		printf("%lld ", v.back());
		v.pop_back();
	}
	return 0;
}