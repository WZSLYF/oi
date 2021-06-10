/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 4695.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月07日 星期一 22时53分18秒
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

//const int INF = ~0U >> 1;

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

const int maxn = 5e5 + 10;
const int INF = 0x7fffffff;
int dat[maxn];
struct node {
    int mx, semx, cntmx, mn, semn, cntmn, tmx, tmn, tad;
    ll sum;
}seg[maxn << 2];

void pushup(int ind) {
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    seg[ind].sum = seg[lefind].sum + seg[rigind].sum;

    if(seg[lefind].mx == seg[rigind].mx) {
        seg[ind].mx = seg[lefind].mx;
        seg[ind].cntmx = seg[lefind].cntmx + seg[rigind].cntmx;
        seg[ind].semx = max(seg[lefind].semx, seg[rigind].semx);
    }
    else if(seg[lefind].mx > seg[rigind].mx) {
        seg[ind].mx = seg[lefind].mx;
        seg[ind].cntmx = seg[lefind].cntmx;
        seg[ind].semx = max(seg[lefind].semx, seg[rigind].mx);
    }
    else {
        seg[ind].mx = seg[rigind].mx;
        seg[ind].cntmx = seg[rigind].cntmx;
        seg[ind].semx = max(seg[lefind].mx, seg[rigind].semx);
    }
    
    if(seg[lefind].mn == seg[rigind].mn) {
        seg[ind].mn = seg[lefind].mn;
        seg[ind].cntmn = seg[lefind].cntmn + seg[rigind].cntmn;
        seg[ind].semn = min(seg[lefind].semn, seg[rigind].semn);
    }
    else if(seg[lefind].mn < seg[rigind].mn) {
        seg[ind].mn = seg[lefind].mn;
        seg[ind].cntmn = seg[lefind].cntmn;
        seg[ind].semn = min(seg[lefind].semn, seg[rigind].mn);
    }
    else {
        seg[ind].mn = seg[rigind].mn;
        seg[ind].cntmn = seg[rigind].cntmn;
        seg[ind].semn = min(seg[lefind].mn, seg[rigind].semn);
    }
}

void pushadd(int l, int r, int ind, int val) {
    seg[ind].sum += (r - l + 1ll) * val;
    seg[ind].mx += val, seg[ind].mn += val;
    if(seg[ind].semx != -INF) seg[ind].semx += val;
    if(seg[ind].semn != INF) seg[ind].semn += val;
    if(seg[ind].tmx != -INF) seg[ind].tmx += val;
    if(seg[ind].tmn != INF) seg[ind].tmn += val;
    seg[ind].tad += val;
}

void pushmin(int ind, int val) {
    if(seg[ind].mx <= val) return;
    seg[ind].sum += (val * 1ll - seg[ind].mx) * seg[ind].cntmx;
    if(seg[ind].semn == seg[ind].mx) seg[ind].semn = val;
    if(seg[ind].mn == seg[ind].mx) seg[ind].mn = val;
    if(seg[ind].tmx > val) seg[ind].tmx = val;
    seg[ind].mx = val;
    seg[ind].tmn = val;
}

void pushmax(int ind, int val) {
    if(seg[ind].mn >= val) return;
    seg[ind].sum += (val * 1ll - seg[ind].mn) * seg[ind].cntmn;
    if(seg[ind].semx == seg[ind].mn) seg[ind].semx = val;
    if(seg[ind].mx == seg[ind].mn) seg[ind].mx = val;
    if(seg[ind].tmn < val) seg[ind].tmn = val;
    seg[ind].mn = val;
    seg[ind].tmx = val;
}

void pushdown(int l, int r, int ind) {
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    int mid = l + (r - l) / 2;
    if(seg[ind].tad) {
        pushadd(l, mid, lefind, seg[ind].tad);
        pushadd(mid + 1, r, rigind, seg[ind].tad);
    }
    if(seg[ind].tmx != -INF) {
        pushmax(lefind, seg[ind].tmx);
        pushmax(rigind, seg[ind].tmx);
    }
    if(seg[ind].tmn != INF) {
        pushmin(lefind, seg[ind].tmn);
        pushmin(rigind, seg[ind].tmn);
    }
    seg[ind].tad = 0, seg[ind].tmx = -INF, seg[ind].tmn = INF;
}

