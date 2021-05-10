/*************************************************************************
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3865.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Sat 08 Feb 2020 10:11:58 PM CST
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

int N, M;
const int maxn = 1e5 + 10;
int dp[maxn][20], preLog[maxn];

void Pre() {
    preLog[1] = 0;
    rep(i, 2, N) {
        preLog[i] = preLog[i - 1];
        if((1 << preLog[i] + 1) == i) ++preLog[i];
    }
}

int main()
{
    io.read(N), io.read(M);
    rep(i, 1, N) io.read(dp[i][0]); // printf("%d\n", dp[i][0]);
    Pre();
    rep(j, 1, 19) for(int i = 1; i + (1 << j) - 1 <= N; ++i) dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]); //printf("%d\n", dp[i][j]);
    Rep(i, M) {
        int l, r;
        io.read(l), io.read(r);
        int k = preLog[r - l + 1];
        //printf("%d %d %d\n", k, dp[l][k], dp[r - (1 << k) + 1][k]);
        io.write(max(dp[l][k], dp[r - (1 << k) + 1][k]), '\n');
    }
    return 0;
}

