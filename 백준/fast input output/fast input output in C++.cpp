#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#if defined(_WIN32) || defined(_WIN64)
#define getchar_unlocked _getchar_nolock
#endif

class FastInput {
public:
    FastInput& operator>>(int& number) {
        number = 0;
        int c = getchar_unlocked(), neg = false;
        while ((c < '0' || c > '9') && c != '-') c = getchar_unlocked();
        if (c == '-') { neg = true; c = getchar_unlocked(); }
        for (; c >= '0' && c <= '9'; c = getchar_unlocked()) number = number * 10 + c - '0';
        if (neg) number = -number;
        return *this;
    }
    FastInput& operator>>(long long& number) {
        number = 0;
        int c = getchar_unlocked(), neg = false;
        while ((c < '0' || c > '9') && c != '-') c = getchar_unlocked();
        if (c == '-') { neg = true; c = getchar_unlocked(); }
        for (; c >= '0' && c <= '9'; c = getchar_unlocked()) number = number * 10 + c - '0';
        if (neg) number = -number;
        return *this;
    }
    FastInput& operator>>(string& str) {
        str.clear();
        int c = getchar_unlocked();
        while (c <= ' ') c = getchar_unlocked();
        for (; c > ' '; c = getchar_unlocked()) str += c;
        return *this;
    }
};

class FastOutput {
public:
    FastOutput& operator<<(char ch) {
        putchar(ch); // Correctly output single characters
        return *this;
    }
    FastOutput& operator<<(int number) {
        printf("%d", number);
        return *this;
    }
    FastOutput& operator<<(long long number) {
        printf("%lld", number);
        return *this;
    }
    FastOutput& operator<<(const string& str) {
        printf("%s", str.c_str());
        return *this;
    }
    FastOutput& operator<<(ostream& (*pf)(ostream&)) {
        pf(cout); // Handle std::endl and similar
        return *this;
    }
    void flush() {
        fflush(stdout);
    }
};

FastInput fin;
FastOutput fout;

#define cin fin
#define cout fout

int main() {
    //freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    
    int a;
    long long b;
    string s;
    cin >> a >> b >> s;
    cout << a << "\n";
    cout << b << "\n";
    cout << s << "\n";

    return 0;
}

//참고 : https://blog.naver.com/jinhan814/222266396476
