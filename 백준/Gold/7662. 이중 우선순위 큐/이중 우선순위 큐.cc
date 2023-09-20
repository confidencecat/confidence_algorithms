#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	char c;
	cin >> t;
	while (t--) {
		int n, k;
		multiset<int> ms;
		cin >> k;
		while (k--) {
			cin >> c >> n;
			if (c == 'I')
				ms.insert(n);
			else {
				if (ms.empty())
					continue;
				if (n == -1) ms.erase(ms.begin());
				else {
					auto iter = ms.end();
					ms.erase(--iter);
				}
			}
		}
		if (ms.empty()) cout << "EMPTY" << '\n';
		else {
			auto iter = ms.end();
			iter--;
			cout << *iter << ' ' << *ms.begin() << '\n';
		}
	}
	return 0;
}