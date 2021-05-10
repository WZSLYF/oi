/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 10204_1.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年05月09日 星期日 10时45分43秒
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

//const int Maxn = 2e9 + 10;
const int maxn = 5e4;
int prim[maxn], tot, a0, a1, b0, b1, n;
bool v[maxn];

void getPrime() {
    tot = 0;
    memset(v, false, sizeof(v));
    for(int i = 2; i < maxn; ++i) {
        if(!v[i]) {
            prim[++tot] = i;
        }
        for(int j = 1; j <= tot && i * prim[j] < maxn; ++j) {
            v[i * prim[j]] = true;
            if(i % prim[j] == 0) break;
        }
    }    
}

inline int getres(int p) {
    int ma0, ma1, mb0, mb1;
    ma0 = ma1 = mb0 = mb1 = 0;
    int res = 0;
    while(a0 % p == 0) { ma0++; a0 /= p; }
    while(a1 % p == 0) { ma1++; a1 /= p; }
    while(b0 % p == 0) { mb0++; b0 /= p; }
    while(b1 % p == 0) { mb1++; b1 /= p; }
    if(ma0 > ma1 && mb0 < mb1 && ma1 == mb1) res = 1;
    if(ma0 > ma1 && mb0 == mb1 && ma1 <= mb1) res = 1;
    if(ma0 == ma1 && mb0 < mb1 && ma1 <= mb1) res = 1;
    if(ma0 == ma1 && mb0 == mb1 && ma1 <= mb1) res = mb1 - ma1 + 1;
    return res;
}

int main() {
    io.read(n);
    getPrime();
    while(n--) {
        io.read(a0), io.read(a1), io.read(b0), io.read(b1);
        int ans = 1;
        for(int i = 1; i <= tot; ++i) {
            if(b1 % prim[i] == 0) ans *= getres(prim[i]);
        }
        if(b1 > 1) ans *= getres(b1);
        io.write(ans, '\n');
    }
    return 0;
}

