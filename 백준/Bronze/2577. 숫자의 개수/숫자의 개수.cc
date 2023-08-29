#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a, b, c, arr[10],num;
int main() {
	scanf("%d %d %d", &a, &b, &c);
	num = a * b * c;
	for (int i = num; i > 0; i /= 10)
		arr[i % 10]++;
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);

	return 0;
}