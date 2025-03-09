#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int n, l[11], ans = 1000, ch[10];
char s[11][11];

void f(char fs[], int ln, int c = 0) {
    if (c == n) {
        ans = ans > ln ? ln : ans;
        //printf("end %s %d\n", fs, ln);
    }
    else {
        //printf("%s %d %d\n", fs, ln, c);        
        for (int i = 0; i < n; i++) {
            if (ch[i] == 0) {
                int nln = 0, k, mx = 0;
                for (k = 1; k <= (ln < l[i] ? ln : l[i]); k++) {
                    bool tf = true;
                    for (int j = 0; j < k; j++) {
                        if (fs[ln - k + j] != s[i][j]) {
                            tf = false;
                            break;
                        }
                    }
                    if (tf) {
                        mx = k > mx ? k : mx;
                    }
                }

                char nes[103];
                for (nln = 0; nln < ln; nln++) nes[nln] = fs[nln];

                //printf("+%s\n", nes);
                k = mx;
                //printf("k : %d\n", k);
                for (int j = k; j < l[i]; j++) {
                    //printf("%d %c\n", nln, s[i][j]);
                    nes[nln++] = s[i][j];
                }
                nes[nln] = '\0';

                


                ch[i] = 1;

                /*printf("%s %d {", nes, c);
                for (int i = 0; i < n; i++) printf(" %d", ch[i]);
                printf("}\n");*/

                f(nes, nln, c + 1);
                ch[i] = 0;
            }
        }
    }
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        l[i] = strlen(s[i]);
    }
    for (int i = 0; i < n; i++) {
        ch[i] = 1;
        //printf(">>>>%d\n", i);
        f(s[i], l[i], 1);
        //printf("<<<<%d\n\n\n", i);
        ch[i] = 0;
    }
    printf("%d\n", ans);
    
    return 0;
}
