//대회 or 인턴
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, k, answer = 0;
	scanf("%d %d %d", &n, &m, &k);
	while (k--) {
		if (n / m >= 2) {
			n -= 1;
		}
		else {
			m -= 1;
		}
	}//5 2
	while (1) {
		if (m - 1 >= 0 && n - 2 >= 0) {
			n -= 2;
			m--;
			answer++;
		}
		else {
			printf("%d", answer);
			break;
		}
	}
	return 0;
}