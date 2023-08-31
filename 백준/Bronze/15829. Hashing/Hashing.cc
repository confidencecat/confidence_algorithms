#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, i;
	long long a = 0, b = 1;
	char s[51];

	scanf("%d %s", &n, s);

	for (i = 0; i < n; i++)
	{
		a = (a + (s[i] - 97 + 1) * b) % 1234567891;
		b = (b * 31) % 1234567891;
	}
	printf("%lld\n", a);

	return 0;
}