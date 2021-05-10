/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 10197.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Sat 17 Apr 2021 08:49:12 PM CST
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

const int maxn = 1e6 + 10;
int prim1[maxn], prim2[maxn], tot1, tot2;
bool vis[maxn];
int l, r, t1, t2, x1, Y1, x2, Y2;

void prime() {
    memset(vis, 1, sizeof(vis));
    tot1 = 0;
    for(int i = 2; i <= 46340; i++) {
        if(!vis[i]) continue;
        prim1[++tot1] = i;
        //printf("%d ", i);
        for(int j = 2; j <= 46340 / i; j++) vis[i * j] = false;
    }
}


int main() {
    prime();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //printf("%d\n", tot1);
    while(cin >> l >> r) {
        memset(vis, 1, sizeof(vis));
        if(l == 1) vis[0] = false;
        //printf("%d\n", tot1);
        for(int i = 1; i <= tot1; ++i) {
            //printf("%d %d ", i, prim1[i]);
            //if(prim1[i] == 6733) printf("----%d %d\n", l/prim1[i], r/prim1[i]);
            for(int j = l / prim1[i]; j <= r / prim1[i]; ++j) if(j > 1 && prim1[i] * j >= l) {
                int tmp = j * prim1[i] - l;
                //printf("%d %d\n", tmp, tot1);
                vis[tmp] = false;
            }
        }
        //printf("%d\n", tot1);
        tot2 = 0;
        //for(int i = l; i <= r; ++i) printf("%d ", vis[i - l]);
        for(int i = l; i <= r; ++i) {
            if(vis[i - l]) prim2[++tot2] = i;// printf("%d ", i);
            if(i == r) break;
        }
        t1 = INF, t2 = 0;
        for(int i = 1; i < tot2; ++i) {
            int tmp = prim2[i + 1] - prim2[i];
            if(tmp < t1) {
                t1 = tmp, x1 = prim2[i], Y1 = prim2[i + 1];
            }
            if(tmp > t2) {
                t2 = tmp, x2 = prim2[i], Y2 = prim2[i + 1];
            }
        }

        if(!t2) printf("There are no adjacent primes.\n");
        else printf("%d,%d are closest, %d,%d are most distant.\n", x1, Y1, x2, Y2);

    }
    return 0;
}

