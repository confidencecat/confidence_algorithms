#include <stdio.h>
#include <string.h>

int main(){
    char S[3005];
    scanf("%s", S);
    
    int len = strlen(S);
    int pos = 0;
    for (int i = 1; ; i++){
        char buf[12];
        int bl = 0;
        int t = i;
        if (t == 0) buf[bl++] = '0';
        else {
            char tmp[12];
            int tl = 0;
            while (t > 0){
                tmp[tl++] = '0' + (t % 10);
                t /= 10;
            }
            while (tl > 0){
                buf[bl++] = tmp[--tl];
            }
        }
        for (int j = 0; j < bl && pos < len; j++){
            if (buf[j] == S[pos]) pos++;
        }
        if (pos == len){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
