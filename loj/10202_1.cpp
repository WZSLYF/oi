/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 10202_1.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Wed 28 Apr 2021 06:09:02 PM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define pb push_back
#define bg begin
#define ed end
#define ll long long

const int INF = ~0U >> 1;

struct IO {
    #define MAXSIZE (1 << 20)
    #define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
    #if DEBUG
    #else
        IO() : p1(buf), p2(buf), pp(pbuf) {}
        ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
    #endif
    inline char gc() {
        #if DEBUG
            return getchar();
        #else
            if(p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
            return p1 == p2 ? ' ' : *p1++;
        #endif
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x) {
        double tmp = 1;
        bool sign = 0;
        x = 0;
        char ch = gc();
        for(; !isdigit(ch); ch = gc())
            if(ch == '-') sign = 1;
        for(; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
        if(ch == '.')
            for(ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if(sign) x = -x;
    }
    inline void read(char *s) {
        char ch = gc();
        for(; blank(ch); ch = gc())
            ;
        for(; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }
    inline void read(char &c) {
        for(c = gc(); blank(c); c = gc())
            ;
    }
    inline void push(const char &c) {
        #if DEBUG
            putchar(c);
        #else
            if(pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
            *pp++ = c;
        #endif
    }
    template <class T>
    inline void write(T x) {
        if(x < 0) x = -x, push('-');
        static T sta[35];
        T top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while(x);
        while(top) push(sta[--top] + '0');
    }
    template <class T>
    inline void write(T x, char lastChar) {
        write(x), push(lastChar);
    } 
}io;

template<class T>
inline T Max(const T& a, const T& b) { return a > b ? a : b; }

template<class T>
inline T Min(const T& a, const T& b) { return a < b ? a : b; }

const int maxn = 1000000 + 10;
const int M = 1000000007;
int n;
bool v[maxn];

int main() {
    //io.read(n);
    scanf("%d", &n);
    //memset(v, 0, sizeof(v));
    int ans = 1;
    rep(i, 2, n) {
        if(!v[i]) {
            for(int j = 2 * i; j <= n; j += i) v[j] = true;
            int cnt = 0;
            for(int j = n / i; j; j /= i) cnt += j;
            ans = (ans * (2ll * cnt + 1)) % M;
        }
    }
    //io.write(ans, '\n');
    printf("%d\n", ans);
    return 0;
}

