/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: d.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年07月01日 星期五 22时55分33秒
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

constexpr int maxn = 210;
struct plane {
    LL x, y, p;
}dat[maxn];
LL dp[maxn][maxn];

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    std::cout.tie(null);
#endif
    int N;
    std::cin >> N;
    rep(i, 0, N) {
        std::cin >> dat[i].x >> dat[i].y >> dat[i].p;
    }

    rep(i, 0, N) {
        rep(j, 0, N) {
            if (i == j) dp[i][j] = 0;
            else {
                LL tmp = std::abs(dat[i].x - dat[j].x) + std::abs(dat[i].y - dat[j].y);
                dp[i][j] = (tmp / dat[i].p) + ((tmp % dat[i].p) != 0);
                /* dp[i][j] = (tmp + dat[i].p - 1) / dat[i].p; */
            }
        }
    }

    rep(k, 0, N) rep(i, 0, N) rep(j, 0, N) {
        dp[i][j]= std::min(dp[i][j], std::max(dp[i][k], dp[k][j]));
    }

    /* rep(i, 0, N) { */
    /*     rep(j, 0, N) std::cout << dp[i][j] << " "; */
    /*     std::cout << std::endl; */
    /* } */
    
    LL ans = 2e18;
    /* LL ans = 1LL * 998244353 * 998244353; */
    rep(i, 0, N) {
        LL tmp = 0;
        rep(j, 0, N) {
            tmp = std::max(tmp, dp[i][j]);
        }
        ans = std::min(ans, tmp);
    }

    /* std::cout << ans << std::endl; */
    std::cout << ans << "\n";
    return 0;
}

