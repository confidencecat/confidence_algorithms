#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

typedef struct {
	int x, y;
}f;

int compare(const void* first, const void* second) {
	f* a = (f*)first;
	f* b = (f*)second;
	if (a->y > b->y) {
		return 1;
	}
	else if (a->y < b->y) {
		return -1;
	}
	else {
		if (a->x > b->x) return 1;
		else if (a->x < b->x) return -1;
		else return 0;
	}
}



int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	f* a = (f*)malloc(sizeof(f) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	qsort(a, n, sizeof(f), compare);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}
	return 0;
}
