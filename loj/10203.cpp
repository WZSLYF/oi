/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 10203.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Wed 28 Apr 2021 10:21:02 PM CST
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

const int dat[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
ll n, ans, cnt;

void dfs(int ind, int num, int size, int tot) {
    if(ind == 10) return;
    ll tmp = 1;
    for(int i = 1; i <= size; ++i) {
        tmp *= dat[ind];
        if(num * tmp > n) return;
        if(tot * (i + 1) == cnt && num * tmp < ans) ans = num * tmp;
        if(tot * (i + 1) > cnt) { cnt = tot * (i + 1); ans = num * tmp; }
        dfs(ind + 1, num * tmp, i, tot * (i + 1));
    }
}

int main() {
    io.read(n);
    ans = INF;
    dfs(0, 1, 30, 1);
    io.write(ans, '\n');
    return 0;
}

