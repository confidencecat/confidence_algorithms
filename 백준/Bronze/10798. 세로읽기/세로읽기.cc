#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	char s[6][16];
	for (int i = 0; i < 5; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < strlen(s[j])) {
				printf("%c", s[j][i]);
			}
		}
	}
	return 0;
}