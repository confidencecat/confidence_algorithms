#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define abs(a) a < 0 ? - a : a

int main() {
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", abs((a - b)));
	return 0;
}