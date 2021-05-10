/*************************************************************************
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   FileName: 17901.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Thu 30 Jan 2020 02:12:54 PM CST
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define Rep(i, n) for(int i = 0; i < n; ++i)
#define pb push_back
#define bg begin
#define ed end
#define ll long long

const int INF = ~0U >> 1;

inline int readInt() { int x; scanf("%d", &x); return x; }
template<class T>
inline T Max(const T& a, const T& b) { return a > b ? a : b; }

template<class T>
inline T Min(const T& a, const T& b) { return a < b ? a : b; }

const int maxn = 1e6 + 10;

struct node {
    ll l, r;
}dat[maxn];

ll n, t;

int main()
{
    scanf("%lld %lld", &n, &t);
    Rep(i, n) scanf("%lld %lld", &dat[i].l, &dat[i].r);
    ll ans = 0;
    ll tmp = dat[0].r - dat[0].l;
    //printf("%lld %lld\n", tmp, tmp / t);
    ll k = tmp % t;
    tmp = tmp / t;
    if(k) tmp++;
    ans += tmp;
    ll l = dat[0].l;
    //printf("%lld\n", tmp);
    for(int i = 1; i < n; ++i) {
        if(l + tmp * t >= dat[i].r) continue;
        else if(l + tmp * t >= dat[i].l) {
            ll temp = dat[i].r - l - tmp * t;
            k = temp % t;
            temp = temp / t;
            if(k) temp++;
            ans += temp;
            l = l + tmp * t;
            tmp = temp;
        }
        else {
            tmp = dat[i].r - dat[i].l;
            //printf("%lld\n", tmp % t);
            k = tmp % t;
            tmp = tmp / t;
            //printf("%lld\n", tmp);
            if(k) tmp++;
            //printf("%lld\n", tmp);
            ans += tmp;
            l = dat[i].l;
        }
    }

    printf("%lld\n", ans);
    return 0;
}

