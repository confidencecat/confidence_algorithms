#include<stdio.h>

int n, a[1001], d[1001], m = 1;

int main(){
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	d[0] = 1;
	for(int  i = 1; i< n; i++){
		for(int j = i - 1; j>=0; j--){
			if(a[i] < a[j]){
				d[i] = d[j] + 1 > d[i] ? d[j] + 1 : d[i];
			}
		}
		if(d[i] == 0) d[i] = 1;
		if(d[i] > m) m = d[i];
	}
	printf("%d\n", m);
	return 0;
}