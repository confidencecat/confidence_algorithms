#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int age;
	int idx;
	char name[101];
}q;

int compare(const void* first, const void* second){
	q* a = (q*)first;
	q* b = (q*)second;

	if (a->age < b->age)
		return -1;
	else if (a->age > b->age)
		return 1;
	else{
		if (a->idx < b->idx)
			return -1;
		else
			return 1;
	}
	return 0;
}

int main(){
	int i, n;
	q* a;

	scanf("%d", &n);
	a = (q*)malloc(n * sizeof(q));

	for (i = 0; i < n; i++)	{
		scanf(" %d %s", &a[i].age, a[i].name);
		a[i].idx = i;
	}

	qsort(a, n, sizeof(a[0]), compare);

	for (i = 0; i < n; i++)	{
		printf("%d %s\n", a[i].age, a[i].name);
	}

	return 0;
}