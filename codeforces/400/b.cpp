/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: b.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年05月29日 星期日 11时03分07秒
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

#if __cplusplus >= 201703L
    #define REGISTER 
    #define null  nullptr
#elif __cplusplus >= 201103L
    #define REGISTER register
    #define null  nullptr
#elif __cplusplus >= 199711L
    #define REGISTER register
    #define null  NULL
#endif

/* #pragma GCC target("avx2") */
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC optimize("unroll-loops") */
#define likely(x) __builtin_expect(x, 1)
#define unlikely(x) __builtin_expect(x, 0)
#define All(x) x.begin(), x.end()
#define Rep(x, a, b) for(REGISTER int x = a; x <= b; ++x)
#define Resp(x, a, b) for(REGISTER int x = a; x >= b; --x)
#define rep(x, a, b) for(REGISTER int x = a; x < b; ++x)
#define resp(x, a, b) for(REGISTER int x = a; x > b; --x)
using LL = long long;
using pr = std::pair<int, int>;
template<typename T>
using vc = std::vector<T>;
template<typename T>
using vv = vc<vc<T>>;
constexpr int INF = INT_MAX;

struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#ifdef DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif

    inline char gc() {
#ifdef DEBUG
        return getchar();
#endif
        if(p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }

    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }

    template <class T>
    inline void read(T &x) {
        REGISTER double tmp = 1;
        REGISTER bool sign = false;
        x = 0;
        REGISTER char ch = gc();
        for(; !isdigit(ch); ch = gc()) if(ch == '-') sign = true;
        for(; isdigit(ch); ch = gc()) x = (x << 1) + (x << 3) + (ch & 15);
        if(ch == '.') for(ch = gc(); isdigit(ch); ch = gc()) tmp /= 10.0, x += tmp * (ch & 15);
        if(sign) x = -x;
    }

    inline void read(char *s) {
        REGISTER char ch = gc();
        for(; blank(ch); ch = gc());
        for(; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }

    inline void read(char &c) {
        for(c = gc(); blank(c); c = gc());
    }

    template <typename T>
    inline void processRead(T &&arg) {
        read(std::forward<T>(arg));
    }

    template <typename T, typename ... Ts>
    inline void read(T&& arg, Ts&& ... args) {
        processRead(std::forward<T>(arg));
        read(std::forward<Ts>(args) ...); 
    }

    inline void push(const char &c) {
#ifdef DEBUG
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
        }while(x);
        while(top) push(sta[--top] + '0');
    }

    inline void write(char *str) {
        char *tmp = str;
        while(*tmp) push(*tmp++);
    }

    template <class T>
    inline void write(T x, char lastChar) {
        write(x), push(lastChar);
    }

}io;

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    std::cout.tie(null);
#endif
    int n;
    io.read(n);
    if (n == 1 || n == 2) {
        io.write(1, '\n');
        Rep(i, 2, n + 1) io.write(1, ' ');
        io.push('\n');
    }
    else {
        vc<bool> prim(n + 10, false);
        Rep(i, 2, n + 1) {
            if (prim[i]) continue;
            for (LL j = 1LL * i * i; j <= n + 1; j += i) prim[j] = true;
        }
        io.write(2, '\n');
        Rep(i, 2, n + 1) {
            io.write(prim[i] ? 1 : 2, ' ');
        }
        io.push('\n');
    }
    return 0;
}

