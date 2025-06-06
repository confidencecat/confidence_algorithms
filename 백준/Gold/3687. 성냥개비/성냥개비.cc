#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 성냥개비 개수에 따른 각 숫자(0~9) 비용 (성냥개비 개수)
static const int cost[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

// 숫자 문자열 a와 b를 “정수값 기준으로” 비교해서,
// a가 더 작으면 true, 그렇지 않으면 false를 반환
bool is_smaller(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main() {
    // 최대 n은 100
    const int MAXN = 100;
    // dp_min[i] := i개의 성냥개비로 만들 수 있는 "가장 작은 수" (문자열)
    vector<string> dp_min(MAXN + 1, "");

    // dp_min[0], dp_min[1]는 사용하지 않는다. (i=2부터 유효)
    // i=2부터 MAXN까지 순차적으로 채워 나간다.
    for (int i = 2; i <= MAXN; i++) {
        string best = "";
        // 각 숫자 d(0~9)를 마지막(또는 첫) 자리로 써볼 수 있는지 확인
        for (int d = 0; d <= 9; d++) {
            int cst = cost[d];
            if (cst > i) continue;

            // (1) i == cst인 경우: 오로지 한 글자인 숫자 d 하나로 만들 수 있다.
            if (cst == i) {
                if (d == 0) continue;         // "0" 단독은 양수가 아니므로 제외
                string cand(1, char('0' + d));
                if (best.empty() || is_smaller(cand, best))
                    best = cand;
            }
            // (2) cst < i인 경우: 나머지(i - cst)개의 성냥개비로 만든 최소 문자열이 있어야 한다.
            else {
                int rem = i - cst;
                if (dp_min[rem].empty()) continue;
                const string &base = dp_min[rem];

                // ── (2-1) "append" 방식: base + d (d를 맨 오른쪽, 최하위 자리로 추가)
                {
                    // base는 절대로 선행 '0'이 없도록 유지되므로, append는 안전
                    string candA = base + char('0' + d);
                    if (best.empty() || is_smaller(candA, best))
                        best = candA;
                }

                // ── (2-2) "prepend" 방식: d + base (d를 맨 왼쪽, 최상위 자리로 추가)
                //    d가 '0'이면 맨 앞에 0이 오면 안 되므로 건너뛴다.
                if (d != 0) {
                    string candB = string(1, char('0' + d)) + base;
                    if (best.empty() || is_smaller(candB, best))
                        best = candB;
                }
            }
        }
        dp_min[i] = best;
    }

    // 테스트 케이스 처리
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        // ── 가장 작은 수: dp_min[n]에 미리 계산해 두었음
        const string &min_num = dp_min[n];
        // ── 가장 큰 수: (c가 홀수면 '7'을 하나 쓰고 나머지를 '1'로 채운다)
        //    (c가 짝수면 전부 '1'로 채움)
        string max_num;
        if (n % 2 == 1) {
            // '7' 하나 쓰면 3개 소모 → 남는 건 (n-3)개
            max_num.push_back('7');
            int cnt1 = (n - 3) / 2;
            for (int i = 0; i < cnt1; i++)
                max_num.push_back('1');
        } else {
            int cnt1 = n / 2;
            for (int i = 0; i < cnt1; i++)
                max_num.push_back('1');
        }

        // 출력: "가장 작은 수" + 공백 + "가장 큰 수"
        printf("%s %s\n", min_num.c_str(), max_num.c_str());
    }
    return 0;
}
