#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int n, cnt = 0, i = 666;
    scanf("%d", &n);
	while (1){
        int tmp=i;
        while(tmp>=666){
            if(tmp%1000==666){
                cnt++;
                break;
            }
            tmp/=10;
        }
        if(n==cnt){
            printf("%d", i);
            break;
        }
        i++;
    }
	return 0;
}