#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static const int cost[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

bool is_smaller(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main() {
    const int MAXN = 100;
    vector<string> dp_min(MAXN + 1, "");

    for (int i = 2; i <= MAXN; i++) {
        string best = "";
        for (int d = 0; d <= 9; d++) {
            int cst = cost[d];
            if (cst > i) continue;

            if (cst == i) {
                if (d == 0) continue;
                string cand(1, char('0' + d));
                if (best.empty() || is_smaller(cand, best))
                    best = cand;
            }
            else {
                int rem = i - cst;
                if (dp_min[rem].empty()) continue;
                const string &base = dp_min[rem];

                {
                    string candA = base + char('0' + d);
                    if (best.empty() || is_smaller(candA, best))
                        best = candA;
                }

                if (d != 0) {
                    string candB = string(1, char('0' + d)) + base;
                    if (best.empty() || is_smaller(candB, best))
                        best = candB;
                }
            }
        }
        dp_min[i] = best;
    }

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        const string &min_num = dp_min[n];

        string max_num;
        if (n % 2 == 1) {
            max_num.push_back('7');
            int cnt1 = (n - 3) / 2;
            for (int i = 0; i < cnt1; i++)
                max_num.push_back('1');
        } else {
            int cnt1 = n / 2;
            for (int i = 0; i < cnt1; i++)
                max_num.push_back('1');
        }

        printf("%s %s\n", min_num.c_str(), max_num.c_str());
    }
    return 0;
}
