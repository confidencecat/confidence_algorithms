#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;

int era[1000001], n = 0;

int main() {
	//freopen("input.txt", "rt", stdin);
	vector<int> prime;
	
	for (int i = 2; i * i <= 1000000; i++) {
		if (era[i] == 0) {
			prime.push_back(i);
			for (int j = i * i; j <= 1000000; j += i) {
				era[j] = 1;
			}
		}
	}

	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}

		for (int i = 0; i < prime.size(); i++) {
			if (prime[i] % 2 == 0 || (n - prime[i]) % 2 == 0) continue;
			if (era[n - prime[i]] == 0) {
				printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
				break;
			}
		}
	}
	return 0;
}