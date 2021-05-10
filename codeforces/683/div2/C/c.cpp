/*************************************************************************
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   FileName: c.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Mon 16 Nov 2020 08:10:53 PM CST
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

const int maxn = 2e5 + 10;
struct node {
    int val;
    int ind;
    node() {}
    node(int _val, int _ind):val(_val), ind(_ind) {}

    bool operator < (const node& b) const {
        return val < b.val;
    }
}dat[maxn];
int t, n;
ll W1, W;

int main() {
    io.read(t);
    while(t--) {
        io.read(n), io.read(W);
        W1 = (W + 1) / 2;
        Rep(i, n) {
            io.read(dat[i].val);
            dat[i].ind = i;
        }

        sort(dat, dat + n);
        
        ll tot = 0;
        bool isExit = false;
        Rep(i, n) if(W1 <= dat[i].val && dat[i].val <= W) {
            isExit = true;
            io.write(1, '\n');
            io.write(dat[i].ind + 1, '\n');
            break;
        }
        if(isExit) continue;
        Rep(i, n) {
            tot += dat[i].val;
            if(tot > W) break;
            if(W1 <= tot && tot <= W) {
                isExit = true;
                io.write(i + 1, '\n');
                Rep(j, i + 1) {
                    if(j == i) io.write(dat[j].ind + 1, '\n');
                    else io.write(dat[j].ind + 1, ' ');
                }
                break;
            }
        }
        if(!isExit) io.write(-1, '\n');
    }
    return 0;
}

