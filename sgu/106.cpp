/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: 106.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Tue Nov  8 17:54:57 2022
*   Describe: 
*   
**************************************************************************/

#include <bits/stdc++.h>

#if __cplusplus >= 201703L
    #define REGISTER
    #define null  nullptr
#elif __cplusplus >= 201103L
    #define REGISTER register
    #define null  nullptr
#elif __cplusplus >= 199711L
    #define REGISTER register
    #define null  NULL
#endif

/* #pragma GCC target("avx2") */
/* #pragma GCC optimize("Ofast") */
/* #pragma GCC optimize("unroll-loops") */
#define likely(x) __builtin_expect(x, 1)
#define unlikely(x) __builtin_expect(x, 0)
#define All(x) x.begin(), x.end()
#define Rep(x, a, b) for(REGISTER int x = a; x <= b; ++x)
#define Resp(x, a, b) for(REGISTER int x = a; x >= b; --x)
#define rep(x, a, b) for(REGISTER int x = a; x < b; ++x)
#define resp(x, a, b) for(REGISTER int x = a; x > b; --x)
using LL = long long;
using pr = std::pair<int, int>;
template<typename T>
using vc = std::vector<T>;
template<typename T>
using vv = vc<vc<T>>;
constexpr int INF = INT_MAX;

LL a, b, c, X1, X2, Y1, Y2;

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    else {
        LL r = exgcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

LL line_mod_question(LL a, LL b, LL n) {
    LL x, y;
    LL count = 0;
    LL d = exgcd(a, n, x, y);
    if (b % d == 0) {
        x %= n, x += n, x %= n;
        /* LL tmpx = x * (b / d) % (n / d); */
        LL tmpx = x * (b / d) % (n / d);
        while (tmpx >= X1) tmpx = (tmpx - n / d);
        /* tmpx = (tmpx + n / d); */
        /* LL tmpy = (a / d * tmpx - b / d) / (n / d); */
        LL tmpy = (a * tmpx - b) / n;
        while (tmpy > Y2) tmpy -= a / d, tmpx += n / d;
        count = std::max((X2 - tmpx + 1) / (n / d), (tmpy - Y1 + 1) / (a / d));
        /* while(tmpx <= X2) { */
        /*     tmpx = (tmpx + n / d); */
        /*     /1* LL tmpy = (a * tmpx - d) / n; *1/ */
        /*     /1* tmpy--; *1/ */
        /*     tmpy = (a * tmpx - b) / n; */
        /*     if (tmpx >= X1 && tmpx <= X2 && tmpy >= Y1 && tmpy <= Y2) count++; */
        /* } */
    }
    return count;
}

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    /* std::cout.tie(null); */
#endif
    std::cin >> a >> b >> c >> X1 >> X2 >> Y1 >> Y2;
    std::cout << line_mod_question(a, -c, -b) << "\n";
    return 0;
}

