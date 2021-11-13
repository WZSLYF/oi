/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 4396_1.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: Wed 23 Jun 2021 11:42:13 AM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define re register

const int maxn = 1e5 + 10;
int n, m, dat[maxn], pos[maxn];
int cnt[maxn], sum1[maxn], sum2[maxn], pos2[maxn];
int ans[maxn], res[maxn];
struct Ques{
    int l, r, a, b, id;
}q[maxn];
int MaxV, b;

namespace nqio{
const unsigned R=4e5,W=4e5;
char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;
bool s;
struct q{
	__attribute__((always_inline))
	void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}
	void f(){fwrite(o,1,c-o,stdout);c=o;}
	~q(){f();}
	__attribute__((always_inline))
	void w(char x){*c=x;if(++c==d)f();}
	__attribute__((always_inline))
	q&operator>>(char&x){do r(x);while(x<=32);return*this;}
	__attribute__((always_inline))
	q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}
	template<typename t>__attribute__((always_inline))
	q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}
	__attribute__((always_inline))
	q&operator<<(char x){w(x);return*this;}
	q&operator<<(char*x){while(*x)w(*x++);return*this;}
	__attribute__((always_inline))
	q&operator<<(const char*x){while(*x)w(*x++);return*this;}
	template<typename t>__attribute__((always_inline))
	q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}
}qio;
}
using nqio::qio;

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
#if DEBUG  // 调试，可显示字符
    return getchar();
#endif
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
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
    for (; !isdigit(ch); ch = gc())
      if (ch == '-') sign = 1;
    for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); isdigit(ch); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }
  inline void read(char *s) {
    register char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }
  inline void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }
  inline void push(const char &c) {
#if DEBUG  // 调试，可显示字符
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }
  template <class T>
  inline void write(T x) {
    if (x < 0) x = -x, push('-');  // 负数输出
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) push(sta[--top] + '0');
  }
  template <class T>
  inline void write(T x, char lastChar) {
    write(x), push(lastChar);
  }
} io;

bool cmp(const Ques &a, const Ques &b) {
    if(pos[a.l] != pos[b.l]) return a.l < b.l;
    if(pos[a.l] & 1) return a.r < b.r;
    return a.r > b.r;
}

void Add(int x) {
    if(!cnt[x]) sum2[pos2[x]]++;
    cnt[x]++;
    sum1[pos2[x]]++;
}

void Sub(int x) {
    cnt[x]--;
    if(!cnt[x]) sum2[pos2[x]]--;
    sum1[pos2[x]]--;
}

int getans(int lef, int rig) {
    int ans = 0;
    rig = min(rig, MaxV);
    if(lef > MaxV) return 0;
    int p = pos2[lef], q = pos2[rig];
    if(p == q) {
        for(re int i = lef; i <= rig; ++i) ans += cnt[i];
    }
    else {
        for(re int i = p + 1; i <= q - 1; ++i) ans += sum1[i];
        for(re int i = lef; pos[i] == p; ++i) ans += cnt[i];
        for(re int i = rig; pos[i] == q; --i) ans += cnt[i];
    }
    return ans;
}

int getres(int lef, int rig) {
    int ans = 0;
    rig = min(rig, MaxV);
    if(lef > MaxV) return 0;
    int p = pos2[lef], q = pos2[rig];
    if(p == q) {
        for(re int i = lef; i <= rig; ++i) ans += cnt[i] ? 1 : 0;
    }
    else {
        for(re int i = p + 1; i <= q - 1; ++i) ans += sum2[i];
        for(re int i = lef; pos[i] == p; ++i) ans += cnt[i] ? 1 : 0;
        for(re int i = rig; pos[i] == q; --i) ans += cnt[i] ? 1 : 0;
    }
    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //qio >> n >> m;
    io.read(n), io.read(m);
    int t = sqrt(n);
    for(re int i = 1; i <= n; ++i) io.read(dat[i]), MaxV = max(MaxV, dat[i]), pos[i] = (i - 1) / t;
    b = sqrt(MaxV);
    for(re int i = 1; i <= MaxV; ++i) pos2[i] = (i - 1) / b;
    for(re int i = 1; i <= m; ++i) io.read(q[i].l), io.read(q[i].r), io.read(q[i].a), io.read(q[i].b), q[i].id = i;

    sort(q + 1, q + m + 1, cmp);
    int lef = 1, rig = 0;
    for(re int i = 1; i <= m; ++i) {
        while(lef > q[i].l) Add(dat[--lef]);
        while(rig < q[i].r) Add(dat[++rig]);
        while(lef < q[i].l) Sub(dat[lef++]);
        while(rig > q[i].r) Sub(dat[rig--]);
        ans[q[i].id] = getans(q[i].a, q[i].b);
        res[q[i].id] = getres(q[i].a, q[i].b);
    }
    for(re int i = 1; i <= m; ++i) io.write(ans[i], ' '), io.write(res[i], '\n');
    return 0;
}

