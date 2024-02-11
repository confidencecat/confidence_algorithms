#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int wid[9][10], len[9][10], square[9][10];
char map[9][9];
bool end = false;

void f(int x, int y) {
	if (end) return;
	if (x == 0 && y == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		end = true;
	}
	else if (map[y][x] != '0') {
		f(x < 8 ? x + 1 : 0, x < 8 ? y : (y + 1));
	}
	else {
		for (int i = 1; i < 10; i++) {
			if (wid[y][i] == 0 && len[x][i] == 0 && square[x / 3 + y / 3 + (y / 3) * 2][i] == 0) {
				map[y][x] = (char)(i + 48);
				wid[y][i] = 1;
				len[x][i] = 1;
				square[(y / 3) * 3 + (x / 3)][i] = 1;
				f(x < 8 ? x + 1 : 0, x < 8 ? y : (y + 1));
				map[y][x] = '0';
				wid[y][i] = 0;
				len[x][i] = 0;
				square[(y / 3) * 3 + (x / 3)][i] = 0;
			}
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 9; i++) {
		scanf("%s", map[i]);
		for (int j = 0; j < 9; j++) {
			if (map[i][j] != '0') {
				wid[i][map[i][j] - 48] = 1;
				len[j][map[i][j] - 48] = 1;
				square[i/3 + j/3 + (i/3) * 2][map[i][j] - 48] = 1;
			}
		}
	}

	f(0, 0);
	return 0;
}