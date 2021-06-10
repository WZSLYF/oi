/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 5306.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月07日 星期一 21时36分55秒
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(register int i = 0; i < n; ++i)
#define rep(i, a, b) for(register int i = a; i <= b; ++i)
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

const int maxn = 1e6 + 10;
int dat[maxn];
int mx[maxn << 2], cnt[maxn << 2], semx[maxn << 2], tg[maxn << 2];
ll sum[maxn << 2];

inline void pushup(int ind) {
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    sum[ind] = sum[lefind] + sum[rigind];
    if(mx[lefind] == mx[rigind]) {
        mx[ind] = mx[lefind];
        cnt[ind] = cnt[lefind] + cnt[rigind];
        semx[ind] = max(semx[lefind], semx[rigind]);
    }
    else if(mx[lefind] > mx[rigind]) {
        mx[ind] = mx[lefind];
        cnt[ind] = cnt[lefind];
        semx[ind] = max(semx[lefind], mx[rigind]);
    }
    else if(mx[lefind] < mx[rigind]){
        mx[ind] = mx[rigind];
        cnt[ind] = cnt[rigind];
        semx[ind] = max(mx[lefind], semx[rigind]);
    }
}

inline void pushtg(int ind, int val) {
    if(mx[ind] <= val) return;
    sum[ind] += (1ll * val - mx[ind]) * cnt[ind];
    mx[ind] = tg[ind] = val;
}

inline void pushdown(int ind) {
    if(-1 == tg[ind]) return;
    pushtg(ind << 1, tg[ind]);
    pushtg((ind << 1) | 1, tg[ind]);
    tg[ind] = -1;
}

void build(int l, int r, int ind) {
    tg[ind] = -1;
    if(l == r) {
        sum[ind] = dat[l];
        mx[ind] = dat[l];
        cnt[ind] = 1;
        semx[ind] = -1;
        return;
    }

    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    build(l, mid, lefind);
    build(mid + 1, r, rigind);
    pushup(ind);
}

void change(int l, int r, int lef, int rig, int ind, int val) {
    if(mx[ind] <= val) return;
    if(lef <= l && r <= rig && semx[ind] < val) return pushtg(ind, val);
    pushdown(ind);
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    if(lef <= mid) change(l, mid, lef, rig, lefind, val);
    if(rig > mid) change(mid + 1, r, lef, rig, rigind, val);
    pushup(ind);
}

int query_max(int l, int r, int lef, int rig, int ind) {
    if(lef <= l && r <= rig) return mx[ind];
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    int mx1 = -1, mx2 = -1;
    pushdown(ind);
    if(lef <= mid) mx1 = query_max(l, mid, lef, rig, lefind);
    if(rig > mid) mx2 = query_max(mid + 1, r, lef, rig, rigind);
    return max(mx1, mx2);
}

ll query_sum(int l, int r, int lef, int rig, int ind) {
    if(lef <= l && r <= rig) return sum[ind];
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    ll ans = 0;
    pushdown(ind);
    if(lef <= mid) ans += query_sum(l, mid, lef, rig, lefind);
    if(rig > mid) ans += query_sum(mid + 1, r, lef, rig, rigind);
    return ans;
}

int main() 
{
    int t;
    io.read(t);
    while(t--) {
        int n, m;
        io.read(n), io.read(m);
        rep(i, 1, n) io.read(dat[i]);
        build(1, n, 1);
        rep(i, 1, m) {
            int opt, l, r;
            io.read(opt), io.read(l), io.read(r);
            if(0 == opt) {
                int val;
                io.read(val);
                change(1, n, l, r, 1, val);
            }
            else if(1 == opt) {
                io.write(query_max(1, n, l, r, 1), '\n');
            }
            else {
                io.write(query_sum(1, n, l, r, 1), '\n');
            }
        }
    }
    return 0;
}


