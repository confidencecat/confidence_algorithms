#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;

int n, a, ln = 0;

int main() {
	//freopen("input.txt", "rt", stdin);
	vector<int> l;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);

		int pos = lower_bound(l.begin(), l.end(), a) - l.begin();
		//printf("%d\n", pos);
		if (i == 0){
			l.push_back(a);
			ln++;
		}
		else if (pos >= ln) {
			l.push_back(a);
			ln++;
		}
		else {
			l[pos] = a;
		}
	}
	//for (int& I : l) printf("%d ", I);
	printf("%d\n", ln);
	return 0;
}