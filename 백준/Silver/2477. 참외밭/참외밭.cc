#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int l[8], d[8];
int main() {
	//freopen("input.txt", "rt", stdin);
	int k, rmax = 0, cmax = 0, m = 1, c = 0;
	
	scanf("%d", &k);
	for (int i = 0; i < 6; i++) {
		scanf("%d %d", &d[i], &l[i]);
		if (d[i] == 1 || d[i] == 2) {
			if (rmax < l[i]) rmax = l[i];
		}
		else if (cmax < l[i]) cmax = l[i];
	}
	for (int i = 0; i < 6; i++) {
		if (d[i] == d[(i + 2) % 6]) m *= l[(i + 1) % 6];
	}
	printf("%d", (rmax * cmax - m) * k);
	return 0;
}