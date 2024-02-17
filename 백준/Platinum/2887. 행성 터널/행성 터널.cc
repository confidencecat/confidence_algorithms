#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#define min(a, b, c) ((a) > (b) ? (b) > (c) ? (c) : (b) : (a) > (c) ? (c) : (a))
#define abs(a) a < 0 ? -a : a;
using namespace std;

int n, d[100001], ans = 0;

struct info {
    int v, s, e;

    info(int a, int b, int c) {
        v = a;
        s = b;
        e = c;
    }

    bool operator<(const info& I)const {
        return I.v < v;
    }
};

struct vinfo {
    int x, y, z, num;
};

int com_x(const void* a, const void* b) {
    vinfo A = *(vinfo*)a;
    vinfo B = *(vinfo*)b;
    return A.x > B.x;
}

int com_y(const void* a, const void* b) {
    vinfo A = *(vinfo*)a;
    vinfo B = *(vinfo*)b;
    return A.y > B.y;
}

int com_z(const void* a, const void* b) {
    vinfo A = *(vinfo*)a;
    vinfo B = *(vinfo*)b;
    return A.z > B.z;
}

int find(int a) {
    if (a == d[a]) return a;
    else return d[a] = find(d[a]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        d[b] = a;
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);

    vector<vinfo> v;
    for (int i = 0; i < n; i++) {
        d[i] = i;
        int xx, yy, zz;
        scanf("%d %d %d", &xx, &yy, &zz);
        v.push_back({ xx, yy, zz, i });
    }


    priority_queue<info> q;

    qsort(&v[0], n, sizeof(vinfo), com_x);
    for (int i = 0; i < n - 1; i++) {
        int x = abs((v[i + 1].x - v[i].x));
        q.push({ x, v[i].num, v[i + 1].num });
    }

    qsort(&v[0], n, sizeof(vinfo), com_y);
    for (int i = 0; i < n - 1; i++) {
        int y = abs((v[i + 1].y - v[i].y));
        q.push({ y, v[i].num, v[i + 1].num});
    }

    qsort(&v[0], n, sizeof(vinfo), com_z);
    for (int i = 0; i < n - 1; i++) {
        int z = abs((v[i + 1].z - v[i].z));
        q.push({ z, v[i].num, v[i + 1].num });
    }

    while(!q.empty()) {
        int cost = q.top().v;
        int s = q.top().s;
        int e = q.top().e;
        q.pop();
        //printf("%d %d %d\n", cost, s, e);

        if (find(s) != find(e)) {
            //printf("%d %d\n", s, e);
            uni(s, e);
            ans += cost;
        }
    }

    printf("%d\n", ans);
    return 0;
}
