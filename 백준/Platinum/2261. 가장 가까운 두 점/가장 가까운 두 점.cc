#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Pair {
    int x, y;
};

vector<Pair> line;

bool comY(const Pair& a, const Pair& b) {
    return a.y < b.y;
}

int com (const Pair& a, const Pair& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int sqr(int A) {
    return A * A;
}

int dis(Pair a, Pair b) {
    return sqr(b.x - a.x) + sqr(b.y - a.y);
}

int min2(int a, int b) {
    return min(a, b);
}

int f(int start, int end) {
    int n = end - start + 1;
    if (n == 2) return dis(line[start], line[end]);
    if (n == 3) {
        return min({ dis(line[start], line[start + 1]), dis(line[start + 1], line[end]), dis(line[start], line[end]) });
    }

    int mid = (start + end) / 2;
    int d = min2(f(start, mid), f(mid + 1, end));

    vector<Pair> new_line;
    int lineX = (line[mid].x + line[mid + 1].x) / 2;

    for (int i = start; i <= end; i++) {
        if (sqr(line[i].x - lineX) < d) {
            new_line.push_back(line[i]);
        }
    }

    sort(new_line.begin(), new_line.end(), comY);

    int len = new_line.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len && sqr(new_line[j].y - new_line[i].y) < d; j++) {
            int dist = dis(new_line[i], new_line[j]);
            if (dist < d) d = dist;
        }
    }

    return d;
}

int main() {
    //freopen("input.txt", "rt", stdin);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        line.push_back({ x, y });
    }

    sort(line.begin(), line.end(), com);
    printf("%d\n", f(0, n - 1));

    return 0;
}