void build(int l, int r, int ind) {
    seg[ind].tmx = -INF, seg[ind].tmn = INF;
    if(l == r) {
        seg[ind].sum = seg[ind].mx = seg[ind].mn = dat[l];
        seg[ind].semx = -INF, seg[ind].semn = INF;
        seg[ind].cntmx = seg[ind].cntmn = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    build(l, mid, lefind), build(mid + 1, r, rigind);
    pushup(ind);
}

void add(int l, int r, int lef, int rig, int ind, int val) {
    if(lef <= l && r <= rig) return pushadd(l, r, ind, val);
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    pushdown(l, r, ind);
    if(lef <= mid) add(l, mid, lef, rig, lefind, val);
    if(rig > mid) add(mid + 1, r, lef, rig, rigind, val);
    pushup(ind);
}

void tomin(int l, int r, int lef, int rig, int ind, int val) {
    if(seg[ind].mx <= val) return;
    if(lef <= l && r <= rig && seg[ind].semx < val) return pushmin(ind, val);
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    pushdown(l, r, ind);
    if(lef <= mid) tomin(l, mid, lef, rig, lefind, val);
    if(rig > mid) tomin(mid + 1, r, lef, rig, rigind, val);
    pushup(ind);
}

void tomax(int l, int r, int lef, int rig, int ind, int val) {
    if(seg[ind].mn >= val) return;
    if(lef <= l && r <= rig && seg[ind].semn > val) return pushmax(ind, val);
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    pushdown(l, r, ind);
    if(lef <= mid) tomax(l, mid, lef, rig, lefind, val);
    if(rig > mid) tomax(mid + 1, r, lef, rig, rigind, val);
    pushup(ind);
}

ll querysum(int l, int r, int lef, int rig, int ind) {
    if(lef <= l && r <= rig) return seg[ind].sum;
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    pushdown(l, r, ind);
    ll sum = 0;
    if(lef <= mid) sum += querysum(l, mid, lef, rig, lefind);
    if(rig > mid) sum += querysum(mid + 1, r, lef, rig, rigind);
    return sum;
}

int querymax(int l, int r, int lef, int rig, int ind) {
    if(lef <= l && r <= rig) return seg[ind].mx;
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    pushdown(l, r, ind);
    int r1 = -INF, r2 = -INF;
    if(lef <= mid) r1 = querymax(l, mid, lef, rig, lefind);
    if(rig > mid) r2 = querymax(mid + 1, r, lef, rig, rigind);
    return max(r1, r2);
}

int querymin(int l, int r, int lef, int rig, int ind) {
    if(lef <= l && r <= rig) return seg[ind].mn;
    int mid = l + (r - l) / 2;
    int lefind = ind << 1, rigind = (ind << 1) | 1;
    pushdown(l, r, ind);
    int r1 = INF, r2 = INF;
    if(lef <= mid) r1 = querymin(l, mid, lef, rig, lefind);
    if(rig > mid) r2 = querymin(mid + 1, r, lef, rig, rigind);
    return min(r1, r2);
}

int main()
{
    int n;
    io.read(n);
    rep(i, 1, n) io.read(dat[i]);
    build(1, n, 1);
    int m;
    io.read(m);
    rep(i, 1, m) {
        int Tp, L, R;
        io.read(Tp), io.read(L), io.read(R);
        if(1 == Tp) {
            int val;
            io.read(val);
            add(1, n, L, R, 1, val);
        }
        else if(2 == Tp) {
            int val;
            io.read(val);
            tomax(1, n, L, R, 1, val);
        }
        else if(3 == Tp) {
            int val;
            io.read(val);
            tomin(1, n, L, R, 1, val);
        }
        else if(4 == Tp) {
            io.write(querysum(1, n, L, R, 1), '\n');
        }
        else if(5 == Tp) {
            io.write(querymax(1, n, L, R, 1), '\n');
        }
        else {
            io.write(querymin(1, n, L, R, 1), '\n');
        }
    }
    return 0;
}


