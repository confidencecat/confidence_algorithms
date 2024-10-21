#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//freopen("input.txt", "r", stdin);
	int a[3], b[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	if (a[0] == a[1]) printf("%d ", a[2]);
	else if (a[0] == a[2]) printf("%d ", a[1]);
	else printf("%d ", a[0]);

	if (b[0] == b[1]) printf("%d", b[2]);
	else if (b[0] == b[2]) printf("%d", b[1]);
	else printf("%d", b[0]);
	return 0;
}