/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 104.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月09日 星期三 18时50分50秒
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
int n;

struct treap{
    int l[maxn], r[maxn], val[maxn], rnd[maxn], siz[maxn], w[maxn];
    int sz, ans, rt;
    inline void pushup(int x) { siz[x] = siz[l[x]] + siz[r[x]] + w[x]; }
    void lrot(int &k) {
        int t = r[k];
        r[k] = l[t];
        l[t] = k;
        siz[t] = siz[k];
        pushup(k);
        k = t;
    }

    void rrot(int &k) {
        int t = l[k];
        l[k] = r[t];
        r[t] = k;
        siz[t] = siz[k];
        pushup(k);
        k = t;
    }

    void insert(int &k, int x) {
        if(!k) {
            sz++;
            k = sz;
            siz[k] = 1;
            w[k] = 1;
            val[k] = x;
            rnd[k] = rand();
            return;
        }
        siz[k]++;
        if(val[k] == x) w[k]++;
        else if(val[k] < x) {
            insert(r[k], x);
            if(rnd[r[k]] < rnd[k]) lrot(k);
        }
        else {
            insert(l[k], x);
            if(rnd[l[k]] < rnd[k]) rrot(k);
        }
    }

    bool del(int &k, int x) {
        if(!k) return false;
        if(val[k] == x) {
            if(w[k] > 1) {
                w[k]--;
                siz[k]--;
                return true;
            }
            if(l[k] == 0 || r[k] == 0) {
                k = l[k] + r[k];
                return true;
            }
            else if(rnd[l[k]] < rnd[r[k]]) {
                rrot(k);
                return del(k, x);
            }
            else {
                lrot(k);
                return del(k, x);
            }
        }
        else if(val[k] < x) {
            bool succ = del(r[k], x);
            if(succ) siz[k]--;
            return succ;
        }
        else {
            bool succ = del(l[k], x);
            if(succ) siz[k]--;
            return succ;
        }
    }

    int queryrank(int k, int x) {
        if(!k) return 0;
        if(val[k] == x) return siz[l[k]] + 1;
        else if(val[k] < x) return siz[l[k]] + w[k] + queryrank(r[k], x);
        else return queryrank(l[k], x);
    }

    int querynum(int k, int x) {
        if(!k) return 0;
        if(x <= siz[l[k]]) return querynum(l[k], x);
        else if(x > siz[l[k]] + w[k]) return querynum(r[k], x - siz[l[k]] - w[k]);
        else return val[k];
    }

    void querypre(int k, int x) {
        if(!k) return;
        if(val[k] < x) ans = k, querypre(r[k], x);
        else querypre(l[k], x);
    }

    void querysub(int k, int x) {
        if(!k) return;
        if(val[k] > x) ans = k, querysub(l[k], x);
        else querysub(r[k], x);
    }

}T;

int main()
{
    srand(time(NULL));
    scanf("%d", &n);
    int opt, x;
    rep(i, 1, n) {
        scanf("%d %d", &opt, &x);
        if(1 == opt) {
            T.insert(T.rt, x);
        }
        else if(2 == opt) {
            T.del(T.rt, x);
        }
        else if(3 == opt) {
            printf("%d\n", T.queryrank(T.rt, x));
        }
        else if(4 == opt) {
            printf("%d\n", T.querynum(T.rt, x));
        }
        else if(5 == opt) {
            T.querypre(T.rt, x);
            printf("%d\n", T.val[T.ans]);
        }
        else {
            T.querysub(T.rt, x);
            printf("%d\n", T.val[T.ans]);
        }
    }
    return 0;
}


