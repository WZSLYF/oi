/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 10143.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月12日 星期六 23时57分47秒
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

const int maxn = (1 << 15) + 10;
int n;

mt19937 randd(233);

struct treap{
    int l[maxn], r[maxn], val[maxn], rnd[maxn], siz[maxn], w[maxn];
    int tot, ans, rt;
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
            tot++;
            k = tot;
            siz[k] = 1;
            w[k] = 1;
            val[k] = x;
            rnd[k] = randd();
            return;
        }
        siz[k]++;
        if(val[k] == x) {
            w[k]++;
        }
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
            if(!l[k] || !r[k]) {
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
        if(x <= siz[l[x]]) return querynum(l[k], x);
        else if(x > siz[l[k]] + w[k]) return querynum(r[k], x - siz[l[k]] - w[k]);
        else return val[k];
    }

    int querypre(int k, int x) {
        if(!k) return 0;
        int cur = k;
        int res = -(1e7);
        while(cur) {
            if(val[cur] == x) { res = x; break; }
            else if(val[cur] < x) res = val[cur], cur = r[cur];
            else cur = l[cur];
        } 
        return res;
    }

    int querysub(int k, int x) {
        if(!k) return 0;
        int cur = k;
        int res = 1e7;
        while(cur) {
            if(val[cur] == x) { res = x; break; }
            else if(val[cur] > x) res = val[cur], cur = l[cur];
            else cur = r[cur];
        }
        return res;    
    }
}tr;

int main()
{
    io.read(n);
    int res = 0;
    rep(i, 1, n) {
        int a;
        io.read(a);
        //tr.ans = 0;
        int tmp = tr.querypre(tr.rt, a);
        int temp = tr.querysub(tr.rt, a);
        res += min(abs(a - tmp), abs(a - temp));
        tr.insert(tr.rt, a);
    }
    io.write(res, '\n');
    return 0;
}


