#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define REG 4
using namespace std;

typedef struct N {
    int n;
    string r;
}Q;

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int A, B;  cin >> A >> B;
        int e = 0;
        queue<N> q;
        vector<int> v(10000, 0);
        q.push({ A, "" });
        while (q.size() && e == 0) {
            N c = q.front();  q.pop();

            if (v[c.n]) continue;
            v[c.n] = 1;

            if (c.n == B) {
                cout << c.r << "\n";
                break;
            }

            int j1, j2;

            for (int i = 0; i < REG; i++) {
                N n = { 0, c.r };
                switch (i) {
                case 0:
                    n.n = (c.n * 2) % 10000;
                    n.r += "D";
                    break;
                case 1:
                    n.n = (c.n == 0 ? 9999 : c.n - 1);
                    n.r += "S";
                    break;
                case 2:
                    j1 = c.n / 1000;
                    n.n = (c.n % 1000) * 10 + j1;
                    n.r += "L";
                    break;
                case 3:
                    j2 = c.n % 10;
                    n.n = (c.n / 10) % 1000 + j2 * 1000;
                    n.r += "R";
                    break;
                }

                if (!v[n.n]) {
                    if (n.n == B) {
                        cout << n.r << "\n";
                        e = 1;
                        break;
                    }
                    q.push(n);
                }
            }
        }
    }
    return 0;
}
