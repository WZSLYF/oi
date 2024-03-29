/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 10143_2.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月13日 星期日 09时03分03秒
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
int rt, tot, fa[maxn], ch[maxn][2], val[maxn], cnt[maxn], siz[maxn];
struct Splay {
    bool flags;
    void maintain(int x) { siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + cnt[x]; }
    bool get(int x) { return x == ch[fa[x]][1]; }
    void clear(int x) {
        fa[x] = ch[x][0] = ch[x][1] = val[x] = cnt[x] = siz[x] = 0;
    }
    void rotate(int x) {
        int y = fa[x], z = fa[y], chk = get(x);
        ch[y][chk] = ch[x][chk ^ 1];
        if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
        ch[x][chk ^ 1] = y;
        fa[y] = x;
        fa[x] = z;
        if(z) ch[z][y == ch[z][1]] = x;
        maintain(y);
        maintain(x);
    }
    
    void splay(int x) {
        for(int f; f = fa[x], f; rotate(x)) 
            if(fa[f]) rotate(get(x) == get(f) ? f : x);
        rt = x;
    }

    void insert(int k) {
        if(!rt) {
            ++tot;
            val[tot] = k;
            cnt[tot]++;
            rt = tot;
            maintain(tot);
            return;
        }
        int cur = rt, f = 0;
        while(1) {
            if(val[cur] == k) {
                flags = true;
                cnt[cur]++;
                maintain(cur);
                if(f) maintain(f);
                splay(cur);
                break;
            }
            f = cur;
            cur = ch[cur][val[cur] < k];
            if(!cur) {
                ++tot;
                val[tot] = k;
                cnt[tot]++;
                fa[tot] = f;
                ch[f][val[f] < k] = tot;
                maintain(tot);
                maintain(f);
                splay(tot);
                break;
            }
        }
    }

    int rk(int k) {
        int res = 0, cur = rt;
        while(1) {
            if(k < val[cur]) cur = ch[cur][0];
            else {
                res += siz[ch[cur][0]];
                if(val[cur] == k) {
                    splay(cur);
                    return res + 1;
                }
                res += cnt[cur];
                cur = ch[cur][1];
            }
        }
    }

    int kth(int k) {
        int cur = rt;
        while(1) {
            if(ch[cur][0] && k <= siz[ch[cur][0]]) cur = ch[cur][0];
            else {
                k -= cnt[cur] + siz[ch[cur][0]];
                if(k <= 0) {
                    splay(cur);
                    return val[k];
                }
                cur = ch[cur][1];
            }
        }
    }

    int pre() {
        int cur = ch[rt][0];
        if(!cur) return cur;
        while(ch[cur][1]) cur = ch[cur][1];
        //splay(cur);
        return cur;
    }

    int nxt() {
        int cur = ch[rt][1];
        if(!cur) return cur;
        while(ch[cur][0]) cur = ch[cur][0];
        //splay(cur);
        return cur;
    }

    void del(int k) {
        rk(k);
        if(cnt[rt] > 1) {
            cnt[rt]--;
            maintain(rt);
            return;
        }
        if(!ch[rt][0] && !ch[rt][1]) {
            clear(rt);
            rt = 0;
            return;
        }
        if(!ch[rt][0]) {
            int cur = rt;
            rt = ch[rt][1];
            fa[rt] = 0;
            clear(cur);
            return;
        }
        if(!ch[rt][1]) {
            int cur = rt;
            rt = ch[rt][0];
            fa[rt] = 0;
            clear(cur);
            return;
        }
        int cur = rt;
        int x = pre();
        fa[ch[cur][1]] = x;
        ch[x][1] = ch[cur][1];
        clear(cur);
        maintain(rt);
    }
}tree;

int main()
{
    int n;
    io.read(n);
    int res = 0;
    int a;
    io.read(a);
    res += a;
    tree.insert(a);
    rep(i, 2, n) {
        //int a;
        io.read(a);
        tree.flags = false;
        tree.insert(a);
        if(!tree.flags) {
            int tmp = tree.pre();
            int temp = tree.nxt();
            int Min = 1e7;
            if(tmp) Min = min(Min, abs(val[tmp] - a));
            if(temp) Min = min(Min, abs(val[temp] - a));
            res += Min;
        }
    }
    io.write(res, '\n');
    return 0;
}


