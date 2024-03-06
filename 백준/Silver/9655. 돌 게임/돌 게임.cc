#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	if ((n - 1) % 4 == 0 || (n - 3) % 4 == 0) printf("SK\n");
	else printf("CY\n");
	return 0;
}