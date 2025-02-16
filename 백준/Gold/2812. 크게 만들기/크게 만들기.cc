#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int n, k;
char s[500003];
vector<int> v;

int main() {

	scanf("%d %d", &n, &k);
	scanf("%s", s);

	int i = 0, pt = 0;
	while (i < n) {
		if (v.empty()) {
			v.push_back(s[i++] - 48);
			//printf("e > %d\n", s[i - 1] - 48);
		}
		else if(v.back() < s[i] - 48 && pt < k) {
			v.pop_back();
			pt++;
			//printf(">pop %d\n", pt);
		}
		else{
			v.push_back(s[i++] - 48);
			
			//printf("j > %d\n", s[i - 1] - 48);
		}
	}
	for (int i = 0; i < n - k; i++) printf("%d", v[i]);

	return 0;
}