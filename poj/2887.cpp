/*************************************************************************
*   Copyright (C) 2021 Sangfor Ltd. All rights reserved.
*   
*   FileName: 2887.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2021年06月09日 星期三 17时17分51秒
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

const int sqn = 1e3;
struct node {
    node *next;
    int size;
    char str[(sqn << 1) + 10];
    node() { size = 0; next = nullptr; }
    void pb(char ch) { str[size++] = ch; }
}*head = nullptr;
int len;

char sstr[(int)1e6 + 10];

void readch(char &ch) {
    do 
        ch = getchar();
    while(!isalpha(ch));
}

void check(node *p) {
    if(p->size >= (sqn << 1)) {
        node *q = new node();
        for(int i = sqn; i < p->size; ++i) q->pb(p->str[i]);
        p->size = sqn, q->next = p->next, p->next = q;
    }
}

void insert(char ch, int pos) {
    node *p = head;
    if(pos > len++) {
        while(p->next != nullptr) p = p->next;
        p->pb(ch), check(p);
        return;
    }

    int tot = 0;
    for(tot = p->size; p != nullptr && tot < pos; p = p->next, tot += p->size);
    tot -= p->size;
    int cnt = pos - tot - 1;
    for(int i = p->size - 1; i >= cnt; --i) p->str[i + 1] = p->str[i];
    p->str[cnt] = ch, p->size++, check(p);
}

char query(int pos) {
    node *p;
    int tot = 0;
    for(p = head, tot = head->size; p != nullptr && tot < pos; p = p->next, tot += p->size);
    tot -= p->size;
    return p->str[pos - tot - 1];
}

int main()
{
    int q;
    scanf("%s %d", sstr, &q);
    node *p = new node();
    head = p;
    len = strlen(sstr);
    for(int i = 0; i < len; ++i) {
        if(i % sqn == 0 && i) p->next = new node(), p = p->next;
        p->pb(sstr[i]);
    }

    char opt, ch;
    int k;
    while(q--) {
        readch(opt);
        if(opt == 'Q') {
            scanf("%d", &k), printf("%c\n", query(k));
        }
        else {
            readch(ch), scanf("%d", &k), insert(ch, k);
        }
    }
    return 0;
}


