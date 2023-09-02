#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int num[100001];
int cnt = 0;

void psh(int n) {
	num[cnt] = n;
	cnt++;
}

void pop() {
	if (cnt != 0) {
		cnt--;
		printf("%d\n", num[cnt]);
		num[cnt] = 0;
	} else {
		printf("%d\n", -1);
	}
}

void tp() {
	if (cnt != 0)
		printf("%d\n", num[cnt - 1]);
	else
		printf("%d\n", -1);
}

void sz() {
	printf("%d\n", cnt);
}

void em() {
	if (cnt != 0)
		printf("0\n");
	else
		printf("1\n");
}

int main() {
	int n;
	char stk[10];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &stk);
		if (strcmp(stk, "push") == 0) {
			int num;
			scanf("%d", &num);
			psh(num);
		} else if (strcmp(stk, "pop") == 0) {
			pop();
		} else if (strcmp(stk, "top") == 0) {
			tp();
		} else if (strcmp(stk, "size") == 0) {
			sz();
		} else if (strcmp(stk, "empty") == 0) {
			em();
		}
	}
}
