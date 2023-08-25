#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int n;
int main() {
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n);
	int m = 0;
	while (n >= 0) {
		if (n % 5 == 0) {
			m += (n / 5);
			printf("%d", m);
			return 0;
		}
		n -= 3;
		m++;
	}
	printf("-1");
	return 0;
}