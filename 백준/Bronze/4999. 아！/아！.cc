#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char a[1000], b[1000];

	scanf("%s", a);
	scanf("%s", b);

	if (strlen(a) >= strlen(b)) printf("go");
	else printf("no");
	
	return 0;
}

