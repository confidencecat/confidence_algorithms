#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n, m, ans = 0;
int a[52][4];
char s[1001][51];
char result[51];

int nucleotide_index(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
    return -1;
}

char index_to_nucleotide(int idx) {
    if (idx == 0) return 'A';
    if (idx == 1) return 'C';
    if (idx == 2) return 'G';
    if (idx == 3) return 'T';
    return '?';
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            a[j][nucleotide_index(s[i][j])]++;
        }
    }

    for (int j = 0; j < m; j++) {
        int max_count = -1, selected_idx = 0;
        for (int k = 0; k < 4; k++) {
            if (a[j][k] > max_count) {
                max_count = a[j][k];
                selected_idx = k;
            } else if (a[j][k] == max_count && k < selected_idx) {
                selected_idx = k;
            }
        }
        result[j] = index_to_nucleotide(selected_idx);
    }
    result[m] = '\0';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != result[j]) ans++;
        }
    }

    printf("%s\n", result);
    printf("%d\n", ans);

    return 0;
}
