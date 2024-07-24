#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;

bool isP(int n) {
	if (n == 1) return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void f(int num, int m) {
	if (m == n) {
		printf("%d\n", num);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (isP(num * 10 + i)) {
				f(num * 10 + i, m + 1);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n);
	n++;
	f(0, 1);

	return 0;
}
