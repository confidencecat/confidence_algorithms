#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a, b, c;

long long int f(long long int y) {
	if (y == 1) return a % c;

	long long int k = f(y / 2) % c;

	if (y % 2 == 0) return k * k % c;
	else return k * k % c * a % c;
}

int main() {
    //freopen("input.txt", "rt", stdin);
	scanf("%d %d %d", &a, &b, &c);

	printf("%lld\n", f(b));

    return 0;
}
