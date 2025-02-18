#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, k;
int a[101];

int con[101], ans = 0;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < k; i++) {
        bool tf = false;
        for (int j = 0; j < n; j++) {
            if (con[j] == a[i]) {
                tf = true;
                break;
            }
        }
        if (tf) continue;

        tf = false;
        for (int j = 0; j < n; j++) {
            if (con[j] == 0) {
                con[j] = a[i];
                tf = true;
                break;
            }
        }
        if (tf) continue;

        /*printf("a[%d] = %d\n", i, a[i]);
        for (int j = 0; j < n; j++) printf("%d ", con[j]);
        printf("\n");*/

        int mx = 0, mxi = 0;
        for (int j = 0; j < n; j++) {
            tf = false;
            //printf("===con[j] : %d===\n", con[j]);
            for (int l = i; l < k; l++) {
                //printf("%d : %d\n", l, a[l]);
                if (con[j] == a[l]) {
                    if (l > mx) {
                        mx = l;
                        mxi = j;
                    }

                    tf = true;
                    break;
                }
            }
            if (!tf) {
                //printf("%d가 뒤에 없음\n", con[j]);
                mxi = j;
                break;
            }
            
        }
        //printf("\n\n");

        con[mxi] = a[i];
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
