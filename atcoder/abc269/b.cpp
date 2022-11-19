/*************************************************************************
*   Copyright (C) 2022 Sangfor Ltd. All rights reserved.
*   
*   FileName: b.cpp
*   Author: LiYuFei
*   Mail: 990704776@qq.com
*   CreatedTime: 2022年09月18日 星期日 11时34分31秒
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
constexpr int rows = 10;

int main()
{
#ifndef DEBUG
    std::ios::sync_with_stdio(false);
    std::cin.tie(null);
    std::cout.tie(null);
#endif
    vc<std::string> maps(rows);
    for (auto &str : maps) std::cin >> str;
    int resminx = rows + 1, resminy = rows + 1;
    int resmaxx = -1, resmaxy = -1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (maps[i][j] == '#') {
                resminx = std::min(resminx, i);
                resminy = std::min(resminy, j);
                resmaxx = std::max(resmaxx, i);
                resmaxy = std::max(resmaxy, j);
            }
        }
    }
    std::cout << resminx + 1 << " " << resmaxx + 1 << std::endl;
    std::cout << resminy + 1 << " " << resmaxy + 1 << std::endl;
    return 0;
}

