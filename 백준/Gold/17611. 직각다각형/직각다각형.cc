#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define CEN 500000

typedef struct ST {
    int x, y;
}ST;

int n, y_min = 1000003, y_max = -1, x_min = 1000003, x_max = -1;
int dp_y[1000003], dp_x[1000003], y_ans = -1, x_ans = -1;

ST a[100003], last;

int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);

        a[i].y += CEN;
        a[i].x += CEN;

        y_min = min(y_min, a[i].y);
        y_max = max(y_max, a[i].y);
        x_min = min(x_min, a[i].x);
        x_max = max(x_max, a[i].x);


        if (i != 0 && last.y != a[i].y) {
            dp_y[min(last.y, a[i].y) + 1] += 1;
            dp_y[max(last.y, a[i].y) + 1] -= 1;
        }
        if (i != 0 && last.x != a[i].x) {
            //printf("%d->%d\n", min(last.x, a[i].x), max(last.x, a[i].x));
            dp_x[min(last.x, a[i].x) + 1] += 1;
            dp_x[max(last.x, a[i].x) + 1] -= 1;
        }

        last = a[i];
    }

    
    if (a[n - 1].x == a[0].x) {
        dp_y[min(last.y, a[0].y) + 1] += 1;
        dp_y[max(last.y, a[0].y) + 1] -= 1;
        
    }
    if (a[n - 1].y == a[0].y) {
        dp_x[min(last.x, a[0].x) + 1] += 1;
        dp_x[max(last.x, a[0].x) + 1] -= 1;
    }


    for (int i = y_min + 1; i <= y_max; i++) {
        dp_y[i] += dp_y[i - 1];
        y_ans = max(dp_y[i], y_ans);
    }
    for (int i = x_min + 1; i <= x_max; i++) {
        dp_x[i] += dp_x[i - 1];
        x_ans = max(dp_x[i], x_ans);
    }

    //printf("mi : %d\n mx : %d\n", y_min, y_max);
    //for (int i = y_max; i >= y_min; i--) {
    //    printf("%d\n", dp_y[i]);
    //}
    //printf("\n");
    //printf("mi : %d\n mx : %d\n", x_min, x_max);
    //for (int i = x_max + 1; i >= x_min - 1; i--) {
    //    printf("%d\n", dp_x[i]);
    //}

    printf("%d", max(x_ans, y_ans));




    return 0;
}