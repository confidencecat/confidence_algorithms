#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
}q;

int compare(const void* first, const void* second) {
	q* a = (q*)first;
	q* b = (q*)second;

	if (a->x < b->x)
		return -1;
	else if (a->x > b->x)
		return 1;
	else {
		if (a->y < b->y)
			return -1;
		else
			return 1;
	}
	return 0;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	q* a = (q*)malloc(sizeof(q) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	qsort(a, n, sizeof(a), compare);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}
	return 0;
}