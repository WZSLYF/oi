/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: c.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年07月01日 星期五 21时39分34秒
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

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    std::cout.tie(null);
#endif
    int N;
    std::cin >> N;

    std::string str;
    std::cin >> str;
    std::map<int, int> f;

    int res = 0;
    rep(i, 0, N) {
        int wi;
        std::cin >> wi;
        res += str[i] == '1';
        f[wi] += str[i] == '0' ? 1 : -1;
    }

    int ans = res;
    for (auto &it : f) {
        res += it.second;
        ans = std::max(ans, res);
    }
    
    std::cout << ans << "\n";

    return 0;
}

