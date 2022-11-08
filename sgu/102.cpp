/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: 102.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: Tue Nov  8 15:06:58 2022
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
    /* std::cout.tie(null); */
#endif
    int n;
    std::cin >> n;
    auto calc = [&]() {
        int ans = n;
        for(int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                ans = ans / i * (i - 1);
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1) ans = ans / n * (n - 1);
        return ans;
    };
    std::cout << calc() << "\n";
    return 0;
}

