#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f(int a, int b) {
	if (b == 0){
		return a;
	}
	else {
		return f(b, a % b);
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int a, b, m;
	scanf("%d %d", &a, &b);

	for (int i = 1; i <= a * b; i++) {
		if (i % a == 0 && i % b == 0) {
			m = i;
			break;
		}
	}

	printf("%d\n%d", f(a, b), m);
	return 0;
}