/*************************************************************************
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   FileName: 1083.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Sat 08 Feb 2020 05:30:58 PM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)
#define pb push_back
#define bg begin
#define ed end
#define ll long long

const int INF = ~0U >> 1;

//#define DEBUG 1
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
        register double tmp = 1;
        register bool sign = 0;
        x = 0;
        register char ch = gc();
        for(; !isdigit(ch); ch = gc())
            if(ch == '-') sign = 1;
        for(; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
        if(ch == '.')
            for(ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if(sign) x = -x;
    }
    inline void read(char *s) {
        register char ch = gc();
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

int n, m;
const int maxn = 1e6 + 10;
ll dat[maxn], tmp[maxn], ans[maxn];
struct node {
    int d, s, t;
}dat2[maxn];
#define rep(i, a, b) for(int i = a; i <= b; ++i)

bool judge(ll dat3[], ll dat4[], int size) {
    rep(i, 1, size) if(dat3[i] > dat4[i]) return false;
    return true;
}

int Calc(int l, int r) {
    //printf("%d %d\n", l, r);
    //ll tmp[maxn], ans[maxn];
    rep(i, 1, n) tmp[i] = 0, ans[i] = 0;
    if(l == r) {
        rep(i, 1, l) {
            tmp[dat2[i].s] += dat2[i].d;
            tmp[dat2[i].t + 1] -= dat2[i].d;
        }
        rep(i, 1, n) ans[i] = ans[i - 1] + tmp[i];
        if(judge(ans, dat, n)) return 0;
        else return l;
    }
    int mid = l + (r - l) / 2;
    rep(i, 1, mid) {
        tmp[dat2[i].s] += dat2[i].d;
        tmp[dat2[i].t + 1] -= dat2[i].d;
    }
    rep(i, 1, n) ans[i] = ans[i - 1] + tmp[i];
    if(judge(ans, dat, n)) return Calc(mid + 1, r);
    else return Calc(l, mid);
}

int main()
{
    io.read(n), io.read(m);
    rep(i, 1, n) io.read(dat[i]);
    rep(i, 1, m) io.read(dat2[i].d), io.read(dat2[i].s), io.read(dat2[i].t);
    //printf("%d\n", m);
    int res = Calc(1, m);
    if(res) io.write(-1, '\n'), io.write(res, '\n');
    else io.write(0, '\n');
    return 0;
}

