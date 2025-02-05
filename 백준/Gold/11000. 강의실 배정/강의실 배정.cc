#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct L {
    int start, end;
}Lecture;


bool cmp(const Lecture& a, const Lecture& b) {
    if (a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}

int main() {
    int N;
    scanf("%d", &N);

    vector<Lecture> lectures(N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &lectures[i].start, &lectures[i].end);
    }

    sort(lectures.begin(), lectures.end(), cmp);

    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(lectures[0].end);

    for (int i = 1; i < N; i++) {
        if (pq.top() <= lectures[i].start) {
            pq.pop();
        }
        pq.push(lectures[i].end);
    }

    printf("%d\n", (int)pq.size());

    return 0;
}
