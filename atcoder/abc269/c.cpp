/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: c.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年09月18日 星期日 15时11分45秒
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
constexpr int maxn = 62;

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    std::cout.tie(null);
#endif
    vc<LL> powtwo(maxn);
    powtwo[0] = 1;
    rep(i, 1, maxn) powtwo[i] = powtwo[i - 1] << 1;

    LL N;
    std::cin >> N;

    vc<LL> dat(maxn);
    int count = 0;
    rep(i, 0, maxn) if (powtwo[i] & N) dat[count++] = powtwo[i];
    /* int countones = __builtin_popcount(N); */
    std::set<LL> ans;
    rep(i, 0, powtwo[count]) {
        LL res = 0;
        rep(j, 0, count) if (i & powtwo[j]) res += dat[j];
        ans.insert(res);
    }
    for (auto &res : ans) {
        std::cout << res << std::endl;
    }
    return 0;
}

