/*************************************************************************
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   FileName: 2070.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Sat 08 Feb 2020 09:22:53 PM CST
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

int N, Num;
char ch;
const int maxn = 1e5 + 10;
struct Line {
    int l, r;
}dat[maxn];
int dat2[maxn], tot, tmp[maxn], ans[maxn];

int main()
{
    io.read(N);
    int pos = 0;
    dat2[tot++] = pos;
    Rep(i, N) {
        io.read(Num), io.read(ch);
        dat[i].l = pos;
        if('R' == ch) pos += Num; else pos -= Num;
        dat[i].r = pos;
        dat2[tot++] = pos;
    }

    sort(dat2, dat2 + tot);
    int len = unique(dat2, dat2 + tot) - dat2;
    Rep(i, N) {
        dat[i].l = lower_bound(dat2, dat2 + len, dat[i].l) - dat2;
        dat[i].r = lower_bound(dat2, dat2 + len, dat[i].r) - dat2;
        if(dat[i].l > dat[i].r) swap(dat[i].l, dat[i].r);
        tmp[dat[i].l + 1] += 1;
        tmp[dat[i].r + 1] -= 1;
    }
    ll res = 0;
    Rep(i, len) {
        if(i) ans[i] = ans[i - 1] + tmp[i]; else ans[i] = tmp[i];
        //printf("%d\n", ans[i]);
        if(ans[i] >= 2) res += dat2[i] - dat2[i - 1]; //printf("%d %d\n", dat2[i], dat2[i - 1]);
    }
    io.write(res, '\n');
    return 0;
}

