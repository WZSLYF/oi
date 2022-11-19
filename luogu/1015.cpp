/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: 1015.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年05月03日 星期二 22时39分19秒
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

constexpr int maxn = 110;
struct node {
    int dat[maxn];
    int siz;
    int bin;
    node():siz(0), bin(0) {}
    node(std::string str, int _bin):siz(0), bin(_bin) {
        for (int i = 0; i < str.size(); ++i){
            dat[siz++] = (str[i] >= 'A' ? str[i] - 'A' + 10 : str[i] - '0');
        }
    }

    node(const node& b) {
        siz = b.siz;
        bin = b.bin;
        memcpy(dat, b.dat, sizeof(int) * (siz - 1));
    }

    node Reserve() {
       node res;
       res.siz = siz;
       for (int i = 0; i < siz; ++i) {
           res.dat[i] = dat[siz - i - 1];
       }
       return res;
    }

    bool ispoliland() {
        for (int i = 0; i < siz / 2; ++i) {
            if (dat[i] != dat[siz - i - 1]) return false;
        }
        return true;
    }

    node operator +(const node& b) {
        node res;
        int c = 0;
        for (int i = 0; i < siz; ++i) {
            int tmp = dat[i] + b.dat[i] + c;
            c = tmp / bin;
            tmp %= bin;
            res.dat[i] = tmp;
        }
        res.siz = siz;
        res.bin = bin;
        if (c) res.dat[res.siz++] = c;
        return res;
    }
};

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    std::cout.tie(null);
#endif
    int N;
    std::string str;
    std::cin >> N >> str;
    node dat({str, N});
    int ans = 0;
    while (!dat.ispoliland() && ++ans <= 30) {
        dat = dat + dat.Reserve();
    }
    if (ans > 30) std::cout << "Impossible!" << std::endl;
    else std::cout << "STEP=" << ans << std::endl;
    return 0;
}

