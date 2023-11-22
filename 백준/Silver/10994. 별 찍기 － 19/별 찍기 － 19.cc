#include<stdio.h>

char s[398][398];

void f(int n, int x, int y){
	int l = (n * 4) - 3;
	if(l == 1){
		s[x][y] = '*';
		return;
	}
	else{
		for(int i = 0; i < l; i++){
			s[x][y + i] = '*';
			s[y + i][x] = '*';
			s[x+(l-1)][y+i] = '*';
			s[x + i][y+(l-1)] = '*';
		}
		n = n-1;
        x = x+2;
        y = y+2;
        f(n, x, y);
		return;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i =0; i < (n * 4) - 3; i++){
		for(int j = 0; j < (n * 4) - 3; j++){
			s[i][j] = ' ';
		}
	}
	f(n, 0, 0);
	
	for(int i = 0; i < (4 * n) - 3; i++){
		printf("%s\n", s[i]);
	}
	
	return 0;
}
