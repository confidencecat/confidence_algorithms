//수 묶기
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int answer = 0, n, m, an = 0, bn = 0, on = 0, zn = 0;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * n);
	int* b = (int*)malloc(sizeof(int) * n);
	int* o = (int*)malloc(sizeof(int) * n);


	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) o[on++] = t;
		else if (t > 0) a[an++] = t;
		else if (t < 0) b[bn++] = t;
		else zn++;
	}
	qsort(a, an, sizeof(int), compare);
	qsort(b, bn, sizeof(int), compare);
	qsort(o, on, sizeof(int), compare);
	for (int i = 0; i < on; i++) answer += o[i];

	if (an % 2 == 0) {
		for (int i = 0; i < an - 1; i += 2) answer += a[i] * a[i + 1];
	}
	else {
		for (int i = 1; i < an - 1; i+=2) answer += a[i] * a[i + 1];
		answer += a[0];
	}

	if (bn % 2 == 0) {
		for (int i = 0; i < bn - 1; i += 2)	answer += b[i] * b[i + 1];
	}
	else {
		for (int i = 0; i < bn - 2; i += 2) answer += b[i] * b[i + 1];
		if (zn == 0) answer += b[bn - 1];
	}

	printf("%d", answer);
	return 0;
}