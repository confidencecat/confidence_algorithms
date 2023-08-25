#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100000
char str[N];

int main(void) {
	int i, count = 0, sum = 0;
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			count++;
		}
		else if (str[i] == ')')	{
			count--;
			if (str[i - 1] != str[i])
				sum += count;
			if (str[i] == str[i + 1])
				sum += 1;
		}
	}
	printf("%d", sum);
}