/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 3236_1.cpp
*   Author: Yufei Li
*   Mail: 990704776@qq.com
*   CreatedTime: Wed 23 Jun 2021 11:42:13 AM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define re register

const int maxn = 1e6 + 10;
//const int maxm = 1e6 + 10;
int n, m, dat[maxn], pos[maxn];
int cnt[maxn], sum1[maxn], sum2[maxn], pos2[maxn];
int ans[maxn], res[maxn];
struct Ques{
    int l, r, a, b, id;
}q[maxn];
int MaxV, b;

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
        for(re int i = lef;i <= b * p; ++i) ans += cnt[i];
        for(re int i = (q - 1) * b + 1; i <= rig; ++i) ans += cnt[i];
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
        for(re int i = lef; i <= b * p; ++i) ans += cnt[i] ? 1 : 0;
        for(re int i = (q - 1) * b + 1; i <= rig; ++i) ans += cnt[i] ? 1 : 0;
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
    for(re int i = 1; i <= n; ++i) io.read(dat[i]), MaxV = max(MaxV, dat[i]), pos[i] = (i - 1) / t + 1;
    b = sqrt(MaxV);
    for(re int i = 1; i <= MaxV; ++i) pos2[i] = (i - 1) / b + 1;
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

