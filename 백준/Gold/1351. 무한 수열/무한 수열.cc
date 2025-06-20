#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
typedef long long int ll;
using namespace std;

typedef struct ST {
    ll i, x;

    ST(ll a, ll b) {
        i = a;
        x = b;
    }

    bool operator<(const ST& st)const {
        return st.i < i;
    }
}ST;

priority_queue<ST> pq, buff;
ll n, p, q;

ll f(ll i) {
    bool tf = false;
    ll x = 1;

    while (!pq.empty()) {
        ll qi = pq.top().i;
        ll qx = pq.top().x;
        pq.pop();

        if (qi == i) {
            tf = true;
            x = qx;
        }

        buff.push({ qi, qx });
    }
    pq = buff;
    while (!buff.empty()) buff.pop();

    //printf("\n%d\n", i);
    if (tf) {
        //printf("true\n");
        return x;
    }
    else {
        //printf("false\n");
        ll fx = f(i / p) + f(i / q);
        pq.push({ i, fx });
        return fx;
    }
}

int main() {
    
    scanf("%lld %lld %lld", &n, &p, &q);

    pq.push({ 0, 1 });
    printf("%lld\n", f(n));

    return 0;
}
