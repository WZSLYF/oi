/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 1552.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月09日 星期三 09时41分26秒
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
int Bi[maxn], Li[maxn], l[maxn], r[maxn], d[maxn], fa[maxn], siz[maxn];
ll sum[maxn], ans;
vector<int> mp[maxn];
int N, M;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(Bi[x] < Bi[y]) swap(x, y);
    r[x] = merge(r[x], y);
    if(d[l[x]] < d[r[x]]) swap(l[x], r[x]);
    d[x] = d[r[x]] + 1;
    return x;
}

void dfs(int x) {
    sum[x] = Bi[x], siz[x] = 1;
    for(int i = 0; i < (int)mp[x].size(); ++i) {
        int y = mp[x][i];
        dfs(y);
        sum[x] += sum[y];
        siz[x] += siz[y];
        fa[x] = fa[y] = merge(find(x), find(y));
    }
    while(sum[x] > M && siz[x]) {
        int pa = find(x);
        //sum[x] -= Bi[pa]
        sum[x] -= Bi[pa];
        siz[x]--;
        fa[l[pa]] = fa[r[pa]] = fa[pa] = merge(l[pa], r[pa]);
        l[pa] = r[pa] = d[pa] = 0;
    }
    ans = max(ans, 1ll * Li[x] * siz[x]);
}

int main()
{
    io.read(N), io.read(M);
    rep(i, 1, N) {
        int pa;
        io.read(pa), io.read(Bi[i]), io.read(Li[i]);
        mp[pa].push_back(i);
        fa[i] = i;
    }
    dfs(1);
    io.write(ans, '\n');
    return 0;
}


