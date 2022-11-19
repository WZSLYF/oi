/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: e.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年07月02日 星期六 16时29分28秒
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

constexpr int maxn = 10;

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    std::cout.tie(null);
#endif
    int N;
    std::cin >> N;

    std::array<int, maxn> dat;
    rep(i, 1, maxn) std::cin >> dat[i];

    vc<int> dp(N + 1);
    rep(i, 1, maxn) Rep(j, dat[i], N) {
        dp[j] = std::max(dp[j], dp[j - dat[i]] + 1);
    }

    while (dp[N] > 0) {
        int tmp = 9;
        while (dat[tmp] > N || dp[N - dat[tmp]] + 1 != dp[N]) tmp--;
        std::cout << tmp;
        N -= dat[tmp];
    }
    std::cout << std::endl;
    return 0;
}

