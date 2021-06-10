/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 1456.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月08日 星期二 21时44分45秒
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

const int maxn = 1e5 + 10;
int v[maxn], l[maxn], r[maxn], d[maxn], fa[maxn];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(v[x] < v[y]) swap(x, y);
    r[x] = merge(r[x], y);
    if(d[l[x]] < d[r[x]]) swap(l[x], r[x]);
    d[x] = d[r[x]] + 1;
    return x;
}

int weak(int x) {
    v[x] >>= 1;
    int tmp = merge(l[x], r[x]);
    l[x] = r[x] = d[x] = 0;
    return fa[x] = fa[tmp] = merge(x, tmp);
}

int main()
{
    int n;
    while(~scanf("%d", &n)) {
        rep(i, 1, n) {
            l[i] = r[i] = d[i] = 0;
            fa[i] = i;
            scanf("%d", v + i);
        }

        int m;
        scanf("%d", &m);
        rep(i, 1, m) {
            int x, y;
            scanf("%d %d", &x, &y);
            x = find(x), y = find(y);
            if(x == y) { printf("-1\n"); continue; }
            else {
                int tmp = weak(x), temp = weak(y);
                fa[tmp] = fa[temp] = merge(tmp, temp);
                printf("%d\n", v[fa[tmp]]);
            }
        }
    }
    return 0;
}


